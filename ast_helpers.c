#include "ast_nodes.h"
#include "ast_helpers.h"
#include "symbol_table.h"
#include "print_ast_tree.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>


// int start_function(union ast_node *declspecs, union ast_node *declarator)
// {
// 	symbol_table_push_scope();
// 	union ast_node *function_name = get_id_node(declarator);

// 	return 1;
// }

const char *get_node_name(int type)
{
	switch (type) {
	case AST_ID: return "AST_ID";
	case AST_TYPEDEF_NAME: return "AST_TYPEDEF_NAME";

	case AST_LIST: return "AST_LIST";
	case AST_POINTER_DECLARATOR: return "AST_POINTER_DECLARATOR";
	case AST_GROUPED_DECLARATOR: return "AST_GROUPED_DECLARATOR";
	case AST_DESIGNATOR: return "AST_DESIGNATOR";
	case AST_POINTER: return "AST_POINTER";

	case AST_FUNCTION_DEFINITION: return "AST_FUNCTION_DEFINITION";
	case AST_FUNCTION_DECLARATOR: return "AST_FUNCTION_DECLARATOR";
	case AST_FUNCTION_CALL: return "AST_FUNCTION_CALL";

	case AST_BLOCK: return "AST_BLOCK";
	case AST_DECLARATION: return "AST_DECLARATION";
	case AST_PARAMETER_DECLARATION: return "AST_PARAMETER_DECLARATION";
	case AST_ABSTRACT_DECLARATOR: return "AST_ABSTRACT_DECLARATOR";

	case AST_UNSPECIFIED_ARRAY: return "AST_UNSPECIFIED_ARRAY";
	case AST_DYNAMIC_ARRAY: return "AST_DYNAMIC_ARRAY";
	case AST_STATIC_ARRAY: return "AST_STATIC_ARRAY";
	case AST_ARRAY: return "AST_ARRAY";
	case AST_STATEMENT: return "AST_STATEMENT";

	case AST_STRUCT: return "AST_STRUCT";
	case AST_UNION: return "AST_UNION";

	case AST_INITIALIZER: return "AST_INITIALIZER";
	case AST_DESIGNATION_INITIALIZER: return "AST_DESIGNATION_INITIALIZER";

	case AST_VOID: return "AST_VOID";
	case AST_CHAR: return "AST_CHAR";
	case AST_SHORT: return "AST_SHORT";
	case AST_INT: return "AST_INT";
	case AST_LONG: return "AST_LONG";
	case AST_FLOAT: return "AST_FLOAT";
	case AST_DOUBLE: return "AST_DOUBLE";
	case AST_SIGNED: return "AST_SIGNED";
	case AST_UNSIGNED: return "AST_UNSIGNED";
	case AST_BOOL: return "AST_BOOL";
	case AST_COMPLEX: return "AST_COMPLEX";
	case AST_IMAGINARY: return "AST_IMAGINARY";

	case AST_THIS: return "AST_THIS";
	case AST_SELF: return "AST_SELF";

	case AST_CONST: return "AST_CONST";
	case AST_RESTRICT: return "AST_RESTRICT";
	case AST_VOLATILE: return "AST_VOLATILE";

	case AST__RESTRICT: return "AST__RESTRICT";

	case AST_TYPEDEF: return "AST_TYPEDEF";
	case AST_EXTERN: return "AST_EXTERN";
	case AST_STATIC: return "AST_STATIC";
	case AST_THREAD_LOCAL: return "AST_THREAD_LOCAL";
	case AST_AUTO: return "AST_AUTO";
	case AST_REGISTER: return "AST_REGISTER";

	// case AST_GENERIC_SPECIFIER: return "AST_GENERIC_SPECIFIER";
	case AST_GENERIC_DECLARATION: return "AST_GENERIC_DECLARATION";
	case AST_GENERIC_STRUCT: return "AST_GENERIC_STRUCT";
	case AST_GENERIC_UNION: return "AST_GENERIC_UNION";

	case AST_STRUCT_OR_UNION_DECLARATION: return "AST_STRUCT_OR_UNION_DECLARATION";
	case AST_STRUCT_OR_UNION_DECLARATOR: return "AST_STRUCT_OR_UNION_DECLARATOR";
	}

	return "UNKNOWN";
}

// ---------------------------------------------------------------------------------------------------
//									AST traversal helper functions
// ---------------------------------------------------------------------------------------------------

union ast_node *get_id_node(union ast_node *node)
{
	if (node == NULL) return NULL;

	union ast_node *tmp;

	switch (node->type) {
	case AST_ID: return node;		//	The target node!

	case AST_THIS: return NULL;
	case AST_SELF: return NULL;

	case AST_LIST:
		tmp = get_id_node(node->list.node);
		if (tmp) return tmp;
		return get_id_node(node->list.next);

	case AST_POINTER_DECLARATOR:
		return get_id_node(node->pointer_declarator.direct_declarator);

	case AST_FUNCTION_DECLARATOR:
		return get_id_node(node->function_declarator.direct_declarator);

	case AST_FUNCTION_DEFINITION:
		return get_id_node(node->function_definition.declarator);

	case AST_GROUPED_DECLARATOR:
		return get_id_node(node->grouped_declarator.declarator);
	
	case AST_ARRAY:
		return get_id_node(node->array.direct_declarator);

	case AST_UNSPECIFIED_ARRAY:
		return get_id_node(node->unspecified_array.direct_declarator);

	case AST_DYNAMIC_ARRAY:
		return get_id_node(node->dynamic_array.direct_declarator);

	case AST_STATIC_ARRAY:
		return get_id_node(node->array.direct_declarator);

	case AST_ABSTRACT_DECLARATOR:
		return get_id_node(node->abstract_declarator.direct_abstract_declarator);


	//	NOTE: `.object` AND `.member` could be AST_ID's ... it's a bit ambiguous.
	case AST_MEMBER_ACCESS:
	case AST_MEMBER_ACCESS_POINTER:
		tmp = get_id_node(node->member_access.object);
		if (tmp) return tmp;
		return get_id_node(node->member_access.member);


	case AST_GENERIC_DECLARATION:	//	`Vec3<T>`
	// case AST_GENERIC_SPECIFIER:		//	`Vec3<float>`
		return get_id_node(node->generic_type.id);


	case AST_ABSTRACT_TYPE_NAME:
		return get_id_node(node->abstract_type_name.specifier_qualifier_list);
		// tmp = get_id_node(node->abstract_type_name.specifier_qualifier_list);
		// return tmp ? tmp : get_id_node(node->abstract_type_name.abstract_declarator);

	// case AST_ABSTRACT_DECLARATOR:
	// 	tmp = get_id_node(node->abstract_declarator.pointer);
	// 	return tmp ? tmp : get_id_node(node->abstract_declarator.direct_abstract_declarator);

	// case AST_POINTER:
	// 	tmp = get_id_node(node->pointer.type_qualifier_list);
	// 	return tmp ? tmp : get_id_node(node->pointer.pointer);


	case AST_STRUCT:
	case AST_UNION:
	case AST_GENERIC_STRUCT:
	case AST_GENERIC_UNION:
		return get_id_node(node->struct_or_union.id);


	case AST_VOID:
	case AST_CHAR:
	case AST_SHORT:
	case AST_INT:
	case AST_LONG:
	case AST_FLOAT:
	case AST_DOUBLE:
	case AST_SIGNED:
	case AST_UNSIGNED:
	case AST_BOOL:
	case AST_COMPLEX:
	case AST_IMAGINARY:

	/* GCC Extensions */
	case AST__BUILTIN_VA_LIST:


	/* GCC __attribute__ extension support */
	case AST__ATTRIBUTE__:
	/* GCC __asm__ extension support */
	case AST__ASM__:

	/* GCC _Decimal32 extension */
	case AST__DECIMAL32:
	/* GCC _Decimal64 extension */
	case AST__DECIMAL64:
	/* GCC _Decimal128 extension */
	case AST__DECIMAL128:

	/* GCC _Float128 extension */
	case AST__FLOAT128:
	/* GCC __int128 extension */
	case AST__INT128:						//	GCC __int128 extension - As of GCC 4.6
	/* GCC __int128_t extension */
	case AST__INT128_T:						//	GCC __int128_t extension - As of GCC 4.1
	/* GCC __uint128_t extension */
	case AST__UINT128_T:						//	GCC __uint128_t extension - As of GCC 4.1

	/* C23 _BitInt(128) */
	//AST__BITINT128,						//	Common in Clang
	/* C23 _BitInt(N) */
	case AST__BITINT:						//	Generic C23 version!

	//	WARNING: We need to add ALL node types!!!
	case AST_CONST:
	case AST_RESTRICT:
	case AST_VOLATILE:

	case AST__RESTRICT:

	case AST_TYPEDEF:
	case AST_EXTERN:
	case AST_STATIC:
	case AST_THREAD_LOCAL:
	case AST_AUTO:
	case AST_REGISTER:
		return NULL;

	default:
#if defined(DEBUG) || !defined(NDEBUG)
		fprintf(stderr, "INTERNAL ERROR DETECTED - UNHANDLED NODE TYPE `%s` (%d) in `%s()`\n", get_node_name(node->type), node->type, __func__);
		exit(EXIT_FAILURE);
#endif
		return NULL;
	}
}


