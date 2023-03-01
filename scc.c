#include <stdlib.h>		// for: malloc, free
#include <stdio.h>		// for: fprintf, stderr, fopen, fclose, fread, fwrite
#include <stdint.h>		// for: uint8_t
#include <string.h>		// for: memcpy
#include <stdbool.h>	// for: bool, true, false
#include <assert.h>		// for: assert
#include <stdarg.h>		// for: va_args

#include "lex.yy.h"

#define YYMAXDEPTH 10000000 // seems to do nothing!
#include "parser.tab.h"

#include "ast.h"
#include "ast_helpers.h"
#include "ast_nodes.h"

#include "symbol_table.h"

#include "codegen.h"
#include "print_ast_tree.h"
#include "indent.h"

#include "scc.h"
#include "compiler_passes.h"

#define SUPERC_VERSION 1


int error_count = 0;
extern FILE *yyin;

#define BUFSIZE 512
#define SENTINEL_SIZE 8
static char buf[BUFSIZE + SENTINEL_SIZE];


#define FUNCTION_NAME_SIZE 256
static char func_name[FUNCTION_NAME_SIZE];


#define MAX_COMMAND (1024 * 4)	// 4k `command line` buffer
char command[MAX_COMMAND];


// static inline void indent(FILE *out, int n);


union ast_node *ast_root;


struct compiler_flags flags = {
	// .optimization_level = 0,
	// .verbose = false,
	.debug = false,
	.ast = false,
};


// Create a linked list of filenames to compile
struct filename_list {
	struct filename_list *next;
	char filename[];
};
// List of transpiled files. These files end with '.i' extension so GCC knows they have been pre-processed! 
struct filename_list *transpiled_filenames = NULL;

void add_transpiled_file(const char *filename)
{
	struct filename_list *new = malloc(sizeof(struct filename_list) + strlen(filename) + 1);
	if (new == NULL) {
		fprintf(stderr, "ERROR: failed to allocate memory for filename list\n");
		exit(EXIT_FAILURE);
	}
	strcpy(new->filename, filename);
	new->next = NULL;

	if (transpiled_filenames == NULL) {
		transpiled_filenames = new;
	} else {
		struct filename_list *last = transpiled_filenames;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = new;
	}
}


struct input_filename_list {
	struct input_filename_list *next;
	const char *filename;				// original input filename ... taken from argv[]
};
struct input_filename_list *input_filenames = NULL;

void add_input_file(const char *filename)
{
	struct input_filename_list *new = malloc(sizeof(struct input_filename_list));
	if (new == NULL) {
		fprintf(stderr, "ERROR: failed to allocate memory for input filename\n");
		exit(EXIT_FAILURE);
	}
	new->filename = filename;
	new->next = NULL;

	if (input_filenames == NULL) {
		input_filenames = new;
	} else {
		struct input_filename_list *last = input_filenames;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = new;
	}
}



struct input_filename_list *object_filenames = NULL;

void add_object_file(const char *filename)
{
	struct input_filename_list *new = malloc(sizeof(struct input_filename_list));
	if (new == NULL) {
		fprintf(stderr, "ERROR: failed to allocate memory for input filename\n");
		exit(EXIT_FAILURE);
	}
	new->filename = filename;
	new->next = NULL;

	if (object_filenames == NULL) {
		object_filenames = new;
	} else {
		struct input_filename_list *last = object_filenames;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = new;
	}
}



struct string_list {
	struct string_list *next;
	const char *argv;
	char string[];
};
struct string_list *pp_commands = NULL;				// eg. -D NDEBUG (disables assert)
struct string_list *compiler_commands = NULL;

void add_preprocessor_arg(const char *arg)
{
	struct string_list *new = malloc(sizeof(struct string_list));
	if (new == NULL) {
		fprintf(stderr, "ERROR: failed to allocate memory for compiler command list	\n");
		exit(EXIT_FAILURE);
	}
	new->argv = arg;
	new->next = NULL;

	if (pp_commands == NULL) {
		pp_commands = new;
	} else {
		struct string_list *last = pp_commands;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = new;
	}
}

// Add a custom command string, eg. -I/usr/include or a filename
// This is different to the `argv` or `args` below, in that they (args) are basically 'const' allocated!
void add_compiler_command(const char *command)
{
	struct string_list *new = malloc(sizeof(struct string_list) + strlen(command) + 1);
	if (new == NULL) {
		fprintf(stderr, "ERROR: failed to allocate memory for compiler command list	\n");
		exit(EXIT_FAILURE);
	}
	strcpy(new->string, command);
	new->argv = NULL;
	new->next = NULL;
	
	if (compiler_commands == NULL) {
		compiler_commands = new;
	} else {
		struct string_list *last = compiler_commands;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = new;
	}
}

// `args` come from the argv[] array!
void add_compiler_arg(const char *arg)
{
	struct string_list *new = malloc(sizeof(struct string_list));
	if (new == NULL) {
		fprintf(stderr, "ERROR: failed to allocate memory for compiler command list	\n");
		exit(EXIT_FAILURE);
	}
	new->argv = arg;
	new->next = NULL;

	if (compiler_commands == NULL) {
		compiler_commands = new;
	} else {
		struct string_list *last = compiler_commands;
		while (last->next != NULL) {
			last = last->next;
		}
		last->next = new;
	}
}

void compile_files()
{
	// Create final compiler command
	strcpy(command, "gcc");

	struct filename_list *fl = transpiled_filenames;
	while (fl != NULL) {
		strncat(command, " ", MAX_COMMAND - strlen(command) - 1);
		strncat(command, fl->filename, MAX_COMMAND - strlen(command) - 1);
		fl = fl->next;
	}

	struct input_filename_list *o = object_filenames;
	while (o != NULL) {
		strncat(command, " ", MAX_COMMAND - strlen(command) - 1);
		strncat(command, o->filename, MAX_COMMAND - strlen(command) - 1);
		o = o->next;
	}

	struct string_list *sl = compiler_commands;
	while (sl != NULL) {
		strncat(command, " ", MAX_COMMAND - strlen(command) - 1);
		strncat(command, sl->argv ? sl->argv : sl->string, MAX_COMMAND - strlen(command) - 1);
		sl = sl->next;
	}
	fprintf(stdout, "%s\n", command);

	// Execute the GCC compiler
	int result = system(command);
	(void) result;
}



// Loop through args and set compiler flags, record filesnames, etc.
// optimization_level = 0, 1, 2, 3 (default 0) -O0, -O1, -O2, -O3
// -D = define a macro ... must be added to preprocessor commands list (pp_commands)
// -o <filename> = output filename
// -g = generate debugging info
// -Wall = enable all warnings
// -ast = ouput both ast files
// -ast-before = ouput only ast 'before' file
// -ast-after = ouput only ast 'after' file
void process_args(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++) {
		if (argv[i][0] == '-') {
			if (argv[i][1] == 'O') {
				add_compiler_arg(argv[i]);

			// } else if (strcmp(argv[i], "-v") == 0) {		-Wl,–verbose
			// 	flags.verbose = true;
			// } else if (strcmp(argv[i], "-d") == 0) {
			// 	flags.debug = true;
			} else if (strcmp(argv[i], "-ast") == 0) {
				flags.ast = true;
			// } else if (strcmp(argv[i], "-c") == 0) {
			// 	flags.compiler = "gcc";

			} else if (argv[i][1] == 'g' && argv[i][2] == '\0') {		//	`-g` == generate debugging information!
			 	flags.debug = true;
				add_compiler_arg(argv[i]);

			} else if (strcmp(argv[i], "-o") == 0) {			//	Output filename. For the compiler/linker!
				if (i + 1 < argc) {
					if (argv[i + 1][0] == '-') {
						fprintf(stderr, "ERROR: invalid output filename '%s' after -o\n", argv[i + 1]);
						exit(EXIT_FAILURE);
					}
					add_compiler_arg(argv[i]);
					add_compiler_arg(argv[i + 1]);
					i++;
				} else {
					fprintf(stderr, "ERROR: missing output filename after '-o'\n");
					exit(EXIT_FAILURE);
				}
			} else if (argv[i][1] == 'D') {	//	Define a macro. Must be added to preprocessor commands list (pp_commands)
				if (argv[i][2] == '\0') {
					if (i + 1 < argc) {
						add_preprocessor_arg(argv[i]);
						add_preprocessor_arg(argv[i + 1]);
						i++;
					} else {
						fprintf(stderr, "ERROR: missing macro name after '-D'\n");
						exit(EXIT_FAILURE);
					}
				} else {
					add_preprocessor_arg(argv[i]);
				}

			// } else if (strcmp(argv[i], "-v") == 0) {		-Wl,–verbose
			// 	flags.verbose = true;
			// } else if (strcmp(argv[i], "-d") == 0) {
			// 	flags.debug = true;

			} else if (strcmp(argv[i], "-I") == 0) {	//	Add search path to header files (.h) or (.hpp).
				if (i + 1 < argc) {
					add_preprocessor_arg(argv[i]);
					add_preprocessor_arg(argv[i + 1]);
					i++;
				} else {
					fprintf(stderr, "ERROR: missing include path after '-I'\n");
					exit(EXIT_FAILURE);
				}
			} else if (strcmp(argv[i], "-L") == 0) {
				if (i + 1 < argc) {
					struct string_list *new = malloc(sizeof(struct string_list) + strlen(argv[i + 1]) + 1);
					new->next = pp_commands;
					new->argv = argv[i + 1];
					strcpy(new->string, argv[i + 1]);
					pp_commands = new;
					i++;
				} else {
					fprintf(stderr, "ERROR: missing library path after '-L'\n");
					exit(EXIT_FAILURE);
				}
			} else if (strcmp(argv[i], "-l") == 0) {	//	Link a library. Must be added to preprocessor commands list (pp_commands)
				if (i + 1 < argc) {
					// struct string_list *new = malloc(sizeof(struct string_list) + strlen(argv[i + 1]) + 1);
					// new->next = pp_commands;
					// new->argv = argv[i + 1];
					// strcpy(new->string, argv[i + 1]);
					// pp_commands = new;
					i++;
				} else {
					fprintf(stderr, "ERROR: missing library name after '-l'\n");
					exit(EXIT_FAILURE);
				}
			} else if (strcmp(argv[i], "-Wall") == 0) {
				//	Is this a preprocessor command as well???
				add_compiler_arg(argv[i]);
				add_preprocessor_arg(argv[i]);
			} else {
				add_compiler_arg(argv[i]);
				// fprintf(stderr, "ERROR: invalid argument '%s'\n", argv[i]);
				// exit(EXIT_FAILURE);
			}
		} else {
			//	Check if the file ends with .c (or .sc?)
			if (strcmp(argv[i] + strlen(argv[i]) - 2, ".c") != 0) {
				if (strcmp(argv[i] + strlen(argv[i]) - 2, ".o") != 0) {
					fprintf(stderr, "ERROR: invalid input file '%s'. Must be a `.c` file (C source code) or `.o` (object) file\n", argv[i]);
					exit(EXIT_FAILURE);
				}

				//	We have an object file. Add it to the list of object files to link!
// printf(".o file: %s\n", argv[i]);
// exit(1);
				add_object_file(argv[i]);
				continue;
			}

			add_input_file(argv[i]);

			// if (flags.input_filename == NULL) {
			// 	flags.input_filename = argv[i];
			// } else {
			// 	fprintf(stderr, "ERROR: multiple input files specified\n");
			// 	exit(EXIT_FAILURE);
			// }
		}
	}

	if (input_filenames == NULL) {
		if (object_filenames == NULL) {
			fprintf(stderr, "ERROR: missing input filename\n");
			exit(EXIT_FAILURE);
		}

		//	We have only object files to link. No need to transpile!

	}
}

#	define MAX_FILENAME 512
static char fn_buf[MAX_FILENAME];

void write_ast_tree_to_file(const char *filename_no_ext, const char *before_or_after, union ast_node *node)
{
	if (flags.debug || flags.ast) {
		snprintf(fn_buf, MAX_FILENAME, "%s.ast.%s.txt", filename_no_ext, before_or_after);
		FILE *file = fopen(fn_buf, "w+");
		if (file == NULL) {
			fprintf(stderr, "ERROR: failed to open output file '%s'\n", fn_buf);
			exit(EXIT_FAILURE);
		}
		print_ast_tree(file, ast_root, 0, NULL);
		fclose(file);
	}
}


