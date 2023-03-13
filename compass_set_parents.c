#include "compass_set_parents.h"
#include "traverse_ast.h"

#include <assert.h>

void handle_list_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

void handle_impl_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

void handle_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_function_definition_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_block_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

void handle_generic_type_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

void handle_struct_or_union_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_struct_or_union_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_struct_or_union_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

void handle_if_statement_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_switch_statement_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_while_loop_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_do_while_loop_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_for_loop_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

void handle_abstract_type_name_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

void set_parent_nodes(union ast_node *root_node)
{
	static traversal_jump_table_t jump_table[AST__LAST__] = { 0 };

	init_traversal_jump_table(jump_table);

	jump_table[AST_LIST].function = handle_list_node;

	jump_table[AST_IMPL].function = handle_impl_node;
	jump_table[AST_STATIC_IMPL].function = handle_impl_node;
	jump_table[AST_GENERIC_IMPL].function = handle_impl_node;
	jump_table[AST_GENERIC_STATIC_IMPL].function = handle_impl_node;

	jump_table[AST_DECLARATION].function = handle_declaration_node;
	jump_table[AST_FUNCTION_DEFINITION].function = handle_function_definition_node;
	jump_table[AST_BLOCK].function = handle_block_node;

	jump_table[AST_GENERIC_DECLARATION].function = handle_generic_type_node;
	jump_table[AST_GENERIC_SPECIFIER].function = handle_generic_type_node;

	jump_table[AST_GENERIC_STRUCT].function = handle_struct_or_union_node;
	jump_table[AST_GENERIC_UNION].function = handle_struct_or_union_node;
	jump_table[AST_STRUCT].function = handle_struct_or_union_node;
	jump_table[AST_UNION].function = handle_struct_or_union_node;

	jump_table[AST_STRUCT_OR_UNION_DECLARATION].function = handle_struct_or_union_declaration_node;
	jump_table[AST_STRUCT_OR_UNION_DECLARATOR].function = handle_struct_or_union_declarator_node;

	jump_table[AST_IF].function = handle_if_statement_node;
	jump_table[AST_SWITCH].function = handle_switch_statement_node;
	jump_table[AST_WHILE].function = handle_while_loop_node;
	jump_table[AST_DO_WHILE].function = handle_do_while_loop_node;
	jump_table[AST_FOR].function = handle_for_loop_node;

	jump_table[AST_ABSTRACT_TYPE_NAME].function = handle_abstract_type_name_node;

	traverse_ast(root_node, NULL, jump_table);
}

void handle_list_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->list.parent = parent;

	traverse_list_node(node, parent, jump_table);
}

void handle_impl_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->impl.parent = parent;

	traverse_impl_node(node, parent, jump_table);
}

void handle_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->declaration.parent = parent;

	traverse_declaration_node(node, parent, jump_table);
}

void handle_function_definition_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->function_definition.parent = parent;

	traverse_function_definition_node(node, parent, jump_table);
}

void handle_block_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->block.parent = parent;

	traverse_block_node(node, parent, jump_table);
}

void handle_generic_type_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->generic_type.parent = parent;

	traverse_generic_type_node(node, parent, jump_table);
}

void handle_struct_or_union_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->struct_or_union.parent = parent;

	traverse_struct_or_union_node(node, parent, jump_table);
}

void handle_struct_or_union_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->struct_or_union_declaration.parent = parent;

	traverse_struct_or_union_declaration_node(node, parent, jump_table);
}

void handle_struct_or_union_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->struct_or_union_declarator.parent = parent;

	traverse_struct_or_union_declarator_node(node, parent, jump_table);
}

void handle_if_statement_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->if_stmt.parent = parent;

	traverse_if_stmt_node(node, parent, jump_table);
}

void handle_switch_statement_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->switch_stmt.parent = parent;

	traverse_switch_stmt_node(node, parent, jump_table);
}

void handle_while_loop_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->while_stmt.parent = parent;

	traverse_while_stmt_node(node, parent, jump_table);
}

void handle_do_while_loop_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->do_while_stmt.parent = parent;

	traverse_do_while_stmt_node(node, parent, jump_table);
}

void handle_for_loop_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->for_stmt.parent = parent;

	traverse_for_stmt_node(node, parent, jump_table);
}

void handle_abstract_type_name_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	node->abstract_type_name.parent = parent;

	traverse_abstract_type_name_node(node, parent, jump_table);
}