// Currently used by the generic methods to get the AST_GENERIC_SPECIFIER node.
// There is only an AST_LIST node in the way.
// You'll need to add additional nodes here if you want to support other types!
union ast_node *get_node_by_type(int type, union ast_node *node)
{
	if (node == NULL) return NULL;

	if (node->type == type) return node;

	union ast_node *tmp;

	switch (node->type) {
	case AST_LIST:
		tmp = get_node_by_type(type, node->list.node);
		return tmp ? tmp : get_node_by_type(type, node->list.next);

	//	Added to support `opaque` generics
	case AST_GENERIC_STRUCT:
	case AST_GENERIC_UNION:
		return get_node_by_type(type, node->struct_or_union.id);
	}

	return NULL;
}





//	Is this vvv (find_typedef) used ???

// Given a parameter declaration, normal declaration or function definition, return the `typedef` of the parameter. Should ignore the rest!
// This is used when going through a functions parameters or declarations to find the matching typedef. We only analyze variables that have a typedef!
// This will have to change in future to support nested `struct` and `union` types. Or "deep" pointers. eg. node1->node2->node3->myFunction();
union ast_node *find_typedef(union ast_node *node)
{
	if (node == NULL) return NULL;

	union ast_node *tmp;

	switch (node->type) {

	case AST_TYPEDEF_NAME:
		return node;

	// I might need these later.
	// case AST_ID:
	// case AST_THIS:
	// case AST_SELF:
	// 	return NULL;

	case AST_LIST:
		tmp = find_typedef(node->list.node);
		if (tmp) return tmp;
		return find_typedef(node->list.next);

	case AST_PARAMETER_DECLARATION:
		return find_typedef(node->parameter_declaration.decl_specs);
	
	case AST_DECLARATION:
		return find_typedef(node->declaration.decl_specs);

	case AST_FUNCTION_DEFINITION:
		return find_typedef(node->function_definition.decl_specs);

	// case AST_POINTER_DECLARATOR:
	// 	return find_typedef(node->pointer_declarator.direct_declarator);

	// case AST_FUNCTION_DECLARATOR:
	// 	return find_typedef(node->function_declarator.direct_declarator);

	// case AST_GROUPED_DECLARATOR:
	// 	return find_typedef(node->grouped_declarator.declarator);
	
	// case AST_ARRAY:
	// 	return find_typedef(node->array.direct_declarator);

	// case AST_UNSPECIFIED_ARRAY:
	// 	return find_typedef(node->unspecified_array.direct_declarator);
	
	// case AST_DYNAMIC_ARRAY:
	// 	return find_typedef(node->dynamic_array.direct_declarator);
	
	// case AST_STATIC_ARRAY:
	// 	return find_typedef(node->static_array.direct_declarator);

	// case AST_ABSTRACT_DECLARATOR:	// Suggested by Copilot - not sure if I need this.
	// 	return find_typedef(node->abstract_declarator.direct_abstract_declarator);

	default:
		printf("FATAL ERROR DETECTED - UNHANDLED NODE TYPE `%s` (%d) IN `find_id()`\n", get_node_name(node->type), node->type);
		exit(EXIT_FAILURE);
		return NULL;
	}
}






//	eg. `Vec3<float>` ==> `Vec3__float`
//	NOTE: This is also used by AST_GENERIC_IMPL and AST_GENERIC_DECLARATION to produce a named `impl` block!
char *get_generic_type_name(union ast_node *node)
{
	static char generic_type_name[128];

	if (node == NULL) return NULL;

	switch (node->type) {

	case AST_ID:
		//	NOTE: I'm using `strcat` here because it might be used for more than just the generic type name.
		return strcat(generic_type_name, node->id.id);

	// case AST_GENERIC_SPECIFIER:
	// 	generic_type_name[0] = '\0';
	// 	strcat(get_generic_type_name(node->generic_type.id), "__");
	// 	return get_generic_type_name(node->generic_type.type_list);

	case AST_GENERIC_DECLARATION:
		// generic_type_name[0] = '\0';
		if (node->generic_type.type_list == NULL) {
			union ast_node *id = get_id_node(node->generic_type.id);
			if (id == NULL) {
				print_ast_tree(stderr, node, 0, 0);
				fprintf(stderr, "PARSER ERROR: Could not find the `id` node for the above generic type!\n");
				exit(EXIT_FAILURE);
			}
			fprintf(stderr, "PARSER or SYNTAX ERROR: We cannot generate the name of a generic type like `%s` without a `type_list`!\n", id->id.id);
			exit(EXIT_FAILURE);
		}

		generic_type_name[0] = '\0';
		strcat(get_generic_type_name(node->generic_type.id), "__");
		return get_generic_type_name(node->generic_type.type_list);
		// return get_generic_type_name(node->generic_type.id);

	// I might need these later.
	// case AST_ID:
	// case AST_THIS:
	// case AST_SELF:
	// 	return NULL;

	case AST_GENERIC_LIST:
		strcat(get_generic_type_name(node->list.node), "__");
		return get_generic_type_name(node->list.next);

	case AST_LIST:
		strcat(get_generic_type_name(node->list.node), "_");
		return get_generic_type_name(node->list.next);

	case AST_TYPEDEF:	//	Used when we find a `typedef`, we pass the `decl_specs` parameter to this function, and it will include an AST_LIST node linking the `typedef` node.
		return generic_type_name;

	case AST_NUMERIC:
	{
		const char *str = node->numeric.num_str;
		for (int i = 0; str[i] != '\0'; i++) {
			if (!isalnum(str[i])) {
				fprintf(stderr, "The generic type identifier `%s` contains a non-alpha-numeric character `%c`. It needs to pass the `isalnum()` test!\n", str, str[i]);
				exit(EXIT_FAILURE);
			}
		}

		return strcat(generic_type_name, str);
	}

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
		get_generic_type_name(node->abstract_type_name.specifier_qualifier_list);
		get_generic_type_name(node->abstract_type_name.abstract_declarator);
		return generic_type_name;

	case AST_ABSTRACT_DECLARATOR:
		get_generic_type_name(node->abstract_declarator.pointer);
		get_generic_type_name(node->abstract_declarator.direct_abstract_declarator);
		return generic_type_name;

	case AST_POINTER:
		strcat(generic_type_name, "_pointer");
		get_generic_type_name(node->pointer.type_qualifier_list);
		get_generic_type_name(node->pointer.pointer);
		return generic_type_name;

	//	TODO: We need to support `bitint`
	/* C23 _BitInt(128) */
	//AST__BITINT128,						//	Common in Clang
	/* C23 _BitInt(N) */
	// case AST__BITINT:					//	Generic C23 version!

	default:
printf("%s():\n", __func__);
print_ast_tree(stdout, node, 0, 0);
		fprintf(stderr, "FATAL ERROR: %s(): Unknown node type: %d\n", __func__, node->type);
		exit(EXIT_FAILURE);
	}

	return generic_type_name;
}



