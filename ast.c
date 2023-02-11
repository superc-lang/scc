#include "ast.h"
#include "symbol_keys.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

union ast_node *ast_root;

union ast_node *ast_condition(int type, int condition, union ast_node *left, union ast_node *right)
{
	struct ast_condition_node *node = (struct ast_condition_node *) malloc(sizeof(struct ast_condition_node));
	node->type = type;
	node->condition = condition;
	node->left = left;
	node->right = right;

	return (union ast_node *) node;
}

// NOTE: For this, we can create static immutable nodes for each type!
union ast_node *ast_type(int type)
{
	int *node = (int*) malloc(sizeof(int));
	*node = type;

	return (union ast_node *) node;
}

// NOTE: For this, we can create static immutable nodes for each type!
union ast_node *create_type_node(int type)
{
	struct ast_type_node *node = (struct ast_type_node *) malloc(sizeof(struct ast_type_node));
	node->type = type;

	return (union ast_node *) node;
}



union ast_node *create_id_node(const char *id)
{
	struct ast_id_node *node = (struct ast_id_node *) malloc(sizeof(struct ast_id_node));
	node->type = AST_ID;
	node->hash = symbol_hash(id);
	node->id = get_symbol_key(id, node->hash);

	return (union ast_node *) node;
}

union ast_node *create_string_node(const char *str)
{
	struct ast_string_node *node = (struct ast_string_node *) malloc(sizeof(struct ast_string_node) + strlen(str) + 1);
	node->type = AST_STRING;
	strcpy(node->str, str);

	return (union ast_node *) node;
}

union ast_node *create_numeric_node(const char *num_str)
{
	struct ast_numeric_node *node = (struct ast_numeric_node *) malloc(sizeof(struct ast_numeric_node) + strlen(num_str) + 1);
	node->type = AST_NUMERIC;
	strcpy(node->num_str, num_str);

	return (union ast_node *) node;
}

union ast_node *create_pragma_node(const char *pragma)
{
	struct ast_pragma_node *node = (struct ast_pragma_node *) malloc(sizeof(struct ast_pragma_node) + strlen(pragma) + 1);
	node->type = AST_PRAGMA;
	strcpy(node->pragma, pragma);

	return (union ast_node *) node;
}

union ast_node *create_enum_node(union ast_node *id, union ast_node *list)
{
	struct ast_enum_node *node = (struct ast_enum_node *) malloc(sizeof(struct ast_enum_node));
	node->type = AST_ENUM;
	node->id = id;
	node->list = list;

	return (union ast_node *) node;
}

union ast_node *create__attribute__node(const char *src_code)
{
	struct ast_attribute_node *node = (struct ast_attribute_node *) malloc(sizeof(struct ast_attribute_node) + strlen(src_code) + 1);
	node->type = AST__ATTRIBUTE__;
	strcpy(node->src_code, src_code);

	return (union ast_node *) node;
}

union ast_node *create__asm__node(const char *str)
{
	struct ast_string_node *node = (struct ast_string_node *) malloc(sizeof(struct ast_string_node) + strlen(str) + 1);
	node->type = AST__ASM__;
	strcpy(node->str, str);

	return (union ast_node *) node;
}

union ast_node *create_binary_node(int type, union ast_node *left, union ast_node *right)
{
	struct ast_binary_node *node = (struct ast_binary_node *) malloc(sizeof(struct ast_binary_node));
	node->type = type;
	node->left = left;
	node->right = right;

	return (union ast_node *) node;
}

union ast_node *create__bitint__node(const char *src_code)
{
	struct ast_bitint_node *node = (struct ast_bitint_node *) malloc(sizeof(struct ast_bitint_node));
	node->type = AST__BITINT;
	int n;
	sscanf(src_code, "_BitInt(%d)", &n);
	node->n = n;

	return (union ast_node *) node;
}




/*
struct_or_union_specifier
	: struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	{ $$ = AST_STRUCT; }
	| UNION
	{ $$ = AST_UNION; }
	;
*/

union ast_node *create_struct_or_union_node(int type, union ast_node *id, union ast_node *decl_list)
{
	struct ast_struct_or_union_node *node = (struct ast_struct_or_union_node *) malloc(sizeof(struct ast_struct_or_union_node));
	node->type = type;
	node->id = id;
	node->decl_list = decl_list;

