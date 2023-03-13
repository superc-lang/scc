#include "symbol_table.h"
#include "symbol_keys.h"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

// DEBUG link: https://godbolt.org/z/sh5oTPGoG
// Includes symbol_keys!

#ifndef NULL
#define NULL ((void *) 0)
#endif

typedef struct scope_symbol_t scope_symbol_t;
typedef struct scope_symbols_t scope_symbols_t;
typedef struct scope_t scope_t;
typedef struct scopes_t scopes_t;

struct scope_symbol_t {
	const char *key;
	unsigned hash;
	symbol_t symbol;
	scope_symbol_t *next;
};

struct scope_symbols_t {
	unsigned capacity;
	unsigned used;
	scope_symbols_t *next;
	scope_symbol_t symbols[];
};

struct scope_t {
	scope_symbols_t *symbols;	//	Linked list of symbols array. New symbols are allocated from the `symbols->symbols` array and then added to the hash table for fast lookup. `symbols` themselves are never freed, because the whole scope is freed at once.
	scope_symbol_t **hash_table;
	unsigned ht_size;
	unsigned ht_used;
	int level;					//	For anonymous functions (that sit inside another function), we set the level to zero. A scope with level 0 (zero) will have access to the global scope at index 0 (zero).
};

struct scopes_t {
	scope_t *scopes;
	unsigned capacity;
	unsigned init;				// previously initialized scopes
	unsigned used;
};
scopes_t scopes;


void init_scope(unsigned capacity, int level);


void symbol_table_init()
{
	symbol_keys_init();

	scopes.capacity = 1;
	scopes.init = 0;
	scopes.used = 0;
	scopes.scopes = (scope_t *) malloc(scopes.capacity * sizeof(scope_t));

	init_scope(512, -1);
}

void symbol_table_reset()
{
	symbol_keys_reset();

	scopes.init = 0;
	scopes.used = 0;
	memset(scopes.scopes, 0, scopes.capacity * sizeof(scope_t));

	init_scope(512, -1);
}


#ifndef MAX
#define MAX(i, j) (((i) > (j)) ? (i) : (j))
#endif


void init_scope(unsigned capacity, int level)
{
	scope_t *scope = &scopes.scopes[scopes.init++];

	scope->symbols = (scope_symbols_t *) malloc(sizeof(scope_symbols_t) + capacity * sizeof(scope_symbol_t));
	scope->symbols->capacity = capacity;
	scope->symbols->used = 0;
	scope->symbols->next = (void *) 0;

	scope->ht_size = MAX(capacity, 16);
	scope->ht_used = 0;
	scope->hash_table = (scope_symbol_t **) malloc(scope->ht_size * sizeof(scope_symbol_t *));

	memset(scope->hash_table, 0, scope->ht_size * sizeof(scope_symbol_t *));
}


void symbol_table_push_scope()
{
	if (scopes.used == scopes.capacity) {
		scopes.capacity *= 2;
		scopes.scopes = (scope_t *) realloc(scopes.scopes, scopes.capacity * sizeof(scope_t));
	}
	if (scopes.used == scopes.init) {
		init_scope(16, 0);
		scopes.used++;
	} else {
		scope_t *scope = &scopes.scopes[scopes.used++];
		scope->ht_size = MAX(scope->ht_size, 16);
		scope->ht_used = 0;
		//	NOTE: As a minor performance improvement, we don't realloc the old hash table, since it's already guaranteed to have enough space for us, until we "expand" it again.
		//scope->hash_table = (scope_symbol_t **) realloc(scope->hash_table, scope->ht_capacity * sizeof(scope_symbol_t *));
		memset(scope->hash_table, 0, scope->ht_size * sizeof(scope_symbol_t *));
		//scope->symbols->capacity = ...;	//	NOTE: We don't set the capacity, because these are FIXED blocks of memory!
		//scope->symbols->next = (void *) 0;	//	Already set to zero when we popped the last scope.
		scope->symbols->used = 0;
	}
}