//	eg. `impl header Vec3<float>` ==> `impl__header__Vec3`
char *get_generic_impl_name(union ast_node *node)
{
	static char generic_impl_name[128];

	//	NOTE: This should probably NEVER happen!
	if (node == NULL) {
		fprintf(stderr, "FATAL ERROR in %s(): node == NULL\n", __func__);
		exit(EXIT_FAILURE);
	}

	switch (node->type) {

	case AST_ID:
		//	NOTE: I'm using `strcat` here because it might be used for more than just the generic type name.
		return strcat(generic_impl_name, node->id.id);

	case AST_GENERIC_DECLARATION:
	// case AST_GENERIC_SPECIFIER:
		// generic_impl_name[0] = '\0';
		strcpy(generic_impl_name, "impl__");
		return get_generic_impl_name(node->generic_type.id);

	case AST_LIST:
		strcat(get_generic_impl_name(node->list.node), "__");
		return get_generic_impl_name(node->list.next);

	default:
printf("%s():\n", __func__);
print_ast_tree(stdout, node, 0, 0);
		fprintf(stderr, "FATAL ERROR in %s(): Unknown or unhandled node type: %d\n", __func__, node->type);
		exit(EXIT_FAILURE);
	}

	return generic_impl_name;
}



char *get_generic_func_name(int func_type, union ast_node *node, union ast_node *func_name)
{
	static char generic_name[512];

	const char *format;

	switch (func_type) {
		case GENERIC_FUNC_NEW:
			format = "%s__%s";
			break;
		case GENERIC_FUNC_SET:
			format = "%s__set__%s";
			break;
		case GENERIC_FUNC_GET:
			format = "%s__get__%s";
			break;
		case GENERIC_FUNC_DELETE:
			format = "%s__%s";
			break;
		case GENERIC_FUNC:
			format = "%s__%s";
			break;
		default:
			fprintf(stderr, "FATAL ERROR: %s(): Unknown func_type: %d\n", __func__, func_type);
			exit(EXIT_FAILURE);
	}

	sprintf(generic_name, format, get_generic_type_name(node), func_name->id.id);

	return generic_name;
}




void register_generic_struct_or_union(union ast_node *node)
{
	union ast_node *id = get_id_node(node->struct_or_union.id);

	assert(id != NULL);
	if (id == NULL) {
		fprintf(stderr, "PARSER ERROR: %s(): Cannot find generic ID node.\n", __func__);
		exit(EXIT_FAILURE);
	}

	const char *name = id->id.id;

// printf("*** register_generic_struct_or_union(): %s\n", name);

	symbol_t *sym = symbol_get(name);
	//  get_id_node(node->struct_or_union.id);
	if (sym == NULL) {
		sym = symbol_add_generic_struct_or_union(name, node);
		sym->is_struct = node->type == AST_GENERIC_STRUCT;
		sym->is_union = node->type == AST_GENERIC_UNION;
		return;
	}

	//	This section will UPDATE the `.decl_list` of the generic struct/union.
	//	For example, in the case when just `struct Foo<T>;` was declared.
	//	This is usually the case for `opaque` structs.
	//	We need to update the `.decl_list` to the actual definition.

	//	The symbol was previously added, check for generic structs
	if (sym->node->type != AST_GENERIC_STRUCT && sym->node->type != AST_GENERIC_UNION) {
		fprintf(stderr, "ERROR: %s(): Symbol with name '%s' already exists! Generics cannot use an existing name.\n", __func__, name);
		exit(EXIT_FAILURE);
	}

	if (node->struct_or_union.decl_list == NULL) {
		//	This might just be a re-declaration, do nothing
		return;
	}

	if (sym->node->struct_or_union.decl_list != NULL) {
		//	We already have this generic struct, do nothing
		fprintf(stderr, "ERROR: %s(): Symbol with name '%s' already exists and defined! Generics cannot be redefined twice.\n", __func__, name);
		exit(EXIT_FAILURE);
	}

// printf("BEFORE: %s(): %s\n", __func__, name);
// print_ast_tree(stdout, sym->node, 0, 0);
	sym->node->struct_or_union.decl_list = node->struct_or_union.decl_list;

// sym = symbol_get(name);
// printf("AFTER: %s(): %s\n", __func__, name);
// print_ast_tree(stdout, sym->node, 0, 0);
}

// void register_generic_union(union ast_node *node)
// {
// 	union ast_node *id = get_id_node(node->struct_or_union.id);

// 	if (id) {
// 		symbol_add_generic_union(id->id.id, node);
// 	}
// }



//	This function recursively goes through the type lists and makes sure the number of parameters match!
//	`tmp_list` is the list of <T> names, `repl_list` is the replacements
bool check_type_list(union ast_node *tmp_list, union ast_node *repl_list)
{
	if (tmp_list == NULL) return false;

	switch (tmp_list->type) {

	case AST_GENERIC_LIST:
		{
			if (repl_list->type != AST_GENERIC_LIST)
				return false;

			return check_type_list(tmp_list->list.node, repl_list->list.node);
		}
	}

	return repl_list->type != AST_GENERIC_LIST;
}




/// @brief 	Replace all generic types with specific types.
/// @param 	node 	The AST declaration list of nodes to replace. eg. `T x; T y; T z;` ==> `float x; float y; float z;`
///	@param 	type 	The type to replace with.
union ast_node *replace_generic_types(union ast_node *node, union ast_node *tmp_list, union ast_node *repl_list)
{
	if (node == NULL) return NULL;

printf("************************************ddd************************************* %s() ==> %s (%d)\n", __func__, get_node_name(node->type), node->type);
// print_ast_tree(stdout, tmp_list, 0, 0);
// print_ast_tree(stdout, repl_list, 0, 0);

