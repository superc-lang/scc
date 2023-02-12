#include <stddef.h>
#include <stdlib.h>

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
	void init(const char *str);

	string *new(const char *str);

	get static inline size_t len() const => self->_length;
	get static inline size_t length() const => self->_length;

	get static inline const char *c_str() const => self->_length < MAX_SSO ? (char*) &self->_str.ss : self->_str.p;
	static inline const char *c_str() const => self->c_str;

	set const char *c_str(const char *str);

	string *cat(const char *str);

	//	`destructor`
	static inline void dtor()
	{
		if (self->_length >= MAX_SSO)
			free(self->_str.p);
	}

	static inline void reset()
	{
		self->dtor();
		self->_length = 0;
		self->_str.ss[0] = '\0';
	}

	static inline void delete()
	{
		self->dtor();
		free(self);
	}
}
