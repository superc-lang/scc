#include "traverse_ast.h"

#include <stdio.h>
#include <assert.h>

// ****************************************************************************
// ****************************************************************************
//	AST Traversal
// ****************************************************************************
// ****************************************************************************

/**
 * These are not ALL the methods that can traverse the AST,
 * these are a specific 'category' of methods used by the compiler passes only.
 * Some of the other traversal methods are in the 'ast_helpers' file or scattered around.
 * 
 * First call `init_jump_table()` to initialize the jump table.
 * This only needs to be done once!
 * It essentially associates a traversal method (function) with each node type.
 * It would have been better to initialize the jump table statically,
 * but that would impact my ability to add/remove node types.
 * 
 * Warning: The `jump_table` parameter should always be an array of `AST__LAST__` size.
 * 
 * The one limitation I have on this, is to `limit` the traversal to specific node types.
 * And also to stop the traversal at a specific node type or point that I can control.
 * So for example, the `process_impl` which handles `impl` nodes,
 *		only needs to traverse root nodes, and not the entire AST.
 * How do I limit the traversal along only the `AST_LIST` nodes at root level?
 * I can extend or enhance this, but that could impact performance.
 */

// static void (*jump_table[AST__LAST__])(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

/**
 * @brief Traverse the AST, calling the appropriate callback function for each node type
 * @param node The current node
 * @param parent The parent node
 * @param jump_table The jump table of callback functions
 */
void traverse_ast(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node == NULL) return;

	traverse_node(node, parent, jump_table);
}

void traverse_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	jump_table[node->type].function(node, parent, jump_table);
}


// ****************************************************************************
//	terminal/general/no-op nodes
// ****************************************************************************

//	This is essentially like a 'terminal' point. It has no child nodes, so it's effectively a no-op!
//	ie. Doesn't need to traverse any further!
void traverse_no_op_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	//	no-op
}


//	NOTE: This is OLD! I'm keeping it for reference!
/**
 *	This is an idea (not implemented yet, but did some basic tests),
 *		where I use a 'dummy' no-op callback, so I don't need to check for NULL pointers!
 *	I would need to benchmark this to see if it's faster than just checking for NULL pointers!
 *	I suspect it would be faster, because I avoid a branch instruction! The method just has a `ret` in it (confirmed).
 *	I'm 50/50 on using this. Use either this method or fill it with NULL's!
 *	NULL's will help us to avoid additional return type checks.
 *	It replaces a `test r,r` and `je .Label` with `call m; ret;` instructions.
 *  Although, even on newer architecture (like Zen 3), `call` is 6 cycles, `ret` is 2 cycles.
 *  	Whereas `test` and `je` are 1 cycle each. Also, the `call` with a register is 2 cycles instead of 6 with memory.
 *  On Haswell, the `call` with memory is 3 cycles, `call` with register is 2 cycles. `ret` is 1 cycle.
 * 		Conditional jumps are 1 cycle, `test` is also 1 cycle.
 *  I guess the biggest difference will come down to branch mispredictions.
 * 		Even if I benchmark this, it would still be architecture dependent.
 * 	So for now, I favor simpler code, readability, and maintainability.
 *  Adding this requires me to loop through the jump table, and set the function pointers to `no_op`.
 *  However, it requires more code in the `traverse_ast` functions to test for NULL in EVERY function!
 *  So I'm still undecided!
 *
 *   movsx rax, DWORD PTR [rdi]
 *   call [QWORD PTR [rdx+rax*8]]
 * 
 *   vs.
 * 
 *   movsx rax, DWORD PTR [rdi]
 *   mov rax, QWORD PTR [rdx+rax*8]
 *   test rax, rax
 *   je .Location
 *   call rax
 */
// void traverse_no_op_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table) { /* no-op */ }


// ****************************************************************************
//	list node
// ****************************************************************************

void traverse_list_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	assert(node->list.node != NULL);
	assert(node->list.next != NULL);

	jump_table[node->list.node->type].function(node->list.node, node, jump_table);
	jump_table[node->list.next->type].function(node->list.next, node, jump_table);
}


// ****************************************************************************
//	Super C extension nodes
// ****************************************************************************

