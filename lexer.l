/**
 *	flex --header-file=lex.yy.h lexer.l
 *	-v, --verbose       write summary of scanner statistics to stdout
 *	--yylineno          track line count in yylineno
 *	--bison-bridge      scanner for bison pure parser.
 *	--bison-locations   scanner for bison pure parser with location support. include yylloc support.
 */
%{
#include <stdio.h>
#include "parser.tab.h"
#include "ast.h"
#include "ast_nodes.h"

#define YYERROR_VERBOSE 1

extern int yylineno;
extern int error_count;

char filename[512];
const char *yyfilename = filename;

extern char *yytext;

extern void yyerror(const char *);
// void update_location(int line, const char *filename);

#include "symbol_table.h"
#include "symbol_keys.h"

extern int sym_type(const char *str);  /* returns type from symbol table */
//#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

// static void comment();
static int check_type();


static inline void init_id(struct ast_id_node *id)
{
	if (id->hash == 0) {
		id->hash = symbol_hash(id->id);
		//id->id = get_symbol_key(id->id, id->hash);
	}
}


//	Clear list of C (and Objective-C) keywords: https://android.googlesource.com/toolchain/gcc/+/donut/gcc-4.2.1/gcc/c-parser.c

%}

%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

%option yylineno

%x IN_COMMENT
%x IN_LINE
%x IN_ATTRIBUTE

%x attribute
%x pragma



