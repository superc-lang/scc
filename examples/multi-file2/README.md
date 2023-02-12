#### Compile with (from root dir):

```bash
./scc -Wall ./examples/multi-file2/main.c ./examples/multi-file2/string.c -o test && ./test
```

#### expected output:

```txt
str->str: Hello
str->len: 5
str->str: Hello World!
str->len: 12
str2.c_str: Hi
str2.len: 2
str2.c_str: Hi, how are you?
str2.len: 16
str2.c_str: New string made with 'c_str' 'setter'!
str2.len: 38
```

### C Output

#### main.i

NOTE: I've removed the content from the `#include "string.h"` directive for brevity.
But you can see it's output in the `string.i` file below!

```c
int main(int argc, const char *argv[])
{
	string *str = string__new("Hello");
	printf("str->str: %s\n", string__get__c_str(str));
	printf("str->len: %lu\n", string__get__len(str));
	str = string__cat(str, " World!");
	printf("str->str: %s\n", string__get__c_str(str));
	printf("str->len: %lu\n", string__get__len(str));
	string__delete(str);
	string str2;
	string__init(&str2, "Hi");
	printf("str2.c_str: %s\n", string__get__c_str(&str2));
	printf("str2.len: %lu\n", string__get__len(&str2));
	string__cat(&str2, ", how are you?");
	printf("str2.c_str: %s\n", string__get__c_str(&str2));
	printf("str2.len: %lu\n", string__get__len(&str2));
	string__set__c_str(&str2, "New string made with 'c_str' 'setter'!");
	printf("str2.c_str: %s\n", string__get__c_str(&str2));
	printf("str2.len: %lu\n", string__get__len(&str2));
	string__dtor(&str2);
	return 0;
}
```

---

#### string.i

```c
typedef struct string {
	size_t _length;
	union _str {
		char ss[sizeof(void*)];
		char *p;
	} _str;
} string;

void string__init(string *self, const char *str);

string *string__new(const char *str);

static inline size_t string__get__len(const string *self)
{
	return self->_length;
}

static inline size_t string__get__length(const string *self)
{
	return self->_length;
}

static inline const char *string__get__c_str(const string *self)
{
	return self->_length < sizeof(void*) ? (char*) &self->_str.ss : self->_str.p;
}

static inline const char *string__c_str(const string *self)
{
	return string__get__c_str(self);
}

const char *string__set__c_str(string *self, const char *str);

string *string__cat(string *self, const char *str);

static inline void string__dtor(string *self)
{
	if (self->_length >= sizeof(void*)) 	free(self->_str.p);
}

static inline void string__reset(string *self)
{
	string__dtor(self);
	self->_length = 0;
	self->_str.ss[0] = '\0';
}

static inline void string__delete(string *self)
{
	string__dtor(self);
	free(self);
}

void string__init(string *self, const char *str)
{
	self->_length = strlen(str);
	if (self->_length < sizeof(void*)) {
		strcpy((char*) &self->_str.ss, str);
	} else {
		self->_str.p = (char*) malloc(self->_length + 1);
		strcpy(self->_str.p, str);
	}
}

string *string__new(const char *str)
{
	string *s = (string*) malloc(sizeof(string));
	string__init(s, str);
	return s;
}

const char *string__set__c_str(string *self, const char *str)
{
	size_t len = strlen(str);
	if (self->_length < sizeof(void*)) {
		self->_length = len;
		if (len < sizeof(void*)) {
			strcpy((char*) &self->_str.ss, str);
		} else {
			self->_str.p = (char*) malloc(len + 1);
			strcpy(self->_str.p, str);
		}
	} else {
		self->_length = len;
		if (len < sizeof(void*)) {
			free(self->_str.p);
			strcpy((char*) &self->_str.ss, str);
		} else {
			self->_str.p = (char*) realloc(self->_str.p, len + 1);
			strcpy(self->_str.p, str);
		}
	}
	return str;
}

string *string__cat(string *self, const char *str)
{
	size_t len = strlen(str);
	size_t new_len = self->_length + len;
	if (new_len < sizeof(void*)) {
		strcat(self->_str.ss, str);
	} else {
		if (self->_length < sizeof(void*)) {
			char *p = (char*) malloc(new_len + 1);
			strcpy(p, (char*) &self->_str.ss);
			strcat(p, str);
			self->_str.p = p;
		} else {
			self->_str.p = (char*) realloc(self->_str.p, new_len + 1);
			strcat(self->_str.p, str);
		} 		self->_length = new_len;
	}
	return self;
}
```
