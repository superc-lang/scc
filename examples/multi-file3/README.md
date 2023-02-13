## Full featured hash table implementation

This is a full featured hash table implemented in standard C, with a Super C interface wrapper.

This example highlights an important aspect of Super C, that is, the ability to incrementally add Super C features to existing C code.

With the `__SUPERC__` macro, you can test the presence of Super C in your code, and use it to generate the Super C interface wrapper.

While also maintaining backwards compatibility with existing standard C code.

The hash table implementation has many features that are not present in the example script.

The one big issue this highlights about standard C, is the lack of 'generics'.
In languages like C++, Rust, Java or C#, you would be able to define a generic hash table class that can store the exact data type in the data member.
This is not really a problem if you're just storing a pointer, but it becomes a problem when you want to store a structure that you'll need to first allocate on the heap.
So normally I would have to create a custom hash table implementation. I do have other workarounds, using macros or defining the data type size and reserving the space.
But none of those common C solutions are ideal, and just feel like hacks.

So generics is one of the top features on my wishlist for Super C.

#### Compile from root dir:

```bash
./scc ./examples/multi-file3/main.c ./examples/multi-file3/hashtab.c -o test
```

#### main.c

```c
int main(int argc, const char *argv[])
{
	HashTable *ht = new HashTable(0);

	const char *values[][2] = {
		{"Hello", "World"},
		{"Ford", "Mustang"},
		{"Ferrari", "Enzo"},
		{"Porsche", "911"},
		{ NULL, NULL}
	};

	for (int i = 0; values[i][0] != NULL; i++) {
		ht->insert(values[i][0], (void*) values[i][1]);
	}

	for (int i = 0; values[i][0] != NULL; i++) {
		printf("%s %s\n", values[i][0], (char*) ht->find(values[i][0]));
	}

	delete ht;

	return 0;
}
```

#### expected output:

```txt
Hello World
Ford Mustang
Ferrari Enzo
Porsche 911
```

### C Output

#### main.i

NOTE: I've removed the content from the `#include` directives for brevity.
But you can see it's output in the `hashtab.i` file below!

```c
int main(int argc, const char *argv[])
{
	HashTable *ht = HashTable__new(0);

	const char *values[][2] = {
		{"Hello", "World"},
		{"Ford", "Mustang"},
		{"Ferrari", "Enzo"},
		{"Porsche", "911"},
		{((void*) 0), ((void*) 0)}
	};

	for (int i = 0; values[i][0] != ((void*) 0); i++) {
		HashTable__insert(ht, values[i][0], (void*) values[i][1]);
	}

	for (int i = 0; values[i][0] != ((void*) 0); i++) {
		printf("%s %s\n", values[i][0], (char*) HashTable__find(ht, values[i][0]));
	}

	HashTable__delete(ht);

	return 0;
}
```

---

#### hashtab.i