void symbol_table_pop_scope()
{
	assert(scopes.used > 0);
	scope_t *scope = &scopes.scopes[--scopes.used];
	scope_symbols_t *slab = scope->symbols->next;
	scope->symbols->next = (void *) 0;
	while (slab) {
		scope_symbols_t *next_slab = slab->next;
		free(slab);
		slab = next_slab;
	}
}


symbol_t *symbol_add(const char *key)
{
	scope_t *scope = &scopes.scopes[scopes.used - 1];
	if (scope->symbols->used == scope->symbols->capacity) {
		unsigned capacity = scope->symbols->capacity * 2;
		scope_symbols_t *slab = (scope_symbols_t *) malloc(sizeof(scope_symbols_t) + capacity * sizeof(scope_symbol_t));
		slab->capacity = capacity;
		slab->used = 0;
		slab->next = scope->symbols;
		scope->symbols = slab;
	}

	scope_symbol_t *scope_symbol = &scope->symbols->symbols[scope->symbols->used++];
	scope_symbol->hash = symbol_hash(key);
	scope_symbol->key = get_symbol_key(key, scope_symbol->hash);

	// scope_symbol->symbol.type = SYMBOL_TYPE_UNKNOWN;
	// scope_symbol->symbol.flags = 0;
	// scope_symbol->symbol.value = 0;
	// scope_symbol->symbol.data = NULL;

	unsigned mask = scope->ht_size - 1;
	unsigned hash_idx = scope_symbol->hash & mask;
	scope_symbol->next = scope->hash_table[hash_idx];
	scope->hash_table[hash_idx] = scope_symbol;
	scope->ht_used++;

	return &scope_symbol->symbol;
}


symbol_t *symbol_get(const char *key)
{
	assert(scopes.used > 0);

	unsigned hash = symbol_hash(key);

	for (int i = scopes.used - 1; i >= 0; --i) {
		scope_t *scope = &scopes.scopes[i];

		unsigned mask = scope->ht_size - 1;
		unsigned hash_idx = hash & mask;

		scope_symbol_t *scope_symbol = scope->hash_table[hash_idx];
		while (scope_symbol) {
			if (scope_symbol->hash == hash && strcmp(scope_symbol->key, key) == 0) {
				return &scope_symbol->symbol;
			}
			scope_symbol = scope_symbol->next;
		}
	}

	return NULL;
}


symbol_t *symbol_get_at_level(const char *key)	//	Searches the current scope level only
{
	assert(scopes.used > 0);

	unsigned hash = symbol_hash(key);

	scope_t *scope = &scopes.scopes[scopes.used - 1];

	unsigned mask = scope->ht_size - 1;
	unsigned hash_idx = hash & mask;

	scope_symbol_t *scope_symbol = scope->hash_table[hash_idx];
	while (scope_symbol) {
		if (scope_symbol->hash == hash && strcmp(scope_symbol->key, key) == 0) {
			return &scope_symbol->symbol;
		}
		scope_symbol = scope_symbol->next;
	}

	return NULL;
}


int symbol_is(const char *key, int (*callback)(symbol_t *symbol))
{
	assert(scopes.used > 0);

	unsigned hash = symbol_hash(key);
	for (int i = scopes.used - 1; i >= 0; --i) {
		scope_t *scope = &scopes.scopes[i];

		unsigned mask = scope->ht_size - 1;
		unsigned hash_idx = hash & mask;

		scope_symbol_t *scope_symbol = scope->hash_table[hash_idx];
		while (scope_symbol) {
			if (scope_symbol->hash == hash && strcmp(scope_symbol->key, key) == 0) {
				int result = callback(&scope_symbol->symbol);
				if (result >= 0) return result;
			}
			scope_symbol = scope_symbol->next;
		}
	}

	return 0;
}


int symbol_is_typedef_callback(symbol_t *symbol)
{
	return symbol->is_typedef ? symbol->is_typedef : -1;
}
int symbol_is_typedef(const char *key)
{
	int result = symbol_is(key, symbol_is_typedef_callback);
	return result > 0;
}