	return (union ast_node *) node;
}

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
union ast_node *create_struct_or_union_declaration_node(union ast_node *spec_qual_list, union ast_node *decl_list)
{
	struct ast_struct_or_union_declaration_node *node = (struct ast_struct_or_union_declaration_node *) malloc(sizeof(struct ast_struct_or_union_declaration_node));
	node->type = AST_STRUCT_OR_UNION_DECLARATION;
	node->spec_qual_list = spec_qual_list;
	node->decl_list = decl_list;

	return (union ast_node *) node;
}
union ast_node *create_struct_or_union_declarator_node(union ast_node *declarator, union ast_node *expr)
{
	struct ast_struct_or_union_declarator_node *node = (struct ast_struct_or_union_declarator_node *) malloc(sizeof(struct ast_struct_or_union_declarator_node));
	node->type = AST_STRUCT_OR_UNION_DECLARATOR;
	node->declarator = declarator;
	node->expr = expr;

	return (union ast_node *) node;
}








/*
jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
*/
union ast_node *create_goto_node(union ast_node *id)
{
	struct ast_goto_node *node = (struct ast_goto_node *) malloc(sizeof(struct ast_goto_node));
	node->type = AST_GOTO;
	node->id = id;

	return (union ast_node *) node;
}
union ast_node *create_return_node(union ast_node *expr)
{
	struct ast_return_node *node = (struct ast_return_node *) malloc(sizeof(struct ast_return_node));
	node->type = AST_RETURN;
	node->expr = expr;

	return (union ast_node *) node;
}

/*
labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;
*/
union ast_node *create_labeled_node(union ast_node *id, union ast_node *stmt)
{
	struct ast_labeled_node *node = (struct ast_labeled_node *) malloc(sizeof(struct ast_labeled_node));
	node->type = AST_LABEL;
	node->id = id;
	node->stmt = stmt;

	return (union ast_node *) node;
}
union ast_node *create_case_node(union ast_node *expr, union ast_node *stmt)
{
	struct ast_case_node *node = (struct ast_case_node *) malloc(sizeof(struct ast_case_node));
	node->type = AST_CASE;
	node->expr = expr;
	node->stmt = stmt;

	return (union ast_node *) node;
}
union ast_node *create_default_node(union ast_node *stmt)
{
	struct ast_default_node *node = (struct ast_default_node *) malloc(sizeof(struct ast_default_node));
	node->type = AST_DEFAULT;
	node->stmt = stmt;

	return (union ast_node *) node;
}

/*
atomic_type_specifier
	: ATOMIC '(' type_name ')'					//	AST_ATOMIC_TYPE
	;
*/
union ast_node *create_atomic_type_node(union ast_node *type_name)
{
	struct ast_atomic_type_node *node = (struct ast_atomic_type_node *) malloc(sizeof(struct ast_atomic_type_node));
	node->type = AST_ATOMIC_TYPE;
	node->type_name = type_name;

	return (union ast_node *) node;
}


/*
expression_statement
	: ';'
	| expression ';'
	;
*/
union ast_node *create_expression_statement_node(union ast_node *expr)
{
	struct ast_expression_statement_node *node = (struct ast_expression_statement_node *) malloc(sizeof(struct ast_expression_statement_node));
	node->type = AST_EXPRESSION_STATEMENT;
	node->expr = expr;

	return (union ast_node *) node;
}



/*
pointer
	: '*' type_qualifier_list pointer
	| '*' type_qualifier_list
	| '*' pointer
	| '*'
	;
*/
//	NOTE: For the initial pointer, we use a static pointer node! This should cater for 90% of pointers!
union ast_node *create_pointer_node(union ast_node *type_qualifier_list, union ast_node *pointer)
{
	struct ast_pointer_node *node = (struct ast_pointer_node *) malloc(sizeof(struct ast_pointer_node));
	node->type = AST_POINTER;
	node->type_qualifier_list = type_qualifier_list;
	node->pointer = pointer;

	return (union ast_node *) node;
}


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
union ast_node *create_unary_node(int type, union ast_node *expr)
{
	struct ast_unary_node *node = (struct ast_unary_node *) malloc(sizeof(struct ast_unary_node));
	node->type = type;
	node->expr = expr;

