#include "compass_generics.h"
#include "traverse_ast.h"
#include "scc.h"
#include "ast_helpers.h"
#include "ast_nodes.h"
#include "print_ast_tree.h"
#include "print_syntax.h"
#include "symbol_table.h"

#include <assert.h>
#include <string.h>
#include <ctype.h>

void handle_typedef(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table); // AST_TYPEDEF

void handle_generic_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table); // AST_GENERIC_DECLARATION
void handle_generic_specifier(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table); // AST_GENERIC_SPECIFIER
void handle_generic_struct(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table); // AST_GENERIC_STRUCT
void handle_generic_union(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table); // AST_GENERIC_UNION

// void is_generic_decl(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

void handle_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table, union ast_node *context); // AST_DECLARATION
// void handle_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table,
// 						union ast_node *context, const char *name, union ast_node *name_node); // AST_DECLARATION

union ast_node *get_base_context(union ast_node *node);
void register_generic(union ast_node *node);
const char *get_generic_name(union ast_node *node);	//	eg. `Foo`
void handle_real_generic_decl(union ast_node *node, union ast_node *context);
void validate_generic_type_list(union ast_node *node);
void build_generic_typedef(union ast_node *node, union ast_node *context);

char *get_original_generic_type_name(union ast_node *node);

void handle_generic_specifier_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table,
										union ast_node *context, const char *name, union ast_node *name_node);

// compiler-pass entry point
void process_generic_decls(union ast_node *root_node)
{
	static traversal_jump_table_t jump_table[AST__LAST__] = { 0 };

	init_traversal_jump_table(jump_table);

	// jump_table[AST_TYPEDEF].function = handle_typedef;

	// jump_table[AST_GENERIC_DECLARATION].function = handle_generic_declaration;	//	These are currently ALWAYS preceded by `AST_GENERIC_STRUCT` or `AST_GENERIC_UNION`. So they should handle this case!
	jump_table[AST_GENERIC_SPECIFIER].function = handle_generic_specifier;
	jump_table[AST_GENERIC_STRUCT].function = handle_generic_struct;
	jump_table[AST_GENERIC_UNION].function = handle_generic_union;

	traverse_ast(root_node, NULL, jump_table);
}

//	***************************************************************************
//	handle (valid) AST_TYPEDEF declarations
//	***************************************************************************
//	Variation 1: `typedef struct Foo<> Foo<int>;`
/*
AST_DECLARATION						<-- `context`
|- .decl_specs
	AST_LIST
	|- .node
		AST_TYPEDEF
	|- .next
		AST_LIST
		|- .node
			AST_GENERIC_STRUCT		<-- `node`
			|- .id
				AST_GENERIC_DECLARATION
				|- .id
					AST_ID: `Foo`
				|- .type_list
					NULL
			|- .decl_list
				NULL
		|- .next
			AST_GENERIC_SPECIFIER
			|- .id
				AST_ID: `Foo`
			|- .type_list
				AST_INT
|- .init_declarator_list
	NULL
*/
//	Variation 2: `typedef struct Foo<int> FooInt;`
/*
AST_DECLARATION						<-- `context`
|- .decl_specs
	AST_LIST
	|- .node
		AST_TYPEDEF
	|- .next
		AST_GENERIC_STRUCT			<-- `node`
		|- .id
			AST_GENERIC_DECLARATION
			|- .id
				AST_ID: `Foo`
			|- .type_list
				AST_INT
		|- .decl_list
			NULL
|- .init_declarator_list
	AST_ID: `FooInt`
*/
//	Variation 3: `typedef Foo<int> FooInt;`
/*
AST_DECLARATION						<-- `context`
|- .decl_specs
	AST_LIST
	|- .node
		AST_TYPEDEF
	|- .next
		AST_GENERIC_SPECIFIER		<-- `node`
		|- .id
			AST_ID: `Foo`
		|- .type_list
			AST_INT
|- .init_declarator_list
	AST_ID: `FooInt`
*/
// `typedef struct Foo<> Foo<int>;` => `typedef struct Foo__int Foo__int;`
// `typedef struct Foo<int> FooInt;` => `typedef struct Foo__int FooInt;`
// `typedef struct Foo<T> { ... } Foo<int>;` => NOT SUPPORTED!
void build_generic_typedef(union ast_node *node, union ast_node *context)
{
	// assert(context->declaration.init_declarator_list == NULL);

	union ast_node *decl_specs = context->declaration.decl_specs;
	union ast_node *next = decl_specs->list.next;
	const char *name;

	//	Variation 1: `typedef struct Foo<> Foo<int>;`
	/*
	AST_DECLARATION						<-- `context`
	|- .decl_specs						<-- `decl_specs`
		AST_LIST
		|- .node
			AST_TYPEDEF
		|- .next						<-- `next`
			AST_LIST
			|- .node
				AST_GENERIC_STRUCT		<-- `node`
				|- .id
					AST_GENERIC_DECLARATION
					|- .id
						AST_ID: `Foo`
					|- .type_list
						NULL
				|- .decl_list
					NULL
			|- .next
				AST_GENERIC_SPECIFIER
				|- .id
					AST_ID: `Foo`
				|- .type_list
					AST_INT
	|- .init_declarator_list
		NULL
	*/
	if (next->type == AST_LIST) {
printf("Variation 1\n");
print_ast_tree(stdout, context, 0);
		if (next->list.node->type != AST_GENERIC_STRUCT
		&&  next->list.node->type != AST_GENERIC_UNION
		&&  next->list.next->type != AST_GENERIC_SPECIFIER) {	//	NOTE: This line checks `.next`
			print_original_syntax(
				node->struct_or_union.id->generic_type.filename,
				node->struct_or_union.id->generic_type.line,
				"Syntax error: Unsupported `typedef` syntax for `%s`.\n",
				get_original_generic_type_name(node)
			);
			exit(EXIT_FAILURE);
		}

		//	FINALLY replace the nodes in the AST!
		name = get_generic_type_name(decl_specs->list.next->list.next);
		union ast_node *name_node = create_id_node(name);
		decl_specs->list.next->list.node->type = AST_STRUCT;
		decl_specs->list.next->list.node->struct_or_union.id = name_node;
		decl_specs->list.next->list.next = name_node;

		//	TODO: Add this typedef to the symbol table!

		//	TODO: If the base generic struct has a `decl_list`, then we need to build our generic after this typedef!

		return;
	}

	//	How is this possible? `typedef struct Foo<int>;` <== INVALID! It didn't pass the test above to have an `AST_LIST` node!
	if (context->declaration.init_declarator_list == NULL) {
		print_original_syntax(
			node->struct_or_union.id->generic_type.filename,
			node->struct_or_union.id->generic_type.line,
			"Syntax error: Invalid generic `typedef` syntax for `%s`.\n",
			get_original_generic_type_name(node)
		);
		exit(EXIT_FAILURE);
	}

	//	Variation 2: `typedef struct Foo<int> FooInt;`
	/*
	AST_DECLARATION						<-- `context`
	|- .decl_specs						<-- `decl_specs`
		AST_LIST
		|- .node
			AST_TYPEDEF
		|- .next						<-- `next`
			AST_GENERIC_STRUCT			<-- `node`
			|- .id
				AST_GENERIC_DECLARATION
				|- .id
					AST_ID: `Foo`
				|- .type_list
					AST_INT
			|- .decl_list
				NULL
	|- .init_declarator_list
		AST_ID: `FooInt`
	*/
	if (next->type == AST_GENERIC_STRUCT || next->type == AST_GENERIC_UNION) {
		assert(next == node);
		assert(next->struct_or_union.id->type == AST_GENERIC_DECLARATION);
		if (next->struct_or_union.decl_list != NULL) {
			print_original_syntax(
				node->struct_or_union.id->generic_type.filename,
				node->struct_or_union.id->generic_type.line,
				"Syntax error: Unsupported generic `typedef` syntax for %s.\n"
				"Due to the nature of generics, you cannot declare the generic type structure within a `typedef`, like you would with a normal `struct` or `union`.\n",
				get_generic_name(node)
			);
			exit(EXIT_FAILURE);
		}

printf("Variation 2\n");
print_ast_tree(stdout, context, 0);
		//	FINALLY replace the nodes in the AST!
		// name = get_generic_type_name(decl_specs->list.next->struct_or_union.id);
		name = get_generic_type_name(node->struct_or_union.id);
		union ast_node *name_node = create_id_node(name);
		node->type = node->type == AST_GENERIC_STRUCT ? AST_STRUCT : AST_UNION;
		node->struct_or_union.id = name_node;
		// decl_specs->list.next->list.next = name_node;
		return;
	}

printf("Variation 3 ................................................\n");

	//	Variation 3: `typedef Foo<int> FooInt;`
	/*
	AST_DECLARATION						<-- `context`
	|- .decl_specs						<-- `decl_specs`
		AST_LIST
		|- .node
			AST_TYPEDEF
		|- .next						<-- `next`
			AST_GENERIC_SPECIFIER		<-- `node`
			|- .id
				AST_ID: `Foo`
			|- .type_list
				AST_INT
	|- .init_declarator_list
		AST_ID: `FooInt`
	*/
	if (next->type == AST_GENERIC_SPECIFIER) {
		assert(next == node);
		assert(next->struct_or_union.id->type == AST_GENERIC_DECLARATION);
		if (next->struct_or_union.decl_list != NULL) {
			print_original_syntax(
				node->struct_or_union.id->generic_type.filename,
				node->struct_or_union.id->generic_type.line,
				"Syntax error: Unsupported generic `typedef` syntax for %s.\n"
				"Due to the nature of generics, you cannot declare the generic type structure within a `typedef`, like you would with a normal `struct` or `union`.\n",
				get_generic_name(node)
			);
			exit(EXIT_FAILURE);
		}

printf("Variation 3\n");
print_ast_tree(stdout, context, 0);
		//	FINALLY replace the nodes in the AST!
		// name = get_generic_type_name(decl_specs->list.next->struct_or_union.id);
		name = get_generic_type_name(node->struct_or_union.id);
		union ast_node *name_node = create_id_node(name);
		node->type = node->type == AST_GENERIC_STRUCT ? AST_STRUCT : AST_UNION;
		node->struct_or_union.id = name_node;
		// decl_specs->list.next->list.next = name_node;
		return;
	}
}



