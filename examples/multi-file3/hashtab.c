#include <string.h>
#include <stdlib.h>

#include "hashtab.h"

typedef struct hashtab_node_t hashtab_node_t;

struct hashtab_node_t {
	hashtab_node_t *next;
	void *data;
	unsigned hash;
	char key[];
};

struct hashtab {
	hashtab_node_t **nodes;
	unsigned size;
	unsigned mask;
	unsigned used;
	void (*free_func)(const char *key, void *data);
};

static inline unsigned hash_func(const char *key)
{
	unsigned hash = 5381;
	int c;

	while ((c = *key++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}

static inline unsigned int next_pow_2(unsigned int n)
{
	n--;

	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;

	n++;

	return n;
}

hashtab *hashtab_create(unsigned est_capacity)
{
	hashtab *ht = (hashtab*) malloc(sizeof(hashtab));
	if (ht == NULL)
		return NULL;

	size_t size = est_capacity ? next_pow_2(est_capacity) : 8;
	ht->size = size;
	ht->mask = size - 1;
	ht->used = 0;
	ht->free_func = NULL;

	ht->nodes = (hashtab_node_t**) calloc(size, sizeof(hashtab_node_t*));
	if (ht->nodes == NULL) {
		free(ht);
		return NULL;
	}

	return ht;
}

void hashtab_set_free_func(hashtab *ht, void (*free_func)(const char *key, void *data))
{
	ht->free_func = free_func;
}

static void hashtab_expand(hashtab *ht)
{
	unsigned new_size = ht->size * 2;
	unsigned new_mask = new_size - 1;

	hashtab_node_t **nodes = (hashtab_node_t**) calloc(new_size, sizeof(hashtab_node_t*));

	for (unsigned i = 0; i < ht->size; i++) {
		hashtab_node_t *node = ht->nodes[i];
		while (node) {
			hashtab_node_t *next_node = node->next;
			unsigned new_index = node->hash & new_mask;
			node->next = nodes[new_index];
			nodes[new_index] = node;
			node = next_node;
		}
	}

	ht->size = new_size;
	ht->mask = new_mask;

	free(ht->nodes);
	ht->nodes = nodes;
}

bool hashtab_add(hashtab *ht, const char *key, void *data)
{
	if (ht->used == ht->size)
		hashtab_expand(ht);

	unsigned hash = hash_func(key);
	unsigned index = hash & ht->mask;

	hashtab_node_t *node = (hashtab_node_t *) malloc(sizeof(hashtab_node_t) + strlen(key) + 1);
	if (node == NULL)
		return false;

	node->next = ht->nodes[index];
	node->data = data;
	node->hash = hash;
	strcpy(node->key, key);

	ht->nodes[index] = node;
	ht->used++;

	return true;
}

bool hashtab_add_copy(hashtab *ht, const char *key, void *data, size_t size)
{
	void *copy = malloc(size);
	if (copy == NULL)
		return false;
	memcpy(copy, data, size);
	bool result = hashtab_add(ht, key, copy);
	if (!result)
		free(copy);

	return result;
}

static hashtab_node_t *hashtab_find_node(const hashtab *ht, const void *key)
{
	unsigned hash = hash_func(key);
	unsigned index = hash & ht->mask;
	hashtab_node_t *node = ht->nodes[index];

	while (node) {
		if (node->hash == hash && strcmp(key, node->key) == 0)
			return node;
		node = node->next;
	}

	return NULL;
}

void *hashtab_find(const hashtab *ht, const void *key)
{
	hashtab_node_t *node = hashtab_find_node(ht, key);

	return node ? node->data : NULL;
}

bool hashtab_update(hashtab *ht, const char *key, void *data)
{
	hashtab_node_t *node = hashtab_find_node(ht, key);
	if (node) {
		if (ht->free_func)
			ht->free_func(node->key, node->data);
		node->data = data;
		return true;
	}

	return hashtab_add(ht, key, data);
}

bool hashtab_remove(hashtab *ht, const char *key)
{
	unsigned hash = hash_func(key);
	unsigned index = hash & ht->mask;
	hashtab_node_t *node = ht->nodes[index];
	hashtab_node_t *prev_node = NULL;

	while (node) {
		if (node->hash == hash && strcmp(key, node->key) == 0) {
			if (prev_node)
				prev_node->next = node->next;
			else
				ht->nodes[index] = node->next;

			if (ht->free_func)
				ht->free_func(node->key, node->data);
			free(node);
			ht->used--;
			return true;
		}

		prev_node = node;
		node = node->next;
	}

	return false;
}

void hashtab_reset_callback(hashtab *ht, void (*free_data)(const char *key, void *data))
{
	for (unsigned i = 0; i < ht->size; i++) {
		hashtab_node_t *node = ht->nodes[i];
		while (node) {
			hashtab_node_t *next_node = node->next;
			if (free_data)
				free_data(node->key, node->data);
			free(node);
			node = next_node;
		}
	}

	ht->used = 0;
}

void hashtab_reset(hashtab *ht)
{
	hashtab_reset_callback(ht, ht->free_func);
}

bool hashtab_foreach(hashtab *ht, bool (*foreach)(const char *key, void *data))
{
	for (unsigned i = 0; i < ht->size; i++) {
		hashtab_node_t *node = ht->nodes[i];
		while (node) {
			bool result = foreach(node->key, node->data);
			if (result)
				return result;
			node = node->next;
		}
	}

	return false;
}

void hashtab_delete_callback(hashtab *ht, void (*free_data)(const char *key, void *data))
{
	hashtab_reset_callback(ht, free_data);
	free(ht->nodes);
#ifndef NDEBUG
	ht->nodes = NULL;
	ht->size = 0;
	ht->mask = 0;
	ht->used = 0;
#endif
	free(ht);
}

void hashtab_delete(hashtab *ht)
{
	hashtab_delete_callback(ht, ht->free_func);
}

//	Utility functions that just uses 'free()' to free the data, no members of data are included.
void hashtab_free_data_callback(const char *key, void *data)
{
	free(data);
}
void hashtab_reset_free(hashtab *ht)
{
	hashtab_reset_callback(ht, hashtab_free_data_callback);
}
void hashtab_delete_free(hashtab *ht)
{
	hashtab_delete_callback(ht, hashtab_free_data_callback);
}


#ifdef __SUPERC__		// Super C interface

impl HashTable
{
	HashTable *new(unsigned capacity) => hashtab_create(capacity);

	set void free_func(void (*free_func)(const char *key, void *data))
		{ hashtab_set_free_func(this, free_func); }

	bool add(const char *key, void *data) => hashtab_add(this, key, data);
	bool add_copy(const char *key, void *data, size_t size)
		=> hashtab_add_copy(this, key, data, size);

	bool insert(const char *key, void *data) => hashtab_add(this, key, data);
	bool insert_copy(const char *key, void *data, size_t size)
		=> hashtab_add_copy(this, key, data, size);

	void *find(const char *key) const => hashtab_find(this, key);
	bool foreach(bool (*foreach)(const char *key, void *data))
		=> hashtab_foreach(this, foreach);

	bool update(const char *key, void *data) => hashtab_update(this, key, data);
	bool remove(const char *key) => hashtab_remove(this, key);

	void reset() { hashtab_reset(this); }
	void reset_callback(void (*free_data)(const char *key, void *data))
			{ hashtab_reset_callback(this, free_data); }

	void delete() { hashtab_delete(this); }
	void delete_callback(void (*free_data)(const char *key, void *data))
		{ hashtab_delete_callback(this, free_data); }

	void reset_free() { hashtab_reset_free(this); }
	void delete_free() { hashtab_delete_free(this); }
}

impl static HashTable
{
	void free_data_callback(const char *key, void *data)
		{ hashtab_free_data_callback(key, data); }
}

#endif
