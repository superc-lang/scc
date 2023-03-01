#include "print_ast_tree.h"
#include "indent.h"
#include "ast.h"
#include "ast_helpers.h"

#include <stdio.h>
#include <stdlib.h>

void print_ast_tree(FILE *out, union ast_node *node, int depth, union ast_node *parent)
{
	indent(out, depth);

	if (node == NULL) {
		fputs("NULL\n", out);
		return;
	}

	switch (node->type) {

	case AST_PRAGMA:
		fputs("AST_PRAGMA\n", out);

		indent(out, depth);
		fputs("|- .pragma\n", out);

		indent(out, depth + 1);
		fprintf(out, "#pragma %s\n", node->pragma.pragma);
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier`

	/*
	type_specifier
		: VOID
		| CHAR
		| SHORT
		| INT
		| LONG
		| FLOAT
		| DOUBLE
		| SIGNED
		| UNSIGNED
		| BOOL
		| COMPLEX
		| IMAGINARY
		| ...
		;
	*/

	case AST_VOID:
		fputs("AST_VOID\n", out);
		break;
	case AST_CHAR:
		fputs("AST_CHAR\n", out);
		break;
	case AST_SHORT:
		fputs("AST_SHORT\n", out);
		break;
	case AST_INT:
		fputs("AST_INT\n", out);
		break;
	case AST_LONG:
		fputs("AST_LONG\n", out);
		break;
	case AST_FLOAT:
		fputs("AST_FLOAT\n", out);
		break;
	case AST_DOUBLE:
		fputs("AST_DOUBLE\n", out);
		break;
	case AST_SIGNED:
		fputs("AST_SIGNED\n", out);
		break;
	case AST_UNSIGNED:
		fputs("AST_UNSIGNED\n", out);
		break;
	case AST_BOOL:
		fputs("AST_BOOL\n", out);
		break;
	case AST_COMPLEX:
		fputs("AST_COMPLEX\n", out);
		break;
	case AST_IMAGINARY:
		fputs("AST_IMAGINARY\n", out);
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ...

	/*
	type_specifier
		: ...
		| atomic_type_specifier
		| struct_or_union_specifier
		| enum_specifier
		| TYPEDEF_NAME
		;
	*/

	case AST_ATOMIC:				//	Not the same as AST_ATOMIC_TYPE!
		fputs("AST_ATOMIC\n", out);
		break;
	case AST_ATOMIC_TYPE:			//	Not the same as AST_ATOMIC!
		fputs("AST_ATOMIC_TYPE\n", out);

		indent(out, depth);
		fputs("|- .type_name\n", out);
		print_ast_tree(out, node->atomic_type.type_name, depth + 1, node);
		break;

	case AST_STRUCT:
		fputs("AST_STRUCT\n", out);

	print_struct_or_union:
		indent(out, depth);
		fputs("|- .id\n", out);
		print_ast_tree(out, node->struct_or_union.id, depth + 1, node);

		indent(out, depth);
		fputs("|- .decl_list\n", out);
		print_ast_tree(out, node->struct_or_union.decl_list, depth + 1, node);
		break;

	case AST_UNION:
		fputs("AST_UNION\n", out);
		goto print_struct_or_union;

	//	...

	case AST_TYPEDEF_NAME:					/* same as AST_ID */
		fputs("AST_TYPEDEF_NAME\n", out);

		indent(out, depth);
		fputs("|- .id\n", out);

		indent(out, depth + 1);
		fprintf(out, "`%s`\n", node->id.id);
		break;


	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ... GCC Extensions

	case AST__BUILTIN_VA_LIST:
		fputs("AST__BUILTIN_VA_LIST\n", out);
		break;








	//	-----------------------------------------------------------------------
	//	`storage_class_specifier`

	/*
	storage_class_specifier
		: TYPEDEF	//	identifiers must be flagged as TYPEDEF_NAME
		| EXTERN
		| STATIC
		| THREAD_LOCAL
		| AUTO
		| REGISTER
		;
	*/
	case AST_TYPEDEF:
		fputs("AST_TYPEDEF\n", out);
		break;
	case AST_EXTERN:
		fputs("AST_EXTERN\n", out);
		break;
	case AST_STATIC:
		fputs("AST_STATIC\n", out);
		break;
	case AST_THREAD_LOCAL:
		fputs("AST_THREAD_LOCAL\n", out);
		break;
	case AST_AUTO:
		fputs("AST_AUTO\n", out);
		break;
	case AST_REGISTER:
		fputs("AST_REGISTER\n", out);
		break;


	/* GCC "__extension__" */
	case AST__EXTENSION__:
		fputs("AST__EXTENSION__\n", out);
		break;





	//	-----------------------------------------------------------------------


	case AST_LIST:
		fputs("AST_LIST\n", out);

		// for (int i = 0; i < node->list.size; i++) {
		// 	print_ast_tree(out, node->list.nodes[i], depth + 1);
		// }
	print_list_node:		//	Used by: AST_GENERIC_LIST
		indent(out, depth);
		fputs("|- .node\n", out);
		print_ast_tree(out, node->list.node, depth + 1, node);

		indent(out, depth);
		fputs("|- .next\n", out);
		print_ast_tree(out, node->list.next, depth + 1, node);
		break;

	case AST_DECLARATION:
		fputs("AST_DECLARATION\n", out);
		// print_ast_tree(out, node->declaration.declarator, depth + 1);

		indent(out, depth);
		fputs("|- .decl_specs\n", out);
		print_ast_tree(out, node->declaration.decl_specs, depth + 1, node);

		indent(out, depth);
		fputs("|- .init_declarator_list\n", out);
		print_ast_tree(out, node->declaration.init_declarator_list, depth + 1, node);
		break;

	// case AST_DECLARATOR:
	// 	fputs("AST_DECLARATOR\n", out);
	// 	print_ast_tree(out, node->declarator.direct_declarator, depth + 1);
	// 	break;

	case AST_POINTER_DECLARATOR:
		fputs("AST_POINTER_DECLARATOR\n", out);

	_print_ast_pointer_declarator:
		indent(out, depth);
		fputs("|- .pointer\n", out);
		print_ast_tree(out, node->pointer_declarator.pointer, depth + 1, node);

		indent(out, depth);
		fputs("|- .direct_declarator\n", out);
		print_ast_tree(out, node->pointer_declarator.direct_declarator, depth + 1, node);
		break;

	case AST_POINTER:
		fputs("AST_POINTER\n", out);

	// _print_ast_pointer:
		indent(out, depth);
		fputs("|- .type_qualifier_list\n", out);
		print_ast_tree(out, node->pointer.type_qualifier_list, depth + 1, node);	//	NULL & NULL == basic pointer! eg. int *i;

		indent(out, depth);
		fputs("|- .pointer\n", out);
		print_ast_tree(out, node->pointer.pointer, depth + 1, node);
		break;





	//	-----------------------------------------------------------------------
	//	`type_qualifier`
	//	-----------------------------------------------------------------------

	/*
	type_qualifier
		: CONST
		| RESTRICT
		| VOLATILE
		| ATOMIC
		;
	*/
	case AST_CONST:
		fputs("AST_CONST\n", out);
		break;
	case AST_RESTRICT:
		fputs("AST_RESTRICT\n", out);
		break;
	case AST_VOLATILE:
		fputs("AST_VOLATILE\n", out);
		break;
	// case AST_ATOMIC:
	// 	fputs("atomic", out);
	// 	break;

	/* GCC */
	case AST__RESTRICT:
		fputs("AST__RESTRICT\n", out);
		break;


	//	-----------------------------------------------------------------------
	//	`function_specifier`
	//	-----------------------------------------------------------------------

	/*
	function_specifier
		: INLINE
		| NORETURN
		;
	*/

	case AST_INLINE:
		fputs("AST_INLINE\n", out);
		break;
	case AST_NORETURN:
		fputs("AST_NORETURN\n", out);
		break;

	//	-----------------------------------------------------------------------
	//	GCC __inline && __inline__ extensions
	case AST__INLINE:
		fputs("AST__INLINE\n", out);
		break;
	case AST__INLINE__:
		fputs("AST__INLINE__\n", out);
		break;


	//	----------------------------------------------
	//	`assignment_expression`
	//	----------------------------------------------

	case AST_ASSIGN:
		fputs("AST_ASSIGN\n", out);

	BINARY_NODE:
		indent(out, depth);
		fputs("|- .left\n", out);
		print_ast_tree(out, node->binary.left, depth + 1, node);

		indent(out, depth);
		fputs("|- .right\n", out);
		print_ast_tree(out, node->binary.right, depth + 1, node);
		break;

	case AST_ADD_ASSIGN:
		fputs("AST_ADD_ASSIGN\n", out);
		goto BINARY_NODE;
	case AST_SUB_ASSIGN:
		fputs("AST_SUB_ASSIGN\n", out);
		goto BINARY_NODE;
	case AST_MUL_ASSIGN:
		fputs("AST_MUL_ASSIGN\n", out);
		goto BINARY_NODE;
	case AST_DIV_ASSIGN:
		fputs("AST_DIV_ASSIGN\n", out);
		goto BINARY_NODE;
	case AST_MOD_ASSIGN:
		fputs("AST_MOD_ASSIGN\n", out);
		goto BINARY_NODE;
	case AST_AND_ASSIGN:
		fputs("AST_AND_ASSIGN\n", out);
		goto BINARY_NODE;
	case AST_XOR_ASSIGN:
		fputs("AST_XOR_ASSIGN\n", out);
		goto BINARY_NODE;
	case AST_OR_ASSIGN:
		fputs("AST_OR_ASSIGN\n", out);
		goto BINARY_NODE;
	case AST_SHL_ASSIGN:
		fputs("AST_SHL_ASSIGN\n", out);
		goto BINARY_NODE;
	case AST_SHR_ASSIGN:
		fputs("AST_SHR_ASSIGN\n", out);
		goto BINARY_NODE;

	//	----------------------------------------------
	//	END `assignment_expression`
	//	----------------------------------------------


	//	----------------------------------------------
	//	`conditional_expression`
	//	----------------------------------------------

	case AST_TERNARY:
		fputs("AST_TERNARY\n", out);

		indent(out, depth);
		fputs("|- cond:\n", out);
		print_ast_tree(out, node->ternary.cond, depth + 1, node);

		indent(out, depth);
		fputs("|- true_expr:\n", out);
		print_ast_tree(out, node->ternary.true_expr, depth + 1, node);

		indent(out, depth);
		fputs("|- false_expr:\n", out);
		print_ast_tree(out, node->ternary.false_expr, depth + 1, node);
		break;

	//	-----------------------------------------------------------------------
	//	`logical_or_expression`
	//	-----------------------------------------------------------------------

	case AST_OR:
		fputs("AST_OR\n", out);
		goto BINARY_NODE;

	//	-----------------------------------------------------------------------
	//	`logical_and_expression`
	//	-----------------------------------------------------------------------

	case AST_AND:
		fputs("AST_AND\n", out);
		goto BINARY_NODE;

	//	-----------------------------------------------------------------------
	//	`inclusive_or_expression`
	//	-----------------------------------------------------------------------

	case AST_BIT_OR:
		fputs("AST_BIT_OR\n", out);
		goto BINARY_NODE;

	//	-----------------------------------------------------------------------
	//	`exclusive_or_expression`
	//	-----------------------------------------------------------------------

	case AST_BIT_XOR:
		fputs("AST_BIT_XOR\n", out);
		goto BINARY_NODE;

	//	-----------------------------------------------------------------------
	//	`and_expression`
	//	-----------------------------------------------------------------------

	case AST_BIT_AND:
		fputs("AST_BIT_AND\n", out);
		goto BINARY_NODE;

	//	----------------------------------------------
	//	`equality_expression`
	//	----------------------------------------------

	case AST_EQ:
		fputs("AST_EQ\n", out);
		goto BINARY_NODE;

	case AST_NE:
		fputs("AST_NE\n", out);
		goto BINARY_NODE;

	//	----------------------------------------------
	//	END `equality_expression`
	//	----------------------------------------------


	case AST_GT:
		fputs("AST_GT\n", out);
		goto BINARY_NODE;
	case AST_GE:
		fputs("AST_GE\n", out);
		goto BINARY_NODE;
	case AST_LT:
		fputs("AST_LT\n", out);
		goto BINARY_NODE;
	case AST_LE:
		fputs("AST_LE\n", out);
		goto BINARY_NODE;


	case AST_ADD:
		fputs("AST_ADD\n", out);
		goto BINARY_NODE;
	case AST_SUB:
		fputs("AST_SUB\n", out);
		goto BINARY_NODE;
	case AST_MUL:
		fputs("AST_MUL\n", out);
		goto BINARY_NODE;
	case AST_DIV:
		fputs("AST_DIV\n", out);
		goto BINARY_NODE;
	case AST_MOD:
		fputs("AST_MOD\n", out);
		goto BINARY_NODE;


	case AST_SHL:
		fputs("AST_SHL\n", out);
		goto BINARY_NODE;
	case AST_SHR:
		fputs("AST_SHR\n", out);
		goto BINARY_NODE;



	// case AST_UNARY:
	// 	fputs("AST_UNARY\n", out);
	// 	print_ast_tree(out, node->unary.expr, depth + 1);
	// 	break;


	//	-----------------------------------------------------------------------
	//	`cast_expression`
	//	-----------------------------------------------------------------------

	/*
	cast_expression
		: unary_expression
		| '(' type_name ')' cast_expression			//	AST_CAST
		;
	*/
	case AST_CAST:
		fputs("AST_CAST\n", out);

		indent(out, depth);
		fputs("|- type_name:\n", out);
		print_ast_tree(out, node->cast.type_name, depth + 1, node);

		indent(out, depth);
		fputs("|- expr:\n", out);
		print_ast_tree(out, node->cast.expr, depth + 1, node);
		break;


	//	-----------------------------------------------------------------------
	//	`unary_expression`
	//	-----------------------------------------------------------------------

	/*
	unary_expression
		: postfix_expression
		| INC unary_expression
		| DEC unary_expression
		| unary_operator cast_expression
		| SIZEOF unary_expression
		| SIZEOF '(' type_name ')'
		| ALIGNOF '(' type_name ')'
		| extension_specifier cast_expression %prec UNARY
	*/

	case AST_PRE_INC:
		fputs("AST_PRE_INC\n", out);

		indent(out, depth);
		fputs("|- ++.expr\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;

	case AST_PRE_DEC:
		fputs("AST_PRE_DEC\n", out);

		indent(out, depth);
		fputs("|- --.expr\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;

	case AST_SIZEOF_EXPR:
		fputs("AST_SIZEOF_EXPR\n", out);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;

	case AST_SIZEOF_TYPE:
		fputs("AST_SIZEOF_TYPE\n", out);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;

	case AST_ALIGNOF:
		fputs("AST_ALIGNOF\n", out);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;


	//	----------------------------------------------
	//	`unary_operator`
	//	----------------------------------------------

	/*
	unary_operator
		: '&'				//	AST_ADDRESS_OF
		| '*'				//	AST_DEREFERENCE
		| '+'				//	AST_POSITIVE
		| '-'				//	AST_NEGATIVE
		| '~'				//	AST_BITWISE_NOT
		| '!'				//	AST_LOGICAL_NOT
		;
	*/
	case AST_ADDRESS_OF:
		fputs("AST_ADDRESS_OF: (&)\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;
	case AST_DEREFERENCE:
		fputs("AST_DEREFERENCE: (*)\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;
	case AST_POSITIVE:
		fputs("AST_POSITIVE: (+)\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;
	case AST_NEGATIVE:
		fputs("AST_NEGATIVE: (-)\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;
	case AST_BITWISE_NOT:
		fputs("AST_BITWISE_NOT: (~)\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;
	case AST_LOGICAL_NOT:
		fputs("AST_LOGICAL_NOT: (!)\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;




	//	-----------------------------------------------------------------------
	//	`postfix_expression`
	//	-----------------------------------------------------------------------

	/*
	postfix_expression
		: primary_expression
		| postfix_expression '[' expression ']'					//	AST_ARRAY_SUBSCRIPT
		| postfix_expression '(' ')'							//	AST_FUNCTION_CALL
		| postfix_expression '(' argument_expression_list ')'	//	AST_FUNCTION_CALL
		| postfix_expression '.' IDENTIFIER						//	AST_MEMBER_ACCESS
		| postfix_expression ARROW IDENTIFIER					//	AST_MEMBER_ACCESS_POINTER
		| postfix_expression INC								//	AST_POST_INC
		| postfix_expression DEC								//	AST_POST_DEC
		| '(' type_name ')' '{' initializer_list '}'			//	AST_COMPOUND_LITERAL
		| '(' type_name ')' '{' initializer_list ',' '}'		//	AST_COMPOUND_LITERAL
		;
	*/

	case AST_ARRAY_SUBSCRIPT:
		fputs("AST_ARRAY_SUBSCRIPT\n", out);

		indent(out, depth);
		fputs("|- .array\n", out);
		print_ast_tree(out, node->array_subscript.array, depth + 1, node);

		indent(out, depth);
		fputs("|- .index\n", out);
		print_ast_tree(out, node->array_subscript.index, depth + 1, node);
		break;

	case AST_FUNCTION_CALL:
		fputs("AST_FUNCTION_CALL\n", out);

	_print_ast_function_call:					//	Used by `AST_DELETE_OPERATOR`
		indent(out, depth);
		fputs("|- .function\n", out);
		print_ast_tree(out, node->function_call.function, depth + 1, node);

		indent(out, depth);
		fputs("|- .args\n", out);
		print_ast_tree(out, node->function_call.args, depth + 1, node);
		break;

	case AST_MEMBER_ACCESS:
		fputs("AST_MEMBER_ACCESS\n", out);

		indent(out, depth);
		fputs("|- .object\n", out);
		print_ast_tree(out, node->member_access.object, depth + 1, node);

		indent(out, depth);
		fputs("|- .member\n", out);
		print_ast_tree(out, node->member_access.member, depth + 1, node);
		break;

	case AST_MEMBER_ACCESS_POINTER:
		fputs("AST_MEMBER_ACCESS_POINTER\n", out);

		indent(out, depth);
		fputs("|- .object\n", out);
		print_ast_tree(out, node->member_access.object, depth + 1, node);

		indent(out, depth);
		fputs("|- .member\n", out);
		print_ast_tree(out, node->member_access.member, depth + 1, node);
		break;

	case AST_POST_INC:
		fputs("AST_POST_INC\n", out);

		indent(out, depth);
		fputs("|- .expr++\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;

	case AST_POST_DEC:
		fputs("AST_POST_DEC\n", out);

		indent(out, depth);
		fputs("|- .expr--\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;

	case AST_COMPOUND_LITERAL:
		fputs("AST_COMPOUND_LITERAL\n", out);

		indent(out, depth);
		fputs("|- .type_name\n", out);
		print_ast_tree(out, node->compound_literal.type_name, depth + 1, node);

		indent(out, depth);
		fputs("|- .init_list\n", out);
		print_ast_tree(out, node->compound_literal.init_list, depth + 1, node);
		break;














	//	-----------------------------------------------------------------------
	//	-----------------------------------------------------------------------






	case AST_INIT_DECLARATOR:
		fputs("AST_INIT_DECLARATOR\n", out);

		indent(out, depth);
		fputs("|- .declarator\n", out);
		print_ast_tree(out, node->init_declarator.declarator, depth + 1, node);

		indent(out, depth);
		fputs("|- .initializer\n", out);
		print_ast_tree(out, node->init_declarator.initializer, depth + 1, node);
		break;


	case AST_BLOCK:
		fputs("AST_BLOCK\n", out);

		indent(out, depth);
		fputs("|- .stmts\n", out);
		print_ast_tree(out, node->block.stmts, depth + 1, node);
		break;




	case AST_EXPRESSION_GROUP:
		fputs("AST_EXPRESSION_GROUP\n", out);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;




	//	-----------------------------------------------------------------------
	//	`struct_declaration_list`
	//	-----------------------------------------------------------------------

	/*
	struct_declaration_list
		: struct_declaration
		| struct_declaration_list struct_declaration
		;

	struct_declaration
		: specifier_qualifier_list ';'	//	for anonymous struct/union
		| specifier_qualifier_list struct_declarator_list ';'
		| static_assert_declaration
		;

	specifier_qualifier_list
		: type_specifier specifier_qualifier_list
		| type_specifier
		| type_qualifier specifier_qualifier_list
		| type_qualifier
		;

	struct_declarator_list
		: struct_declarator
		| struct_declarator_list ',' struct_declarator
		;

	struct_declarator
		: ':' constant_expression
		| declarator ':' constant_expression
		| declarator
		;
	*/
	case AST_STRUCT_OR_UNION_DECLARATION:
		fputs("AST_STRUCT_OR_UNION_DECLARATION\n", out);

		indent(out, depth);
		fputs("|- .spec_qual_list\n", out);
		print_ast_tree(out, node->struct_or_union_declaration.spec_qual_list, depth + 1, node);

		indent(out, depth);
		fputs("|- .decl_list\n", out);
		print_ast_tree(out, node->struct_or_union_declaration.decl_list, depth + 1, node);
		break;

	case AST_STRUCT_OR_UNION_DECLARATOR:
		fputs("AST_STRUCT_OR_UNION_DECLARATOR\n", out);

		indent(out, depth);
		fputs("|- .declarator\n", out);
		print_ast_tree(out, node->struct_or_union_declarator.declarator, depth + 1, node);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->struct_or_union_declarator.expr, depth + 1, node);
		break;


	//	-----------------------------------------------------------------------
	//	`enum_specifier`
	//	-----------------------------------------------------------------------
	/*
	enum_specifier
		: ENUM '{' enumerator_list '}'
		| ENUM '{' enumerator_list ',' '}'
		| ENUM identifier '{' enumerator_list '}'
		| ENUM identifier '{' enumerator_list ',' '}'
		| ENUM identifier
		;
	*/
	case AST_ENUM:
		fputs("AST_ENUM\n", out);

		indent(out, depth);
		fputs("|- .id\n", out);
		print_ast_tree(out, node->enum_type.id, depth + 1, node);

		indent(out, depth);
		fputs("|- .list\n", out);
		print_ast_tree(out, node->enum_type.list, depth + 1, node);
		break;

	//	-----------------------------------------------------------------------
	//	`enumerator_list` && `enumerator`
	//	-----------------------------------------------------------------------
	/*
	enumerator_list
		: enumerator
		| enumerator_list ',' enumerator
		;
	enumerator
		: enumeration_constant '=' constant_expression
		| enumeration_constant
		;
	*/
	case AST_ENUM_INIT:
		fputs("AST_ENUM_INIT\n", out);

		indent(out, depth);
		fputs("|- .left\n", out);
		print_ast_tree(out, node->binary.left, depth + 1, node);

		indent(out, depth);
		fputs("|- .right\n", out);
		print_ast_tree(out, node->binary.right, depth + 1, node);
		break;


	//	-----------------------------------------------------------------------




	case AST_ABSTRACT_TYPE_NAME:
		fputs("AST_ABSTRACT_TYPE_NAME\n", out);

		indent(out, depth);
		fputs("|- .specifier_qualifier_list\n", out);
		print_ast_tree(out, node->abstract_type_name.specifier_qualifier_list, depth + 1, node);

		indent(out, depth);
		fputs("|- .abstract_declarator\n", out);
		print_ast_tree(out, node->abstract_type_name.abstract_declarator, depth + 1, node);
		break;

	case AST_ABSTRACT_DECLARATOR:
		fputs("AST_ABSTRACT_DECLARATOR\n", out);

		indent(out, depth);
		fputs("|- .pointer\n", out);
		print_ast_tree(out, node->abstract_declarator.pointer, depth + 1, node);

		indent(out, depth);
		fputs("|- .direct_abstract_declarator\n", out);
		print_ast_tree(out, node->abstract_declarator.direct_abstract_declarator, depth + 1, node);
		break;


	case AST_FUNCTION_DEFINITION:
		fputs("AST_FUNCTION_DEFINITION\n", out);

	_print_ast_function_definition:
		indent(out, depth);
		fputs("|- .decl_specs\n", out);
		print_ast_tree(out, node->function_definition.decl_specs, depth + 1, node);

		indent(out, depth);
		fputs("|- .declarator\n", out);
		print_ast_tree(out, node->function_definition.declarator, depth + 1, node);

		indent(out, depth);
		fputs("|- .decl_list\n", out);
		print_ast_tree(out, node->function_definition.decl_list, depth + 1, node);

		indent(out, depth);
		fputs("|- .block\n", out);
		print_ast_tree(out, node->function_definition.block, depth + 1, node);
		break;

	case AST_PARAMETER_DECLARATION:
		fputs("AST_PARAMETER_DECLARATION\n", out);

		indent(out, depth);
		fputs("|- .decl_specs\n", out);
		print_ast_tree(out, node->parameter_declaration.decl_specs, depth + 1, node);

		indent(out, depth);
		fputs("|- .declarator\n", out);
		print_ast_tree(out, node->parameter_declaration.declarator, depth + 1, node);
		break;


	case AST_RETURN:
		fputs("AST_RETURN\n", out);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->return_stmt.expr, depth + 1, node);
		break;


	//	-----------------------------------------------------------------------
	//	`direct_declarator`

	case AST_GROUPED_DECLARATOR:
		fputs("AST_GROUPED_DECLARATOR\n", out);

		indent(out, depth);
		fputs("|- .declarator\n", out);
		print_ast_tree(out, node->grouped_declarator.declarator, depth + 1, node);
		break;

	case AST_UNSPECIFIED_ARRAY:
		fputs("AST_UNSPECIFIED_ARRAY\n", out);

		indent(out, depth);
		fputs("|- .direct_declarator\n", out);
		print_ast_tree(out, node->unspecified_array.direct_declarator, depth + 1, node);

		indent(out, depth);
		fputs("|- .type_qualifier_list\n", out);
		print_ast_tree(out, node->unspecified_array.type_qualifier_list, depth + 1, node);
		break;

	case AST_DYNAMIC_ARRAY:
		fputs("AST_DYNAMIC_ARRAY\n", out);

		indent(out, depth);
		fputs("|- .direct_declarator\n", out);
		print_ast_tree(out, node->dynamic_array.direct_declarator, depth + 1, node);

		indent(out, depth);
		fputs("|- .type_qualifier_list\n", out);
		print_ast_tree(out, node->dynamic_array.type_qualifier_list, depth + 1, node);
		break;

	case AST_STATIC_ARRAY:
		fputs("AST_STATIC_ARRAY\n", out);

		indent(out, depth);
		fputs("|- .direct_declarator\n", out);
		print_ast_tree(out, node->array.direct_declarator, depth + 1, node);

		indent(out, depth);
		fputs("|- .type_qualifier_list\n", out);
		print_ast_tree(out, node->array.type_qualifier_list, depth + 1, node);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->array.expr, depth + 1, node);
		break;

	case AST_ARRAY:
		fputs("AST_ARRAY\n", out);

		indent(out, depth);
		fputs("|- .direct_declarator\n", out);
		print_ast_tree(out, node->array.direct_declarator, depth + 1, node);

		indent(out, depth);
		fputs("|- .type_qualifier_list\n", out);
		print_ast_tree(out, node->array.type_qualifier_list, depth + 1, node);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->array.expr, depth + 1, node);
		break;

	case AST_FUNCTION_DECLARATOR:
		fputs("AST_FUNCTION_DECLARATOR\n", out);

		indent(out, depth);
		fputs("|- .direct_declarator\n", out);
		print_ast_tree(out, node->function_declarator.direct_declarator, depth + 1, node);

		indent(out, depth);
		fputs("|- .params\n", out);
		print_ast_tree(out, node->function_declarator.params, depth + 1, node);

		indent(out, depth);
		fputs("|- .identifier_list\n", out);
		print_ast_tree(out, node->function_declarator.identifier_list, depth + 1, node);
		break;

	//	end `direct_declarator`
	//	-----------------------------------------------------------------------



	//	----------------------------------------------
	//	`selection_statement`
	//	----------------------------------------------
	/*
	selection_statement
		: IF '(' expression ')' statement ELSE statement
		| IF '(' expression ')' statement
		| SWITCH '(' expression ')' statement
		;
	*/
	case AST_IF:
		fputs("AST_IF\n", out);

		indent(out, depth);
		fputs("|- .cond\n", out);
		print_ast_tree(out, node->if_stmt.cond, depth + 1, node);

		indent(out, depth);
		fputs("|- .if_true\n", out);
		print_ast_tree(out, node->if_stmt.if_true, depth + 1, node);

		indent(out, depth);
		fputs("|- .if_false\n", out);
		print_ast_tree(out, node->if_stmt.if_false, depth + 1, node);
		break;

	case AST_SWITCH:
		fputs("AST_SWITCH\n", out);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->switch_stmt.expr, depth + 1, node);

		indent(out, depth);
		fputs("|- .stmt\n", out);
		print_ast_tree(out, node->switch_stmt.stmt, depth + 1, node);
		break;



	//	-----------------------------------------------------------------------
	//	`iteration_statement`
	//	-----------------------------------------------------------------------

	/*
	iteration_statement
		: WHILE '(' expression ')' statement
		| DO statement WHILE '(' expression ')' ';'
		| FOR '(' expression_statement expression_statement ')' statement
		| FOR '(' expression_statement expression_statement expression ')' statement
		| FOR '(' declaration expression_statement ')' statement
		| FOR '(' declaration expression_statement expression ')' statement
		;
	*/

	case AST_WHILE:
		fputs("AST_WHILE\n", out);

		indent(out, depth);
		fputs("|- .cond\n", out);
		print_ast_tree(out, node->while_stmt.cond, depth + 1, node);

		indent(out, depth);
		fputs("|- .body\n", out);
		print_ast_tree(out, node->while_stmt.body, depth + 1, node);
		break;

	case AST_DO_WHILE:
		fputs("AST_DO_WHILE\n", out);

		indent(out, depth);
		fputs("|- .body\n", out);
		print_ast_tree(out, node->do_while_stmt.body, depth + 1, node);

		indent(out, depth);
		fputs("|- .cond\n", out);
		print_ast_tree(out, node->do_while_stmt.cond, depth + 1, node);
		break;

	case AST_FOR:
		fputs("AST_FOR\n", out);

		indent(out, depth);
		fputs("|- .init\n", out);
		print_ast_tree(out, node->for_stmt.init, depth + 1, node);

		indent(out, depth);
		fputs("|- .cond\n", out);
		print_ast_tree(out, node->for_stmt.cond, depth + 1, node);

		indent(out, depth);
		fputs("|- .incr\n", out);
		print_ast_tree(out, node->for_stmt.incr, depth + 1, node);

		indent(out, depth);
		fputs("|- .body\n", out);
		print_ast_tree(out, node->for_stmt.body, depth + 1, node);
		break;

	//	-----------------------------------------------------------------------
	//	`expression_statement`
	//	-----------------------------------------------------------------------

	case AST_EXPRESSION_STATEMENT:
		fputs("AST_EXPRESSION_STATEMENT\n", out);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->unary.expr, depth + 1, node);
		break;



	//	-----------------------------------------------------------------------
	//	`initializer`
	//	`initializer_list`
	//	`designation`
	//	`designator_list`
	//	`designator`
	//	-----------------------------------------------------------------------

	/*
	initializer
		: '{' initializer_list '}'							// create_initializer_node($2);
		| '{' initializer_list ',' '}'						// create_initializer_node($2);
		| assignment_expression
		;
	*/

	case AST_INITIALIZER:
		fputs("AST_INITIALIZER\n", out);

		indent(out, depth);
		fputs("|- .list\n", out);
		print_ast_tree(out, node->initializer.list, depth + 1, node);
		break;

	/*
	initializer_list
		: designation initializer							// create_designation_initializer_node($1, $2);
		| initializer				
		| initializer_list ',' designation initializer		// create_list_node($1, create_designation_initializer_node($3, $4), ", ");
		| initializer_list ',' initializer					// create_list_node($1, $3, ", ");
		;
	*/

	/*
	designation
		: designator_list '='
		;
	*/

	case AST_DESIGNATION_INITIALIZER:
		fputs("AST_DESIGNATION_INITIALIZER\n", out);

		indent(out, depth);
		fputs("|- .designation\n", out);
		print_ast_tree(out, node->designation_initializer.designation, depth + 1, node);

		indent(out, depth);
		fputs("|- .initializer\n", out);
		print_ast_tree(out, node->designation_initializer.initializer, depth + 1, node);
		break;

	/*
	designator_list
		: designator
		| designator_list designator		//	AST_LIST
		;
	*/
	/*
	designator
		: '[' constant_expression ']'		//	create_designator_node($2, NULL);
		| '.' IDENTIFIER					//	create_designator_node(NULL, $2);
		;
	*/

	case AST_DESIGNATOR:
		fputs("AST_DESIGNATOR\n", out);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->designator.expr, depth + 1, node);

		indent(out, depth);
		fputs("|- .id\n", out);
		print_ast_tree(out, node->designator.id, depth + 1, node);	//	most common case!
		break;


	//	-----------------------------------------------------------------------
	//	`_Static_assert` (C11 keyword) || `static_assert` (C23 keyword, C11 macro)
	//	-----------------------------------------------------------------------

	/*
	static_assert_declaration
		: _STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
		| _STATIC_ASSERT '(' constant_expression ')' ';'
		| STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
		| STATIC_ASSERT '(' constant_expression ')' ';'
		;
	*/

	case AST__STATIC_ASSERT:
		fputs("AST__STATIC_ASSERT\n", out);
		goto _print_ast_static_assert;

	case AST_STATIC_ASSERT:
		fputs("AST_STATIC_ASSERT\n", out);

	_print_ast_static_assert:
		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->static_assert_stmt.expr, depth + 1, node);

		indent(out, depth);
		fputs("|- .str\n", out);
		print_ast_tree(out, node->static_assert_stmt.str, depth + 1, node);
		break;



	/* ELLIPSIS token == "..." */
	case AST_ELLIPSIS:
		fputs("AST_ELLIPSIS\n", out);


	case AST__ATTRIBUTE__:
		fputs("AST__ATTRIBUTE__\n", out);

		indent(out, depth);
		fputs("|- .expr\n", out);
		indent(out, depth + 1);
		fprintf(out, "`%s`\n", node->attribute.src_code);
		break;


	case AST__ASM__:
		fprintf(out, "AST__ASM__: `%s`\n", node->str.str);
		break;


	//	-----------------------------------------------------------------------
	//	Super C Extensions
	//	-----------------------------------------------------------------------

	case AST_IMPL:
		fputs("AST_IMPL\n", out);

	_print_impl_node:
		indent(out, depth);
		fputs("|- .id\n", out);
		print_ast_tree(out, node->impl.id, depth + 1, node);

		indent(out, depth);
		fputs("|- .body\n", out);
		print_ast_tree(out, node->impl.body, depth + 1, node);
		break;

	case AST_STATIC_IMPL:
		fputs("AST_STATIC_IMPL\n", out);
		goto _print_impl_node;

	case AST_THIS:
		fputs("AST_THIS\n", out);
		break;

	case AST_SELF:
		fputs("AST_SELF\n", out);
		break;

	case AST_NS_OP:
		fputs("AST_NS_OP\n", out);

		indent(out, depth);
		fputs("|- .left\n", out);
		print_ast_tree(out, node->binary.left, depth + 1, node);

		indent(out, depth);
		fputs("|- .right\n", out);
		print_ast_tree(out, node->binary.right, depth + 1, node);
		break;

/*
	case AST_NEW:
		fputs("AST_NEW\n", out);

		indent(out, depth);
		fputs("|- .id\n", out);
		print_ast_tree(out, node->new.id, depth + 1, node);

		indent(out, depth);
		fputs("|- .parameter_list\n", out);
		print_ast_tree(out, node->new.parameter_list, depth + 1, node);
		break;

	case AST_DELETE:
		fputs("AST_DELETE\n", out);

		indent(out, depth);
		fputs("|- .id\n", out);
		print_ast_tree(out, node->delete.id, depth + 1, node);

		indent(out, depth);
		fputs("|- .expr\n", out);
		print_ast_tree(out, node->delete.expr, depth + 1, node);
		break;
*/

	case AST_IMPL_NEW_FUNCTION:
		fputs("AST_IMPL_NEW_FUNCTION\n", out);
		goto _print_ast_function_definition;	//	AST_FUNCTION_DEFINITION

	case AST_IMPL_NEW_DECLARATOR:
		fputs("AST_IMPL_NEW_DECLARATOR\n", out);
		goto _print_ast_pointer_declarator;		//	AST_POINTER_DECLARATOR / `pointer_declarator`

	case AST_IMPL_DELETE_FUNCTION:
		fputs("AST_IMPL_DELETE_FUNCTION\n", out);
		goto _print_ast_function_definition;	//	AST_FUNCTION_DEFINITION



	case AST_DELETE_OPERATOR:
		fputs("AST_DELETE_OPERATOR\n", out);
		goto _print_ast_function_call;			//	AST_FUNCTION_CALL

		// indent(out, depth);
		// fputs("|- .id\n", out);
		// print_ast_tree(out, node->delete.id, depth + 1, node);

		// indent(out, depth);
		// fputs("|- .expr\n", out);
		// print_ast_tree(out, node->delete.expr, depth + 1, node);
		// break;


	case AST_IMPL_FUNCTION_DECLARATION:
		fputs("AST_IMPL_FUNCTION_DECLARATION\n", out);
		goto _print_ast_function_definition;	//	AST_FUNCTION_DEFINITION

	// case AST_BLANK_ID:
	// 	fputs("AST_BLANK_ID\n", out);
	// 	break;

	case AST_GETTER:
		fputs("AST_GETTER\n", out);
		goto _print_ast_function_definition;	//	AST_FUNCTION_DEFINITION

	case AST_SETTER:
		fputs("AST_SETTER\n", out);
		goto _print_ast_function_definition;	//	AST_FUNCTION_DEFINITION


	//	-----------------------------------------------------------------------
	//	generics
	//	-----------------------------------------------------------------------

	case AST_GENERIC_STRUCT:	//	NOT the same as AST_STRUCT! Because it includes a `type_list`!
		fputs("AST_GENERIC_STRUCT\n", out);
		goto print_struct_or_union;

	case AST_GENERIC_UNION:		//	NOT the same as AST_UNION! Because it includes a `type_list`!
		fputs("AST_GENERIC_UNION\n", out);
		goto print_struct_or_union;

	/*
	generic_specifier
		: GENERIC_NAME '<' generic_type_specifiers '>'
		;
	*/
	case AST_GENERIC_DECLARATION:
		fputs("AST_GENERIC_DECLARATION\n", out);

		indent(out, depth);
		fputs("|- .id\n", out);
		print_ast_tree(out, node->generic_type.id, depth + 1, node);

		indent(out, depth);
		fputs("|- .type_list\n", out);
		print_ast_tree(out, node->generic_type.type_list, depth + 1, node);
		break;


	case AST_GENERIC_IMPL:
		fputs("AST_GENERIC_IMPL\n", out);
		goto _print_impl_node;

	case AST_GENERIC_STATIC_IMPL:
		fputs("AST_GENERIC_STATIC_IMPL\n", out);
		goto _print_impl_node;


	case AST_GENERIC_LIST:
		fputs("AST_GENERIC_LIST\n", out);
		goto print_list_node;


	// case AST_GENERIC:
	// 	fputs("AST_GENERIC\n", out);

	// 	indent(out, depth);
	// 	fputs("|- .id\n", out);
	// 	print_ast_tree(out, node->generic.id, depth + 1, node);

	// 	indent(out, depth);
	// 	fputs("|- .parameter_list\n", out);
	// 	print_ast_tree(out, node->generic.parameter_list, depth + 1, node);
	// 	break;



	//	-----------------------------------------------------------------------

	case AST__NO_OP__:
		fputs("AST__NO_OP__", out);
		break;

	//	-----------------------------------------------------------------------
	//	AST_ERROR node

	case AST_ERROR:
		fputs("AST_ERROR\n", out);
		break;

	//	-----------------------------------------------------------------------

	case AST_NUMERIC:
		fprintf(out, "AST_NUMERIC: `%s`\n", node->numeric.num_str);
		break;

	case AST_ID:
		fprintf(out, "AST_ID: `%s`\n", node->id.id);
		break;

	case AST_STRING:
		fprintf(out, "AST_STRING: %s\n", node->str.str);
		break;

	case AST_DUMMY:
		fputs("AST_DUMMY node\n", out);
		break;

	default:
		fprintf(out, "Unknown node type: %d\n", node->type);
		break;
	}
}
