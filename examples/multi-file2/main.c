#include <stdio.h>

#include "string.h"

int main(int argc, const char *argv[])
{
	// heap allocated 'string' object

	string *str = new string("Hello");

	printf("str->str: %s\n", str->c_str);
	printf("str->len: %lu\n", str->len);

	str = str->cat(" World!");

	printf("str->str: %s\n", str->c_str);
	printf("str->len: %lu\n", str->len);

	delete str;


	// stack allocated 'string' object 

	string str2;
	str2.init("Hi");

	printf("str2.c_str: %s\n", str2.c_str);
	printf("str2.len: %lu\n", str2.len);

	str2.cat(", how are you?");

	printf("str2.c_str: %s\n", str2.c_str);
	printf("str2.len: %lu\n", str2.len);

	str2.c_str = "New string made with 'c_str' 'setter'!";

	printf("str2.c_str: %s\n", str2.c_str);
	printf("str2.len: %lu\n", str2.len);

	str2.dtor();	//	destructor

	return 0;
}
