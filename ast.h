#pragma once

#include <stdlib.h>

typedef enum ast_node_type {
	AST_ROOT,

	AST_ERROR,

	AST_PRAGMA,

	/* Assignment */
	AST_ASSIGN,		/* =   */
	AST_ADD_ASSIGN,	/* +=  */
	AST_SUB_ASSIGN,	/* -=  */
	AST_MUL_ASSIGN,	/* *=  */
	AST_DIV_ASSIGN,	/* /=  */
	AST_MOD_ASSIGN,	/* %=  */
	AST_AND_ASSIGN,	/* &=  */
	AST_XOR_ASSIGN,	/* ^=  */
	AST_OR_ASSIGN,	/* |=  */
	AST_SHL_ASSIGN,	/* <<= */
	AST_SHR_ASSIGN,	/* >>= */

	AST_EQ,			/* == */	//	Used in: `equality_expression`
	AST_NE,			/* != */	//		"				"
	AST_GT,			/* >  */	//	Used in: `relational_expression`
	AST_GE,			/* >= */	//		"				"
	AST_LT,			/* <  */	//		"				"
	AST_LE,			/* <= */	//		"				"

	AST_ADD,		/* + */
	AST_SUB,		/* - */
	AST_MUL,		/* * */
	AST_DIV,		/* / */
	AST_MOD,		/* % */

	AST_SHL,		/* << */	//	Used in: `shift_expression`
	AST_SHR,		/* >> */	//		"				"

	// AST_NOT,		/* ! */		//	declared as AST_LOGICAL_NOT in `unary_ops`

	AST_AND,		/* && */	//	Used in: `logical_and_expression`
	AST_OR,			/* || */	//	Used in: `logical_or_expression`

	AST_BIT_AND,	/* & */		//	Used in: `and_expression`
	AST_BIT_OR,		/* | */		//	Used in: `inclusive_or_expression`
	AST_BIT_XOR,	/* ^ */		//	Used in: `exclusive_or_expression`
	//AST_BIT_NOT,	/* ~ */	// This is a unary operator! Not required here, defined in `unary_operator`

	AST_ID,
	AST_ENUMERATION_CONSTANT,
	AST_TYPEDEF_NAME,

	AST_STRING,
	AST_NUM,

	AST_NULL,

	AST_THIS,
	AST_SELF,

	AST_THIS_DOT,
	AST_SELF_DOT,

	AST_FALSE,
	AST_TRUE,


	AST_NUMERIC, // Generic numeric type. If all the numeric types, int, long, float, double, etc. all store the original string, then we can just use this type for all of them.
	// AST_I_CONSTANT,
	// AST_F_CONSTANT,



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
	AST_VOID,
	AST_CHAR,
	AST_SHORT,
	AST_INT,
	AST_LONG,
	AST_FLOAT,
	AST_DOUBLE,
	AST_SIGNED,
	AST_UNSIGNED,
	AST_BOOL,
	AST_COMPLEX,
	AST_IMAGINARY,

	/* GCC Extensions */
	AST__BUILTIN_VA_LIST,


	/* GCC __attribute__ extension support */
	AST__ATTRIBUTE__,
	/* GCC __asm__ extension support */
	AST__ASM__,

	/* GCC _Decimal32 extension */
	AST__DECIMAL32,
	/* GCC _Decimal64 extension */
	AST__DECIMAL64,
	/* GCC _Decimal128 extension */
	AST__DECIMAL128,

	/* GCC _Float128 extension */
	AST__FLOAT128,
	/* GCC __int128 extension */
	AST__INT128,						//	GCC __int128 extension - As of GCC 4.6
	/* GCC __int128_t extension */
	AST__INT128_T,						//	GCC __int128_t extension - As of GCC 4.1
	/* GCC __uint128_t extension */
	AST__UINT128_T,						//	GCC __uint128_t extension - As of GCC 4.1

	/* C23 _BitInt(128) */
	//AST__BITINT128,						//	Common in Clang
	/* C23 _BitInt(N) */
	AST__BITINT,						//	Generic C23 version!



	AST_CONST,
	AST_RESTRICT,
	AST_VOLATILE,

	AST__RESTRICT,	//	__restrict

	//	storage_class_specifier
	AST_TYPEDEF,
	AST_EXTERN,
	AST_STATIC,
	AST_THREAD_LOCAL,
	AST_AUTO,
	AST_REGISTER,

	/*
	struct_or_union
		: STRUCT
		| UNION
		;
	*/
	AST_STRUCT,
	AST_UNION,


	/*
	generic_specifier
		: GENERIC_NAME '<' generic_type_specifiers '>'
		;
	*/
	AST_GENERIC_DECLARATION,
	AST_GENERIC_SPECIFIER,

	AST_GENERIC_STRUCT,
	AST_GENERIC_UNION,



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
	AST_STRUCT_OR_UNION_DECLARATION,
	AST_STRUCT_OR_UNION_DECLARATOR,



	AST_ENUM,
	// AST_ENUM_LIST, // An "enum_list" is a "binary_node" of "enum_constant" nodes. However, if there is only one enum value, then it just be a "enum_constant" node.
	AST_ENUM_INIT, // A binary node (left & right) used when an enum value is initialized with a value, eg. "enum { A = 5 }"
	// AST_ENUM_AUTO, // A unary node used when an enum value is not initialized with a value, eg. "enum { A }"
	//	NOTE: We don't need "AUTO" because we can just return the ID node directly! So the type will be "AST_ID"!
	//AST_ENUM_ID, // A unary node used when an enum value is not initialized with a value, eg. "enum { A }"
	// AST_ENUM_CONSTANT, // A unary node used when an enum value is not initialized with a value, eg. "enum { A }"


	//	function_specifier
	AST_INLINE,
	AST_NORETURN,
	//	-----------------------------------------------------------------------
	//	GCC __inline && __inline__ extensions
	AST__INLINE,
	AST__INLINE__,
	//AST__ATTRIBUTE__ALWAYS_INLINE,


	/*
	selection_statement
		: IF '(' expression ')' statement ELSE statement
		| IF '(' expression ')' statement
		| SWITCH '(' expression ')' statement
		;
	*/
	AST_IF,
	// AST_ELSE,		//	Currently not used. There is just one kind of "if" statement that takes care of both scenarios.
	// AST_IF_ELSE,		//	My idea was to have a single "if" statement that takes care of both scenarios. However, if I need a node type that has a separate "else" statement, then I can use this.
	AST_SWITCH,




	/*
	labeled_statement
		: IDENTIFIER ':' statement					//	AST_LABEL
		| CASE constant_expression ':' statement	//	AST_CASE
		| DEFAULT ':' statement						//	AST_DEFAULT
		;
	*/
	AST_LABEL,
	AST_CASE,
	AST_DEFAULT,

	/*
	jump_statement
		: GOTO IDENTIFIER ';'						//	AST_GOTO
		| CONTINUE ';'								//	AST_CONTINUE
		| BREAK ';'									//	AST_BREAK
		| RETURN ';'								//	AST_RETURN
		| RETURN expression ';'						//	AST_RETURN
	*/
	AST_GOTO,
	AST_CONTINUE,
	AST_BREAK,
	AST_RETURN,


	/*
	expression_statement
		: ';'
		| expression ';'
		;
	*/
	AST_EXPRESSION_STATEMENT,


	/*
	atomic_type_specifier
		: ATOMIC '(' type_name ')'					//	AST_ATOMIC_TYPE
		;
	*/
	AST_ATOMIC_TYPE,								//	Not exactly the same as `AST_ATOMIC`! This is the "atomic" keyword used in `atomic_type_specifier`
	AST_ATOMIC,										//	Not exactly the same as `AST_ATOMIC_TYPE`! This is the "atomic" keyword used in `type_qualifier`


	/*
	unary_operator
		: '&'
		| '*'
		| '+'
		| '-'
		| '~'
		| '!'
		;
	*/
	AST_UNARY,
	//	See `unary_ops` for the actual values
	// AST_UNARY_ADDRESS_OF,	/* & */
	// AST_UNARY_DEREFERENCE,	/* * */
	// AST_UNARY_PLUS,			/* + */
	// AST_UNARY_MINUS,			/* - */
	// AST_UNARY_BITWISE_NOT,	/* ~ */
	// AST_UNARY_LOGICAL_NOT,	/* ! */


	/*
	pointer
		: '*' type_qualifier_list pointer
		| '*' type_qualifier_list
		| '*' pointer
		| '*'
		;
	*/
	AST_POINTER,


	/*
	conditional_expression
		: logical_or_expression
		| logical_or_expression '?' expression ':' conditional_expression		//	AST_TERNARY
		;
	*/
	AST_TERNARY,


	/*
	cast_expression
		: unary_expression
		| '(' type_name ')' cast_expression			//	AST_CAST
		;
	*/
	AST_CAST,


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
	AST_PRE_INC,
	AST_PRE_DEC,
	AST_SIZEOF_EXPR,
	AST_SIZEOF_TYPE,
	AST_ALIGNOF,


	/*
	unary_operator
		: '&'
		| '*'
		| '+'
		| '-'
		| '~'
		| '!'
		;
	*/
	AST_ADDRESS_OF,			/* & */
	AST_DEREFERENCE,		/* * */
	AST_POSITIVE,			/* + */
	AST_NEGATIVE,			/* - */
	AST_BITWISE_NOT,		/* ~ */
	AST_LOGICAL_NOT,		/* ! */








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
	AST_ARRAY_SUBSCRIPT,
	AST_FUNCTION_CALL,
	AST_MEMBER_ACCESS,
	AST_MEMBER_ACCESS_POINTER,
	AST_POST_INC,
	AST_POST_DEC,
	// AST_INC_POSTFIX,
	// AST_DEC_POSTFIX,
	// AST_POSTFIX_INCREMENT,
	// AST_POSTFIX_DECREMENT,
	AST_COMPOUND_LITERAL,


	/*
	primary_expression
		: IDENTIFIER
		| constant
		| string
		| '(' expression ')'
		| generic_selection
		;
	*/
	AST_EXPRESSION_GROUP,




	AST_INIT_LIST,	//	Initializer list / `initializer_list`



	/*	
	init_declarator
		: declarator '=' initializer
		| declarator
		;
	*/
	AST_INIT_DECLARATOR,


	/*
	declarator
		: pointer direct_declarator
		| direct_declarator
		;
	*/
	AST_POINTER_DECLARATOR,





	/*
	generic_selection
		: GENERIC '(' assignment_expression ',' generic_assoc_list ')'
		;

	generic_assoc_list
		: generic_association
		| generic_assoc_list ',' generic_association
		;

	generic_association
		: type_name ':' assignment_expression
		| DEFAULT ':' assignment_expression
		;
	*/
	AST_GENERIC_SELECTION,
	AST_GENERIC_ASSOC_LIST,
	AST_GENERIC_ASSOC,
	//AST_GENERIC_ASSOC_DEFAULT,




	/*
	compound_statement
		: '{' '}'
		| '{' block_item_list '}'
		;

	block_item_list
		: block_item
		| block_item_list block_item
		;

	block_item
		: declaration
		| statement
		;
	*/
	// AST_COMPOUND_STATEMENT,
	AST_BLOCK,
	// AST_BLOCK_ITEM_LIST,
	// AST_BLOCK_LIST,
	// AST_BLOCK_ITEM,
	// AST_BLOCK_ITEM_DECLARATION,
	// AST_BLOCK_ITEM_STATEMENT,
	AST_DECLARATION,
	AST_STATEMENT,




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
	AST_WHILE,
	AST_DO_WHILE,
	// AST_DO,
	AST_FOR,
	


	/*
	function_definition
		: declaration_specifiers declarator declaration_list compound_statement
		| declaration_specifiers declarator compound_statement
		;
	*/
	AST_FUNCTION_DEFINITION,


	/*
	type_name
		: specifier_qualifier_list abstract_declarator
		| specifier_qualifier_list
		;
	*/
	AST_ABSTRACT_TYPE_NAME,


	/*
	abstract_declarator
		: pointer direct_abstract_declarator
		| pointer
		| direct_abstract_declarator
		;
	*/
	AST_ABSTRACT_DECLARATOR,



	/*
	direct_declarator
		: IDENTIFIER
		| '(' declarator ')'															//	AST_GROUPED_DECLARATOR ... AST_CALLBACK ??? || AST_FUNCTION_POINTER ???
		| direct_declarator '[' ']'														//	AST_UNSPECIFIED_ARRAY
		| direct_declarator '[' '*' ']'													//	AST_DYNAMIC_ARRAY
		| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'	//	AST_STATIC_ARRAY
		| direct_declarator '[' STATIC assignment_expression ']'						//	AST_STATIC_ARRAY
		| direct_declarator '[' type_qualifier_list '*' ']'								//	AST_DYNAMIC_ARRAY
		| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'	//	AST_STATIC_ARRAY
		| direct_declarator '[' type_qualifier_list assignment_expression ']'			//	AST_ARRAY
		| direct_declarator '[' type_qualifier_list ']'									//	AST_UNSPECIFIED_ARRAY
		| direct_declarator '[' assignment_expression ']'								//	AST_ARRAY
		| direct_declarator '(' parameter_type_list ')'									//	AST_FUNCTION_DECLARATOR
		| direct_declarator '(' ')'														//	AST_FUNCTION_DECLARATOR
		| direct_declarator '(' identifier_list ')'										//	AST_FUNCTION_DECLARATOR
		;
	*/
	AST_GROUPED_DECLARATOR,
	AST_UNSPECIFIED_ARRAY,
	AST_DYNAMIC_ARRAY,
	AST_STATIC_ARRAY,
	AST_ARRAY,
	AST_FUNCTION_DECLARATOR,



	/*
	parameter_declaration
		: declaration_specifiers declarator
		| declaration_specifiers abstract_declarator
		| declaration_specifiers
		;
	*/
	AST_PARAMETER_DECLARATION,



	/*
	initializer
		: '{' initializer_list '}'
		| '{' initializer_list ',' '}'
		| assignment_expression
		;
	*/
	AST_INITIALIZER,
	/*
	designation
		: designator_list '='
		;
	*/
	AST_DESIGNATION_INITIALIZER,
	/*
	designator
		: '[' constant_expression ']'
		| '.' IDENTIFIER
		;
	*/
	AST_DESIGNATOR,


	/*
	static_assert_declaration
		: _STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
		| _STATIC_ASSERT '(' constant_expression ')' ';'
		| STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
		| STATIC_ASSERT '(' constant_expression ')' ';'
		;
	*/
	AST__STATIC_ASSERT,
	AST_STATIC_ASSERT,


	/* ELLIPSIS token == "..." */
	AST_ELLIPSIS,

	//	Generic list node
	AST_LIST,


	//	GCC __attribute__ extension
// AST__NOTHROW__,
AST__LEAF__,
AST__PURE__,
AST__NONNULL__,
AST__VECTOR_SIZE__,
AST__MAY_ALIAS__,
AST__GNU_INLINE__,
AST__ALWAYS_INLINE__,
AST__ARTIFICIAL__,
AST__WARN_UNUSED_RESULT__,
AST__NORETURN__,
	AST__CONST__,
AST__DEPRECATED__,
AST__MALLOC__,
AST__ALLOC_SIZE__,
AST__MODE__,
AST__FORMAT__,
AST__ALIGNED__,
// AST__DEPRECATED__,
// AST__DEPRECATED_MSG__,


	/* GCC "__extension__" */
	AST__EXTENSION__,


	AST__FUNC__,	//	represents: __func__


	///////////////////////////////////////////////////////////////////////////
	//	Super C language extensions
	AST_CLASS,
	AST_INTERFACE,
	AST_TRAIT,
	AST_MIXIN,
	AST_IMPL,
	AST_STATIC_IMPL,

	// AST_GENERIC_NAME,	//	eg. in `Vec3<T>`, `Vec3` would be the generic name! ... Isn't this just the same as AST_TYPEDEF_NAME or AST_IDENTIFIER?

	AST_GENERIC_LIST,		//	required to produce special separators for generic types, eg. `Vec3<T, U, V>` ==> `Vec3__long__long__long__long` is too ambiguous! Is it: `long long, long, long` or `long, long long, long` or `long, long, long long`?
	AST_GENERIC_IMPL,
	AST_GENERIC_STATIC_IMPL,

	// AST_NEW,				//	"new" is actually converted to a regular function call during parsing stage, we detect the "new" keyword and we also have the TYPEDEF_NAME at the same time.
	AST_DELETE_OPERATOR,	//	Creates a "regular" function call during processing. Works a bit different to "new" though, because "new" usually comes with the object type as part of the "new" statement, eg. "new Foo()" which can easily be converted to "Foo__new()". But "delete" doesn't have the object type, only a variable name to delete; we have to do a manual lookup for the object type for that variable, eg. "delete foo;" will need to be converted to "Foo__delete(foo)", where we need to lookup "Foo", which is the object/struct/typedef type name of the variable!
	AST_NEW_ARRAY,
	AST_DELETE_ARRAY,

	AST_IMPL_NEW_FUNCTION,			// NOTE: During "impl" processing, the type is changed to AST_FUNCTION_DEFINITION!
	AST_IMPL_NEW_DECLARATOR,

	AST_IMPL_DELETE_FUNCTION,

	AST_NS_OP,						//	AKA AST_TYPENAME_NS_ID, AST_NAMESPACE_REF; eg. `size_t::min`

	AST_GETTER,
	AST_SETTER,

	// AST_BLANK_ID,					//	eg. my_func(&); ... also used during parsing of the AST_DELETE_OPERATOR

	AST_IMPL_FUNCTION_DECLARATION,  // NOTE: During "impl" processing, the type is changed to AST_FUNCTION_DEFINITION! This is probably wrong, because normal function declarations don't use this type! We just use it so it can "output" the correct source code!

	AST_PUBLIC,
	AST_ABSTRACT,
	AST_FINAL,
	AST_OPAQUE,
	AST_VIRTUAL,
	AST_TYPE,

	AST_PRIVATE,
	AST_PROTECTED,
	AST_INTERNAL,


	AST_DUMMY,

	AST__NO_OP__,			//	Going to add this, so we NEVER have a 'NULL' node! This is so the traversal jump_table can avoid checking for NULL nodes, especially if we remove something from an AST_LIST node, because I want to avoid the NULL checks for AST_LIST!

	AST__LAST__				//	NOTE: This is used to determine the size of the `ast_node_type` enum, so it must be the last item in the enum!
} ast_node_type;