	return (union ast_node *) node;
}



/*
conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;
*/
union ast_node *create_ternary_node(union ast_node *cond, union ast_node *true_expr, union ast_node *false_expr)
{
	struct ast_ternary_node *node = (struct ast_ternary_node *) malloc(sizeof(struct ast_ternary_node));
	node->type = AST_TERNARY;
	node->cond = cond;
	node->true_expr = true_expr;
	node->false_expr = false_expr;

	return (union ast_node *) node;
}


/*
cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression			//	AST_CAST
	;
*/
union ast_node *create_cast_node(union ast_node *type_name, union ast_node *expr)
{
	struct ast_cast_node *node = (struct ast_cast_node *) malloc(sizeof(struct ast_cast_node));
	node->type = AST_CAST;
	node->type_name = type_name;
	node->expr = expr;

	return (union ast_node *) node;
}




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
union ast_node *create_generic_selection_node(union ast_node *expr, union ast_node *assoc_list)
{
	struct ast_generic_selection_node *node = (struct ast_generic_selection_node *) malloc(sizeof(struct ast_generic_selection_node));
	node->type = AST_GENERIC_SELECTION;
	node->expr = expr;
	node->assoc_list = assoc_list;

	return (union ast_node *) node;
}
union ast_node *create_generic_assoc_list_node(union ast_node *assoc, union ast_node *assoc_list)
{
	struct ast_generic_assoc_list_node *node = (struct ast_generic_assoc_list_node *) malloc(sizeof(struct ast_generic_assoc_list_node));
	node->type = AST_GENERIC_ASSOC_LIST;
	node->assoc = assoc;
	node->assoc_list = assoc_list;

	return (union ast_node *) node;
}
union ast_node *create_generic_assoc_node(union ast_node *type_name, union ast_node *expr)
{
	struct ast_generic_assoc_node *node = (struct ast_generic_assoc_node *) malloc(sizeof(struct ast_generic_assoc_node));
	node->type = AST_GENERIC_ASSOC;
	node->type_name = type_name;
	node->expr = expr;

	return (union ast_node *) node;
}



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
union ast_node *create_block_node(union ast_node *stmts)
{
	struct ast_block_node *node = (struct ast_block_node *) malloc(sizeof(struct ast_block_node));
	node->type = AST_BLOCK;
	node->stmts = stmts;

	return (union ast_node *) node;
}



/*
selection_statement
	: IF '(' expression ')' statement ELSE statement
	| IF '(' expression ')' statement
	| SWITCH '(' expression ')' statement
	;
*/
union ast_node *create_if_node(union ast_node *cond, union ast_node *if_true, union ast_node *if_false)
{
	struct ast_if_node *node = (struct ast_if_node *) malloc(sizeof(struct ast_if_node));
	node->type = AST_IF;
	node->cond = cond;
	node->if_true = if_true;
	node->if_false = if_false;

	return (union ast_node *) node;
}
union ast_node *create_switch_node(union ast_node *expr, union ast_node *stmt)
{
	struct ast_switch_node *node = (struct ast_switch_node *) malloc(sizeof(struct ast_switch_node));
	node->type = AST_SWITCH;
	node->expr = expr;
	node->stmt = stmt;

	return (union ast_node *) node;
}





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
union ast_node *create_while_node(union ast_node *cond, union ast_node *body)
{
	struct ast_while_node *node = (struct ast_while_node *) malloc(sizeof(struct ast_while_node));
	node->type = AST_WHILE;
	node->cond = cond;
	node->body = body;

	return (union ast_node *) node;
}
union ast_node *create_do_while_node(union ast_node *body, union ast_node *cond)
{
	struct ast_do_while_node *node = (struct ast_do_while_node *) malloc(sizeof(struct ast_do_while_node));
	node->type = AST_DO_WHILE;
	node->body = body;
	node->cond = cond;

	return (union ast_node *) node;
}
union ast_node *create_for_node(union ast_node *init, union ast_node *cond, union ast_node *incr, union ast_node *body)
{
	struct ast_for_node *node = (struct ast_for_node *) malloc(sizeof(struct ast_for_node));
	node->type = AST_FOR;
	node->init = init;
	node->cond = cond;
	node->incr = incr;
	node->body = body;

