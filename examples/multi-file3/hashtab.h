#include <stddef.h>
#include <stdlib.h>

typedef struct hashtab hashtab;

hashtab *hashtab_create(unsigned est_capacity);

void hashtab_set_free_func(hashtab *ht, void (*free_func)(const char *key, void *data));

bool hashtab_add(hashtab *ht, const char *key, void *data);
bool hashtab_add_copy(hashtab *ht, const char *key, void *data, size_t size);

void *hashtab_find(const hashtab *ht, const void *key);
bool hashtab_foreach(hashtab *ht, bool (*foreach)(const char *key, void *data));

bool hashtab_update(hashtab *ht, const char *key, void *data);

bool hashtab_remove(hashtab *ht, const char *key);

void hashtab_reset(hashtab *ht);
void hashtab_reset_callback(hashtab *ht, void (*free_data)(const char *key, void *data));

void hashtab_delete(hashtab *ht);
void hashtab_delete_callback(hashtab *ht, void (*free_data)(const char *key, void *data));

void hashtab_free_data_callback(const char *key, void *data);
void hashtab_reset_free(hashtab *ht);
void hashtab_delete_free(hashtab *ht);


#ifndef __SUPERC__
#define __SUPERC__ 1	// Just to avoid syntax highlighting issues
#endif

#ifdef __SUPERC__		// Super C interface

typedef hashtab HashTable;

impl HashTable
{
	HashTable *new(unsigned capacity);

	set void free_func(void (*free_func)(const char *key, void *data));

	bool add(const char *key, void *data);
	bool add_copy(const char *key, void *data, size_t size);

	//	synonyms for `add` and `add_copy`
	bool insert(const char *key, void *data);
	bool insert_copy(const char *key, void *data, size_t size);

	void *find(const char *key) const;
	// void *get(const char *key) const;

	bool foreach(bool (*foreach)(const char *key, void *data));

	bool update(const char *key, void *data);
	bool remove(const char *key);

	void reset();
	void reset_callback(void (*free_data)(const char *key, void *data));
	
	void delete();
	void delete_callback(void (*free_data)(const char *key, void *data));
	
	void reset_free();
	void delete_free();
}

impl static HashTable
{
	void free_data_callback(const char *key, void *data);
}

#endif
