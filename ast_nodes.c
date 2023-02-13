#include "ast_nodes.h"

//	Single digit node
struct ast_digit_node digit_node[] = {
	{ AST_NUMERIC, { '0', '\0' } },
	{ AST_NUMERIC, { '1', '\0' } },
	{ AST_NUMERIC, { '2', '\0' } },
	{ AST_NUMERIC, { '3', '\0' } },
	{ AST_NUMERIC, { '4', '\0' } },
	{ AST_NUMERIC, { '5', '\0' } },
	{ AST_NUMERIC, { '6', '\0' } },
	{ AST_NUMERIC, { '7', '\0' } },
	{ AST_NUMERIC, { '8', '\0' } },
	{ AST_NUMERIC, { '9', '\0' } },
};

struct ast_digit_node real_node[] = {
	{ AST_NUMERIC, { '0', '.', '0', '\0' } },
	{ AST_NUMERIC, { '0', '.', '1', '\0' } },
	{ AST_NUMERIC, { '0', '.', '2', '\0' } },
	{ AST_NUMERIC, { '0', '.', '3', '\0' } },
	{ AST_NUMERIC, { '0', '.', '4', '\0' } },
	{ AST_NUMERIC, { '0', '.', '5', '\0' } },
	{ AST_NUMERIC, { '0', '.', '6', '\0' } },
	{ AST_NUMERIC, { '0', '.', '7', '\0' } },
	{ AST_NUMERIC, { '0', '.', '8', '\0' } },
	{ AST_NUMERIC, { '0', '.', '9', '\0' } },
	{ AST_NUMERIC, { '1', '.', '0', '\0' } },
	{ AST_NUMERIC, { '1', '.', '1', '\0' } },
	{ AST_NUMERIC, { '1', '.', '2', '\0' } },
	{ AST_NUMERIC, { '1', '.', '3', '\0' } },
	{ AST_NUMERIC, { '1', '.', '4', '\0' } },
	{ AST_NUMERIC, { '1', '.', '5', '\0' } },
	{ AST_NUMERIC, { '1', '.', '6', '\0' } },
	{ AST_NUMERIC, { '1', '.', '7', '\0' } },
	{ AST_NUMERIC, { '1', '.', '8', '\0' } },
	{ AST_NUMERIC, { '1', '.', '9', '\0' } },
	{ AST_NUMERIC, { '2', '.', '0', '\0' } },
	{ AST_NUMERIC, { '2', '.', '1', '\0' } },
	{ AST_NUMERIC, { '2', '.', '2', '\0' } },
	{ AST_NUMERIC, { '2', '.', '3', '\0' } },
	{ AST_NUMERIC, { '2', '.', '4', '\0' } },
	{ AST_NUMERIC, { '2', '.', '5', '\0' } },
	{ AST_NUMERIC, { '2', '.', '6', '\0' } },
	{ AST_NUMERIC, { '2', '.', '7', '\0' } },
	{ AST_NUMERIC, { '2', '.', '8', '\0' } },
	{ AST_NUMERIC, { '2', '.', '9', '\0' } },
	{ AST_NUMERIC, { '3', '.', '0', '\0' } },
	{ AST_NUMERIC, { '3', '.', '1', '\0' } },
	{ AST_NUMERIC, { '3', '.', '2', '\0' } },
	{ AST_NUMERIC, { '3', '.', '3', '\0' } },
	{ AST_NUMERIC, { '3', '.', '4', '\0' } },
	{ AST_NUMERIC, { '3', '.', '5', '\0' } },
	{ AST_NUMERIC, { '3', '.', '6', '\0' } },
	{ AST_NUMERIC, { '3', '.', '7', '\0' } },
	{ AST_NUMERIC, { '3', '.', '8', '\0' } },
	{ AST_NUMERIC, { '3', '.', '9', '\0' } },
	{ AST_NUMERIC, { '4', '.', '0', '\0' } },
	{ AST_NUMERIC, { '4', '.', '1', '\0' } },
	{ AST_NUMERIC, { '4', '.', '2', '\0' } },
	{ AST_NUMERIC, { '4', '.', '3', '\0' } },
	{ AST_NUMERIC, { '4', '.', '4', '\0' } },
	{ AST_NUMERIC, { '4', '.', '5', '\0' } },
	{ AST_NUMERIC, { '4', '.', '6', '\0' } },
	{ AST_NUMERIC, { '4', '.', '7', '\0' } },
	{ AST_NUMERIC, { '4', '.', '8', '\0' } },
	{ AST_NUMERIC, { '4', '.', '9', '\0' } },
	{ AST_NUMERIC, { '5', '.', '0', '\0' } },
	{ AST_NUMERIC, { '5', '.', '1', '\0' } },
	{ AST_NUMERIC, { '5', '.', '2', '\0' } },
	{ AST_NUMERIC, { '5', '.', '3', '\0' } },
	{ AST_NUMERIC, { '5', '.', '4', '\0' } },
	{ AST_NUMERIC, { '5', '.', '5', '\0' } },
	{ AST_NUMERIC, { '5', '.', '6', '\0' } },
	{ AST_NUMERIC, { '5', '.', '7', '\0' } },
	{ AST_NUMERIC, { '5', '.', '8', '\0' } },
	{ AST_NUMERIC, { '5', '.', '9', '\0' } },
	{ AST_NUMERIC, { '6', '.', '0', '\0' } },
	{ AST_NUMERIC, { '6', '.', '1', '\0' } },
	{ AST_NUMERIC, { '6', '.', '2', '\0' } },
	{ AST_NUMERIC, { '6', '.', '3', '\0' } },
	{ AST_NUMERIC, { '6', '.', '4', '\0' } },
	{ AST_NUMERIC, { '6', '.', '5', '\0' } },
	{ AST_NUMERIC, { '6', '.', '6', '\0' } },
	{ AST_NUMERIC, { '6', '.', '7', '\0' } },
	{ AST_NUMERIC, { '6', '.', '8', '\0' } },
	{ AST_NUMERIC, { '6', '.', '9', '\0' } },
	{ AST_NUMERIC, { '7', '.', '0', '\0' } },
	{ AST_NUMERIC, { '7', '.', '1', '\0' } },
	{ AST_NUMERIC, { '7', '.', '2', '\0' } },
	{ AST_NUMERIC, { '7', '.', '3', '\0' } },
	{ AST_NUMERIC, { '7', '.', '4', '\0' } },
	{ AST_NUMERIC, { '7', '.', '5', '\0' } },
	{ AST_NUMERIC, { '7', '.', '6', '\0' } },
	{ AST_NUMERIC, { '7', '.', '7', '\0' } },
	{ AST_NUMERIC, { '7', '.', '8', '\0' } },
	{ AST_NUMERIC, { '7', '.', '9', '\0' } },
	{ AST_NUMERIC, { '8', '.', '0', '\0' } },
	{ AST_NUMERIC, { '8', '.', '1', '\0' } },
	{ AST_NUMERIC, { '8', '.', '2', '\0' } },
	{ AST_NUMERIC, { '8', '.', '3', '\0' } },
	{ AST_NUMERIC, { '8', '.', '4', '\0' } },
	{ AST_NUMERIC, { '8', '.', '5', '\0' } },
	{ AST_NUMERIC, { '8', '.', '6', '\0' } },
	{ AST_NUMERIC, { '8', '.', '7', '\0' } },
	{ AST_NUMERIC, { '8', '.', '8', '\0' } },
	{ AST_NUMERIC, { '8', '.', '9', '\0' } },
	{ AST_NUMERIC, { '9', '.', '0', '\0' } },
	{ AST_NUMERIC, { '9', '.', '1', '\0' } },
	{ AST_NUMERIC, { '9', '.', '2', '\0' } },
	{ AST_NUMERIC, { '9', '.', '3', '\0' } },
	{ AST_NUMERIC, { '9', '.', '4', '\0' } },
	{ AST_NUMERIC, { '9', '.', '5', '\0' } },
	{ AST_NUMERIC, { '9', '.', '6', '\0' } },
	{ AST_NUMERIC, { '9', '.', '7', '\0' } },
	{ AST_NUMERIC, { '9', '.', '8', '\0' } },
	{ AST_NUMERIC, { '9', '.', '9', '\0' } },
};

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
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME		// after it has been defined as such
	;
