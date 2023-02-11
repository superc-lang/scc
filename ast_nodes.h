#pragma once

#include "ast.h"

extern struct ast_digit_node digit_node[];
extern struct ast_digit_node real_node[];

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
extern struct ast_type_node void_node;
extern struct ast_type_node char_node;
extern struct ast_type_node short_node;
extern struct ast_type_node int_node;
extern struct ast_type_node long_node;
extern struct ast_type_node float_node;
extern struct ast_type_node double_node;
extern struct ast_type_node signed_node;
extern struct ast_type_node unsigned_node;
extern struct ast_type_node bool_node;
extern struct ast_type_node complex_node;
extern struct ast_type_node imaginary_node;

/* GCC __builtin_va_list extension */
extern struct ast_type_node builtin_va_list_node;

/* GCC _Decimal32 extension */
extern struct ast_type_node ___decimal32_node;
/* GCC _Decimal64 extension */
extern struct ast_type_node ___decimal64_node;
/* GCC _Decimal128 extension */
extern struct ast_type_node ___decimal128_node;

/* GCC _Float128 extension */
extern struct ast_type_node ___float128_node;
/* GCC __int128 extension */
extern struct ast_type_node ___int128_node;
/* GCC __int128_t extension */
extern struct ast_type_node ___int128_t_node;
/* GCC __uint128_t extension */
extern struct ast_type_node ___uint128_t_node;
/* C23 _BitInt(128) */
extern struct ast_bitint_node ___bitint128_node;


extern struct ast_int_node true_node;
extern struct ast_int_node false_node;

extern struct ast_expression_group_node null_node;

extern struct ast_pointer_node pointer_node;


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
extern struct ast_type_node _public_node;
extern struct ast_type_node _abstract_node;
extern struct ast_type_node _final_node;
extern struct ast_type_node _opaque_node;
extern struct ast_type_node _virtual_node;
extern struct ast_type_node _type_node;
// extern struct ast_type_node _static_node;		//	Already defined in `storage_class_specifier`
// extern struct ast_type_node _extern_node;



/*
type_qualifier
	: CONST
	| RESTRICT
	| VOLATILE
	| ATOMIC
	;
*/
extern struct ast_type_node const_node;
extern struct ast_type_node restrict_node;
extern struct ast_type_node volatile_node;
extern struct ast_type_node atomic_node;

extern struct ast_type_node ___restrict_node;




/*
function_specifier
	: INLINE
	| NORETURN
	;
*/
extern struct ast_type_node inline_node;
extern struct ast_type_node noreturn_node;

extern struct ast_type_node ___inline_node;		// GCC __inline
extern struct ast_type_node ___inline__node;	// GCC __inline__

/* MSVC __forceinline / GCC __attribute__((always_inline)) */
//	NOTE: This needs to be more dynamic (GCC and MSVC use different nodes), so I can't use the common above method
//	The "common" method of defining this as a static union ast_node* and then casting it to a struct ast_type_node* is more efficient
//	Because this requires us to store the pointer value externally, whereas the common static method doesn't require the pointer to be stored externally!
extern struct ast_type_node ___forceinline_node;





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
extern struct ast_type_node typedef_node;
extern struct ast_type_node extern_node;
extern struct ast_type_node static_node;
extern struct ast_type_node thread_local_node;
extern struct ast_type_node auto_node;
extern struct ast_type_node register_node;

/* GCC "__extension__" */
extern struct ast_type_node ___extension___node;


/*
jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
*/
// extern struct ast_type_node goto_node;		//	Use create_goto_node(), because it has a random identifier!
extern struct ast_type_node continue_node;
extern struct ast_type_node break_node;
extern struct ast_return_node return_node;	//	NOTE: This is for a `return` statement without an expression! Use create_return_node() for a `return` statement with an expression!



/*
struct_or_union
	: STRUCT
	| UNION
	;
*/
extern struct ast_type_node struct_node;
extern struct ast_type_node union_node;



/*
expression_statement
	: ';'
	| expression ';'
	;
*/
extern struct ast_expression_statement_node expression_statement_node;	//	NOTE: This is for a `;` expression without an expression! Use create_expression_node() for a `;` statement with an expression!



/*
string
	: STRING_LITERAL
	| FUNC_NAME
	;
*/
extern struct ast_type_node ___func__node;	//	represents: __func__



/* ELLIPSIS token == "..." */
extern struct ast_type_node ellipsis_node;




//	----------------------------------------------------------------------------------------------------------------
//	AST_ERROR node

extern struct ast_type_node error_node;

//	----------------------------------------------------------------------------------------------------------------
//	----------------------------------------------------------------------------------------------------------------

// extern struct ast_lcase_node _lcase_node[];
extern struct ast_id_node lcase_node[];

extern struct ast_id_node strlen_node;

extern struct ast_id_node printf_node;
extern struct ast_id_node fprintf_node;
extern struct ast_id_node sprintf_node;
extern struct ast_id_node snprintf_node;

extern struct ast_id_node exit_node;
extern struct ast_id_node assert_node;
extern struct ast_id_node static_assert_node;

extern struct ast_id_node malloc_node;
extern struct ast_id_node calloc_node;
extern struct ast_id_node realloc_node;
extern struct ast_id_node free_node;
extern struct ast_id_node alloca_node;

extern struct ast_id_node memmove_node;
extern struct ast_id_node memcpy_node;
extern struct ast_id_node memset_node;

extern struct ast_id_node size_t_node;

// extern struct ast_id_node _this_node;
// extern struct ast_id_node _self_node;

extern struct ast_type_node this_node;
extern struct ast_type_node self_node;

// extern struct ast_type_node _blank_id_node;

//	----------------------------------------------------------------------------------------------------------------
//	----------------------------------------------------------------------------------------------------------------


// extern struct ast_type_node private_node;
// extern struct ast_type_node protected_node;
// extern struct ast_type_node internal_node;	//	`internal` could be used inside an `impl` block, to denote that the function cannot be called externally !?!?

//	----------------------------------------------------------------------------------------------------------------
//	----------------------------------------------------------------------------------------------------------------
//								NEW `reserved keywords` that are also IDENTIFIER's!
//	When we detect one of these keywords used as variable or function names; then we fallback to the IDENTIFIER.

extern struct ast_id_node new_as_id_node;
extern struct ast_id_node delete_as_id_node;

extern struct ast_id_node in_as_id_node;

extern struct ast_id_node get_as_id_node;
extern struct ast_id_node set_as_id_node;

// extern struct ast_id_node private_as_id_node;
// extern struct ast_id_node protected_as_id_node;
// extern struct ast_id_node internal_as_id_node;