	switch (node->type) {

	case AST_LIST:
		{
			union ast_node *list_node = replace_generic_types(node->list.node, tmp_list, repl_list);
			union ast_node *list_next = replace_generic_types(node->list.next, tmp_list, repl_list);

			if (node->list.node == list_node && node->list.next == list_next) {
				return node;
			}

			return create_list_node(list_node, list_next, node->list.separator);
		}

	case AST_STRUCT_OR_UNION_DECLARATION:
		{
			// union ast_node *old_spec_qual_list = node->struct_or_union_declaration.spec_qual_list;
			// union ast_node *old_decl_list = node->struct_or_union_declaration.decl_list;

			// union ast_node *new_spec_qual_list = replace_generic_types(old_spec_qual_list, tmp_list, repl_list);
			// union ast_node *new_decl_list = replace_generic_types(old_decl_list, tmp_list, repl_list);

			// if (old_spec_qual_list == new_spec_qual_list && old_decl_list == new_decl_list) {
			// 	return node;
			// }

			return create_struct_or_union_declaration_node(
				replace_generic_types(node->struct_or_union_declaration.spec_qual_list, tmp_list, repl_list),
				replace_generic_types(node->struct_or_union_declaration.decl_list, tmp_list, repl_list)
			);
		}

	case AST_ID:
printf("found AST_ID: %s\n", node->id.id);
		//	TODO: In future, we need to loop through the `tmp_list` and replace the generic type with the specific type from `repl_list`.
		//	We will need to loop through both lists at the same time, simulaniously. We can do this by keeping them in sync!
		//	In other words, we could loop through them here, if the AST_LIST node doesn't match, until it does!
		//	TODO: Eventually, we will unify all the `id` nodes, so an `id` node with `T` will all have the same pointer!
		//	Then we can just do a check on the pointer, instead of a string compare!
		if (tmp_list->type != AST_GENERIC_LIST) {
			assert(tmp_list != NULL);
			assert(tmp_list->type == AST_ID);
			if (strcmp(node->id.id, tmp_list->id.id) == 0) {
printf("%s(): found match: `%s` == `%s`\n", __func__, node->id.id, tmp_list->id.id);
				return repl_list;
			}
		} else {
printf("found: AST_GENERIC_LIST\n");
			assert(repl_list != NULL);
			assert(repl_list->type == AST_GENERIC_LIST);
			union ast_node *result = replace_generic_types(node, tmp_list->list.node, repl_list->list.node);
			return result->type != AST_ID ? result : replace_generic_types(node, tmp_list->list.next, repl_list->list.next);
		}


		//	NOTE: I had issues with the process_impl() function, which was processing the `magnitude` 'getter'.
		//	It would replace it, but that method would then 'stick' around for other generics!
		//	Because when we come here, we don't make a copy of the ID! We just return the original ID!
		//	When the 'original' is changed, the change is replicated to all the other generics!
		//	We need to find a way of altering the 'getter' methods without affecting other generics.
		//	Because we are creating a 'costly' copy here for every 'id' node!
		//	Maybe we can force only certain node types to be copied, and not others?
		return create_id_node(node->id.id);
printf("%s(): NO match: `%s` != `%s`\n", __func__, node->id.id, tmp_list->id.id);
		// break;

	case AST_IMPL_NEW_FUNCTION:
		return create_new_function_definition_node(
			replace_generic_types(node->function_definition.decl_specs, tmp_list, repl_list),
			replace_generic_types(node->function_definition.declarator, tmp_list, repl_list),
			replace_generic_types(node->function_definition.block, tmp_list, repl_list));

	case AST_IMPL_NEW_DECLARATOR:
		// {
		// 	union ast_node *pointer = node->declarator.direct_declarator;
		// 	union ast_node *direct_declarator = node->declarator.direct_declarator;

		// 	while (tmp->type == AST_LIST) {
		// 		tmp = tmp->list.node;
		// 		repl = repl->list.node;
		// 	}

		// 	if (tmp->type == AST_ID) {
		// 		if (strcmp(tmp->id.id, tmp_list->id.id) == 0) {
		// 			repl = repl_list;
		// 		}
		// 	}

			
		// }


		return create_new_function_declarator_node(
			replace_generic_types(node->pointer_declarator.pointer, tmp_list, repl_list),
			replace_generic_types(node->pointer_declarator.direct_declarator->function_declarator.params, tmp_list, repl_list));

		// return create_new_function_declarator_node(
		// 	replace_generic_types(node->pointer_declarator.pointer, tmp_list, repl_list),
		// 	replace_generic_types(node->pointer_declarator.direct_declarator, tmp_list, repl_list));



	case AST_IMPL_DELETE_FUNCTION:
		return create_delete_function_definition_node(
			replace_generic_types(node->function_definition.decl_specs, tmp_list, repl_list),
			replace_generic_types(node->function_definition.declarator, tmp_list, repl_list),
			replace_generic_types(node->function_definition.block, tmp_list, repl_list));

	case AST_FUNCTION_DECLARATOR:
		{
printf("VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n");
print_ast_tree(stdout, node, 0, 0);
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
			union ast_node *direct_declarator = replace_generic_types(node->function_declarator.direct_declarator, tmp_list, repl_list);
			union ast_node *params = replace_generic_types(node->function_declarator.params, tmp_list, repl_list);

			//	NOTE: `identifier_list` is actually used for the `const` (AST_CONST) method qualifier!
			//assert(node->function_declarator.identifier_list == NULL);

			// NOTE: For some reason, if I don't return a copy of this, then the AST gets corrupted!
			//	Basically, the method names get prefixed with previous versions.
			//	So you land up with a function named: `Example__int__Example__const_char_pointer__get_value`
			//	So we MUST make a copy of this node, regardless of whether it has changed or not!
			//	It might also be an issue with setting the AST_ID function name node, and overwriting the main 'generic' node!
			//	NOTE about `identifier_list`: It's used for the `const` (AST_CONST) method qualifier!
			return create_function_declarator_node(direct_declarator, params, node->function_declarator.identifier_list);

			// if (node->function_declarator.direct_declarator == direct_declarator && node->function_declarator.params == params) {
			// 	return node;
			// }

			// return create_function_declarator_node(direct_declarator, params, node->function_declarator.identifier_list);
		}

	case AST_SETTER:
	case AST_GETTER:
	case AST_FUNCTION_DEFINITION:
		return create_impl_function_node(
			node->type,
			replace_generic_types(node->function_definition.decl_specs, tmp_list, repl_list),
			replace_generic_types(node->function_definition.declarator, tmp_list, repl_list),
			replace_generic_types(node->function_definition.block, tmp_list, repl_list)
		);

		// return create_function_definition_node(
		// 	replace_generic_types(node->function_definition.decl_specs, tmp_list, repl_list),
		// 	replace_generic_types(node->function_definition.declarator, tmp_list, repl_list),
		// 	NULL,
		// 	replace_generic_types(node->function_definition.block, tmp_list, repl_list)
		// );


	case AST_GENERIC_DECLARATION:
	// case AST_GENERIC_SPECIFIER:
		return create_generic_declaration_node(
				replace_generic_types(node->generic_type.id, tmp_list, repl_list),
				replace_generic_types(node->generic_type.type_list, tmp_list, repl_list));


	case AST_PARAMETER_DECLARATION:
		return create_parameter_declaration_node(
			replace_generic_types(node->parameter_declaration.decl_specs, tmp_list, repl_list),
			replace_generic_types(node->parameter_declaration.declarator, tmp_list, repl_list));

	case AST_BLOCK:
		return create_block_node(replace_generic_types(node->block.stmts, tmp_list, repl_list));

	case AST_DECLARATION:
		return create_declaration_node(
			replace_generic_types(node->declaration.decl_specs, tmp_list, repl_list),
			replace_generic_types(node->declaration.init_declarator_list, tmp_list, repl_list));

	case AST_INIT_DECLARATOR:
		return create_init_declarator_node(
			replace_generic_types(node->init_declarator.declarator, tmp_list, repl_list),
			replace_generic_types(node->init_declarator.initializer, tmp_list, repl_list));

	case AST_FUNCTION_CALL:
		return create_function_call_node(
			replace_generic_types(node->function_call.function, tmp_list, repl_list),
			replace_generic_types(node->function_call.args, tmp_list, repl_list));

	case AST_CAST:
		{
			union ast_node *type_name = replace_generic_types(node->cast.type_name, tmp_list, repl_list);
			union ast_node *expr = replace_generic_types(node->cast.expr, tmp_list, repl_list);

			return type_name == node->cast.type_name && expr == node->cast.expr
				? node
				: create_cast_node(type_name, expr);
		}

	case AST_RETURN:
		{
			union ast_node *expr = replace_generic_types(node->return_stmt.expr, tmp_list, repl_list);

			return expr == node->cast.expr ? node : create_return_node(expr);
		}

	case AST_ABSTRACT_TYPE_NAME:
		{
			union ast_node *spec_list = replace_generic_types(node->abstract_type_name.specifier_qualifier_list, tmp_list, repl_list);
			union ast_node *abs_decl = replace_generic_types(node->abstract_type_name.abstract_declarator, tmp_list, repl_list);

			if (spec_list == node->abstract_type_name.specifier_qualifier_list && abs_decl == node->abstract_type_name.abstract_declarator) {
				return node;
			}

			return create_abstract_type_name_node(spec_list, abs_decl);
		}

	case AST_ABSTRACT_DECLARATOR:
		{
			union ast_node *pointer = replace_generic_types(node->abstract_declarator.pointer, tmp_list, repl_list);
			union ast_node *direct = replace_generic_types(node->abstract_declarator.direct_abstract_declarator, tmp_list, repl_list);

			if (pointer == node->abstract_declarator.pointer && direct == node->abstract_declarator.direct_abstract_declarator) {
				return node;
			}

			return create_abstract_declarator_node(pointer, direct);
		}
	
	case AST_ARRAY:
		{
			union ast_node *direct_declarator = replace_generic_types(node->array.direct_declarator, tmp_list, repl_list);
			union ast_node *type_qualifier_list = replace_generic_types(node->array.type_qualifier_list, tmp_list, repl_list);
			union ast_node *expr = replace_generic_types(node->array.expr, tmp_list, repl_list);

			if (direct_declarator == node->array.direct_declarator && type_qualifier_list == node->array.type_qualifier_list && expr == node->array.expr) {
				return node;
			}

			return create_array_node(direct_declarator, type_qualifier_list, expr);
		}

	//	Binary nodes!
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
		{
			union ast_node *left = replace_generic_types(node->binary.left, tmp_list, repl_list);
			union ast_node *right = replace_generic_types(node->binary.right, tmp_list, repl_list);

			if (node->binary.left == left && node->binary.right == right) {
				return node;
			}

			return create_binary_node(node->type, left, right);
		}
		// return create_binary_node(
		// 	node->type,
		// 	replace_generic_types(node->binary.left, tmp_list, repl_list),
		// 	replace_generic_types(node->binary.right, tmp_list, repl_list));

	//	Also uses `unary` node, but it's set in the create() function!
	case AST_EXPRESSION_STATEMENT:
		return create_expression_statement_node(replace_generic_types(node->unary.expr, tmp_list, repl_list));
	//	UNARY expressions
	case AST_SIZEOF_TYPE:
		{
			union ast_node *expr = replace_generic_types(node->unary.expr, tmp_list, repl_list);

			if (expr == node->unary.expr) {
				return node;
			}

			return create_unary_node(node->type, expr);
		}

	case AST_MEMBER_ACCESS_POINTER:
	case AST_MEMBER_ACCESS:
		{
			union ast_node *object = replace_generic_types(node->member_access.object, tmp_list, repl_list);
			union ast_node *member = replace_generic_types(node->member_access.member, tmp_list, repl_list);

			if (node->member_access.object == object && node->member_access.member == member) {
				return node;
			}

			return create_member_access_node(node->type, object, member);
		}

	case AST_POINTER_DECLARATOR:
		{
			union ast_node *pointer = replace_generic_types(node->pointer_declarator.pointer, tmp_list, repl_list);
			union ast_node *direct_declarator = replace_generic_types(node->pointer_declarator.direct_declarator, tmp_list, repl_list);

			if (node->pointer_declarator.direct_declarator == direct_declarator && node->pointer_declarator.pointer == pointer) {
				return node;
			}

			return create_pointer_declarator_node(pointer, direct_declarator);
		}

	/*
		AST_POINTER
		|- .type_qualifier_list
				NULL
		|- .pointer
				NULL
	*/
	case AST_POINTER:
		{
			union ast_node *type_qual_list = replace_generic_types(node->pointer.type_qualifier_list, tmp_list, repl_list);
			union ast_node *pointer = replace_generic_types(node->pointer.pointer, tmp_list, repl_list);

			if (node->pointer.type_qualifier_list == type_qual_list && node->pointer.pointer == pointer) {
				return node;
			}

			return create_pointer_node(type_qual_list, pointer);
		}

	case AST_STRUCT_OR_UNION_DECLARATOR:
		{
			union ast_node *declarator = replace_generic_types(node->struct_or_union_declarator.declarator, tmp_list, repl_list);
			union ast_node *expr = replace_generic_types(node->struct_or_union_declarator.expr, tmp_list, repl_list);

			if (node->struct_or_union_declarator.declarator == declarator && node->struct_or_union_declarator.expr == expr) {
				return node;
			}

			return create_struct_or_union_declarator_node(declarator, expr);
		}

	case AST_STRUCT:
	case AST_UNION:
		{
			union ast_node *id = replace_generic_types(node->struct_or_union.id, tmp_list, repl_list);
			union ast_node *decl_list = replace_generic_types(node->struct_or_union.decl_list, tmp_list, repl_list);

			// if (node->struct_or_union.id == id && node->struct_or_union.decl_list == decl_list) {
			// 	return node;
			// }

			return create_struct_or_union_node(node->type, id, decl_list);
		}

	case AST_GENERIC_STRUCT:
	case AST_GENERIC_UNION:
		{
			node->type = node->type == AST_GENERIC_STRUCT ? AST_STRUCT : AST_UNION;

			union ast_node *id = replace_generic_types(node->struct_or_union.id, tmp_list, repl_list);
			union ast_node *decl_list = replace_generic_types(node->struct_or_union.decl_list, tmp_list, repl_list);

			// if (node->struct_or_union.id == id && node->struct_or_union.decl_list == decl_list) {
			// 	return node;
			// }

			const char *name = get_generic_type_name(id);
printf("New AST_GENERIC_STRUCT name: %s\n", name);
			union ast_node *new_id_node = create_id_node(name);
			name = new_id_node->id.id;	//	Set the `name` using the ID node, because the string returned by `get_generic_type_name` can be overwritten!

			//create_struct_or_union_node(id, generic_list);

			union ast_node *gen = create_struct_or_union_node(node->type, new_id_node, decl_list);
print_ast_tree(stdout, gen, 0, 0);

			return gen; //create_struct_or_union_node(node->type, new_id_node, decl_list);
		}
	}