// typedef enum unary_ops {
// 	AST_PRE_INC,			/* ++n */
// 	AST_PRE_DEC,			/* --n */
// 	AST_POST_INC,			/* n++ */	//	NOTE: I could also move this to a `create_postfix_node` function, and use AST_POSTFIX with AST_INC/DEC
// 	AST_POST_DEC,			/* n-- */
// 	AST_SIZEOF_EXPR,		/* sizeof n */
// 	AST_SIZEOF_TYPE,		/* sizeof(type) */
// 	AST_ALIGNOF,			/* alignof(type) */
// 	AST_ADDRESS_OF,			/* & */		//	AST_UNARY_ADDRESS_OF
// 	AST_DEREFERENCE,		/* * */		//	AST_UNARY_DEREFERENCE
// 	AST_POSITIVE,			/* + */		//	AST_UNARY_PLUS
// 	AST_NEGATIVE,			/* - */		//	AST_UNARY_MINUS
// 	AST_BITWISE_NOT,		/* ~ */		//	AST_UNARY_BITWISE_NOT
// 	AST_LOGICAL_NOT,		/* ! */		//	AST_UNARY_LOGICAL_NOT
// } unary_ops;


// struct ast_assignment_node {
// 	int type;
// 	// int assign_type;	//	AKA operator type (+=, -=, *=, /=, %=, &=, ^=, |=, <<=, >>=)
// 	union ast_node *left;
// 	union ast_node *right;
// };