```c
//	standard C methods

typedef struct hashtab  hashtab;

hashtab *hashtab_create(unsigned est_capacity);

void hashtab_set_free_func(hashtab *ht, void (*free_func)(const char *key, void *data));
_Bool hashtab_add(hashtab *ht, const char *key, void *data);
_Bool hashtab_add_copy(hashtab *ht, const char *key, void *data, size_t size);
void *hashtab_find(const hashtab *ht, const void *key);
_Bool hashtab_foreach(hashtab *ht, _Bool (*foreach)(const char *key, void *data));
_Bool hashtab_update(hashtab *ht, const char *key, void *data);
_Bool hashtab_remove(hashtab *ht, const char *key);
void hashtab_reset(hashtab *ht);
void hashtab_reset_callback(hashtab *ht, void (*free_data)(const char *key, void *data));
void hashtab_delete(hashtab *ht);
void hashtab_delete_callback(hashtab *ht, void (*free_data)(const char *key, void *data));
void hashtab_free_data_callback(const char *key, void *data);
void hashtab_reset_free(hashtab *ht);
void hashtab_delete_free(hashtab *ht);

//	Super C interface wrapper methods converted to standard C.

typedef hashtab HashTable;	//	NOTE: you don't need to define a new typedef!

HashTable *HashTable__new(unsigned capacity);

void HashTable__set__free_func(HashTable *self, void (*free_func)(const char *key, void *data));

_Bool HashTable__add(HashTable *self, const char *key, void *data);

_Bool HashTable__add_copy(HashTable *self, const char *key, void *data, size_t size);

_Bool HashTable__insert(HashTable *self, const char *key, void *data);

_Bool HashTable__insert_copy(HashTable *self, const char *key, void *data, size_t size);

void *HashTable__find(const HashTable *self, const char *key);

_Bool HashTable__foreach(HashTable *self, _Bool (*foreach)(const char *key, void *data));

_Bool HashTable__update(HashTable *self, const char *key, void *data);

_Bool HashTable__remove(HashTable *self, const char *key);

void HashTable__reset(HashTable *self);

void HashTable__reset_callback(HashTable *self, void (*free_data)(const char *key, void *data));

void HashTable__delete(HashTable *self);

void HashTable__delete_callback(HashTable *self, void (*free_data)(const char *key, void *data));

void HashTable__reset_free(HashTable *self);

void HashTable__delete_free(HashTable *self);

void HashTable__free_data_callback(const char *key, void *data);

typedef struct hashtab_node_t  hashtab_node_t;

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
	while ((c = *key++)) 	hash = ((hash >> 5) + hash) + c;
	return hash;
}

static inline unsigned int next_pow_2(unsigned int n)
{
	n--;
	n |= n << 1;
	n |= n << 2;
	n |= n << 4;
	n |= n << 8;
	n |= n << 16;
	n++;
	return n;
}

hashtab *hashtab_create(unsigned est_capacity)
{
	hashtab *ht = (hashtab*) malloc(sizeof(hashtab));
	if (ht == ((void*) 0))
		return ((void*) 0);
	size_t size = est_capacity ? next_pow_2(est_capacity) : 8;
	ht->size = size;
	ht->mask = size - 1;
	ht->used = 0;
	ht->free_func = ((void*) 0);
	ht->nodes = (hashtab_node_t**) calloc(size, sizeof(hashtab_node_t*));
	if (ht->nodes == ((void*) 0)) {
		free(ht);
		return ((void*) 0);
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

_Bool hashtab_add(hashtab *ht, const char *key, void *data)
{
	if (ht->used == ht->size)
		hashtab_expand(ht);
	unsigned hash = hash_func(key);
	unsigned index = hash & ht->mask;
	hashtab_node_t *node = (hashtab_node_t*) malloc(sizeof(hashtab_node_t) + strlen(key) + 1);
	if (node == ((void*) 0))
		return 0;
	node->next = ht->nodes[index];
	node->data = data;
	node->hash = hash;
	strcpy(node->key, key);
	ht->nodes[index] = node;
	ht->used++;
	return 1;
}

_Bool hashtab_add_copy(hashtab *ht, const char *key, void *data, size_t size)
{
	void *copy = malloc(size);
	if (copy == ((void*) 0))
		return 0;
	memcpy(copy, data, size);
	_Bool result = hashtab_add(ht, key, copy);
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
	return ((void*) 0);
}

void *hashtab_find(const hashtab *ht, const void *key)
{
	hashtab_node_t *node = hashtab_find_node(ht, key);
	return node ? node->data : ((void*) 0);
}

_Bool hashtab_update(hashtab *ht, const char *key, void *data)
{
	hashtab_node_t *node = hashtab_find_node(ht, key);
	if (node) {
		if (ht->free_func)
			ht->free_func(node->key, node->data);
		node->data = data;
		return 1;
	}
	return hashtab_add(ht, key, data);
}

_Bool hashtab_remove(hashtab *ht, const char *key)
{
	unsigned hash = hash_func(key);
	unsigned index = hash & ht->mask;
	hashtab_node_t *node = ht->nodes[index];
	hashtab_node_t *prev_node = ((void*) 0);
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
			return 1;
		}
		prev_node = node;
		node = node->next;
	}
	return 0;
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

_Bool hashtab_foreach(hashtab *ht, _Bool (*foreach)(const char *key, void *data))
{
	for (unsigned i = 0; i < ht->size; i++) {
		hashtab_node_t *node = ht->nodes[i];
		while (node) {
			_Bool result = foreach(node->key, node->data);
			if (result)
				return result;
			node = node->next;
		}
	}
	return 0;
}

void hashtab_delete_callback(hashtab *ht, void (*free_data)(const char *key, void *data))
{
	hashtab_reset_callback(ht, free_data);
	free(ht->nodes);
	ht->nodes = ((void*) 0);
	ht->size = 0;
	ht->mask = 0;
	ht->used = 0;
	free(ht);
}

void hashtab_delete(hashtab *ht)
{
	hashtab_delete_callback(ht, ht->free_func);
}

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

HashTable *HashTable__new(unsigned capacity)
{
	return hashtab_create(capacity);
}

void HashTable__set__free_func(HashTable *this, void (*free_func)(const char *key, void *data))
{
	hashtab_set_free_func(this, free_func);
}

_Bool HashTable__add(HashTable *this, const char *key, void *data)
{
	return hashtab_add(this, key, data);
}

_Bool HashTable__add_copy(HashTable *this, const char *key, void *data, size_t size)
{
	return hashtab_add_copy(this, key, data, size);
}

_Bool HashTable__insert(HashTable *this, const char *key, void *data)
{
	return hashtab_add(this, key, data);
}

_Bool HashTable__insert_copy(HashTable *this, const char *key, void *data, size_t size)
{
	return hashtab_add_copy(this, key, data, size);
}

void *HashTable__find(const HashTable *this, const char *key)
{
	return hashtab_find(this, key);
}

_Bool HashTable__foreach(HashTable *this, _Bool (*foreach)(const char *key, void *data))
{
	return hashtab_foreach(this, foreach);
}

_Bool HashTable__update(HashTable *this, const char *key, void *data)
{
	return hashtab_update(this, key, data);
}

_Bool HashTable__remove(HashTable *this, const char *key)
{
	return hashtab_remove(this, key);
}

void HashTable__reset(HashTable *this)
{
	hashtab_reset(this);
}

void HashTable__reset_callback(HashTable *this, void (*free_data)(const char *key, void *data))
{
	hashtab_reset_callback(this, free_data);
}

void HashTable__delete(HashTable *this)
{
	hashtab_delete(this);
}

void HashTable__delete_callback(HashTable *this, void (*free_data)(const char *key, void *data))
{
	hashtab_delete_callback(this, free_data);
}

void HashTable__reset_free(HashTable *this)
{
	hashtab_reset_free(this);
}

void HashTable__delete_free(HashTable *this)
{
	hashtab_delete_free(this);
}

void HashTable__free_data_callback(const char *key, void *data)
{
	hashtab_free_data_callback(key, data);
}
```
