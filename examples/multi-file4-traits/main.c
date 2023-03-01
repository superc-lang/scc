#include <stdio.h>

#include "hashtab.h"

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

	// ht->insert("Hello", "World");
	// ht->insert("Ford", "Mustang");
	// ht->insert("Ferrari", "Enzo");
	// ht->insert("Porsche", "911");

	// printf("Hello %s\n", (char*) ht->find("Hello"));
	// printf("Ford %s\n", (char*) ht->find("Ford"));
	// printf("Ferrari %s\n", (char*) ht->find("Ferrari"));
	// printf("Porsche %s\n", (char*) ht->find("Porsche"));

	delete ht;

	return 0;
}
