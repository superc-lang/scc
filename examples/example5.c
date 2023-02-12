#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//	This is another example of a (small string optimized) string class.
//	The class has a union, if the string length is small enough (8 bytes on 64-bit machines), then it's stored directly inside.
//	If the string length exceeds the internal buffer, then it's stored on the heap (with calls to malloc() and realloc())
//	This is just a demonstration!

//	Compile with:
//	clear && make clean && make debug && ./scc -g -ast -Wall ./examples/example5.c -o test && ./test

#define MAX_SSO	sizeof(void*)	// 64 bit = 8 bytes, 32 bit = 4 bytes ... you could also double this, eg. `(sizeof(void*) * 2)`

typedef struct string {
	size_t _length;
	union _str {
		char ss[MAX_SSO];
		char *p;
	} _str;
} string;

impl string
{
	//	`constructor`
	void init(const char *str)
	{
		self->_length = strlen(str);
		if (self->_length < MAX_SSO) {
			strcpy((char*) &self->_str.ss, str);
		} else {
			self->_str.p = (char *) malloc(self->_length + 1);
			strcpy(self->_str.p, str);
		}
	}

	string *new(const char *str)
	{
		string *_ = (string *) malloc(sizeof(string));
		_->init(str);
		return _;
	}

	get static inline size_t len() const => self->_length;
	get static inline size_t length() const => self->_length;

	get static inline const char *c_str() const => self->_length < MAX_SSO ? (char*) &self->_str.ss : self->_str.p;
	static inline const char *c_str() const => self->c_str;

	set static inline const char *c_str(const char *str)
	{
		size_t len = strlen(str);
		if (self->_length < MAX_SSO) {
			self->_length = len;
			if (len < MAX_SSO) {
				strcpy((char*) &self->_str.ss, str);
			} else {
				self->_str.p = (char *) malloc(len + 1);
				strcpy(self->_str.p, str);
			}
		} else {
			self->_length = len;
			if (len < MAX_SSO) {
				free(self->_str.p);
				strcpy((char*) &self->_str.ss, str);
			} else {
				self->_str.p = (char *) realloc(self->_str.p, len + 1);
				strcpy(self->_str.p, str);
			}
		}

		return str;
	}

	static inline string *cat(const char *str)
	{
		size_t len = strlen(str);
		size_t new_len = self->_length + len;
		if (new_len < MAX_SSO) {
			strcat(self->_str.ss, str);
		} else {
			if (self->_length < MAX_SSO) {
				char *p = (char *) malloc(new_len + 1);
				strcpy(p, (char*) &self->_str.ss);
				strcat(p, str);
				self->_str.p = p;
			} else {
				self->_str.p = (char *) realloc(self->_str.p, new_len + 1);
				strcat(self->_str.p, str);
			}
			self->_length = new_len;
		}
		return self;
	}

	//	`destructor`
	void dtor()
	{
		if (self->_length >= MAX_SSO)
			free(self->_str.p);
	}

	void reset()
	{
		self->dtor();
		self->_length = 0;
		self->_str.ss[0] = '\0';
	}

	void delete()
	{
		self->dtor();
		free(self);
	}
}

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

	str2.reset();

	printf("str2 length after reset: %lu\n", str2.len);

	str2.c_str = "New string!";	//	Calls the 'c_str' 'setter'

	printf("str2.c_str: %s\n", str2.c_str);
	printf("str2.len: %lu\n", str2.len);

	str2.dtor();	//	destructor

	return 0;
}