//	base context == AST_DECLARATION
//	NOTE: This is NOT called directly during AST traversal - because that would force us to evaluate every declaration!
//	We call this once we have esablished that the 'base context' of an `AST_GENERIC_STRUCT` node is an `AST_DECLARATION`
void handle_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table, union ast_node *context)
// void handle_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table,
// 						union ast_node *context, const char *name, union ast_node *name_node)
{
	union ast_node *decl_specs = context->declaration.decl_specs;

	if (decl_specs->type == AST_LIST) {
		if (decl_specs->list.node->type == AST_TYPEDEF) {
			build_generic_typedef(node, context);
			return;
		}
	}

	//	We must make sure that no future parser changes, lead to a `typedef` node that is NOT in the exact location we are expecting!
	//	We currently expect, and assume that ALL (currently valid) `typedef` declarations include an `AST_LIST` node with an `AST_TYPEDEF` node!
	if (is_typedef_node(decl_specs)) {
		print_original_syntax(
			node->struct_or_union.id->generic_type.filename,
			node->struct_or_union.id->generic_type.line,
			"Syntax error: Unsupported `typedef` syntax for generic called `%s`.\n", get_generic_name(node)
		);
		exit(EXIT_FAILURE);
	}

	//	Definately NOT a `typedef` from here!
	//	Could be a local variable declaration!

	union ast_node *init_decl_list = context->declaration.init_declarator_list;
	if (init_decl_list == NULL) {
		//	I think this is an error! I don't know of any situation where this would be valid!
		print_original_syntax(
			node->struct_or_union.id->generic_type.filename,
			node->struct_or_union.id->generic_type.line,
			"Syntax error: Unknown or unsupported syntax for generic called `%s`.\n", get_generic_name(node)
		);
		exit(EXIT_FAILURE);

	/*
		union ast_node *decl_specs = node->declaration.decl_specs;
		if (is_typeof_node(AST_GENERIC_SPECIFIER, decl_specs)) {
printf("FOUND GENERIC SPECIFIER!\n");
			//	Disabling the check for `typedef` ... to support `opaque` generics!
			//	Is the `typedef` check necessary?
			if (1 || is_typeof_node(AST_TYPEDEF, decl_specs)) {

				build_generic_struct(node);

				// printf("FOUND GENERIC SPECIFIER WITH TYPEDEF!\n");
				//	We need to generate the typedef here, because the generic type is not a real type, but a placeholder for a real type
				// indent(out, depth);
				// fprintf(out, "typedef struct %s {", get_generic_type_name(node->declaration.decl_specs));

					// Retrieve the generic template structure, and run through it while replacing the generic type with the real/concrete type

				// fprintf(out, " } %s;\n", get_generic_type_name(node->declaration.decl_specs));

				// TODO: We need to build/expand/replace the generic template structure!
				// break;
			} else {
// build_generic_struct(node);

			}
		} else if (is_typeof_node(AST_GENERIC_STRUCT, decl_specs) || is_typeof_node(AST_GENERIC_UNION, decl_specs)) {
printf("NOT FOUND GENERIC SPECIFIER!\n");
			// register_generic_struct_or_union(node);
			// break;
		}
	*/
	}


	// else ... node->declaration.init_declarator_list != NULL
	assert(init_decl_list != NULL);
	//	We need to rule out the case where the `init_declarator_list` is a generic type or invalid!!!
	//	NOTE: I don't think this is necessary! Because any kind of `generic` node doesn't actually set the `init_declarator_list`!
	if (init_decl_list->type != AST_ID) {
		if (init_decl_list->type != AST_INIT_DECLARATOR) {
			if (init_decl_list->type != AST_POINTER_DECLARATOR) {
				fprintf(stderr, "Syntax Error: Unexpected declarator list type: %s\n", get_node_name(init_decl_list->type));
				exit(EXIT_FAILURE);
			}
		}
	}

	//traverse_declaration_node(node, parent, jump_table);




	//	TODO:  CHECK  &&  VALIDATE  THIS !!!

	//	The code below was written in haste! Make sure this valid!


	const char *name = get_generic_type_name(node->struct_or_union.id);
	union ast_node *name_node = create_id_node(name);

	//	TODO: Check that the `type_list` is valid for a concrete type!
	int type = node->struct_or_union.type;
	assert(type == AST_GENERIC_STRUCT || type == AST_GENERIC_UNION);
	type = type == AST_GENERIC_STRUCT ? AST_STRUCT : AST_UNION;
	node->struct_or_union.type = type;
	node->struct_or_union.id = name_node;


}