	return (union ast_node *) node;
}



/*
function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;
*/
union ast_node *create_function_definition_node(union ast_node *decl_specs, union ast_node *declarator, union ast_node *decl_list, union ast_node *block)
{
	struct ast_function_definition_node *node = (struct ast_function_definition_node *) malloc(sizeof(struct ast_function_definition_node));
	node->type = AST_FUNCTION_DEFINITION;
	node->decl_specs = decl_specs;
	node->declarator = declarator;
	node->decl_list = decl_list;
	node->block = block;				//	AKA `body`

	return (union ast_node *) node;
}


union ast_node *create_list_node(union ast_node *node, union ast_node *next, const char *separator)
{
	struct ast_list_node *list = (struct ast_list_node *) malloc(sizeof(struct ast_list_node));
	list->type = AST_LIST;
	list->node = node;
	list->next = next;
	list->separator = separator;

	return (union ast_node *) list;
}



/*
declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	| static_assert_declaration
	;
*/
union ast_node *create_declaration_node(union ast_node *decl_specs, union ast_node *init_declarator_list)
{
	struct ast_declaration_node *node = (struct ast_declaration_node *) malloc(sizeof(struct ast_declaration_node));
	node->type = AST_DECLARATION;
	node->decl_specs = decl_specs;
	node->init_declarator_list = init_declarator_list;

	return (union ast_node *) node;
}


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
union ast_node *create_array_subscript_node(union ast_node *array, union ast_node *index)
{
	struct ast_array_subscript_node *node = (struct ast_array_subscript_node *) malloc(sizeof(struct ast_array_subscript_node));
	node->type = AST_ARRAY_SUBSCRIPT;
	node->array = array;
	node->index = index;

	return (union ast_node *) node;
}
union ast_node *create_function_call_node(union ast_node *function, union ast_node *args)
{
	struct ast_function_call_node *node = (struct ast_function_call_node *) malloc(sizeof(struct ast_function_call_node));
	node->type = AST_FUNCTION_CALL;
	node->function = function;
	node->args = args;

	return (union ast_node *) node;
}
union ast_node *create_member_access_node(int type, union ast_node *object, union ast_node *member)
{
	struct ast_member_access_node *node = (struct ast_member_access_node *) malloc(sizeof(struct ast_member_access_node));
	node->type = type;
	node->object = object;
	node->member = member;

	return (union ast_node *) node;
}
union ast_node *create_compound_literal_node(union ast_node *type_name, union ast_node *init_list)
{
	struct ast_compound_literal_node *node = (struct ast_compound_literal_node *) malloc(sizeof(struct ast_compound_literal_node));
	node->type = AST_COMPOUND_LITERAL;
	node->type_name = type_name;
	node->init_list = init_list;

	return (union ast_node *) node;
}



/*
primary_expression
	: IDENTIFIER
	| constant
	| string
	| '(' expression ')'
	| generic_selection
	;
*/
union ast_node *create_expression_group_node(union ast_node *expr)
{
	struct ast_expression_group_node *node = (struct ast_expression_group_node *) malloc(sizeof(struct ast_expression_group_node));
	node->type = AST_EXPRESSION_GROUP;
	node->expr = expr;

	return (union ast_node *) node;
}



/*
type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
	;
*/
union ast_node *create_abstract_type_name_node(union ast_node *specifier_qualifier_list, union ast_node *abstract_declarator)
{
	struct ast_abstract_type_name_node *node = (struct ast_abstract_type_name_node *) malloc(sizeof(struct ast_abstract_type_name_node));
	node->type = AST_ABSTRACT_TYPE_NAME;
	node->specifier_qualifier_list = specifier_qualifier_list;
	node->abstract_declarator = abstract_declarator;

	return (union ast_node *) node;
}



/*
abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;
*/
union ast_node *create_abstract_declarator_node(union ast_node *pointer, union ast_node *direct_abstract_declarator)
{
	struct ast_abstract_declarator_node *node = (struct ast_abstract_declarator_node *) malloc(sizeof(struct ast_abstract_declarator_node));
	node->type = AST_ABSTRACT_DECLARATOR;
	node->pointer = pointer;
	node->direct_abstract_declarator = direct_abstract_declarator;

	return (union ast_node *) node;
}


