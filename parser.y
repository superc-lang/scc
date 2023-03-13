%{
/**
 *	bison -d --verbose --debug parser.y
 *	--locations                  enable location support
 *		NOTE: locations might not be useable, due to the files being preprocessed
 *			If we switch to parsing the original .c and .h files, then we can use locations
 *	--glr-parser				produce a GLR parser
 *	-v, --verbose				verbose mode
 *	-t, --debug					instrument the parser for tracing
 */

#define YYMAXDEPTH 10000000 // seems to do nothing!

#include "lex.yy.h"
#include "ast.h"
#include "ast_nodes.h"
#include "ast_helpers.h"
#include "print_ast_tree.h"
#include "symbol_table.h"
#include "scc.h"
#include "print_syntax.h"

extern int yylineno;
extern const char *yyfilename;

extern int error_count;
char func_name[512];

void yyerror(const char *s);
// void register_typedef(union ast_node *decl_specs, union ast_node *declarator);
static inline union ast_node *maybe_attributes(union ast_node *left, union ast_node *right);

%}
/* %empty external_declaration */
/* %empty translation_unit */

/* Produce a GLR parser */
%glr-parser

/* Verbose error messages */
/* %error-verbose */
/* "warning: deprecated directive: ‘%error-verbose’, use ‘%define parse.error verbose’ [-Wdeprecated]" */
%define parse.error verbose

//%parse-param { const char *filename } ... this adds another parameter to the yyerror() function, which I don't like!

/* Enable location tracking */
%locations

%union {
	char *id;
	char *string;
	char *i_constant;
	char *f_constant;
	union ast_node *node;
	int type;					//	Used for AST_STRUCT and AST_UNION: `struct_or_union`
}

%token	<node>		IDENTIFIER
%token	<node>		STRING_LITERAL
%token	<node>		I_CONSTANT
%token	<node>		F_CONSTANT
%token	<node>		ENUMERATION_CONSTANT
%token	<node>		TYPEDEF_NAME


/*
struct Vec<>;			//	struct IDENTIFIER '<' '>' ... `Vec` gets registered as a GENERIC_NAME
struct Vec<T> {			//	struct GENERIC_NAME '<' IDENTIFIER '>'
	...
};

typedef struct Bar<> Bar<int>;			//	struct IDENTIFIER '<' '>' ... `Bar` gets registered as a GENERIC_NAME
typedef struct Bar<T> Bar<float>;		//	struct GENERIC_NAME '<' IDENTIFIER '>' ... `Bar` gets registered as a GENERIC_NAME

struct Vec<T> {			//	struct IDENTIFIER '<' IDENTIFIER '>' ... `Vec` gets registered as a GENERIC_NAME
	T *data;
	int size;
};

struct Foo<T> {			//	struct IDENTIFIER '<' IDENTIFIER '>'
	Foo<T> *next;		//	GENERIC_NAME '<' GENERIC_TYPE '>'
	Vec<T> *vec;		//	GENERIC_NAME '<' GENERIC_TYPE '>'
	Vec<int> *vec2;		//	GENERIC_NAME '<' GENERIC_TYPE '>' || GENERIC_TYPEDEF_NAME '<' GENERIC_TYPE '>'
	struct Bar<T> {		//	struct IDENTIFIER '<' IDENTIFIER '>'
		int x;
	};
	int x;
};

typedef struct Foo<> Foo<int>;			//	GENERIC_NAME '<' GENERIC_TYPEDEF_NAME '>'		...	`Foo<int>` is registered as a TYPEDEF_NAME ... why do we need this? I think we can use `typedef` like this: `typedef Foo<int> MyFooType;`

typedef struct Foo<int> MyFoo;
typedef Foo<int> MyFoo;

typedef struct Foo<int> Foo<int>;		//	GENERIC_NAME '<' GENERIC_TYPEDEF_NAME '>'

typedef Foo<int> FooInt;				//	GENERIC_NAME '<' GENERIC_TYPEDEF_NAME '>'

*/
%token	<node>		GENERIC_TYPE
%token	<node>		GENERIC_NAME
/* %token	<node>		GENERIC_TYPEDEF_NAME */


%token	FUNC_NAME

%token	SIZEOF
%token	ARROW
%token	INC
%token	DEC
%token	SHL
%token	SHR
%token	LE
%token	GE
%token	EQ
%token	NE
%token	AND
%token	OR
%token	MUL_ASSIGN
%token	DIV_ASSIGN
%token	MOD_ASSIGN
%token	ADD_ASSIGN
%token	SUB_ASSIGN
%token	SHL_ASSIGN
%token	SHR_ASSIGN
%token	AND_ASSIGN
%token	XOR_ASSIGN
%token	OR_ASSIGN

%token	TYPEDEF
%token	EXTERN
%token	STATIC
%token	AUTO
%token	REGISTER
%token	INLINE
%token	CONST
%token	RESTRICT
%token	VOLATILE
%token	ELLIPSIS

//%token	<node>	LINE	// I think we will want to extract the line info and store it in the AST. Maybe as part of function definition, line statements etc.
%token	<node>	PRAGMA

/* GCC extensions */
%token	__ALIGNOF
%token	__ALIGNOF__
%token	<node>	__ASM
%token	<node>	__ASM__
%token	__ATTRIBUTE
%token	<node>		__ATTRIBUTE__
%token	__COMPLEX
%token	__COMPLEX__
%token	__CONST
%token	__CONST__		// defined as part of the __attribute__ extensions. Is it used elsewhere?
%token	__EXTENSION__
%token	__IMAG
%token	__IMAG__
%token	__INLINE
%token	__INLINE__		// GCC recommendations: - https://gcc.gnu.org/onlinedocs/gcc/Alternate-Keywords.html#Alternate-Keywords
%token	__INTERATOR
%token	__INTERATOR__
%token	__LABEL__
%token	__REAL
%token	__REAL__
%token	__SIGNED
%token	__SIGNED__
%token	__TYPEOF
%token	__TYPEOF__		// GCC recommendations: - https://gcc.gnu.org/onlinedocs/gcc/Alternate-Keywords.html#Alternate-Keywords
%token	__VOLATILE
%token	__VOLATILE__
%token	ASM
%token	TYPEOF
%token	__RESTRICT
%token	__AUTO_TYPE


/* GCC __attribute__ extensions */
/* %token	__ATTRIBUTE__ */
/* %token	__NOTHROW__ */
/* %token	__LEAF__ */
/* %token	__PURE__ */
/* %token	<node> __NONNULL__ */
/* %token	<node> __VECTOR_SIZE__ */
/* %token	__MAY_ALIAS__ */
/* %token	__ARTIFICIAL__ */
/* %token	__ALWAYS_INLINE__ */
/* %token	__GNU_INLINE__ */
/* %token	__WARN_UNUSED_RESULT__ */
/* %token	__NORETURN__ */
/* %token	__CONST__ */
/* %token	__DEPRECATED__ */
/* %token	__MALLOC__ */
/* %token	<node> __ALLOC_SIZE__ */
/* %token	<node> __MODE__ */
/* %token	<node> __FORMAT__ */
/* %token	<node> __ALIGNED__ */




//	----------------------------------------
//	Data Types

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
	| IMAGINARY	  	// non-mandated extension
	| atomic_type_specifier
	| struct_or_union_specifier
	| enum_specifier
	| TYPEDEF_NAME		// after it has been defined as such
	;
*/
%token	VOID
%token	CHAR
%token	SHORT
%token	INT
%token	LONG
%token	FLOAT
%token	DOUBLE
%token	SIGNED
%token	UNSIGNED
%token	BOOL
%token	COMPLEX
%token	IMAGINARY 

%token	ATOMIC

%token	STRUCT
%token	UNION

%token	ENUM

//	GCC extensions
%token	__BUILTIN_VA_LIST

//	GCC _Decimal32 extension
%token	_DECIMAL32
//	GCC _Decimal64 extension
%token	_DECIMAL64
//	GCC _Decimal128 extension
%token	_DECIMAL128

//	GCC _Float128 extension
%token	_FLOAT128
//	GCC __int128 extension
%token	__INT128						//	GCC __int128 extension - As of GCC 4.6 - https://gcc.gnu.org/onlinedocs/gcc/_005f_005fint128.html
//	GCC __int128_t extension
%token	__INT128_T						//	GCC __int128_t extension - As of GCC 4.1
//	GCC __uint128_t extension
%token	__UINT128_T						//	GCC __uint128_t extension - As of GCC 4.1
//	C23 _BitInt(128)
%token	_BITINT128						//	Common in Clang
//	C23 _BitInt(N)
%token	<node> _BITINT					//	Generic version!



//	end of Data Types
//	----------------------------------------


%token	CASE
%token	DEFAULT
%token	IF
%token	ELSE
%token	SWITCH
%token	WHILE
%token	DO
%token	FOR
%token	GOTO
%token	CONTINUE
%token	BREAK
%token	RETURN

%token	ALIGNAS
%token	ALIGNOF
%token	GENERIC
%token	NORETURN
%token	_STATIC_ASSERT	/* C11, deprecated in C23 */
%token	STATIC_ASSERT	/* C23 */
%token	THREAD_LOCAL

/******************************************************************************
 *
 *								Super C Keywords
 *
 */

// NOTE: These two are not really keywords, they are returned as normal identifiers because ... they will essentially be used as such!
%token	THIS
%token	SELF

%token	NEW
%token	DELETE

%token	NS

%token	FAT_ARROW		//	=>

%token	GET
%token	SET

%token 	IMPL

%token	END_OF_FILE


/******************************************************************************
 *
 *						New Super C grammar
 *
 */
%type <node> impl_definition

