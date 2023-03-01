#include "compass_impl.h"
#include "scc.h"
#include "traverse_ast.h"
#include "ast_helpers.h"
#include "ast_nodes.h"
#include "symbol_table.h"

#include <assert.h>
// #include <stdio.h>

#define FUNCTION_NAME_SIZE 256
static char func_name[FUNCTION_NAME_SIZE];

void prepend_this_or_self_to_params(union ast_node *node, struct ast_function_declarator_node *fn_decl, union ast_node *parent);
union ast_node *find_this_or_self_id(union ast_node *node);
void detach_impl_body(union ast_node *node, union ast_node *parent);
void process_new_function(union ast_node *node, union ast_node *parent);
void process_static_impl(union ast_node *node, union ast_node *parent);


// Prepend `self` or `this` to the parameter list!
void prepend_this_or_self_to_params(union ast_node *node, struct ast_function_declarator_node *fn_decl, union ast_node *parent)
{
	union ast_node *decl_specs;
	union ast_node *this_or_self;
	union ast_node *tmp;

	if (fn_decl->identifier_list) {
		assert(fn_decl->identifier_list->type == AST_CONST);
		decl_specs = create_list_node(fn_decl->identifier_list, parent->impl.id, " ");
		fn_decl->identifier_list = NULL;
	} else {
		decl_specs = parent->impl.id;
	}

	this_or_self = node->function_definition.block ? find_this_or_self_id(node->function_definition.block) : NULL;
	if (this_or_self == NULL) this_or_self = (void *) & self_node; // This is where we set the 'default' argument name for the 'hidden' first argument 'impl' blocks. It could be either 'this' or 'self'. Since we were unable to find a name in the code, we just set the name to 'self'! We require a name for GCC! We could also just make this a neutral name like '_' or something!
	tmp = create_parameter_declaration_node(decl_specs, create_pointer_declarator_node(create_pointer_node(NULL, NULL), this_or_self));

	fn_decl->params = fn_decl->params == NULL ? tmp : create_list_node(tmp, fn_decl->params, ", ");
}


void detach_impl_body(union ast_node *node, union ast_node *parent)
{
	if (parent == NULL) {
		ast_root = node->impl.body;
		return;
	}

	//	Step 1: make sure the "impl" `id` is a registered typedef! ... OR, we can just do that in the parser!
	//	Step 2: detach the impl node from the parent! Attach the body nodes instead!
	if (parent->type == AST_LIST) {
		if (parent->list.node == node) {
			parent->list.node = node->impl.body;
		} else if (parent->list.next == node) {
			parent->list.next = node->impl.body;
		} else {
			fprintf(stderr, "PARSER ERROR: Regression error detected. Make sure the parent node passed to process_impl is an AST_LIST node that includes the AST_IMPL node!\n");
			exit(EXIT_FAILURE);
		}
	} else {
		if (parent == ast_root) {		//	NOTE: I don't think this is possible! This should probably be removed! Need to test it!
			ast_root = node->impl.body;
		} else {
			fprintf(stderr, "PARSER ERROR: Unknown or unhandled `impl` parent! `impl` statements may only appear at the root level\n");
			exit(EXIT_FAILURE);
		}
	}
}