	return node;
}


/**
 * There are essentially N types of generic type declarations & definitions:
 * struct Foo<T> { ... };			//	Definition
 * typedef Foo<int>;				//	Declare position of concrete type
 * 
 * struct Foo<>;					//	Forward declaration ... is this necessary?
 * 
 * Opaque type support:
 * -------------------
 * typedef struct Foo<> Foo<int>;	//	Forward declaration of opaque type
 * struct Foo<int>;					//	This is used by `opaque types`, to declare WHERE the `opaque type's` concrete code must go!
 * 
 * Variable Declarations:
 * ---------------------
 * Foo<int> foo;					//	Variable declaration
 */
void build_generic_struct(union ast_node *node)
{
printf("build_generic_declaration\n");
print_ast_tree(stdout, node, 0, 0);

	union ast_node *decl_specs = node->declaration.decl_specs;

	union ast_node *id = get_id_node(decl_specs);
printf("id:\n");
print_ast_tree(stdout, id, 0, 0);

	assert(id->type == AST_ID);
	const char *name = id->id.id;

	union ast_node *struct_or_union = get_node_by_type(AST_GENERIC_STRUCT, decl_specs);
	if (struct_or_union == NULL) {
		struct_or_union = get_node_by_type(AST_GENERIC_UNION, decl_specs);
	}

	symbol_t *symbol = symbol_get(name);
	if (symbol == NULL) {
		//	This could be a forward declaration or an opaque generic!
		if (struct_or_union == NULL) {
			fprintf(stderr, "SYNTAX ERROR: Unknown symbol for: %s. Unable to find a generic structure with this name.\n", name);
			exit(EXIT_FAILURE);
		}

		//	Should we get the `AST_ID` again (updated, because there can be more than one)?
		//	Someone might have defined `struct Foo<> Bar<>` ...
		//	However, the first `get_id_node()` should have returned `Foo` in this case anyway!

		symbol = symbol_add_generic_struct_or_union(name, struct_or_union);
		symbol->is_struct = struct_or_union->type == AST_GENERIC_STRUCT;
		symbol->is_union = struct_or_union->type == AST_GENERIC_UNION;

printf("Struct or Union Node:\n");
print_ast_tree(stdout, struct_or_union, 0, 0);

		// fprintf(stderr, "FATAL ERROR: Unknown symbol for: %s. Unable to find a generic structure with this name.\n", id->id.id);
		// exit(EXIT_FAILURE);
	} else {
		//	We need to confirm everything about the symbol, and update the structure if necessary!
printf("Symbol:\n");
print_ast_tree(stdout, symbol->node, 0, 0);

		if ( ! symbol->is_generic) {
			fprintf(stderr, "SYNTAX ERROR: Symbol %s is not a generic structure! Are you sure you declared a generic structure with this name?\n", name);
			exit(EXIT_FAILURE);
		}

		if ( ! symbol->is_struct && ! symbol->is_union) {
			fprintf(stderr, "SYNTAX ERROR: Symbol %s is not a struct or union type! Only `struct` or `unions` are allowed as generic types!\n", name);
			exit(EXIT_FAILURE);
		}

		if (struct_or_union) {
			if (symbol->node->struct_or_union.decl_list && struct_or_union->struct_or_union.decl_list) {
				fprintf(stderr, "SYNTAX ERROR: Re-definition of generic symbol %s!\n", name);
				exit(EXIT_FAILURE);
			}

			//	This is an update to the symbol declaration list! ie. The list of declared values in the struct.
			if (symbol->node->struct_or_union.decl_list == NULL && struct_or_union->struct_or_union.decl_list) {
				symbol->node->struct_or_union.decl_list = struct_or_union->struct_or_union.decl_list;
			}

			//	This could be an update to the type list, eg. `typedef struct Foo<> Foo<int>;`
			//	`struct Foo<>` had an anonymous type list.
			//	The `type list` is the `<T>` part!
			assert(symbol->node->struct_or_union.id->type == AST_GENERIC_DECLARATION);
			if (symbol->node->struct_or_union.id->generic_type.type_list == NULL) {
				symbol->node->struct_or_union.id->generic_type.type_list = struct_or_union->generic_type.type_list;
			}
		}
	}


	int state = 0;
	do {
		switch (state) {
		case 0:
			if (decl_specs->type != AST_LIST) {
				state = -1;
				break;
			}

			if (decl_specs->list.node->type != AST_TYPEDEF) {
				state = -1;
				break;
			}

			if (decl_specs->list.next->type != AST_LIST) {
				state = 1;
				break;
			}

			if (decl_specs->list.next->list.node->type != AST_GENERIC_STRUCT &&
				decl_specs->list.next->list.node->type != AST_GENERIC_UNION) {
				state = -1;
				break;
			}

			if (decl_specs->list.next->list.next->type != AST_GENERIC_DECLARATION) {
				state = -1;
				break;
			}

			if (decl_specs->list.next->list.next->generic_type.type_list == NULL) {
				//	The user has done this:
				//	`typedef struct Foo<> Foo<>;` ... note the second `Foo<>` is missing the type list!
				//	TODO: Add line number to the error output!
				fprintf(stderr, "SYNTAX ERROR: Generic typedef for %s is missing type list!\n", id->id.id);
				exit(EXIT_FAILURE);
			}

			if (decl_specs->list.next->list.node->struct_or_union.id->type != AST_GENERIC_DECLARATION) {
				//	The user has done this:
				//	`typedef struct Foo Foo<>;` ... note the first `struct Foo` is missing the `<>`!
				fprintf(stderr, "SYNTAX ERROR: Generic typedef for %s must have a generic struct or union declared with `<>`!\n", id->id.id);
				exit(EXIT_FAILURE);
			}

			name = get_generic_type_name(decl_specs->list.next->list.next);
			union ast_node *name_node = create_id_node(name);
			decl_specs->list.next->list.node->type = AST_STRUCT;
			decl_specs->list.next->list.node->struct_or_union.id = name_node;
			decl_specs->list.next->list.next = name_node;


printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ %s\n", name);
print_ast_tree(stdout, decl_specs->list.next, 0, 0);
// exit(1);
			return;

			state = -2;
// const char *generic_name = get_generic_type_name(generic_decl->generic_type.id);

			break;
			// if (decl_specs->list.next->list.next->struct_or_union.id->generic_type. != AST_GENERIC_DECLARATION) {

			// }

		case 1:
			if (decl_specs->list.next->type != AST_GENERIC_DECLARATION) {
				state = -1;
				break;
			}


			break;

		case 6:
			//	This is a `typedef struct Foo<> Foo<int>;`
			//	`struct Foo<>` had an anonymous type list.
			//	The `type list` is the `<T>` part!
			assert(decl_specs->list.next->list.node->type == AST_GENERIC_STRUCT || decl_specs->list.next->list.node->type == AST_GENERIC_UNION);
			assert(decl_specs->list.next->list.next->type == AST_GENERIC_DECLARATION);
			decl_specs->list.next->list.next->generic_type.type_list = decl_specs->list.next->list.node->generic_type.type_list;
			state = -1;
			break;
		}
	} while (state >= 0);



	//	This is not really very good, we are looking for a `hard coded` code structure!
	//	eg. `typedef struct Foo<> Foo<int>;`
	//	Which starts with an AST_LIST node!
	/*
		AST_DECLARATION
		|- .decl_specs
			AST_LIST
			|- .node
				AST_TYPEDEF
			|- .next
				AST_LIST
				|- .node
					AST_GENERIC_STRUCT
					|- .id
						AST_GENERIC_DECLARATION
						|- .id
							AST_ID: `Foo`
						|- .type_list
							NULL
					|- .decl_list
						NULL
				|- .next
					AST_GENERIC_DECLARATION
					|- .id
						AST_ID: `Foo`
					|- .type_list
						AST_INT
		|- .init_declarator_list
			NULL
	*/
	if (decl_specs->type == AST_LIST) {
		assert(decl_specs->list.node != NULL);
		if (decl_specs->list.node->type == AST_TYPEDEF) {
			assert(decl_specs->list.next != NULL);
			if (decl_specs->list.next->type == AST_LIST) {
				union ast_node *list = decl_specs->list.next;
				assert(list->list.node != NULL);
				if (list->list.node->type == AST_GENERIC_STRUCT || list->list.node->type == AST_GENERIC_UNION) {
					if (list->list.next->type == AST_GENERIC_DECLARATION) {
						union ast_node *generic_decl = list->list.next;
						if (generic_decl->generic_type.type_list == NULL) {
							//	This is a `typedef struct Foo<> Foo<int>;` situation!
							//	We need to update the `type_list` of the `AST_GENERIC_DECLARATION` node!
							// generic_decl->generic_type.type_list = type_list;
						} else {
							if (generic_decl->generic_type.type_list && get_id_node(generic_decl->generic_type.type_list) == NULL) {
								//	We HAVE a type_list AND it doesn't have an `id` node in it! PERFECT!
								const char *generic_name = get_generic_type_name(generic_decl->generic_type.id);
								if (generic_name) {
									
								} else {
									
								}
							} else {
								
							}
						}
					} else {

					}
				} else {
					
				}
			} else if (decl_specs->list.next->type == AST_GENERIC_DECLARATION) {
				//	This is an alternative path:
				/*
					AST_DECLARATION
					|- .decl_specs
						AST_LIST
						|- .node
							AST_TYPEDEF
						|- .next
							AST_GENERIC_DECLARATION
							|- .id
								AST_ID: `Foo`
							|- .type_list
								AST_INT
					|- .init_declarator_list
						NULL
				*/
			} else {
				//	NOTE: There are really only two types of `typedef` declarations!
			}
		}
	}


	//	For what?
	bool is_typedef = is_typedef_node(decl_specs);
	if (is_typedef) {
	}


	// if (symbol->is_struct) {
	// 	register_generic_struct(symbol->node);
	// } else if (symbol->is_union) {
	// 	register_generic_union(symbol->node);
	// } else {
	// 	fprintf(stderr, "FATAL ERROR: symbol %s is not a struct or union type!\n", id->id.id);
	// 	exit(EXIT_FAILURE);
	// }

	int type;
	if (symbol->node->type == AST_GENERIC_STRUCT) {
		type = AST_STRUCT;
	} else if (symbol->node->type == AST_GENERIC_UNION) {
		type = AST_UNION;
	} else {
		//	WHY? Why not also allow arrays? `typedef T Matrix<T,N>[N] mat<float, 4>;` hmm, how would this work?
		fprintf(stderr, "FATAL ERROR: Symbol %s is not a struct or union type! Only `struct` or `unions` are allowed as generic types!\n", id->id.id);
		exit(EXIT_FAILURE);
	}






















	union ast_node *specifier = get_node_by_type(AST_GENERIC_DECLARATION, decl_specs);
print_ast_tree(stdout, decl_specs, 0, 0);
	assert(specifier != NULL);
	//	NOTE: There is already a check for `AST_GENERIC_SPECIFIER` done in the codegen!
	// NOTE: This section of code WAS below the `get_generic_type_name` call, but I had to move it above the `opaque pointer` check!
	// if (specifier == NULL) {
	// 	fprintf(stderr, "FATAL ERROR: %s(): No generic specifier found in declaration specifiers for %s!\n", __func__, new_id_node->id.id);
	// 	exit(EXIT_FAILURE);
	// }

	name = get_generic_type_name(specifier);
	union ast_node *new_id_node = create_id_node(name);
	name = new_id_node->id.id;	//	Set the `name` using the ID node, because the string returned by `get_generic_type_name` can be overwritten!

printf("NEW NAME: %s\n", name);

	//	Check for an opaque pointer declaration: eg. `typedef struct foo *bar;`
	union ast_node *struct_or_union_decl = get_node_by_type(symbol->node->type, decl_specs);
	if (struct_or_union_decl) {
		// struct_or_union_decl->type = type;



		//	This is probably a generic `opaque pointer` declaration
printf("OPAQUE DECL\n");
	}
	// union ast_node *specifier = get_node_by_type(AST_GENERIC_SPECIFIER, decl_specs);





	/*
	AST_DECLARATION
	|- .decl_specs
		AST_LIST
		|- .node
			AST_TYPEDEF
		|- .next
			AST_GENERIC_SPECIFIER
			|- .id
				AST_ID
					`Vec3`
			|- .type_list
				AST_FLOAT
	|- .init_declarator_list
		NULL
	*/


	/*
	AST_DECLARATION
	|- .decl_specs
		AST_GENERIC_STRUCT
		|- .id
			AST_GENERIC_DECLARATION
			|- .id
				AST_ID
					`Vec3`
			|- .type_list
				AST_ID
					`T`
		|- .decl_list
			AST_LIST
				...
	*/
	union ast_node *declaration = get_node_by_type(AST_GENERIC_DECLARATION, symbol->node->struct_or_union.id);

	bool valid_type_list = check_type_list(declaration->generic_type.type_list, specifier->generic_type.type_list);
	if ( ! valid_type_list) {
		//	TODO: 'repair' the generic name displayed here! We can replace the first `__` with '<', and subsequent '__' with ',', and any '_' with ' ', then end with '>'
		fprintf(stderr, "SYNTAX ERROR: List of generic type parameters for `%s` don't match the base declaration for `%s<>`!\n", new_id_node->id.id, id->id.id);
		exit(EXIT_FAILURE);
	}

	union ast_node *new_decl_list = replace_generic_types(symbol->node->struct_or_union.decl_list, declaration->generic_type.type_list, specifier->generic_type.type_list);

printf("new_decl_list:\n");
print_ast_tree(stdout, new_decl_list, 0, 0);


	union ast_node *new_struct_or_union = create_struct_or_union_node(type, new_id_node, new_decl_list);


	node->declaration.decl_specs = create_list_node((void *) & typedef_node, new_struct_or_union, " ");
	node->declaration.init_declarator_list = new_id_node;


// printf("symbol->type: %d\n", symbol->type);
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



	// union ast_node *id = get_id_node(node->generic_type.id);

	// if (id) {
	// 	symbol_add_generic_declaration(id->id.id, node);
	// }
}