%type <node> impl_body
%type <node> impl_declarations
%type <node> impl_declaration

%type <node> static_impl_body
%type <node> static_impl_declarations
%type <node> static_impl_declaration

%type <node> impl_function_definition
%type <node> impl_fat_arrow_function_definition
%type <node> impl_function_declaration
%type <node> impl_function_declarator
%type <node> impl_direct_declarator
//%type <node> impl_first_id
%type <node> this_or_self

%type <node> getters
%type <node> setters
%type <node> getter_declarator
%type <node> getter_direct_declarator
%type <node> setter_declarator
%type <node> setter_direct_declarator
%type <node> getter_fat_arrow_definition
%type <node> setter_fat_arrow_definition


//	These are used in the initial `struct` or `union` object!
%type <node> generic_declaration					//	eg. `Vec3<T>`
%type <node> generic_specifier						//	eg. `Vec3<float>`

%type <node> generic_id_or_generic_name

//	These are used in the `impl` blocks as the template type placeholders (after declaration!)
%type <node> generic_type_declaration
%type <node> generic_type_list

%type <node> generic_specifier_qualifier_list

/* %type <node> generic_struct_or_union_specifier	//	generics */
%type <node> generic_type_specifiers				//	generics
%type <node> generic_id_list						//	generics

%type <node> generic_id_or_type_declaration
%type <node> generic_id_or_type_specifiers
%type <node> generic_id_or_type_list				//	generics

%type <node> generic_body_or_empty


/* %type <node> getter
%type <node> setter */

%type <node> new_function_definition
%type <node> new_function_declarator

%type <node> delete_function_definition
%type <node> delete_function_declarator
//%type <node> delete_function_params

%type <node> new_expression
%type <node> delete_expression

%type <node> fat_arrow_function_definition	//	Public & general purpose fat arrow function definition!









%type <node> translation_unit
%type <node> external_declarations			//	Added by me, to support empty files! All other methods failed, like adding %empty to external_declaration or translation_unit.
%type <node> external_declaration
%type <node> function_definition
/* %type <node> function_body */
%type <node> declaration_list
%type <node> postfix_expression
%type <node> primary_expression
%type <node> constant
%type <node> enumeration_constant
%type <node> string
%type <node> generic_selection
/* %type <node> generic_assoc_list */
/* %type <node> generic_association */

%type <node> argument_expression_list
/* %type <node> argument_expression			//	Added by me to support __extension__ and __attribute__ in the argument_expression_list; */


%type <node> pragma




%type <node> unary_expression
%type <type> unary_operator
%type <node> cast_expression




%type <node> multiplicative_expression


%type <node> additive_expression
%type <node> shift_expression
%type <node> relational_expression
%type <node> equality_expression
%type <node> and_expression
%type <node> exclusive_or_expression
%type <node> inclusive_or_expression
%type <node> logical_and_expression
%type <node> logical_or_expression
%type <node> conditional_expression



%type <node> assignment_expression
%type <type> assignment_operator
%type <node> expression
%type <node> constant_expression
%type <node> declaration


%type <node> declaration_specifiers
/* %type <node> maybe_attribute					//	EXPERIMENTAL */


%type <node> init_declarator_list
%type <node> init_declarator
%type <node> storage_class_specifier
%type <node> type_specifier
%type <node> struct_or_union_specifier
%type <node> identifier							//	Added by me to support the `typename` having the same as the struct!
%type <type> struct_or_union					//	Used for AST_STRUCT and AST_UNION
%type <node> struct_declaration_list
%type <node> struct_declaration					//	tmp
%type <node> specifier_qualifier_list
%type <node> struct_declarator_list
%type <node> struct_declarator
%type <node> enum_specifier
%type <node> enumerator_list
%type <node> enumerator
%type <node> atomic_type_specifier
%type <node> type_qualifier
%type <node> function_specifier
%type <node> alignment_specifier
%type <node> declarator
%type <node> direct_declarator
%type <node> pointer
%type <node> type_qualifier_list
%type <node> parameter_type_list
%type <node> parameter_list
%type <node> parameter_declaration
%type <node> identifier_list
%type <node> type_name
%type <node> abstract_declarator
%type <node> direct_abstract_declarator
%type <node> initializer
%type <node> initializer_list
%type <node> designation
%type <node> designator_list
%type <node> designator
%type <node> static_assert_declaration
%type <node> statement
%type <node> labeled_statement
%type <node> compound_statement
%type <node> block_item_list
%type <node> block_item
%type <node> expression_statement
%type <node> selection_statement
%type <node> iteration_statement
%type <node> jump_statement



/* GCC __attribute__ extension support */
/* %type <node> attribute_specifier */
/* GCC __asm__ extension support */
%type <node> __asm__specifier
/* GCC __extension__ extension support */
/* %type <node> __extension__specifier */



/* Added to try and support them both ... */
/* %type <node> extension_expression
%type <node> attribute_expression */



/* %type <node> maybe_attributes */
/* %type <node> attribute_list */

/* GCC __extension__ extension support */
%type <node> extension_specifier			//	Added by me to support: return __extension__ (__m128){ 0.0f, 0.0f, 0.0f, 0.0f };
/* %type <node> maybe_extension */


%type <node> maybe_attributes
%type <node> attributes
%type <node> attribute



/* Taken from GCC 2.7.2.3 - c-parse.y */
/* Add precedence rules to solve dangling else s/r conflict */
%nonassoc IF
%nonassoc ELSE

/*
 * Operator Precedence
 */
%left '+' '-' '*' '/' '%'
%left '|' '&' '^'

// Added by me, what happens when we implement Generics? eg. <int> ??? Or doesn't it matter?
%left '<' '>'

%left EQ				// ==
%left NE				// !=
%left LE				// <=
%left GE				// >=

%right '='
%right ADD_ASSIGN		// +=
%right SUB_ASSIGN		// -=
%right MUL_ASSIGN		// *=
%right DIV_ASSIGN		// /=
%right MOD_ASSIGN		// %=
%right AND_ASSIGN		// &=
%right OR_ASSIGN		// |=
%right XOR_ASSIGN		// ^=
%right SHR_ASSIGN		// >>=
%right SHL_ASSIGN		// <<=

%right '?' ':'
%right '!' '~'

%right INC DEC
%right SIZEOF

%left '[' '('
%left ARROW				// ->
%left '.'
%left ','
%left AND				// &&
%left OR				// ||

%left SHR				// >>
%left SHL				// <<

/* Special - added for GCC __extension__ support - taken from GCC 2.7.2.3 c-parse.y to support `contextual precedence`! */
/* https://www.gnu.org/software/bison/manual/html_node/Contextual-Precedence.html */
%right UNARY


// just testing this!
%right __ATTRIBUTE__		// __attribute__ ( ( ) )

/* %left maybe_postfix_attributes	// __attribute__ ( ( ) )
%left postfix_attributes	// __attribute__ ( ( ) )
%left postfix_attribute	// __attribute__ ( ( ) )
%left postfix_attribute_list	// __attribute__ ( ( ) )
%left postfix_attribute_specifier	// __attribute__ ( ( ) )
%left attribute_expression	// __attribute__ ( ( ) ) */


/* %type <node> maybe_postfix_attributes
%type <node> postfix_attributes
%type <node> postfix_attribute
%type <node> postfix_attribute_list
%type <node> postfix_attribute_specifier
/* %type <node> attribute_expression */

/* %type <node> maybe_prefix_attributes
%type <node> prefix_attributes
%type <node> prefix_attribute
%type <node> prefix_attribute_list
%type <node> prefix_attribute_specifier */




//%expect 11				//	expecting 2 x shift/reduce conflicts

%start translation_unit

%%

translation_unit
	: %empty
	{ root_node = $$ = NULL; }
	| external_declarations
	{ root_node = $$ = $1; }
	;

external_declarations
	: external_declaration
	{ $$ = $1; }
	| external_declarations external_declaration
	{ $$ = create_list_node($1, $2, ""); }
	;

external_declaration
	: function_definition
	{ $$ = $1; }
	| fat_arrow_function_definition
	{ $$ = $1; }
	| declaration
	{ $$ = $1; }
	/* Super C `impl` */
	| impl_definition
	{ $$ = $1; }

	/*
	| interface_definition
	{ $$ = $1; }
	| trait_or_mixin_definition
	{ $$ = $1; }
	*/
	| pragma
	{ $$ = $1; }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	{ $$ = create_function_definition_node($1, $2, $3, $4); }
	| declaration_specifiers declarator
		{ symbol_table_push_scope(); }
		compound_statement
		{ symbol_table_pop_scope(); $$ = create_function_definition_node($1, $2, NULL, $4); }
	;

/* function_body
	: compound_statement
	; */

/*
function_body
	: '{' '}'
	{ $$ = create_block_node(NULL); }
	| '{' block_item_list '}'
	{ $$ = create_block_node($2); }
	;
*/



fat_arrow_function_definition
	: declaration_specifiers declarator FAT_ARROW expression ';'
	{ $$ = create_function_definition_node($1, $2, NULL, create_block_node(create_return_node($4))); }
	;

declaration_list
	: declaration
	{ $$ = $1; }
	| declaration declaration_list
	{ $$ = create_list_node($1, $2, ""); }
	;

/******************************************************************************
 *
 *						New Super C grammar
 *
 */


impl_definition
	: IMPL TYPEDEF_NAME '{' impl_body '}'
	{ $$ = create_impl_node($2, NULL, $4); }
	| IMPL STATIC TYPEDEF_NAME '{' static_impl_body '}'
	{ $$ = create_static_impl_node($3, NULL, $5); }
	;

impl_body
	: %empty { $$ = NULL; }
	| impl_declarations { $$ = $1; }
	;

