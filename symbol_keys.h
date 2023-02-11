#pragma once

void symbol_keys_init();
const char *get_symbol_key(const char *key, unsigned hash);	//	Automatically adds key to hash table if it doesn't exist. Returns the "permanent" address of the key. 
void symbol_keys_print();
void symbol_keys_reset();

//	I do notice that it has many collisions. "SuperFastHash" has a lot less, but it's SOO much more complicated and possibly slower! This is `fast` for small strings (I hope!)
static inline unsigned symbol_hash(const char *key)
{
	unsigned hash = 5381;
	int c;

	while ((c = *key++))
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
}
