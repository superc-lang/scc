#include "ast_helpers.h"
#include "symbol_table.h"

#include <stdio.h>


int start_function(union ast_node *declspecs, union ast_node *declarator)
{
	symbol_table_push_scope();
	union ast_node *function_name = get_id_node(declarator);

	return 1;
}

const char *get_node_name(int type)
{
	switch (type) {
	case AST_ID: return "AST_ID";
	case AST_TYPEDEF_NAME: return "AST_TYPEDEF_NAME";

	case AST_LIST: return "AST_LIST";
	case AST_POINTER_DECLARATOR: return "AST_POINTER_DECLARATOR";
	case AST_GROUPED_DECLARATOR: return "AST_GROUPED_DECLARATOR";
	case AST_DESIGNATOR: return "AST_DESIGNATOR";

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
		return get_id_node(node->static_array.direct_declarator);

	case AST_ABSTRACT_DECLARATOR:	// Suggested by Copilot - not sure if I need this.
		return get_id_node(node->abstract_declarator.direct_abstract_declarator);


	//	NOTE: `.object` AND `.member` could be AST_ID's ... it's a bit ambiguous.
	case AST_MEMBER_ACCESS:
	case AST_MEMBER_ACCESS_POINTER:
		tmp = get_id_node(node->member_access.object);
		if (tmp) return tmp;
		return get_id_node(node->member_access.member);


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
		fprintf(stderr, "FATAL ERROR DETECTED - UNHANDLED NODE TYPE `%s` (%d) in `%s()`\n", get_node_name(node->type), node->type, __func__);
		exit(EXIT_FAILURE);
#endif
		return NULL;
	}
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