/*	
init_declarator
	: declarator '=' initializer
	| declarator
	;
*/
union ast_node *create_init_declarator_node(union ast_node *declarator, union ast_node *initializer)
{
	struct ast_init_declarator_node *node = (struct ast_init_declarator_node *) malloc(sizeof(struct ast_init_declarator_node));
	node->type = AST_INIT_DECLARATOR;
	node->declarator = declarator;
	node->initializer = initializer;

	return (union ast_node *) node;
}


/*
declarator
	: pointer direct_declarator
	| direct_declarator
	;
*/
union ast_node *create_pointer_declarator_node(union ast_node *pointer, union ast_node *direct_declarator)
{
	struct ast_pointer_declarator_node *node = (struct ast_pointer_declarator_node *) malloc(sizeof(struct ast_pointer_declarator_node));
	node->type = AST_POINTER_DECLARATOR;
	node->pointer = pointer;
	node->direct_declarator = direct_declarator;

	return (union ast_node *) node;
}




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
union ast_node *create_grouped_declarator_node(union ast_node *declarator)
{
	struct ast_grouped_declarator_node *node = (struct ast_grouped_declarator_node *) malloc(sizeof(struct ast_grouped_declarator_node));
	node->type = AST_GROUPED_DECLARATOR;
	node->declarator = declarator;

	return (union ast_node *) node;
}
union ast_node *create_unspecified_array_node(union ast_node *direct_declarator, union ast_node *type_qualifier_list)
{
	struct ast_unspecified_array_node *node = (struct ast_unspecified_array_node *) malloc(sizeof(struct ast_unspecified_array_node));
	node->type = AST_UNSPECIFIED_ARRAY;
	node->direct_declarator = direct_declarator;
	node->type_qualifier_list = type_qualifier_list;

	return (union ast_node *) node;
}
union ast_node *create_dynamic_array_node(union ast_node *direct_declarator, union ast_node *type_qualifier_list)
{
	struct ast_dynamic_array_node *node = (struct ast_dynamic_array_node *) malloc(sizeof(struct ast_dynamic_array_node));
	node->type = AST_DYNAMIC_ARRAY;
	node->direct_declarator = direct_declarator;
	node->type_qualifier_list = type_qualifier_list;

	return (union ast_node *) node;
}
union ast_node *create_static_array_node(union ast_node *direct_declarator, union ast_node *type_qualifier_list, union ast_node *expr)
{
	struct ast_static_array_node *node = (struct ast_static_array_node *) malloc(sizeof(struct ast_static_array_node));
	node->type = AST_STATIC_ARRAY;
	node->direct_declarator = direct_declarator;
	node->type_qualifier_list = type_qualifier_list;
	node->expr = expr;

	return (union ast_node *) node;
}
union ast_node *create_array_node(union ast_node *direct_declarator, union ast_node *type_qualifier_list, union ast_node *expr)
{
	struct ast_array_node *node = (struct ast_array_node *) malloc(sizeof(struct ast_array_node));
	node->type = AST_ARRAY;
	node->direct_declarator = direct_declarator;
	node->type_qualifier_list = type_qualifier_list;
	node->expr = expr;

	return (union ast_node *) node;
}
union ast_node *create_function_declarator_node(union ast_node *direct_declarator, union ast_node *params, union ast_node *identifier_list)
{
	struct ast_function_declarator_node *node = (struct ast_function_declarator_node *) malloc(sizeof(struct ast_function_declarator_node));
	node->type = AST_FUNCTION_DECLARATOR;
	node->direct_declarator = direct_declarator;
	node->params = params;
	node->identifier_list = identifier_list;

	return (union ast_node *) node;
}


/*
parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;
*/
union ast_node *create_parameter_declaration_node(union ast_node *decl_specs, union ast_node *declarator)
{
	struct ast_parameter_declaration_node *node = (struct ast_parameter_declaration_node *) malloc(sizeof(struct ast_parameter_declaration_node));
	node->type = AST_PARAMETER_DECLARATION;
	node->decl_specs = decl_specs;
	node->declarator = declarator;

	return (union ast_node *) node;
}



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
union ast_node *create_initializer_node(union ast_node *list)
{
	struct ast_initializer_node *node = (struct ast_initializer_node *) malloc(sizeof(struct ast_initializer_node));
	node->type = AST_INITIALIZER;
	node->list = list;

