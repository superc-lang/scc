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
void traverse_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);


// ****************************************************************************
//	no-op node
// ****************************************************************************

void traverse_no_op_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

// ****************************************************************************
//	list node
// ****************************************************************************

void traverse_list_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

// ****************************************************************************
//	Super C extension nodes
// ****************************************************************************

void traverse_impl_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_generic_type_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

// ****************************************************************************
//	unary nodes
// ****************************************************************************

void traverse_unary_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

//	Should be unary!
void traverse_initializer_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_default_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_goto_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_return_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_atomic_type_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_block_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_grouped_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

// ****************************************************************************
//	binary nodes
// ****************************************************************************

void traverse_binary_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

//	Should be binary nodes!
void traverse_cast_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_array_subscript_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_function_call_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_member_access_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_compound_literal_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_designation_initializer_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_designator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_label_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_case_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_switch_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_while_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_do_while_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_static_assert_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_struct_or_union_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_struct_or_union_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_struct_or_union_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_enum_type_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_pointer_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_pointer_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_parameter_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_init_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_abstract_type_name_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_abstract_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_unspecified_array_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_dynamic_array_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

// ****************************************************************************
//	ternary nodes
// ****************************************************************************

void traverse_ternary_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_if_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_array_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_function_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);


// ****************************************************************************
//	quad nodes
// ****************************************************************************

void traverse_for_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_function_definition_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void traverse_unsupported_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