//	UNUSED!
// AST_GENERIC_DECLARATION
void handle_generic_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	
}


void build_generic_specifier_typedef(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table,
	union ast_node *context, const char *name, union ast_node *name_node)
{
	union ast_node *decl_specs = context->declaration.decl_specs;

	assert(decl_specs->type == AST_LIST);
	assert(decl_specs->list.node->type == AST_TYPEDEF);
	// assert(decl_specs->list.next == node);

	symbol_t *concrete_symbol = symbol_get(name);	//	`name` == `Foo__int`

	const char *generic_name = get_generic_name(node->generic_type.id);	//	`generic_name` == `Foo`

	union ast_node *init_decl_list = context->declaration.init_declarator_list;
	if (init_decl_list != NULL) {
		//	`typedef Foo<int> FooInt;`
		if (decl_specs->list.next == node) {
			if (concrete_symbol == NULL || concrete_symbol->is_generic == false) {
				print_original_syntax(
					node->generic_type.filename,
					node->generic_type.line,
					"Syntax error: Concrete generic type `%s` has not been declared.\n",
					get_original_generic_type_name(node)
				);
				exit(EXIT_FAILURE);
			}

			if (init_decl_list->type != AST_ID) {
				print_original_syntax(
					node->generic_type.filename,
					node->generic_type.line,
					"Syntax error: Invalid syntax for generic type `%s`.\n",
					get_original_generic_type_name(node)
				);
				exit(EXIT_FAILURE);
			}

			//	This is kind of preparing for the day when we need to do a FULL symbol table!
			//	Because we are currently only adding the symbol from a generic `typedef`, what about a `typedef` from a `typedef` from another `typedef`?
			symbol_t *sym = symbol_add_typedef(init_decl_list->id.id, node);
			sym->is_struct = concrete_symbol->is_struct;
			sym->is_union = concrete_symbol->is_union;

			assert(decl_specs == parent);
			decl_specs->list.next = name_node;
			return;
		}

		print_original_syntax(
			node->generic_type.filename,
			node->generic_type.line,
			"Parser error in %s: Unhandled code syntax in the following AST structure; unhandled node type `%s` (%d).\n",
			__func__,
			get_node_name(decl_specs->list.next->type),
			decl_specs->list.next->type
		);
		print_ast_tree(stderr, context, 0);
		exit(EXIT_FAILURE);
	}

	assert(init_decl_list == NULL);

	//	`typedef Foo<int>;`
	if (decl_specs->list.next == node) {

		if (concrete_symbol != NULL) {
			print_original_syntax(
				node->generic_type.filename,
				node->generic_type.line,
				"Syntax error: Redefinition of `%s`. Generics may only be declared once.\n",
				get_original_generic_type_name(node)
			);
			exit(EXIT_FAILURE);
		}

		symbol_t *symbol = symbol_get(generic_name);
		if (symbol == NULL) {
symbol_table_print(stdout);
			print_original_syntax(
				node->generic_type.filename,
				node->generic_type.line,
				"Syntax error: Unknown type `%s`. Cannot determine if this is a `struct` or `union`. Please use the full syntax.\n",
				get_original_generic_type_name(node)
			);
			exit(EXIT_FAILURE);
		}

		if (symbol->is_generic == 0) {
			print_original_syntax(
				node->generic_type.filename,
				node->generic_type.line,
				"Syntax error: Invalid data type detected for `%s`. This is not the name of a generic.\n",
				name
			);
			exit(EXIT_FAILURE);
		}

		int type = symbol->is_struct ? AST_STRUCT : AST_UNION;

		//	TODO: We need to build the struct!

		decl_specs->list.next = create_list_node(
			create_struct_or_union_node(type, name_node, NULL),
			name_node,
			" "
		);

		return;
	}

	print_original_syntax(
		node->generic_type.filename,
		node->generic_type.line,
		"Syntax error: Unsupported `typedef` syntax for generic called `%s`.\n",
		name
	);
	exit(EXIT_FAILURE);
}


// Declarations can be: a `typedef`, a local variable, an opaque `struct` declaration, a forward declaration etc.
//	`typedef Foo<int> Foo<int>;`
void handle_generic_specifier_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table,
	union ast_node *context, const char *name, union ast_node *name_node)
{
	assert(context->type == AST_DECLARATION);

	union ast_node *decl_specs = context->declaration.decl_specs;

	if (decl_specs->type == AST_LIST) {
		if (decl_specs->list.node->type == AST_TYPEDEF) {
			build_generic_specifier_typedef(node, parent, jump_table, context, name, name_node);
			return;
		}
	}

	//	We must make sure that no future parser changes, lead to a `typedef` node that is NOT in the exact location we are expecting!
	//	We currently expect, and assume that ALL (currently valid) `typedef` declarations include an `AST_LIST` node with an `AST_TYPEDEF` node!
	if (is_typedef_node(decl_specs)) {
		print_original_syntax(
			node->generic_type.filename,
			node->generic_type.line,
			"Syntax error: Unsupported `typedef` syntax for generic called `%s`.\n",
			get_generic_name(node)
		);
		exit(EXIT_FAILURE);
	}