impl_declarations
	: impl_declaration
	{ $$ = $1; }
	| impl_declarations impl_declaration
	{ $$ = create_list_node($1, $2, ""); }
	;

impl_declaration
	: impl_function_definition
	{ $$ = $1; }
	| impl_fat_arrow_function_definition
	{ $$ = $1; }
	| getter_fat_arrow_definition
	{ $$ = $1; }
	| setter_fat_arrow_definition
	{ $$ = $1; }
	| new_function_definition
	{ $$ = $1; }
	| delete_function_definition
	{ $$ = $1; }
	| getters
	{ $$ = $1; }
	| setters
	{ $$ = $1; }
	| impl_function_declaration
	{ $$ = $1; }
	| pragma
	{ $$ = $1; }
	;


static_impl_body
	: %empty { $$ = NULL; }
	| static_impl_declarations { $$ = $1; }
	;

static_impl_declarations
	: static_impl_declaration
	{ $$ = $1; }
	| static_impl_declarations static_impl_declaration
	{ $$ = create_list_node($1, $2, ""); }
	;

static_impl_declaration
	: impl_function_definition
	{ $$ = $1; }
	| impl_fat_arrow_function_definition
	{ $$ = $1; }
	| getter_fat_arrow_definition
	{ $$ = $1; }	//	ERROR! Cannot have `getters` in the `impl static` block
	| new_function_definition
	{ $$ = $1; }
	| delete_function_definition
	{ $$ = $1; }	//	ERROR???
	| getters
	{ $$ = $1; }	//	ERROR! Cannot have `getters` in the `impl static` block
	| setters
	{ $$ = $1; }	//	ERROR! Cannot have `setters` in the `impl static` block
	| impl_function_declaration
	{ $$ = $1; }
	| pragma
	{ $$ = $1; }
	;



impl_fat_arrow_function_definition
	: declaration_specifiers impl_function_declarator FAT_ARROW expression ';'
	{ $$ = create_function_definition_node($1, $2, NULL, create_block_node(create_return_node($4))); }
	;

/* impl_declaration_specifiers
	: declaration_specifiers
	{ $$ = $1; }
	| GET declaration_specifiers
	{ $$ = $2; }
	| SET declaration_specifiers
	{ $$ = $2; }
	| declaration_specifiers GET
	{ $$ = $2; }
	| declaration_specifiers SET
	{ $$ = $2; }
	| declaration_specifiers GET declaration_specifiers
	{ $$ = $2; }
	| declaration_specifiers SET declaration_specifiers
	{ $$ = $2; }
	; */


impl_function_definition
	: declaration_specifiers impl_function_declarator compound_statement
	{ $$ = create_function_definition_node($1, $2, NULL, $3); }
	;

impl_function_declaration
	: declaration_specifiers impl_function_declarator maybe_attributes ';'
	{ $$ = create_function_definition_node($1, maybe_attributes($2, $3), NULL, NULL); }
	;

impl_function_declarator
	: pointer impl_direct_declarator
	{ $$ = create_pointer_declarator_node($1, $2); }
	| impl_direct_declarator
	{ $$ = $1; }
	;

impl_direct_declarator
	: IDENTIFIER '(' parameter_type_list ')'
	{ $$ = create_function_declarator_node($1, $3, NULL); }
	| IDENTIFIER '(' ')'
	{ $$ = create_function_declarator_node($1, NULL, NULL); }
	/*
	| IDENTIFIER '(' impl_first_id ',' parameter_type_list ')'
	{ $$ = create_function_declarator_node($1, create_list_node($3, $5, ", "), NULL); }
	| IDENTIFIER '(' impl_first_id ')'
	{ $$ = create_function_declarator_node($1, $3, NULL); }
	*/
	| IDENTIFIER '(' parameter_type_list ')' CONST
	{ $$ = create_function_declarator_node($1, $3, CONST_NODE); }
	| IDENTIFIER '(' ')' CONST
	{ $$ = create_function_declarator_node($1, NULL, CONST_NODE); }
	;

/*
//	This was when I created a special section for the first parameter shortcuts! However, now I don't even declare the first parameter!
impl_first_id
	: this_or_self                 { $$ = $1; }
	| '*' this_or_self             { $$ = $2; }
	| '*' CONST this_or_self       { $$ = $3; }
	| CONST '*' CONST this_or_self { $$ = $4; }
	| CONST '*' this_or_self       { $$ = $3; }
	| '&' this_or_self             { $$ = $2; }
	/*
	| '*'                          { $$ = blank_id_node; }	//	`blank_id_node` is no longer valid or necessary! We need to deprecate it!
	| '&'                          { $$ = blank_id_node; }
	*/
//	;

this_or_self
	: THIS { $$ = THIS_NODE; }
	| SELF { $$ = SELF_NODE; }
	;

getters
	: GET declaration_specifiers getter_declarator compound_statement
	{ $$ = create_getter_node($2, $3, $4); }
	/* | declaration_specifiers GET getter_declarator compound_statement
	{ $$ = create_getter_node($1, $3, $4); }
	| declaration_specifiers GET declaration_specifiers getter_declarator compound_statement
	{ $$ = create_getter_node(create_list_node($1, $3, " "), $4, $5); } */

	//	Declaration only, no body
	| GET declaration_specifiers getter_declarator ';'
	{ $$ = create_getter_node($2, $3, NULL); }
	/* | declaration_specifiers GET getter_declarator ';'
	{ $$ = create_getter_node($1, $3, NULL); }
	| declaration_specifiers GET declaration_specifiers getter_declarator ';'
	{ $$ = create_getter_node(create_list_node($1, $3, " "), $4, NULL); } */
	;

getter_declarator
	: pointer getter_direct_declarator
	{ $$ = create_pointer_declarator_node($1, $2); }
	| getter_direct_declarator
	{ $$ = $1; }
	;

getter_direct_declarator
	: IDENTIFIER '(' ')'
	{ $$ = create_function_declarator_node($1, NULL, NULL); }
	| IDENTIFIER '(' ')' CONST
	{ $$ = create_function_declarator_node($1, NULL, CONST_NODE); }
	;

setters
	: SET declaration_specifiers setter_declarator compound_statement
	{ $$ = create_setter_node($2, $3, $4); }
	/* | declaration_specifiers SET setter_declarator compound_statement
	{ $$ = create_setter_node($1, $3, $4); }
	| declaration_specifiers SET declaration_specifiers setter_declarator compound_statement
	{ $$ = create_setter_node(create_list_node($1, $3, " "), $4, $5); } */

	//	Declaration only, no body
	| SET declaration_specifiers setter_declarator ';'
	{ $$ = create_setter_node($2, $3, NULL); }
	/* | declaration_specifiers SET setter_declarator ';'
	{ $$ = create_setter_node($1, $3, NULL); }
	| declaration_specifiers SET declaration_specifiers setter_declarator ';'
	{ $$ = create_setter_node(create_list_node($1, $3, " "), $4, NULL); } */
	;

setter_declarator
	: pointer setter_direct_declarator
	{ $$ = create_pointer_declarator_node($1, $2); }
	| setter_direct_declarator
	{ $$ = $1; }
	;

setter_direct_declarator
	: IDENTIFIER '(' parameter_declaration ')'
	{ $$ = create_function_declarator_node($1, $3, NULL); }
	| IDENTIFIER '(' parameter_declaration ')' CONST		//	TODO: Handle/report this error better!
	{ $$ = (void *) & error_node; fprintf(stderr, "'setter' functions cannot be 'const'!\n"); exit(EXIT_FAILURE); }
	;

getter_fat_arrow_definition
	: GET declaration_specifiers getter_declarator FAT_ARROW expression ';'
	{ $$ = create_getter_node($2, $3, create_block_node(create_return_node($5))); }
	/* | declaration_specifiers GET getter_declarator FAT_ARROW expression ';'
	{ $$ = create_getter_node($1, $3, create_block_node(create_return_node($5))); }
	| declaration_specifiers GET declaration_specifiers getter_declarator FAT_ARROW expression ';'
	{ $$ = create_getter_node(create_list_node($1, $3, " "), $4, create_block_node(create_return_node($6))); } */
	;

setter_fat_arrow_definition
	: SET declaration_specifiers setter_declarator FAT_ARROW expression ';'
	{ $$ = create_setter_node($2, $3, create_block_node(create_return_node($5))); }
	/* { fprintf(stderr, "... REVERSE THIS! I WILL SUPPORT SETTER FAT ARROW FUNCTIONS!!!  ERROR: Fat arrow functions for setters are not supported! `setters` don't normally return something ... actually they CAN! They're just a function call!"); exit(EXIT_FAILURE); } */
	/* | declaration_specifiers SET setter_declarator FAT_ARROW expression ';'
	{ fprintf(stderr, "ERROR: Fat arrow functions for setters are not supported!"); exit(EXIT_FAILURE); }
	| declaration_specifiers SET declaration_specifiers setter_declarator FAT_ARROW expression ';'
	{ fprintf(stderr, "ERROR: Fat arrow functions for setters are not supported!"); exit(EXIT_FAILURE); } */
	;

/* 
parameter_declaration
	: declaration_specifiers declarator
	{ $$ = create_parameter_declaration_node($1, $2); }
	| declaration_specifiers abstract_declarator
	{ $$ = create_parameter_declaration_node($1, $2); }
	| declaration_specifiers
	{ $$ = create_parameter_declaration_node($1, NULL); }
	;

	: pointer direct_declarator
	{ $$ = create_pointer_declarator_node($1, $2); }
*/