void traverse_impl_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	assert(node->impl.id != NULL);

	jump_table[node->impl.id->type].function(node->impl.id, node, jump_table);

	if (node->impl.interface) {
		jump_table[node->impl.interface->type].function(node->impl.interface, node, jump_table);
	}
	if (node->impl.body) {
		jump_table[node->impl.body->type].function(node->impl.body, node, jump_table);
	}
}

void traverse_generic_type_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	assert(node->generic_type.id != NULL);

	jump_table[node->generic_type.id->type].function(node->generic_type.id, node, jump_table);

	if (node->generic_type.type_list) {
		jump_table[node->generic_type.type_list->type].function(node->generic_type.type_list, node, jump_table);
	}
}



// ****************************************************************************
//	unary nodes
// ****************************************************************************

void traverse_unary_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	assert(node->unary.expr != NULL);	//	Can a `unary` node NOT have an expression? I guess we'll find out!

	// if (node->unary.expr) {
		jump_table[node->unary.expr->type].function(node->unary.expr, node, jump_table);
	// }
}

//	Should be unary!
void traverse_initializer_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->initializer.list) {
		jump_table[node->initializer.list->type].function(node->initializer.list, node, jump_table);
	}
}

void traverse_default_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->default_stmt.stmt) {
		jump_table[node->default_stmt.stmt->type].function(node->default_stmt.stmt, node, jump_table);
	}
}

void traverse_goto_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	assert(node->goto_stmt.id != NULL);

	jump_table[node->goto_stmt.id->type].function(node->goto_stmt.id, node, jump_table);
}

void traverse_return_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	// assert(node->return_stmt.expr != NULL);

	if (node->return_stmt.expr) {
		jump_table[node->return_stmt.expr->type].function(node->return_stmt.expr, node, jump_table);
	}
}

void traverse_atomic_type_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->atomic_type.type_name) {
		jump_table[node->atomic_type.type_name->type].function(node->atomic_type.type_name, node, jump_table);
	}
}

void traverse_block_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->block.stmts) {
		jump_table[node->block.stmts->type].function(node->block.stmts, node, jump_table);
	}
}

void traverse_grouped_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->grouped_declarator.declarator) {
		jump_table[node->grouped_declarator.declarator->type].function(node->grouped_declarator.declarator, node, jump_table);
	}
}


// ****************************************************************************
//	binary nodes
// ****************************************************************************

void traverse_binary_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->binary.left) {
		jump_table[node->binary.left->type].function(node->binary.left, node, jump_table);
	}
	if (node->binary.right) {
		jump_table[node->binary.right->type].function(node->binary.right, node, jump_table);
	}
}


//	Should be binary nodes!
void traverse_cast_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->cast.type_name) {
		jump_table[node->cast.type_name->type].function(node->cast.type_name, node, jump_table);
	}
	if (node->cast.expr) {
		jump_table[node->cast.expr->type].function(node->cast.expr, node, jump_table);
	}
}

void traverse_array_subscript_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->array_subscript.array) {
		jump_table[node->array_subscript.array->type].function(node->array_subscript.array, node, jump_table);
	}
	if (node->array_subscript.index) {
		jump_table[node->array_subscript.index->type].function(node->array_subscript.index, node, jump_table);
	}
}

void traverse_function_call_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->function_call.function) {
		jump_table[node->function_call.function->type].function(node->function_call.function, node, jump_table);
	}
	if (node->function_call.args) {
		jump_table[node->function_call.args->type].function(node->function_call.args, node, jump_table);
	}
}

void traverse_member_access_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->member_access.object) {
		jump_table[node->member_access.object->type].function(node->member_access.object, node, jump_table);
	}
	if (node->member_access.member) {
		jump_table[node->member_access.member->type].function(node->member_access.member, node, jump_table);
	}
}

void traverse_compound_literal_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->compound_literal.type_name) {
		jump_table[node->compound_literal.type_name->type].function(node->compound_literal.type_name, node, jump_table);
	}
	if (node->compound_literal.init_list) {
		jump_table[node->compound_literal.init_list->type].function(node->compound_literal.init_list, node, jump_table);
	}
}