void transpile_file(const char *filename)
{
	// static char filename_no_ext[MAX_FILENAME];		//	will sort this out later! Currently allocating heap for the name!
	static char pp_filename[MAX_FILENAME];
	// static char ast_before_filename[MAX_FILENAME];
	// static char ast_after_filename[MAX_FILENAME];
	static char output_filename[MAX_FILENAME];

	// Create a preprocessor command to execute the GCC preprocessor
	snprintf(command, MAX_COMMAND, "gcc -E %s -D __SUPERC__=%d", filename, SUPERC_VERSION);
	struct string_list *sl = pp_commands;
	while (sl != NULL) {
		strncat(command, " ", MAX_COMMAND - strlen(command) - 1);
		strncat(command, sl->argv ? sl->argv : sl->string, MAX_COMMAND - strlen(command) - 1);
		sl = sl->next;
	}
	// fprintf(stdout, "%s\n", command);

	// Execute the GCC preprocessor on the input file
	FILE *fp = popen(command, "r");
	if (fp == NULL) {
		fprintf(stderr, "ERROR: failed to open or process file '%s'\n", filename);
		exit(EXIT_FAILURE);
	}

	char *buffer = buf;
	size_t size = fread(buf, 1, BUFSIZE, fp);
	if (size == BUFSIZE) {
		// create a dynamic buffer and read more data
		char *tmpbuf = (char *) malloc(size + SENTINEL_SIZE);
		// copy contents of buffer to tmpbuf
		memcpy(tmpbuf, buf, size);
		size_t pos = 0;
		for (;;) {
			// read more data
			size_t n = fread(buf, 1, BUFSIZE, fp);
			if (n > 0) {
				pos = size;
				size += n;
				// printf("realloc(tmpbuf, %d)\n", (int) size);
				tmpbuf = (char *) realloc(tmpbuf, size + SENTINEL_SIZE);
				memcpy(&tmpbuf[pos], buf, n);
				if (n < BUFSIZE) {
					break;
				}
			} else {
				break;
			}
		}
		buffer = tmpbuf;

		// add EOF sentinel
		memset(&tmpbuf[size], 0, SENTINEL_SIZE);

	} else if (size == 0) {
		//	The following error happens when for example the file doesn't exist.
		// fprintf(stderr, "Unknown error detected while trying to read from input stream\n");
		exit(EXIT_FAILURE);
	}

	if (pclose(fp) != 0) {
		// I got this error when the preprocessor failed to process the input file!
		// fprintf(stderr, "Unknown error detected while closing file handle\n");
		exit(EXIT_FAILURE);
	}

	//	Extract base filename from path
	const char *filename_no_ext = filename;
	const char *filename_ext = NULL;
	for (int i = strlen(filename) - 1; i >= 0; i--) {
		if (filename[i] == '.') {
			filename_ext = &filename[i];
			break;
		}
	}
	if (filename_ext == NULL) {
		filename_ext = &filename[strlen(filename)];
	}
	int filename_no_ext_len = filename_ext - filename_no_ext;
	char *filename_no_ext_copy = (char *) malloc(filename_no_ext_len + 1);
	memcpy(filename_no_ext_copy, filename_no_ext, filename_no_ext_len);
	filename_no_ext_copy[filename_no_ext_len] = '\0';
	filename_no_ext = filename_no_ext_copy;

	//	Open and write buffer to macro preprocessor output file
	snprintf(pp_filename, MAX_FILENAME, "%s.sc.i", filename_no_ext);
	FILE *pp_out = fopen(pp_filename, "w+");
	if (pp_out == NULL) {
		fprintf(stderr, "ERROR: failed to open output file '%s'\n", pp_filename);
		exit(EXIT_FAILURE);
	}
	if (fwrite(buffer, 1, size, pp_out) != size) {
		fprintf(stderr, "ERROR: failed to write preprocessor output file '%s'\n", pp_filename);
		exit(EXIT_FAILURE);
	}
	fclose(pp_out);

	//	Begin transpiling

	symbol_table_init();
	symbol_table_push_scope();		//	Push global scope

	yy_scan_bytes(buffer, size);

	// error_count = 0;

	// yydebug = 1;	// requires Bison to be compiled with -t/--debug flag
	int parse_result = yyparse();

	if (buffer != buf) {
		free(buffer);
	}

	write_ast_tree_to_file(filename_no_ext, "before", ast_root);

	//	We at least try to print out the `before` AST tree, even if the parser failed.
	if (parse_result != 0 || error_count > 0) {
		fprintf(stderr, "ERROR: failed to parse input file '%s'\n", filename);
		fprintf(stderr, "Parse result: %d, Errors %d\n", parse_result, error_count);
		exit(EXIT_FAILURE);
	}

	run_compiler_passes();

	write_ast_tree_to_file(filename_no_ext, "after", ast_root);


	snprintf(output_filename, MAX_FILENAME, "%s.i", filename_no_ext);
	FILE *out = fopen(output_filename, "w+");
	if (out == NULL) {
		fprintf(stderr, "ERROR: failed to open output file '%s'\n", output_filename);
		exit(EXIT_FAILURE);
	}
	codegen(out, ast_root, 0, NULL);
	fclose(out);

	add_transpiled_file(output_filename);	//	Add filename to final list of files to compile with GCC!

	// if (flags.debug || flags.ast) {
	// 	snprintf(ast_after_filename, MAX_FILENAME, "%s.ast.after.txt", filename_no_ext);
	// 	FILE *ast_after = fopen(ast_after_filename, "w+");
	// 	if (ast_after == NULL) {
	// 		fprintf(stderr, "ERROR: failed to open output file '%s'\n", ast_after_filename);
	// 		exit(EXIT_FAILURE);
	// 	}
	// 	print_ast_tree(ast_after, ast_root, 0, NULL);
	// 	fclose(ast_after);
	// }

	// printf("----------------------   Symbol table   ---------------------\n");
	// symbol_table_print(stdout);
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//	Process command line arguments
	process_args(argc, argv);

	//	Loop through and transpile all input files
	struct input_filename_list *input_filename = input_filenames;
	while (input_filename != NULL) {
		transpile_file(input_filename->filename);
		input_filename = input_filename->next;
	}

	//	Execute GCC (or other backend compiler) to compile all files
	// if (flags.compile) {
		compile_files();
	// }
}



int __main__(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	const char *filename = argv[1];

	// Create a command to execute the GCC preprocessor
	snprintf(command, MAX_COMMAND, "gcc -E %s", filename);
	// printf("command: %s\n", command);

	// Execute the GCC preprocessor on the input file
	FILE *fp = popen(command, "r");
	if (fp == NULL) {
		fprintf(stderr, "ERROR failed to open or process file '%s'\n", filename);
		exit(EXIT_FAILURE);
	}

	char *buffer = buf;
	size_t size = fread(buf, 1, BUFSIZE, fp);
	if (size == BUFSIZE) {
		// create a dynamic buffer and read more data
		char *tmpbuf = (char *) malloc(size + SENTINEL_SIZE);
		// copy contents of buffer to tmpbuf
		memcpy(tmpbuf, buf, size);
		size_t pos = 0;
		for (;;) {
			// read more data
			size_t n = fread(buf, 1, BUFSIZE, fp);
			if (n > 0) {
				pos = size;
				size += n;
				// printf("realloc(tmpbuf, %d)\n", (int) size);
				tmpbuf = (char *) realloc(tmpbuf, size + SENTINEL_SIZE);
				memcpy(&tmpbuf[pos], buf, n);
				if (n < BUFSIZE) {
					break;
				}
			} else {
				break;
			}
		}
		buffer = tmpbuf;

		// add EOF sentinel
		memset(&tmpbuf[size], 0, SENTINEL_SIZE);

	} else if (size == 0) {
		//	The following error happens when for example the file doesn't exist.
		// fprintf(stderr, "Unknown error detected while trying to read from input stream\n");
		exit(EXIT_FAILURE);
	}

	if (pclose(fp) != 0) {
		// I got this error when the preprocessor failed to process the input file!
		// fprintf(stderr, "Unknown error detected while closing file handle\n");
		exit(EXIT_FAILURE);
	}

	//	Write out file contents after initial macro expansion (preprocessing)!

	FILE *fd = fopen("./pp-output.i", "w+");
	fwrite(buffer, 1, size, fd);
	fclose(fd);

	symbol_table_init();
	symbol_table_push_scope();		//	Push global scope

	yy_scan_bytes(buffer, size);

	// yydebug = 1;	// requires Bison to be compiled with -t/--debug flag
	int parse_result = yyparse();

	//	Write AST tree BEFORE transformation.

	FILE *ast_before = fopen("./output.ast.before.txt", "w+");
	print_ast_tree(ast_before, ast_root, 0, NULL);
	fclose(ast_before);

	if (parse_result != 0 || error_count > 0) {
		exit(EXIT_FAILURE);
	}

	//	Reset the symbol table, for a `clean` codegen run

	symbol_table_init();
	symbol_table_push_scope();		//	Push global scope

	FILE *out = fopen("./output.i", "w+");
	codegen(out, ast_root, 0, NULL);
	fclose(out);

	//	Write AST tree AFTER transformation.

	FILE *ast_after = fopen("./output.ast.after.txt", "w+");
	print_ast_tree(ast_after, ast_root, 0, NULL);
	fclose(ast_after);

	// printf("----------------------   Symbol table   ---------------------\n");
	// symbol_table_print(stdout);

	if (buffer != buf) {
		free(buffer);
	}

	return 0;
}
























//
//	This is the main function that adds pointer parameters to a function scope! eg. func(Point *foo); where `foo` is the parameter we add. The parent decl_specs is AST_ID node for the data type, eg. `Point`.
//
void add_pointer_param_to_function_scope(union ast_node *node, union ast_node *parent)
{
	if (node == NULL) return;

	switch (node->type) {

	case AST_ID:
		symbol_add_pointer(node->id.id, parent->parameter_declaration.decl_specs);
		break;

	case AST_THIS:
		symbol_add_pointer("this", parent->parameter_declaration.decl_specs);
		break;

	case AST_SELF:
		symbol_add_pointer("self", parent->parameter_declaration.decl_specs);
		break;

	default:
		fprintf(stderr, "FATAL ERROR: unhandled node type %s (%d) in %s:%d (%s)\n", get_node_name(node->type), node->type, __FILE__, __LINE__, __FUNCTION__);
		exit(EXIT_FAILURE);
		return;
	}
}