new_function_definition
	: declaration_specifiers new_function_declarator compound_statement
	{ $$ = create_new_function_definition_node($1, $2, $3); }
	| declaration_specifiers new_function_declarator ';'
	{ $$ = create_new_function_definition_node($1, $2, NULL); }
	| declaration_specifiers new_function_declarator FAT_ARROW expression ';'
	{ $$ = create_new_function_definition_node($1, $2, create_block_node(create_return_node($4))); }
	;





new_function_declarator
	: pointer NEW '(' ')'
	{ $$ = create_new_function_declarator_node($1, NULL); }
	| pointer NEW '(' parameter_type_list ')'
	{ $$ = create_new_function_declarator_node($1, $4); }
	;


delete_function_definition
	: declaration_specifiers delete_function_declarator compound_statement
	{ $$ = create_delete_function_definition_node($1, $2, $3); }
	/* { $$ = create_delete_function_definition_node(VOID_NODE, $2, $3); } */
	| declaration_specifiers delete_function_declarator ';'
	{ $$ = create_delete_function_definition_node($1, $2, NULL); }
	/* { $$ = create_delete_function_definition_node(VOID_NODE, $2, NULL); } */
	| declaration_specifiers delete_function_declarator FAT_ARROW expression ';'
	{ $$ = create_delete_function_definition_node($1, $2, create_block_node(create_return_node($4))); }
	;

delete_function_declarator
	: DELETE '(' ')'
	{ $$ = create_function_declarator_node(NULL, NULL, NULL); }
	;


/*
delete_function_params
	: TYPEDEF_NAME pointer this_or_self
	{ $$ = create_parameter_declaration_node($1, create_pointer_declarator_node($2, $3)); }
	| impl_first_id
	{ $$ = $1; }
	;
*/


/*
getter_direct_declarator
	: IDENTIFIER '(' TYPEDEF_NAME pointer this_or_self ')'
	{
		$$ = create_function_declarator_node($1,
			create_parameter_declaration_node($3, create_pointer_declarator_node($4, $5)),
			NULL);
	}
	| IDENTIFIER '(' impl_first_id ')'
	{ $$ = create_function_declarator_node($1, $3, NULL); }
	;
*/












	/*
	: IDENTIFIER '(' TYPEDEF_NAME pointer this_or_self ')'
	{
		$$ = create_function_declarator_node($1,
			create_parameter_declaration_node($3, create_pointer_declarator_node($4, $5)),
			NULL);
	}
	| IDENTIFIER '(' impl_first_id ')'
	{ $$ = create_function_declarator_node($1, $3, NULL); }
	*/






// eg. Car *car = new Car()
new_expression									//	Ideas from C++ EBNF and Java BNF: https://cui.unige.ch/isi/bnf/JAVA/AJAVA.html
	: NEW TYPEDEF_NAME '(' parameter_list ')'
	{ $$ = create_new_node($2, $4); }
	| NEW TYPEDEF_NAME '(' ')'
	{ $$ = create_new_node($2, NULL); }
	| NEW TYPEDEF_NAME
	{ $$ = create_new_node($2, NULL); }
	;



delete_expression
	: DELETE IDENTIFIER
	{ $$ = create_function_call_node(create_member_access_node(AST_MEMBER_ACCESS_POINTER, $2, (void *) & delete_as_id_node), NULL); }
	| DELETE
	{ $$ = (void *) & delete_as_id_node; }
	;
	/* : DELETE IDENTIFIER
	{ $$ = create_delete_operator_node($2); } */


	/*
	| DELETE IDENTIFIER '[' ']'
	{ $$ = create_delete_node($2, NULL); }
	| DELETE IDENTIFIER '[' expression ']'
	{ $$ = create_delete_node($2, $4); }
	| DELETE cast_expression					//	From the official C++ EBNF: https://www.externsoft.ch/download/cpp-iso.html#universal_character_name
	{ $$ = create_delete_node(NULL, $2); }
	*/


//	---------------------------------------------------------------------------
//					#pragma
//	---------------------------------------------------------------------------

pragma
	: PRAGMA
	{ $$ = $1; }
	;


// maybe_comma
//	: /* empty */
//	| ','
//	;


//	---------------------------------------------------------------------------
//					Expression
//	---------------------------------------------------------------------------

expression
	: assignment_expression
	{ $$ = $1; }
	| expression ',' assignment_expression
	{ $$ = create_list_node($1, $3, ", "); }
	;

assignment_expression
	: conditional_expression
	{ $$ = $1; }
	| unary_expression assignment_operator assignment_expression
	{ $$ = create_binary_node($2, $1, $3); }
	;

assignment_operator
	: '='        { $$ = AST_ASSIGN; }
	| MUL_ASSIGN { $$ = AST_MUL_ASSIGN; }
	| DIV_ASSIGN { $$ = AST_DIV_ASSIGN; }
	| MOD_ASSIGN { $$ = AST_MOD_ASSIGN; }
	| ADD_ASSIGN { $$ = AST_ADD_ASSIGN; }
	| SUB_ASSIGN { $$ = AST_SUB_ASSIGN; }
	| SHL_ASSIGN { $$ = AST_SHL_ASSIGN; }
	| SHR_ASSIGN { $$ = AST_SHR_ASSIGN; }
	| AND_ASSIGN { $$ = AST_AND_ASSIGN; }
	| XOR_ASSIGN { $$ = AST_XOR_ASSIGN; }
	| OR_ASSIGN  { $$ = AST_OR_ASSIGN; }
	;

