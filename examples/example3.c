#include <stdio.h>
#include <string.h>

typedef const char String;

impl String
{
	get static size_t len() => strlen(this);
}

int main(int argc, const char *argv[])
{
	String *str = "Hello World!";

	printf("str.len: %lu\n", str->len);

	return 0;
}