void add_params_to_function_scope(union ast_node *node, union ast_node *parent)
{
	if (node == NULL) return;

	union ast_node *tmp;

	switch (node->type) {

	case AST_ID:
		symbol_add_variable(node->id.id, parent->parameter_declaration.decl_specs);
		break;

	case AST_THIS:
		symbol_add_variable("this", parent->parameter_declaration.decl_specs);
		break;

	case AST_SELF:
		symbol_add_variable("self", parent->parameter_declaration.decl_specs);
		break;

	case AST_POINTER_DECLARATOR:
	//	NOTE: This is the main breakout point to add pointer params! Notice the call to `add_pointer_param_...`
		add_pointer_param_to_function_scope(node->pointer_declarator.direct_declarator, parent);
		return;

	case AST_LIST:
		add_params_to_function_scope(node->list.node, parent);
		add_params_to_function_scope(node->list.next, parent);
		return;

	case AST_UNSPECIFIED_ARRAY:
		add_params_to_function_scope(node->unspecified_array.direct_declarator, parent);
		return;

	case AST_DYNAMIC_ARRAY:
		add_params_to_function_scope(node->dynamic_array.direct_declarator, parent);
		return;

	case AST_STATIC_ARRAY:
		add_params_to_function_scope(node->array.direct_declarator, parent);
		return;

	case AST_ARRAY:
		add_params_to_function_scope(node->array.direct_declarator, parent);
		return;

	case AST_PARAMETER_DECLARATION:
		//	At this point, we ONLY add `typedef`'s to the function scope, not regular variables!
		//	One reason is that a lot of the code has an assert on symbol->node->type == AST_ID!
		//	WARNING: This is very fragile! When I added `const` to the functions, it broke this code because it then put the AST_ID in an AST_LIST!!
		tmp = get_id_node(node->parameter_declaration.decl_specs);
		if (tmp && tmp->type == AST_ID) {
			add_params_to_function_scope(node->parameter_declaration.declarator, node); // NOTE: We pass `node` as the parent, not `parent`!
		}
		return;

	case AST_FUNCTION_DECLARATOR:	//	For callback functions: eg. `int (*callback)(int i)`
		add_params_to_function_scope(node->function_declarator.direct_declarator, parent);
		return;

	case AST_GROUPED_DECLARATOR:	//	Part of the callback functions: eg. `int (*callback)(int i)` ... this is the `(*callback)` part! `function_declarator.direct_declarator` is the `callback` part!
		add_params_to_function_scope(node->grouped_declarator.declarator, parent);
		return;

	case AST_ABSTRACT_DECLARATOR:	//	eg. `int [3]`, `int []` etc. Dunno why you use or want to do this!
		add_params_to_function_scope(node->abstract_declarator.direct_abstract_declarator, parent);
		return;

/*
		if (node->parameter_declaration.declarator->type == AST_POINTER_DECLARATOR) {
			printf("-------------------------------------------------------- node->parameter_declaration.declarator->type == AST_POINTER_DECLARATOR\n");
			tmp = node->parameter_declaration.declarator->pointer_declarator.direct_declarator;
		} else if (node->parameter_declaration.declarator->type == AST_UNSPECIFIED_ARRAY) {
			printf("-------------------------------------------------------- node->parameter_declaration.declarator->type == AST_UNSPECIFIED_ARRAY\n");
			tmp = node->parameter_declaration.declarator->unspecified_array.direct_declarator;
		} else if (node->parameter_declaration.declarator->type == AST_DYNAMIC_ARRAY) {
			printf("-------------------------------------------------------- node->parameter_declaration.declarator->type == AST_DYNAMIC_ARRAY\n");
			tmp = node->parameter_declaration.declarator->dynamic_array.direct_declarator;
		} else if (node->parameter_declaration.declarator->type == AST_STATIC_ARRAY) {
			printf("-------------------------------------------------------- node->parameter_declaration.declarator->type == AST_STATIC_ARRAY\n");
			tmp = node->parameter_declaration.declarator->array.direct_declarator;
		} else {
			printf("-------------------------------------------------------- node->parameter_declaration.declarator->type != AST_POINTER_DECLARATOR\n");
			tmp = node->parameter_declaration.declarator;
		}

		symbol = new__symbol();
		symbol->node = node;

		if (tmp->type == AST_ID) {
			printf("-------------------------------------------------------- tmp->type == AST_ID\n");
			key = tmp->id.id;
		} else if (tmp->type == AST_THIS) {
			printf("-------------------------------------------------------- tmp->type == AST_THIS\n");
			key = "this";
		} else if (tmp->type == AST_SELF) {
			printf("-------------------------------------------------------- tmp->type == AST_SELF\n");
			key = "self";
		} else {
			fprintf(stderr, "FATAL ERROR: unhandled node type %d (%s) in %s:%d (%s)\n", tmp->type, get_node_name(tmp->type), __FILE__, __LINE__, __FUNCTION__);
			exit(EXIT_FAILURE);
		}

printf("-------------------------------------------------------- Adding param %s to function scope\n", key);
		hash_map_add(&function_scope_symbols, key, symbol);
*/
		//add_params_to_function_scope(node->parameter_declaration.declarator);
		return;

	case AST_ELLIPSIS:
		return;

	case AST__ATTRIBUTE__:
		return;

	case AST_DECLARATION:
		add_params_to_function_scope(node->declaration.init_declarator_list, parent);
		return;

	// case AST_ARRAY_SUBSCRIPT:
	// 	tmp = find_this_or_self_id(node->array_subscript.array);
	// 	if (tmp) return tmp;
	// 	return find_this_or_self_id(node->array_subscript.index);

	default:
		fprintf(stderr, "FATAL ERROR: unhandled node type %d (%s) in %s:%d (%s)\n", node->type, get_node_name(node->type), __FILE__, __LINE__, __FUNCTION__);
		exit(EXIT_FAILURE);
		return;
	}

	return;
}









































//	Expands both regular function calls as well as calls to getters and setters!
//	By `expanding` we mean to replace calls like car->model with Car__get__model(car), new Car() with Car__new(), car->drive() with Car__drive(car, ...)
void expand_function_calls(union ast_node *node, union ast_node *parent)
{
	if (node == NULL) return;

	switch (node->type) {

	case AST_LIST:
		expand_function_calls(node->list.node, parent);
		expand_function_calls(node->list.next, parent);
		break;

	case AST_FUNCTION_CALL:
		// fn_call = &node->function_call;
		// if (fn_call->direct_declarator->type == AST_ID) {
		// 	name = fn_call->direct_declarator;
		// } else if (fn_call->direct_declarator->type == AST_POINTER_DECLARATOR) {
		// 	name = fn_call->direct_declarator->pointer_declarator.direct_declarator;
		// } else {
		// 	fprintf(stderr, "Error: Unsupported function call type: %d (%s)\n", fn_call->direct_declarator->type, get_node_name(fn_call->direct_declarator->type));
		// 	exit(EXIT_FAILURE);
		// }

		//	Step 1, make sure the "impl" `id` is a registered typedef! ... OR, we can just do that in the parser!
		//	Step 1, detach the impl node from the parent! Attach the body nodes instead!

		printf("<<<<<<<<<<<<<<<<<<<---------------->>>>>>>>>>>>>>>>>>>>> Function call detected: `%s`\n", node->function_call.function->id.id);

		//	Step 2, find the function definition!
	case AST_FUNCTION_DEFINITION:
		printf("<<<<<<<<<<<<<<<<<<<---------------->>>>>>>>>>>>>>>>>>>>> Function definition: `%s`\n", node->function_definition.declarator->function_declarator.direct_declarator->id.id);
		printf("HOW do you have a function definition here?!\n"); /// I think this is a callback function definition!

	
	}
}




























void check_for_setter(union ast_node *node, union ast_node *parent)
{
	if (node == NULL) return;

	switch (node->type) {

	case AST_ASSIGN:
		check_for_setter(node->binary.left, parent);
		break;

	case AST_MEMBER_ACCESS:

		break;

	// case AST_MEMBER_ACCESS:

		break;
	}
}

































/**
 *	Recursively loop through each AST tree node; generating the final transpiled C source code
 */