struct ast_binary_node {
	int type;
	union ast_node *left;
	union ast_node *right;
};

struct ast_condition_node {
	int type;
	int condition;					//	AKA operator type (==, !=, <, <=, >, >=)
	union ast_node *left;
	union ast_node *right;
};


struct ast_list_node {
	int type;						//	AST_LIST | AST_GENERIC_LIST
	union ast_node *parent;
	union ast_node *node;
	union ast_node *next;
	const char *separator;
};
union ast_node *create_list_node(union ast_node *node, union ast_node *next, const char *separator);
union ast_node *create_generic_list_node(union ast_node *node, union ast_node *next);


struct ast_id_node {
	int type;						//	AST_ID
	unsigned hash;
	const char *id;
};

struct ast_fixed_id_node {
	int type;						//	AST_ID
	char id[12];					//	"malloc", "printf", "strlen", "size_t" etc.
};

struct ast_string_node {
	int type;
	char str[];
};

struct ast_numeric_node {
	int type;
	char num_str[];
};

struct ast_digit_node {
	int type;
	char num_str[4];
};

struct ast_float_node {
	int type;
	char str[5];
};

struct ast_bool_node {
	int type;
	int value;
	char str[6];
};

struct ast_null_node {
	int type;
	char str[6];
};

/** Generic digit node, eg. for zero we store { '0', '\0' } */
struct ast_int_node {
	int type;
	int value; // numeric representation of the digit
	char str[4];
};
struct ast_real_node {
	int type;
	double value;
	char str[8];
};

