#include "compiler_passes.h"
#include "scc.h"
#include "ast.h"
#include "symbol_table.h"
#include "compass_impl.h"
#include "compass_generics.h"

struct {
	const char *name;
	void (*execute)(union ast_node *node, union ast_node *parent);
} static compiler_passes[] = {
	{ "Process IMPL blocks", process_impl_blocks },
	{ "Process `generic` declarations", process_generic_decls },
	{ 0 },
};

void run_compiler_passes()
{
	for (int i = 0; compiler_passes[i].execute; i++) {
		symbol_table_init();			//	Reset the symbol table
		symbol_table_push_scope();		//	Push a clean global scope

		compiler_passes[i].execute(ast_root, NULL);
	}
}