*/
struct ast_type_node void_node = { AST_VOID };
struct ast_type_node char_node = { AST_CHAR };
struct ast_type_node short_node = { AST_SHORT };
struct ast_type_node int_node = { AST_INT };
struct ast_type_node long_node = { AST_LONG };
struct ast_type_node float_node = { AST_FLOAT };
struct ast_type_node double_node = { AST_DOUBLE };
struct ast_type_node signed_node = { AST_SIGNED };
struct ast_type_node unsigned_node = { AST_UNSIGNED };
struct ast_type_node bool_node = { AST_BOOL };			//	alias for _Bool
struct ast_type_node complex_node = { AST_COMPLEX };
struct ast_type_node imaginary_node = { AST_IMAGINARY };

/* GCC __builtin_va_list extension */
struct ast_type_node builtin_va_list_node = { AST__BUILTIN_VA_LIST };

/* GCC _Decimal32 extension */
struct ast_type_node ___decimal32_node = { AST__DECIMAL32 };
/* GCC _Decimal64 extension */
struct ast_type_node ___decimal64_node = { AST__DECIMAL64 };
/* GCC _Decimal128 extension */
struct ast_type_node ___decimal128_node = { AST__DECIMAL128 };

/* GCC _Float128 extension */
struct ast_type_node ___float128_node = { AST__FLOAT128 };
/* GCC __int128 extension */
struct ast_type_node ___int128_node = { AST__INT128 };
/* GCC __int128_t extension */
struct ast_type_node ___int128_t_node = { AST__INT128_T };
/* GCC __uint128_t extension */
struct ast_type_node ___uint128_t_node = { AST__UINT128_T };
/* C23 _BitInt(123) */
struct ast_bitint_node ___bitint128_node = { AST__BITINT, 128 };