struct ast_char_node {
	int type;
	char str[3];
};

struct ast_i_constant_node {
	int type;
	long long value;
};

struct ast_f_constant_node {
	int type;
	double value;
};


//	-----------------------------------------------------------------------
//	`type_specifier`

/*
type_specifier
	: ...
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME
	;
*/

/*
atomic_type_specifier
	: ATOMIC '(' type_name ')'					//	AST_ATOMIC_TYPE
	;
*/
struct ast_atomic_type_node {
	int type;									//	AST_ATOMIC_TYPE
	union ast_node *type_name;
};
union ast_node *create_atomic_type_node(union ast_node *type_name);

/*
struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT	{ $$ = AST_STRUCT; }
	| UNION		{ $$ = AST_UNION; }
	;
*/
struct ast_struct_or_union_node {
	int type;						//	AST_STRUCT | AST_UNION
	union ast_node *parent;
	union ast_node *id;
	union ast_node *decl_list;
};
union ast_node *create_struct_or_union_node(int type, union ast_node *id, union ast_node *decl_list);


/*
struct_or_union_specifier
	...
	| struct_or_union identifier '<' generic_type_list '>' '{' struct_declaration_list '}'
	;

generic_type_list
	: IDENTIFIER
	| generic_type_list ',' IDENTIFIER
	;
*/
// struct ast_generic_struct_or_union_node {
// 	int type;						//	AST_GENERIC_STRUCT | AST_GENERIC_UNION
// 	union ast_node *id;
// 	union ast_node *type_list;
// 	union ast_node *decl_list;
// };
// union ast_node *create_generic_struct_or_union_node(int type, union ast_node *id, union ast_node *type_list, union ast_node *decl_list);


/*
generic_specifier
	: IDENTIFIER '<' generic_type_specifiers '>'
	;
*/
struct ast_generic_type_node {
	int type;						//	AST_GENERIC | AST_GENERIC_DECLARATION | AST_GENERIC_SPECIFIER
	int line;
	const char *filename;
	union ast_node *parent;
	union ast_node *id;
	union ast_node *type_list;
};
union ast_node *create_generic_declaration_node(union ast_node *id, union ast_node *type_list, const char *filename, int line);
union ast_node *create_generic_specifier_node(union ast_node *id, union ast_node *type_list, const char *filename, int line);




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
struct ast_struct_or_union_declaration_node {
	int type;						//	AST_STRUCT_OR_UNION_DECLARATION
	union ast_node *parent;
	union ast_node *spec_qual_list;
	union ast_node *decl_list;
};
struct ast_struct_or_union_declarator_node {
	int type;						//	AST_STRUCT_OR_UNION_DECLARATOR
	union ast_node *parent;
	union ast_node *declarator;
	union ast_node *expr;
};
union ast_node *create_struct_or_union_declaration_node(union ast_node *spec_qual_list, union ast_node *decl_list);
union ast_node *create_struct_or_union_declarator_node(union ast_node *declarator, union ast_node *expr);











/*
enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list ',' '}'
	| ENUM IDENTIFIER
	;
*/
struct ast_enum_node {
	int type;						//	AST_ENUM
	union ast_node *id;
	union ast_node *list;			//	enumerator_list
};
union ast_node *create_enum_node(union ast_node *id, union ast_node *list);


//	-----------------------------------------------------------------------

/** Generic `type only` node */
struct ast_type_node {
	int type;
};

//	-----------------------------------------------------------------------


struct ast_value_node {
	int type;
	union {
		char c;
		unsigned char uc;
		short s;
		unsigned short us;
		int i;
		unsigned int u;
		long l;
		unsigned long ul;
		long long ll;
		unsigned long long ull;
		float f;
		double d;
	} value;
};


union ast_node *create_id_node(const char *id);
union ast_node *create_string_node(const char *str);
union ast_node *create_numeric_node(const char *num_str);


struct ast_pragma_node {
	int type;						//	AST_PRAGMA
	char pragma[];
};
union ast_node *create_pragma_node(const char *pragma);