void traverse_designation_initializer_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->designation_initializer.designation) {
		jump_table[node->designation_initializer.designation->type].function(node->designation_initializer.designation, node, jump_table);
	}
	if (node->designation_initializer.initializer) {
		jump_table[node->designation_initializer.initializer->type].function(node->designation_initializer.initializer, node, jump_table);
	}
}

void traverse_designator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->designator.id) {
		jump_table[node->designator.id->type].function(node->designator.id, node, jump_table);
	}
	if (node->designator.expr) {
		jump_table[node->designator.expr->type].function(node->designator.expr, node, jump_table);
	}
}

void traverse_label_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->label.id) {
		jump_table[node->label.id->type].function(node->label.id, node, jump_table);
	}
	if (node->label.stmt) {
		jump_table[node->label.stmt->type].function(node->label.stmt, node, jump_table);
	}
}

void traverse_case_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->case_stmt.expr) {
		jump_table[node->case_stmt.expr->type].function(node->case_stmt.expr, node, jump_table);
	}
	if (node->case_stmt.stmt) {
		jump_table[node->case_stmt.stmt->type].function(node->case_stmt.stmt, node, jump_table);
	}
}

void traverse_switch_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->switch_stmt.expr) {
		jump_table[node->switch_stmt.expr->type].function(node->switch_stmt.expr, node, jump_table);
	}
	if (node->switch_stmt.stmt) {
		jump_table[node->switch_stmt.stmt->type].function(node->switch_stmt.stmt, node, jump_table);
	}
}

void traverse_while_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->while_stmt.cond) {
		jump_table[node->while_stmt.cond->type].function(node->while_stmt.cond, node, jump_table);
	}
	if (node->while_stmt.body) {
		jump_table[node->while_stmt.body->type].function(node->while_stmt.body, node, jump_table);
	}
}

void traverse_do_while_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->do_while_stmt.body) {
		jump_table[node->do_while_stmt.body->type].function(node->do_while_stmt.body, node, jump_table);
	}
	if (node->do_while_stmt.cond) {
		jump_table[node->do_while_stmt.cond->type].function(node->do_while_stmt.cond, node, jump_table);
	}
}

void traverse_static_assert_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->static_assert_stmt.expr) {
		jump_table[node->static_assert_stmt.expr->type].function(node->static_assert_stmt.expr, node, jump_table);
	}
	if (node->static_assert_stmt.str) {
		jump_table[node->static_assert_stmt.str->type].function(node->static_assert_stmt.str, node, jump_table);
	}
}

void traverse_struct_or_union_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->struct_or_union.id) {
		jump_table[node->struct_or_union.id->type].function(node->struct_or_union.id, node, jump_table);
	}
	if (node->struct_or_union.decl_list) {
		jump_table[node->struct_or_union.decl_list->type].function(node->struct_or_union.decl_list, node, jump_table);
	}
}

void traverse_struct_or_union_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->struct_or_union_declaration.spec_qual_list) {
		jump_table[node->struct_or_union_declaration.spec_qual_list->type].function(node->struct_or_union_declaration.spec_qual_list, node, jump_table);
	}
	if (node->struct_or_union_declaration.decl_list) {
		jump_table[node->struct_or_union_declaration.decl_list->type].function(node->struct_or_union_declaration.decl_list, node, jump_table);
	}
}

void traverse_struct_or_union_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->struct_or_union_declarator.declarator) {
		jump_table[node->struct_or_union_declarator.declarator->type].function(node->struct_or_union_declarator.declarator, node, jump_table);
	}
	if (node->struct_or_union_declarator.expr) {
		jump_table[node->struct_or_union_declarator.expr->type].function(node->struct_or_union_declarator.expr, node, jump_table);
	}
}

void traverse_enum_type_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->enum_type.id) {
		jump_table[node->enum_type.id->type].function(node->enum_type.id, node, jump_table);
	}
	if (node->enum_type.list) {
		jump_table[node->enum_type.list->type].function(node->enum_type.list, node, jump_table);
	}
}

void traverse_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->declaration.decl_specs) {
		jump_table[node->declaration.decl_specs->type].function(node->declaration.decl_specs, node, jump_table);
	}
	if (node->declaration.init_declarator_list) {
		jump_table[node->declaration.init_declarator_list->type].function(node->declaration.init_declarator_list, node, jump_table);
	}
}

