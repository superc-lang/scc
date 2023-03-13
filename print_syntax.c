#include "print_syntax.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>

void print_original_syntax(const char *yyfilename, int yylineno, const char *errmsg, ...)
{
	va_list args;
	va_start(args, errmsg);

#	define MAX_BUF 2048
	static char buf[MAX_BUF];

	int len = vsnprintf(buf, MAX_BUF, errmsg, args);
	if (len >= 2) {
		// Check that buf has a newline at the end
		if (buf[len - 1] != '\n') {
			assert(MAX_BUF > len + 2);
			assert(MAX_BUF >= 2048); // We are unlikely to ever write an error message this long!
			buf[len] = '\n';
			buf[len + 1] = '\0';
		}
	}

	if (yyfilename == NULL || yyfilename[0] == '\0') {
		fprintf(stderr, "%s", buf);
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "%s:%d: %s", yyfilename, yylineno, buf);

	FILE *fp = fopen(yyfilename, "r");
	if (fp == NULL) {
		fprintf(stderr, "Error opening file: %s\n", yyfilename);
		exit(EXIT_FAILURE);
	}

	int current_line = 0;
	while (fgets(buf, MAX_BUF, fp) != NULL) {
		current_line++;
		if (current_line >= yylineno - 1 && current_line <= yylineno + 1) {
			fprintf(stderr, "%c%5d | %s", current_line == yylineno ? '>' : ' ', current_line, buf);
		}
	}

	va_end(args);
}
