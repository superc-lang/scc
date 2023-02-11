#pragma once

#include "symbol.h"

#include <stdio.h>

void symbol_table_init();

void symbol_table_push_scope();
void symbol_table_pop_scope();

void symbol_table_reset();

void symbol_table_print(FILE *fd);

int symbol_table_get_level();

symbol_t *symbol_add(const char *key);
symbol_t *symbol_get(const char *key);


symbol_t *symbol_add_function(const char *key, union ast_node *node);
symbol_t *symbol_add_variable(const char *key, union ast_node *node);	//	NON pointer types
symbol_t *symbol_add_parameter(const char *key, union ast_node *node);
symbol_t *symbol_add_enum_constant(const char *key, union ast_node *node);

symbol_t *symbol_add_pointer(const char *key, union ast_node *node);

symbol_t *symbol_add_getter(const char *key, union ast_node *node);
symbol_t *symbol_add_setter(const char *key, union ast_node *node);


symbol_t *symbol_add_typedef(const char *key, union ast_node *node);			//	Standard data type eg. typedef long int i32;
symbol_t *symbol_add_typedef_struct(const char *key, union ast_node *node);
symbol_t *symbol_add_typedef_union(const char *key, union ast_node *node);



symbol_t *symbol_get_typedef(const char *key);
symbol_t *symbol_get_function(const char *key);
symbol_t *symbol_get_variable(const char *key);
symbol_t *symbol_get_parameter(const char *key);
symbol_t *symbol_get_enum_constant(const char *key);



int symbol_is(const char *key, int (*cmp)(symbol_t *symbol));


int symbol_is_declared(const char *key);	//	declared functions = int fn();
int symbol_is_defined(const char *key);		//	defined functions = int fn(...) { ... }


int symbol_is_typedef(const char *key);
int symbol_is_enum_constant(const char *key);
int symbol_is_function(const char *key);
int symbol_is_variable(const char *key);




// int symbol_is_setter(const char *key);
// int symbol_is_getter(const char *key);
// int symbol_is_struct_or_union(const char *key);