//	This works a bit differently to the 'struct builder'!
//	Here, we will construct a 'normal' 'impl' block, and then run it through the regular AST_IMPL processor!
void build_impl_from_generic(union ast_node *specifier, union ast_node *declaration)
{
	if (specifier->impl.body) {
		fprintf(stderr, "FATAL ERROR: %s(): Impl body already exists!\n", __func__);
		exit(EXIT_FAILURE);
	}

printf("%s\n", __func__);
print_ast_tree(stdout, declaration, 0, 0);
print_ast_tree(stdout, specifier, 0, 0);

	/**
	 * 	Explanation of the code that follows this comment; we basically need to convert the generic title 
	 *	Step 1: Convert the following 'generic impl' AST:
	 ********************************************

		AST_GENERIC_IMPL
		|- .id
			AST_GENERIC_SPECIFIER
			|- .id
				AST_LIST
				|- .node
					AST_ID
						`header`
				|- .next
					AST_ID
						`Vec3`
			|- .type_list
				AST_FLOAT
		|- .body
			NULL

	 *	Step 2: to this:
	 ********************************************

		AST_GENERIC_IMPL
		|- .id
			AST_GENERIC_SPECIFIER
			|- .id
				AST_ID
					`Vec3`
			|- .type_list
				AST_FLOAT
		|- .body
			NULL

	 *	Step 3: Then run the 'name generator' on the generic node: `Vec3<float>` to produce the final `impl` block name: `Vec3__float`
	 ********************************************

		AST_IMPL
		|- .id
			AST_ID
				`Vec3__float`
		|- .body
			NULL
	*/
	specifier->type = AST_IMPL;

	assert(specifier->impl.id != NULL);
	// assert(specifier->impl.id->type == AST_GENERIC_SPECIFIER);
	assert(specifier->impl.id->type == AST_GENERIC_DECLARATION);


	//	Backup the specifier `type_list`!
	//	We need the `type_list` to replace the 'generic types' in the `body`!
	//	eg. `T` (declaration type_list) -> `float` (specifier type_list)
	assert(specifier->impl.id->generic_type.type_list != NULL);
	union ast_node *type_list = specifier->impl.id->generic_type.type_list;

	assert(specifier->impl.id->generic_type.id != NULL);
	assert(specifier->impl.id->generic_type.id->type == AST_LIST);
	assert(specifier->impl.id->generic_type.id->list.next != NULL);
	assert(specifier->impl.id->generic_type.id->list.next->type == AST_ID);
	//	Remove the 'label' component from `impl <label>` for the new AST_IMPL node! We cannot use the <label>, because functions wouldn't know what `label` to use! We just need the generic name eg. `Vec3` and the type eg. `float` to construct the function prefix!
	specifier->impl.id->generic_type.id = specifier->impl.id->generic_type.id->list.next;
	// const char *name = specifier->impl.id->generic_type.id;		//specifier->impl.id->generic_type.id->list.next->id.id;
	const char *name = get_generic_type_name(specifier->impl.id);
	union ast_node *new_id_node = create_id_node(name);
	specifier->impl.id = new_id_node;
// printf("<<<<<<<<<<<< New name: %s\n", name);
// print_ast_tree(stdout, specifier->impl.id, 0, 0);
// print_ast_tree(stdout, declaration->impl.id->generic_type.type_list, 0, 0);
// print_ast_tree(stdout, type_list, 0, 0);


	// specifier->impl.id = specifier->impl.id->generic_type.id->list.next;
	//specifier->impl.body = declaration->impl.body;
	//	recursively loop through the body, and change the `T` temporary (template) type name to the actual type!
	//	We need to do this, because the AST_IMPL processor will not do this for us!
	//replace_generic_types(specifier->impl.body, declaration->generic_type.type_list, specifier->impl.id->generic_type.type_list);

	specifier->impl.body = replace_generic_types(declaration->impl.body, declaration->impl.id->generic_type.type_list, type_list);


}