/* GCC __attribute__ extension support */
struct ast_attribute_node {
	int type;						//	AST__ATTRIBUTE__
	char src_code[];
};
union ast_node *create__attribute__node(const char *src_code);

/* GCC __asm__ extension support */
union ast_node *create__asm__node(const char *str);

// union ast_node *create_i_constant(const char* i_constant);
// union ast_node *create_f_constant(const char* f_constant);

/* C23 _BitInt(N) extension */
struct ast_bitint_node {
	int type;						//	AST__BITINT
	int n;
};
union ast_node *create__bitint__node(const char *src_code);

union ast_node *create_binary_node(int type, union ast_node *left, union ast_node *right);
union ast_node *create_condition(int type, int condition, union ast_node *left, union ast_node *right);
union ast_node *create_type_node(int type);	//	null, true, false, int, bool, char, float, double, void, etc.






/*
jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
*/
struct ast_goto_node {
	int type;						//	AST_GOTO
	union ast_node *id;
};
struct ast_return_node {
	int type;						//	AST_RETURN
	union ast_node *expr;
};
union ast_node *create_goto_node(union ast_node *id);
union ast_node *create_return_node(union ast_node *expr);


/*
labeled_statement
	: IDENTIFIER ':' statement					//	AST_LABEL
	| CASE constant_expression ':' statement	//	AST_CASE
	| DEFAULT ':' statement						//	AST_DEFAULT
	;
*/
struct ast_labeled_node {
	int type;									//	AST_LABEL
	union ast_node *id;
	union ast_node *stmt;
};
struct ast_case_node {
	int type;									//	AST_CASE
	union ast_node *expr;
	union ast_node *stmt;
};
struct ast_default_node {
	int type;									//	AST_DEFAULT
	union ast_node *stmt;
};
union ast_node *create_labeled_node(union ast_node *id, union ast_node *stmt);
union ast_node *create_case_node(union ast_node *expr, union ast_node *stmt);
union ast_node *create_default_node(union ast_node *stmt);


/*
pointer
	: '*' type_qualifier_list pointer
	| '*' type_qualifier_list
	| '*' pointer
	| '*'
	;
*/
struct ast_pointer_node {
	int type;									//	AST_POINTER
	union ast_node *type_qualifier_list;		//	WARNING: Don't change the order here, it's used in the "null" node
	union ast_node *pointer;
};
union ast_node *create_pointer_node(union ast_node *type_qualifier_list, union ast_node *pointer);


/*
unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;
*/
struct ast_unary_node {
	int type;									//	AST_UNARY
	union ast_node *expr;
};
union ast_node *create_unary_node(int type, union ast_node *expr);




/*
conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;
*/
struct ast_ternary_node {
	int type;									//	AST_TERNARY
	union ast_node *cond;
	union ast_node *true_expr;
	union ast_node *false_expr;
};
union ast_node *create_ternary_node(union ast_node *cond, union ast_node *true_expr, union ast_node *false_expr);


/*
expression_statement
	: ';'
	| expression ';'
	;
*/
// struct ast_expression_statement_node {
// 	int type;									//	AST_EXPRESSION_STATEMENT
// 	union ast_node *expr;
// };
//	UPDATE: Converted to `unary` node!
union ast_node *create_expression_statement_node(union ast_node *expr);



struct ast_translation_unit_node {
	int type;									//	AST_TRANSLATION_UNIT
	union ast_node *decl_list;
};


/*
cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression			//	AST_CAST
	;
*/
struct ast_cast_node {
	int type;									//	AST_CAST
	union ast_node *type_name;
	union ast_node *expr;
};
union ast_node *create_cast_node(union ast_node *type_name, union ast_node *expr);





/*
generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')'
	;

generic_assoc_list
	: generic_association
	| generic_assoc_list ',' generic_association
	;

generic_association
	: type_name ':' assignment_expression
	| DEFAULT ':' assignment_expression
	;
*/
struct ast_generic_selection_node {
	int type;									//	AST_GENERIC_SELECTION
	union ast_node *expr;
	union ast_node *assoc_list;
};
struct ast_generic_assoc_list_node {
	int type;									//	AST_GENERIC_ASSOC_LIST
	union ast_node *assoc;
	union ast_node *assoc_list;
};
struct ast_generic_assoc_node {
	int type;									//	AST_GENERIC_ASSOC
	union ast_node *type_name;
	union ast_node *expr;
};
union ast_node *create_generic_selection_node(union ast_node *expr, union ast_node *assoc_list);
union ast_node *create_generic_assoc_list_node(union ast_node *assoc, union ast_node *assoc_list);
union ast_node *create_generic_assoc_node(union ast_node *type_name, union ast_node *expr);





/* AKA block / block_statement*/
/*
compound_statement
	: '{' '}'
	| '{' block_item_list '}'
	;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;
*/
struct ast_block_node {
	int type;									//	AST_BLOCK  ... AKA `body`?
	union ast_node *parent;
	union ast_node *stmts;
};
union ast_node *create_block_node(union ast_node *stmts);




/*
selection_statement
	: IF '(' expression ')' statement ELSE statement
	| IF '(' expression ')' statement
	| SWITCH '(' expression ')' statement
	;
*/
struct ast_if_node {
	int type;									//	AST_IF
	union ast_node *parent;
	union ast_node *cond;
	union ast_node *if_true;
	union ast_node *if_false;
};
struct ast_switch_node {
	int type;									//	AST_SWITCH
	union ast_node *parent;
	union ast_node *expr;
	union ast_node *stmt;
};
union ast_node *create_if_node(union ast_node *cond, union ast_node *if_true, union ast_node *if_false);
union ast_node *create_switch_node(union ast_node *expr, union ast_node *stmt);



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
struct ast_while_node {
	int type;									//	AST_WHILE
	union ast_node *parent;
	union ast_node *cond;
	union ast_node *body;
};
struct ast_do_while_node {
	int type;									//	AST_DO_WHILE
	union ast_node *parent;
	union ast_node *body;
	union ast_node *cond;
};
struct ast_for_node {
	int type;									//	AST_FOR
	union ast_node *parent;
	union ast_node *init;
	union ast_node *cond;
	union ast_node *incr;
	union ast_node *body;
};
union ast_node *create_while_node(union ast_node *cond, union ast_node *body);
union ast_node *create_do_while_node(union ast_node *body, union ast_node *cond);
union ast_node *create_for_node(union ast_node *init, union ast_node *cond, union ast_node *incr, union ast_node *body);