/* Entry point for many other productions and nonterminals! */
conditional_expression
	: logical_or_expression
	{ $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression
	{ $$ = create_ternary_node($1, $3, $5); }
	;

logical_or_expression
	: logical_and_expression
	{ $$ = $1; }
	| logical_or_expression OR logical_and_expression
	{ $$ = create_binary_node(AST_OR, $1, $3); }
	;

logical_and_expression
	: inclusive_or_expression
	{ $$ = $1; }
	| logical_and_expression AND inclusive_or_expression
	{ $$ = create_binary_node(AST_AND, $1, $3); }
	;

inclusive_or_expression
	: exclusive_or_expression
	{ $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression
	{ $$ = create_binary_node(AST_BIT_OR, $1, $3); }
	;

exclusive_or_expression
	: and_expression
	{ $$ = $1; }
	| exclusive_or_expression '^' and_expression
	{ $$ = create_binary_node(AST_BIT_XOR, $1, $3); }
	;

and_expression
	: equality_expression
	{ $$ = $1; }
	| and_expression '&' equality_expression
	{ $$ = create_binary_node(AST_BIT_AND, $1, $3); }
	;

equality_expression
	: relational_expression
	{ $$ = $1; }
	| equality_expression EQ relational_expression
	{ $$ = create_binary_node(AST_EQ, $1, $3); }
	| equality_expression NE relational_expression
	{ $$ = create_binary_node(AST_NE, $1, $3); }
	;

relational_expression
	: shift_expression
	{ $$ = $1; }
	| relational_expression '<' shift_expression
	{ $$ = create_binary_node(AST_LT, $1, $3); }
	| relational_expression '>' shift_expression
	{ $$ = create_binary_node(AST_GT, $1, $3); }
	| relational_expression LE shift_expression
	{ $$ = create_binary_node(AST_LE, $1, $3); }
	| relational_expression GE shift_expression
	{ $$ = create_binary_node(AST_GE, $1, $3); }
	;

shift_expression
	: additive_expression
	{ $$ = $1; }
	| shift_expression SHL additive_expression
	{ $$ = create_binary_node(AST_SHL, $1, $3); }
	| shift_expression SHR additive_expression
	{ $$ = create_binary_node(AST_SHR, $1, $3); }
	;

additive_expression
	: multiplicative_expression
	{ $$ = $1; }
	| additive_expression '+' multiplicative_expression
	{ $$ = create_binary_node(AST_ADD, $1, $3); }
	| additive_expression '-' multiplicative_expression
	{ $$ = create_binary_node(AST_SUB, $1, $3); }
	;

multiplicative_expression
	: cast_expression
	{ $$ = $1; }
	| multiplicative_expression '*' cast_expression
	{ $$ = create_binary_node(AST_MUL, $1, $3); }
	| multiplicative_expression '/' cast_expression
	{ $$ = create_binary_node(AST_DIV, $1, $3); }
	| multiplicative_expression '%' cast_expression
	{ $$ = create_binary_node(AST_MOD, $1, $3); }

	/* : extension_expression
	{ $$ = $1; }
	| multiplicative_expression '*' extension_expression
	{ $$ = create_binary_node(AST_MUL, $1, $3); }
	| multiplicative_expression '/' extension_expression
	{ $$ = create_binary_node(AST_DIV, $1, $3); }
	| multiplicative_expression '%' extension_expression
	{ $$ = create_binary_node(AST_MOD, $1, $3); } */
	;

cast_expression
	: unary_expression
	{ $$ = $1; }
	/* | __EXTENSION__ '(' type_name ')' cast_expression
	{ $$ = create_list_node(__extension__node, create_cast_node($3, $5), " "); } */
	| '(' type_name ')' cast_expression
	{ $$ = create_cast_node($2, $4); }
	;

unary_expression
	: postfix_expression
	{ $$ = $1; }
	| INC unary_expression
	{ $$ = create_unary_node(AST_PRE_INC, $2); }
	| DEC unary_expression
	{ $$ = create_unary_node(AST_PRE_DEC, $2); }
	| unary_operator cast_expression
	{ $$ = create_unary_node($1, $2); }
	| SIZEOF unary_expression
	{ $$ = create_unary_node(AST_SIZEOF_EXPR, $2); }
	| SIZEOF '(' type_name ')'
	{ $$ = create_unary_node(AST_SIZEOF_TYPE, $3); }
	| ALIGNOF '(' type_name ')'
	{ $$ = create_unary_node(AST_ALIGNOF, $3); }

	/* | __EXTENSION__ '(' type_name ')' cast_expression
	{ $$ = create_list_node(__extension__node, create_cast_node($3, $5), " "); } */

	/* This code was "adapted" from GCC 2.7.2.3 c-parse.y lines 402~407 */
	| extension_specifier cast_expression %prec UNARY
	{ $$ = create_list_node($1, $2, " "); }
	;

unary_operator
	: '&' { $$ = AST_ADDRESS_OF; }
	| '*' { $$ = AST_DEREFERENCE; }
	| '+' { $$ = AST_POSITIVE; }
	| '-' { $$ = AST_NEGATIVE; }
	| '~' { $$ = AST_BITWISE_NOT; }
	| '!' { $$ = AST_LOGICAL_NOT; }
	;

postfix_expression
	: primary_expression
	{ $$ = $1; }
	| postfix_expression '[' expression ']'
	{ $$ = create_array_subscript_node($1, $3); }
	| postfix_expression '(' ')'
	{ $$ = create_function_call_node($1, NULL); }
	| postfix_expression '(' argument_expression_list ')'
	{ $$ = create_function_call_node($1, $3); }

	/*
	//	BEFORE adding support for THIS and SELF!
	| postfix_expression '.' IDENTIFIER
	{ $$ = create_member_access_node(AST_MEMBER_ACCESS, $1, $3); }
	*/
	//	NOTE: This adds support for THIS and SELF! We cannot do it as a rule here, because it would conflict with adding THIS and SELF to the primary_expression rule.
	//	Which is necessary to support `return this;` or `return self;` and also sending `this` or `self` as a parameter to a function.
	| postfix_expression '.' IDENTIFIER
	{ $$ = create_member_access_node($1->type == AST_THIS || $1->type == AST_SELF ? AST_MEMBER_ACCESS_POINTER : AST_MEMBER_ACCESS, $1, $3); }

	//	eg. `foo.this` or `foo.self`
	| postfix_expression '.' this_or_self
	{ $$ = create_member_access_node($1->type == AST_THIS || $1->type == AST_SELF ? AST_MEMBER_ACCESS_POINTER : AST_MEMBER_ACCESS, $1, $3); }
	| postfix_expression ARROW this_or_self
	{ $$ = create_member_access_node(AST_MEMBER_ACCESS_POINTER, $1, $3); }


	/* | THIS '.' IDENTIFIER
	{ $$ = create_member_access_node(AST_MEMBER_ACCESS_POINTER, $1, $3); }
	| SELF '.' IDENTIFIER
	{ $$ = create_member_access_node(AST_MEMBER_ACCESS_POINTER, $1, $3); } */

	| postfix_expression ARROW IDENTIFIER
	{ $$ = create_member_access_node(AST_MEMBER_ACCESS_POINTER, $1, $3); }
	| postfix_expression INC
	{ $$ = create_unary_node(AST_POST_INC, $1); }
	| postfix_expression DEC
	{ $$ = create_unary_node(AST_POST_DEC, $1); }

	| '(' type_name ')' '{' initializer_list '}'
	{ $$ = create_compound_literal_node($2, $5); }
	| '(' type_name ')' '{' initializer_list ',' '}'
	{ $$ = create_compound_literal_node($2, $5); }
	;

primary_expression
	: IDENTIFIER
	{ $$ = $1; }
	| constant
	{ $$ = $1; }
	| string
	{ $$ = $1; }
	| '(' expression ')'
	{ $$ = create_expression_group_node($2); }
	| generic_selection
	{ $$ = $1; }


	//
	//	Super C extensions
	//

	//	NOTE: We need to add this here, so we can support statements like this: "return this;", or even sending "this" or "self" in the parameter list!
	| this_or_self
	{ $$ = $1; }

	/*
	| NEW STRUCT IDENTIFIER
	{ $$ = create_new_node($2); }
	| NEW STRUCT TYPEDEF_NAME
	{ $$ = create_new_node($2); }
	*/
	| NEW TYPEDEF_NAME
	{
		sprintf(func_name, "%s__new", $2->id.id);
		$$ = create_id_node(func_name);
	}
	| TYPEDEF_NAME namespace_operator NEW
	{ $$ = create_binary_node(AST_NS_OP, $1, (void *) & new_as_id_node); }
	| TYPEDEF_NAME namespace_operator IDENTIFIER
	{ $$ = create_binary_node(AST_NS_OP, $1, $3); }

	| NEW
	{ $$ = (void *) & new_as_id_node; }

	| delete_expression
	{ $$ = $1; }

	| __asm__specifier
	{ $$ = $1; }
	;

namespace_operator
	: NS
	| '.'
	;


constant
	: I_CONSTANT			/* includes character_constant */
	{ $$ = $1; }
	| F_CONSTANT
	{ $$ = $1; }
	| ENUMERATION_CONSTANT	/* after it has been defined as such */
	{ $$ = $1; }
	;

// enumeration_constant		/* before it has been defined as such. e.g. enum Type; ??? */
//	: IDENTIFIER
//	{ $$ = $1; string_array_add(&enums, $1->id.id); }
//	;

string
	: STRING_LITERAL
	{ $$ = $1; }
	| FUNC_NAME
	{ $$ = (void *) & ___func__node; }
	;

generic_selection
	: GENERIC '(' assignment_expression ',' generic_assoc_list ')'
	{ $$ = create_tmp_node(); }	//	create_generic_selection_node()
	;

generic_assoc_list
	: generic_association
	| generic_assoc_list ',' generic_association
	;

generic_association
	: type_name ':' assignment_expression
	| DEFAULT ':' assignment_expression
	;

argument_expression_list
	: assignment_expression
	{ $$ = $1; }
	| argument_expression_list ',' assignment_expression
	{ $$ = create_list_node($1, $3, ", "); }
	;


//	---------------------------------------------------------------------------
//					end Expression
//	---------------------------------------------------------------------------















//	---------------------------------------------------------------------------

constant_expression
	: conditional_expression	/* with constraints */
	{ $$ = $1; }
	;

declaration
	: declaration_specifiers maybe_attributes ';'
	{ $$ = create_declaration_node(maybe_attributes($1, $2), NULL); }
	| declaration_specifiers init_declarator_list ';'
	{ $$ = create_declaration_node($1, $2); register_typedef($1, $2); }
	/* | extension_specifier declaration_specifiers ';'
	{
		$$ = create_declaration_node($2, NULL);
		$$ = create_list_node($1, $$, " ");
	}
	| extension_specifier declaration_specifiers init_declarator_list ';'
	{
		$$ = create_declaration_node($2, $3);
		$$ = create_list_node($1, $$, " ");
		check_typedef($2, $3);
	} */
	| static_assert_declaration
	{ $$ = $1; }
	;


declaration_specifiers
	: storage_class_specifier declaration_specifiers
	{ $$ = create_list_node($1, $2, " "); }
	| storage_class_specifier
	{ $$ = $1; }
	| extension_specifier storage_class_specifier declaration_specifiers
	{ $$ = create_list_node($1, create_list_node($2, $3, " "), " "); }
	| extension_specifier storage_class_specifier
	{ $$ = create_list_node($1, $2, " "); }

	| extension_specifier type_specifier declaration_specifiers
	{ $$ = create_list_node($1, create_list_node($2, $3, " "), " "); }
	| extension_specifier type_specifier
	{ $$ = create_list_node($1, $2, " "); }

	| type_specifier declaration_specifiers
	{ $$ = create_list_node($1, $2, " "); }
	| type_specifier
	{ $$ = $1; }

	| type_qualifier declaration_specifiers
	{ $$ = create_list_node($1, $2, " "); }
	| type_qualifier
	{ $$ = $1; }

	| function_specifier declaration_specifiers
	{ $$ = create_list_node($1, $2, " "); }
	| function_specifier
	{ $$ = $1; }

	| alignment_specifier declaration_specifiers
	{ $$ = create_list_node($1, $2, " "); }
	| alignment_specifier
	{ $$ = $1; }
	;

init_declarator_list
	: init_declarator
	{ $$ = $1; }
	| init_declarator_list ',' init_declarator
	{ $$ = create_list_node($1, $3, ", "); }
	;

init_declarator
	: declarator maybe_attributes '=' initializer
	{ $$ = create_init_declarator_node(maybe_attributes($1, $2), $4); }
	| declarator maybe_attributes
	{ $$ = maybe_attributes($1, $2); }
	/* : declarator maybe_attributes '=' initializer */
	/* { $$ = create_init_declarator_node(maybe_attributes($1, $2), $4); } */
	/* | declarator maybe_attributes */
	/* { $$ = maybe_attributes($1, $2); } */
	;

/* init_declarator___ORIGINAL */
	/* : declarator maybe_postfix_attributes '=' initializer */
	/* { $$ = create_init_declarator_node($1, $3); } */
	/* { $$ = create_init_declarator_node($2 == NULL ? $1 : create_list_node($1, $2, " "), $4); } */
	/* | declarator maybe_postfix_attributes */
	/* { $$ = $1; } */
	/* { $$ = $2 == NULL ? $1 : create_list_node($1, $2, " "); } */
	/* ; */


maybe_attributes
	: %empty     { $$ = NULL; }
	| attributes { $$ = $1; }
	;

attributes
	: attribute
	{ $$ = $1; }
	| attributes attribute
	{ $$ = create_list_node($1, $2, " "); }
	;

attribute
	: __ATTRIBUTE__
	{ $$ = $1; }
	;




//maybe_extension
//	: %empty
//	{ $$ = NULL; }
//	| extension_specifier
//	{ $$ = $1; }
//	;


storage_class_specifier
	: maybe_attributes TYPEDEF	/* identifiers must be flagged as TYPEDEF_NAME */
	{ $$ = maybe_attributes($1, TYPEDEF_NODE); }
	/* : extension_specifier TYPEDEF
	{ $$ = create_list_node($1, typedef_node, " "); }
	| extension_specifier EXTERN
	{ $$ = create_list_node($1, extern_node, " "); }
	| extension_specifier STATIC
	{ $$ = create_list_node($1, static_node, " "); } */
	| maybe_attributes EXTERN
	{ $$ = maybe_attributes($1, EXTERN_NODE); }
	/* | extension_specifier STATIC
	{ $$ = create_list_node($1, static_node, " "); } */
	| maybe_attributes STATIC
	{ $$ = maybe_attributes($1, STATIC_NODE); }
	| maybe_attributes THREAD_LOCAL
	{ $$ = maybe_attributes($1, THREAD_LOCAL_NODE); }
	| maybe_attributes AUTO
	{ $$ = maybe_attributes($1, AUTO_NODE); }
	| maybe_attributes REGISTER
	{ $$ = maybe_attributes($1, REGISTER_NODE); }

	/* GCC "__extension__" */
	/* | __EXTENSION__
	{ $$ = __extension__node; } */
	/* | extension_specifier
	{ $$ = $1; } */
	;

type_specifier
	: maybe_attributes VOID
	{ $$ = maybe_attributes($1, VOID_NODE); }
	| maybe_attributes CHAR
	{ $$ = maybe_attributes($1, CHAR_NODE); }
	| maybe_attributes SHORT
	{ $$ = maybe_attributes($1, SHORT_NODE); }
	| maybe_attributes INT
	{ $$ = maybe_attributes($1, INT_NODE); }
	| maybe_attributes LONG
	{ $$ = maybe_attributes($1, LONG_NODE); }
	| maybe_attributes FLOAT
	{ $$ = maybe_attributes($1, FLOAT_NODE); }
	| maybe_attributes DOUBLE
	{ $$ = maybe_attributes($1, DOUBLE_NODE); }
	| maybe_attributes SIGNED
	{ $$ = maybe_attributes($1, SIGNED_NODE); }
	| maybe_attributes UNSIGNED
	{ $$ = maybe_attributes($1, UNSIGNED_NODE); }
	| maybe_attributes BOOL
	{ $$ = maybe_attributes($1, BOOL_NODE); }
	| maybe_attributes COMPLEX
	{ $$ = maybe_attributes($1, COMPLEX_NODE); }
	| maybe_attributes IMAGINARY	  	/* non-mandated extension */
	{ $$ = maybe_attributes($1, IMAGINARY_NODE); }
	| maybe_attributes atomic_type_specifier
	{ $$ = maybe_attributes($1, $2); }
	| maybe_attributes struct_or_union_specifier
	{ $$ = maybe_attributes($1, $2); }
	| maybe_attributes enum_specifier
	{ $$ = maybe_attributes($1, $2); }
	| maybe_attributes TYPEDEF_NAME		/* after it has been defined as such */
	{ $$ = maybe_attributes($1, $2); }


	//	NOTE: I don't think the next comment is true anymore, but I'm leaving it here for now.
	//	NOTE: I'm moving this out of here, because it was causing a shift/reduce ambiguity!
	//	The ambiguity occured usually when you had a `struct` with an inner `struct` using the generic name.
	//	However, this began when I added abilities for opaque generics, and I had to add `type_specifier` to one of the generic lists
	| maybe_attributes GENERIC_TYPE
	{ $$ = maybe_attributes($1, $2); }

	| generic_specifier
	{ $$ = $1; }

	/* GCC extensions */

	/* | attribute
	{ $$ = $1; } */

	/* GCC __attribute__ extension */
	/* | attribute_specifier
	{ $$ = $1; } */
	/* GCC __attribute__ extension */
	/* | prefix_attribute
	{ $$ = $1; } */

	| maybe_attributes __BUILTIN_VA_LIST
	{ $$ = maybe_attributes($1, BUILTIN_VA_LIST_NODE); }

	/* https://android.googlesource.com/toolchain/gcc/+/donut/gcc-4.2.1/gcc/c-parser.c */
	| maybe_attributes _DECIMAL32
	{ $$ = maybe_attributes($1, DECIMAL32_NODE); }
	| maybe_attributes _DECIMAL64
	{ $$ = maybe_attributes($1, DECIMAL64_NODE); }
	| maybe_attributes _DECIMAL128
	{ $$ = maybe_attributes($1, DECIMAL128_NODE); }

	| maybe_attributes _FLOAT128
	{ $$ = maybe_attributes($1, FLOAT128_NODE); }
	| maybe_attributes __INT128
	{ $$ = maybe_attributes($1, INT128_NODE); }
	| maybe_attributes __INT128_T
	{ $$ = maybe_attributes($1, INT128_T_NODE); }
	| maybe_attributes __UINT128_T
	{ $$ = maybe_attributes($1, UINT128_T_NODE); }

	| maybe_attributes _BITINT128
	{ $$ = maybe_attributes($1, BITINT128_NODE); }
	| maybe_attributes _BITINT
	{ $$ = maybe_attributes($1, $2); }
	;



struct_or_union_specifier
	: struct_or_union '{' '}'
	{ $$ = create_struct_or_union_node($1, NULL, NULL); }
	| struct_or_union '{' struct_declaration_list '}' /* maybe_postfix_attributes */
	{ $$ = create_struct_or_union_node($1, NULL, $3); }
	| struct_or_union identifier '{' '}'
	{ $$ = create_struct_or_union_node($1, $2, NULL); }
	| struct_or_union identifier '{' struct_declaration_list '}' /* maybe_postfix_attributes */
	{ $$ = create_struct_or_union_node($1, $2, $4); }
	| struct_or_union identifier
	{ $$ = create_struct_or_union_node($1, $2, NULL); }

	| struct_or_union generic_declaration '{' struct_declaration_list '}'
	{
		symbol_table_pop_scope();
		$$ = create_struct_or_union_node($1 == AST_STRUCT ? AST_GENERIC_STRUCT : AST_GENERIC_UNION, $2, $4);
		// symbol_update_generic(get_id_node($2)->id.id, $$);
	}
	| struct_or_union generic_declaration
	{
		symbol_table_pop_scope();
		$$ = create_struct_or_union_node($1 == AST_STRUCT ? AST_GENERIC_STRUCT : AST_GENERIC_UNION, $2, NULL);
		// symbol_add_generic_name(get_id_node($2)->id.id, NULL);
	}
	/*
	| struct_or_union IDENTIFIER '<' error '>'
	{
		fprintf(stderr, "Generic type names eg. `<T>` cannot be used with a `struct`, remove the `struct` and try again!\n");
		exit(1);
	}
	*/
	;

generic_declaration
	: generic_id_or_generic_name '<' { symbol_table_push_scope(); } generic_id_list '>'
	{ $$ = create_generic_declaration_node($1, $4, yyfilename, yylineno); }
	;

generic_id_or_generic_name
	: IDENTIFIER
	{ $$ = $1; symbol_add_generic($1->id.id, NULL); }
	| GENERIC_NAME
	{ $$ = $1; }
	;

generic_id_list
	: %empty
	{ $$ = NULL; }
	| IDENTIFIER
	{ $$ = $1; symbol_add_generic_type($1->id.id, $1); }
	| generic_id_list ',' IDENTIFIER
	{ $$ = create_generic_list_node($1, $3); symbol_add_generic_type($3->id.id, $3); }

	// NOTE: This is already included in `specifier_qualifier_list`
	/*
	| GENERIC_TYPE
	{ $$ = $1; }
	| generic_id_list ',' GENERIC_TYPE
	{ $$ = create_generic_list_node($1, $3); }
	*/

	// From 68 to 70 shift/reduce conflicts!
	| specifier_qualifier_list
	{ $$ = $1; }
	| generic_id_list ',' specifier_qualifier_list
	{ $$ = create_generic_list_node($1, $3); }
	;

generic_specifier
	: GENERIC_NAME '<' generic_specifier_qualifier_list '>'
	{ $$ = create_generic_specifier_node($1, $3, yyfilename, yylineno); }
	;

generic_specifier_qualifier_list
	: specifier_qualifier_list
	{ $$ = $1; }
	| generic_specifier_qualifier_list ',' specifier_qualifier_list
	{ $$ = create_generic_list_node($1, $3); }
	| IDENTIFIER
	{
		char buf[512];
		snprintf(buf, 512,
			"Syntax error: unexpected token `%s` on line %d.\n"
			"> Only concrete types or pre-defined generic types within a generic struct allowed.\n"
			"> Are you trying to declare a generic typedef with `typedef struct Foo<> Foo<%s>;`\n"
			"> Or are you trying to declare a variable with a generic typename `Foo<%s> foo;` outside a generic struct?\n"
			"> You cannot declare a generic typedef or variable this way,"
			" as the <%s> is not valid outside a generic struct or `impl` block!",
			$1->id.id,
			yylineno,
			$1->id.id,
			$1->id.id,
			$1->id.id);
		yyerror(buf);
		// fprintf(stderr, "Syntax error: unexpected token %s at line %d\n", $1->id.id, @1.first_line);
		YYERROR;
	}
	/*
	| error
	{
		$$ = NULL;
	}
	*/
/*
	| GENERIC_TYPE
	{ $$ = $1; }
	| generic_specifier_qualifier_list ',' GENERIC_TYPE
	{ $$ = create_generic_list_node($1, $3); }
*/
	;








/* Added to the original C11 spec when I realized that if you declare a typename, the same as the struct, then the `typename` lookup in the lexer will return `typename` instead of an IDENTIFIER! This is also implemented in GCC 1.42 this way! */
identifier
	: IDENTIFIER
	| TYPEDEF_NAME
//	| TYPENAME GCC's equivalent of TYPEDEF_NAME!
	;

struct_or_union
	: STRUCT { $$ = AST_STRUCT; }
	| UNION  { $$ = AST_UNION; }
	;

struct_declaration_list
	: struct_declaration
	{ $$ = $1; }
	| struct_declaration_list struct_declaration
	{ $$ = create_list_node($1, $2, ""); }
	;

struct_declaration
	: specifier_qualifier_list maybe_attributes ';'	/* for anonymous struct/union */
	{ $$ = create_struct_or_union_declaration_node(maybe_attributes($1, $2), NULL); }
	| specifier_qualifier_list struct_declarator_list ';'
	{ $$ = create_struct_or_union_declaration_node($1, $2); }
	| static_assert_declaration
	{ $$ = $1; }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	{ $$ = create_list_node($1, $2, " "); }
	| type_specifier
	{ $$ = $1; }

	| extension_specifier type_specifier specifier_qualifier_list
	{ $$ = create_list_node($1, create_list_node($2, $3, " "), " "); }
	| extension_specifier type_specifier
	{ $$ = create_list_node($1, $2, " "); }

	| type_qualifier specifier_qualifier_list
	{ $$ = create_list_node($1, $2, " "); }
	| type_qualifier
	{ $$ = $1; }
	;

struct_declarator_list
	: struct_declarator
	{ $$ = $1; }
	| struct_declarator_list ',' struct_declarator
	{ $$ = create_list_node($1, $3, ", "); }
	;

struct_declarator
	: declarator maybe_attributes /* maybe_postfix_attributes */
	{ $$ = create_struct_or_union_declarator_node(maybe_attributes($1, $2), NULL); }
	/* { $$ = create_struct_or_union_declarator_node($2 == NULL ? $1 : create_list_node($1, $2, " "), NULL); } */
	| declarator maybe_attributes ':' constant_expression /* maybe_postfix_attributes */
	{ $$ = create_struct_or_union_declarator_node(maybe_attributes($1, $2), $4); }
	/* { $$ = create_struct_or_union_declarator_node($1, $4 == NULL ? $3 : create_list_node($3, $4, " ")); } */
	| ':' constant_expression
	{ $$ = create_struct_or_union_declarator_node(NULL, $2); }
	;

enum_specifier
	: ENUM '{' enumerator_list '}' /* maybe_postfix_attributes */
	{ $$ = create_enum_node(NULL, $3); }
	/* { $$ = create_enum_node(NULL, $3); $$ = $5 == NULL ? $$ : create_list_node($$, $5, " "); } */
	| ENUM '{' enumerator_list ',' '}' /* maybe_postfix_attributes */
	{ $$ = create_enum_node(NULL, $3); }
	/* { $$ = create_enum_node(NULL, $3); $$ = $6 == NULL ? $$ : create_list_node($$, $6, " "); } */
	| ENUM identifier '{' enumerator_list '}' /* maybe_postfix_attributes */
	{ $$ = create_enum_node($2, $4); }
	/* { $$ = create_enum_node($2, $4); $$ = $6 == NULL ? $$ : create_list_node($$, $6, " "); } */
	| ENUM identifier '{' enumerator_list ',' '}' /* maybe_postfix_attributes */
	{ $$ = create_enum_node($2, $4); }
	/* { $$ = create_enum_node($2, $4); $$ = $7 == NULL ? $$ : create_list_node($$, $7, " "); } */
	| ENUM identifier
	{ $$ = create_enum_node($2, NULL); }
	;

enumerator_list
	: enumerator
	{ $$ = $1; }
	| enumerator_list ',' enumerator
	{ $$ = create_list_node($1, $3, ",\n"); }
	;

enumerator	/* identifiers from here must be flagged as ENUMERATION_CONSTANT */
	: enumeration_constant '=' constant_expression
	{ $$ = create_binary_node(AST_ENUM_INIT, $1, $3); symbol_add_enum_constant($1->id.id, $$); }
	| enumeration_constant
	/* NOTE: We "wrap" the ID field around this enum value, so we can add indentation! We could also create a dedicated enum, like AST_ENUM_ID to be able to add indentation! */
	{ $$ = create_binary_node(AST_ENUM_INIT, $1, NULL); symbol_add_enum_constant($1->id.id, $$); }
	;

enumeration_constant		/* before it has been defined as such. e.g. enum Type; ??? */
	: IDENTIFIER { $$ = $1; }
	/* : IDENTIFIER { $$ = $1; hash_set_add(&enums, $1->id.id); } */
	;

atomic_type_specifier
	: ATOMIC '(' type_name ')'
	{ $$ = create_atomic_type_node($3); }
	;

type_qualifier
	: CONST      { $$ = CONST_NODE; }
	| RESTRICT   { $$ = RESTRICT_NODE; }
	| __RESTRICT { $$ = _RESTRICT_NODE; }
	| VOLATILE   { $$ = VOLATILE_NODE; }
	| ATOMIC     { $$ = ATOMIC_NODE; }
	;

function_specifier
	: INLINE        { $$ = INLINE_NODE; }
	| NORETURN      { $$ = NORETURN_NODE; }
	/* GCC __inline and __inline__ extensions */
	| __INLINE      { $$ = ___INLINE_NODE; }
	| __INLINE__    { $$ = ___INLINE___NODE; }
	;

alignment_specifier
	: ALIGNAS '(' type_name ')'
	{ $$ = create_tmp_node(); }
	| ALIGNAS '(' constant_expression ')'
	{ $$ = create_tmp_node(); }
	;

declarator
	: pointer direct_declarator
	{ $$ = create_pointer_declarator_node($1, $2); }
	| direct_declarator
	{ $$ = $1; }
	;

direct_declarator
	: maybe_attributes IDENTIFIER
	{ $$ = maybe_attributes($1, $2); }

	| maybe_attributes this_or_self
	{ $$ = maybe_attributes($1, $2); }

	| '(' declarator ')'
	{ $$ = create_grouped_declarator_node($2); }
	| direct_declarator '[' ']'
	{ $$ = create_unspecified_array_node($1, NULL); }
	| direct_declarator '[' '*' ']'
	{ $$ = create_dynamic_array_node($1, NULL); }
	| direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	{ $$ = create_static_array_node($1, $4, $5); }
	| direct_declarator '[' STATIC assignment_expression ']'
	{ $$ = create_static_array_node($1, NULL, $4); }
	| direct_declarator '[' type_qualifier_list '*' ']'
	{ $$ = create_dynamic_array_node($1, $3); }
	| direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	{ $$ = create_static_array_node($1, $3, $5); }
	| direct_declarator '[' type_qualifier_list assignment_expression ']'
	{ $$ = create_array_node($1, $3, $4); }
	| direct_declarator '[' type_qualifier_list ']'
	{ $$ = create_unspecified_array_node($1, $3); }
	| direct_declarator '[' assignment_expression ']'
	{ $$ = create_array_node($1, NULL, $3); }


	| direct_declarator '(' parameter_type_list ')'
	{ $$ = create_function_declarator_node($1, $3, NULL); }
	| direct_declarator '(' ')'
	{ $$ = create_function_declarator_node($1, NULL, NULL); }
	| direct_declarator '(' identifier_list ')'
	{ $$ = create_function_declarator_node($1, NULL, $3); }




	/* GCC __asm__ extension support - the version that follows builtin/standard library function definitions! */
	| direct_declarator __asm__specifier
	{ $$ = create_list_node($1, $2, " "); }
	;




extension_specifier
	: __EXTENSION__ { $$ = ___EXTENSION___NODE; }
	;



__asm__specifier
	: __ASM__ { $$ = $1; }
	;


pointer
	: '*' type_qualifier_list pointer
	{ $$ = create_pointer_node($2, $3); }
	| '*' type_qualifier_list
	{ $$ = create_pointer_node($2, NULL); }
	| '*' pointer
	{ $$ = create_pointer_node(NULL, $2); }
	| '*'
	{ $$ = POINTER_NODE; }
	;

type_qualifier_list
	: type_qualifier
	{ $$ = $1; }
	| type_qualifier_list type_qualifier
	{ $$ = create_list_node($2, $1, " "); }
	;

parameter_type_list
	: parameter_list ',' ELLIPSIS
	{ $$ = create_list_node($1, ELLIPSIS_NODE, ", "); }
	| parameter_list
	{ $$ = $1; }
	;

parameter_list
	: parameter_declaration
	{ $$ = $1; }
	| parameter_list ',' parameter_declaration
	{ $$ = create_list_node($1, $3, ", "); }
	;

parameter_declaration
	: declaration_specifiers declarator
	{ $$ = create_parameter_declaration_node($1, $2); }
	| declaration_specifiers abstract_declarator
	{ $$ = create_parameter_declaration_node($1, $2); }
	| declaration_specifiers
	{ $$ = create_parameter_declaration_node($1, NULL); }

	/* | declaration_specifiers this_or_self_declarator
	{ $$ = create_parameter_declaration_node($1, $2); } */
	;

identifier_list
	: maybe_attributes IDENTIFIER
	{ $$ = maybe_attributes($1, $2); }
	/* { $$ = $2; } */
	| identifier_list ',' maybe_attributes IDENTIFIER
	{ $$ = create_list_node($1, maybe_attributes($3, $4), ", "); }
	;

type_name
	: specifier_qualifier_list abstract_declarator
	{ $$ = create_abstract_type_name_node($1, $2); }
	| specifier_qualifier_list
	{ $$ = $1; }
	;

abstract_declarator
	: pointer direct_abstract_declarator
	{ $$ = create_abstract_declarator_node($1, $2); }
	| pointer
	{ $$ = create_abstract_declarator_node($1, NULL); }
	| direct_abstract_declarator
	{ $$ = create_abstract_declarator_node(NULL, $1); }
	;

// NOTE: These share functions with `direct_declarator`!
direct_abstract_declarator
	: '(' abstract_declarator ')'
	{ $$ = create_grouped_declarator_node($2); }
	| '[' ']'
	{ $$ = create_unspecified_array_node(NULL, NULL); }
	| '[' '*' ']'
	{ $$ = create_dynamic_array_node(NULL, NULL); }
	| '[' STATIC type_qualifier_list assignment_expression ']'
	{ $$ = create_static_array_node(NULL, $3, $4); }
	| '[' STATIC assignment_expression ']'
	{ $$ = create_static_array_node(NULL, NULL, $3); }
	| '[' type_qualifier_list STATIC assignment_expression ']'
	{ $$ = create_static_array_node(NULL, $2, $4); }
	| '[' type_qualifier_list assignment_expression ']'
	{ $$ = create_array_node(NULL, $2, $3); }
	| '[' type_qualifier_list ']'
	{ $$ = create_unspecified_array_node(NULL, $2); }
	| '[' assignment_expression ']'
	{ $$ = create_array_node(NULL, NULL, $2); }
	| direct_abstract_declarator '[' ']'
	{ $$ = create_unspecified_array_node($1, NULL); }
	| direct_abstract_declarator '[' '*' ']'
	{ $$ = create_dynamic_array_node($1, NULL); }
	| direct_abstract_declarator '[' STATIC type_qualifier_list assignment_expression ']'
	{ $$ = create_static_array_node($1, $4, $5); }
	| direct_abstract_declarator '[' STATIC assignment_expression ']'
	{ $$ = create_static_array_node($1, NULL, $4); }
	| direct_abstract_declarator '[' type_qualifier_list assignment_expression ']'
	{ $$ = create_array_node($1, $3, $4); }
	| direct_abstract_declarator '[' type_qualifier_list STATIC assignment_expression ']'
	{ $$ = create_static_array_node($1, $3, $5); }
	| direct_abstract_declarator '[' type_qualifier_list ']'
	{ $$ = create_unspecified_array_node($1, $3); }
	| direct_abstract_declarator '[' assignment_expression ']'
	{ $$ = create_array_node($1, NULL, $3); }
	| '(' ')'
	{ $$ = create_grouped_declarator_node(NULL); }
	| '(' parameter_type_list ')'
	{ $$ = create_function_declarator_node(NULL, $2, NULL); }
	| direct_abstract_declarator '(' ')'
	{ $$ = create_function_declarator_node($1, NULL, NULL); }
	| direct_abstract_declarator '(' parameter_type_list ')'
	{ $$ = create_function_declarator_node($1, $3, NULL); }
	;

initializer
	: '{' initializer_list '}'
	{ $$ = create_initializer_node($2); }
	| '{' initializer_list ',' '}'
	{ $$ = create_initializer_node($2); }
	| assignment_expression
	{ $$ = $1; }
	;

initializer_list
	: designation initializer
	{ $$ = create_designation_initializer_node($1, $2); }
	| initializer
	{ $$ = $1; }
	| initializer_list ',' designation initializer
	{ $$ = create_list_node($1, create_designation_initializer_node($3, $4), ", "); }
	| initializer_list ',' initializer
	{ $$ = create_list_node($1, $3, ", "); }
	;

designation
	: designator_list '='
	{ $$ = $1; }
	;

designator_list
	: designator
	{ $$ = $1; }
	| designator_list designator
	{ $$ = create_list_node($1, $2, " "); }
	;

designator
	: '[' constant_expression ']'
	{ $$ = create_designator_node($2, NULL); }
	| '.' IDENTIFIER
	{ $$ = create_designator_node(NULL, $2); }

	//	NOTE: I think the reason why they added the '.' in front, was so it would not be ambiguous with a general assignment statement!
	//	However, since this is in the `initializer_list` segment, which is wrapped in '{' and '}', it should be fine to just have the IDENTIFIER, and not the require '.' IDENTIFIER.
	//	"I think this is a bug in the standard." lol, this was added ChatGPT! along with the following (dead) link - https://stackoverflow.com/questions/1000000/why-is-the-dot-in-a-designator-required
	//	More resources:
	//		- https://stackoverflow.com/questions/8047261/what-does-dot-mean-in-a-struct-initializer
	//		- https://stackoverflow.com/questions/330793/how-to-initialize-a-struct-in-accordance-with-c-programming-language-standards
	//		- https://en.cppreference.com/w/cpp/language/aggregate_initialization
	//		- https://en.cppreference.com/w/c/language/struct_initialization
	/* | IDENTIFIER
	{ $$ = create_designator_node(NULL, $2); } */
	;

static_assert_declaration
	: _STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	{ $$ = create_static_assert_node(AST__STATIC_ASSERT, $3, $5); }
	| _STATIC_ASSERT '(' constant_expression ')' ';'
	{ $$ = create_static_assert_node(AST__STATIC_ASSERT, $3, NULL); }
	| STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	{ $$ = create_static_assert_node(AST_STATIC_ASSERT, $3, $5); }
	| STATIC_ASSERT '(' constant_expression ')' ';'
	{ $$ = create_static_assert_node(AST_STATIC_ASSERT, $3, NULL); }
	;

statement
	: labeled_statement    { $$ = $1; }
	|
		{ symbol_table_push_scope(); }
		compound_statement
		{ symbol_table_pop_scope(); $$ = $2; }
	| expression_statement { $$ = $1; }
	| selection_statement  { $$ = $1; }
	| iteration_statement  { $$ = $1; }
	| jump_statement       { $$ = $1; }
	/* Super C addition - for compiler compatibility */
	| pragma               { $$ = $1; }
	;

labeled_statement
	: IDENTIFIER ':' statement
	{ $$ = create_labeled_node($1, $3); }
	| CASE constant_expression ':' statement
	{ $$ = create_case_node($2, $4); }
	| DEFAULT ':' statement
	{ $$ = create_default_node($3); }
	;

compound_statement
	: '{' '}'
	{ $$ = create_block_node(NULL); }
	| '{'
		//{ symbol_table_push_scope(); }
		block_item_list '}'
		{
			$$ = create_block_node($2);
		// symbol_table_pop_scope();
		}
	//{ $$ = create_block_node($2); }
	;

block_item_list
	: block_item
	{ $$ = $1; }
	| block_item_list block_item
	{ $$ = create_list_node($1, $2, ""); }
	;

block_item
	: declaration { $$ = $1; }
	| statement   { $$ = $1; }
	;

expression_statement
	: ';'
	{ $$ = create_expression_statement_node(NULL); }
	| expression ';'
	{ $$ = create_expression_statement_node($1); }
	/* | error ';'
	{ $$ = (void *) & error_node; err_count++; fprintf(stdout, "expression error\n"); } */
	;

selection_statement
	: IF '(' expression ')' statement ELSE statement
	{ $$ = create_if_node($3, $5, $7); }
	| IF '(' expression ')' statement
	{ $$ = create_if_node($3, $5, NULL); }
	| SWITCH '(' expression ')' statement
	{ $$ = create_switch_node($3, $5); }
	;

iteration_statement
	: WHILE '(' expression ')' statement
	{ $$ = create_while_node($3, $5); }
	| DO statement WHILE '(' expression ')' ';'
	{ $$ = create_do_while_node($2, $5); }
	| FOR '(' expression_statement expression_statement ')' statement
	{ $$ = create_for_node($3, $4, NULL, $6); }
	| FOR '(' expression_statement expression_statement expression ')' statement
	{ $$ = create_for_node($3, $4, $5, $7); }
	| FOR '(' declaration expression_statement ')' statement
	{ $$ = create_for_node($3, $4, NULL, $6); }
	| FOR '(' declaration expression_statement expression ')' statement
	{ $$ = create_for_node($3, $4, $5, $7); }
	;

jump_statement
	: GOTO IDENTIFIER ';'   { $$ = create_goto_node($2); }
	| CONTINUE ';'          { $$ = CONTINUE_NODE; }
	| BREAK ';'             { $$ = BREAK_NODE; }
	| RETURN ';'            { $$ = RETURN_NODE; }
	| RETURN expression ';' { $$ = create_return_node($2); }
	;

%%
#include <stdio.h>

/* void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "ERROR: %s\n", s);
} */







void yyerror(const char *s)
{
	print_original_syntax(yyfilename, yylineno, s);
return;


	if (yyfilename == NULL || yyfilename[0] == '\0') {
		fprintf(stderr, "%s on line %d\n", s, yylineno);
	}

	fprintf(stderr, "%s:%d: %s\n", yyfilename, yylineno, s);

#	define MAX_LINE_LENGTH 1024
	static char line[MAX_LINE_LENGTH];

	FILE *fp = fopen(yyfilename, "r");
	if (fp == NULL) {
		fprintf(stderr, "Error opening file: %s\n", yyfilename);
		exit(EXIT_FAILURE);
	}

	int current_line = 0;
	while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
		current_line++;
		if (current_line >= yylineno - 1 && current_line <= yylineno + 1) {
			fprintf(stderr, "%c%5d | %s", current_line == yylineno ? '>' : ' ', current_line, line);
		}
	}
}

static inline union ast_node* maybe_attributes(union ast_node *left, union ast_node *right)
{
	if (left == NULL) return right;
	if (right == NULL) return left;
	return create_list_node(left, right, " ");
}


