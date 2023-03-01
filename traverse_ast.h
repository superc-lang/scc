#pragma once

#include "ast.h"

/**
 * Due to the nature of the jump table callback being recursive,
 * we need to forward declare the traversal_jump_table_t struct.
 * (Could have been any struct, but it must be a forward declanation)
 * This is because the traversal_jump_table_t struct contains a pointer essentially to itself.
 * The `jump_table` parameter in the traversal_callback_t function, is a pointer to the same typedef `traversal_callback_t`.
 * And since you can't have typedefs of typedefs, we need to forward declare the struct.
 */
typedef struct traversal_jump_table traversal_jump_table_t;
typedef void (*traversal_callback_t)(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
struct traversal_jump_table {
    traversal_callback_t function;
};

void init_traversal_jump_table(traversal_jump_table_t *jump_table);
void traverse_ast(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);


/**
 * By `exposing` these, we allow you to call them after handling a node type.
 * If you need to handle more node types, just add them here!
 */
void traverse_no_op_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_list_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