int symbol_is_generic_callback(symbol_t *symbol)
{
	return symbol->is_generic;
}
int symbol_is_generic(const char *key)
{
	return symbol_is(key, symbol_is_generic_callback);
}

int symbol_is_generic_type_callback(symbol_t *symbol)
{
	return symbol->is_generic_type;
}
int symbol_is_generic_type(const char *key)
{
	return symbol_is(key, symbol_is_generic_type_callback);
}




// int symbol_is_typedef(const char *key)
// {
// 	return symbol_is(key, s => s->is_typedef ?: -1);
// }
// int symbol_is_typedef(const char *key)
// {
// 	return symbol_is(key, s => s->is_typedef ? s->is_typedef : -1);
// }
// int symbol_is_typedef(const char *key)
// {
// 	return symbol_is(key, (symbol) => symbol->is_typedef ? symbol->is_typedef : -1);
// }
// int symbol_is_typedef(const char *key)
// {
// 	return symbol_is(key, (symbol) { return symbol->is_typedef ? symbol->is_typedef : -1; });
// }

int symbol_is_enum_constant(const char *key)
{
	assert(scopes.used > 0);

	unsigned hash = symbol_hash(key);
	
	for (int i = scopes.used - 1; i >= 0; --i) {
		scope_t *scope = &scopes.scopes[i];

		unsigned mask = scope->ht_size - 1;
		unsigned hash_idx = hash & mask;

		scope_symbol_t *scope_symbol = scope->hash_table[hash_idx];
		while (scope_symbol) {
			if (scope_symbol->hash == hash && strcmp(scope_symbol->key, key) == 0) {
				if (scope_symbol->symbol.is_enum_constant)
					return scope_symbol->symbol.is_enum_constant;
			}
			scope_symbol = scope_symbol->next;
		}
	}

	return 0;
}

int symbol_is_function(const char *key)
{
	assert(scopes.used > 0);

	unsigned hash = symbol_hash(key);
	
	for (int i = scopes.used - 1; i >= 0; --i) {
		scope_t *scope = &scopes.scopes[i];

		unsigned mask = scope->ht_size - 1;
		unsigned hash_idx = hash & mask;

		scope_symbol_t *scope_symbol = scope->hash_table[hash_idx];
		while (scope_symbol) {
			if (scope_symbol->hash == hash && strcmp(scope_symbol->key, key) == 0) {
				if (scope_symbol->symbol.is_function)
					return scope_symbol->symbol.is_function;
			}
			scope_symbol = scope_symbol->next;
		}
	}

	return 0;
}

// int symbol_is_setter(const char *key);
// int symbol_is_getter(const char *key);
// int symbol_is_struct_or_union(const char *key);


void symbol_table_print(FILE *out)
{
	for (unsigned i = 0; i < scopes.used; i++) {
		scope_t *scope = &scopes.scopes[i];
		fprintf(out, "Scope level: %u\n-----------------\n", i);

		unsigned ht_count = 0;
		for (unsigned j = 0; j < scope->ht_size; j++) {
			scope_symbol_t *scope_symbol = scope->hash_table[j];
			while (scope_symbol) {
				printf("%s (%u)", scope_symbol->key, j);
				if (scope_symbol->symbol.is_typedef) {
					fputs(" (typedef)", out);
				}
				if (scope_symbol->symbol.is_enum_constant) {
					fputs(" (enum)", out);
				}
				if (scope_symbol->symbol.is_function) {
					fputs(" (function)", out);
				}

				if (scope_symbol->symbol.is_generic) {
					if (scope_symbol->symbol.is_struct) {
						fputs(" (generic struct)", out);
					} else if (scope_symbol->symbol.is_union) {
						fputs(" (generic union)", out);
					} else {
						fputs(" (generic)", out);
					}
				} else if (scope_symbol->symbol.is_struct) {
					fputs(" (struct)", out);
				} else if (scope_symbol->symbol.is_union) {
					fputs(" (union)", out);
				}

				if (scope_symbol->symbol.is_generic_type) {
					fputs(" (generic type)", out);
				}

				fputc('\n', out);
				scope_symbol = scope_symbol->next;
				ht_count++;
			}
		}
		fprintf(out, "Hash Table symbols: %u\n", ht_count);
		fputs("-----------------\n", out);
		fputs("Slabs:\n", out);

		scope_symbols_t *symbols = scope->symbols;
		while (symbols) {
			fprintf(out, "Used %u of %u\n", symbols->used, symbols->capacity);
			
			symbols = symbols->next;
		}

		fputs("-----------------\n", out);
	}
}