void process_impl(union ast_node *node, union ast_node *parent)
{
	if (node == NULL) return;

	struct ast_function_declarator_node *fn_decl;
	union ast_node *tmp;

	switch (node->type) {

	case AST_IMPL:
		//	NOTE: The test below is no longer necessary, because we only loop through top level nodes in the traversal!
		//	Make sure we are at the GLOBAL symbol table level! ie. index 0 in the symbol table ... this is only really useful for debugging!
		// assert(symbol_table_get_level() == 0);
		/*
		if (symbol_table_get_level() != 0) {
			fprintf(stderr, "`impl` statements may only appear at the root level!\n"); // I think this is redundant! We can just leave the assert()!
			if (flags.debug) {
				symbol_table_print(stderr);
			}
			exit(EXIT_FAILURE);
		}
		*/

		detach_impl_body(node, parent);


		//	Step 2: Loop through all the functions in the "impl" block and rename them!
		process_impl(node->impl.body, node);

		//	Step 3: Loop through the functions code blocks, and expand all function calls and getter/setter calls!
		//	This method should also add a function declaration at the top of the "impl" code so we don't have to worry about function order!
		//expand_function_calls(node->impl.body, node);
		break;

	case AST_LIST:
		process_impl(node->list.node, parent);
		process_impl(node->list.next, parent);
		break;

	case AST_IMPL_NEW_FUNCTION:
		process_new_function(node, parent);
		break;

	case AST_IMPL_DELETE_FUNCTION:
		node->type = AST_FUNCTION_DEFINITION;
		tmp = node->function_definition.declarator;
		if (tmp->type == AST_FUNCTION_DECLARATOR) {
			//tmp->type = AST_POINTER_DECLARATOR;
			//tmp = tmp->pointer_declarator.direct_declarator;
			// if (tmp->type == AST_FUNCTION_DECLARATOR) {
				sprintf(func_name, "%s__delete", parent->impl.id->id.id);

				// Add the function name to the global symbol table
				//symbol = symbol_add_function(func_name, node);

				fn_decl = &tmp->function_declarator;

				fn_decl->direct_declarator = create_id_node(func_name);

				prepend_this_or_self_to_params(node, fn_decl, parent);


				// expand_function_calls(node->function_definition.block, node);
				break;
			// }
		}
		fprintf(stderr, "Unsupported syntax for `delete` method!! eg. void delete(&self);\n");
		exit(EXIT_FAILURE);
		break;


	case AST_GETTER:
		node->type = AST_FUNCTION_DEFINITION;
		tmp = node->function_definition.declarator;
		if (tmp->type == AST_POINTER_DECLARATOR) {
			tmp = tmp->pointer_declarator.direct_declarator;
			if (tmp->type == AST_FUNCTION_DECLARATOR) {
				fn_decl = &tmp->function_declarator;
			} else {
				fprintf(stderr, "ERROR: Expected a standard `getter` function declarator! Found AST node id %d (%s) instead\n", tmp->type, get_node_name(tmp->type));
				exit(EXIT_FAILURE);
			}
		} else if (tmp->type == AST_FUNCTION_DECLARATOR) {
			fn_decl = &tmp->function_declarator;
		} else if (tmp->type == AST_LIST) {
			tmp = tmp->list.node;
			if (tmp->type == AST_ID) {
				fprintf(stderr, ">>> TTT %s\n", tmp->id.id);
				exit(EXIT_FAILURE);
			}
			fprintf(stderr, "Found AST node id %d\n", tmp->type);
			exit(EXIT_FAILURE);
		} else {
			fprintf(stderr, "Unsupported `getter` syntax or structure! Found AST node id %d (%s) instead\n", tmp->type, get_node_name(tmp->type));
			exit(EXIT_FAILURE);
		}

		//	Detect if there is a `non-getter` function with the same name! Why do we need to check this???

		//	TODO: FIX THIS! I've disabled it to implement the new symbol table symbol_add_...() functionality!

		// sprintf(func_name, "%s__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);
		// if (hash_map_get_value(&impl_functions, func_name) || hash_map_get_value(&global_scope_symbols, func_name)) {
		// 	fprintf(stderr, "Error: `getter` and `non-getter` function with the same name detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 	exit(EXIT_FAILURE);
		// }

		sprintf(func_name, "%s__get__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);

		//	NEW symbol table!
		// symbol = symbol_add_getter(func_name, node);


		// fn_impl = (impl_t *) hash_map_get_value(&impl_functions, func_name);
		// if (fn_impl == NULL) {
		// 	fn_impl = new__impl(node);
			
		// 	fn_impl->is_getter = true;

		// 	if (node->function_definition.block == NULL) {
		// 		fn_impl->has_declaration = true;
		// 	} else {
		// 		fn_impl->has_definition = true;
		// 	}

		// 	hash_map_add(&impl_functions, func_name, fn_impl);
		// } else {
		// 	// TODO: Check the function signature of both the declaration and definition!
		// 	if (node->function_definition.block) {
		// 		if (fn_impl->has_definition == false) {
		// 			fn_impl->has_definition = true;
		// 		} else {
		// 			fprintf(stderr, "Error: Duplicate function definition detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 			exit(EXIT_FAILURE);
		// 		}
		// 	} else {
		// 		if (fn_impl->has_declaration == false) {
		// 			fn_impl->has_declaration = true;
		// 		} else {
		// 			fprintf(stderr, "Error: Duplicate function declaration detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 			exit(EXIT_FAILURE);
		// 		}
		// 		// fn_impl->has_declaration = true;
		// 	}
		// 	// fprintf(stderr, "Error: Duplicate function name detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 	// exit(EXIT_FAILURE);
		// }

		fn_decl->direct_declarator = create_id_node(func_name);

		prepend_this_or_self_to_params(node, fn_decl, parent);

		// expand_function_calls(node->function_definition.block, node);

		break;

	case AST_SETTER:
		node->type = AST_FUNCTION_DEFINITION;
		tmp = node->function_definition.declarator;
		if (tmp->type == AST_POINTER_DECLARATOR) {
			tmp = tmp->pointer_declarator.direct_declarator;
			if (tmp->type == AST_FUNCTION_DECLARATOR) {
				fn_decl = &tmp->function_declarator;
			} else {
				fprintf(stderr, "ERROR: Expected a standard `setter` function declarator! Found AST node id %d (%s) instead\n", tmp->type, get_node_name(tmp->type));
				exit(EXIT_FAILURE);
			}
		} else if (tmp->type == AST_FUNCTION_DECLARATOR) {
			fn_decl = &tmp->function_declarator;
		} else if (tmp->type == AST_LIST) {
			tmp = tmp->list.node;
			if (tmp->type == AST_ID) {
				fprintf(stderr, "Setter: >>> TTT %s\n", tmp->id.id);
				exit(EXIT_FAILURE);
			}
			fprintf(stderr, "Setter: Found AST node id %d\n", tmp->type);
			exit(EXIT_FAILURE);
			//fn_decl = &tmp->function_declarator;
		} else {
			fprintf(stderr, "Unsupported `setter` syntax or structure! Found AST node id %d (%s) instead\n", tmp->type, get_node_name(tmp->type));
			exit(EXIT_FAILURE);
		}

		//	Detect if there is a `non-setter` function with the same name! Why do we need to check this???
		// sprintf(func_name, "%s__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);
		// if (hash_map_get_value(&impl_functions, func_name) || hash_map_get_value(&global_scope_symbols, func_name)) {
		// 	fprintf(stderr, "Error: `setter` and `non-setter` function with the same name detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 	exit(EXIT_FAILURE);
		// }

		sprintf(func_name, "%s__set__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);

		//	NEW symbol table!
		//symbol = symbol_add_setter(func_name, node);

		// // Add the function name to the impl symbol table
		// fn_impl = (impl_t *) hash_map_get_value(&impl_functions, func_name);
		// if (fn_impl == NULL) {
		// 	fn_impl = new__impl(node);
			
		// 	fn_impl->is_setter = true;

		// 	if (node->function_definition.block == NULL) {
		// 		fn_impl->has_declaration = true;
		// 	} else {
		// 		fn_impl->has_definition = true;
		// 	}

		// 	hash_map_add(&impl_functions, func_name, fn_impl);
		// } else {
		// 	// TODO: Check the function signature of both the declaration and definition!
		// 	if (node->function_definition.block) {
		// 		if (fn_impl->has_definition == false) {
		// 			fn_impl->has_definition = true;
		// 		} else {
		// 			fprintf(stderr, "Error: Duplicate function definition detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 			exit(EXIT_FAILURE);
		// 		}
		// 	} else {
		// 		if (fn_impl->has_declaration == false) {
		// 			fn_impl->has_declaration = true;
		// 		} else {
		// 			fprintf(stderr, "Error: Duplicate function declaration detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 			exit(EXIT_FAILURE);
		// 		}
		// 		// fn_impl->has_declaration = true;
		// 	}
		// 	// fprintf(stderr, "Error: Duplicate function name detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 	// exit(EXIT_FAILURE);
		// }

		fn_decl->direct_declarator = create_id_node(func_name);

		prepend_this_or_self_to_params(node, fn_decl, parent);

		// expand_function_calls(node->function_definition.block, node);

		break;

	case AST_IMPL_FUNCTION_DECLARATION:
		break;

		//	disabling the code below! Will be removed later!

		node->type = AST_FUNCTION_DEFINITION;
		tmp = node->function_definition.declarator;
		if (tmp->type == AST_POINTER_DECLARATOR) {
			tmp = tmp->pointer_declarator.direct_declarator;
			if (tmp->type == AST_FUNCTION_DECLARATOR) {
				fn_decl = &tmp->function_declarator;
			} else {
				fprintf(stderr, "Expected a standard `impl` function declarator! Found AST node id %d (%s) instead of function declarator\n", tmp->type, get_node_name(tmp->type));
				exit(EXIT_FAILURE);
			}
		} else if (tmp->type == AST_FUNCTION_DECLARATOR) {
			fn_decl = &tmp->function_declarator;
		} else {
			fprintf(stderr, "Unsupported `impl` syntax or structure! Found AST node id %d (%s) instead of function declarator\n", tmp->type, get_node_name(tmp->type));
			exit(EXIT_FAILURE);
		}

		sprintf(func_name, "%s__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);

		//symbol = symbol_add_function(func_name, node);

		// // Add the function name to the global symbol table
		// fn_impl = (impl_t *) hash_map_get_value(&impl_functions, func_name);
		// if (fn_impl == NULL) {
		// 	fn_impl = new__impl(node);

		// 	fn_impl->is_function = true;

		// 	if (node->function_definition.block == NULL) {
		// 		fn_impl->has_declaration = true;	//	Will always be true!
		// 	} else {
		// 		fn_impl->has_definition = true;
		// 	}

		// 	hash_map_add(&impl_functions, func_name, fn_impl);
		// } else {
		// 	// NOTE: At this point, we've detected that we already have a function with this name. We need to determine if there is an existing definition or not!
		// 	if (fn_impl->has_definition == true) {
		// 		fprintf(stderr, "Error: Redeclaration of function definition: %s in `impl %s`\n", fn_decl->direct_declarator->id.id, parent->impl.id->id.id);
		// 		exit(EXIT_FAILURE);
		// 	}
		// 	// TODO: Make sure this function declaration is exactly the same as the other one!
		// }

		//	Rename the function!
		fn_decl->direct_declarator = create_id_node(func_name);

		break;

	case AST_FUNCTION_DEFINITION:
		tmp = node->function_definition.declarator;
		if (tmp->type == AST_POINTER_DECLARATOR) {
			tmp = tmp->pointer_declarator.direct_declarator;
			if (tmp->type == AST_FUNCTION_DECLARATOR) {
				fn_decl = &tmp->function_declarator;
			} else {
				// TODO: Handle a pointer pointer eg. `int (*(*foo)(int))();`
				// TODO: Handle a double pointer eg. `int (**foo)(int);`
				// TODO: Handle a pointer to a pointer eg. `Car **foo(int);`
				fprintf(stderr, "Expected a standard function declarator! Found AST node id %d instead\n", tmp->type);
				exit(EXIT_FAILURE);
			}
		} else if (tmp->type == AST_FUNCTION_DECLARATOR) {
			fn_decl = &tmp->function_declarator;
		} else {
			fprintf(stderr, "Expected a standard function declarator! Found AST node id %d instead\n", tmp->type);
			exit(EXIT_FAILURE);
		}

		// //	Detect if there is a `getter` or `setter` function with the same name!
		// sprintf(func_name, "%s__get__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);
		// if (hash_map_get_value(&impl_functions, func_name)) {
		// 	fprintf(stderr, "Error: `getter` and `non-getter` function with the same name detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 	exit(EXIT_FAILURE);
		// }
		// sprintf(func_name, "%s__set__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);
		// if (hash_map_get_value(&impl_functions, func_name)) {
		// 	fprintf(stderr, "Error: `setter` and `non-setter` function with the same name detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 	exit(EXIT_FAILURE);
		// }

		//	TODO: Check if the function signature is the same as the declaration! (if it exists) For now, we can just leave it to the compiler to do this for us!

		sprintf(func_name, "%s__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);


		//symbol = symbol_add_function(func_name, node);


		// // Add the function name to the global impl symbol table
		// fn_impl = (impl_t *) hash_map_get_value(&impl_functions, func_name);
		// if (fn_impl == NULL) {
		// 	fn_impl = new__impl(node);

		// 	if (node->function_definition.block == NULL) {
		// 		fn_impl->has_declaration = true;
		// 	} else {
		// 		fn_impl->has_definition = true;
		// 	}

		// 	hash_map_add(&impl_functions, func_name, fn_impl);
		// } else {
		// 	fprintf(stderr, "Error: Duplicate function name detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 	exit(EXIT_FAILURE);
		// }

		fn_decl->direct_declarator = create_id_node(func_name);



/*
		// Prepend `self` or `this` to the parameter list!

		if (fn_decl->identifier_list) {
			assert(fn_decl->identifier_list->type == AST_CONST);
			decl_specs = create_list_node(fn_decl->identifier_list, parent->impl.id, " ");
			fn_decl->identifier_list = NULL;
		} else {
			decl_specs = parent->impl.id;
		}

		this_or_self = node->function_definition.block ? find_this_or_self_id(node->function_definition.block) : NULL;
		tmp = create_parameter_declaration_node(decl_specs, create_pointer_declarator_node(create_pointer_node(NULL, NULL), this_or_self));

		fn_decl->params = fn_decl->params == NULL ? tmp : create_list_node(tmp, fn_decl->params, ", ");
*/

		prepend_this_or_self_to_params(node, fn_decl, parent);



//		expand_function_calls(node->function_definition.block, node);

		break;
	}
}

void process_static_impl(union ast_node *node, union ast_node *parent)
{
	if (node == NULL) return;

	struct ast_function_declarator_node *fn_decl;
	union ast_node *tmp;

	switch (node->type) {

	case AST_STATIC_IMPL:
		//	Make sure we are at the GLOBAL symbol table level! ie. index 0 in the symbol table ... this is only really useful for debugging!
		// assert(symbol_table_get_level() == 0);
		if (symbol_table_get_level() != 0) {
			fprintf(stderr, "`impl` statements may only appear at the root level!\n"); // I think this is redundant! We can just leave the assert()!
			if (flags.debug) {
				symbol_table_print(stderr);
			}
			assert(symbol_table_get_level() == 0); // will show us the level! ... only debug mode or without NDEBUG!
			exit(EXIT_FAILURE);
		}

		detach_impl_body(node, parent);

		//	Step 2: Loop through all the functions in the "impl" block and rename them!
		process_static_impl(node->impl.body, node);

		//	Step 3: Loop through the functions code blocks, and expand all function calls and getter/setter calls!
		break;

	case AST_LIST:
		process_static_impl(node->list.node, parent);
		process_static_impl(node->list.next, parent);
		break;

	case AST_FUNCTION_DEFINITION:
		tmp = node->function_definition.declarator;
		if (tmp->type == AST_POINTER_DECLARATOR) {
			tmp = tmp->pointer_declarator.direct_declarator;
			if (tmp->type == AST_FUNCTION_DECLARATOR) {
				fn_decl = &tmp->function_declarator;
			} else {
				// TODO: Handle a pointer pointer eg. `int (*(*foo)(int))();`
				// TODO: Handle a double pointer eg. `int (**foo)(int);`
				// TODO: Handle a pointer to a pointer eg. `Car **foo(int);`
				fprintf(stderr, "Expected a standard function declarator! Found AST node id %d instead\n", tmp->type);
				exit(EXIT_FAILURE);
			}
		} else if (tmp->type == AST_FUNCTION_DECLARATOR) {
			fn_decl = &tmp->function_declarator;
		} else {
			fprintf(stderr, "Expected a standard function declarator! Found AST node id %d instead\n", tmp->type);
			exit(EXIT_FAILURE);
		}

		// //	Detect if there is a `getter` or `setter` function with the same name!
		// sprintf(func_name, "%s__get__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);
		// if (hash_map_get_value(&impl_functions, func_name)) {
		// 	fprintf(stderr, "Error: `getter` and `non-getter` function with the same name detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 	exit(EXIT_FAILURE);
		// }
		// sprintf(func_name, "%s__set__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);
		// if (hash_map_get_value(&impl_functions, func_name)) {
		// 	fprintf(stderr, "Error: `setter` and `non-setter` function with the same name detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
		// 	exit(EXIT_FAILURE);
		// }

		//	TODO: Check if the function signature is the same as the declaration! (if it exists) For now, we can just leave it to the compiler to do this for us!

		sprintf(func_name, "%s__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);
		//symbol = symbol_add_function(func_name, node);
		fn_decl->direct_declarator = create_id_node(func_name);
		break;

	case AST_GETTER:
		node->type = AST_FUNCTION_DEFINITION;
		tmp = node->function_definition.declarator;
		if (tmp->type == AST_POINTER_DECLARATOR) {
			tmp = tmp->pointer_declarator.direct_declarator;
			if (tmp->type == AST_FUNCTION_DECLARATOR) {
				fn_decl = &tmp->function_declarator;
			} else {
				fprintf(stderr, "ERROR: Expected a standard `getter` function declarator! Found AST node id %d (%s) instead\n", tmp->type, get_node_name(tmp->type));
				exit(EXIT_FAILURE);
			}
		} else if (tmp->type == AST_FUNCTION_DECLARATOR) {
			fn_decl = &tmp->function_declarator;
		} else if (tmp->type == AST_LIST) {
			tmp = tmp->list.node;
			if (tmp->type == AST_ID) {
				fprintf(stderr, ">>> TTT %s\n", tmp->id.id);
				exit(EXIT_FAILURE);
			}
			fprintf(stderr, "Found AST node id %d\n", tmp->type);
			exit(EXIT_FAILURE);
		} else {
			fprintf(stderr, "Unsupported `getter` syntax or structure! Found AST node id %d (%s) instead\n", tmp->type, get_node_name(tmp->type));
			exit(EXIT_FAILURE);
		}

		sprintf(func_name, "%s__get__%s", parent->impl.id->id.id, fn_decl->direct_declarator->id.id);
		//symbol = symbol_add_getter(func_name, node);
		fn_decl->direct_declarator = create_id_node(func_name);
		break;

	default:
		//	NOTE: An end user should never see this! Because we should have already filtered out the invalid AST nodes during parsing!
		fprintf(stderr, "Error: Unexpected AST node %s (%d) in `%s!\n", get_node_name(node->type), node->type, __func__);
		exit(EXIT_FAILURE);
		break;
	}
}




void process_impl_blocks(union ast_node *node, union ast_node *parent)
{
	if (node == NULL) return;

	// union ast_node *tmp;
	// symbol_t *symbol;

	switch (node->type) {

	//	-----------------------------------------------------------------------
	//			AST_LIST
	//	-----------------------------------------------------------------------

	case AST_LIST:
		process_impl_blocks(node->list.node, node);
		process_impl_blocks(node->list.next, node);
		break;

	//	-----------------------------------------------------------------------
	//			Super C extensions
	//	-----------------------------------------------------------------------

	case AST_IMPL:
		process_impl(node, parent);
		break;

	case AST_STATIC_IMPL:
		process_static_impl(node, parent);
		break;

	case AST_GENERIC_IMPL:
		// if (node->impl.id->type == AST_GENERIC_DECLARATION) {


		// // 	//	Store the node in the symbol table for processing later!
		// // 	const char *name = get_generic_impl_name(node->impl.id);
		// // 	//	TODO: We should remove the node from the AST; create a new node, move the node into it, and set this one to NULL!
		// // 	symbol_add_generic_impl(name, node);
		// // } else if (node->impl.id->type == AST_GENERIC_SPECIFIER) {



// 			const char *name = get_generic_impl_name(node->impl.id);
// 			symbol = symbol_get(name);

// printf("AST_GENERIC_IMPL ===> AST_GENERIC_DECLARATION: %s\n", name);




/*
printf("symbol->is_generic: %d\n", symbol->is_generic);
printf("symbol->is_struct: %d\n", symbol->is_struct);

printf("symbol->is_union: %d\n", symbol->is_union);
printf("symbol->is_function: %d\n", symbol->is_function);
printf("symbol->is_variable: %d\n", symbol->is_variable);
printf("symbol->is_typedef: %d\n", symbol->is_typedef);
printf("symbol->is_setter: %d\n", symbol->is_setter);
printf("symbol->is_getter: %d\n", symbol->is_getter);
printf("symbol->is_pointer: %d\n", symbol->is_pointer);
printf("symbol->is_generic_name: %d\n", symbol->is_generic_name);
printf("symbol->is_generic_type: %d\n", symbol->is_generic_type);
printf("symbol->is_generic_impl: %d\n", symbol->is_generic_impl);
*/
/*
			if (symbol == NULL || symbol->is_generic_impl == false) {
				tmp = node->impl.id->generic_type.id;
				if (tmp->type != AST_LIST || tmp->list.node->type != AST_ID || tmp->list.next->type != AST_ID) {
					fprintf(stderr, "FATAL ERROR: Unknown `impl` label, typename or invalid syntax structure\n");
					exit(EXIT_FAILURE);
				}
				fprintf(stderr, "Syntax error: Unknown or undeclared label or object for: `impl %s %s`!\n", tmp->list.node->id.id, tmp->list.next->id.id);
				exit(EXIT_FAILURE);
			}

			build_impl_from_generic(node, symbol->node);
printf("AST_GENERIC_IMPL ===> AST_GENERIC_DECLARATION ===> codegen()\n");
print_ast_tree(stdout, node, 0, NULL);
			codegen(out, node, depth, parent);
printf("============================================================\n");

		} else {
			fprintf(stderr, "ERROR: Unknown AST_GENERIC_IMPL type detected in `.id` node. Only AST_GENERIC_DECLARATION is supported!!\n");
			exit(EXIT_FAILURE);
		}


printf("AST_GENERIC_IMPL\n");
print_ast_tree(stdout, node, 0, NULL);
printf("name: %s\n", get_generic_impl_name(node->impl.id));
		// symbol_add_generic_impl(node, node);
		break;
*/

	case AST_GENERIC_STATIC_IMPL:		//	NOTE: 'might' be needed?
		break;

	default:
		break;
	}
}






// This is the function that searches a function body for use of either `this` or `self`.
// If we find an AST_THIS or AST_SELF, then we use that as the name of the first parameter.
// This allows us to support BOTH `this` and `self` in method bodies, (but obviously only one at a time!)
union ast_node *find_this_or_self_id(union ast_node *node)
{
	if (node == NULL) return NULL;

	union ast_node *tmp;

	switch (node->type) {
	case AST_THIS: return node;
	case AST_SELF: return node;

	// case AST_ID:
	// 	if (strcmp(block->id.id, "this") == 0) {
	// 		return block;
	// 	}
	// 	if (strcmp(block->id.id, "self") == 0) {
	// 		return block;
	// 	}
	// 	break;

	// case AST_ID:
	// 	if (strcmp(block->id.id, "this") == 0 || strcmp(block->id.id, "self") == 0) {
	// 		return block;
	// 	}
	// 	break;

	case AST_BLOCK:
		return find_this_or_self_id(node->block.stmts);

	case AST_LIST:
		tmp = find_this_or_self_id(node->list.node);
		return tmp ? tmp : find_this_or_self_id(node->list.next);

	case AST_DECLARATION:
		//	There are probably 3 possibilities here:
		//	Self *self;
		//	Self *self = xyz;		//	AST_INIT_DECLARATOR { .init_declarator_list = AST_POINTER_DECLARATOR (.direct_declarator == AST_SELF) }
		//	Foo *tmp;
		//	Self *tmp = self;		//	AST_INIT_DECLARATOR => AST_POINTER_DECLARATOR + AST_SELF
		//	Foo *tmp = self.foo;	//	AST_INIT_DECLARATOR => AST_POINTER_DECLARATOR + AST_SELF
		// tmp = node->declaration.init_declarator_list;
		// if (tmp) {
		// 	if (tmp->type == AST_SELF || tmp->type == AST_THIS) {
		// 		return (void *) & static_node;
		// 	}
		// }
		tmp = find_this_or_self_id(node->declaration.init_declarator_list);
		//	NOTE: .init_declarator_list CAN be NULL (just declare `int;` without a name)!
		//	BUT if `tmp` is NOT NULL, then .init_declarator_list is also NOT NULL!
//printf("AST_DECLARATION: tmp->type: %d %s\n", tmp ? tmp->type : 0, get_node_name(tmp ? tmp->type : 0));
		if (tmp && node->declaration.init_declarator_list->type != AST_INIT_DECLARATOR) {
			break;
		}
		return tmp;
		// If `tmp` is not NULL, I need to cancel the search, because there was a `this` or `self` in the declaration!
		// That means it's probably a static method!
		// Using a `static_node` to indicate that the search should be canceled.
		// This means that a local variable was defined and called `this` or `self` and should indicate a 'static method'.
		// return tmp ? (void *) & static_node : find_this_or_self_id(node->declaration.init_declarator_list);

	case AST_INIT_DECLARATOR:
		//	So `AST_INIT_DECLARATOR` handles a separate scenario, and that's why it's filtered out above!
		//	You CAN have a `this` or `self` in the `.initializer`, but NOT in the `.declarator`
		tmp = find_this_or_self_id(node->init_declarator.declarator);
		//	You could do something like `int foo[this] = 0;`
		if (tmp) {
			if (node->init_declarator.declarator->type != AST_ARRAY) {
				break;
			}
			return tmp; // `this` or `self` was used to initialize an array member!?!?
		}
		return find_this_or_self_id(node->init_declarator.initializer);

	case AST_POINTER_DECLARATOR:
		return find_this_or_self_id(node->pointer_declarator.direct_declarator);

	case AST_EXPRESSION_STATEMENT:
		return find_this_or_self_id(node->unary.expr);

	case AST_TERNARY:
		tmp = find_this_or_self_id(node->ternary.cond);
		if (tmp) return tmp;
		tmp = find_this_or_self_id(node->ternary.true_expr);
		if (tmp) return tmp;
		return find_this_or_self_id(node->ternary.false_expr);

	case AST_IF:
		tmp = find_this_or_self_id(node->if_stmt.cond);
		if (tmp) return tmp;
		tmp = find_this_or_self_id(node->if_stmt.if_true);
		if (tmp) return tmp;
		return find_this_or_self_id(node->if_stmt.if_false); // NOTE: We don't need to do an explicit `if_false == NULL` test! It's done at the top of the function!

	case AST_SWITCH:
		tmp = find_this_or_self_id(node->switch_stmt.expr);
		return tmp ? tmp : find_this_or_self_id(node->switch_stmt.stmt);

	case AST_WHILE:
		tmp = find_this_or_self_id(node->while_stmt.cond);
		return tmp ? tmp : find_this_or_self_id(node->while_stmt.body);

	case AST_DO_WHILE:
		tmp = find_this_or_self_id(node->do_while_stmt.body);
		return tmp ? tmp : find_this_or_self_id(node->do_while_stmt.cond);

	case AST_FOR:
		tmp = find_this_or_self_id(node->for_stmt.init);
		if (tmp) return tmp;
		tmp = find_this_or_self_id(node->for_stmt.cond);
		if (tmp) return tmp;
		tmp = find_this_or_self_id(node->for_stmt.incr);
		if (tmp) return tmp;
		return find_this_or_self_id(node->for_stmt.body);

	case AST_RETURN:
		return find_this_or_self_id(node->return_stmt.expr);

	case AST_ARRAY:
		tmp = find_this_or_self_id(node->array.direct_declarator);
		if (tmp) {
			break;	//	I think this is checking if `this` or `self` was in the name?
		}
		return find_this_or_self_id(node->array.expr);

	case AST_ARRAY_SUBSCRIPT:
		tmp = find_this_or_self_id(node->array_subscript.array);
		return tmp ? tmp : find_this_or_self_id(node->array_subscript.index);

	case AST_UNSPECIFIED_ARRAY:	//	eg. `int a[] = {1, 2, 3};`
		return find_this_or_self_id(node->unspecified_array.direct_declarator);

	case AST_FUNCTION_CALL:	//	HOW does this work? Where will `this` or `self` be in a function call???
		tmp = find_this_or_self_id(node->function_call.function);	// I think a function called `this` or `self` is a problem!!
		if (tmp) {	//	`this` or `self` was used as a function call NAME!
			return tmp;		//	I believe this should fix `this` or `self` being used in a function call!
		}
		//if (tmp) return tmp;
		return find_this_or_self_id(node->function_call.args);

	// case AST_FUNCTION_DECLARATOR:	//	Do I need this? Is this valid?
	// 	return find_this_or_self_id(node->function_declarator.params);

	case AST_MEMBER_ACCESS:
	case AST_MEMBER_ACCESS_POINTER:
		return find_this_or_self_id(node->member_access.object);

		//	We don't support finding `this` or `self` as a member name!
		//	eg. `foo.this` or `foo->self` ... they might have a structure member called `this` or `self`!
		// tmp = find_this_or_self_id(node->member_access.object);
		// if (tmp) return tmp;
		// return find_this_or_self_id(node->member_access.member);

	case AST_PRE_INC:
	case AST_PRE_DEC:
	case AST_SIZEOF_EXPR:
	case AST_SIZEOF_TYPE:
	case AST_ALIGNOF:
	case AST_ADDRESS_OF:
	// case AST_DEREF:
	case AST_DEREFERENCE:
	case AST_POSITIVE:
	case AST_NEGATIVE:
	case AST_BITWISE_NOT:
	case AST_LOGICAL_NOT:
	case AST_POST_INC:
	case AST_POST_DEC:
		return find_this_or_self_id(node->unary.expr);

	case AST_ASSIGN:
	case AST_MUL_ASSIGN:
	case AST_DIV_ASSIGN:
	case AST_MOD_ASSIGN:
	case AST_ADD_ASSIGN:
	case AST_SUB_ASSIGN:
	case AST_SHL_ASSIGN:
	case AST_SHR_ASSIGN:
	case AST_AND_ASSIGN:
	case AST_XOR_ASSIGN:
	case AST_OR_ASSIGN:
	case AST_OR:
	case AST_AND:
	case AST_BIT_OR:
	case AST_BIT_XOR:
	case AST_BIT_AND:
	case AST_EQ:
	case AST_NE:
	case AST_LT:
	case AST_GT:
	case AST_LE:
	case AST_GE:
	case AST_SHL:
	case AST_SHR:
	case AST_ADD:
	case AST_SUB:
	case AST_MUL:
	case AST_DIV:
	case AST_MOD:
		tmp = find_this_or_self_id(node->binary.left);
		return tmp ? tmp : find_this_or_self_id(node->binary.right);

	case AST_CAST:
		return find_this_or_self_id(node->cast.expr);

	case AST_COMPOUND_LITERAL:
		return find_this_or_self_id(node->compound_literal.init_list);

	case AST_PARAMETER_DECLARATION:
		return find_this_or_self_id(node->parameter_declaration.declarator);

	case AST_INITIALIZER:
		return find_this_or_self_id(node->initializer.list);

	case AST_LABEL:
		return find_this_or_self_id(node->label.stmt);
	
	case AST_CASE:
		tmp = find_this_or_self_id(node->case_stmt.expr);
		return tmp ? tmp : find_this_or_self_id(node->case_stmt.stmt);

	case AST_DEFAULT:
		return find_this_or_self_id(node->default_stmt.stmt);

	//	Depends on if I want to explicitly support EVERY kind of node, or if we just have a `default: return NULL;`
	//	Currently, I've gone with `default: return NULL;` ... but ...
	//	The problem is, users might not know that they're using a node type that I don't support!
	//	What this means, is that if a user used `this` or `self` in a node type we haven't added, we might not pick it up!
	case AST_NUMERIC:
	case AST_PRAGMA:
		return NULL;

	case AST_ID:
		return NULL;	//	don't need this if we treat all non-found nodes as 'NULL'!

	default:
		return NULL;
		// fprintf(stderr, "ERROR: Unsupported node type `%s` (%d) in `%s()`!", get_node_name(node->type), node->type, __func__);
		// fprintf(stderr, "It's not you, it's us! We probably need to add this node type! Please report this issue!\n");
		// exit(EXIT_FAILURE);
	}

	fprintf(stderr, "`%s` is not allowed as a local variable name in methods within `impl` blocks!\n", tmp->type == AST_SELF ? "self" : "this");
	exit(EXIT_FAILURE);

	return NULL;
}


void process_new_function(union ast_node *node, union ast_node *parent)
{
	union ast_node *tmp;

	node->type = AST_FUNCTION_DEFINITION;
	tmp = node->function_definition.declarator;
	if (tmp->type == AST_IMPL_NEW_DECLARATOR) {
		tmp->type = AST_POINTER_DECLARATOR;
		tmp = tmp->pointer_declarator.direct_declarator;
		if (tmp->type == AST_FUNCTION_DECLARATOR) {
			sprintf(func_name, "%s__new", parent->impl.id->id.id);

			// Add the function name to the global symbol table
			//symbol_t *symbol = symbol_add_function(func_name, node);
			//	TODO: Check that a function with this name doesn't already exist!


			// fn_impl = (impl_t *) hash_map_get_value(&impl_functions, func_name);
			// if (fn_impl == NULL) {
			// 	hash_map_add(&impl_functions, func_name, node);
			// } else {
			// 	fprintf(stderr, "Error: Duplicate `new` function detected: %s in `impl %s`\n", func_name, parent->impl.id->id.id);
			// 	exit(EXIT_FAILURE);
			// }

			// Rename the `new` function
			tmp->function_declarator.direct_declarator = create_id_node(func_name);
			return;
		}
	}
	fprintf(stderr, "Unsupported `new` operator syntax or structure!!\n");
	exit(EXIT_FAILURE);
}



