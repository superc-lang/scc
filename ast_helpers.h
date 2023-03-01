#pragma once

#include "ast.h"

// #include <stdio.h>

const char *get_node_name(int type);

void register_function(union ast_node *declspecs, union ast_node *declarator);

//	In loving memory of the GCC `start_function` method found in `c-decl.c`.
int start_function(union ast_node *declspecs, union ast_node *declarator);

// Recursively loop through the declarator nodes looking for the AST_ID node.
union ast_node *get_id_node(union ast_node *node);

union ast_node *get_node_by_type(int type, union ast_node *node);

// extern void print_ast_tree(FILE *out, union ast_node *node, int depth, union ast_node *parent);



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

static inline int is_typeof_node(int type, union ast_node *node)
{
	if (node == NULL) return 0;

	if (node->type != type) {	//	In case we asked for a node type in the switch statement!
		switch (node->type) {
		case AST_LIST:
			return is_typeof_node(type, node->list.node)
				|| is_typeof_node(type, node->list.next);

		//	Added to support `opaque` generics
		case AST_GENERIC_STRUCT:
		case AST_GENERIC_UNION:
			return is_typeof_node(type, node->struct_or_union.id)
				|| is_typeof_node(type, node->struct_or_union.decl_list);
		}
	}

	return node->type == type;
}

// Recursively loop through the specifier nodes looking for an AST_TYPEDEF node.
static inline int is_typedef_node(union ast_node *node)
{
	return is_typeof_node(AST_TYPEDEF, node);
}






enum {
	GENERIC_TYPEDEF_NAME,	//	eg. `Vec3<float>`
	GENERIC_FUNC_NEW,		//	eg. `Vec3<float> new()` ==> `Vec3<float> Vec3__float__new()`
	GENERIC_FUNC_SET,
	GENERIC_FUNC_GET,
	GENERIC_FUNC,
	GENERIC_FUNC_DELETE,
	/*
	GENERIC_TYPE_NONE,
	GENERIC_TYPE_I8,
	GENERIC_TYPE_U8,
	GENERIC_TYPE_I16,
	GENERIC_TYPE_U16,
	GENERIC_TYPE_I32,
	GENERIC_TYPE_U32,
	GENERIC_TYPE_I64,
	GENERIC_TYPE_U64,
	GENERIC_TYPE_I128,
	GENERIC_TYPE_U128,
	GENERIC_TYPE_F32,
	GENERIC_TYPE_F64,
	GENERIC_TYPE_PTR,
	GENERIC_TYPE_ARRAY,
	GENERIC_TYPE_FUNC,
	GENERIC_TYPE_STRUCT,
	GENERIC_TYPE_UNION,
	GENERIC_TYPE_ENUM,
	GENERIC_TYPE_TYPEDEF,
	GENERIC_TYPE_MAX
	*/
};
//	eg. `Vec3<float>` ==> `Vec3__float`
char *get_generic_type_name(union ast_node *node);
char *get_generic_impl_name(union ast_node *node);

//	eg. `new Vec3<float>()` ==> `Vec3__float__new()`
char *get_generic_func_name(int func_type, union ast_node *node, union ast_node *type_list);


void register_generic_struct_or_union(union ast_node *node);

void build_generic_struct(union ast_node *node);
void build_impl_from_generic(union ast_node *specifier, union ast_node *declaration);

void register_typedef(union ast_node *decl_specs, union ast_node *declarator);
void register_declaration(union ast_node *node);
