#include "symbol_keys.h"

#include <stdio.h>
#include <assert.h>

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// DEBUG link: https://godbolt.org/z/sh5oTPGoG
// Includes symbol_table!

#define SYMBOL_KEYS_INITIAL_CAPACITY 512		// NOTE: Must be a power of 2


typedef struct key_slab_t key_slab_t;
typedef struct node_slab_t node_slab_t;

typedef struct symbol_key_t symbol_key_t;
typedef struct symbol_keys_t symbol_keys_t;


struct key_slab_t {
	const char *slab;
	unsigned capacity;
	unsigned used;
};

struct node_slab_t {
	symbol_key_t *slab;
	unsigned capacity;
	unsigned used;
};


struct symbol_key_t {
	symbol_key_t *next;
	unsigned hash;
	const char *key;
};

struct symbol_keys_t {
	symbol_key_t **nodes;
	unsigned size;
	unsigned mask;
	unsigned used;
};


key_slab_t key_slab;
node_slab_t node_slab;
symbol_keys_t symbol_keys;

void symbol_keys_init();
const char *get_symbol_key(const char *key, unsigned hash);
const char *symbol_keys_add(const char *key, unsigned hash);
void symbol_keys_resize();

static inline int streq(const char *s1, const char *s2);
static inline unsigned next_pow_2(unsigned v);

void symbol_keys_init()
{
	size_t size = next_pow_2(SYMBOL_KEYS_INITIAL_CAPACITY);
	symbol_keys.size = size;
	symbol_keys.mask = size - 1;
	symbol_keys.nodes = (symbol_key_t **) calloc(symbol_keys.size, sizeof(symbol_key_t*));
	symbol_keys.used = 0;

	key_slab.capacity = size * 8;
	key_slab.slab = (const char *) malloc(key_slab.capacity * sizeof(char));
	key_slab.used = 0;

	node_slab.capacity = size;
	node_slab.slab = (symbol_key_t *) malloc(node_slab.capacity * sizeof(symbol_key_t));
	node_slab.used = 0;

	assert(symbol_keys.nodes);
	assert(key_slab.slab);
	assert(node_slab.slab);
}

void symbol_keys_reset()
{
	symbol_keys.used = 0;
	memset(symbol_keys.nodes, 0, symbol_keys.size * sizeof(symbol_key_t*));
	key_slab.used = 0;
	node_slab.used = 0;
}

const char *get_symbol_key(const char *key, unsigned hash)
{
	unsigned index = hash & symbol_keys.mask;
	symbol_key_t *node = symbol_keys.nodes[index];

	while (node != NULL) {
		if (node->hash == hash && streq(key, node->key) == 0)
			return node->key;

		node = node->next;
	}

	return symbol_keys_add(key, hash);
}


// NOTE: Don't make this `static`, or it will add many `push` statements to the `symbol_keys_get` function!
const char *symbol_keys_add(const char *key, unsigned hash)
{
	unsigned keylen = (unsigned) strlen(key);
	const char *ret;

	if (keylen <= 64) {
		unsigned needed = keylen + 1;
		unsigned new_used = key_slab.used + needed;
		if (new_used <= key_slab.capacity) {
			ret = &key_slab.slab[key_slab.used];
			key_slab.used = new_used;
		} else {
			key_slab.capacity *= 2;
			assert(key_slab.capacity >= needed);
			key_slab.slab = ret = (const char *) malloc(key_slab.capacity * sizeof(char));
			key_slab.used = needed;
		}
		strcpy((char *) ret, key);
	} else {
		ret = strdup(key);
	}

	symbol_key_t *node;

	if (node_slab.used < node_slab.capacity) {
		node = &node_slab.slab[node_slab.used];
		node_slab.used++;
	} else {
		node_slab.capacity *= 2;
		node_slab.slab = (symbol_key_t *) malloc(node_slab.capacity * sizeof(symbol_key_t));
		node = &node_slab.slab[0];
		node_slab.used = 1;
	}
	node->hash = hash;
	node->key = ret;

	if (symbol_keys.used == symbol_keys.size) {
		symbol_keys_resize();
	}

	node->hash = hash;
	unsigned index = node->hash & symbol_keys.mask;

	node->next = symbol_keys.nodes[index];
	symbol_keys.nodes[index] = node;

	symbol_keys.used++;

	return ret;
}


void symbol_keys_resize()
{
	unsigned new_size = symbol_keys.size * 2;
	unsigned new_mask = new_size - 1;

	symbol_key_t **nodes = (symbol_key_t**) calloc(new_size, sizeof(symbol_key_t*));

	for (unsigned i = 0; i < symbol_keys.size; i++) {
		symbol_key_t *node = symbol_keys.nodes[i];
		while (node != NULL) {
			unsigned new_index = node->hash & new_mask;
			symbol_key_t *next_node = node->next;
			node->next = nodes[new_index];
			nodes[new_index] = node;
			node = next_node;
		}
	}

	symbol_keys.mask = new_mask;
	symbol_keys.size = new_size;

	free(symbol_keys.nodes);
	symbol_keys.nodes = nodes;
}


void symbol_keys_print()
{
	int n = 0;
	for (unsigned i = 0; i < symbol_keys.size; i++) {
		// printf("Hash table index: %u\n", i);
		symbol_key_t *node = symbol_keys.nodes[i];
		while (node) {
			printf("Key: %s (%d)\n", node->key, i);
			// printf("strlen(key): %lu\n", strlen(node->key));
			node = node->next;
			n++;
		}
	}
	printf("Total keys: %d\n", n);
    printf("Hash table size: %u\n", symbol_keys.size);
}


// Taken from: https://github.com/lattera/glibc/blob/master/string/test-strcmp.c
static inline int streq(const char *s1, const char *s2)
{
	int ret;
	while ((ret = *(unsigned char *) s1 - *(unsigned char*) s2++) == 0 && *s1++);

	return ret;
}


//	Taken from: https://graphics.stanford.edu/~seander/bithacks.html#RoundUpPowerOf2
static inline unsigned next_pow_2(unsigned v)
{
	v += (v == 0);
	--v;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	++v;
	return v;
}