	//	Definately NOT a `typedef` from here!
	//	Could be a local variable declaration!

	if (parent == context) {
		assert(context->declaration.decl_specs == node);
		context->declaration.decl_specs = name_node;
		return;
	}

	//	TODO: What about `static` nodes!

	//	Just make sure that from here, the parent is DEFINATELY not the same as `context`, which we know is an `AST_DECLARATION` node!
	assert(parent->type != AST_DECLARATION);




	union ast_node *init_decl_list = context->declaration.init_declarator_list;
	if (init_decl_list == NULL) {
		//	I think this is an error! I don't know of any situation where this would be valid!
		print_original_syntax(
			node->generic_type.filename,
			node->generic_type.line,
			"Syntax error: Unknown or unsupported syntax for generic called `%s`.\n",
			get_generic_name(node)
		);
		exit(EXIT_FAILURE);

	/*
		union ast_node *decl_specs = node->declaration.decl_specs;
		if (is_typeof_node(AST_GENERIC_SPECIFIER, decl_specs)) {
printf("FOUND GENERIC SPECIFIER!\n");
			//	Disabling the check for `typedef` ... to support `opaque` generics!
			//	Is the `typedef` check necessary?
			if (1 || is_typeof_node(AST_TYPEDEF, decl_specs)) {

				build_generic_struct(node);

				// printf("FOUND GENERIC SPECIFIER WITH TYPEDEF!\n");
				//	We need to generate the typedef here, because the generic type is not a real type, but a placeholder for a real type
				// indent(out, depth);
				// fprintf(out, "typedef struct %s {", get_generic_type_name(node->declaration.decl_specs));

					// Retrieve the generic template structure, and run through it while replacing the generic type with the real/concrete type

				// fprintf(out, " } %s;\n", get_generic_type_name(node->declaration.decl_specs));

				// TODO: We need to build/expand/replace the generic template structure!
				// break;
			} else {
// build_generic_struct(node);

			}
		} else if (is_typeof_node(AST_GENERIC_STRUCT, decl_specs) || is_typeof_node(AST_GENERIC_UNION, decl_specs)) {
printf("NOT FOUND GENERIC SPECIFIER!\n");
			// register_generic_struct_or_union(node);
			// break;
		}
	*/
	}


	// else ... node->declaration.init_declarator_list != NULL
	assert(init_decl_list != NULL);
	//	We need to rule out the case where the `init_declarator_list` is a generic type or invalid!!!
	//	NOTE: I don't think this is necessary! Because any kind of `generic` node doesn't actually set the `init_declarator_list`!
	if (init_decl_list->type != AST_ID) {
		if (init_decl_list->type != AST_INIT_DECLARATOR) {
			if (init_decl_list->type != AST_POINTER_DECLARATOR) {
				fprintf(stderr, "Syntax Error: Unexpected declarator list type: %s\n", get_node_name(init_decl_list->type));
				exit(EXIT_FAILURE);
			}
		}
	}

	//traverse_declaration_node(node, parent, jump_table);


	//	TODO: Find and handle more scenarios!


	if (parent->type == AST_LIST) {
		if (parent->list.node == node) {
			parent->list.node = name_node;
		} else {
			assert(parent->list.next == node);
			parent->list.next = name_node;
		}
		return;
	}


	print_original_syntax(
		node->generic_type.filename,
		node->generic_type.line,
		"Parser error in %s(): Unhandled generic specifier syntax.\n",
		__func__
	);
	print_ast_tree(stdout, context, 0);
	exit(EXIT_FAILURE);
}

// AST_GENERIC_SPECIFIER
void handle_generic_specifier(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	assert(node->generic_type.id != NULL);
	// register_generic(node);

	union ast_node *context = get_base_context(node);
	const char *name = get_generic_type_name(node);
	union ast_node *name_node = create_id_node(name);

	switch (context->type)
	{
	case AST_DECLARATION:
printf("::AST_GENERIC_SPECIFIER::AST_DECLARATION::\n");
		handle_generic_specifier_declaration(node, parent, jump_table, context, name, name_node);
		break;

	case AST_PARAMETER_DECLARATION:	//	func(Foo<int> *foo)
	{
printf("::AST_GENERIC_SPECIFIER::AST_PARAMETER_DECLARATION::\n");
		union ast_node *decl_specs = context->parameter_declaration.decl_specs;

		if (decl_specs == node) {
			assert(parent->type == AST_PARAMETER_DECLARATION);
			assert(parent == context);
			context->parameter_declaration.decl_specs = name_node;
			return;
		}

		assert(decl_specs->type == AST_LIST);
		assert(parent->type == AST_LIST);
		if (parent->list.node == node) {
			parent->list.node = name_node;
		} else {
			assert(parent->list.next != NULL);
			assert(parent->list.next == node);
			parent->list.next = name_node;
		}
		break;
	}	//	NOTE: TODO: I think we need to "carry on" testing other parameters! They could be generic types too!

	case AST_FUNCTION_DEFINITION:	//	Foo<int> *func()
printf("::AST_GENERIC_SPECIFIER::AST_FUNCTION_DEFINITION::\n");
		assert(context->function_definition.decl_specs == node);
		assert(parent == context);
		context->function_definition.decl_specs = name_node;
		// decl_specs->list.next->list.next = name_node;
		return;

	case AST_ABSTRACT_TYPE_NAME:
printf("::AST_GENERIC_SPECIFIER::AST_ABSTRACT_TYPE_NAME::\n");
		assert(parent == context);
		assert(context->abstract_type_name.specifier_qualifier_list == node);
		context->abstract_type_name.specifier_qualifier_list = name_node;
		break;

	//	No longer supported, this falls under `AST_ABSTRACT_TYPE_NAME`
	case AST_CAST:
printf("::AST_GENERIC_SPECIFIER::AST_CAST::\n");
		assert(parent == context);
		assert(context->unary.expr == node);
		context->unary.expr = name_node;
		break;

	case AST_SIZEOF_TYPE:	//	sizeof(`type`)
printf("::AST_GENERIC_SPECIFIER::AST_SIZEOF_TYPE::\n");
		assert(parent == context);
		assert(context->unary.expr == node);
		context->unary.expr = name_node;
		break;

	case AST_SIZEOF_EXPR:	//	sizeof `expr`
printf("::AST_GENERIC_SPECIFIER::AST_SIZEOF_EXPR::\n");
		//	Currently unsupported! It doesn't even pass the parser!
		break;

	case AST_BLOCK:	//	How??? I doubt this is possible! It will probably land up in an `AST_DECLARATION` node!
printf("::AST_GENERIC_SPECIFIER::AST_BLOCK::\n");
		break;

	default:
printf("::UNKNOWN generic context::\n");
		break;
	}


return;
	//	Variation 3: `typedef Foo<int> FooInt;`
	/*
	AST_DECLARATION						<-- `context`
	|- .decl_specs						<-- `decl_specs`
		AST_LIST
		|- .node
			AST_TYPEDEF
		|- .next						<-- `next`
			AST_GENERIC_SPECIFIER		<-- `node`
			|- .id
				AST_ID: `Foo`
			|- .type_list
				AST_INT
	|- .init_declarator_list
		AST_ID: `FooInt`
	*/

// printf("Variation 3\n");
// print_ast_tree(stdout, context, 0);
// 		//	FINALLY replace the nodes in the AST!
// 		// name = get_generic_type_name(decl_specs->list.next->struct_or_union.id);
// 		const char *name = get_generic_type_name(node->struct_or_union.id);
// 		union ast_node *name_node = create_id_node(name);
// 		node->type = node->type == AST_GENERIC_STRUCT ? AST_STRUCT : AST_UNION;
// 		node->struct_or_union.id = name_node;
// 		// decl_specs->list.next->list.next = name_node;
// 		return;





}


