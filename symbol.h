#pragma once

typedef struct symbol_t symbol_t;

/* In grokdeclarator, distinguish syntactic contexts of declarators.  */
enum decl_context // SYMBOL_TYPE
{
	SYMBOL_FUNCTION,
	SYMBOL_TYPEDEF,
	SYMBOL_STRUCT,
	SYMBOL_UNION,
	SYMBOL_ENUM,
	SYMBOL_ENUM_CONSTANT,
	SYMBOL_VARIABLE,
	SYMBOL_PARAMETER,
	SYMBOL_LABEL,
	SYMBOL_TYPE,
	SYMBOL_DECLARATION,
	SYMBOL_UNKNOWN
};



enum decl_flags // SYMBOL_FLAGS
{
	// NORMAL,		/* Ordinary declaration */
	// FUNCDEF,	/* Function definition */
	// PARM,		/* Declaration of parm before function body */
	// FIELD,		/* Declaration inside struct or union */
	// BITFIELD,	/* Likewise but with specified width */
	// TYPENAME,	/* Typename (inside cast or sizeof)  */

	SYM_FIELD,		/* Struct / Union field */
	SYM_BITFIELD,	/* Struct / Union bitfield */
	SYM_TYPENAME,

    SYM_VARIABLE,
    SYM_FUNCTION,
    SYM_TYPEDEF,
    SYM_STRUCT,
    SYM_UNION,
    SYM_ENUM,
	SYM_TYPEDEF_NAME,
	SYM_ENUM_CONSTANT,

	SYM_CLASS,
	SYM_INTERFACE,
	SYM_NAMESPACE,
	SYM_TRAIT,
	SYM_TEMPLATE,
	SYM_CONSTANT,
	SYM_GLOBAL,
	SYM_LOCAL,
	SYM_PARAMETER,
	SYM_LABEL,
	SYM_TYPE,
	SYM_DECLARATION,

	SYM_CHAR,
	SYM_SHORT,
	SYM_INT,
	SYM_LONG,
	SYM_LONG_LONG,
	SYM_SIGNED,
	SYM_UNSIGNED,
	SYM_FLOAT,
	SYM_DOUBLE,
	SYM_UNSIGNED_CHAR,
	SYM_UNSIGNED_SHORT,
	SYM_UNSIGNED_INT,
	SYM_UNSIGNED_LONG,
	SYM_UNSIGNED_LONG_LONG,

	SYM_VOID,
	SYM_BOOL,
	SYM_STRING,
	SYM_ARRAY,
	SYM_POINTER,
};			

typedef union ast_node ast_node;

typedef struct impl_t {
	union ast_node *node;
//	hash_map_t functions;
//	hash_map_t properties;
//	hash_map_t getters;
//	hash_map_t setters;

//	int is_struct  : 1;
//	int is_union   : 1;
//	int is_typedef : 1;

	int is_new      : 1;
	int is_delete   : 1;
	int is_setter   : 1;
	int is_getter   : 1;
	int is_function : 1;
	int has_declaration : 1;
	int has_definition  : 1;
} impl_t;

struct symbol_t {
	union ast_node *node;
	// union ast_node *typedef_name;	// eg. typedef struct Car Car; Car* car; ... typedef_name = Car
	// union ast_node *declaration;	//	eg. `parameter_declaration`
	unsigned is_function : 1;
	unsigned is_variable : 1;
	unsigned is_typedef  : 1;		// eg. `typedef struct Foo<int> MyFoo;` ... `MyFoo` is a typedef!
	unsigned is_setter   : 1;
	unsigned is_getter   : 1;
	unsigned is_pointer  : 1;
	// unsigned is_generic_name : 1;	// eg. `Vec3` ... using `is_generic` instead
	unsigned is_generic_type : 1;	// eg. `T`
	unsigned is_generic_impl : 1;	// eg. `impl Vec3<T> { ... }`
	unsigned is_generic_static_impl : 1;	// eg. `impl static Vec3<T> { ... }`

	unsigned is_struct : 1;
	unsigned is_union : 1;
	unsigned is_generic : 1;	// eg. `Vec3`

//	unsigned is_struct_or_union_member : 1;	//	AKA AST_STRUCT_OR_UNION_DECLARATOR

	unsigned is_enum_constant : 1;

	unsigned is_extern : 1;
	unsigned is_static : 1;
	unsigned is_const : 1;
	unsigned is_volatile : 1;
	unsigned is_enum : 1;
	unsigned is_class : 1;
	unsigned is_interface : 1;
	unsigned is_namespace : 1;
	unsigned is_template : 1;
	unsigned is_implicit : 1;
	unsigned is_explicit : 1;
	unsigned is_virtual : 1;
	unsigned is_override : 1;
	unsigned is_final : 1;
	unsigned is_abstract : 1;
	unsigned is_pure_virtual : 1;
	unsigned is_deleted : 1;
	unsigned is_default : 1;
	unsigned is_inline : 1;
	unsigned is_friend : 1;
	unsigned is_auto : 1;
	unsigned is_register : 1;
	unsigned is_mutable : 1;
	unsigned is_signed : 1;
	unsigned is_unsigned : 1;
	unsigned is_short : 1;
	unsigned is_long : 1;
	unsigned is_char : 1;
	unsigned is_int : 1;
	unsigned is_float : 1;
	unsigned is_double : 1;
	unsigned is_void : 1;
	unsigned is_bool : 1;
	unsigned is_wchar_t : 1;
	unsigned is_constexpr : 1;
	unsigned is_noexcept : 1;
	unsigned is_thread_local : 1;
	unsigned is_restrict : 1;
	unsigned is_atomic : 1;
	unsigned is_noreturn : 1;
	unsigned is_alignas : 1;
	unsigned is_alignof : 1;
	unsigned is_decltype : 1;
	unsigned is_typeof : 1;
	unsigned is_sizeof : 1;

	unsigned is_parameter : 1;
};
