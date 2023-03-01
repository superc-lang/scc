// #include <stdio.h>
// #include <stdlib.h>

#include "codegen.h"
#include "indent.h"

#include <assert.h>

void codegen(FILE *out, union ast_node *node, int depth, union ast_node *parent)
{
	if (node == NULL) return;

	switch (node->type) {

	case AST_PRAGMA:
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
		fputs("void", out);
		break;
	case AST_CHAR:
		fputs("char", out);
		break;
	case AST_SHORT:
		fputs("short", out);
		break;
	case AST_INT:
		fputs("int", out);
		break;
	case AST_LONG:
		fputs("long", out);
		break;
	case AST_FLOAT:
		fputs("float", out);
		break;
	case AST_DOUBLE:
		fputs("double", out);
		break;
	case AST_SIGNED:
		fputs("signed", out);
		break;
	case AST_UNSIGNED:
		fputs("unsigned", out);
		break;
	case AST_BOOL:
		fputs("_Bool", out);
		break;
	case AST_COMPLEX:
		fputs("_Complex", out);
		break;
	case AST_IMAGINARY:
		fputs("_Imaginary", out);
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

	case AST_ATOMIC:
		fputs("_Atomic", out);
		break;

	case AST_ATOMIC_TYPE:
		fputs("_Atomic (", out);
		codegen(out, node->atomic_type.type_name, depth, node);
		fputc(')', out);
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ... GCC Extensions

	case AST__BUILTIN_VA_LIST:
		fputs("__builtin_va_list", out);
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ... GCC _Decimal32, _Decimal64, _Decimal128 extensions

	case AST__DECIMAL32:
		fputs("_Decimal32", out);
		break;

	case AST__DECIMAL64:
		fputs("_Decimal64", out);
		break;

	case AST__DECIMAL128:
		fputs("_Decimal128", out);
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ... GCC _Float128 extension

	case AST__FLOAT128:
		fputs("_Float128", out);
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ... GCC __int128 extension

	case AST__INT128:
		fputs("__int128", out);		//	As of GCC 4.6 - Source: https://stackoverflow.com/a/54815033
		break;

	case AST__INT128_T:
		fputs("__int128_t", out);	//	As of GCC 4.1 - Source: https://stackoverflow.com/a/54815033
		break;

	case AST__UINT128_T:
		fputs("__uint128_t", out);	//	As of GCC 4.1 - Source: https://stackoverflow.com/a/54815033
		break;

	//	NOTE: I don't think I should support a dedicated _BitInt(128)! Just use the AST__BITINT type with 128! That is what the static node uses when it detects `_BitInt(123)`
	// case AST__BITINT128:		//	Clang `_BitInt(128)` support (https://clang.llvm.org/docs/LanguageExtensions.html#bitint)  &&  https://clang.llvm.org/docs/LanguageExtensions.html#extended-integer-types
	// 	fprintf(out, "_BitInt(128)");	//	Note: Clang originally had `_ExtInt(N)` which has been deprecated in favor of the C23 standard `_BitInt(N)`
	// 	break;

	//	C23 _BitInt(N)
	case AST__BITINT:
		fprintf(out, "_BitInt(%d)", node->bitint.n);
		break;

	//	-----------------------------------------------------------------------
	//	GCC __attribute__ extension

	case AST__ATTRIBUTE__:
		fputs(node->attribute.src_code, out);
		// fprintf(out, "%s", node->attribute.src_code);
		//codegen(out, node->attribute.src_code, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	GCC __asm__ extension

	case AST__ASM__:
		fputs(node->str.str, out);
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
		fputs("\ntypedef", out);
		break;
	case AST_EXTERN:
		fputs("extern", out);
		break;
	case AST_STATIC:
		fputs("static", out);
		break;
	case AST_THREAD_LOCAL:
		fputs("_Thread_local", out);
		break;
	case AST_AUTO:
		fputs("auto", out);
		break;
	case AST_REGISTER:
		fputs("register", out);
		break;


	/* GCC "__extension__" */
	case AST__EXTENSION__:
		fputs("__extension__", out);
		break;


	/*
	struct_or_union_specifier
		: struct_or_union '{' struct_declaration_list '}'
		| struct_or_union IDENTIFIER '{' struct_declaration_list '}'
		| struct_or_union IDENTIFIER
		;

	struct_or_union
		: STRUCT
		| UNION
		;
	*/

	case AST_STRUCT:
		///indent(out, depth);
		if (node->struct_or_union.id)
			fprintf(out, "struct %s ", node->struct_or_union.id->id.id);
		else
			fputs("struct ", out);
		goto struct_or_union;

	case AST_UNION:
		//indent(out, depth);
		if (node->struct_or_union.id)
			fprintf(out, "union %s ", node->struct_or_union.id->id.id);
		else
			fputs("union ", out);
		goto struct_or_union;

	struct_or_union:
		if (node->struct_or_union.decl_list) {
			fputs("{\n", out);
			codegen(out, node->struct_or_union.decl_list, depth + 1, node);
			indent(out, depth);
			fputs("}", out);
		}
		break;

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
		indent(out, depth);
		codegen(out, node->struct_or_union_declaration.spec_qual_list, depth, node);
		if (node->struct_or_union_declaration.decl_list) {
			fputc(' ', out);
			codegen(out, node->struct_or_union_declaration.decl_list, depth, node);
		}
		fputs(";\n", out);
		break;

	case AST_STRUCT_OR_UNION_DECLARATOR:
		codegen(out, node->struct_or_union_declarator.declarator, depth, node);
		if (node->struct_or_union_declarator.expr) {
			fputs(": ", out);
			codegen(out, node->struct_or_union_declarator.expr, depth, node);
		}
		break;


	case AST_ENUM:
		indent(out, depth);
		if (node->enum_type.id)
			fprintf(out, "enum %s ", node->enum_type.id->id.id);
		else
			fputs("enum ", out);

		if (node->enum_type.list) {
			fputs("{\n", out);
			codegen(out, node->enum_type.list, depth + 1, node);
			fputc('\n', out);
			indent(out, depth);
			fputc('}', out);
		}
		break;

	case AST_ENUM_INIT:
		indent(out, depth);
		if (node->binary.right == NULL) {
			fputs(node->binary.left->id.id, out);
		} else {
			fprintf(out, "%s = ", node->binary.left->id.id);
			codegen(out, node->binary.right, depth, node);
		}
		break;

	// case AST_ENUM_CONSTANT:
	// 	fprintf(out, "%s", node->id.id);
	// 	break;


	case AST_TYPEDEF_NAME:					/* same as AST_ID */
		fputs(node->id.id, out);
		break;

	//	-----------------------------------------------------------------------

	case AST_LIST:
		codegen(out, node->list.node, depth, node);
		fputs(node->list.separator, out);
		codegen(out, node->list.next, depth, node);
		break;

	//	-----------------------------------------------------------------------

	case AST_BLOCK:
		fputs("{\n", out);
		codegen(out, node->block.stmts, depth + 1, node);
		indent(out, depth);
		if ((parent->type == AST_IF && parent->if_stmt.if_false != NULL) || parent->type == AST_DO_WHILE) {
			fputc('}', out);
		} else {
			fputs("}\n", out);
		}
		break;

	//	-----------------------------------------------------------------------

	case AST_DECLARATION:
		if (parent != NULL && parent->type != AST_FOR) {
			indent(out, depth);
		}
		codegen(out, node->declaration.decl_specs, depth, node);
		if (node->declaration.init_declarator_list) {
			fputc(' ', out);
			codegen(out, node->declaration.init_declarator_list, depth, node);	//	struct test { int a; } t = { 1 }; ... this represents the "t" (if used without initialization!) and "t = { 1 }" part
		} else {	//	This might be a generic node: `typedef Vec3<float>;` ... which wouldn't have a init_declarator_list
			// fprintf(out, " ");
			// codegen(out, node->declaration.decl_specs, depth, node);
// 			char *func_name = get_generic_type_name(node->declaration.decl_specs);
// printf("AST_DECLARATION func name: %s\n", func_name);
			if (is_typeof_node(AST_GENERIC_DECLARATION, node->declaration.decl_specs)) {
				//printf("FOUND GENERIC SPECIFIER!\n");
			}
		}
		if (parent != NULL && parent->type == AST_FOR) {
			fputs("; ", out);
		} else {
			fputs(";\n", out);
		}
		break;

	case AST_POINTER_DECLARATOR:
		codegen(out, node->pointer_declarator.pointer, depth, node);
		codegen(out, node->pointer_declarator.direct_declarator, depth, node);
		break;

	case AST_POINTER:
		fputc('*', out);
		if (node->pointer.type_qualifier_list) {
			codegen(out, node->pointer.type_qualifier_list, depth, node);
			fputc(' ', out);	//	solved a problem where `char *__restrict __bar` -> `char *__restrict__bar` (missing space)
		}
		codegen(out, node->pointer.pointer, depth, node);
		break;


	case AST_FUNCTION_DEFINITION:
		// printf("AST_FUNCTION_DEFINITION: `%s`\n", tmp->id.id);
		fputc('\n', out);
		codegen(out, node->function_definition.decl_specs, depth, node);
		if (node->function_definition.decl_specs->type != AST_ABSTRACT_TYPE_NAME)
			fputc(' ', out);
		codegen(out, node->function_definition.declarator, depth, node);	// This will push the function name onto the global scope, but it also processes the function params, but we ignore for now! Unless there is a function body/block, then we process the params!
		if (node->function_definition.decl_list) {
			fputc('\n', out);
			codegen(out, node->function_definition.decl_list, depth, node);		//	eg. main(argc, argv) int argc, char *argv[] { ... }
		}
		if (node->function_definition.block == NULL) {
			fputs(";\n", out);
		} else {
			fputc('\n', out);
			codegen(out, node->function_definition.block, depth, node);
		}
		break;


	case AST_PARAMETER_DECLARATION:
		codegen(out, node->parameter_declaration.decl_specs, depth, node);
		if (node->parameter_declaration.decl_specs->type != AST_ABSTRACT_TYPE_NAME)
			fputc(' ', out);
		codegen(out, node->parameter_declaration.declarator, depth, node);
		break;


	//	`declarator '=' initializer`
	case AST_INIT_DECLARATOR:
		codegen(out, node->init_declarator.declarator, depth, node);
		fputs(" = ", out);
		codegen(out, node->init_declarator.initializer, depth, node);
		break;


	//	-----------------------------------------------------------------------
	//	`type_name`
	//	-----------------------------------------------------------------------

	/*
	type_name
		: specifier_qualifier_list abstract_declarator
		| specifier_qualifier_list
		;
	*/

	case AST_ABSTRACT_TYPE_NAME:
		codegen(out, node->abstract_type_name.specifier_qualifier_list, depth, node);
		fputc(' ', out);
		codegen(out, node->abstract_type_name.abstract_declarator, depth, node);
		break;

	/*
	abstract_declarator
		: pointer direct_abstract_declarator
		| pointer
		| direct_abstract_declarator
		;
	*/

	case AST_ABSTRACT_DECLARATOR:
		codegen(out, node->abstract_declarator.pointer, depth, node);
		codegen(out, node->abstract_declarator.direct_abstract_declarator, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	ELLIPSIS token == "..."
	//	-----------------------------------------------------------------------

	case AST_ELLIPSIS:
		fputs("...", out);
		break;

	//	-----------------------------------------------------------------------
	//	`direct_declarator`
	//	-----------------------------------------------------------------------

	case AST_GROUPED_DECLARATOR:
		fputc('(', out);
		codegen(out, node->grouped_declarator.declarator, depth, node);
		fputc(')', out);
		break;

	case AST_UNSPECIFIED_ARRAY:
		codegen(out, node->unspecified_array.direct_declarator, depth, node);
		fputc('[', out);
		codegen(out, node->unspecified_array.type_qualifier_list, depth, node);
		fputc(']', out);
		break;

	case AST_DYNAMIC_ARRAY:
		codegen(out, node->dynamic_array.direct_declarator, depth, node);
		fputc('[', out);
		codegen(out, node->dynamic_array.type_qualifier_list, depth, node);
		fputs(" * ]", out);
		break;

	case AST_STATIC_ARRAY:
		codegen(out, node->array.direct_declarator, depth, node);
		fputs("[ static ", out);
		if (node->array.type_qualifier_list) {
			codegen(out, node->array.type_qualifier_list, depth, node);
			fputc(' ', out);
		}
		codegen(out, node->array.expr, depth, node);
		fputc(']', out);
		break;

	case AST_ARRAY:
		codegen(out, node->array.direct_declarator, depth, node);
		fputc('[', out);
		if (node->array.type_qualifier_list) {
			codegen(out, node->array.type_qualifier_list, depth, node);
			fputc(' ', out);
		}
		codegen(out, node->array.expr, depth, node);
		fputc(']', out);
		break;

	case AST_FUNCTION_DECLARATOR:
		codegen(out, node->function_declarator.direct_declarator, depth, node);
		fputc('(', out);
		codegen(out, node->function_declarator.params, depth, node);
		codegen(out, node->function_declarator.identifier_list, depth, node);	//	eg. int main(argc, argv) ... `identifier_list` == argc, argv ... deprecated! "This is called "old-style function definition" and it is considered as a deprecated feature in C89 and later versions of the C standard, because it can lead to confusion and errors. It is recommended to always use function prototyping to define functions in C."
		fputc(')', out);
		break;

	//	-----------------------------------------------------------------------


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
		fputs("const", out);
		break;
	case AST_RESTRICT:
		fputs("restrict", out);
		break;
	case AST_VOLATILE:
		fputs("volatile", out);
		break;
	// case AST_ATOMIC:
	// 	fputs("atomic", out);
	// 	break;

	/* GCC */
	case AST__RESTRICT:
		fputs("__restrict", out);
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
		fputs("inline", out);
		break;
	case AST_NORETURN:
		fputs("_Noreturn", out);
		break;

	//	-----------------------------------------------------------------------
	//	GCC __inline && __inline__ extensions
	//	-----------------------------------------------------------------------

	case AST__INLINE:
		fputs("__inline", out);
		break;
	case AST__INLINE__:
		fputs("__inline__", out);
		break;

	//	-----------------------------------------------------------------------
	//	`assignment_expression`
	//	-----------------------------------------------------------------------

	case AST_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" = ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_ADD_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" += ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_SUB_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" -= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_MUL_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" *= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_DIV_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" /= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_MOD_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" %%= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_AND_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" &= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_XOR_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" ^= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_OR_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" |= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_SHL_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" <<= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_SHR_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" >>= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`conditional_expression`
	//	-----------------------------------------------------------------------

	case AST_TERNARY:
		codegen(out, node->ternary.cond, depth, node);
		fputs(" ? ", out);
		codegen(out, node->ternary.true_expr, depth, node);
		fputs(" : ", out);
		codegen(out, node->ternary.false_expr, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`logical_or_expression`
	//	-----------------------------------------------------------------------

	case AST_OR:
		codegen(out, node->binary.left, depth, node);
		fputs(" || ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`logical_and_expression`
	//	-----------------------------------------------------------------------

	case AST_AND:
		codegen(out, node->binary.left, depth, node);
		fputs(" && ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`inclusive_or_expression`
	//	-----------------------------------------------------------------------

	case AST_BIT_OR:
		codegen(out, node->binary.left, depth, node);
		fputs(" | ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`exclusive_or_expression`
	//	-----------------------------------------------------------------------

	case AST_BIT_XOR:
		codegen(out, node->binary.left, depth, node);
		fputs(" ^ ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`and_expression`
	//	-----------------------------------------------------------------------

	case AST_BIT_AND:
		codegen(out, node->binary.left, depth, node);
		fputs(" & ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`equality_expression`
	//	-----------------------------------------------------------------------

	case AST_EQ:
		codegen(out, node->binary.left, depth, node);
		fputs(" == ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_NE:
		codegen(out, node->binary.left, depth, node);
		fputs(" != ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`relational_expression`
	//	-----------------------------------------------------------------------

	case AST_LT:
		codegen(out, node->binary.left, depth, node);
		fputs(" < ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_GT:
		codegen(out, node->binary.left, depth, node);
		fputs(" > ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_LE:
		codegen(out, node->binary.left, depth, node);
		fputs(" <= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_GE:
		codegen(out, node->binary.left, depth, node);
		fputs(" >= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`shift_expression`
	//	-----------------------------------------------------------------------

	case AST_SHL:
		codegen(out, node->binary.left, depth, node);
		fputs(" >> ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_SHR:
		codegen(out, node->binary.left, depth, node);
		fputs(" << ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`additive_expression`
	//	-----------------------------------------------------------------------

	case AST_ADD:
		codegen(out, node->binary.left, depth, node);
		fputs(" + ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_SUB:
		codegen(out, node->binary.left, depth, node);
		fputs(" - ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`multiplicative_expression`
	//	-----------------------------------------------------------------------

	case AST_MUL:
		codegen(out, node->binary.left, depth, node);
		fputs(" * ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_DIV:
		codegen(out, node->binary.left, depth, node);
		fputs(" / ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_MOD:
		codegen(out, node->binary.left, depth, node);
		fputs(" %% ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`cast_expression`
	//	-----------------------------------------------------------------------

	case AST_CAST:
		fputc('(', out);
		codegen(out, node->cast.type_name, depth, node);
		fputs(") ", out);
		codegen(out, node->cast.expr, depth, node);
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
		;
	*/

	case AST_PRE_INC:
		fputs("++", out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_PRE_DEC:
		fputs("--", out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_SIZEOF_EXPR:
		fputs("sizeof ", out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_SIZEOF_TYPE:
		fputs("sizeof(", out);
		codegen(out, node->unary.expr, depth, node);
		fputc(')', out);
		break;

	case AST_ALIGNOF:
		fputs("_Alignof(", out);
		codegen(out, node->unary.expr, depth, node);
		fputc(')', out);
		break;


	//	-----------------------------------------------------------------------
	//	`unary_operator`
	//	-----------------------------------------------------------------------

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
		fputc('&', out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_DEREFERENCE:
		fputc('*', out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_POSITIVE:
		fputc('+', out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_NEGATIVE:
		fputc('-', out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_BITWISE_NOT:
		fputc('~', out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_LOGICAL_NOT:
		fputc('!', out);
		codegen(out, node->unary.expr, depth, node);
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
		codegen(out, node->array_subscript.array, depth, node);
		fputc('[', out);
		codegen(out, node->array_subscript.index, depth, node);
		fputc(']', out);
		break;

	case AST_FUNCTION_CALL:
		codegen(out, node->function_call.function, depth, node);
		fputc('(', out);
		codegen(out, node->function_call.args, depth, node);
		fputc(')', out);
		break;

	case AST_MEMBER_ACCESS:
		codegen(out, node->member_access.object, depth, node);
		fputc('.', out);
		codegen(out, node->member_access.member, depth, node);
		break;

	case AST_MEMBER_ACCESS_POINTER:
		codegen(out, node->member_access.object, depth, node);
		fputs("->", out);
		codegen(out, node->member_access.member, depth, node);
		break;

	case AST_POST_INC:
		codegen(out, node->unary.expr, depth, node);
		fputs("++", out);
		break;

	case AST_POST_DEC:
		codegen(out, node->unary.expr, depth, node);
		fputs("--", out);
		break;

	case AST_COMPOUND_LITERAL:
		fputc('(', out);
		codegen(out, node->compound_literal.type_name, depth, node);
		fputs(") {", out);
		codegen(out, node->compound_literal.init_list, depth, node);
		fputc('}', out);
		break;

	//	-----------------------------------------------------------------------
	//	`primary_expression`
	//	-----------------------------------------------------------------------

	/*
	primary_expression
		: IDENTIFIER
		| constant
		| string
		| '(' expression ')'
		| generic_selection
		;
	*/

	case AST_ID:
		fputs(node->id.id, out);
		break;

	//	----------------------------------------------
	//	`constant`
	//	----------------------------------------------

	case AST_NUMERIC:
		fputs(node->numeric.num_str, out);
		break;

	case AST_ENUMERATION_CONSTANT:
		fputs(node->id.id, out);
		break;

	//	----------------------------------------------
	//	`string`
	//	----------------------------------------------

	case AST_STRING:
		fputs(node->str.str, out);
		break;

	case AST__FUNC__:
		fputs("__func__", out);
		break;

	//	----------------------------------------------
	//	"expression group"

	case AST_EXPRESSION_GROUP:
		fputc('(', out);
		codegen(out, node->unary.expr, depth, node);
		fputc(')', out);
		break;


	//	----------------------------------------------
	//	`generic_selection`
	//	----------------------------------------------

	//	generic_selection
	// AST_GENERIC_SELECTION,
	// AST_GENERIC_ASSOC_LIST,
	// AST_GENERIC_ASSOC,

	//	-----------------------------------------------------------------------


	//	-----------------------------------------------------------------------
	//	`initializer`
	//	-----------------------------------------------------------------------

	/*
	initializer
		: '{' initializer_list '}'
		| '{' initializer_list ',' '}'
		| assignment_expression
		;
	*/

	case AST_INITIALIZER:
		fputc('{', out);
		codegen(out, node->initializer.list, depth, node);
		fputc('}', out);
		break;


	//	-----------------------------------------------------------------------
	//	`initializer_list` && `designation`
	//	-----------------------------------------------------------------------

	/*
	initializer_list
		: designation initializer
		| initializer
		| initializer_list ',' designation initializer
		| initializer_list ',' initializer
		;

	designation
		: designator_list '='
		;
	*/

	case AST_DESIGNATION_INITIALIZER:
		codegen(out, node->designation_initializer.designation, depth, node);
		fputs(" = ", out);
		codegen(out, node->designation_initializer.initializer, depth, node);
		break;


	//	-----------------------------------------------------------------------
	//	`designator`
	//	-----------------------------------------------------------------------

	/*
	designator
		: '[' constant_expression ']'
		| '.' IDENTIFIER
		;
	*/

	case AST_DESIGNATOR:
		if (node->designator.id) {
			fputc('.', out);
			codegen(out, node->designator.id, depth, node);
		} else {
			fputc('[', out);
			codegen(out, node->designator.expr, depth, node);
			fputc(']', out);
		}
		break;


	//	-----------------------------------------------------------------------
	//	`labeled_statement`
	//	-----------------------------------------------------------------------

	case AST_LABEL:
		indent(out, depth);
		codegen(out, node->label.id, depth, node);
		fputs(":\n", out);
		codegen(out, node->label.stmt, depth + 1, node);
		break;

	case AST_CASE:
		indent(out, depth - 1);
		fputs("case ", out);
		codegen(out, node->case_stmt.expr, depth, node);
		fputs(":\n", out);
		codegen(out, node->case_stmt.stmt, depth, node);
		break;

	case AST_DEFAULT:
		indent(out, depth - 1);
		fputs("default:\n", out);
		codegen(out, node->default_stmt.stmt, depth, node);
		break;


	//	-----------------------------------------------------------------------
	//	`jump_statement`
	//	-----------------------------------------------------------------------

	case AST_GOTO:
		indent(out, depth);
		fputs("goto ", out);
		codegen(out, node->goto_stmt.id, depth, node);
		fputs(";\n", out);
		break;

	case AST_CONTINUE:
		indent(out, depth);
		fputs("continue;\n", out);
		break;

	case AST_BREAK:
		indent(out, depth);
		fputs("break;\n", out);
		break;

	case AST_RETURN:
		indent(out, depth);
		if (node->return_stmt.expr) {
			fputs("return ", out);
			codegen(out, node->return_stmt.expr, depth, node);
			fputs(";\n", out);
		} else {
			fputs("return;\n", out);
		}
		break;


	//	-----------------------------------------------------------------------
	//	`selection_statement`
	//	-----------------------------------------------------------------------

	/*
	selection_statement
		: IF '(' expression ')' statement ELSE statement
		| IF '(' expression ')' statement
		| SWITCH '(' expression ')' statement
		;
	*/

	case AST_IF:
		if (parent->type != AST_IF) {
			indent(out, depth);
		}
		fputs("if (", out);
		codegen(out, node->if_stmt.cond, depth, node);

		if (node->if_stmt.if_true) {
			if (node->if_stmt.if_true->type == AST_BLOCK) {
				fputs(") ", out);
				codegen(out, node->if_stmt.if_true, depth, node);
			} else {
				fputs(")\n", out);
				codegen(out, node->if_stmt.if_true, depth + 1, node);
			}
		}

		if (node->if_stmt.if_false) {
			if (node->if_stmt.if_false->type == AST_BLOCK || node->if_stmt.if_false->type == AST_IF) {
				fputs(" else ", out);
				codegen(out, node->if_stmt.if_false, depth, node);
			} else {
				indent(out, depth);
				fputs("else\n", out);
				codegen(out, node->if_stmt.if_false, depth + 1, node);
			}
			fputc('\n', out);
		}
		break;

	case AST_SWITCH:
		indent(out, depth);
		fputs("switch (", out);
		codegen(out, node->switch_stmt.expr, depth, node);
		fputs(") ", out);
		codegen(out, node->switch_stmt.stmt, depth, node);
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
		indent(out, depth);
		fputs("while (", out);
		codegen(out, node->while_stmt.cond, depth, node);
		fputs(") ", out);
		codegen(out, node->while_stmt.body, depth, node);
		break;

	case AST_DO_WHILE:
		indent(out, depth);
		fputs("do ", out);
		codegen(out, node->do_while_stmt.body, depth, node);
		fputs("while (", out);
		codegen(out, node->do_while_stmt.cond, depth, node);
		fputs(");\n", out);
		break;

	case AST_FOR:
		indent(out, depth);
		fputs("for (", out);
		if (node->for_stmt.init) {
			codegen(out, node->for_stmt.init, depth, node);
		}
		// fputs(" ", out);		//	added by `AST_EXPRESSION_STATEMENT`
		if (node->for_stmt.cond) {
			codegen(out, node->for_stmt.cond, depth, node);
		}
		// fputs(" ", out);		//	added by `AST_EXPRESSION_STATEMENT`
		if (node->for_stmt.incr) {
			codegen(out, node->for_stmt.incr, depth, node);
		}
		fputs(") ", out);
		codegen(out, node->for_stmt.body, depth, node);
		break;


	//	-----------------------------------------------------------------------
	//	`expression_statement`
	//	-----------------------------------------------------------------------

	case AST_EXPRESSION_STATEMENT:
		if (parent->type != AST_FOR) indent(out, depth);
		codegen(out, node->unary.expr, depth, node);
		fputs(parent->type == AST_FOR ? "; " : ";\n", out);
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
		fputs("_Static_assert(", out);
		goto _static_assert;

	case AST_STATIC_ASSERT:
		fputs("static_assert(", out);

	_static_assert:
		codegen(out, node->static_assert_stmt.expr, depth, node);
		if (node->static_assert_stmt.str) {
			fputs(", ", out);
			codegen(out, node->static_assert_stmt.str, depth, node);
		}
		fputs(");", out);
		break;


	//	-----------------------------------------------------------------------
	//			Super C extensions
	//	-----------------------------------------------------------------------

	case AST_THIS:
		fputs("this", out);
		break;

	case AST_SELF:
		fputs("self", out);
		break;

	case AST_IMPL:
	case AST_STATIC_IMPL:
	case AST_NS_OP:
	case AST_GENERIC_DECLARATION:
	case AST_GENERIC_STRUCT:
	case AST_GENERIC_UNION:
	case AST_GENERIC_LIST:
	case AST_GENERIC_IMPL:
	case AST_GENERIC_STATIC_IMPL:
	case AST_DELETE_OPERATOR:
	case AST_IMPL_NEW_FUNCTION:
	case AST_IMPL_NEW_DECLARATOR:
	case AST_IMPL_DELETE_FUNCTION:
	case AST_IMPL_FUNCTION_DECLARATION:		//	looks like this has been 'deprecated'?
	case AST_GETTER:
	case AST_SETTER:
	// case AST_BLANK_ID:	//	no longer used
		fprintf(stderr, "PARSER ERROR: `%s` node type (%d) detected! This should never happen!\n", get_node_name(node->type), node->type);
		exit(EXIT_FAILURE);
		break;

	//	-----------------------------------------------------------------------

	//	We might need a to add some checks for `AST__NO_OP__` nodes
	//	Because we often test for 'NULL' nodes, and output some code
	//	A `no-op` node would pass the test, but we don't want to output code for it!
	case AST__NO_OP__:
		assert(parent->type == AST_LIST);	//	I want to make sure we catch non-`AST_LIST` nodes, because it might affect other node types.
		//fputs("/* NOOP */", out);
		break;

	//	-----------------------------------------------------------------------

	case AST_DUMMY:
		fputs(" ( DUMMY NODE ) ", out);
		break;

	//	-----------------------------------------------------------------------

	default:
		fprintf(stderr, "PARSER ERROR: Unknown node type id: %d\n", node->type);
		exit(EXIT_FAILURE);
		break;
	}
}
