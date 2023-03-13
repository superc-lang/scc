#pragma once

#include "ast.h"

#include <stdbool.h>

extern union ast_node *root_node;

struct compiler_flags {
	// int optimization_level;
	// bool verbose;
	bool debug;
	bool ast;
	// const char *compiler;
	// const char *output_filename;
	// const char *input_filename;
	// const char *input_filename_no_ext;
	// const char *input_filename_ext;
	// const char *input_filename_path;
};

extern struct compiler_flags flags;