// AST_TYPEDEF
void handle_typedef(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
return;

	union ast_node *context = get_base_context(parent);

printf("AST_TYPEDEF\n");

	assert(context != NULL);
	assert(context->type == AST_DECLARATION);

	if (context->type != AST_DECLARATION) {
		fprintf(stderr, "Syntax Error: Unexpected context type `%s` for declaration\n", get_node_name(context->type));
		exit(EXIT_FAILURE);
	}

	//	We need to make sure that the `typedef` is the first node in the list!
	if (context->declaration.decl_specs->type != AST_LIST) {
		fprintf(stderr, "Syntax Error: Unexpected declaration specifier type `%s` for declaration\n", get_node_name(context->declaration.decl_specs->type));
		exit(EXIT_FAILURE);
	}

	union ast_node *id = get_id_node(context->declaration.init_declarator_list);

	assert(id != NULL);
	assert(id->type == AST_ID);

	const char *name = id->id.id;

	symbol_t *sym = symbol_get(name);

	//	Can you declare a `typedef` symbol twice?
	//	YES! As long as it's identical to the previous one OR it's in a different context!
	//	`error: conflicting types for 's'; have 'long int'`
	//	note: previous declaration of 's' with type 's' {aka 'int'}

	//	YES, you can declare it again in a new context! eg. inside a function block, you can redeclare the `typedef` to something new with the same name!
	if (sym != NULL) {
		fprintf(stderr, "Syntax Error: Redefinition of symbol `%s`.\n", name);
		exit(EXIT_FAILURE);
	}

	symbol_add_typedef(name, context);
}


const char *get_generic_name(union ast_node *node)	//	eg. `Foo`
{
	union ast_node *id = get_id_node(node);

	assert(id != NULL);
	assert(id->type == AST_ID);

	return id->id.id;
}


void validate_generic_type_list(union ast_node *node)
{
	assert(node != NULL);

	switch (node->type) {
	case AST_LIST:
		assert(node->list.node != NULL);
		assert(node->list.next != NULL);
		validate_generic_type_list(node->list.node);
		validate_generic_type_list(node->list.next);
		break;

	case AST_ID:
		break;

	default:
		// assert(0);
		//	TODO: We need some sort of `data type` print method??? Or should we just use `codegen`?
		fprintf(stderr, "Syntax error: Invalid type `%s` used in generic declaration! Only placeholder names like `<T>` are allowed!\n", get_node_name(node->type));
		exit(EXIT_FAILURE);
	}
}


//	The struct has a `declaration list` eg. `struct foo<T> { ... };` where the `{ ... }` is the declaration list!
void handle_real_generic_decl(union ast_node *node, union ast_node *context)
{
	//	This is a 'real' generic declaration, with a declaration list!
	//	We need to remove it from the AST!
	//	We also need to make sure it's NOT a `typedef` and that it doesn't have a variable declaration with it!
	if (context->type != AST_DECLARATION) {
		print_original_syntax(
			node->struct_or_union.id->generic_type.filename,
			node->struct_or_union.id->generic_type.line,
			"Syntax error: Generic structures like `%s` with a declaration list can only be defined in a declaration!\n", get_generic_name(node->struct_or_union.id)
		);
		// fprintf(stderr, "Syntax error: Generic structures like `%s` with a declaration list can only be defined in a declaration!\n", get_generic_name(node->struct_or_union.id));
		exit(EXIT_FAILURE);
	}

	//	The generic declaration must be a direct child of the base node!
	//	If not, then it's probably sitting in a `typedef` or something else!
	//	eg. `typedef struct foo<T> { ... } foo;` ... is invalid!
	if (node->struct_or_union.parent != context) {
		if (is_typedef_node(context->declaration.decl_specs)) {
			print_original_syntax(
				node->struct_or_union.id->generic_type.filename,
				node->struct_or_union.id->generic_type.line,
				"Syntax error: Generic structures like `%s` with a declaration list cannot be defined as a `typedef`!\n", get_generic_name(node->struct_or_union.id)
			);
			// fprintf(stderr, "Syntax error: Generic structures like `%s` with a declaration list cannot be defined as a `typedef`!\n", get_generic_name(node->struct_or_union.id));
		} else {
			print_original_syntax(
				node->struct_or_union.id->generic_type.filename,
				node->struct_or_union.id->generic_type.line,
				"Syntax error: Invalid or unhandled generic declaration for `%s`!\n", get_generic_name(node->struct_or_union.id)
			);
			// fprintf(stderr, "Syntax error: Invalid or unhandled generic declaration for `%s`!\n", get_generic_name(node->struct_or_union.id));
		}
		exit(EXIT_FAILURE);
	}

	//	You cannot declare an instance of a generic `struct` with an 'instance' name! eg. `struct foo<T> { ... } foo;`
	if (context->declaration.init_declarator_list != NULL) {
		union ast_node *init_name = get_id_node(context->declaration.init_declarator_list);
		assert(init_name != NULL);
		assert(init_name->type == AST_ID);

		print_original_syntax(
			node->struct_or_union.id->generic_type.filename,
			node->struct_or_union.id->generic_type.line,
			"Syntax error: You cannot declare an instance of a generic struct (`%s`), the instance name you are trying to declare is: `%s`!\n",
			get_generic_name(node->struct_or_union.id),
			get_generic_name(context->declaration.init_declarator_list)
		);
		// fprintf(stderr, "Syntax error: You cannot declare an instance of a generic struct (`%s`), the instance name you are trying to declare is: `%s`!\n",
		// 	get_generic_name(node->struct_or_union.id),
		// 	get_generic_name(context->declaration.init_declarator_list)
		// );
		exit(EXIT_FAILURE);
	}

	//	Make sure the `type_list` has only valid `AST_ID` nodes!
	//	eg. `struct foo<T, int> { ... };` is invalid!
	validate_generic_type_list(node->struct_or_union.id->generic_type.type_list);


	// check if the parent is the root node
	if (context->declaration.parent == NULL) {
		assert(root_node == context);
		root_node = NULL;
		return;
	}

	//	TODO: There might be other parent node types for `struct Foo<T> { ... };` declarations!
	switch (context->declaration.parent->type) {
	case AST_LIST:
		if (context->declaration.parent->list.node == context) {
			context->declaration.parent->list.node = NO_OP_NODE;
		} else {
			assert(context->declaration.parent->list.next == context);
			context->declaration.parent->list.next = NO_OP_NODE;
		}
		break;

	case AST_BLOCK:
		context->declaration.parent->block.stmts = NO_OP_NODE;
		break;

	default:
		{
			int type = context->declaration.parent->type;
			print_original_syntax(
				node->struct_or_union.id->generic_type.filename,
				node->struct_or_union.id->generic_type.line,
				"Parser error in %s(): Unhandled parent node type %s (%d)\n", __func__, get_node_name(type), type
			);
			// fprintf(stderr, "Parser error in %s(): Unhandled parent node type %s (%d)\n", __func__, get_node_name(type), type);
			exit(EXIT_FAILURE);
		}
	}
}