int symbol_table_get_level()
{
	return scopes.used - 1;
}


symbol_t *symbol_add_function(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);
	symbol->is_function = 1;
	//	is_definition / is_declaration???
	symbol->node = node;

	return symbol;
}
//symbol_t *symbol_add_function_definition(const char *key, union ast_node *node)
//symbol_t *symbol_add_function_declaration(const char *key, union ast_node *node)


symbol_t *symbol_add_variable(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);
	symbol->is_variable = 1;
	symbol->node = node;

	return symbol;
}

symbol_t *symbol_add_pointer(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);
	symbol->is_variable = 1;
	symbol->is_pointer = 1;
	symbol->node = node;

	return symbol;
}


//	NOTE: At this point, I think the `node` will always be NULL!
//	We `update` the symbol with the `node` at the end of the declaration!
//	This is so that structures can use the 'parent' structure internally, like linked list nodes pointing to themselves!
symbol_t *__symbol_add_generic_name(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);

	// symbol->is_generic_name = 1;
	symbol->node = node;

	return symbol;
}
symbol_t *symbol_add_generic_type(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);

	symbol->is_generic_type = 1;
	symbol->node = node;

	return symbol;
}
symbol_t *symbol_add_generic_impl(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);

	symbol->is_generic_impl = 1;
	symbol->node = node;

	return symbol;
}
symbol_t *symbol_add_generic_static_impl(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);

	symbol->is_generic_static_impl = 1;
	symbol->node = node;

	return symbol;
}


symbol_t *__symbol_update_generic_name(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_get(key);

	assert(symbol != NULL);
	// assert(symbol->is_generic_name == 1);
	assert(symbol->node == NULL);

	symbol->node = node;

	return symbol;
}







symbol_t *symbol_add_parameter(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);
	symbol->is_parameter = 1;
	symbol->node = node;

	return symbol;
}

symbol_t *symbol_add_typedef(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);
	symbol->is_typedef = 1;
	symbol->node = node;

	return symbol;
}

symbol_t *symbol_add_typedef_struct(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);
	symbol->is_typedef = 1;
	symbol->is_struct = 1;
	symbol->node = node;

	return symbol;
}

symbol_t *symbol_add_typedef_union(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);
	symbol->is_typedef = 1;
	symbol->is_union = 1;
	symbol->node = node;

	return symbol;
}

symbol_t *symbol_add_enum_constant(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);
	symbol->is_enum_constant = 1;
	symbol->node = node;

	return symbol;
}


symbol_t *symbol_add_getter(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);
	symbol->is_function = 1;
	symbol->is_getter = 1;
	symbol->node = node;

	return symbol;
}
symbol_t *symbol_add_setter(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);
	symbol->is_function = 1;
	symbol->is_setter = 1;
	symbol->node = node;

	return symbol;
}



symbol_t *symbol_add_generic(const char *key, union ast_node *node)
{
	symbol_t *symbol = symbol_add(key);

	// assert(node->type == AST_GENERIC_STRUCT || node->type == AST_GENERIC_UNION);

	symbol->is_generic = 1;
	//	I don't want to add `ast.h` just for this function! So I'll do this outside of this function!
	//	Look for the function called `register_generic_struct_or_union`!
	// symbol->is_struct = node->type == AST_GENERIC_STRUCT;
	// symbol->is_union = node->type == AST_GENERIC_UNION;
	symbol->node = node;

	return symbol;
}




// symbol_t *symbol_add_struct_or_union(const char *key);


int symbol_is_declared(const char *key)
{
	return 0;
}

int symbol_is_defined(const char *key)
{
	return 0;
}
