#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//	This is just an example of a length prefixed string class.
//	There would still be many 'gotcha' moments, like when you 'cat' the string,
//		you would need to re-assign the value because the realloc() might return a new address!
//	But if you designed a string class like this in C, and had 'helper' methods, you would still land up with the same issues.


typedef struct string {
	size_t _length;
	char _str[];
} string;

impl string
{
	string *new(const char *str)
	{
		size_t len = strlen(str);
		string *s = (string *) malloc(sizeof(string) + len + 1);
		s->_length = len;
		strcpy(s->_str, str);
		return s;
	}

	get static inline size_t len() => this->_length;
	get static inline size_t length() => this->_length;

	get static inline const char *str() => this->_str;

	static inline string *cat(const char *str)
	{
		size_t len = strlen(str);
		string *s = (string *) realloc(this, sizeof(string) + this->_length + len + 1);
		s->_length += len;
		strcat(s->_str, str);
		return s;
	}

	void delete()
	{
		free(this);
	}
}

int main(int argc, const char *argv[])
{
	string *str = new string("Hello");

	printf("str->str: %s\n", str->str);
	printf("str->len: %lu\n", str->len);

	str = str->cat(" World!");

	printf("str->str: %s\n", str->str);
	printf("str->len: %lu\n", str->len);

	delete str;

	return 0;
}