/*
function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;
*/
struct ast_function_definition_node {
	int type;									//	AST_FUNCTION_DEFINITION
	union ast_node *parent;
	union ast_node *decl_specs;
	union ast_node *declarator;
	union ast_node *decl_list;
	union ast_node *block;
};
union ast_node *create_function_definition_node(union ast_node *decl_specs, union ast_node *declarator, union ast_node *decl_list, union ast_node *block);


/*
declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	| static_assert_declaration
	;
*/
struct ast_declaration_node {
	int type;									//	AST_DECLARATION
	int line;
	const char *filename;
	union ast_node *parent;
	union ast_node *decl_specs;
	union ast_node *init_declarator_list;
};
union ast_node *create_declaration_node(union ast_node *decl_specs, union ast_node *init_declarator_list);








/*
declaration_specifiers
	: storage_class_specifier declaration_specifiers
	| storage_class_specifier
	| type_specifier declaration_specifiers
	| type_specifier
	| type_qualifier declaration_specifiers
	| type_qualifier
	| function_specifier declaration_specifiers
	| function_specifier
	| alignment_specifier declaration_specifiers
	| alignment_specifier
	;
*/





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
struct ast_array_subscript_node {
	int type;									//	AST_ARRAY_SUBSCRIPT
	union ast_node *array;
	union ast_node *index;
};
struct ast_function_call_node {
	int type;									//	AST_FUNCTION_CALL
	union ast_node *function;
	union ast_node *args;
};
struct ast_member_access_node {
	int type;									//	AST_MEMBER_ACCESS || AST_MEMBER_ACCESS_POINTER
	union ast_node *object;
	union ast_node *member;
};
struct ast_compound_literal_node {
	int type;									//	AST_COMPOUND_LITERAL
	union ast_node *type_name;
	union ast_node *init_list;
};
union ast_node *create_array_subscript_node(union ast_node *array, union ast_node *index);
union ast_node *create_function_call_node(union ast_node *function, union ast_node *args);
union ast_node *create_member_access_node(int type, union ast_node *object, union ast_node *member);
union ast_node *create_compound_literal_node(union ast_node *type_name, union ast_node *init_list);


/*
primary_expression
	: IDENTIFIER
	| constant
	| string
	| '(' expression ')'
	| generic_selection
	;
*/
// struct ast_expression_group_node {
// 	int type;									//	AST_EXPRESSION_GROUP
// 	union ast_node *expr;
// };
//	UPDATE: converted to `unary` node!
union ast_node *create_expression_group_node(union ast_node *expr);





/*
type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
	;
*/
struct ast_abstract_type_name_node {
	int type;									//	AST_ABSTRACT_TYPE_NAME
	union ast_node *parent;
	union ast_node *specifier_qualifier_list;
	union ast_node *abstract_declarator;
};
union ast_node *create_abstract_type_name_node(union ast_node *specifier_qualifier_list, union ast_node *abstract_declarator);



/*
abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;
*/
struct ast_abstract_declarator_node {
	int type;									//	AST_ABSTRACT_DECLARATOR
	union ast_node *pointer;
	union ast_node *direct_abstract_declarator;
};
union ast_node *create_abstract_declarator_node(union ast_node *pointer, union ast_node *direct_abstract_declarator);
// struct ast_pointer_node {
// 	int type;									//	AST_POINTER
// 	union ast_node *type_name;
// };
// union ast_node *create_pointer_node(union ast_node *type_name);





/*
direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' '*' ']'
	| '[' STATIC type_qualifier_list assignment_expression ']'
	| '[' STATIC assignment_expression ']'
	| '[' type_qualifier_list STATIC assignment_expression ']'
	| '[' type_qualifier_list assignment_expression ']'
	| '[' type_qualifier_list ']'
	| '[' assignment_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' '*' ']'
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	| direct_abstract_declarator '[' type_qualifier_list ']'
	| direct_abstract_declarator '[' assignment_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;
*/
struct ast_direct_abstract_declarator_node {
	int type;									//	AST_DIRECT_ABSTRACT_DECLARATOR
	union ast_node *direct_abstract_declarator;
	union ast_node *abstract_declarator;
	union ast_node *parameter_type_list;
};
struct ast_direct_abstract_array_declarator_node {
	int type;									//	AST_DIRECT_ABSTRACT_DECLARATOR
	union ast_node *direct_abstract_declarator;
	union ast_node *array_expression;
};

union ast_node *create_direct_abstract_declarator_node(union ast_node *direct_abstract_declarator, union ast_node *abstract_declarator, union ast_node *parameter_type_list);
union ast_node *create_direct_abstract_array_declarator_node(union ast_node *direct_abstract_declarator, union ast_node *array_expression);




















/*	
init_declarator
	: declarator '=' initializer
	| declarator
	;
*/
struct ast_init_declarator_node {
	int type;									//	AST_INIT_DECLARATOR
	union ast_node *declarator;
	union ast_node *initializer;
};
union ast_node *create_init_declarator_node(union ast_node *declarator, union ast_node *initializer);


/*
declarator
	: pointer direct_declarator
	| direct_declarator
	;
*/
struct ast_pointer_declarator_node {
	int type;									//	AST_POINTER_DECLARATOR
	union ast_node *pointer;
	union ast_node *direct_declarator;
};
union ast_node *create_pointer_declarator_node(union ast_node *pointer, union ast_node *direct_declarator);