// AST_GENERIC_STRUCT || AST_GENERIC_UNION
void handle_generic_struct_or_union(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	assert(node->struct_or_union.id != NULL);
	assert(node->struct_or_union.id->type == AST_GENERIC_DECLARATION);
	register_generic(node);

	union ast_node *context = get_base_context(node);

	//	The struct has a `declaration list` eg. `struct foo<T> { ... };`
	//	This is the MAIN `generic` declaration!
	if (node->struct_or_union.decl_list != NULL) {
		handle_real_generic_decl(node, context);
		//	TODO: After removing the generic struct from the AST, we (might) need to check if there are any `pending` generic declarations. Otherwise, we can just build them as needed!
		return;
	}

	if (context->type == AST_DECLARATION) {
printf("::AST_DECLARATION::\n");
		// Declarations can be: a `typedef`, a local variable, an opaque `struct`, a function etc.
		handle_declaration(node, parent, jump_table, context);
		return;
	}

printf("handle_generic_struct_or_union()\n");
print_ast_tree(stdout, context, 0);

	if (node->struct_or_union.id->generic_type.type_list == NULL) {
		print_original_syntax(
			node->struct_or_union.id->generic_type.filename,
			node->struct_or_union.id->generic_type.line,
			"Syntax error: Generic `%s` requires a concrete type.\n",
			get_generic_name(node)
		);
		exit(EXIT_FAILURE);
	}

	const char *name = get_generic_type_name(node->struct_or_union.id);
	union ast_node *name_node = create_id_node(name);

	//	TODO: Check that the `type_list` is valid for a concrete type!
	int type = node->struct_or_union.type;
	assert(type == AST_GENERIC_STRUCT || type == AST_GENERIC_UNION);
	type = type == AST_GENERIC_STRUCT ? AST_STRUCT : AST_UNION;
	node->struct_or_union.type = type;
	node->struct_or_union.id = name_node;
return;

	switch (context->type)
	{
	case AST_PARAMETER_DECLARATION:	//	func(Foo<int> *foo)
	{
printf("::AST_PARAMETER_DECLARATION::\n");
		union ast_node *decl_specs = context->parameter_declaration.decl_specs;

		if (decl_specs == node) {
			assert(parent->type == AST_PARAMETER_DECLARATION);
			assert(parent == context);
			context->parameter_declaration.decl_specs = name_node;
			return;
		}

		assert(decl_specs->type == AST_LIST);
		assert(parent->type == AST_LIST);
		if (parent->list.node == node) {
			parent->list.node = name_node;
		} else {
			assert(parent->list.next != NULL);
			assert(parent->list.next == node);
			parent->list.next = name_node;
		}
		break;
	}	//	NOTE: TODO: I think we need to "carry on" testing other parameters! They could be generic types too!

	case AST_FUNCTION_DEFINITION:	//	Foo<int> *func()
printf("::AST_FUNCTION_DEFINITION::\n");
		assert(context->function_definition.decl_specs == node);
		assert(parent == context);
		context->function_definition.decl_specs = name_node;
		// decl_specs->list.next->list.next = name_node;
		return;

// 	case AST_CAST:	//	use `AST_ABSTRACT_TYPE_NAME` instead!
	case AST_ABSTRACT_TYPE_NAME:
printf("::AST_ABSTRACT_TYPE_NAME::\n");
		assert(parent == context);
		assert(context->abstract_type_name.specifier_qualifier_list == node);
		context->abstract_type_name.specifier_qualifier_list = name_node;
		break;

	case AST_SIZEOF_TYPE:	//	sizeof(`type`)
printf("::AST_SIZEOF_TYPE::\n");
		assert(parent == context);
		assert(context->unary.expr == node);
		context->unary.expr = name_node;
		break;

	default:
		print_original_syntax(
			node->struct_or_union.id->generic_type.filename,
			node->struct_or_union.id->generic_type.line,
			"Parser error in %s(): Unhandled generic context type `%s` (%d)\n",
			__func__,
			get_node_name(context->type),
			context->type
		);
		exit(EXIT_FAILURE);
	}
}
// AST_GENERIC_STRUCT
void handle_generic_struct(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	handle_generic_struct_or_union(node, parent, jump_table);
}
// AST_GENERIC_UNION
void handle_generic_union(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	handle_generic_struct_or_union(node, parent, jump_table);
}





union ast_node *get_base_context(union ast_node *node)
{
	assert(node != NULL);