struct ast_int_node true_node = { AST_NUMERIC, 1 };
struct ast_int_node false_node = { AST_NUMERIC, 0 };

// struct ast_null_node null_node = { AST_NULL, { 'n', 'u', 'l', 'l', '\0' } };	//	Super C specific `NULL` type ... we need to replace this with `((void*)0)`
// struct ast_null_node null1_node = { AST_NULL, { 'N', 'U', 'L', 'L', '\0' } };	//	Common `NULL` type
// struct ast_null_node null3_node = { AST_NULL, { '(', 'v', 'o', 'i', 'd', '*', ')', '0', '\0' } };		//	#define NULL (void*)0
// struct ast_null_node null3_node = { AST_NULL, { '(', 'v', 'o', 'i', 'd', ' ', '*', ')', '0', '\0' } };	//	#define NULL (void *)0


/*
	struct ast_expression_group_node* node = (struct ast_expression_group_node*) malloc(sizeof(struct ast_expression_group_node));
	node->type = AST_EXPRESSION_GROUP;
	node->expr = expr;

	return (union ast_node*) node;
*/
//struct ast_int_node _null_node = { AST_NUMERIC, 0 };	//	In future, we should replace this with a node representing `((void*)0)`

// Construct a null node from an ast_expression_group_node and a void pointer with value 0
// Construct a void* node
//struct ast_pointer_node _void_pointer_node = { AST_POINTER, { AST_VOID } };