void register_typedef(union ast_node *decl_specs, union ast_node *declarator)
{
	//NOTE: Here, we need to check if the declaration is a `typedef` declaration.
	//	We first scan the declaration_specifiers to see if there is a `typedef` keyword, by checking for an AST_TYPEDEF node.
	//	Then we scan the init_declarator_list to see if there is a declarator with an identifier.

	//	Scan the declaration_specifiers
	union ast_node *node;

	if ( ! is_typedef_node(decl_specs))
		return;

	node = get_id_node(declarator);

	if (node) {
		symbol_add_typedef(node->id.id, node);
		return;
	}

printf("%s(): decl_specs:\n", __func__);
print_ast_tree(stdout, decl_specs, 0, 0);

printf("%s(): declarator:\n", __func__);
print_ast_tree(stdout, declarator, 0, 0);

printf("%s(): node:\n", __func__);
print_ast_tree(stdout, node, 0, 0);

	/* if (decl_specs->type == AST_GENERIC_SPECIFIER) { */		//	it's actually an AST_LIST!

printf("%s(): generic_node: %s\n", __func__, get_generic_type_name(decl_specs));

		node = get_id_node(decl_specs);		//	eg. typedef Vec3<float>; ... it doesn't have a `declarator`! The `Vec3` ID node is inside `decl_specs`!

printf("%s(): new node:\n", __func__);
print_ast_tree(stdout, node, 0, 0);

	//	TODO: We need to generate a `generic` typedef! eg. `typedef Vec3<float>;` ==> `typedef struct Vec3__float Vec3__float;`
	//	If this IS a generic node: then `decl_specs` will be an AST_GENERIC_SPECIFIER!

		if (node) {
			symbol_add_typedef(node->id.id, node);
			return;
		}
	/* } else {
		fprintf(stderr, "FATAL ERROR: typedef has unhandled decl_specs node type: %s (%d)\n", get_node_name(decl_specs->type), decl_specs->type);
		exit(EXIT_FAILURE);
	} */

	//	NOTE: This might be the case for a typedef that is defined more than once ???. Or a symbol that doesn't have a name??? Anonymous struct? But I think the typedef will be named!
	fprintf(stderr, "FATAL ERROR: typedef has unhandled decl_specs node type: %s (%d) or ID node is NULL\n", get_node_name(decl_specs->type), decl_specs->type);
	exit(EXIT_FAILURE);
}