	return (union ast_node *) node;
}
union ast_node *create_designation_initializer_node(union ast_node *designation, union ast_node *initializer)
{
	struct ast_designation_initializer_node *node = (struct ast_designation_initializer_node *) malloc(sizeof(struct ast_designation_initializer_node));
	node->type = AST_DESIGNATION_INITIALIZER;
	node->designation = designation;
	node->initializer = initializer;

	return (union ast_node *) node;
}
union ast_node *create_designator_node(union ast_node *expr, union ast_node *id)
{
	struct ast_designator_node *node = (struct ast_designator_node *) malloc(sizeof(struct ast_designator_node));
	node->type = AST_DESIGNATOR;
	node->expr = expr;
	node->id = id;

	return (union ast_node *) node;
}


/*
static_assert_declaration
	: _STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	| _STATIC_ASSERT '(' constant_expression ')' ';'
	| STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
	| STATIC_ASSERT '(' constant_expression ')' ';'
	;
*/
union ast_node *create_static_assert_node(int type, union ast_node *expr, union ast_node *str)
{
	struct ast_static_assert_node *node = (struct ast_static_assert_node *) malloc(sizeof(struct ast_static_assert_node));
	node->type = type;
	node->expr = expr;
	node->str = str;

	return (union ast_node *) node;
}



/******************************************************************************
 *
 *						Super C classes, interfaces, traits, mixins
 *
 */

union ast_node *create_class_node(int type, union ast_node *id, union ast_node *modifiers, union ast_node *extends, union ast_node *implements, union ast_node *body)
{
	struct ast_class_node *node = (struct ast_class_node *) malloc(sizeof(struct ast_class_node));
	node->type = type;
	node->id = id;
	node->modifiers = modifiers;
	node->extends = extends;
	node->implements = implements;
	node->body = body;

	return (union ast_node *) node;
}

union ast_node *create_class_declaration_node(int type, union ast_node *id, union ast_node *modifiers)
{
	struct ast_class_declaration_node *node = (struct ast_class_declaration_node *) malloc(sizeof(struct ast_class_declaration_node));
	node->type = type;
	node->id = id;
	node->modifiers = modifiers;

	return (union ast_node *) node;
}

union ast_node *create_impl_node(union ast_node *id, union ast_node *interface, union ast_node *body)
{
	struct ast_impl_node *node = (struct ast_impl_node *) malloc(sizeof(struct ast_impl_node));
	node->type = AST_IMPL;
	node->id = id;
	node->interface = interface;
	node->body = body;

	return (union ast_node *) node;
}
union ast_node *create_static_impl_node(union ast_node *id, union ast_node *body)
{
	struct ast_impl_node *node = (struct ast_impl_node *) malloc(sizeof(struct ast_impl_node));
	node->type = AST_STATIC_IMPL;
	node->id = id;
	node->interface = NULL;
	node->body = body;

	return (union ast_node *) node;
}


union ast_node *create_static_impl_node(union ast_node *id, union ast_node *body);




// union ast_node *create_new_node(union ast_node *id, union ast_node *parameter_list)
// {
// 	struct ast_new_node *node = (struct ast_new_node *) malloc(sizeof(struct ast_new_node));
// 	node->type = AST_NEW;
// 	node->id = id;
// 	node->parameter_list = parameter_list;

// 	return (union ast_node *) node;
// }
// union ast_node *create_delete_node(union ast_node *id, union ast_node *expr)
// {
// 	struct ast_delete_node *node = (struct ast_delete_node *) malloc(sizeof(struct ast_delete_node));
// 	node->type = AST_DELETE;
// 	node->id = id;
// 	node->expr = expr;

// 	return (union ast_node *) node;
// }


union ast_node *create_new_function_definition_node(union ast_node *decl_specs, union ast_node *declarator, union ast_node *block)
{
	struct ast_function_definition_node *node = (struct ast_function_definition_node *) malloc(sizeof(struct ast_function_definition_node));
	node->type = AST_IMPL_NEW_FUNCTION;							// Changed to normal function type (AST_FUNCTION_DEFINITION) during "impl" processing
	node->decl_specs = decl_specs;
	node->declarator = declarator;
	node->decl_list = NULL;
	node->block = block;