struct ast_pointer_node pointer_node = {
	.type = AST_POINTER,
	.type_qualifier_list = (union ast_node*) 0,
	.pointer = (union ast_node*) 0,
};
struct ast_list_node _void_ptr_list_node = {
	.type = AST_LIST,
	.node = (union ast_node*) & void_node,
	.next = (union ast_node*) & pointer_node,
	.separator = ""
};
struct ast_expression_group_node _void_ptr_node = {
	AST_EXPRESSION_GROUP,
	(union ast_node*) & _void_ptr_list_node,
};
struct ast_list_node _null_list_node = {
	.type = AST_LIST,
	.node = (union ast_node*) & _void_ptr_node,
	.next = (union ast_node*) & digit_node[0],
	.separator = ""
};
struct ast_expression_group_node null_node = {
	.type = AST_EXPRESSION_GROUP,
	.expr = (union ast_node*) & _null_list_node
};







/*
class_modifier
	: PUBLIC
	| ABSTRACT
	| FINAL
	| OPAQUE
	| VIRTUAL
	| TYPE
	| STATIC
	| EXTERN
	;
*/
struct ast_type_node public_node = { AST_PUBLIC };
struct ast_type_node abstract_node = { AST_ABSTRACT };
struct ast_type_node final_node = { AST_FINAL };
struct ast_type_node opaque_node = { AST_OPAQUE };
struct ast_type_node virtual_node = { AST_VIRTUAL };
struct ast_type_node type_node = { AST_TYPE };
// struct ast_type_node _static_node = { AST_STATIC };		//	Already defined in `storage_class_specifier`
// struct ast_type_node _extern_node = { AST_EXTERN };







/*
type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	| ATOMIC
	;
*/
struct ast_type_node const_node = { AST_CONST };
struct ast_type_node restrict_node = { AST_RESTRICT };
struct ast_type_node volatile_node = { AST_VOLATILE };
struct ast_type_node atomic_node = { AST_ATOMIC };

struct ast_type_node ___restrict_node = { AST__RESTRICT };

/*
function_specifier
	: INLINE
	| NORETURN
	;
*/
struct ast_type_node inline_node = { AST_INLINE };
struct ast_type_node noreturn_node = { AST_NORETURN };

struct ast_type_node ___inline_node = { AST__INLINE };		// GCC __inline
struct ast_type_node ___inline__node = { AST__INLINE__ };	// GCC __inline__


/*
jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
*/
// extern struct ast_type_node goto_node;	//	Use create_goto_node() instead!
struct ast_type_node continue_node = { AST_CONTINUE };
struct ast_type_node break_node = { AST_BREAK };
struct ast_return_node return_node = { AST_RETURN, (void *) 0 };	//	This is for a `return` statement without an expression! Use create_return_node() for a `return` statement with an expression!



/*
expression_statement
	: ';'
	| expression ';'
	;
*/
struct ast_expression_statement_node expression_statement_node = { AST_EXPRESSION_STATEMENT, (void *) 0 };	//	This is for an `expression` statement, but without an expression! Use create_expression_node() for an `expression` statement with an expression! eg. Just `;` by itself!



/*
storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| THREAD_LOCAL
	| AUTO
	| REGISTER
	;
*/
struct ast_type_node typedef_node = { AST_TYPEDEF };
struct ast_type_node extern_node = { AST_EXTERN };
struct ast_type_node static_node = { AST_STATIC };
struct ast_type_node thread_local_node = { AST_THREAD_LOCAL };
struct ast_type_node auto_node = { AST_AUTO };
struct ast_type_node register_node = { AST_REGISTER };

/* GCC "__extension__" */
struct ast_type_node ___extension___node = { AST__EXTENSION__ };


/*
struct_or_union
	: STRUCT
	| UNION
	;
*/
struct ast_type_node struct_node = { AST_STRUCT };
struct ast_type_node union_node = { AST_UNION };

/*
enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	;
*/
//	Use create_enum_node() to create an enum node!
//	We don't have a hard-coded node! Because we don't need it! "ENUM" is defined only here, so we don't need a `temporary` node!
//struct ast_type_node enum_node = { AST_ENUM };


