#include "compass_generics.h"
#include "traverse_ast.h"
#include "ast_helpers.h"
#include "ast_nodes.h"
#include "print_ast_tree.h"

#include <assert.h>

// #include "impl.h"
// #include "scc.h"
// // #include "traverse_ast.h"
// #include "ast_helpers.h"
// #include "ast_nodes.h"
// #include "symbol_table.h"


void handle_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_generic_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_generic_struct(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);
void handle_generic_union(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table);

void process_generic_decls(union ast_node *node, union ast_node *parent)
{
	static traversal_jump_table_t jump_table[AST__LAST__] = { 0 };

	init_traversal_jump_table(jump_table);

	jump_table[AST_DECLARATION].function = handle_declaration;

	jump_table[AST_GENERIC_DECLARATION].function = handle_generic_declaration;
	jump_table[AST_GENERIC_STRUCT].function = handle_generic_struct;
	jump_table[AST_GENERIC_UNION].function = handle_generic_union;

	traverse_ast(node, parent, jump_table);
}

void handle_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	if (node->declaration.init_declarator_list == NULL) {
		union ast_node *decl_specs = node->declaration.decl_specs;
		if (is_typeof_node(AST_GENERIC_DECLARATION, decl_specs)) {
printf("FOUND GENERIC SPECIFIER!\n");
			//	Disabling the check for `typedef` ... to support `opaque` generics!
			//	Is the `typedef` check necessary?
			if (1 || is_typeof_node(AST_TYPEDEF, decl_specs)) {

				build_generic_struct(node);

				// printf("FOUND GENERIC SPECIFIER WITH TYPEDEF!\n");
				//	We need to generate the typedef here, because the generic type is not a real type, but a placeholder for a real type
				// indent(out, depth);
				// fprintf(out, "typedef struct %s {", get_generic_type_name(node->declaration.decl_specs));

					// Retrieve the generic template structure, and run through it while replacing the generic type with the real/concrete type

				// fprintf(out, " } %s;\n", get_generic_type_name(node->declaration.decl_specs));

				// TODO: We need to build/expand/replace the generic template structure!
				// break;
			} else {
// build_generic_struct(node);

			}
		} else if (is_typeof_node(AST_GENERIC_STRUCT, decl_specs) || is_typeof_node(AST_GENERIC_UNION, decl_specs)) {
printf("NOT FOUND GENERIC SPECIFIER!\n");
			// codegen(out, decl_specs, depth, node);
			// break;
		}
	}

print_ast_tree(stdout, node, 0, 0);
printf("begin register_typedef\n");
	register_typedef(node->declaration.decl_specs, node->declaration.init_declarator_list);
printf("being register_declaration\n");
	register_declaration(node);
printf("end register_declaration\n");
}

void handle_generic_declaration(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
	
}


void handle_generic_struct(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{
// case AST_GENERIC_STRUCT:
// case AST_GENERIC_UNION:
	assert(node->generic_type.id != NULL);
	if (node->generic_type.id->type == AST_GENERIC_DECLARATION) {
		register_generic_struct_or_union(node);
		if (parent->type == AST_DECLARATION && parent->declaration.decl_specs == node) {
			parent->declaration.decl_specs = NULL;
		}
	} else {
printf("HERLEJHRELJRHLEJHREJLHR J====================>>>>\n");
	}
}

void handle_generic_union(union ast_node *node, union ast_node *parent, traversal_jump_table_t *jump_table)
{

}


