#pragma once

#include "ast.h"

const char *get_node_name(int type);

void register_function(union ast_node *declspecs, union ast_node *declarator);

//	In loving memory of the GCC `start_function` method found in `c-decl.c`.
int start_function(union ast_node *declspecs, union ast_node *declarator);

// Recursively loop through the declarator nodes looking for the AST_ID node.
union ast_node *get_id_node(union ast_node *declarator);


// Recursively loop through the specifier nodes looking for an AST_TYPEDEF node.
static inline union ast_node *get_typedef_node(union ast_node *specifier)
{
	if (specifier == NULL) return NULL;

	union ast_node *node;

	switch (specifier->type) {
	case AST_LIST:
		node = get_typedef_node(specifier->list.node);
		if (node) return node;
		return get_typedef_node(specifier->list.next);

	case AST_TYPEDEF:
		return specifier;
	}

	return NULL;
}

// Recursively loop through the specifier nodes looking for an AST_TYPEDEF node.
static inline int is_typedef_node(union ast_node *specifier)
{
	if (specifier == NULL) return 0;

	switch (specifier->type) {
	case AST_LIST:
		return is_typedef_node(specifier->list.node)
			|| is_typedef_node(specifier->list.next);

	case AST_TYPEDEF:
		return 1;
	}

	return 0;
}