void register_declarator(union ast_node *node, union ast_node *typename)
{
	if (node == NULL) return;

	switch (node->type) {

	case AST_ID:
		symbol_add_variable(node->id.id, typename);
		return;

	case AST_THIS:
		symbol_add_variable("this", typename);
		return;

	case AST_SELF:
		symbol_add_variable("self", typename);
		return;

	case AST_TYPEDEF_NAME:	//	AST_TYPEDEF_NAME is not really implemented yet, but it might be in future.
		fprintf(stderr, "ERROR: `AST_TYPEDEF_NAME` node type cannot appear in the `.init_declarator_list`\n");
		exit(EXIT_FAILURE);
		return;

	case AST_LIST:
		//	Is this possible or not?
		register_declarator(node->list.node, typename);
		register_declarator(node->list.next, typename);
		return;

	default:
		return;
	}
}

void register_pointer_declarator(union ast_node *node, union ast_node *typename)
{
	if (node == NULL) return;

	switch (node->type) {

	case AST_ID:
		symbol_add_pointer(node->id.id, typename);
		return;

	case AST_THIS:
		symbol_add_pointer("this", typename);
		return;

	case AST_SELF:
		symbol_add_pointer("self", typename);
		return;

	case AST_TYPEDEF_NAME:	//	AST_TYPEDEF_NAME is not really implemented yet, but it might be in future.
		fprintf(stderr, "ERROR: `AST_TYPEDEF_NAME` node type cannot appear in the `.init_declarator_list`\n");
		exit(EXIT_FAILURE);
		return;

	case AST_LIST:
		//	Is this possible or not?
		register_pointer_declarator(node->list.node, typename);
		register_pointer_declarator(node->list.next, typename);
		return;

	default:
		return;
	}
}

void register_declaration_list(union ast_node *node, union ast_node *typename)
{
	// union ast_node *decl;

	if (node == NULL) return;

	switch (node->type) {

	case AST_ID:
	case AST_THIS:
	case AST_SELF:
		register_declarator(node, typename);
		return;

	case AST_TYPEDEF_NAME:	//	AST_TYPEDEF_NAME is not really implemented yet, but it might be in future.
		fprintf(stderr, "ERROR: `AST_TYPEDEF_NAME` node type cannot appear in the declarator_list\n");
		exit(EXIT_FAILURE);
		return;

	case AST_POINTER_DECLARATOR:
		register_pointer_declarator(node->pointer_declarator.direct_declarator, typename);
		return;

	case AST_INIT_DECLARATOR:
		register_declaration_list(node->init_declarator.declarator, typename);
		// decl = node->init_declarator.declarator;
		// if (decl->type == AST_POINTER_DECLARATOR) {
		// 	register_pointer_declarator(decl->pointer_declarator.direct_declarator, typename);
		// } else {
		// 	register_declarator(decl, typename);
		// }
		return;

	case AST_LIST:
		//	eg. const MyStruct s;
		register_declaration_list(node->list.node, typename);
		register_declaration_list(node->list.next, typename);
		return;

	case AST_ARRAY:
		//	eg. Foo foo[10]; ... `Foo` == AST_DECLARATION.decl_specs.AST_ID, `foo` == AST_DECLARATION.init_declarator_list.AST_ARRAY.direct_declarator.AST_ID
		register_declaration_list(node->array.direct_declarator, typename);
		return;

	default:
		return;
	}
}

//	This function is just used to get the "type" of the declaration.
//	eg. Car *car ... the type will be "Car".
//	This is found as an AST_ID node in the `node->declaration.decl_specs` (which can sometimes include a list, like `const Car`)
//	Once the `type` is found, then we can register individual variable names belonging to that type!
//	We currently don't implement `AST_TYPEDEF_NAME`, but this would be a very good place where that node type would be useful!
void register_variable_declaration_get_typename(union ast_node *node, union ast_node *declaration)
{
	if (node == NULL) return;

	switch (node->type) {

	case AST_ID:
	// case AST_GENERIC_SPECIFIER:
	case AST_GENERIC_DECLARATION:
		register_declaration_list(declaration->declaration.init_declarator_list, node);
		return;

	case AST_TYPEDEF_NAME:
		//	Currently, "AST_TYPEDEF_NAME" is not implemented as an actual node type, only a token returned from the lexer
		//	I'm in two minds about implementing it as an actual node type. Is it necessary? Will it be useful?
		//	Maybe in this case it will be useful, so we can detect only `AST_TYPEDEF_NAME`'s, since I think they are the only ones that will have an "impl" block!
		fprintf(stderr, "ERROR: `AST_TYPEDEF_NAME` node type should be implemented in %s()\n", __func__);
		exit(EXIT_FAILURE);
		return;

	case AST_THIS:
		// key = "this";
		break;

	case AST_SELF:
		// key = "self";
		break;

	case AST_LIST:
		//	eg. const MyStruct s;
		register_variable_declaration_get_typename(node->list.node, declaration);
		register_variable_declaration_get_typename(node->list.next, declaration);
		return;

	case AST_TYPEDEF:
		return;

	case AST_CONST:
		return;

	case AST_STRUCT:
	case AST_UNION:
		//	Does not proceed on struct and union types! This is reserved mainly for variables!
		return;

	default:
		return;
		//	I don't think we need to handle ALL cases!
		// fprintf(stderr, "ERROR: Unhandled node type (%s:%d) in %s\n", get_node_name(node->type), node->type, __func__);
		// exit(EXIT_FAILURE);
	}
}

void register_declaration(union ast_node *node)
{
	register_variable_declaration_get_typename(node->declaration.decl_specs, node);
}