void traverse_pointer_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->pointer_declarator.pointer) {
		jump_table[node->pointer_declarator.pointer->type].function(node->pointer_declarator.pointer, node, jump_table);
	}
	if (node->pointer_declarator.direct_declarator) {
		jump_table[node->pointer_declarator.direct_declarator->type].function(node->pointer_declarator.direct_declarator, node, jump_table);
	}
}

void traverse_pointer_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->pointer.type_qualifier_list) {
		jump_table[node->pointer.type_qualifier_list->type].function(node->pointer.type_qualifier_list, node, jump_table);
	}
	if (node->pointer.pointer) {
		jump_table[node->pointer.pointer->type].function(node->pointer.pointer, node, jump_table);
	}
}

void traverse_parameter_declaration_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->parameter_declaration.decl_specs) {
		jump_table[node->parameter_declaration.decl_specs->type].function(node->parameter_declaration.decl_specs, node, jump_table);
	}
	if (node->parameter_declaration.declarator) {
		jump_table[node->parameter_declaration.declarator->type].function(node->parameter_declaration.declarator, node, jump_table);
	}
}

void traverse_init_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->init_declarator.declarator) {
		jump_table[node->init_declarator.declarator->type].function(node->init_declarator.declarator, node, jump_table);
	}
	if (node->init_declarator.initializer) {
		jump_table[node->init_declarator.initializer->type].function(node->init_declarator.initializer, node, jump_table);
	}
}

void traverse_abstract_type_name_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->abstract_type_name.specifier_qualifier_list) {
		jump_table[node->abstract_type_name.specifier_qualifier_list->type].function(node->abstract_type_name.specifier_qualifier_list, node, jump_table);
	}
	if (node->abstract_type_name.abstract_declarator) {
		jump_table[node->abstract_type_name.abstract_declarator->type].function(node->abstract_type_name.abstract_declarator, node, jump_table);
	}
}

void traverse_abstract_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->abstract_declarator.pointer) {
		jump_table[node->abstract_declarator.pointer->type].function(node->abstract_declarator.pointer, node, jump_table);
	}
	if (node->abstract_declarator.direct_abstract_declarator) {
		jump_table[node->abstract_declarator.direct_abstract_declarator->type].function(node->abstract_declarator.direct_abstract_declarator, node, jump_table);
	}
}

void traverse_unspecified_array_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->unspecified_array.direct_declarator) {
		jump_table[node->unspecified_array.direct_declarator->type].function(node->unspecified_array.direct_declarator, node, jump_table);
	}
	if (node->unspecified_array.type_qualifier_list) {
		jump_table[node->unspecified_array.type_qualifier_list->type].function(node->unspecified_array.type_qualifier_list, node, jump_table);
	}
}

void traverse_dynamic_array_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->dynamic_array.direct_declarator) {
		jump_table[node->dynamic_array.direct_declarator->type].function(node->dynamic_array.direct_declarator, node, jump_table);
	}
	if (node->dynamic_array.type_qualifier_list) {
		jump_table[node->dynamic_array.type_qualifier_list->type].function(node->dynamic_array.type_qualifier_list, node, jump_table);
	}
}



// ****************************************************************************
//	ternary nodes
// ****************************************************************************

void traverse_ternary_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	assert(node->ternary.cond != NULL);
	assert(node->ternary.true_expr != NULL);
	assert(node->ternary.false_expr != NULL);

	jump_table[node->ternary.cond->type].function(node->ternary.cond, node, jump_table);
	jump_table[node->ternary.true_expr->type].function(node->ternary.true_expr, node, jump_table);
	jump_table[node->ternary.false_expr->type].function(node->ternary.false_expr, node, jump_table);
}

//	Should be ternary nodes ... `if` statement can't really be, because then we would need to do a test on the `false_expr` in ternary nodes, which is not required for `ternary` statements.
void traverse_if_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	assert(node->if_stmt.cond != NULL);
	assert(node->if_stmt.if_true != NULL);

	jump_table[node->if_stmt.cond->type].function(node->if_stmt.cond, node, jump_table);
	jump_table[node->if_stmt.if_true->type].function(node->if_stmt.if_true, node, jump_table);

	if (node->if_stmt.if_false) {
		jump_table[node->if_stmt.if_false->type].function(node->if_stmt.if_false, node, jump_table);
	}
}

