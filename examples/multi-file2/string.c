#include <string.h>
#include <stdlib.h>

#include "string.h"

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
		string *s = (string *) malloc(sizeof(string));
		s->init(str);
		return s;
	}

	set const char *c_str(const char *str)
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

	string *cat(const char *str)
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
}