O	[0-7]
D	[0-9]
NZ	[1-9]
L	[a-zA-Z_]
A	[a-zA-Z_0-9]
H	[a-fA-F0-9]
HP	(0[xX])
E	([Ee][+-]?{D}+)
P	([Pp][+-]?{D}+)
FS	(f|F|l|L)
IS	(((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP	(u|U|L)
SP	(u8|u|U|L)
ES	(\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS	[ \t\v\n\f]
NUM {D}+
FILENAME	"\"([^\"\\\n])*\""
LINE2		"#[ \t]*[0-9]+[ \t]*(\"([^\"\\\n])*\"[ \t]*)?"

LINE	#[ \t]*([0-9]+)[ \t]*"([^\"])*".*




PP	(#[ \t]*)

%%
"/*"						{ BEGIN(IN_COMMENT); }
<IN_COMMENT>"*/"			{ BEGIN(INITIAL); }
<IN_COMMENT>.*				{ /* ignore everything inside the comment */ }
<IN_COMMENT>\n				{ /* yylineno++; */ }

"//".*						{ /* consume //-comment */ }

"var"						{ return VAR; /* Similar to C++ auto */ }
"let"						{ return LET; /* Similar to C++ auto */ }
"__auto_type"				{ return __AUTO_TYPE; /* GCC extension! */ }

"auto"						{ return AUTO; }
"break"						{ return BREAK; }
"case"						{ return CASE; }
"char"						{ return CHAR; }
"const"						{ return CONST; /* `const` without any other decl specs should act like C++ `auto`! */ }
"continue"					{ return CONTINUE; }
"default"					{ return DEFAULT; }
"do"						{ return DO; }
"double"					{ return DOUBLE; }
"else"						{ return ELSE; }
"enum"						{ return ENUM; }
"extern"					{ return EXTERN; }
"float"						{ return FLOAT; }
"for"						{ return FOR; }
"goto"						{ return GOTO; }
"if"						{ return IF; }
"inline"					{ return INLINE; }
"int"						{ return INT; }
"long"						{ return LONG; }
"register"					{ return REGISTER; }
"restrict"					{ return RESTRICT; }
"return"					{ return RETURN; }
"short"						{ return SHORT; }
"signed"					{ return SIGNED; }
"sizeof"					{ return SIZEOF; }
"static"					{ return STATIC; }
"struct"					{ return STRUCT; }
"switch"					{ return SWITCH; }
"typedef"					{ return TYPEDEF; }
"union"						{ return UNION; }
"unsigned"					{ return UNSIGNED; }
"void"						{ return VOID; }
"volatile"					{ return VOLATILE; }
"while"						{ return WHILE; }
"_Alignas"					{ return ALIGNAS; }
"_Alignof"					{ return ALIGNOF; }
"_Atomic"					{ return ATOMIC; }
"_Bool"						{ return BOOL; }
"_Complex"					{ return COMPLEX; }
"_Generic"					{ return GENERIC; }
"_Imaginary"				{ return IMAGINARY; }

"_Noreturn"					{ return NORETURN; }
"noreturn"					{ return NORETURN; /* alias for "_Noreturn" */ }

"_Static_assert"			{ return _STATIC_ASSERT; /* C11, deprecated in C23 */ }
"static_assert"				{ return STATIC_ASSERT; /* C23 */ }

"_Thread_local"				{ return THREAD_LOCAL; }
"__func__"					{ return FUNC_NAME; /* --Isn't this already removed/replaced by the pre-processor? Actually, I think it will be replaced by the compiler?-- Apparently it creates a `static const char*` inside the function. */ }

"__restrict"				{ return __RESTRICT; /* alias for "restrict", but GCC syntax ... where is this from?? */ }

"__builtin_va_list"			{ return __BUILTIN_VA_LIST; /* typedef __builtin_va_list __gnuc_va_list; */ }

"_Float128"					{ return _FLOAT128; /* GCC __float128 extension */ }
"__int128"					{ return __INT128; /* GCC __int128 extension - As of GCC 4.6 */ }
"__int128_t"				{ return __INT128_T; /* GCC __int128_t extension - As of GCC 4.1 - actually used in `/usr/include/x86_64-linux-gnu/bits/link.h` without being defined! */ }
"__uint128_t"				{ return __UINT128_T; /* GCC __uint128_t extension - As of GCC 4.1 */ }
"_BitInt(128)"				{ return _BITINT128; /* C23 _BitInt(128) - common in Clang */ }
"_BitInt("{D}+")"			{ yylval.node = create__bitint__node(yytext); return _BITINT; /* C23 _BitInt(N) - TODO: parse the inner integer! Also, this could probably also be `_BitInt  ( 32  )` with extra spaces, what about `_BitInt(0x10)` (is this valid?)? */ }

"_Decimal32"				{ return _DECIMAL32; }
"_Decimal64"				{ return _DECIMAL64; }
"_Decimal128"				{ return _DECIMAL128; /* https://android.googlesource.com/toolchain/gcc/+/donut/gcc-4.2.1/gcc/c-parser.c */}

"forceinline"				{ return __FORCEINLINE; /* shorthand for: __attribute__((always_inline)) -- MSVC __forceinline extension */ }
"__forceinline"				{ return __FORCEINLINE; /* shorthand for: __attribute__((always_inline)) -- MSVC __forceinline extension */ }
"always_inline"				{ return __FORCEINLINE; /* shorthand for: __attribute__((always_inline)) */ }
"__always_inline"			{ return __FORCEINLINE; /* shorthand for: __attribute__((always_inline)) */ }


"__alignof"					{ return __ALIGNOF; }
"__alignof__"				{ return __ALIGNOF__; }
"__asm"						{ return __ASM; /* TODO: move the __asm__ code into a re-useable function! */ /* ASM_KEYWORD */ }
"__asm__"					{
								/* ASM_KEYWORD */
								#define __ASM_BUF_SIZE 1024
								char asm_buf[__ASM_BUF_SIZE];
								strcpy(asm_buf, yytext);
								int paren_count = 0;
								int i = strlen(yytext);
								int c;

								//	Find the opening '('
								while ((c = input()) != EOF) {
									asm_buf[i++] = c;
									if (c == '(') {
										paren_count++;
										break;
									} else if (c == ' ' || c == '\t') {
										/* ignore whitespace */
										continue;
									} else {
										// Could be __volatile__! eg. __asm__ __volatile__ ("nop");
										continue;
									}
									if (i >= __ASM_BUF_SIZE - 1) {
										fprintf(stderr, "error: __asm__ statement is too long\n");
										break;
									}
								}

								while ((c = input()) != EOF) {
									if (c == '(') {
										paren_count++;
									} else if (c == ')') {
										paren_count--;
									}
									asm_buf[i++] = c;
									if (paren_count == 0) {
										//fprintf(stderr, "error: unbalanced parenthesis\n");
										break;
									}
									if (i >= __ASM_BUF_SIZE - 1) {
										fprintf(stderr, "error: __asm__ statement is too long\n");
										break;
									}
								}
								asm_buf[i] = '\0';

								yylval.node = create__asm__node(asm_buf);
								return __ASM__; /* GCC recommendation: alias for "asm" - https://gcc.gnu.org/onlinedocs/gcc/Alternate-Keywords.html#Alternate-Keywords */
							}
"__attribute"				{ return __ATTRIBUTE; /* TODO: move the __attribute__ code into a re-useable function! */ /* ATTRIBUTE */ }
"__attribute__"				{
								#define __ATTRIBUTE_BUF_SIZE 512
								char attribute_buf[__ATTRIBUTE_BUF_SIZE];
								strcpy(attribute_buf, yytext);
								int paren_count = 0;
								int i = strlen(yytext);
								int c;

								//	Find the opening '('
								while ((c = input()) != EOF) {
									attribute_buf[i++] = c;
									if (c == '(') {
										paren_count++;
										break;
									} else if (c == ' ' || c == '\t') {
										/* ignore whitespace */
										continue;
									} else {
										fprintf(stderr, "error: expected '(' after '__attribute__'\n");
										exit(1);
									}
									if (i >= __ATTRIBUTE_BUF_SIZE - 1) {
										fprintf(stderr, "error: __attribute__ statement is too long\n");
										break;
									}
								}

								while ((c = input()) != EOF) {
									if (c == '(') {
										paren_count++;
									} else if (c == ')') {
										paren_count--;
									}
									attribute_buf[i++] = c;
									if (paren_count == 0) {
										//fprintf(stderr, "error: unbalanced parenthesis\n");
										break;
									}
									if (i >= __ATTRIBUTE_BUF_SIZE - 1) {
										fprintf(stderr, "error: __attribute__ statement is too long\n");
										break;
									}
								}
								attribute_buf[i] = '\0';

								yylval.node = create__attribute__node(attribute_buf);
								return __ATTRIBUTE__;
							}
"__complex"					{ return __COMPLEX; /* TYPESPEC */ }
"__complex__"				{ return __COMPLEX__; /* TYPESPEC */ }
"__const"					{ return __CONST; /* TYPE_QUAL */ }
"__const__"					{ return __CONST__; /* TYPE_QUAL */ }
"__extension__"				{ return __EXTENSION__; /* EXTENSION in GCC lexer */ /* GCC extension, eg: `__extension__ extern int ffsll (long long int __ll);` */ }
"__imag"					{ return __IMAG; /* IMAGPART */ }
"__imag__"					{ return __IMAG__; /* IMAGPART */ }
"__inline"					{ return __INLINE; /* SCSPEC */ /* GCC __inline extension */ }
"__inline__"				{ return __INLINE__; /* SCSPEC -- GCC recommendation: alias for "inline" - https://gcc.gnu.org/onlinedocs/gcc/Alternate-Keywords.html#Alternate-Keywords */ }
"__iterator"				{ return __INTERATOR; /* SCSPEC */ }
"__iterator__"				{ return __INTERATOR__; /* SCSPEC */ }
"__label__"					{ return __LABEL__; /* LABEL */ }
"__real"					{ return __REAL; /* REALPART */ }
"__real__"					{ return __REAL__; /* REALPART */ }
"__signed"					{ return __SIGNED; /* TYPESPEC */ }
"__signed__"				{ return __SIGNED__; /* TYPESPEC */ }
"__typeof"					{ return __TYPEOF; /* TYPEOF */ }
"__typeof__"				{ return __TYPEOF__; /* TYPEOF -- GCC recommendation: alias for "typeof" - https://gcc.gnu.org/onlinedocs/gcc/Alternate-Keywords.html#Alternate-Keywords */ }
"__volatile"				{ return __VOLATILE; /* TYPE_QUAL */ }
"__volatile__"				{ return __VOLATILE__; /* TYPE_QUAL */ }
"asm"						{ return ASM; /* GCC ASM_KEYWORD */ }
"typeof"					{ return TYPEOF; /* TYPE_QUAL -- GCC extension -- https://gcc.gnu.org/onlinedocs/gcc/Typeof.html -- "If you are writing a header file that must work when included in ISO C programs, write __typeof__ instead of typeof." */ }


"foreach"					{ return FOREACH; /* currently unsupported! */ }
"in"						{ return IN; /* currently unsupported! WARNING: GCC uses this as an input parameter! `extern int inflateBack (z_streamp strm, in_func in, void *in_desc, out_func out, void *out_desc)` */ }

"bool"						{ return BOOL; /* alias for: "_Bool" */ }
"true"						{ yylval.node = (void *) & digit_node[1]; return I_CONSTANT; /* In future we should add a dedicated "true_node"? One potential issue with "true" is that we could also change any conditions using it to "!= 0" because this is much more efficient than testing "== 1". "Expands to the integer constant 1" */ }
"false"						{ yylval.node = (void *) & digit_node[0]; return I_CONSTANT; /* "Expands to the integer constant 0" ... In C23, this becomes ((bool)0) and ((bool)1) for true! */ }

"null"						{ yylval.node = (void *) & null_node; return I_CONSTANT; }
"nullptr"					{ yylval.node = (void *) & null_node; return I_CONSTANT; }
"NULL"						{ yylval.node = (void *) & null_node; return I_CONSTANT; /* This is here just in-case the traditional NULL macro wasn't expanded! */ }

"a"|"b"|"c"|"d"|"e"|"f"|"g"|"h"|"i"|"j"|"k"|"l"|"m"|"n"|"o"|"p"|"q"|"r"|"s"|"t"|"u"|"v"|"w"|"x"|"y"|"z" { yylval.node = (void *) & lcase_node[yytext[0] - 'a']; return check_type(); }

"strlen"					{ yylval.node = (void *) & strlen_node; return check_type(); }

"printf"					{ yylval.node = (void *) & printf_node; return check_type(); }
"fprintf"					{ yylval.node = (void *) & fprintf_node; return check_type(); }
"sprintf"					{ yylval.node = (void *) & sprintf_node; return check_type(); }
"snprintf"					{ yylval.node = (void *) & snprintf_node; return check_type(); }

"exit"						{ yylval.node = (void *) & exit_node; return check_type(); }
"assert"					{ yylval.node = (void *) & assert_node; return check_type(); }

"malloc"					{ yylval.node = (void *) & malloc_node; return check_type(); }
"calloc"					{ yylval.node = (void *) & calloc_node; return check_type(); }
"realloc"					{ yylval.node = (void *) & realloc_node; return check_type(); }
"free"						{ yylval.node = (void *) & free_node; return check_type(); }
"alloca"					{ yylval.node = (void *) & alloca_node; return check_type(); /* Not very common, but included anyway! */ }

"memmove"					{ yylval.node = (void *) & memmove_node; return check_type(); }
"memcpy"					{ yylval.node = (void *) & memcpy_node; return check_type(); }
"memset"					{ yylval.node = (void *) & memset_node; return check_type(); }

"size_t"					{ yylval.node = (void *) & size_t_node; return check_type(); }

"new"						{ return NEW;    /* return check_type(); */ }
"delete"					{ return DELETE; /* return check_type(); */ }

"this"						{ return THIS; /* return check_type(); */ }
"self"						{ return SELF; /* return check_type(); */ }

"__byte"					{ return /* BYTE */ CHAR; /* Super C typedef unsigned char byte; */ }

"defer"						{ return DEFER; /* Super C defer { ... } ... https://open-std.org/jtc1/sc22/wg14/www/docs/n2895.htm */ }

"__constructor"				{ return CONSTRUCTOR; /* Super C constructor { ... } */ }
"__destructor"				{ return DESTRUCTOR; /* Super C destructor { ... } */ }

"get"						{ return GET; /* Super C get name { ... } */ }
"set"						{ return SET; /* Super C set name(const char *name) { ... } */ }
"readonly"					{ return READONLY; /* AKA private */ }

"::"						{ return NS; /* pseudo-namespace operator */ /* eg. Car::new(), Car::construct(), Car::myStaticVar */ }

"impl"						{ return IMPL; /* support for Rust's "impl" keyword, which is actually used to define all the methods of their structures! It also acts like C# extension methods! */ }
"class"						{ return CLASS; }
"extends"					{ return EXTENDS; }
"abstract"					{ return ABSTRACT; }
"opaque"					{ return OPAQUE; }
"virtual"					{ return VIRTUAL; }
"interface"					{ return INTERFACE; }
"final"						{ return FINAL; }
"public"					{ return PUBLIC; }
"private"					{ return PRIVATE; }
"protected"					{ return PROTECTED; }
"internal"					{ return INTERNAL; }
"override"					{ return OVERRIDE; }
"explicit"					{ return EXPLICIT; }
"friend"					{ return FRIEND; }
"operator"					{ return OPERATOR; }
"typename"					{ return TYPENAME; }
"using"						{ return USING; }
"implements"				{ return IMPLEMENTS; }
"trait"						{ return TRAIT; }
"mixin"						{ return MIXIN; }
"type"						{ return TYPE; /* AKA type class eg. Int */ }

"template"					{ return TEMPLATE; }
"namespace"					{ return NAMESPACE; }
"import"					{ return IMPORT; }
"package"					{ return PACKAGE; }
"instanceof"				{ return INSTANCEOF; }
"native"					{ return NATIVE; }
"super"						{ return SUPER; }
"synchronized"				{ return SYNCRONIZED; }
"transient"					{ return TRANSIENT; }

{L}{A}*						{ yylval.node = create_id_node(yytext); return check_type(); }

{HP}{H}+{IS}?				{ yylval.node = create_numeric_node(yytext); return I_CONSTANT; }
{NZ}{D}*{IS}?				{ yylval.node = yytext[1] == '\0' ? (void*) & digit_node[yytext[0] - '0'] : create_numeric_node(yytext); return I_CONSTANT; }
"0"{O}*{IS}?				{ yylval.node = yytext[1] == '\0' ? (void*) & digit_node[0] : create_numeric_node(yytext); return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"	{ yylval.node = create_numeric_node(yytext); return I_CONSTANT; /* char node: eg. 'a' */ }

{D}+{E}{FS}?				{ yylval.node = create_numeric_node(yytext); return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?		{ yylval.node = yytext[0] == '0' && yytext[1] == '.' && yytext[2] == '0' && yytext[3] == '\0' ? (void*) & real_node[0] : create_numeric_node(yytext); return F_CONSTANT; }
{D}+"."{E}?{FS}?			{ yylval.node = create_numeric_node(yytext); return F_CONSTANT; }
{HP}{H}+{P}{FS}?			{ yylval.node = create_numeric_node(yytext); return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?		{ yylval.node = create_numeric_node(yytext); return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?			{ yylval.node = create_numeric_node(yytext); return F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*\"{WS}*)+	{ yylval.node = create_string_node(yytext); return STRING_LITERAL; }

"="						{ return '='; }
"+="					{ return ADD_ASSIGN; }
"-="					{ return SUB_ASSIGN; }
"*="					{ return MUL_ASSIGN; }
"/="					{ return DIV_ASSIGN; }
"%="					{ return MOD_ASSIGN; }
"&="					{ return AND_ASSIGN; }
"^="					{ return XOR_ASSIGN; }
"|="					{ return OR_ASSIGN; }
"<<="					{ return SHL_ASSIGN; }
">>="					{ return SHR_ASSIGN; }

"++"					{ return INC; }
"--"					{ return DEC; }
"&&"					{ return AND; }
"||"					{ return OR; }
"<<"					{ return SHL; }
">>"					{ return SHR; }

"->"					{ return ARROW; }
"=>"					{ return FAT_ARROW; }

"=="					{ return EQ; }
"!="					{ return NE; }
"<="					{ return LE; }
">="					{ return GE; }

"..."					{ return ELLIPSIS; }

";"						{ return ';'; }
("{"|"<%")				{ return '{'; /* Aren't the digraphs handled by the preprocessor??? NO, they are not! */ }
("}"|"%>")				{ return '}'; }
","						{ return ','; }
":"						{ return ':'; }
"("						{ return '('; }
")"						{ return ')'; }
("["|"<:")				{ return '['; }
("]"|":>")				{ return ']'; }
"."						{ return '.'; }
"&"						{ return '&'; }
"!"						{ return '!'; }
"~"						{ return '~'; }
"+"						{ return '+'; }
"-"						{ return '-'; }
"*"						{ return '*'; }
"/"						{ return '/'; }
"%"						{ return '%'; }
"<"						{ return '<'; }
">"						{ return '>'; }
"^"						{ return '^'; }
"|"						{ return '|'; }
"?"						{ return '?'; }

#[ \t]*pragma[ \t]+		{ BEGIN(pragma); }
<pragma>.*				{ BEGIN(INITIAL); yylval.node = create_pragma_node(yytext); return PRAGMA; }

#[ \t]*					{ BEGIN(IN_LINE); }
<IN_LINE>.*				{
							sscanf(yytext, "%d \"%[^\"]", &yylineno, filename);
							BEGIN(INITIAL);
						}


{WS}+					{ /* whitespace separates tokens */ }
.						{ yyerror("invalid character"); }

%EOF					{ return END_OF_FILE; }

%%

int yywrap()		/* called at end of input */
{
	return 1;			/* terminate now */
}


/*
//	Manually processes comments ... but I found a better way to do it.
static void comment()
{
	int c;

	while ((c = input()) != 0) {
		if (c == '*')
		{
			while ((c = input()) == '*')
				;

			if (c == '/')
				return;

			if (c == 0)
				break;
		}
	}
	yyerror("unterminated comment");
}
*/



/* int sym_type(const char *str)  // returns type from symbol table
{
	if (string_array_contains(&typedefs, str))
		return TYPEDEF_NAME;

	if (string_array_contains(&enums, str))
		return ENUMERATION_CONSTANT;

	return IDENTIFIER;
} */

static int check_type()
{
	/* if (string_array_contains(&typedefs, yytext))
		return TYPEDEF_NAME; */

	/* if (hash_set_find(&typedefs, yytext)) */
	if (symbol_is_typedef(yytext)) {
		return TYPEDEF_NAME;
	}

	/* if (string_array_contains(&enums, yytext))
		return ENUMERATION_CONSTANT; */

	/* if (hash_set_find(&enums, yytext)) */
	if (symbol_is_enum_constant(yytext)) {
		return ENUMERATION_CONSTANT;
	}

	return IDENTIFIER;

	switch (sym_type(yytext))
	{
	/* FUNC_NAME is added by me, not in the original! */
	/*
	case FUNC_NAME:					
		return FUNC_NAME;
	*/
	case TYPEDEF_NAME:					/* previously defined */
	/* NOTE: I think we need to set the "id string node" type to "AST_TYPEDEF_NAME" or something !?!? Actually, if we look at the "type" of variable and we see "is string" I think we should know it's a TYPEDEF ??? */
		return TYPEDEF_NAME;

	case ENUMERATION_CONSTANT:			/* previously defined */
		return ENUMERATION_CONSTANT;

	default:							/* includes undefined */
		return IDENTIFIER;
	}
}


/* 
void update_location(int line, const char *filename)
{
	static char fn[256];
	//yylloc.first_line = yylloc.last_line = line;
	//yylloc.first_column = yylloc.last_column = 0;
	//ylloc.filename = filename;
	yylineno = line;
	strcpy(fn, filename);
	yyfilename = fn;
} */



/*
List of reserved keywords taken from GCC 2.7.2.3 c-parse.gperf
*/


/*
Tokens taken from GCC 2.7.2.3 c-parse.y

   All identifiers that are not reserved words
   and are not declared typedefs in the current block
%token IDENTIFIER

   All identifiers that are declared typedefs in the current block.
   In some contexts, they are treated just like IDENTIFIER,
   but they can also serve as typespecs in declarations.
%token TYPENAME

   Reserved words that specify storage class.
   yylval contains an IDENTIFIER_NODE which indicates which one.
%token SCSPEC

   Reserved words that specify type.
   yylval contains an IDENTIFIER_NODE which indicates which one.
%token TYPESPEC

   Reserved words that qualify type: "const" or "volatile".
   yylval contains an IDENTIFIER_NODE which indicates which one.
%token TYPE_QUAL

   Character or numeric constants.
   yylval is the node for the constant.
%token CONSTANT

   String constants in raw form.
   yylval is a STRING_CST node.
%token STRING

   "...", used for functions with variable arglists.
%token ELLIPSIS

   the reserved words
%token SIZEOF ENUM STRUCT UNION IF ELSE WHILE DO FOR SWITCH CASE DEFAULT
%token BREAK CONTINUE RETURN GOTO ASM TYPEOF ALIGNOF
%token ATTRIBUTE
*/


/*
	Newer list here: https://android.googlesource.com/toolchain/gcc/+/donut/gcc-4.2.1/gcc/c-parser.c
*/


/*
@class, CLASS, NORID
@compatibility_alias, ALIAS, NORID
@defs, DEFS, NORID
@encode, ENCODE, NORID
@end, END, NORID
@implementation, IMPLEMENTATION, NORID
@interface, INTERFACE, NORID
@private, PRIVATE, NORID
@protected, PROTECTED, NORID
@protocol, PROTOCOL, NORID
@public, PUBLIC, NORID
@selector, SELECTOR, NORID
__alignof, ALIGNOF, NORID
__alignof__, ALIGNOF, NORID
__asm, ASM_KEYWORD, NORID
__asm__, ASM_KEYWORD, NORID
__attribute, ATTRIBUTE, NORID
__attribute__, ATTRIBUTE, NORID
__complex, TYPESPEC, RID_COMPLEX
__complex__, TYPESPEC, RID_COMPLEX
__const, TYPE_QUAL, RID_CONST
__const__, TYPE_QUAL, RID_CONST
__extension__, EXTENSION, NORID
__imag, IMAGPART, NORID
__imag__, IMAGPART, NORID
__inline, SCSPEC, RID_INLINE
__inline__, SCSPEC, RID_INLINE
__iterator, SCSPEC, RID_ITERATOR
__iterator__, SCSPEC, RID_ITERATOR
__label__, LABEL, NORID
__real, REALPART, NORID
__real__, REALPART, NORID
__signed, TYPESPEC, RID_SIGNED
__signed__, TYPESPEC, RID_SIGNED
__typeof, TYPEOF, NORID
__typeof__, TYPEOF, NORID
__volatile, TYPE_QUAL, RID_VOLATILE
__volatile__, TYPE_QUAL, RID_VOLATILE
asm, ASM_KEYWORD, NORID
auto, SCSPEC, RID_AUTO
break, BREAK, NORID
bycopy, TYPE_QUAL, RID_BYCOPY
case, CASE, NORID
char, TYPESPEC, RID_CHAR
const, TYPE_QUAL, RID_CONST
continue, CONTINUE, NORID
default, DEFAULT, NORID
do, DO, NORID
double, TYPESPEC, RID_DOUBLE
else, ELSE, NORID
enum, ENUM, NORID
extern, SCSPEC, RID_EXTERN
float, TYPESPEC, RID_FLOAT
for, FOR, NORID
goto, GOTO, NORID
id, OBJECTNAME, RID_ID
if, IF, NORID
in, TYPE_QUAL, RID_IN
inout, TYPE_QUAL, RID_INOUT
inline, SCSPEC, RID_INLINE
int, TYPESPEC, RID_INT
long, TYPESPEC, RID_LONG
oneway, TYPE_QUAL, RID_ONEWAY
out, TYPE_QUAL, RID_OUT
register, SCSPEC, RID_REGISTER
return, RETURN, NORID
short, TYPESPEC, RID_SHORT
signed, TYPESPEC, RID_SIGNED
sizeof, SIZEOF, NORID
static, SCSPEC, RID_STATIC
struct, STRUCT, NORID
switch, SWITCH, NORID
typedef, SCSPEC, RID_TYPEDEF
typeof, TYPEOF, NORID
union, UNION, NORID
unsigned, TYPESPEC, RID_UNSIGNED
void, TYPESPEC, RID_VOID
volatile, TYPE_QUAL, RID_VOLATILE
while, WHILE, NORID
*/