//	We MUST check all params, check `direct_abstract_declarator` for instances where even the `direct_declarator` is NULL.
void traverse_array_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->array.direct_declarator) {
		jump_table[node->array.direct_declarator->type].function(node->array.direct_declarator, node, jump_table);
	}
	if (node->array.type_qualifier_list) {
		jump_table[node->array.type_qualifier_list->type].function(node->array.type_qualifier_list, node, jump_table);
	}
	if (node->array.expr) {
		jump_table[node->array.expr->type].function(node->array.expr, node, jump_table);
	}
}

//	Unfortunately, we MUST check even the `direct_declarator`, because they are not used in function pointers! Check `direct_abstract_declarator` for confirmation.
void traverse_function_declarator_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->function_declarator.direct_declarator) {
		jump_table[node->function_declarator.direct_declarator->type].function(node->function_declarator.direct_declarator, node, jump_table);
	}
	if (node->function_declarator.params) {
		jump_table[node->function_declarator.params->type].function(node->function_declarator.params, node, jump_table);
	}
	if (node->function_declarator.identifier_list) {
		jump_table[node->function_declarator.identifier_list->type].function(node->function_declarator.identifier_list, node, jump_table);
	}
}


// ****************************************************************************
//	quad nodes
// ****************************************************************************

void traverse_for_stmt_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->for_stmt.init) {
		jump_table[node->for_stmt.init->type].function(node->for_stmt.init, node, jump_table);
	}
	if (node->for_stmt.cond) {
		jump_table[node->for_stmt.cond->type].function(node->for_stmt.cond, node, jump_table);
	}
	if (node->for_stmt.incr) {
		jump_table[node->for_stmt.incr->type].function(node->for_stmt.incr, node, jump_table);
	}
	if (node->for_stmt.body) {
		jump_table[node->for_stmt.body->type].function(node->for_stmt.body, node, jump_table);
	}
}

void traverse_function_definition_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->function_definition.decl_specs) {
		jump_table[node->function_definition.decl_specs->type].function(node->function_definition.decl_specs, node, jump_table);
	}
	if (node->function_definition.declarator) {
		jump_table[node->function_definition.declarator->type].function(node->function_definition.declarator, node, jump_table);
	}
	if (node->function_definition.decl_list) {
		jump_table[node->function_definition.decl_list->type].function(node->function_definition.decl_list, node, jump_table);
	}
	if (node->function_definition.block) {
		jump_table[node->function_definition.block->type].function(node->function_definition.block, node, jump_table);
	}
}


void traverse_unsupported_node(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	fprintf(stderr, "AST TRAVERSAL ERROR: Error trying to traverse unknown or unsupported node type %d detected\n", node->type);
	exit(EXIT_FAILURE);
}