void _codegen(FILE *out, union ast_node *node, int depth, union ast_node *parent)
{
	if (node == NULL) return;

	union ast_node *tmp;
	symbol_t *symbol;

	switch (node->type) {

	case AST_PRAGMA:
		fprintf(out, "#pragma %s\n", node->pragma.pragma);
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier`

	/*
	type_specifier
		: VOID
		| CHAR
		| SHORT
		| INT
		| LONG
		| FLOAT
		| DOUBLE
		| SIGNED
		| UNSIGNED
		| BOOL
		| COMPLEX
		| IMAGINARY
		| ...
		;
	*/

	case AST_VOID:
		fprintf(out, "void");
		break;
	case AST_CHAR:
		fprintf(out, "char");
		break;
	case AST_SHORT:
		fprintf(out, "short");
		break;
	case AST_INT:
		fprintf(out, "int");
		break;
	case AST_LONG:
		fprintf(out, "long");
		break;
	case AST_FLOAT:
		fprintf(out, "float");
		break;
	case AST_DOUBLE:
		fprintf(out, "double");
		break;
	case AST_SIGNED:
		fprintf(out, "signed");
		break;
	case AST_UNSIGNED:
		fprintf(out, "unsigned");
		break;
	case AST_BOOL:
		fprintf(out, "_Bool");
		break;
	case AST_COMPLEX:
		fprintf(out, "_Complex");
		break;
	case AST_IMAGINARY:
		fprintf(out, "_Imaginary");
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ...

	/*
	type_specifier
		: ...
		| atomic_type_specifier
		| struct_or_union_specifier
		| enum_specifier
		| TYPEDEF_NAME
		;
	*/

	case AST_ATOMIC:
		fprintf(out, "_Atomic");
		break;

	case AST_ATOMIC_TYPE:
		fprintf(out, "_Atomic (");
		codegen(out, node->atomic_type.type_name, depth, node);
		fprintf(out, ")");
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ... GCC Extensions

	case AST__BUILTIN_VA_LIST:
		fprintf(out, "__builtin_va_list");
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ... GCC _Decimal32, _Decimal64, _Decimal128 extensions

	case AST__DECIMAL32:
		fprintf(out, "_Decimal32");
		break;

	case AST__DECIMAL64:
		fprintf(out, "_Decimal64");
		break;

	case AST__DECIMAL128:
		fprintf(out, "_Decimal128");
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ... GCC _Float128 extension

	case AST__FLOAT128:
		fprintf(out, "_Float128");
		break;

	//	-----------------------------------------------------------------------
	//	`type_specifier` continued ... GCC __int128 extension

	case AST__INT128:
		fprintf(out, "__int128");		//	As of GCC 4.6 - Source: https://stackoverflow.com/a/54815033
		break;

	case AST__INT128_T:
		fprintf(out, "__int128_t");	//	As of GCC 4.1 - Source: https://stackoverflow.com/a/54815033
		break;

	case AST__UINT128_T:
		fprintf(out, "__uint128_t");	//	As of GCC 4.1 - Source: https://stackoverflow.com/a/54815033
		break;

	//	NOTE: I don't think I should support a dedicated _BitInt(128)! Just use the AST__BITINT type with 128! That is what the static node uses when it detects `_BitInt(123)`
	// case AST__BITINT128:		//	Clang `_BitInt(128)` support (https://clang.llvm.org/docs/LanguageExtensions.html#bitint)  &&  https://clang.llvm.org/docs/LanguageExtensions.html#extended-integer-types
	// 	fprintf(out, "_BitInt(128)");	//	Note: Clang originally had `_ExtInt(N)` which has been deprecated in favor of the C23 standard `_BitInt(N)`
	// 	break;

	//	C23 _BitInt(N)
	case AST__BITINT:
		fprintf(out, "_BitInt(%d)", node->bitint.n);
		break;

	//	-----------------------------------------------------------------------
	//	GCC __attribute__ extension

	case AST__ATTRIBUTE__:
		fprintf(out, "%s", node->attribute.src_code);
		//codegen(out, node->attribute.src_code, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	GCC __asm__ extension

	case AST__ASM__:
		fprintf(out, "%s", node->str.str);
		break;



	//	-----------------------------------------------------------------------
	//	`storage_class_specifier`

	/*
	storage_class_specifier
		: TYPEDEF	//	identifiers must be flagged as TYPEDEF_NAME
		| EXTERN
		| STATIC
		| THREAD_LOCAL
		| AUTO
		| REGISTER
		;
	*/
	case AST_TYPEDEF:
		fputs("\ntypedef", out);
		break;
	case AST_EXTERN:
		fprintf(out, "extern");
		break;
	case AST_STATIC:
		fprintf(out, "static");
		break;
	case AST_THREAD_LOCAL:
		fprintf(out, "_Thread_local");
		break;
	case AST_AUTO:
		fprintf(out, "auto");
		break;
	case AST_REGISTER:
		fprintf(out, "register");
		break;


	/* GCC "__extension__" */
	case AST__EXTENSION__:
		fprintf(out, "__extension__");
		break;




	/*
	struct_or_union_specifier
		: struct_or_union '{' struct_declaration_list '}'
		| struct_or_union IDENTIFIER '{' struct_declaration_list '}'
		| struct_or_union IDENTIFIER
		;

	struct_or_union
		: STRUCT
		| UNION
		;
	*/
	case AST_STRUCT:
		///indent(out, depth);
		if (node->struct_or_union.id)
			fprintf(out, "struct %s ", node->struct_or_union.id->id.id);
		else
			fprintf(out, "struct ");
		goto struct_or_union;

	case AST_UNION:
		//indent(out, depth);
		if (node->struct_or_union.id)
			fprintf(out, "union %s ", node->struct_or_union.id->id.id);
		else
			fprintf(out, "union ");
		goto struct_or_union;

	struct_or_union:
		if (node->struct_or_union.decl_list) {
			fprintf(out, "{\n");
			codegen(out, node->struct_or_union.decl_list, depth + 1, node);
			indent(out, depth);
			fprintf(out, "}");
		}
		break;

	/*
	struct_declaration_list
		: struct_declaration
		| struct_declaration_list struct_declaration
		;

	struct_declaration
		: specifier_qualifier_list ';'	//	for anonymous struct/union
		| specifier_qualifier_list struct_declarator_list ';'
		| static_assert_declaration
		;

	specifier_qualifier_list
		: type_specifier specifier_qualifier_list
		| type_specifier
		| type_qualifier specifier_qualifier_list
		| type_qualifier
		;

	struct_declarator_list
		: struct_declarator
		| struct_declarator_list ',' struct_declarator
		;

	struct_declarator
		: ':' constant_expression
		| declarator ':' constant_expression
		| declarator
		;
	*/
	case AST_STRUCT_OR_UNION_DECLARATION:
		indent(out, depth);
		codegen(out, node->struct_or_union_declaration.spec_qual_list, depth, node);
		if (node->struct_or_union_declaration.decl_list) {
			fprintf(out, " ");
			codegen(out, node->struct_or_union_declaration.decl_list, depth, node);
		}
		fprintf(out, ";\n");
		break;

	case AST_STRUCT_OR_UNION_DECLARATOR:
		codegen(out, node->struct_or_union_declarator.declarator, depth, node);
		if (node->struct_or_union_declarator.expr) {
			fprintf(out, ": ");
			codegen(out, node->struct_or_union_declarator.expr, depth, node);
		}
		break;


	case AST_ENUM:
		indent(out, depth);
		if (node->enum_type.id)
			fprintf(out, "enum %s ", node->enum_type.id->id.id);
		else
			fprintf(out, "enum ");

		if (node->enum_type.list) {
			fprintf(out, "{\n");
			codegen(out, node->enum_type.list, depth + 1, node);
			fprintf(out, "\n");
			indent(out, depth);
			fprintf(out, "}");
		}
		break;

	case AST_ENUM_INIT:
		indent(out, depth);
		if (node->binary.right == NULL) {
			fprintf(out, "%s", node->binary.left->id.id);
		} else {
			fprintf(out, "%s = ", node->binary.left->id.id);
			codegen(out, node->binary.right, depth, node);
		}
		break;

	// case AST_ENUM_CONSTANT:
	// 	fprintf(out, "%s", node->id.id);
	// 	break;


	case AST_TYPEDEF_NAME:					/* same as AST_ID */
		fprintf(out, "%s", node->id.id);
		break;

	//	-----------------------------------------------------------------------

	case AST_LIST:
		codegen(out, node->list.node, depth, node);
		fprintf(out, "%s", node->list.separator);
		codegen(out, node->list.next, depth, node);
		break;

	//	-----------------------------------------------------------------------

	case AST_BLOCK:
		fprintf(out, "{\n");
		codegen(out, node->block.stmts, depth + 1, node);
		indent(out, depth);
		if ((parent->type == AST_IF && parent->if_stmt.if_false != NULL) || parent->type == AST_DO_WHILE) {
		// if (parent->type == AST_DO_WHILE) {
			fprintf(out, "}");
		} else {
			fprintf(out, "}\n");
		}
		break;

	//	-----------------------------------------------------------------------


	case AST_DECLARATION:
		//	This is a relatively fast check. However, I think maybe we should have a special `AST_GENERIC_DECLARATION` node type, which is only used for generic declarations ... to make this check faster.
		if (node->declaration.init_declarator_list == NULL) {
			union ast_node *decl_specs = node->declaration.decl_specs;
			if (is_typeof_node(AST_GENERIC_DECLARATION, decl_specs)) {
printf("FOUND GENERIC SPECIFIER!\n");
				//	Disabling the check for `typedef` ... to support `opaque` generics!
				//	Is the `typedef` check necessary?
				if (1 || is_typeof_node(AST_TYPEDEF, decl_specs)) {

					build_generic_struct(node);

					// printf("FOUND GENERIC SPECIFIER WITH TYPEDEF!\n");
					//	We need to generate the typedef here, because the generic type is not a real type, but a placeholder for a real type
					// indent(out, depth);
					// fprintf(out, "typedef struct %s {", get_generic_type_name(node->declaration.decl_specs));

						// Retrieve the generic template structure, and run through it while replacing the generic type with the real/concrete type

					// fprintf(out, " } %s;\n", get_generic_type_name(node->declaration.decl_specs));

					// TODO: We need to build/expand/replace the generic template structure!
					// break;
				} else {
// build_generic_struct(node);

				}
			} else if (is_typeof_node(AST_GENERIC_STRUCT, decl_specs) || is_typeof_node(AST_GENERIC_UNION, decl_specs)) {
printf("NOT FOUND GENERIC SPECIFIER!\n");
				codegen(out, decl_specs, depth, node);
				break;
			}
		}

print_ast_tree(stdout, node, 0, 0);
printf("begin register_typedef\n");
		register_typedef(node->declaration.decl_specs, node->declaration.init_declarator_list);
printf("being register_declaration\n");
		register_declaration(node);
printf("end register_declaration\n");

		if (parent != NULL && parent->type != AST_FOR) {
			indent(out, depth);
		}
		codegen(out, node->declaration.decl_specs, depth, node);
		if (node->declaration.init_declarator_list) {
			fputc(' ', out);
			codegen(out, node->declaration.init_declarator_list, depth, node);	//	struct test { int a; } t = { 1 }; ... this represents the "t" (if used without initialization!) and "t = { 1 }" part
		} else {	//	This might be a generic node: `typedef Vec3<float>;` ... which wouldn't have a init_declarator_list
			// fprintf(out, " ");
			// codegen(out, node->declaration.decl_specs, depth, node);
// 			char *func_name = get_generic_type_name(node->declaration.decl_specs);
// printf("AST_DECLARATION func name: %s\n", func_name);
			if (is_typeof_node(AST_GENERIC_DECLARATION, node->declaration.decl_specs)) {
				//printf("FOUND GENERIC SPECIFIER!\n");
			}
		}
		if (parent != NULL && parent->type == AST_FOR) {
			fputs("; ", out);
		} else {
			fputs(";\n", out);
		}
		break;

	case AST_POINTER_DECLARATOR:
		codegen(out, node->pointer_declarator.pointer, depth, node);
		codegen(out, node->pointer_declarator.direct_declarator, depth, node);
		break;

	case AST_POINTER:
		fputc('*', out);
		if (node->pointer.type_qualifier_list) {
			codegen(out, node->pointer.type_qualifier_list, depth, node);
			fputc(' ', out);	//	solved a problem where `char *__restrict __bar` -> `char *__restrict__bar` (missing space)
		}
		codegen(out, node->pointer.pointer, depth, node);
		break;


	case AST_FUNCTION_DEFINITION:
		// printf("AST_FUNCTION_DEFINITION: `%s`\n", tmp->id.id);
		fprintf(out, "\n");
		codegen(out, node->function_definition.decl_specs, depth, node);
		if (node->function_definition.decl_specs->type != AST_ABSTRACT_TYPE_NAME)
			fputc(' ', out);
		codegen(out, node->function_definition.declarator, depth, node);	// This will push the function name onto the global scope, but it also processes the function params, but we ignore for now! Unless there is a function body/block, then we process the params!
		if (node->function_definition.decl_list) {
			fprintf(out, "\n");
			codegen(out, node->function_definition.decl_list, depth, node);		//	eg. main(argc, argv) int argc, char *argv[] { ... }
		}
		if (node->function_definition.block == NULL) {
			fprintf(out, ";\n");
		} else {
			fprintf(out, "\n");

			//	After the function declaration above has been pushed to the global scope, we create a new scope for the function body; then push the function params and run the body codegen, which also pushes locally declared variables onto the function scope.
			symbol_table_push_scope();
			{
				assert(node->function_definition.declarator != NULL);
			//	assert(node->function_definition.declarator->type == AST_FUNCTION_DECLARATOR);

				//	NOTE: We need to be more specific about the exact node we send to `add_params_to_function_scope`.
				//	We cannot just send the whole AST_FUNCTION_DECLARATOR, because inside `add_params_to_function_scope` we also check for this because it could be a function pointer ie. callback function!
//print_ast_tree(stdout, node->function_definition.declarator, 0, 0);
				//add_params_to_function_scope(node->function_definition.declarator->function_declarator.params, node);

				if (node->function_definition.declarator->type == AST_FUNCTION_DECLARATOR) {
					add_params_to_function_scope(node->function_definition.declarator->function_declarator.params, node);
				} else if (node->function_definition.declarator->type == AST_POINTER_DECLARATOR) {
					assert(node->function_definition.declarator->pointer_declarator.direct_declarator->type == AST_FUNCTION_DECLARATOR);
					add_params_to_function_scope(node->function_definition.declarator->pointer_declarator.direct_declarator->function_declarator.params, node);
				} else {
					//assert(0);
					printf("ERROR: Unknown AST_FUNCTION_DEFINITION .declarator type: %s (%d)\n", get_node_name(node->function_definition.declarator->type), node->function_definition.declarator->type);
					exit(EXIT_FAILURE);
				}

				codegen(out, node->function_definition.block, depth, node);
			}
			symbol_table_pop_scope();
		}
		break;


	case AST_PARAMETER_DECLARATION:
		codegen(out, node->parameter_declaration.decl_specs, depth, node);
		if (node->parameter_declaration.decl_specs->type != AST_ABSTRACT_TYPE_NAME)
			fputc(' ', out);
		codegen(out, node->parameter_declaration.declarator, depth, node);
		break;


	//	`declarator '=' initializer`
	case AST_INIT_DECLARATOR:
		codegen(out, node->init_declarator.declarator, depth, node);
		fputs(" = ", out);
		codegen(out, node->init_declarator.initializer, depth, node);
		break;


	//	-----------------------------------------------------------------------
	//	`type_name`
	//	-----------------------------------------------------------------------

	/*
	type_name
		: specifier_qualifier_list abstract_declarator
		| specifier_qualifier_list
		;
	*/

	case AST_ABSTRACT_TYPE_NAME:
		codegen(out, node->abstract_type_name.specifier_qualifier_list, depth, node);
		fputc(' ', out);
		codegen(out, node->abstract_type_name.abstract_declarator, depth, node);
		break;

	/*
	abstract_declarator
		: pointer direct_abstract_declarator
		| pointer
		| direct_abstract_declarator
		;
	*/

	case AST_ABSTRACT_DECLARATOR:
		codegen(out, node->abstract_declarator.pointer, depth, node);
		codegen(out, node->abstract_declarator.direct_abstract_declarator, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	ELLIPSIS token == "..."
	//	-----------------------------------------------------------------------

	case AST_ELLIPSIS:
		fputs("...", out);
		break;

	//	-----------------------------------------------------------------------
	//	`direct_declarator`
	//	-----------------------------------------------------------------------

	case AST_GROUPED_DECLARATOR:
		fprintf(out, "(");
		codegen(out, node->grouped_declarator.declarator, depth, node);
		fprintf(out, ")");
		break;

	case AST_UNSPECIFIED_ARRAY:
		codegen(out, node->unspecified_array.direct_declarator, depth, node);
		fprintf(out, "[");
		codegen(out, node->unspecified_array.type_qualifier_list, depth, node);
		fprintf(out, "]");
		break;

	case AST_DYNAMIC_ARRAY:
		codegen(out, node->dynamic_array.direct_declarator, depth, node);
		fprintf(out, "[");
		codegen(out, node->dynamic_array.type_qualifier_list, depth, node);
		fprintf(out, " * ]");
		break;

	case AST_STATIC_ARRAY:
		codegen(out, node->array.direct_declarator, depth, node);
		fprintf(out, "[ static ");
		if (node->array.type_qualifier_list) {
			codegen(out, node->array.type_qualifier_list, depth, node);
			fprintf(out, " ");
		}
		codegen(out, node->array.expr, depth, node);
		fprintf(out, "]");
		break;

	case AST_ARRAY:
		codegen(out, node->array.direct_declarator, depth, node);
		fprintf(out, "[");
		if (node->array.type_qualifier_list) {
			codegen(out, node->array.type_qualifier_list, depth, node);
			fprintf(out, " ");
		}
		codegen(out, node->array.expr, depth, node);
		fprintf(out, "]");
		break;

	case AST_FUNCTION_DECLARATOR:
		tmp = node->function_declarator.direct_declarator;
		assert(tmp != NULL);
		// assert(tmp->type == AST_ID); // Could also be `AST_GROUPED_DECLARATOR` for callbacks/function pointers!
		if (tmp && tmp->type == AST_ID) {
			assert(symbol_table_get_level() == 0);
			symbol_add_function(tmp->id.id, node);
		}
		codegen(out, tmp, depth, node);
		//codegen(out, node->function_declarator.direct_declarator, depth, node);

		fprintf(out, "(");
		codegen(out, node->function_declarator.params, depth, node);
		codegen(out, node->function_declarator.identifier_list, depth, node);	//	eg. int main(argc, argv) ... `identifier_list` == argc, argv ... deprecated! "This is called "old-style function definition" and it is considered as a deprecated feature in C89 and later versions of the C standard, because it can lead to confusion and errors. It is recommended to always use function prototyping to define functions in C."
		fprintf(out, ")");
		break;

	//	-----------------------------------------------------------------------




	//	-----------------------------------------------------------------------
	//	`type_qualifier`
	//	-----------------------------------------------------------------------

	/*
	type_qualifier
		: CONST
		| RESTRICT
		| VOLATILE
		| ATOMIC
		;
	*/

	case AST_CONST:
		fprintf(out, "const");
		break;
	case AST_RESTRICT:
		fprintf(out, "restrict");
		break;
	case AST_VOLATILE:
		fprintf(out, "volatile");
		break;
	// case AST_ATOMIC:
	// 	fprintf(out, "atomic");
	// 	break;

	/* GCC */
	case AST__RESTRICT:
		fprintf(out, "__restrict");
		break;


	//	-----------------------------------------------------------------------
	//	`function_specifier`
	//	-----------------------------------------------------------------------

	/*
	function_specifier
		: INLINE
		| NORETURN
		;
	*/

	case AST_INLINE:
		fprintf(out, "inline");
		break;
	case AST_NORETURN:
		fprintf(out, "_Noreturn");
		break;

	//	-----------------------------------------------------------------------
	//	GCC __inline && __inline__ extensions
	//	-----------------------------------------------------------------------

	case AST__INLINE:
		fputs("__inline", out);
		break;
	case AST__INLINE__:
		fputs("__inline__", out);
		break;

	//	-----------------------------------------------------------------------
	//	`assignment_expression`
	//	-----------------------------------------------------------------------

	case AST_ASSIGN:

		assert(node->binary.left != NULL);
		assert(node->binary.right != NULL);

		if (node->binary.left->type == AST_MEMBER_ACCESS) {
			//	We need to look for setters!
			//	eg. foo.x = 10; -> Foo__set__x(&foo, 10);
			tmp = node->binary.left->member_access.object;
			if (tmp->type == AST_ARRAY_SUBSCRIPT) {
				tmp = tmp->array_subscript.array;
				assert(tmp != NULL);
			}

			if (tmp->type == AST_ID) {
				symbol = symbol_get(tmp->id.id);
				if (symbol != NULL && symbol->is_variable) {	//	Could also be a pointer type, but not necessary eg. `Foo foo` is not a pointer!
					assert(symbol->node != NULL);

					const char *sym;
					if (symbol->node->type == AST_ID) {
						sym = symbol->node->id.id;
					} else if (symbol->node->type == AST_GENERIC_DECLARATION) {
						sym = get_generic_type_name(symbol->node);
					} else {
						assert(get_id_node(symbol->node)->type == AST_ID);
						sym = get_id_node(symbol->node)->id.id;
					}
					sprintf(func_name, "%s__set__%s", sym, node->binary.left->member_access.member->id.id);

					// check if the symbol is an AST_ID node. If it's NOT, then it's probably a normal variable. eg. AST_INT
					// if (symbol->node->type == AST_ID) {



						// This will return the data type of the variable, usually a typedef.
						// We take that typedef name, and append "__set__" to it.
						// Then we append the member name.
						// Then we append the value we are assigning to it.
						// Then we append a semicolon.
						// eg. Foo__set__x(&foo, 10);
						// sprintf(func_name, "%s__set__%s", symbol->node->id.id, node->binary.left->member_access.member->id.id);
						symbol = symbol_get(func_name);
						if (symbol != NULL) {
							// We found a setter function!
							// Alter the AST tree to call the setter function instead.

							assert(sizeof(struct ast_binary_node) >= sizeof(struct ast_function_call_node));
							// assert(offsetof(struct ast_member_access_node, object) == offsetof(struct ast_function_call_node, args));
							// assert(offsetof(node->member_access, object) == offsetof(node->function_call, args));

							tmp = node->binary.left->member_access.object;	//	NOTE: This may have changed, eg. if it's an array subscript! We need to store it again, because it will be overwritten!.

							node->type = AST_FUNCTION_CALL;
							node->function_call.function = create_id_node(func_name);
							node->function_call.args = create_list_node(create_unary_node(AST_ADDRESS_OF, tmp), node->binary.right, ", ");

							codegen(out, node, depth, parent);
							break;
						}
					// }
				}
			}
		}

		if (node->binary.left->type == AST_MEMBER_ACCESS_POINTER) {
			//	We need to look for setters!
			//	eg. foo->x = 10; -> Foo__set__x(foo, 10);
			tmp = node->binary.left->member_access.object;
			if (tmp->type == AST_ARRAY_SUBSCRIPT) {
				tmp = tmp->array_subscript.array;
				assert(tmp != NULL);
			}

			if (tmp->type == AST_ID) {
				symbol = symbol_get(tmp->id.id);
				if (symbol != NULL && symbol->is_variable) {
					assert(symbol->node != NULL);

					const char *sym;
					if (symbol->node->type == AST_ID) {
						sym = symbol->node->id.id;
					} else if (symbol->node->type == AST_GENERIC_DECLARATION) {
						sym = get_generic_type_name(symbol->node);
					} else {
						assert(get_id_node(symbol->node)->type == AST_ID);
						sym = get_id_node(symbol->node)->id.id;
					}
					sprintf(func_name, "%s__set__%s", sym, node->binary.left->member_access.member->id.id);

					// if (symbol->node->type == AST_ID) {
						// This will return the data type of the variable, usually a typedef.
						// We take that typedef name, and append "__set__" to it.
						// Then we append the member name.
						// Then we append the value we are assigning to it.
						// Then we append a semicolon.
						// eg. Foo__set__x(&foo, 10);
						// sprintf(func_name, "%s__set__%s", symbol->node->id.id, node->binary.left->member_access.member->id.id);
						symbol = symbol_get(func_name);
						if (symbol != NULL) {
							// We found the setter function!
							// Alter the AST tree to call the setter function instead.

							assert(sizeof(struct ast_binary_node) >= sizeof(struct ast_function_call_node));
							// assert(offsetof(struct ast_member_access_node, object) == offsetof(struct ast_function_call_node, args));
							// assert(offsetof(node->member_access, object) == offsetof(node->function_call, args));

							tmp = node->binary.left->member_access.object;	//	NOTE: This may have changed, eg. if it's an array subscript! We need to store it again, because it will be overwritten!.

							node->type = AST_FUNCTION_CALL;
							node->function_call.function = create_id_node(func_name);
							node->function_call.args = create_list_node(tmp, node->binary.right, ", ");

							codegen(out, node, depth, parent);
							break;
						}
					// }
				}
			}
		}

		codegen(out, node->binary.left, depth, node);
		fputs(" = ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_ADD_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" += ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_SUB_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" -= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_MUL_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" *= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_DIV_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" /= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_MOD_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" %%= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_AND_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" &= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_XOR_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" ^= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_OR_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" |= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_SHL_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" <<= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_SHR_ASSIGN:
		codegen(out, node->binary.left, depth, node);
		fputs(" >>= ", out);
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`conditional_expression`
	//	-----------------------------------------------------------------------

	case AST_TERNARY:
		codegen(out, node->ternary.cond, depth, node);
		fprintf(out, " ? ");
		codegen(out, node->ternary.true_expr, depth, node);
		fprintf(out, " : ");
		codegen(out, node->ternary.false_expr, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`logical_or_expression`
	//	-----------------------------------------------------------------------

	case AST_OR:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " || ");
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`logical_and_expression`
	//	-----------------------------------------------------------------------

	case AST_AND:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " && ");
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`inclusive_or_expression`
	//	-----------------------------------------------------------------------

	case AST_BIT_OR:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " | ");
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`exclusive_or_expression`
	//	-----------------------------------------------------------------------

	case AST_BIT_XOR:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " ^ ");
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`and_expression`
	//	-----------------------------------------------------------------------

	case AST_BIT_AND:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " & ");
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`equality_expression`
	//	-----------------------------------------------------------------------

	case AST_EQ:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " == ");
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_NE:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " != ");
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`relational_expression`
	//	-----------------------------------------------------------------------

	case AST_LT:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " < ");
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_GT:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " > ");
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_LE:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " <= ");
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_GE:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " >= ");
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`shift_expression`
	//	-----------------------------------------------------------------------

	case AST_SHL:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " >> ");
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_SHR:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " << ");
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`additive_expression`
	//	-----------------------------------------------------------------------

	case AST_ADD:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " + ");
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_SUB:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " - ");
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`multiplicative_expression`
	//	-----------------------------------------------------------------------

	case AST_MUL:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " * ");
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_DIV:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " / ");
		codegen(out, node->binary.right, depth, node);
		break;

	case AST_MOD:
		codegen(out, node->binary.left, depth, node);
		fprintf(out, " %% ");
		codegen(out, node->binary.right, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`cast_expression`
	//	-----------------------------------------------------------------------

	case AST_CAST:
		fprintf(out, "(");
		codegen(out, node->cast.type_name, depth, node);
		fprintf(out, ") ");
		codegen(out, node->cast.expr, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`unary_expression`
	//	-----------------------------------------------------------------------

	/*
	unary_expression
		: postfix_expression
		| INC unary_expression
		| DEC unary_expression
		| unary_operator cast_expression
		| SIZEOF unary_expression
		| SIZEOF '(' type_name ')'
		| ALIGNOF '(' type_name ')'
		;
	*/

	case AST_PRE_INC:
		fputs("++", out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_PRE_DEC:
		fputs("--", out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_SIZEOF_EXPR:
		fputs("sizeof ", out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_SIZEOF_TYPE:
		fputs("sizeof(", out);
		codegen(out, node->unary.expr, depth, node);
		fputc(')', out);
		break;

	case AST_ALIGNOF:
		fputs("_Alignof(", out);
		codegen(out, node->unary.expr, depth, node);
		fputc(')', out);
		break;



	//	-----------------------------------------------------------------------
	//	`unary_operator`
	//	-----------------------------------------------------------------------

	/*
	unary_operator
		: '&'				//	AST_ADDRESS_OF
		| '*'				//	AST_DEREFERENCE
		| '+'				//	AST_POSITIVE
		| '-'				//	AST_NEGATIVE
		| '~'				//	AST_BITWISE_NOT
		| '!'				//	AST_LOGICAL_NOT
		;
	*/

	case AST_ADDRESS_OF:
		fputc('&', out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_DEREFERENCE:
		fputc('*', out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_POSITIVE:
		fputc('+', out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_NEGATIVE:
		fputc('-', out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_BITWISE_NOT:
		fputc('~', out);
		codegen(out, node->unary.expr, depth, node);
		break;

	case AST_LOGICAL_NOT:
		fputc('!', out);
		codegen(out, node->unary.expr, depth, node);
		break;





	//	-----------------------------------------------------------------------
	//	`postfix_expression`
	//	-----------------------------------------------------------------------

	/*
	postfix_expression
		: primary_expression
		| postfix_expression '[' expression ']'					//	AST_ARRAY_SUBSCRIPT
		| postfix_expression '(' ')'							//	AST_FUNCTION_CALL
		| postfix_expression '(' argument_expression_list ')'	//	AST_FUNCTION_CALL
		| postfix_expression '.' IDENTIFIER						//	AST_MEMBER_ACCESS
		| postfix_expression ARROW IDENTIFIER					//	AST_MEMBER_ACCESS_POINTER
		| postfix_expression INC								//	AST_POST_INC
		| postfix_expression DEC								//	AST_POST_DEC
		| '(' type_name ')' '{' initializer_list '}'			//	AST_COMPOUND_LITERAL
		| '(' type_name ')' '{' initializer_list ',' '}'		//	AST_COMPOUND_LITERAL
		;
	*/

	case AST_ARRAY_SUBSCRIPT:
		codegen(out, node->array_subscript.array, depth, node);
		fputc('[', out);
		codegen(out, node->array_subscript.index, depth, node);
		fputc(']', out);
		break;

	case AST_FUNCTION_CALL:

		//	Convert function calls on "AST_MEMBER_ACCESS_POINTER"'s to standard C calls passing the object as the first argument.
		//	We first extract the AST_ID from the AST_MEMBER_ACCESS_POINTER, and do a symbol table lookup to get the object type.
		//	Once we have the type, we take the object type, and concatenate the member name to it, and do a symbol table lookup for a function with this name.
		//	If we find a corresponding function with this name, we change the AST_MEMBER_ACCESS_POINTER to an AST_ID, and add the object as the first argument.
		tmp = node->function_call.function;
		if (tmp->type == AST_MEMBER_ACCESS_POINTER) {
			//	If a function with this name doesn't exist, then it's going to be a an error!
			//	We need to do a symbol table lookup for the function with this name.
			//	We need to get the object type, and concatenate the member name to it, and do a symbol table lookup for a function with this name.

			union ast_node *obj = tmp->member_access.object;
			if (obj->type == AST_ARRAY_SUBSCRIPT) {
				obj = obj->array_subscript.array;
			}

			assert(obj != NULL);

			const char *id;
			if (obj->type == AST_ID) {
				id = obj->id.id;
			} else if (obj->type == AST_SELF) {
				id = "self";
			} else if (obj->type == AST_THIS) {
				id = "this";
			} else {
				fprintf(stderr, "codegen: AST_FUNCTION_CALL: AST_MEMBER_ACCESS_POINTER: object is not an AST_ID, AST_SELF or AST_THIS\n");
				exit(EXIT_FAILURE);
			}

			symbol = symbol_get(id);
			if (symbol == NULL) {
				fprintf(stderr, "ERROR: Variable declaration for `%s` not found. Are you sure you declared it?\n", id);
				exit(EXIT_FAILURE);
			}
			if (symbol->is_variable) {
				assert(symbol->node != NULL);
				assert(tmp->member_access.member != NULL);
				assert(tmp->member_access.member->type == AST_ID);
				if (tmp->member_access.member->type == AST_ID) {

					// union ast_node *sym;	//	The AST_ID might be in an AST_LIST node. eg. `const Foo`
					const char *sym;
					if (symbol->node->type == AST_ID) {
						sym = symbol->node->id.id;
					} else if (symbol->node->type == AST_GENERIC_DECLARATION) {
						sym = get_generic_type_name(symbol->node);
					} else {
						assert(get_id_node(symbol->node)->type == AST_ID);
						sym = get_id_node(symbol->node)->id.id;
					}
					sprintf(func_name, "%s__%s", sym, tmp->member_access.member->id.id);

// printf("#########################################>>>>>>>>>>> func_name: %s, %d\n", func_name, symbol->node->type);
					symbol = symbol_get(func_name);
					if (symbol != NULL) {
						if (tmp->member_access.object->type == AST_ARRAY_SUBSCRIPT) {
							tmp = create_unary_node(AST_ADDRESS_OF, tmp->member_access.object);
						} else {
							tmp = tmp->member_access.object;
						}

						//	We need to attach the member object ID to the function call argument list. eg. car->drive() becomes Car__drive(car); where we've moved the `car` object to the front of the argument list.
						if (node->function_call.args == NULL) {
							node->function_call.args = tmp;
						} else {
							node->function_call.args = create_list_node(tmp, node->function_call.args, ", ");
						}

						node->function_call.function = create_id_node(func_name);
						//  vvv fallthrough to output the new (transpiled) function call!

					} else {
						//	TODO: I had to disable this to support function pointers!

						//	WARNING: We could be calling a function pointer!
						// fprintf(stderr, "ERROR: function call %s not found\n", tmp->member_access.member->id.id);
						// exit(EXIT_FAILURE);
					}
				}
			} else {
				fprintf(stderr, "codegen: AST_FUNCTION_CALL: AST_MEMBER_ACCESS_POINTER: symbol for %s is not a variable\n", tmp->member_access.object->id.id);
				exit(EXIT_FAILURE);
			}

		} else if (tmp->type == AST_MEMBER_ACCESS) {

			union ast_node *obj = tmp->member_access.object;
			if (obj->type == AST_ARRAY_SUBSCRIPT) {
				obj = obj->array_subscript.array;
			}

			assert(obj != NULL);
			if (obj->type == AST_ID) {
				symbol = symbol_get(obj->id.id);
				if (symbol == NULL) {
					fprintf(stderr, "ERROR: Variable declaration for `%s` not found. Are you sure you declared it?\n", obj->id.id);
					exit(EXIT_FAILURE);
				}
				if (symbol->is_variable) {
					assert(symbol->node != NULL);
					assert(tmp->member_access.member != NULL);
					assert(tmp->member_access.member->type == AST_ID);
					if (tmp->member_access.member->type == AST_ID) {

						// union ast_node *sym;	//	The AST_ID might be in an AST_LIST node. eg. `const Foo`
						const char *sym;
						if (symbol->node->type == AST_ID) {
							sym = symbol->node->id.id;
						} else if (symbol->node->type == AST_GENERIC_DECLARATION) {
							sym = get_generic_type_name(symbol->node);
						} else {
							assert(get_id_node(symbol->node)->type == AST_ID);
							sym = get_id_node(symbol->node)->id.id;
						}

						// assert(sym->type == AST_ID);
						sprintf(func_name, "%s__%s", sym, tmp->member_access.member->id.id);
						symbol = symbol_get(func_name);
						if (symbol != NULL) {

							// We found a function!
							// Alter the AST tree to call the function instead.

							tmp = create_unary_node(AST_ADDRESS_OF, tmp->member_access.object);

							if (node->function_call.args == NULL) {
								node->function_call.args = tmp;
							} else {
								node->function_call.args = create_list_node(tmp, node->function_call.args, ", ");
							}

							node->function_call.function = create_id_node(func_name);

							//	fallthrough to codegen below!
						} else {
							//	TODO: I had to disable this to support function pointers!

							// fprintf(stderr, "ERROR: function call %s not found\n", tmp->member_access.member->id.id);
							// exit(EXIT_FAILURE);
						}
					}
				} else {
					fprintf(stderr, "codegen: AST_FUNCTION_CALL: AST_MEMBER_ACCESS: symbol for %s is not a variable\n", tmp->member_access.object->id.id);
					exit(EXIT_FAILURE);
				}
			} else {
				fprintf(stderr, "codegen: AST_FUNCTION_CALL: AST_MEMBER_ACCESS: object is not an AST_ID\n");
				exit(EXIT_FAILURE);
			}
		}

		codegen(out, node->function_call.function, depth, node);
		fputc('(', out);
		codegen(out, node->function_call.args, depth, node);
		fputc(')', out);
		break;

	case AST_MEMBER_ACCESS:

		assert(node->member_access.object != NULL);
		assert(node->member_access.member != NULL);

		//	Here we need to look for getters!
		//	eg. foo.getter;
		tmp = node->member_access.object;
		if (tmp->type == AST_ARRAY_SUBSCRIPT) {
			tmp = tmp->array_subscript.array;
			assert(tmp != NULL);
		}

		if (tmp->type == AST_ID) {
			symbol = symbol_get(tmp->id.id);
			if (symbol != NULL && symbol->is_variable) {
				// This will return the data type of the variable, usually a typedef.
				// We take that typedef name, and append "__get__" with the member name.
				// We then look for that function in the symbol table.
				// If it exists, we alter the AST tree to call that function instead.
				// If it doesn't exist, we leave the AST tree as is.
				assert(node->member_access.member != NULL);
				if (node->member_access.member->type == AST_ID) {
					assert(symbol->node != NULL);

					// union ast_node *sym;	//	The AST_ID might be in an AST_LIST node. eg. `const Foo`
					const char *sym;
					if (symbol->node->type == AST_ID) {
						sym = symbol->node->id.id;
					} else if (symbol->node->type == AST_GENERIC_DECLARATION) {
						sym = get_generic_type_name(symbol->node);
					} else {
						assert(get_id_node(symbol->node)->type == AST_ID);
						sym = get_id_node(symbol->node)->id.id;
					}

					// assert(sym->type == AST_ID);
					sprintf(func_name, "%s__get__%s", sym, node->member_access.member->id.id);
					symbol = symbol_get(func_name);
					if (symbol != NULL) {
						// We found the getter function!
						// Alter the AST tree to call the getter function instead.

						//create_function_call_node(node, symbol->node, node->member_access.object);

						assert(sizeof(struct ast_member_access_node) >= sizeof(struct ast_function_call_node));
						// assert(offsetof(struct ast_member_access_node, object) == offsetof(struct ast_function_call_node, args));
						// assert(offsetof(node->member_access, object) == offsetof(node->function_call, args));

						tmp = node->member_access.object;	//	NOTE: This may have changed, eg. if it's an array subscript! We need to store it again, because it will be overwritten!.

						node->type = AST_FUNCTION_CALL;
						node->function_call.function = create_id_node(func_name);
						node->function_call.args = create_unary_node(AST_ADDRESS_OF, tmp);

						codegen(out, node, depth, parent);

						return;
					}
				}
			}
		} else {
			// Maybe the user did the following:
			// *car.age
		}

		codegen(out, node->member_access.object, depth, node);
		fputc('.', out);
		codegen(out, node->member_access.member, depth, node);
		break;


	case AST_MEMBER_ACCESS_POINTER:
		//	Here we need to look for getters!
		tmp = node->member_access.object;
		assert(node->member_access.object != NULL);
		if (tmp->type == AST_ID) {
			symbol = symbol_get(tmp->id.id);
			if (symbol != NULL && symbol->is_variable) {
				// This will return the data type of the variable, usually a typedef.
				// We take that typedef name, and append "__get__" with the member name.
				// We then look for that function in the symbol table.
				// If it exists, we alter the AST tree to call that function instead.
				// If it doesn't exist, we leave the AST tree as is.
				assert(node->member_access.member != NULL);
				if (node->member_access.member->type == AST_ID) {
					assert(symbol->node != NULL);

					// union ast_node *sym;	//	The AST_ID might be in an AST_LIST node. eg. `const Foo`
					const char *sym;
					if (symbol->node->type == AST_ID) {
						sym = symbol->node->id.id;
					} else if (symbol->node->type == AST_GENERIC_DECLARATION) {
						sym = get_generic_type_name(symbol->node);
					} else {
						assert(get_id_node(symbol->node)->type == AST_ID);
						sym = get_id_node(symbol->node)->id.id;
					}

					// assert(sym->type == AST_ID);
					sprintf(func_name, "%s__get__%s", sym, node->member_access.member->id.id);
					symbol = symbol_get(func_name);
					if (symbol != NULL) {
						// We found the getter function!
						// Alter the AST tree to call the getter function instead.

						//create_function_call_node(node, symbol->node, node->member_access.object);

						assert(sizeof(struct ast_member_access_node) == sizeof(struct ast_function_call_node));
						// assert(offsetof(struct ast_member_access_node, object) == offsetof(struct ast_function_call_node, args));
						// assert(offsetof(node->member_access, object) == offsetof(node->function_call, args));

						node->type = AST_FUNCTION_CALL;
						node->function_call.function = create_id_node(func_name);
						node->function_call.args = tmp;

						codegen(out, node, depth, parent);

						return;
					}
				}
			}
		} else if (tmp->type == AST_THIS || tmp->type == AST_SELF) {
			symbol = symbol_get(tmp->type == AST_THIS ? "this" : "self");

			if (symbol != NULL && symbol->is_variable) {
				assert(node->member_access.member != NULL);
				if (node->member_access.member->type == AST_ID) {
					assert(symbol->node != NULL);

					// union ast_node *sym;	//	The AST_ID might be in an AST_LIST node. eg. `const Foo`
					const char *sym;
					if (symbol->node->type == AST_ID) {
						sym = symbol->node->id.id;
					} else if (symbol->node->type == AST_GENERIC_DECLARATION) {
						sym = get_generic_type_name(symbol->node);
					} else {
						assert(get_id_node(symbol->node)->type == AST_ID);
						sym = get_id_node(symbol->node)->id.id;
					}

					// assert(sym->type == AST_ID);
					sprintf(func_name, "%s__get__%s", sym, node->member_access.member->id.id);
					symbol = symbol_get(func_name);
					if (symbol != NULL) {
						// We found the getter function!
						// Alter the AST tree to call the getter function instead.

						//create_function_call_node(node, symbol->node, node->member_access.object);

						assert(sizeof(struct ast_member_access_node) >= sizeof(struct ast_function_call_node));

						node->type = AST_FUNCTION_CALL;
						node->function_call.function = create_id_node(func_name);
						node->function_call.args = tmp;

						codegen(out, node, depth, parent);

						return;
					}
				}
			}
		} else {
			// Maybe the user did the following:
			// *car.age
		}

		codegen(out, node->member_access.object, depth, node);
		fprintf(out, "->");
		codegen(out, node->member_access.member, depth, node);
		break;

	case AST_POST_INC:
		codegen(out, node->unary.expr, depth, node);
		fprintf(out, "++");
		break;

	case AST_POST_DEC:
		codegen(out, node->unary.expr, depth, node);
		fprintf(out, "--");
		break;

	case AST_COMPOUND_LITERAL:
		fprintf(out, "(");
		codegen(out, node->compound_literal.type_name, depth, node);
		fprintf(out, ") {");
		codegen(out, node->compound_literal.init_list, depth, node);
		fprintf(out, "}");
		break;

	//	-----------------------------------------------------------------------
	//	`primary_expression`
	//	-----------------------------------------------------------------------

	/*
	primary_expression
		: IDENTIFIER
		| constant
		| string
		| '(' expression ')'
		| generic_selection
		;
	*/

	case AST_ID:
		fprintf(out, "%s", node->id.id);
		break;

	//	----------------------------------------------
	//	`constant`
	//	----------------------------------------------

	case AST_NUMERIC:
		fprintf(out, "%s", node->numeric.num_str);
		break;

	case AST_ENUMERATION_CONSTANT:
		fprintf(out, "%s", node->id.id);
		break;

	//	----------------------------------------------
	//	`string`
	//	----------------------------------------------

	case AST_STRING:
		fprintf(out, "%s", node->str.str);
		break;

	case AST__FUNC__:
		fprintf(out, "__func__");
		break;

	//	----------------------------------------------
	//	"expression group"

	case AST_EXPRESSION_GROUP:
		fprintf(out, "(");
		codegen(out, node->unary.expr, depth, node);
		fprintf(out, ")");
		break;

	//	----------------------------------------------
	//	`generic_selection`
	//	----------------------------------------------

	//	generic_selection
	// AST_GENERIC_SELECTION,
	// AST_GENERIC_ASSOC_LIST,
	// AST_GENERIC_ASSOC,

	//	-----------------------------------------------------------------------




	//	-----------------------------------------------------------------------
	//	`initializer`
	//	-----------------------------------------------------------------------
	/*
	initializer
		: '{' initializer_list '}'
		| '{' initializer_list ',' '}'
		| assignment_expression
		;
	*/

	case AST_INITIALIZER:
		fprintf(out, "{");
		codegen(out, node->initializer.list, depth, node);
		fprintf(out, "}");
		break;

	//	-----------------------------------------------------------------------
	//	`initializer_list` && `designation`
	//	-----------------------------------------------------------------------
	/*
	initializer_list
		: designation initializer
		| initializer
		| initializer_list ',' designation initializer
		| initializer_list ',' initializer
		;

	designation
		: designator_list '='
		;
	*/

	case AST_DESIGNATION_INITIALIZER:
		codegen(out, node->designation_initializer.designation, depth, node);
		fprintf(out, " = ");
		codegen(out, node->designation_initializer.initializer, depth, node);
		break;

	//	-----------------------------------------------------------------------
	//	`designator`
	//	-----------------------------------------------------------------------
	/*
	designator
		: '[' constant_expression ']'
		| '.' IDENTIFIER
		;
	*/

	case AST_DESIGNATOR:
		if (node->designator.id) {
			fprintf(out, ".");
			codegen(out, node->designator.id, depth, node);
		} else {
			fprintf(out, "[");
			codegen(out, node->designator.expr, depth, node);
			fprintf(out, "]");
		}
		break;


	//	-----------------------------------------------------------------------
	//	`labeled_statement`
	//	-----------------------------------------------------------------------

	case AST_LABEL:
		indent(out, depth);
		codegen(out, node->label.id, depth, node);
		fprintf(out, ":\n");
		codegen(out, node->label.stmt, depth + 1, node);
		break;

	case AST_CASE:
		indent(out, depth - 1);
		fprintf(out, "case ");
		codegen(out, node->case_stmt.expr, depth, node);
		fprintf(out, ":\n");
		codegen(out, node->case_stmt.stmt, depth, node);
		break;

	case AST_DEFAULT:
		indent(out, depth - 1);
		fprintf(out, "default:\n");
		codegen(out, node->default_stmt.stmt, depth, node);
		break;


	//	-----------------------------------------------------------------------
	//	`jump_statement`
	//	-----------------------------------------------------------------------

	case AST_GOTO:
		indent(out, depth);
		fprintf(out, "goto ");
		codegen(out, node->goto_stmt.id, depth, node);
		fprintf(out, ";\n");
		break;

	case AST_CONTINUE:
		indent(out, depth);
		fprintf(out, "continue;\n");
		break;

	case AST_BREAK:
		indent(out, depth);
		fprintf(out, "break;\n");
		break;

	case AST_RETURN:
		indent(out, depth);
		if (node->return_stmt.expr) {
			fprintf(out, "return ");
			codegen(out, node->return_stmt.expr, depth, node);
			fprintf(out, ";\n");
		} else {
			fprintf(out, "return;\n");
		}
		break;



	//	-----------------------------------------------------------------------
	//	`selection_statement`
	//	-----------------------------------------------------------------------

	/*
	selection_statement
		: IF '(' expression ')' statement ELSE statement
		| IF '(' expression ')' statement
		| SWITCH '(' expression ')' statement
		;
	*/

	case AST_IF:
		if (parent->type != AST_IF) {
			indent(out, depth);
		}
		fprintf(out, "if (");
		codegen(out, node->if_stmt.cond, depth, node);

		if (node->if_stmt.if_true) {
			if (node->if_stmt.if_true->type == AST_BLOCK) {
				fprintf(out, ") ");
				codegen(out, node->if_stmt.if_true, depth, node);
			} else {
				fprintf(out, ")\n");
				codegen(out, node->if_stmt.if_true, depth + 1, node);
			}
		}

		if (node->if_stmt.if_false) {
			if (node->if_stmt.if_false->type == AST_BLOCK || node->if_stmt.if_false->type == AST_IF) {
				fprintf(out, " else ");
				codegen(out, node->if_stmt.if_false, depth, node);
			} else {
				indent(out, depth);
				fprintf(out, "else\n");
				codegen(out, node->if_stmt.if_false, depth + 1, node);
			}
			fprintf(out, "\n");
		}
		break;

	case AST_SWITCH:
		indent(out, depth);
		fprintf(out, "switch (");
		codegen(out, node->switch_stmt.expr, depth, node);
		fprintf(out, ") ");
		codegen(out, node->switch_stmt.stmt, depth, node);
		break;


	//	-----------------------------------------------------------------------
	//	`iteration_statement`
	//	-----------------------------------------------------------------------

	/*
	iteration_statement
		: WHILE '(' expression ')' statement
		| DO statement WHILE '(' expression ')' ';'
		| FOR '(' expression_statement expression_statement ')' statement
		| FOR '(' expression_statement expression_statement expression ')' statement
		| FOR '(' declaration expression_statement ')' statement
		| FOR '(' declaration expression_statement expression ')' statement
		;
	*/

	case AST_WHILE:
		indent(out, depth);
		fprintf(out, "while (");
		codegen(out, node->while_stmt.cond, depth, node);
		fprintf(out, ") ");
		codegen(out, node->while_stmt.body, depth, node);
		break;

	case AST_DO_WHILE:
		indent(out, depth);
		fprintf(out, "do ");
		codegen(out, node->do_while_stmt.body, depth, node);
		fprintf(out, "while (");
		codegen(out, node->do_while_stmt.cond, depth, node);
		fprintf(out, ");\n");
		break;

	case AST_FOR:
		indent(out, depth);
		fprintf(out, "for (");
		if (node->for_stmt.init) {
			codegen(out, node->for_stmt.init, depth, node);
		}
		// fprintf(out, " ");
		if (node->for_stmt.cond) {
			codegen(out, node->for_stmt.cond, depth, node);
		}
		// fprintf(out, " ");
		if (node->for_stmt.incr) {
			codegen(out, node->for_stmt.incr, depth, node);
		}
		fprintf(out, ") ");
		codegen(out, node->for_stmt.body, depth, node);
		break;


	//	-----------------------------------------------------------------------
	//	`expression_statement`
	//	-----------------------------------------------------------------------

	case AST_EXPRESSION_STATEMENT:
		if (parent->type != AST_FOR) indent(out, depth);
		codegen(out, node->unary.expr, depth, node);
		fprintf(out, parent->type == AST_FOR ? "; " : ";\n");
		break;


	//	-----------------------------------------------------------------------
	//	`_Static_assert` (C11 keyword) || `static_assert` (C23 keyword, C11 macro)
	//	-----------------------------------------------------------------------

	/*
	static_assert_declaration
		: _STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
		| _STATIC_ASSERT '(' constant_expression ')' ';'
		| STATIC_ASSERT '(' constant_expression ',' STRING_LITERAL ')' ';'
		| STATIC_ASSERT '(' constant_expression ')' ';'
		;
	*/
	case AST__STATIC_ASSERT:
		fprintf(out, "_Static_assert(");
		goto _static_assert;
	case AST_STATIC_ASSERT:
		fprintf(out, "static_assert(");
	_static_assert:
		codegen(out, node->static_assert_stmt.expr, depth, node);
		if (node->static_assert_stmt.str) {
			fprintf(out, ", ");
			codegen(out, node->static_assert_stmt.str, depth, node);
		}
		fprintf(out, ");");
		break;


	//	-----------------------------------------------------------------------
	//			Super C extensions
	//	-----------------------------------------------------------------------

	case AST_IMPL:
		process_impl(node, parent);
		codegen(out, node->impl.body, depth, parent);
		break;

	case AST_STATIC_IMPL:
		process_static_impl(node, parent);
		codegen(out, node->impl.body, depth, parent);
		break;

	case AST_THIS:
		fputs("this", out);
		break;

	case AST_SELF:
		fputs("self", out);
		break;

	case AST_NS_OP:
		//	First we need to look for getters!
		//	If the NS OP is a getter, we need to convert the node to a `function call`!
		tmp = NULL; //node->binary.left;

		assert(node->binary.left != NULL);
		assert(node->binary.left->type == AST_ID);
		if (node->binary.left->type != AST_ID) {
			//	NOTE: This should never be seen by end users! Because this should be the case from the parser!
			fprintf(stderr, "ERROR: left hand side of NS OP is not an AST_ID node!\n");
			exit(EXIT_FAILURE);
		}

		symbol = symbol_get(node->binary.left->id.id);

		assert(symbol != NULL);
		if (symbol == NULL) {
			fprintf(stderr, "ERROR: Left side of namespace operator `%s` doesn't refer to a valid typename!\n", node->binary.left->id.id);
			exit(EXIT_FAILURE);
		}

		assert(symbol->is_typedef);
		if (symbol->is_typedef == false) {
			fprintf(stderr, "ERROR: Left side of namespace operator `%s` doesn't refer to a valid typename!\n", node->binary.left->id.id);
			exit(EXIT_FAILURE);
		}

		// This will return the data type of the variable, usually a typedef.
		// We take that typedef name, and append "__get__" with the member name.
		// We then look for that function in the symbol table.
		// If it exists, we alter the AST tree to call that function instead.
		// If it doesn't exist, we leave the AST tree as is.
		assert(node->binary.right != NULL);
		if (node->binary.right->type != AST_ID) {
			fprintf(stderr, "ERROR: Right side of namespace operator must be a valid AST_ID node! Found %d\n", node->binary.right->type);
			exit(EXIT_FAILURE);
		}

		assert(symbol->node != NULL);
		assert(symbol->node->type == AST_ID || symbol->node->type == AST_TYPEDEF_NAME);
		sprintf(func_name, "%s__get__%s", node->binary.left->id.id, node->binary.right->id.id);
		symbol = symbol_get(func_name);
		if (symbol != NULL) {
			// We found a getter function!
			// Alter the AST tree to call the getter function instead.
			assert(sizeof(struct ast_binary_node) >= sizeof(struct ast_function_call_node));
			node->type = AST_FUNCTION_CALL;
			node->function_call.function = create_id_node(func_name);
			node->function_call.args = NULL;

			codegen(out, node, depth, parent);
			return;
		}

		// We didn't find a getter function! Try searching for a regular method call!
		sprintf(func_name, "%s__%s", node->binary.left->id.id, node->binary.right->id.id);
		symbol = symbol_get(func_name);
		if (symbol) {
			if (symbol->is_function == false) {
				fprintf(stderr, "ERROR: Namespace lookup for `%s` and `%s` doesn't refer to a valid function!\n", node->binary.left->id.id, node->binary.right->id.id);
				fprintf(stderr, "Did you forget to add a function in an `impl static %s { ... }` block for %s?\n", node->binary.left->id.id, node->binary.right->id.id);
				exit(EXIT_FAILURE);
			}

			if (parent->type != AST_FUNCTION_CALL) {
				// This would be a syntax check, to make sure the user is calling the function properly... But we can also let the compiler do that!
				// fprintf(stderr, "ERROR: Typedef functions must be done with a regular function call parenthesis `()`\n", node->binary.left->id.id, node->binary.right->id.id);
				// exit(EXIT_FAILURE);
			}

			// We found a regular (static) typename function!
			// Alter the AST tree with an AST_ID. We assume the AST_NS_OP is inside a function call!
			assert(sizeof(struct ast_binary_node) >= sizeof(struct ast_id_node));
			node->type = AST_ID;
			node->id.id = strdup(func_name);
			//node = create_id_node(func_name);

			codegen(out, node, depth, parent);
			return;
		}

		fprintf(stderr, "ERROR: Namespace lookup for `%s` and `%s` doesn't refer to a valid `static impl` function!\n", node->binary.left->id.id, node->binary.right->id.id);
		fprintf(stderr, "Did you forget to add a function in an `impl static %s { ... }` block for `%s()`?\n", node->binary.left->id.id, node->binary.right->id.id);
		exit(EXIT_FAILURE);
		break;

	// case AST_NEW:
	// 	//process_impl(node, parent);
	// 	//codegen(out, node->impl.body, depth, parent);
	// 	break;


	case AST_GENERIC_DECLARATION:
	// 	codegen(out, node->generic_type.id, depth, parent);
	// 	fputs("<", out);
	// 	codegen(out, node->generic_type.type_list, depth, parent);
	// 	fputs(">", out);
	// 	break;

	// case AST_GENERIC_SPECIFIER:
		{
			const char *generic_name = get_generic_type_name(node);
printf("AST_GENERIC_DECLARATION: generic_name = %s\n", generic_name);
			if (generic_name == NULL) {
				fprintf(stderr, "FATAL ERROR: Could not generate generic type name!\n");
				exit(EXIT_FAILURE);
			}
			fputs(generic_name, out);
		}
		// codegen(out, node->generic_type.id, depth, parent);
		// fputs("<", out);
		// codegen(out, node->generic_type.type_list, depth, parent);
		// fputs(">", out);

		//	NOTE: This should never be seen by end users! Because this should be the case from the parser!
		// fprintf(stderr, "ERROR: AST_GENERIC_DECLARATION detected after expansion! This should never happen!\n");
		// exit(EXIT_FAILURE);
		break;

	case AST_GENERIC_STRUCT:
	case AST_GENERIC_UNION:
		assert(node->generic_type.id != NULL);
		if (node->generic_type.id->type == AST_GENERIC_DECLARATION) {
			register_generic_struct_or_union(node);
			if (parent->type == AST_DECLARATION && parent->declaration.decl_specs == node) {
				parent->declaration.decl_specs = NULL;
			}
		} else {
printf("HERLEJHRELJRHLEJHREJLHR J====================>>>>\n");
		}
		break;

	case AST_GENERIC_LIST:
print_ast_tree(stderr, parent, 0, 0);
		fprintf(stderr, "ERROR: AST_GENERIC_LIST detected after expansion! This should never happen!\n");
		exit(EXIT_FAILURE);
		// codegen(out, node->generic_list.head, depth, parent);
		// fputs(", ", out);
		// codegen(out, node->generic_list.tail, depth, parent);
		break;


	case AST_GENERIC_IMPL:
		if (node->impl.id->type == AST_GENERIC_DECLARATION) {
		// 	//	Store the node in the symbol table for processing later!
		// 	const char *name = get_generic_impl_name(node->impl.id);
		// 	//	TODO: We should remove the node from the AST; create a new node, move the node into it, and set this one to NULL!
		// 	symbol_add_generic_impl(name, node);
		// } else if (node->impl.id->type == AST_GENERIC_SPECIFIER) {

			const char *name = get_generic_impl_name(node->impl.id);
			symbol = symbol_get(name);

printf("AST_GENERIC_IMPL ===> AST_GENERIC_DECLARATION: %s\n", name);


/*
printf("symbol->is_generic: %d\n", symbol->is_generic);
printf("symbol->is_struct: %d\n", symbol->is_struct);

printf("symbol->is_union: %d\n", symbol->is_union);
printf("symbol->is_function: %d\n", symbol->is_function);
printf("symbol->is_variable: %d\n", symbol->is_variable);
printf("symbol->is_typedef: %d\n", symbol->is_typedef);
printf("symbol->is_setter: %d\n", symbol->is_setter);
printf("symbol->is_getter: %d\n", symbol->is_getter);
printf("symbol->is_pointer: %d\n", symbol->is_pointer);
printf("symbol->is_generic_name: %d\n", symbol->is_generic_name);
printf("symbol->is_generic_type: %d\n", symbol->is_generic_type);
printf("symbol->is_generic_impl: %d\n", symbol->is_generic_impl);
*/

			if (symbol == NULL || symbol->is_generic_impl == false) {
				tmp = node->impl.id->generic_type.id;
				if (tmp->type != AST_LIST || tmp->list.node->type != AST_ID || tmp->list.next->type != AST_ID) {
					fprintf(stderr, "FATAL ERROR: Unknown `impl` label, typename or invalid syntax structure\n");
					exit(EXIT_FAILURE);
				}
				fprintf(stderr, "Syntax error: Unknown or undeclared label or object for: `impl %s %s`!\n", tmp->list.node->id.id, tmp->list.next->id.id);
				exit(EXIT_FAILURE);
			}

			build_impl_from_generic(node, symbol->node);
printf("AST_GENERIC_IMPL ===> AST_GENERIC_DECLARATION ===> codegen()\n");
print_ast_tree(stdout, node, 0, NULL);
			codegen(out, node, depth, parent);
printf("============================================================\n");

		} else {
			fprintf(stderr, "ERROR: Unknown AST_GENERIC_IMPL type detected in `.id` node. Only AST_GENERIC_DECLARATION is supported!!\n");
			exit(EXIT_FAILURE);
		}


printf("AST_GENERIC_IMPL\n");
print_ast_tree(stdout, node, 0, NULL);
printf("name: %s\n", get_generic_impl_name(node->impl.id));
		// symbol_add_generic_impl(node, node);
		break;
	case AST_GENERIC_STATIC_IMPL:
		break;


	case AST_DELETE_OPERATOR:
		fprintf(stderr, "ERROR: AST_DELETE_OPERATOR detected after expansion! This should never happen!\n");
		exit(EXIT_FAILURE);
		break;

	//	This is essentially a regular/top level `new()` function outside of an "impl" block!
	case AST_IMPL_NEW_FUNCTION:
		fprintf(stderr, "ERROR: AST_IMPL_NEW_FUNCTION detected after expansion! This should never happen!\n");
		exit(EXIT_FAILURE);
		break;

	case AST_IMPL_NEW_DECLARATOR:
		fprintf(stderr, "ERROR: AST_IMPL_NEW_DECLARATOR detected after expansion! This should never happen!\n");
		exit(EXIT_FAILURE);
		break;

	//	This is essentially a regular/top level `delete()` function outside of an "impl" block!
	case AST_IMPL_DELETE_FUNCTION:
		fprintf(stderr, "ERROR: AST_IMPL_DELETE_FUNCTION detected after expansion! This should never happen!\n");
		exit(EXIT_FAILURE);
		break;

	case AST_IMPL_FUNCTION_DECLARATION:
		fprintf(stderr, "ERROR: AST_IMPL_FUNCTION_DECLARATION detected after expansion! This should never happen!\n");
		exit(EXIT_FAILURE);
		break;

	//	do I still use blank id? I think not!
	// case AST_BLANK_ID:
	// 	fprintf(stderr, "ERROR: AST_BLANK_ID detected after expansion! This should never happen!\n");
	// 	exit(EXIT_FAILURE);
	// 	break;

	case AST_GETTER:
		fprintf(stderr, "ERROR: AST_GETTER detected after expansion! This should never happen!\n");
		exit(EXIT_FAILURE);
		break;

	case AST_SETTER:
		fprintf(stderr, "ERROR: AST_SETTER detected after expansion! This should never happen!\n");
		exit(EXIT_FAILURE);
		break;

	//	-----------------------------------------------------------------------
	//	-----------------------------------------------------------------------

	case AST_DUMMY:
		fprintf(out, " ( DUMMY NODE ) ");
		break;

	default:
		fprintf(stderr, "Unknown node type id: %d\n", node->type);
		exit(EXIT_FAILURE);
		break;
	}
}








//	Just STORED here! For the `AST_GENERIC_IMPL` code!
void __process_impl_traversal(union ast_node *node, union ast_node *parent)
{
	if (node == NULL) return;

	union ast_node *tmp;
	symbol_t *symbol;

	switch (node->type) {

	//	-----------------------------------------------------------------------
	//			AST_LIST
	//	-----------------------------------------------------------------------

	case AST_LIST:
		__process_impl_traversal(node->list.node, node);
		__process_impl_traversal(node->list.next, node);
		break;

	//	-----------------------------------------------------------------------
	//			Super C extensions
	//	-----------------------------------------------------------------------

	case AST_IMPL:
		process_impl(node, parent);
		break;

	case AST_STATIC_IMPL:
		process_static_impl(node, parent);
		break;

	case AST_GENERIC_IMPL:
		if (node->impl.id->type == AST_GENERIC_DECLARATION) {
		// 	//	Store the node in the symbol table for processing later!
		// 	const char *name = get_generic_impl_name(node->impl.id);
		// 	//	TODO: We should remove the node from the AST; create a new node, move the node into it, and set this one to NULL!
		// 	symbol_add_generic_impl(name, node);
		// } else if (node->impl.id->type == AST_GENERIC_SPECIFIER) {

			const char *name = get_generic_impl_name(node->impl.id);
			symbol = symbol_get(name);

printf("AST_GENERIC_IMPL ===> AST_GENERIC_DECLARATION: %s\n", name);


/*
printf("symbol->is_generic: %d\n", symbol->is_generic);
printf("symbol->is_struct: %d\n", symbol->is_struct);

printf("symbol->is_union: %d\n", symbol->is_union);
printf("symbol->is_function: %d\n", symbol->is_function);
printf("symbol->is_variable: %d\n", symbol->is_variable);
printf("symbol->is_typedef: %d\n", symbol->is_typedef);
printf("symbol->is_setter: %d\n", symbol->is_setter);
printf("symbol->is_getter: %d\n", symbol->is_getter);
printf("symbol->is_pointer: %d\n", symbol->is_pointer);
printf("symbol->is_generic_name: %d\n", symbol->is_generic_name);
printf("symbol->is_generic_type: %d\n", symbol->is_generic_type);
printf("symbol->is_generic_impl: %d\n", symbol->is_generic_impl);
*/

			if (symbol == NULL || symbol->is_generic_impl == false) {
				tmp = node->impl.id->generic_type.id;
				if (tmp->type != AST_LIST || tmp->list.node->type != AST_ID || tmp->list.next->type != AST_ID) {
					fprintf(stderr, "FATAL ERROR: Unknown `impl` label, typename or invalid syntax structure\n");
					exit(EXIT_FAILURE);
				}
				fprintf(stderr, "Syntax error: Unknown or undeclared label or object for: `impl %s %s`!\n", tmp->list.node->id.id, tmp->list.next->id.id);
				exit(EXIT_FAILURE);
			}

			build_impl_from_generic(node, symbol->node);
printf("AST_GENERIC_IMPL ===> AST_GENERIC_DECLARATION ===> codegen()\n");
print_ast_tree(stdout, node, 0, NULL);
			// _codegen(out, node, 0, parent);
printf("============================================================\n");

		} else {
			fprintf(stderr, "ERROR: Unknown AST_GENERIC_IMPL type detected in `.id` node. Only AST_GENERIC_DECLARATION is supported!!\n");
			exit(EXIT_FAILURE);
		}


printf("AST_GENERIC_IMPL\n");
print_ast_tree(stdout, node, 0, NULL);
printf("name: %s\n", get_generic_impl_name(node->impl.id));
		// symbol_add_generic_impl(node, node);
		break;

	case AST_GENERIC_STATIC_IMPL:		//	NOTE: 'might' be needed?
		break;

	default:
		break;
	}
}