/*
direct_declarator
	: IDENTIFIER
	| '(' declarator ')'															//	AST_GROUPED_DECLARATOR ... AST_CALLBACK ??? || AST_FUNCTION_POINTER ???
	| direct_declarator '[' ']'														//	AST_UNSPECIFIED_ARRAY
	| direct_declarator '[' '*' ']'													//	AST_DYNAMIC_ARRAY
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'	//	AST_STATIC_ARRAY
	| direct_declarator '[' STATIC assignment_expression ']'						//	AST_STATIC_ARRAY
	| direct_declarator '[' type_qualifier_list '*' ']'								//	AST_DYNAMIC_ARRAY
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'	//	AST_STATIC_ARRAY
	| direct_declarator '[' type_qualifier_list assignment_expression ']'			//	AST_ARRAY
	| direct_declarator '[' type_qualifier_list ']'									//	AST_UNSPECIFIED_ARRAY
	| direct_declarator '[' assignment_expression ']'								//	AST_ARRAY
	| direct_declarator '(' parameter_type_list ')'									//	AST_FUNCTION_DECLARATOR
	| direct_declarator '(' ')'														//	AST_FUNCTION_DECLARATOR
	| direct_declarator '(' identifier_list ')'										//	AST_FUNCTION_DECLARATOR
	;
*/
struct ast_grouped_declarator_node {
	int type;									//	AST_GROUPED_DECLARATOR
	union ast_node *declarator;
};
struct ast_unspecified_array_node {
	int type;									//	AST_UNSPECIFIED_ARRAY
	union ast_node *direct_declarator;
	union ast_node *type_qualifier_list;
};
struct ast_dynamic_array_node {
	int type;									//	AST_DYNAMIC_ARRAY
	union ast_node *direct_declarator;
	union ast_node *type_qualifier_list;
};
// struct ast_static_array_node {
// 	int type;									//	AST_STATIC_ARRAY
// 	union ast_node *direct_declarator;
// 	union ast_node *type_qualifier_list;
// 	union ast_node *expr;
// };
struct ast_array_node {
	int type;									//	AST_ARRAY | AST_STATIC_ARRAY
	union ast_node *direct_declarator;
	union ast_node *type_qualifier_list;
	union ast_node *expr;
};
struct ast_function_declarator_node {
	int type;									//	AST_FUNCTION_DECLARATOR
	union ast_node *direct_declarator;
	union ast_node *params;
	union ast_node *identifier_list;			//	eg. main(argc, argv) ... NOTE: This is used for CONST in `impl` block functions!
};
union ast_node *create_grouped_declarator_node(union ast_node *declarator);
union ast_node *create_unspecified_array_node(union ast_node *direct_declarator, union ast_node *type_qualifier_list);
union ast_node *create_dynamic_array_node(union ast_node *direct_declarator, union ast_node *type_qualifier_list);
union ast_node *create_static_array_node(union ast_node *direct_declarator, union ast_node *type_qualifier_list, union ast_node *expr);
union ast_node *create_array_node(union ast_node *direct_declarator, union ast_node *type_qualifier_list, union ast_node *expr);
union ast_node *create_function_declarator_node(union ast_node *direct_declarator, union ast_node *params, union ast_node *identifier_list);



/*
parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;
*/
struct ast_parameter_declaration_node {
	int type;									//	AST_PARAMETER_DECLARATION
	union ast_node *decl_specs;
	union ast_node *declarator;
};
union ast_node *create_parameter_declaration_node(union ast_node *decl_specs, union ast_node *declarator);




/*
initializer
	: '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	| assignment_expression
	;

initializer_list
	: designation initializer
	| initializer
	| initializer_list ',' designation initializer
	| initializer_list ',' initializer
	;

designation
	: designator_list '='
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: '[' constant_expression ']'
	| '.' IDENTIFIER
	;
*/
struct ast_initializer_node {
	int type;									//	AST_INITIALIZER
	union ast_node *list;
};
struct ast_designation_initializer_node {
	int type;									//	AST_DESIGNATION_INITIALIZER
	union ast_node *designation;
	union ast_node *initializer;
};
struct ast_designator_node {
	int type;									//	AST_DESIGNATOR
	union ast_node *expr;
	union ast_node *id;
};
union ast_node *create_initializer_node(union ast_node *list);
union ast_node *create_designation_initializer_node(union ast_node *designation, union ast_node *initializer);
union ast_node *create_designator_node(union ast_node *expr, union ast_node *id);


/*
static_assert_declaration
	: _STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	| _STATIC_ASSERT '(' constant_expression ')' ';'
	| STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	| STATIC_ASSERT '(' constant_expression ')' ';'
	;
*/
struct ast_static_assert_node {
	int type;									//	AST__STATIC_ASSERT || AST_STATIC_ASSERT
	union ast_node *expr;
	union ast_node *str;
};
union ast_node *create_static_assert_node(int type, union ast_node *expr, union ast_node *str);



/******************************************************************************
 *
 *						Super C classes, interfaces, traits, mixins
 *
 */

struct ast_class_node {
	int type;									//	AST_CLASS / AST_INTERFACE / AST_TRAIT / AST_MIXIN
	union ast_node *id;
	union ast_node *modifiers;
	union ast_node *extends;
	union ast_node *implements;
	union ast_node *body;
};
union ast_node *create_class_node(int type, union ast_node *id, union ast_node *modifiers, union ast_node *extends, union ast_node *implements, union ast_node *body);

struct ast_class_declaration_node {
	int type;									//	AST_CLASS / AST_INTERFACE / AST_TRAIT / AST_MIXIN
	union ast_node *id;
	union ast_node *modifiers;
};
union ast_node *create_class_declaration_node(int type, union ast_node *id, union ast_node *modifiers);

struct ast_impl_node {
	int type;									//	AST_IMPL || AST_STATIC_IMPL
	union ast_node *parent;
	union ast_node *id;
	union ast_node *interface;					//	NOTE: I'm unlikely to use this! Because this might indicate that you can 'randomly' declare `impl` blocks that implement interfaces that are not even in the same file! I'm more likely to use the `implements` keyword in the struct declaration! eg. struct Foo implements Bar { ... } etc.
	union ast_node *body;
};
union ast_node *create_impl_node(union ast_node *id, union ast_node *interface, union ast_node *body);
union ast_node *create_static_impl_node(union ast_node *id, union ast_node *interface, union ast_node *body);


// struct ast_generic_impl_node {
// 	int type;									//	AST_GENERIC_IMPL || AST_GENERIC_STATIC_IMPL
// 	union ast_node *id;
// 	// union ast_node *type_list;
// 	union ast_node *interface;
// 	union ast_node *body;
// };
union ast_node *create_generic_impl_node(union ast_node *id, union ast_node *interface, union ast_node *body);
union ast_node *create_generic_static_impl_node(union ast_node *id, union ast_node *interface, union ast_node *body);





// struct ast_new_node {
// 	int type;									//	AST_NEW
// 	union ast_node *id;
// 	union ast_node *parameter_list;
// };
// union ast_node *create_new_node(union ast_node *id, union ast_node *parameter_list);

// struct ast_delete_node {
// 	int type;									//	AST_DELETE
// 	union ast_node *id;
// 	union ast_node *expr;
// };
// union ast_node *create_delete_node(union ast_node *id, union ast_node *expr);