/* ELLIPSIS token == "..." */
struct ast_type_node ellipsis_node = { AST_ELLIPSIS };




/*
string
	: STRING_LITERAL
	| FUNC_NAME
	;
*/
struct ast_type_node ___func__node = { AST__FUNC__ };	//	represents: __func__






//struct ast_type_node not_node = { AST_NOT };


//	----------------------------------------------------------------------------------------------------------------
//	AST_ERROR node

struct ast_type_node error_node = { AST_ERROR };


//	----------------------------------------------------------------------------------------------------------------
//	----------------------------------------------------------------------------------------------------------------

struct ast_id_node lcase_node[] = {
	{ AST_ID, 0, "a" },
	{ AST_ID, 0, "b" },
	{ AST_ID, 0, "c" },
	{ AST_ID, 0, "d" },
	{ AST_ID, 0, "e" },
	{ AST_ID, 0, "f" },
	{ AST_ID, 0, "g" },
	{ AST_ID, 0, "h" },
	{ AST_ID, 0, "i" },
	{ AST_ID, 0, "j" },
	{ AST_ID, 0, "k" },
	{ AST_ID, 0, "l" },
	{ AST_ID, 0, "m" },
	{ AST_ID, 0, "n" },
	{ AST_ID, 0, "o" },
	{ AST_ID, 0, "p" },
	{ AST_ID, 0, "q" },
	{ AST_ID, 0, "r" },
	{ AST_ID, 0, "s" },
	{ AST_ID, 0, "t" },
	{ AST_ID, 0, "u" },
	{ AST_ID, 0, "v" },
	{ AST_ID, 0, "w" },
	{ AST_ID, 0, "x" },
	{ AST_ID, 0, "y" },
	{ AST_ID, 0, "z" },
};

struct ast_id_node main_node     = { AST_ID, 0, "main" };

struct ast_id_node strlen_node   = { AST_ID, 0, "strlen" };

struct ast_id_node printf_node   = { AST_ID, 0, "printf" };
struct ast_id_node fprintf_node  = { AST_ID, 0, "fprintf" };
struct ast_id_node sprintf_node  = { AST_ID, 0, "sprintf" };
struct ast_id_node snprintf_node = { AST_ID, 0, "snprintf" };

struct ast_id_node exit_node     = { AST_ID, 0, "exit" };
struct ast_id_node assert_node   = { AST_ID, 0, "assert" };
struct ast_id_node static_assert_node = { AST_ID, 0, "static_assert" };

struct ast_id_node malloc_node   = { AST_ID, 0, "malloc" };
struct ast_id_node calloc_node   = { AST_ID, 0, "calloc" };
struct ast_id_node realloc_node  = { AST_ID, 0, "realloc" };
struct ast_id_node free_node     = { AST_ID, 0, "free" };
struct ast_id_node alloca_node   = { AST_ID, 0, "alloca" };

struct ast_id_node memmove_node  = { AST_ID, 0, "memmove" };
struct ast_id_node memcpy_node   = { AST_ID, 0, "memcpy" };
struct ast_id_node memset_node   = { AST_ID, 0, "memset" };

struct ast_id_node size_t_node   = { AST_ID, 0, "size_t" };

struct ast_type_node this_node = { AST_THIS };
struct ast_type_node self_node = { AST_SELF };

//	----------------------------------------------------------------------------------------------------------------
//	----------------------------------------------------------------------------------------------------------------
//								NEW `reserved keywords` that are also IDENTIFIER's!
//	When we detect one of these keywords used as variable or function names; then we fallback to the IDENTIFIER.

struct ast_id_node new_as_id_node = { AST_ID, 0, "new" };
struct ast_id_node delete_as_id_node = { AST_ID, 0, "delete" };

struct ast_id_node get_as_id_node = { AST_ID, 0, "get" };
struct ast_id_node set_as_id_node = { AST_ID, 0, "set" };