void init_traversal_jump_table(traversal_jump_table_t *jump_table)
{
	for (int i = 0; i < AST__LAST__; i++) {
		jump_table[i].function = traverse_unsupported_node;
	}

	// ************************************************************************
	//	list nodes
	// ************************************************************************
	jump_table[AST_LIST].function = traverse_list_node;


	// ************************************************************************
	//	Super C extension nodes
	// ************************************************************************

	jump_table[AST_THIS].function = traverse_no_op_node;
	jump_table[AST_SELF].function = traverse_no_op_node;

	jump_table[AST_IMPL].function = traverse_impl_node;
	jump_table[AST_STATIC_IMPL].function = traverse_impl_node;
	jump_table[AST_GENERIC_IMPL].function = traverse_impl_node;
	jump_table[AST_GENERIC_STATIC_IMPL].function = traverse_impl_node;

	jump_table[AST_NS_OP].function = traverse_binary_node;
	jump_table[AST_DELETE_OPERATOR].function = traverse_function_call_node;

	jump_table[AST_GENERIC_DECLARATION].function = traverse_generic_type_node;
	jump_table[AST_GENERIC_SPECIFIER].function = traverse_generic_type_node;

	jump_table[AST_GENERIC_STRUCT].function = traverse_struct_or_union_node;
	jump_table[AST_GENERIC_UNION].function = traverse_struct_or_union_node;
	jump_table[AST_GENERIC_LIST].function = traverse_list_node;

	jump_table[AST_IMPL_NEW_FUNCTION].function = traverse_function_definition_node;
	jump_table[AST_IMPL_NEW_DECLARATOR].function = traverse_pointer_declarator_node;
	jump_table[AST_IMPL_DELETE_FUNCTION].function = traverse_function_definition_node;
	jump_table[AST_IMPL_FUNCTION_DECLARATION].function = traverse_function_definition_node;

	jump_table[AST_GETTER].function = traverse_function_definition_node;
	jump_table[AST_SETTER].function = traverse_function_definition_node;



	// ************************************************************************
	//	unary nodes
	// ************************************************************************
	jump_table[AST_PRE_INC].function = traverse_unary_node;
	jump_table[AST_PRE_DEC].function = traverse_unary_node;
	jump_table[AST_SIZEOF_EXPR].function = traverse_unary_node;
	jump_table[AST_SIZEOF_TYPE].function = traverse_unary_node;
	jump_table[AST_ALIGNOF].function = traverse_unary_node;
	jump_table[AST_ADDRESS_OF].function = traverse_unary_node;
	jump_table[AST_DEREFERENCE].function = traverse_unary_node;
	jump_table[AST_POSITIVE].function = traverse_unary_node;
	jump_table[AST_NEGATIVE].function = traverse_unary_node;
	jump_table[AST_BITWISE_NOT].function = traverse_unary_node;
	jump_table[AST_LOGICAL_NOT].function = traverse_unary_node;
	jump_table[AST_POST_INC].function = traverse_unary_node;
	jump_table[AST_POST_DEC].function = traverse_unary_node;
	jump_table[AST_EXPRESSION_GROUP].function = traverse_unary_node;
	jump_table[AST_EXPRESSION_STATEMENT].function = traverse_unary_node;

	//	Should be unary nodes
	jump_table[AST_INITIALIZER].function = traverse_initializer_node;
	jump_table[AST_DEFAULT].function = traverse_default_stmt_node;
	jump_table[AST_GOTO].function = traverse_goto_stmt_node;
	jump_table[AST_RETURN].function = traverse_return_stmt_node;
	jump_table[AST_ATOMIC_TYPE].function = traverse_atomic_type_node;
	jump_table[AST_BLOCK].function = traverse_block_node;
	jump_table[AST_GROUPED_DECLARATOR].function = traverse_grouped_declarator_node;



	// ************************************************************************
	//	binary nodes
	// ************************************************************************
	jump_table[AST_ASSIGN].function = traverse_binary_node;
	jump_table[AST_ADD_ASSIGN].function = traverse_binary_node;
	jump_table[AST_SUB_ASSIGN].function = traverse_binary_node;
	jump_table[AST_MUL_ASSIGN].function = traverse_binary_node;
	jump_table[AST_DIV_ASSIGN].function = traverse_binary_node;
	jump_table[AST_MOD_ASSIGN].function = traverse_binary_node;
	jump_table[AST_AND_ASSIGN].function = traverse_binary_node;
	jump_table[AST_XOR_ASSIGN].function = traverse_binary_node;
	jump_table[AST_OR_ASSIGN].function = traverse_binary_node;
	jump_table[AST_SHL_ASSIGN].function = traverse_binary_node;
	jump_table[AST_SHR_ASSIGN].function = traverse_binary_node;
	jump_table[AST_OR].function = traverse_binary_node;
	jump_table[AST_AND].function = traverse_binary_node;
	jump_table[AST_BIT_OR].function = traverse_binary_node;
	jump_table[AST_BIT_XOR].function = traverse_binary_node;
	jump_table[AST_BIT_AND].function = traverse_binary_node;
	jump_table[AST_EQ].function = traverse_binary_node;
	jump_table[AST_NE].function = traverse_binary_node;
	jump_table[AST_LT].function = traverse_binary_node;
	jump_table[AST_GT].function = traverse_binary_node;
	jump_table[AST_LE].function = traverse_binary_node;
	jump_table[AST_GE].function = traverse_binary_node;
	jump_table[AST_SHL].function = traverse_binary_node;
	jump_table[AST_SHR].function = traverse_binary_node;
	jump_table[AST_ADD].function = traverse_binary_node;
	jump_table[AST_SUB].function = traverse_binary_node;
	jump_table[AST_MUL].function = traverse_binary_node;
	jump_table[AST_DIV].function = traverse_binary_node;
	jump_table[AST_MOD].function = traverse_binary_node;
	jump_table[AST_ENUM_INIT].function = traverse_binary_node;

	//	Should be binary nodes
	jump_table[AST_CAST].function = traverse_cast_node;
	jump_table[AST_ARRAY_SUBSCRIPT].function = traverse_array_subscript_node;
	jump_table[AST_FUNCTION_CALL].function = traverse_function_call_node;
	jump_table[AST_MEMBER_ACCESS].function = traverse_member_access_node;
	jump_table[AST_MEMBER_ACCESS_POINTER].function = traverse_member_access_node;
	jump_table[AST_COMPOUND_LITERAL].function = traverse_compound_literal_node;
	jump_table[AST_DESIGNATION_INITIALIZER].function = traverse_designation_initializer_node;
	jump_table[AST_DESIGNATOR].function = traverse_designator_node;
	jump_table[AST_LABEL].function = traverse_label_node;
	jump_table[AST_CASE].function = traverse_case_stmt_node;
	jump_table[AST_SWITCH].function = traverse_switch_stmt_node;
	jump_table[AST_WHILE].function = traverse_while_stmt_node;
	jump_table[AST_DO_WHILE].function = traverse_do_while_stmt_node;
	jump_table[AST__STATIC_ASSERT].function = traverse_static_assert_stmt_node;
	jump_table[AST_STATIC_ASSERT].function = traverse_static_assert_stmt_node;
	jump_table[AST_STRUCT].function = traverse_struct_or_union_node;
	jump_table[AST_UNION].function = traverse_struct_or_union_node;
	jump_table[AST_STRUCT_OR_UNION_DECLARATION].function = traverse_struct_or_union_declaration_node;
	jump_table[AST_STRUCT_OR_UNION_DECLARATOR].function = traverse_struct_or_union_declarator_node;
	jump_table[AST_ENUM].function = traverse_enum_type_node;
	jump_table[AST_DECLARATION].function = traverse_declaration_node;
	jump_table[AST_POINTER_DECLARATOR].function = traverse_pointer_declarator_node;
	jump_table[AST_POINTER].function = traverse_pointer_node;
	jump_table[AST_PARAMETER_DECLARATION].function = traverse_parameter_declaration_node;
	jump_table[AST_INIT_DECLARATOR].function = traverse_init_declarator_node;
	jump_table[AST_ABSTRACT_TYPE_NAME].function = traverse_abstract_type_name_node;
	jump_table[AST_ABSTRACT_DECLARATOR].function = traverse_abstract_declarator_node;
	jump_table[AST_UNSPECIFIED_ARRAY].function = traverse_unspecified_array_node;
	jump_table[AST_DYNAMIC_ARRAY].function = traverse_dynamic_array_node;



	// ************************************************************************
	//	ternary nodes
	// ************************************************************************
	jump_table[AST_TERNARY].function = traverse_ternary_node;

	// Should be ternary nodes
	jump_table[AST_IF].function = traverse_if_stmt_node;
	jump_table[AST_STATIC_ARRAY].function = traverse_array_node;
	jump_table[AST_ARRAY].function = traverse_array_node;
	jump_table[AST_FUNCTION_DECLARATOR].function = traverse_function_declarator_node;



	// ************************************************************************
	//	quad nodes
	// ************************************************************************
	jump_table[AST_FOR].function = traverse_for_stmt_node;
	jump_table[AST_FUNCTION_DEFINITION].function = traverse_function_definition_node;



	// ************************************************************************
	//	general/terminal/no-op nodes
	// ************************************************************************

	jump_table[AST_ID].function = traverse_no_op_node;
	jump_table[AST_TYPEDEF_NAME].function = traverse_no_op_node;	//	Unused!
	jump_table[AST_STRING].function = traverse_no_op_node;
	jump_table[AST_NUMERIC].function = traverse_no_op_node;
	jump_table[AST_ENUMERATION_CONSTANT].function = traverse_no_op_node;
	jump_table[AST_CONTINUE].function = traverse_no_op_node;
	jump_table[AST_BREAK].function = traverse_no_op_node;

	jump_table[AST__FUNC__].function = traverse_no_op_node;

	jump_table[AST_VOID].function = traverse_no_op_node;
	jump_table[AST_CHAR].function = traverse_no_op_node;
	jump_table[AST_SHORT].function = traverse_no_op_node;
	jump_table[AST_INT].function = traverse_no_op_node;
	jump_table[AST_LONG].function = traverse_no_op_node;
	jump_table[AST_FLOAT].function = traverse_no_op_node;
	jump_table[AST_DOUBLE].function = traverse_no_op_node;
	jump_table[AST_SIGNED].function = traverse_no_op_node;
	jump_table[AST_UNSIGNED].function = traverse_no_op_node;
	jump_table[AST_BOOL].function = traverse_no_op_node;
	jump_table[AST_COMPLEX].function = traverse_no_op_node;
	jump_table[AST_IMAGINARY].function = traverse_no_op_node;
	jump_table[AST_ATOMIC].function = traverse_no_op_node;
	jump_table[AST__BUILTIN_VA_LIST].function = traverse_no_op_node;
	jump_table[AST__DECIMAL32].function = traverse_no_op_node;
	jump_table[AST__DECIMAL64].function = traverse_no_op_node;
	jump_table[AST__DECIMAL128].function = traverse_no_op_node;
	jump_table[AST__FLOAT128].function = traverse_no_op_node;
	jump_table[AST__INT128].function = traverse_no_op_node;
	jump_table[AST__INT128_T].function = traverse_no_op_node;
	jump_table[AST__UINT128_T].function = traverse_no_op_node;
	jump_table[AST__BITINT].function = traverse_no_op_node;
	jump_table[AST__ATTRIBUTE__].function = traverse_no_op_node;
	jump_table[AST__ASM__].function = traverse_no_op_node;
	jump_table[AST_TYPEDEF].function = traverse_no_op_node;
	jump_table[AST_EXTERN].function = traverse_no_op_node;
	jump_table[AST_STATIC].function = traverse_no_op_node;
	jump_table[AST_THREAD_LOCAL].function = traverse_no_op_node;
	jump_table[AST_AUTO].function = traverse_no_op_node;
	jump_table[AST_REGISTER].function = traverse_no_op_node;
	jump_table[AST__EXTENSION__].function = traverse_no_op_node;
	jump_table[AST_ELLIPSIS].function = traverse_no_op_node;
	jump_table[AST_CONST].function = traverse_no_op_node;
	jump_table[AST_RESTRICT].function = traverse_no_op_node;
	jump_table[AST_VOLATILE].function = traverse_no_op_node;
	jump_table[AST__RESTRICT].function = traverse_no_op_node;
	jump_table[AST_INLINE].function = traverse_no_op_node;
	jump_table[AST_NORETURN].function = traverse_no_op_node;
	jump_table[AST__INLINE].function = traverse_no_op_node;
	jump_table[AST__INLINE__].function = traverse_no_op_node;
	jump_table[AST_PRAGMA].function = traverse_no_op_node;


	jump_table[AST__NO_OP__].function = traverse_no_op_node;


	//	For now, we have a few 'unused' nodes, so this would fail.
	//	Once we get some time to cleanup the list of nodes,
	//	then we can properly implement this check/assert!
	//	Currently, we pre-initialize all the nodes to `traverse_unsupported_node`,
	//		so this check is not needed.
	for (int i = 0; i < AST__LAST__; i++) {
		if (jump_table[i].function == NULL) {
			printf("PARSER ERROR: jump_table[%d] == NULL in %s()\n", i, __FUNCTION__);
		}
		assert(jump_table[i].function != NULL);
	}
}