	switch (node->type) {

	case AST_GENERIC_STRUCT:
	case AST_GENERIC_UNION:
		return get_base_context(node->struct_or_union.parent);

	case AST_GENERIC_DECLARATION:
	case AST_GENERIC_SPECIFIER:
		return get_base_context(node->generic_type.parent);

	case AST_LIST:
		return get_base_context(node->list.parent);

	case AST_ABSTRACT_TYPE_NAME:	//	part of `AST_CAST` eg. `(Foo<int>*)` for `malloc()` casting! Parent node should be `AST_CAST`. This is a pointer cast!
		return node; //get_base_context(node->abstract_type_name.parent);


	/*
	AST_FUNCTION_DEFINITION
	|- .decl_specs
		AST_INT
	|- .declarator
		AST_FUNCTION_DECLARATOR
		|- .direct_declarator
			AST_ID: `fn`
		|- .params
			AST_PARAMETER_DECLARATION
			|- .decl_specs
				AST_GENERIC_SPECIFIER
				|- .id
					AST_ID: `Foo`
				|- .type_list
					AST_INT
			|- .declarator
				AST_POINTER_DECLARATOR
				|- .pointer
					AST_POINTER
					|- .type_qualifier_list
						NULL
					|- .pointer
						NULL
				|- .direct_declarator
					AST_ID: `foo`
		|- .identifier_list
			NULL
	|- .decl_list
		NULL
	|- .block
		AST_BLOCK
		|- .stmts
			NULL
	*/
	//	Not sure yet if I want to end on this, or `AST_FUNCTION_DECLARATOR` or `AST_FUNCTION_DEFINITION`
	case AST_PARAMETER_DECLARATION:
		return node;

	// case AST_FUNCTION_DECLARATOR:
	case AST_FUNCTION_DEFINITION:
		return node;

	case AST_SIZEOF_TYPE:	//	sizeof(`type`)
	case AST_SIZEOF_EXPR:	//	sizeof `expr`
	case AST_BLOCK:
	case AST_CAST:
	case AST_DECLARATION:
		return node;
	}

	fprintf(stderr, "Parser error in %s(): Unhandled parent node type `%s` (%d) for generic implementation!\n", __func__, get_node_name(node->type), node->type);
	exit(EXIT_FAILURE);
	return NULL;
}






void register_generic(union ast_node *node)
{
	assert(node->type == AST_GENERIC_STRUCT || node->type == AST_GENERIC_UNION);
	assert(node->struct_or_union.id != NULL);
	assert(node->struct_or_union.id->type == AST_GENERIC_DECLARATION); // Already tested externally, just here to make doubly sure!
	union ast_node *id = get_id_node(node->struct_or_union.id);

	assert(id != NULL);
	assert(id->id.type == AST_ID);
	// if (id == NULL) {
	// 	fprintf(stderr, "PARSER ERROR: %s(): Cannot find generic ID node.\n", __func__);
	// 	exit(EXIT_FAILURE);
	// }

	const char *name = id->id.id;

// printf("*** register_generic_struct_or_union(): %s\n", name);

	symbol_t *sym = symbol_get(name);
	//  get_id_node(node->struct_or_union.id);
	if (sym == NULL) {
		sym = symbol_add_generic(name, node);
		sym->is_struct = node->type == AST_GENERIC_STRUCT;
		sym->is_union = node->type == AST_GENERIC_UNION;
printf("Symbol table after adding `%s`:\n", name);
symbol_table_print(stdout);
		return;
	}

	//	The symbol was previously added, check for generic structs
	//	This could happen if the user declares a local variable with the same name?
	if (sym->node->type != AST_GENERIC_STRUCT && sym->node->type != AST_GENERIC_UNION) {
		print_original_syntax(
			node->struct_or_union.id->generic_type.filename,
			node->struct_or_union.id->generic_type.line,
			"Syntax error: Symbol with name '%s' already exists! Generic names must be unique! Did you declare a local variable with this name?\n", name
		);
		exit(EXIT_FAILURE);
	}

	if (sym->node->type != node->type) {
		print_original_syntax(
			node->struct_or_union.id->generic_type.filename,
			node->struct_or_union.id->generic_type.line,
			"Syntax error: '%s' cannot be redeclared with a different generic type (struct vs. union).\n", name
		);
		exit(EXIT_FAILURE);
	}

	//	This section will UPDATE the `.decl_list` of the generic struct/union.
	//	For example, in the case when just `struct Foo<T>;` was declared.
	//	This is usually the case for `opaque` structs.
	//	We need to update the `.decl_list` to the actual definition.

	if (node->struct_or_union.decl_list == NULL) {
		//	This might just be a re-declaration or being used in a `typedef`, do nothing
		return;
	}

	if (sym->node->struct_or_union.decl_list != NULL) {
		print_original_syntax(
			node->struct_or_union.id->generic_type.filename,
			node->struct_or_union.id->generic_type.line,
			"Syntax error: Symbol with name '%s' already exists and defined! Generics cannot be redefined.\n", name
		);
		// fprintf(stderr, "Syntax error: Symbol with name '%s' already exists and defined! Generics cannot be redefined.\n", name);
		exit(EXIT_FAILURE);
	}

// printf("BEFORE: %s(): %s\n", __func__, name);
// print_ast_tree(stdout, sym->node, 0);
	// sym->node->struct_or_union.decl_list = node->struct_or_union.decl_list;
	sym->node = node;

	// validate_generic_type_list(node); //	This is already done in `handle_real_generic_decl`!

	// sym->node->struct_or_union.id->generic_type.type_list = node->struct_or_union.id->generic_type.type_list;

// sym = symbol_get(name);
// printf("AFTER: %s(): %s\n", __func__, name);
// print_ast_tree(stdout, sym->node, 0);
}

// void register_generic_union(union ast_node *node)
// {
// 	union ast_node *id = get_id_node(node->struct_or_union.id);

// 	if (id) {
// 		symbol_add_generic_union(id->id.id, node);
// 	}
// }
















void ___handle_generic_struct(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
// case AST_GENERIC_STRUCT:
// case AST_GENERIC_UNION:
	assert(node->generic_type.id != NULL);
	if (node->generic_type.id->type == AST_GENERIC_DECLARATION) {
		register_generic(node);
		if (parent->type == AST_DECLARATION && parent->declaration.decl_specs == node) {
			parent->declaration.decl_specs = NULL;
		}
	} else {
printf("HERLEJHRELJRHLEJHREJLHR J====================>>>>\n");
	}
}