	return (union ast_node *) node;
}

union ast_node *create_new_function_declarator_node(union ast_node *pointer, union ast_node *params)
{
	struct ast_pointer_declarator_node *node = (struct ast_pointer_declarator_node *) malloc(sizeof(struct ast_pointer_declarator_node));
	node->type = AST_IMPL_NEW_DECLARATOR;
	node->pointer = pointer;
	node->direct_declarator = create_function_declarator_node(NULL, params, NULL);
	// NOTE:                                        This NULL ^^^^ will be replaced by the new function name, eg. "Foo__new"

	return (union ast_node *) node;
}

//	NOTE: The "new operator" is replaced immediately during parsing, and the result is added directly to the AST tree.
//	Because it doesn't require a lookup to get a TYPEDEF name from a variable name, it already includes the TYPEDEF name, eg. "new Foo()" is replaced by "Foo__new()".

union ast_node *create_delete_function_definition_node(union ast_node *decl_specs, union ast_node *declarator, union ast_node *block)
{
	struct ast_function_definition_node *node = (struct ast_function_definition_node *) malloc(sizeof(struct ast_function_definition_node));
	node->type = AST_IMPL_DELETE_FUNCTION;							// Changed to normal function type (AST_FUNCTION_DEFINITION) during "impl" processing
	node->decl_specs = decl_specs;
	node->declarator = declarator;
	node->decl_list = NULL;
	node->block = block;

	return (union ast_node *) node;
}

union ast_node *create_delete_operator_node(union ast_node *obj)
{
	struct ast_function_call_node *node = (struct ast_function_call_node *) malloc(sizeof(struct ast_function_call_node));
	node->type = AST_DELETE_OPERATOR;	//	Changed to normal function call type (AST_FUNCTION_CALL) during "impl" processing
	node->function= NULL;				//	This will be replaced by the new "delete" function name, eg. "Foo__delete"
	node->args = obj;					//	This is the object to be deleted, we pass it as the first argument to the delete function

	return (union ast_node *) node;
}






union ast_node *create_getter_node(union ast_node *decl_specs, union ast_node *declarator, union ast_node *block)
{
	struct ast_function_definition_node *node = (struct ast_function_definition_node *) malloc(sizeof(struct ast_function_definition_node));
	node->type = AST_GETTER;
	node->decl_specs = decl_specs;
	node->declarator = declarator;
	node->decl_list = NULL;
	node->block = block;

	return (union ast_node *) node;
}
union ast_node *create_setter_node(union ast_node *decl_specs, union ast_node *declarator, union ast_node *block)
{
	struct ast_function_definition_node *node = (struct ast_function_definition_node *) malloc(sizeof(struct ast_function_definition_node));
	node->type = AST_SETTER;
	node->decl_specs = decl_specs;
	node->declarator = declarator;
	node->decl_list = NULL;
	node->block = block;

	return (union ast_node *) node;
}
union ast_node *create_getter_or_setter_node(int type, union ast_node *decl_specs, union ast_node *declarator, union ast_node *block)
{
	struct ast_function_definition_node *node = (struct ast_function_definition_node *) malloc(sizeof(struct ast_function_definition_node));
	node->type = type;
	node->decl_specs = decl_specs;
	node->declarator = declarator;
	node->decl_list = NULL;
	node->block = block;

	return (union ast_node *) node;
}

/*
union ast_node *create_impl_function_declaration_node(union ast_node *decl_specs, union ast_node *declarator)
{
	struct ast_function_definition_node *node = (struct ast_function_definition_node *) malloc(sizeof(struct ast_function_definition_node));
	node->type = AST_IMPL_FUNCTION_DECLARATION;
	node->decl_specs = decl_specs;
	node->declarator = declarator;
	node->decl_list = NULL;
	node->block = NULL;

	return (union ast_node *) node;
}
*/



// struct ast_pointer_declarator_node {
// 	int type;									//	AST_POINTER_DECLARATOR
// 	union ast_node *pointer;
// 	union ast_node *direct_declarator;
// };







// ----------------
union ast_node *create_tmp_node()
{
	static struct ast_type_node tmp_node = { AST_DUMMY };

	return (union ast_node *) & tmp_node;
}