// AST_IMPL_NEW_FUNCTION
// NOTE: In order to replace the "new" function inside the "impl", we will use the SAME type of node as a normal function definition. We just set the type differently so we can recognize it in our "impl" processor. The only thing we need to do really is change the name!
union ast_node *create_new_function_definition_node(union ast_node *decl_specs, union ast_node *declarator, union ast_node *block);

// AST_IMPL_NEW_DECLARATOR
// Uses the AST_POINTER_DECLARATOR node ... ie. struct ast_pointer_declarator_node
union ast_node *create_new_function_declarator_node(union ast_node *pointer, union ast_node *parameter_type_list);


// AST_IMPL_DELETE_FUNCTION
union ast_node *create_delete_function_definition_node(union ast_node *decl_specs, union ast_node *declarator, union ast_node *block);
// AST_DELETE_OPERATOR
union ast_node *create_delete_operator_node(union ast_node *obj);



// AST_GETTER / AST_SETTER
union ast_node *create_getter_node(union ast_node *decl_specs, union ast_node *declarator, union ast_node *block);
union ast_node *create_setter_node(union ast_node *decl_specs, union ast_node *declarator, union ast_node *block);
// This WAS called `create_getter_or_setter_node` ... however, I changed it to be more generic! Since I actually use it in the 'generics' implementation!
//union ast_node *create_getter_or_setter_node(int type, union ast_node *decl_specs, union ast_node *declarator, union ast_node *block);
union ast_node *create_impl_function_node(int type, union ast_node *decl_specs, union ast_node *declarator, union ast_node *block);


/*
//	No Longer Used!
struct ast_impl_function_declaration_node {
	int type;									//	AST_IMPL_FUNCTION_DECLARATION
	union ast_node *decl_specs;
	union ast_node *declarator;
	union ast_node *params;
};
*/
//union ast_node *create_impl_function_declaration_node(union ast_node *decl_specs, union ast_node *declarator);








// --------------------------------------------
union ast_node *create_tmp_node();


// --------------------------------------------

union ast_node {
	int type;
	// struct ast_assignment_node assign;

	struct ast_pragma_node pragma;

	struct ast_unary_node unary;
	struct ast_binary_node binary;
	struct ast_ternary_node ternary;

	struct ast_cast_node cast;
	struct ast_list_node list;
	struct ast_condition_node condition;
	struct ast_id_node id;
	struct ast_string_node str;
	struct ast_i_constant_node i;
	struct ast_f_constant_node f;
	struct ast_numeric_node numeric;
	struct ast_block_node block;


	struct ast_declaration_node declaration;
	struct ast_init_declarator_node init_declarator;
	struct ast_pointer_declarator_node pointer_declarator;
	struct ast_pointer_node pointer;
	struct ast_abstract_type_name_node abstract_type_name;
	struct ast_abstract_declarator_node abstract_declarator;
	struct ast_direct_abstract_declarator_node direct_abstract_declarator;
	struct ast_function_definition_node function_definition;
	struct ast_parameter_declaration_node parameter_declaration;
	// struct ast_expression_group_node expression_group;			//	Converted to `unary` node!


	//	-----------------------------------------------------------------------
	//	GCC __attribute__ extension
	struct ast_attribute_node attribute;

	//	-----------------------------------------------------------------------
	//	C23 _BitInt(N)
	struct ast_bitint_node bitint;

	//	-----------------------------------------------------------------------
	//	`initializer`
	struct ast_initializer_node initializer;
	struct ast_designation_initializer_node designation_initializer;
	struct ast_designator_node designator;


	//	-----------------------------------------------------------------------
	//	`iteration_statement`
	struct ast_while_node while_stmt;
	struct ast_do_while_node do_while_stmt;
	struct ast_for_node for_stmt;


	// struct ast_continue_node continue_stmt;
	// struct ast_break_node break_stmt;
	// struct ast_function_call_node function_call;
	// struct ast_array_access_node array_access;
	// struct ast_struct_access_node struct_access;
	// struct ast_struct_pointer_access_node struct_pointer_access;
	// struct ast_postfix_increment_node postfix_increment;
	// struct ast_postfix_decrement_node postfix_decrement;
	// struct ast_sizeof_type_node sizeof_type;


	//	-----------------------------------------------------------------------
	//	`type_specifier`
	struct ast_struct_or_union_node struct_or_union;
	struct ast_enum_node enum_type;
	struct ast_atomic_type_node atomic_type;

	//	-----------------------------------------------------------------------
	//	`struct_or_union`
	struct ast_struct_or_union_declaration_node struct_or_union_declaration;
	struct ast_struct_or_union_declarator_node struct_or_union_declarator;

	//	-----------------------------------------------------------------------
	//	`expression_statement`
	// struct ast_expression_statement_node expr_stmt;	//	No longer used! Converted to `unary` node!

	//	-----------------------------------------------------------------------
	//	`selection_statement`
	struct ast_if_node if_stmt;
	struct ast_switch_node switch_stmt;

	//	-----------------------------------------------------------------------
	//	`jump_statement`
	struct ast_goto_node goto_stmt;
	struct ast_return_node return_stmt;

	//	-----------------------------------------------------------------------
	//	`labeled_statement`
	struct ast_labeled_node label;
	struct ast_case_node case_stmt;
	struct ast_default_node default_stmt;

	//	-----------------------------------------------------------------------
	//	`postfix_expression`
	struct ast_array_subscript_node array_subscript;
	struct ast_function_call_node function_call;
	struct ast_member_access_node member_access;
	struct ast_compound_literal_node compound_literal;

	//	-----------------------------------------------------------------------
	//	`direct_declarator`
	struct ast_grouped_declarator_node grouped_declarator;
	struct ast_unspecified_array_node unspecified_array;
	struct ast_dynamic_array_node dynamic_array;
	// struct ast_static_array_node static_array;
	struct ast_array_node array;
	struct ast_function_declarator_node function_declarator;

	//	-----------------------------------------------------------------------
	//	`static_assert_declaration`
	struct ast_static_assert_node static_assert_stmt;

	//	-----------------------------------------------------------------------
	//	Super C extensions
	struct ast_impl_node impl;

	struct ast_generic_type_node generic_type;
	// struct ast_generic_type_node generic_specifier;
	// struct ast_generic_type_node generic_declaration;


	// struct ast_new_node new;
	// struct ast_delete_node delete;

//	struct ast_new_function_node new_function;
//	struct ast_new_declarator_node new_declarator;
};