void __handle_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->declaration.init_declarator_list == NULL) {
		union ast_node *decl_specs = node->declaration.decl_specs;
		if (is_typeof_node(AST_GENERIC_DECLARATION, decl_specs)) {
printf("FOUND GENERIC SPECIFIER!\n");
symbol_table_print(stdout);
			//	Disabling the check for `typedef` ... to support `opaque` generics!
			//	Is the `typedef` check necessary?
			if (1 || is_typeof_node(AST_TYPEDEF, decl_specs)) {

				build_generic_struct(node);
symbol_table_print(stdout);

				// printf("FOUND GENERIC SPECIFIER WITH TYPEDEF!\n");
				//	We need to generate the typedef here, because the generic type is not a real type, but a placeholder for a real type
				// indent(out, depth);
				// fprintf(out, "typedef struct %s {", get_generic_type_name(node->declaration.decl_specs));

					// Retrieve the generic template structure, and run through it while replacing the generic type with the real/concrete type

				// fprintf(out, " } %s;\n", get_generic_type_name(node->declaration.decl_specs));

				// TODO: We need to build/expand/replace the generic template structure!
				// break;
			} else {
// build_generic_struct(node);

			}
		} else if (is_typeof_node(AST_GENERIC_STRUCT, decl_specs) || is_typeof_node(AST_GENERIC_UNION, decl_specs)) {
printf("NOT FOUND GENERIC SPECIFIER!\n");
			// codegen(out, decl_specs, depth, node);
			// break;
		}
	}

print_ast_tree(stdout, node, 0);
printf("begin register_typedef\n");
	register_typedef(node->declaration.decl_specs, node->declaration.init_declarator_list);
printf("being register_declaration\n");
	register_declaration(node);
printf("end register_declaration\n");
}


//	eg. `Foo<int>` ==> `Foo<int>`
//	NOTE: This is usually used for error messages, so we can add node types that usually an error in generic types; like AST_THIS and AST_SELF!
char *get_original_generic_type_name(union ast_node *node)
{
	static char generic_type_name[128];

	if (node == NULL) return NULL;

	switch (node->type) {

	case AST_ID: return strcat(generic_type_name, node->id.id);

	case AST_GENERIC_SPECIFIER:
	case AST_GENERIC_DECLARATION:

		generic_type_name[0] = '\0';
		if (get_original_generic_type_name(node->generic_type.id) == NULL) {
			break;
		}
		strcat(generic_type_name, "<");
		if (get_original_generic_type_name(node->generic_type.type_list) == NULL) {
			break;
		}
		return strcat(generic_type_name, ">");

		// generic_type_name[0] = '\0';
		// strcat(get_original_generic_type_name(node->generic_type.id), "<");
		// strcat(get_original_generic_type_name(node->generic_type.type_list), ">");
		// return generic_type_name;

	case AST_GENERIC_STRUCT:
	case AST_GENERIC_UNION:
		generic_type_name[0] = '\0';	//	NOTE: Not necessary, but here just to be sure!
		return get_original_generic_type_name(node->struct_or_union.id);

	case AST_GENERIC_LIST:
		strcat(get_original_generic_type_name(node->list.node), ", ");
		return get_original_generic_type_name(node->list.next);

	case AST_LIST:
		strcat(get_original_generic_type_name(node->list.node), " ");
		return get_original_generic_type_name(node->list.next);

	case AST_THIS:		return strcat(generic_type_name, "this");
	case AST_SELF:		return strcat(generic_type_name, "self");

	case AST_NUMERIC:	return strcat(generic_type_name, node->numeric.num_str);
	case AST_STRING:	return strcat(generic_type_name, node->id.id);

	case AST_VOID:		return strcat(generic_type_name, "void");
	case AST_CHAR:		return strcat(generic_type_name, "char");
	case AST_SHORT:		return strcat(generic_type_name, "short");
	case AST_INT:		return strcat(generic_type_name, "int");
	case AST_LONG:		return strcat(generic_type_name, "long");
	case AST_FLOAT:		return strcat(generic_type_name, "float");
	case AST_DOUBLE:	return strcat(generic_type_name, "double");
	case AST_SIGNED:	return strcat(generic_type_name, "signed");
	case AST_UNSIGNED:	return strcat(generic_type_name, "unsigned");
	case AST_BOOL:		return strcat(generic_type_name, "bool");
	case AST_COMPLEX:	return strcat(generic_type_name, "complex");
	case AST_IMAGINARY:	return strcat(generic_type_name, "imaginary");

	/* GCC _Decimal32 extension */
	case AST__DECIMAL32:	return strcat(generic_type_name, "_Decimal32");
	/* GCC _Decimal64 extension */
	case AST__DECIMAL64:	return strcat(generic_type_name, "_Decimal64");
	/* GCC _Decimal128 extension */
	case AST__DECIMAL128:	return strcat(generic_type_name, "_Decimal128");

	/* GCC _Float128 extension */
	case AST__FLOAT128:		return strcat(generic_type_name, "_Float128");
	/* GCC __int128 extension */
	case AST__INT128:		return strcat(generic_type_name, "__int128");		//	GCC __int128 extension - As of GCC 4.6
	/* GCC __int128_t extension */
	case AST__INT128_T:		return strcat(generic_type_name, "__int128_t");		//	GCC __int128_t extension - As of GCC 4.1
	/* GCC __uint128_t extension */
	case AST__UINT128_T:	return strcat(generic_type_name, "__uint128_t");	//	GCC __uint128_t extension - As of GCC 4.1

	//	WARNING: We need to add ALL node types!!!
	case AST_CONST:			return strcat(generic_type_name, "const");
	case AST_RESTRICT:		return strcat(generic_type_name, "restrict");
	case AST_VOLATILE:		return strcat(generic_type_name, "volatile");


	case AST_ABSTRACT_TYPE_NAME:
		get_original_generic_type_name(node->abstract_type_name.specifier_qualifier_list);
		get_original_generic_type_name(node->abstract_type_name.abstract_declarator);
		return generic_type_name;

	case AST_ABSTRACT_DECLARATOR:
		get_original_generic_type_name(node->abstract_declarator.pointer);
		get_original_generic_type_name(node->abstract_declarator.direct_abstract_declarator);
		return generic_type_name;

	case AST_POINTER:
		strcat(generic_type_name, "*");
		get_original_generic_type_name(node->pointer.type_qualifier_list);
		get_original_generic_type_name(node->pointer.pointer);
		return generic_type_name;

	//	TODO: We need to support `bitint`
	/* C23 _BitInt(128) */
	//AST__BITINT128,						//	Common in Clang
	/* C23 _BitInt(N) */
	// case AST__BITINT:					//	Generic C23 version!

	default:
		fprintf(stderr, "Parser error in %s(): Unhandled node type `%s` (%d)\n", __func__, get_node_name(node->type), node->type);
		print_ast_tree(stderr, node, 0);
		exit(EXIT_FAILURE);
	}

	return generic_type_name;
}
