/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Skeleton implementation for Bison GLR parsers in C

   Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C GLR parser skeleton written by Paul Hilfinger.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.c"

/* Pure parsers.  */
#define YYPURE 0






/* First part of user prologue.  */
#line 1 "parser.y"

/**
 *	bison -d --verbose --debug parser.y
 *	--locations                  enable location support
 *		NOTE: locations might not be useable, due to the files being preprocessed
 *			If we switch to parsing the original .c and .h files, then we can use locations
 *	--glr-parser				produce a GLR parser
 *	-v, --verbose				verbose mode
 *	-t, --debug					instrument the parser for tracing
 */

#define YYMAXDEPTH 10000000 // seems to do nothing!

#include "lex.yy.h"
#include "ast.h"
#include "ast_nodes.h"
#include "ast_helpers.h"

extern int yylineno;
extern const char *yyfilename;

extern void print_ast_tree(FILE *out, union ast_node* node, int depth, union ast_node* parent);


#include "symbol_table.h"

char func_name[256];
int error_count = 0;


static inline union ast_node* maybe_attributes(union ast_node *left, union ast_node *right);

void yyerror(const char *s);
void register_typedef(union ast_node *decl_specs, union ast_node *declarator);

typedef struct used_datatypes_t {
	int uses_byte;

	int uses_i8;
	int uses_u8;			//	We will have to be careful here, because someone might use "u8" or "i8" as a variable name!
	int uses_int8;
	int uses_uint8;

	int uses_i16;
	int uses_u16;
	int uses_int16;
	int uses_uint16;

	int uses_i32;
	int uses_u32;
	int uses_int32;
	int uses_uint32;

	int uses_i64;
	int uses_u64;
	int uses_int64;
	int uses_uint64;

	int uses_i128;
	int uses_u128;
	int uses_int128;
	int uses_uint128;

	int uses_f32;
	int uses_f64;
	int uses_float32;
	int uses_float64;
} datatypes_t;



#line 129 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;



#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#define YYSIZEMAX \
  (PTRDIFF_MAX < SIZE_MAX ? PTRDIFF_MAX : YY_CAST (ptrdiff_t, SIZE_MAX))

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0)  \
            || 4 < __GNUC__ + (7 <= __GNUC_MINOR__)))
   /* _Noreturn works as-is.  */
# elif 2 < __GNUC__ + (8 <= __GNUC_MINOR__) || 0x5110 <= __SUNPRO_C
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4367

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  194
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  116
/* YYNRULES -- Number of rules.  */
#define YYNRULES  397
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  671
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 7
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token number (for yychar).  */
#define YYMAXUTOK   424
/* YYUNDEFTOK -- Symbol number (for yytoken) that denotes an unknown
   token.  */
#define YYUNDEFTOK  2

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                         \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   182,     2,     2,     2,   173,   175,     2,
     185,   192,   171,   169,   187,   170,   186,   172,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   181,   189,
     177,   179,   178,   180,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   184,     2,   193,   176,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   190,   174,   191,   183,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   188
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   646,   646,   648,   653,   655,   660,   662,   664,   667,
     675,   680,   683,   682,   704,   709,   711,   723,   725,   734,
     735,   739,   741,   746,   748,   750,   752,   754,   756,   758,
     760,   762,   764,   770,   771,   775,   777,   782,   784,   786,
     788,   790,   792,   794,   796,   798,   805,   828,   833,   838,
     840,   845,   847,   855,   857,   877,   878,   882,   890,   899,
     901,   906,   908,   913,   921,   930,   932,   937,   939,   944,
     953,   986,   988,   994,   996,  1002,  1004,  1009,  1077,  1079,
    1101,  1117,  1119,  1124,  1126,  1131,  1132,  1133,  1134,  1135,
    1136,  1137,  1138,  1139,  1140,  1141,  1146,  1148,  1153,  1155,
    1160,  1162,  1167,  1169,  1174,  1176,  1181,  1183,  1188,  1190,
    1192,  1197,  1199,  1201,  1203,  1205,  1210,  1212,  1214,  1219,
    1221,  1223,  1228,  1230,  1232,  1234,  1248,  1252,  1257,  1259,
    1261,  1263,  1265,  1267,  1269,  1276,  1281,  1282,  1283,  1284,
    1285,  1286,  1290,  1292,  1294,  1296,  1306,  1310,  1312,  1321,
    1323,  1325,  1328,  1330,  1335,  1337,  1339,  1341,  1343,  1351,
    1360,  1370,  1375,  1377,  1387,  1391,  1395,  1400,  1401,  1406,
    1408,  1410,  1420,  1422,  1427,  1432,  1433,  1437,  1438,  1442,
    1444,  1470,  1475,  1477,  1490,  1496,  1498,  1500,  1502,  1505,
    1507,  1510,  1512,  1515,  1517,  1520,  1522,  1525,  1527,  1532,
    1534,  1539,  1541,  1560,  1561,  1565,  1567,  1572,  1588,  1596,
    1600,  1602,  1604,  1606,  1617,  1619,  1621,  1623,  1625,  1627,
    1629,  1631,  1633,  1635,  1637,  1639,  1641,  1643,  1645,  1647,
    1662,  1666,  1668,  1670,  1673,  1675,  1677,  1679,  1682,  1684,
    1689,  1691,  1698,  1700,  1703,  1709,  1710,  1715,  1716,  1720,
    1722,  1727,  1729,  1735,  1740,  1742,  1746,  1748,  1753,  1755,
    1760,  1762,  1767,  1770,  1773,  1778,  1781,  1784,  1787,  1790,
    1795,  1797,  1802,  1804,  1810,  1815,  1820,  1821,  1822,  1823,
    1824,  1828,  1829,  1831,  1832,  1834,  1838,  1840,  1845,  1847,
    1852,  1856,  1859,  1861,  1863,  1865,  1867,  1869,  1871,  1873,
    1875,  1877,  1888,  1890,  1892,  1899,  1907,  1913,  1918,  1920,
    1922,  1924,  1929,  1931,  1936,  1938,  1943,  1945,  1950,  1952,
    1954,  1962,  1965,  1970,  1972,  1977,  1979,  1981,  1987,  1989,
    1991,  1993,  1995,  1997,  1999,  2001,  2003,  2005,  2007,  2009,
    2011,  2013,  2015,  2017,  2019,  2021,  2023,  2025,  2027,  2032,
    2034,  2036,  2041,  2043,  2045,  2047,  2052,  2057,  2059,  2064,
    2066,  2082,  2084,  2086,  2088,  2093,  2095,  2095,  2098,  2099,
    2100,  2101,  2103,  2107,  2109,  2111,  2116,  2118,  2129,  2131,
    2136,  2137,  2141,  2143,  2150,  2152,  2154,  2159,  2161,  2163,
    2165,  2167,  2169,  2174,  2175,  2176,  2177,  2178
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "I_CONSTANT", "F_CONSTANT", "ENUMERATION_CONSTANT", "TYPEDEF_NAME",
  "CLASS_NAME", "FUNC_NAME", "SIZEOF", "ARROW", "INC", "DEC", "SHL", "SHR",
  "LE", "GE", "EQ", "NE", "AND", "OR", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE",
  "ELLIPSIS", "PRAGMA", "__ALIGNOF", "__ALIGNOF__", "__ASM", "__ASM__",
  "__ATTRIBUTE", "__ATTRIBUTE__", "__COMPLEX", "__COMPLEX__", "__CONST",
  "__CONST__", "__EXTENSION__", "__IMAG", "__IMAG__", "__INLINE",
  "__INLINE__", "__INTERATOR", "__INTERATOR__", "__LABEL__", "__REAL",
  "__REAL__", "__SIGNED", "__SIGNED__", "__TYPEOF", "__TYPEOF__",
  "__VOLATILE", "__VOLATILE__", "ASM", "TYPEOF", "__RESTRICT",
  "__AUTO_TYPE", "__FORCEINLINE", "FOREACH", "IN", "VOID", "CHAR", "SHORT",
  "INT", "LONG", "FLOAT", "DOUBLE", "SIGNED", "UNSIGNED", "BOOL",
  "COMPLEX", "IMAGINARY", "ATOMIC", "STRUCT", "UNION", "ENUM",
  "__BUILTIN_VA_LIST", "_DECIMAL32", "_DECIMAL64", "_DECIMAL128",
  "_FLOAT128", "__INT128", "__INT128_T", "__UINT128_T", "_BITINT128",
  "_BITINT", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF",
  "GENERIC", "NORETURN", "_STATIC_ASSERT", "STATIC_ASSERT", "THREAD_LOCAL",
  "THIS", "SELF", "NEW", "DELETE", "NS", "FAT_ARROW", "BYTE", "DEFER",
  "VAR", "LET", "CONSTRUCTOR", "DESTRUCTOR", "GET", "SET", "READONLY",
  "IMPL", "CLASS", "EXTENDS", "ABSTRACT", "OPAQUE", "VIRTUAL", "INTERFACE",
  "FINAL", "PUBLIC", "PRIVATE", "PROTECTED", "INTERNAL", "OVERRIDE",
  "EXPLICIT", "FRIEND", "OPERATOR", "TYPENAME", "USING", "IMPLEMENTS",
  "TRAIT", "MIXIN", "TYPE", "TEMPLATE", "NAMESPACE", "IMPORT", "PACKAGE",
  "INSTANCEOF", "NATIVE", "SUPER", "SYNCRONIZED", "TRANSIENT",
  "END_OF_FILE", "'+'", "'-'", "'*'", "'/'", "'%'", "'|'", "'&'", "'^'",
  "'<'", "'>'", "'='", "'?'", "':'", "'!'", "'~'", "'['", "'('", "'.'",
  "','", "UNARY", "';'", "'{'", "'}'", "')'", "']'", "$accept",
  "translation_unit", "external_declarations", "external_declaration",
  "function_definition", "$@1", "fat_arrow_function_definition",
  "declaration_list", "impl_definition", "impl_body", "impl_declarations",
  "impl_declaration", "static_impl_body", "static_impl_declarations",
  "static_impl_declaration", "impl_fat_arrow_function_definition",
  "impl_function_definition", "impl_function_declaration",
  "impl_function_declarator", "impl_direct_declarator", "this_or_self",
  "getters", "getter_declarator", "getter_direct_declarator", "setters",
  "setter_declarator", "setter_direct_declarator",
  "getter_fat_arrow_definition", "setter_fat_arrow_definition",
  "new_function_definition", "new_function_declarator",
  "delete_function_definition", "delete_function_declarator",
  "delete_expression", "pragma", "expression", "assignment_expression",
  "assignment_operator", "conditional_expression", "logical_or_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression",
  "namespace_operator", "constant", "string", "generic_selection",
  "generic_assoc_list", "generic_association", "argument_expression_list",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "maybe_attributes",
  "attributes", "attribute", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "identifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "enumeration_constant", "atomic_type_specifier", "type_qualifier",
  "function_specifier", "alignment_specifier", "declarator",
  "direct_declarator", "extension_specifier", "__asm__specifier",
  "pointer", "type_qualifier_list", "parameter_type_list",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "initializer", "initializer_list", "designation", "designator_list",
  "designator", "static_assert_declaration", "statement", "$@2",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", YY_NULLPTR
};
#endif

#define YYPACT_NINF (-551)
#define YYTABLE_NINF (-367)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    3553,  -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,
    -551,  -551,  -551,  -142,  -551,  -120,  -106,    56,    76,  3928,
    -551,  -551,  -551,  -551,  -551,  -551,    44,  4184,    68,  -551,
    1476,  1563,  1615,  1654,  1756,    68,  -551,  2923,  3451,  3451,
     -66,   126,  -551,  -551,    69,    44,  -100,  -551,    52,  2033,
      33,   -26,  -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,
    -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,
     -45,  -551,  -551,    21,  -551,  -551,  -551,  -551,  -551,  -551,
    -551,  -551,  -551,  -551,  -551,  -551,    43,  -551,  -551,  -551,
    -551,  -551,  -551,  -551,  -551,  1778,  1865,  -551,  -551,  -551,
    -551,  -551,   -63,  -551,  3576,  3640,  3640,  -551,  -551,    90,
      93,  -551,  -551,   179,   295,  -551,  -551,  -551,  -551,  -551,
    -551,  3023,  -551,  -551,  -551,   -12,   296,   127,   144,   151,
      94,    57,   293,   242,   191,  -551,  -551,  3451,    58,  -551,
    -551,  -551,  -551,   149,  4050,   463,  -103,  1726,  3353,  -551,
     152,   -80,  3451,    62,  3763,   161,  -551,  -551,    69,   227,
     165,    44,  -551,  -551,  -551,  -551,  3451,   188,   188,  2555,
      44,  3695,   659,   679,  -551,    33,   738,  -551,  -551,   366,
     210,   504,   237,  -551,  -551,  -551,  -551,    12,  3110,  -551,
    3210,  -551,  -551,   854,  3451,  -551,  -551,    80,  -551,  -551,
      74,   241,  3451,  3451,  3451,  3451,  3451,  3451,  3451,  3451,
    3451,  3451,  3451,  3451,  3451,  3451,  3451,  3451,  3451,  3451,
    3451,  -551,   301,  -551,  -551,  3451,  1260,   322,  -551,  -551,
      68,   843,   750,   234,  -551,   265,  -551,  -551,  1917,  -551,
     434,   253,   442,   266,   338,  3011,  3130,   277,  3790,  -551,
    -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,
      37,  3845,  -551,  -551,  -551,  -551,    68,   243,  2021,  -551,
    -551,  -551,  2397,  3297,   288,  -551,   315,   970,  -551,   269,
    4089,   292,   323,  -551,   102,   324,  -551,    79,  -551,   309,
     366,  -551,   635,  -551,    66,  -551,   915,  -551,  -551,   332,
     335,   336,   344,  3451,  -551,  -551,  -551,  -551,  -551,  -551,
    -551,  -551,  -551,  -551,  -551,  -551,  3451,  2523,   296,  -114,
     127,   144,   151,    94,    57,    57,   293,   293,   293,   293,
     242,   242,   191,   191,  -551,  -551,  -551,  -551,  -551,  -110,
    -551,  -551,   123,  -551,  -551,  3297,   339,  -551,   340,  1044,
    -551,   337,   345,   265,  1169,   873,  -551,   346,  -551,   348,
    -551,   356,   270,    50,    54,  -551,  -551,   357,    29,  -551,
     310,    41,  3198,   355,  3872,  -551,  -551,  -551,  -551,  -551,
    -551,  -551,  -551,  -551,  -551,   368,  -551,   367,  3451,   369,
     364,   372,   376,  2711,   377,   548,   375,   378,  2736,  -551,
    -551,  -551,   247,  -551,  3434,  -551,   188,  -551,  2175,  -551,
    -551,  -551,  -551,  -551,  2379,  -551,  -551,   373,  3297,  -551,
    -551,  3451,   379,  -551,   381,  2400,  -551,   115,  -551,  -551,
    -551,  2943,    68,  -551,  -551,    11,  -551,  3451,   104,  -551,
    -551,  3451,    63,   280,  -551,    68,  -551,  1259,   385,   385,
    -551,   589,  -551,  -551,  2379,  -551,  3451,  -551,  3451,  -551,
     384,  3297,  -551,  -551,  3451,  -551,   389,  -551,  -551,  3297,
     395,  -551,   396,  1243,  -551,   399,   380,   405,   403,  -551,
    -551,   411,   -71,  -551,   562,   416,   -58,  -551,   599,  1070,
    3451,   414,  -551,  -551,  -551,   419,  -551,    54,  -551,  -551,
    2711,   424,  2711,  3451,  3451,  3451,   498,  2611,   420,  -551,
    -551,  -551,   290,  -551,  -551,  -551,  -551,  3451,   607,  -551,
     216,  2397,   -94,  -551,  -551,   418,   427,  -551,  -551,  3989,
    -551,  -551,   618,  -551,  -551,  -551,    15,  -551,  -551,  -551,
      66,  -551,   441,  -551,   444,   129,  -551,   445,   222,  -551,
    -551,  -551,   439,   443,  -551,   447,  3297,  -551,  -551,  3451,
    -551,   448,  -551,  -551,  -551,  -551,   450,  3451,  -551,  -551,
    -551,  4249,  3451,  -551,  -551,  -551,   598,   454,   291,  -551,
    1366,   316,  -551,  2711,  -551,   141,   143,   145,   465,  2836,
    2836,  -551,  -551,   456,  -551,  2151,  -551,  -551,  -551,  -551,
    -551,  -551,  -551,  -551,  -551,  3451,  3451,   820,  -551,  3451,
    2300,  -551,  -551,  -551,  -551,   458,   460,  -551,   615,   298,
     467,   304,  -551,   617,  -551,  -551,   468,  -551,  2711,  2711,
    2711,  3451,  1385,  1459,  -551,  -551,  -551,  2397,  -551,  -551,
    -551,  -551,  -551,  -551,  -551,  -551,  -551,   629,  -551,  -551,
    -551,   551,  -551,  -551,   147,  2711,   153,  2711,   156,  -551,
    -551,  2711,   482,  -551,  2711,  -551,  2711,  -551,  -551,  -551,
    -551
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     203,   281,   276,   277,   279,    80,   207,   306,   283,   284,
     278,   285,   280,     0,   282,     0,     0,     0,     0,   203,
       4,     6,     7,     9,    10,     8,   203,     0,   204,   205,
     203,   203,   203,   203,   203,   203,   184,   203,     0,     0,
       0,     0,     1,     5,   311,   203,     0,   199,     0,   203,
     289,   203,   229,   208,   209,   210,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
       0,   247,   248,     0,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   211,   227,     0,   228,   226,   206,
     185,   191,   193,   195,   197,   203,   203,   154,   172,   169,
     170,   171,     0,   173,     0,     0,     0,   307,   160,     0,
       0,    55,    56,   164,    79,   138,   139,   137,   136,   141,
     140,   203,   159,   165,   181,    96,    98,   100,   102,   104,
     106,   108,   111,   116,   119,   122,   126,     0,   128,   142,
     155,   156,   158,     0,     0,   203,   324,   203,   203,   166,
       0,     0,     0,     0,   203,     0,   312,   310,   309,     0,
       0,   203,   183,   290,   182,   291,     0,     0,     0,   203,
     203,   202,     0,   203,   305,   288,   203,   245,   246,     0,
     269,   203,   244,   187,   189,   167,   168,     0,   203,   132,
     203,   129,   130,   203,     0,   161,    78,     0,    81,    83,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   131,     0,   150,   151,     0,     0,     0,   287,   254,
     203,     0,   203,   326,   323,   327,   258,   135,   203,   286,
       0,     0,     0,     0,     0,   203,   203,     0,   203,    21,
      24,    23,    31,    29,    30,    25,    26,    27,    28,    32,
       0,   203,   313,   308,   292,   200,   203,     0,   203,    13,
      11,    16,     0,     0,   137,   293,     0,     0,   303,   203,
       0,     0,   315,   316,     0,     0,   274,     0,   270,   273,
       0,   240,   203,   249,   203,   253,   203,   163,   162,     0,
       0,     0,     0,     0,   157,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    85,     0,     0,    99,     0,
     101,   103,   105,   107,   109,   110,   114,   115,   112,   113,
     117,   118,   120,   121,   123,   124,   125,   149,   148,     0,
     144,   179,     0,   146,   147,     0,   137,   329,     0,     0,
     345,     0,     0,   325,     0,   203,   256,     0,   362,     0,
     364,     0,     0,     0,     0,    17,    22,     0,   203,    50,
       0,     0,   203,     0,   203,    35,    38,    37,    44,    42,
      43,    39,    40,    41,    45,   202,    14,   154,     0,     0,
       0,     0,     0,   366,     0,     0,     0,     0,     0,   382,
     376,   372,     0,   380,   203,   381,     0,   365,   203,   378,
     368,   369,   370,   371,     0,   351,   201,     0,     0,   294,
     301,     0,   137,   300,     0,   203,   318,   203,   319,   321,
     302,   203,   203,   304,   275,     0,   265,     0,     0,   241,
     250,     0,     0,     0,   260,   203,   242,   203,   133,     0,
     134,   203,    82,    84,     0,   127,     0,   143,     0,   145,
       0,     0,   330,   336,     0,   335,     0,   346,   328,     0,
     137,   337,     0,     0,   347,     0,     0,     0,     0,    76,
      75,     0,     0,    60,     0,     0,     0,    66,     0,   203,
       0,     0,    47,    72,    71,     0,    49,     0,    18,    36,
     366,     0,   366,     0,     0,     0,     0,   203,     0,   394,
     395,   396,     0,   383,   367,   377,   379,     0,     0,   353,
       0,     0,     0,   357,   296,     0,     0,   297,   299,     0,
     314,   317,     0,   266,   271,   272,     0,   267,   264,   251,
     203,   252,   262,   243,     0,     0,   175,     0,     0,    97,
     180,   332,     0,     0,   334,     0,     0,   338,   344,     0,
     343,     0,   348,   361,   363,    77,     0,     0,    58,    57,
      59,   203,     0,    64,    63,    65,    52,     0,     0,    48,
     203,     0,   373,   366,   375,     0,     0,     0,     0,     0,
       0,   393,   397,     0,   360,     0,   349,   352,   356,   358,
     295,   298,   322,   268,   261,     0,     0,   203,   174,     0,
       0,   152,   331,   333,   340,     0,     0,   341,    61,     0,
       0,     0,    54,    51,    46,    73,     0,   374,   366,   366,
     366,     0,     0,     0,   359,   350,   355,     0,   263,   178,
     176,   177,   153,   339,   342,    62,    69,    67,    70,    53,
      74,   385,   386,   387,     0,   366,     0,   366,     0,   354,
      68,   366,     0,   391,   366,   389,   366,   384,   388,   392,
     390
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -551,  -551,  -551,   658,  -551,  -551,  -551,   510,  -551,  -551,
    -551,   432,  -551,  -551,   307,  -235,  -207,  -119,  -551,   312,
     -43,  -109,  -551,   198,    -3,   189,   197,     2,  -551,    24,
    -551,    27,  -551,  -551,    42,   -33,   342,  -551,   -35,  -551,
     486,   493,   485,   495,   496,   313,   263,   311,   302,   -90,
     175,  -551,  -551,  -551,  -551,  -551,  -551,  -551,  -551,    95,
    -551,   -27,   -42,   464,  -551,   543,   -10,  -551,   677,   -34,
       1,  -551,   622,  -551,   415,  -275,   -95,  -551,   174,  -551,
     425,  -161,  -551,  -551,   166,  -551,  -551,   -17,   -31,     0,
      75,     4,  -147,  -160,  -551,  -372,  -551,    83,  -118,  -227,
    -264,   262,  -550,  -551,   199,   -87,   -74,  -551,  -551,  -146,
    -551,   318,  -284,  -551,  -551,  -551
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,    21,   167,    22,   168,    23,   247,
     248,   249,   373,   374,   375,   250,   251,   252,   368,   369,
     122,   253,   482,   483,   254,   486,   487,   255,   256,   257,
     370,   258,   362,   123,   401,   402,   198,   316,   199,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     200,   137,   138,   139,   187,   140,   141,   142,   545,   546,
     342,   143,    25,   279,    46,    47,    27,    28,    29,    30,
      31,    85,   180,    86,   292,   293,   146,   443,   444,    87,
     287,   288,   289,    88,    32,    33,    34,   160,    50,   152,
     149,    51,   158,   351,   282,   283,   284,   547,   352,   235,
     519,   520,   521,   522,   523,    36,   405,   406,   407,   574,
     408,   409,   410,   411,   412,   413
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    95,   124,   124,   124,   165,   353,   169,   416,    49,
     202,   151,   153,   281,   286,   297,    48,   440,   286,    35,
     175,   269,   270,     6,   177,   277,   376,   144,   234,   178,
      35,    35,    35,    35,    35,   159,    96,   148,   145,   171,
     367,   159,    24,    37,   367,   637,   177,   221,   157,    35,
     229,   178,   236,   481,   377,   163,   567,   485,   237,   531,
     637,    24,   237,   185,    40,    38,   163,   456,    44,   572,
     222,   223,   224,   303,   210,   211,    42,   303,     6,    39,
     107,   231,   232,   457,   349,   598,   294,   161,   197,   162,
     517,    41,   518,     6,   295,    35,    35,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   240,     2,     3,
       4,   144,   241,   208,   209,     6,   165,     6,   568,   268,
     150,   148,   145,   186,   154,   174,   418,   169,   334,   335,
     336,   573,   268,   267,   155,   144,   298,   144,   144,   376,
     176,    10,   378,   356,   266,   230,   145,   230,   145,   238,
     233,   159,   379,   266,    35,   197,   490,   197,    12,    45,
      48,   428,   263,   280,     6,   495,   144,   377,   203,    35,
     319,   144,   440,    35,   111,   112,   230,   145,   144,   338,
     144,   230,   145,   144,   344,   111,   112,   195,   148,   145,
     148,   145,   339,   230,   145,   475,   259,   294,   461,   620,
     353,   294,   533,   147,   201,   295,   603,   473,    44,   295,
     156,   179,   136,   136,   136,    44,   480,   172,   173,   268,
     144,    44,   492,   590,   494,    44,   403,   455,   144,    45,
     163,   238,    35,   181,   212,   213,   233,    44,   230,   145,
      44,   164,   225,   226,   227,    35,    35,   441,    35,   242,
     174,    45,   539,   315,   243,   378,   385,   597,   380,   285,
     514,    35,   426,   381,   371,   379,   435,   303,   404,   159,
     436,   299,   304,   300,   534,   193,   301,   445,   194,   189,
     191,   192,   144,   427,   442,   382,   144,   147,   383,   432,
     259,   536,   230,   145,   433,   537,   230,   145,   196,   231,
     425,   205,  -326,   384,   337,   632,   633,  -326,   214,   215,
     458,   147,   136,   147,   237,   459,   607,   204,     6,   506,
     206,   608,   556,   136,   262,   343,   207,   136,   303,   577,
     303,   636,   303,   628,   303,   629,   569,   630,   156,   662,
     303,   228,   147,   303,   239,   664,   636,   147,   666,   111,
     112,   261,   294,   124,   147,    35,   147,   264,   491,   147,
     295,   501,   218,   219,   220,   512,   403,   484,   488,   286,
      95,   380,    35,   659,    35,   534,   381,   136,   268,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   175,   156,   382,   165,
     290,   383,   124,   595,   147,    96,   124,   596,   404,   610,
     535,   216,   217,   611,   538,   529,   384,   159,   231,   232,
     626,   549,   532,   111,   112,    35,   582,   296,   584,   427,
     303,    35,   386,   317,   303,   542,   513,   144,   357,   156,
      44,   144,   358,   262,   111,   112,   359,   230,   145,   354,
     355,   230,   145,   231,   425,   360,  -320,   578,   147,   479,
     268,  -320,   147,   361,    26,   589,  -255,   540,   365,   541,
     585,   586,   587,   326,   327,   328,   329,   303,   303,   592,
     624,   419,   124,    26,   430,   303,   165,   646,   437,    35,
     593,   303,   136,   648,    90,    91,    92,    93,    94,   493,
     268,   488,     2,     3,     4,   573,   268,   404,   420,   627,
     431,   156,     6,   170,   276,   262,   434,     7,   332,   333,
     156,   324,   325,   445,   448,   330,   331,   449,   450,   467,
     159,   451,   462,   463,   619,    10,   302,   468,   476,   621,
     477,   478,   489,     2,     3,     4,   498,   272,   500,   503,
     502,   508,    12,     6,   651,   652,   653,   504,     7,   183,
     184,   505,   507,   136,   509,   481,   524,   510,   341,   563,
     124,    35,   527,   348,   528,   454,    10,   551,   638,   136,
      35,   663,   554,   665,   262,  -255,  -255,   667,   557,   558,
     669,   562,   670,    12,   564,   565,   566,   144,   654,   656,
     658,   571,   485,   579,   580,   583,   588,   230,   145,   591,
     594,   600,   136,   147,   415,   417,   136,   147,   260,   424,
     601,   602,   605,    15,    16,   606,   609,   262,     2,     3,
       4,   136,   612,   170,  -255,   156,   613,   622,     6,   262,
     614,   617,   618,     7,  -255,   452,   623,  -255,  -255,   634,
     631,   643,  -255,   644,   645,  -255,   649,   661,   453,   647,
     650,    10,    97,    98,    99,   100,   101,   102,   660,   103,
     104,   668,   105,   106,     2,     3,     4,    43,    12,   271,
     366,   499,   570,   496,     6,   575,   581,   460,   318,     7,
     321,   466,   136,   544,   273,   291,   472,   320,     2,     3,
       4,   322,   640,   323,   265,    89,   107,    10,   182,   363,
     364,   447,   260,     7,   604,   438,   548,     1,     2,     3,
       4,   599,   262,     0,    12,   260,   516,     0,     6,     0,
       0,    10,   170,     7,     0,   108,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,    10,     0,    11,    15,    16,   415,     0,     0,     0,
     525,     0,     0,   526,     0,     0,     0,     0,    12,     0,
       0,     0,     0,   147,     0,   109,   110,     2,     3,     4,
     136,   111,   112,   113,   114,     0,     0,     6,     1,     2,
       3,     4,     7,     0,    13,     0,   415,    14,     0,     6,
     550,     0,     0,   552,     7,     0,   553,     8,     9,     0,
      10,   555,     0,     0,     0,   561,     0,     0,     0,     0,
       0,     0,    10,     0,    11,     0,   439,    12,   115,   116,
     274,     0,     0,     0,   118,     0,   497,     0,   260,    12,
       0,   119,   120,     0,   121,     0,    97,    98,    99,   100,
     101,   102,   275,   103,   104,     0,   105,   106,     0,     2,
       3,     4,     0,   415,     0,    13,     0,     0,    14,     6,
       0,   278,   170,     0,     7,     0,     0,     0,   345,     0,
       0,     0,     2,     3,     4,     0,     0,     0,     0,     0,
     107,     0,    10,     2,     3,     4,     0,     7,   615,     0,
       0,   616,     0,     6,     0,     0,     0,     0,     7,    12,
       0,     1,     2,     3,     4,    10,     0,     0,     0,   108,
       0,    44,     6,     0,   544,     0,    10,     7,     0,     0,
       8,     9,    12,     0,   231,   232,     0,   415,     0,     0,
       0,     0,   350,    12,     0,    10,     0,    11,   639,     0,
       0,   641,   415,     0,     2,     3,     4,     0,     0,   109,
     110,     0,    12,     0,     6,   111,   112,   113,   114,     7,
       0,   170,     0,    97,    98,    99,   100,   101,   102,   415,
     103,   104,     0,   105,   106,     0,     0,    10,    13,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,   421,     0,     0,     0,     2,
       3,     4,   115,   116,   346,     0,     0,   107,   118,     0,
       0,     0,     0,     0,     7,   119,   120,     0,   121,     0,
       0,     0,     0,     0,    15,    16,   347,     0,     0,     0,
       0,     0,    10,     0,     0,     0,   108,    97,    98,    99,
     100,   101,   102,     0,   103,   104,     0,   105,   106,    12,
       0,     0,     0,     0,     0,   474,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
       0,     0,     0,     2,     3,     4,   109,   110,     0,     0,
       0,   107,   111,   112,   113,   114,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,   446,     0,     1,     2,
       3,     4,     0,     0,     0,     0,    10,     0,     0,     6,
     108,     0,     0,     0,     7,     0,     0,     8,     9,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,   115,
     116,   422,    10,     0,    11,   118,     0,     0,     0,     0,
       0,     0,   119,   120,     0,   121,     0,     0,     0,    12,
     109,   110,     0,   423,     0,     0,   111,   112,   113,   114,
       0,     0,    97,    98,    99,   100,   101,   102,     0,   103,
     104,     0,   105,   106,     0,    13,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   469,     0,     0,     0,     2,     3,
       4,     0,     0,   115,   116,   117,   107,     0,     0,   118,
       0,     0,     0,     7,     0,     0,   119,   120,     0,   121,
       0,     0,     0,     0,     0,     0,     0,   465,     0,     0,
       0,    10,     0,     0,     0,   108,    97,    98,    99,   100,
     101,   102,     0,   103,   104,     0,   105,   106,    12,     0,
       0,     0,   576,    97,    98,    99,   100,   101,   102,     0,
     103,   104,     0,   105,   106,     0,     0,     0,   559,     0,
       0,     0,     2,     3,     4,   109,   110,     0,     0,     0,
     107,   111,   112,   113,   114,     0,     0,     7,     2,     3,
       4,     0,     0,     0,     0,     0,     0,   107,     6,     0,
       0,     0,     0,     7,     7,    10,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    12,     0,     0,     0,   108,     0,   115,   116,
     470,     0,     0,     0,   118,     0,     0,     0,    12,     0,
       0,   119,   120,     0,   121,     0,     0,     0,     0,   109,
     110,     0,   471,     0,     0,   111,   112,   113,   114,     0,
       0,     0,     0,     0,     0,     0,   109,   110,    15,    16,
       0,     0,   111,   112,   113,   114,     0,     0,    97,    98,
      99,   100,   101,   102,     0,   103,   104,     0,   105,   106,
       0,     0,     0,     0,     1,     2,     3,     4,     0,     0,
       0,     0,   115,   116,   117,     6,     0,     0,   118,     0,
       7,     0,     0,     8,     9,   119,   120,     0,   121,   115,
     116,   117,   107,     0,     0,   118,   560,     0,    10,     7,
      11,     0,   119,   120,     0,   121,     0,     0,     0,     0,
     543,     0,   340,     0,     0,    12,     0,     0,     0,     0,
       0,   108,    97,    98,    99,   100,   101,   102,     0,   103,
     104,     0,   105,   106,     0,     0,     0,     0,     0,  -186,
       0,    13,     0,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,   110,     0,     0,     0,   107,   111,   112,   113,
     114,     0,     0,     7,     1,     2,     3,     4,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     0,     0,     0,
       7,     0,     0,     8,     9,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,     0,
      11,     0,     0,     0,   115,   116,   117,     0,   625,     0,
     118,     0,     0,     0,     0,    12,  -192,   119,   120,     0,
     121,     0,     0,     0,     0,   109,   110,   655,     0,     0,
       0,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,    13,     0,     0,    14,     0,     0,     0,  -186,  -186,
       0,     1,     2,     3,     4,     0,     0,     0,     0,     0,
       0,     0,     6,     0,     0,     0,     0,     7,  -194,     0,
       8,     9,     0,     0,     0,     0,     0,     0,   115,   116,
     117,     0,     0,     0,   118,    10,     0,    11,     0,     0,
       0,   119,   120,     0,   121,     0,     0,  -186,     0,     0,
       0,   657,    12,     1,     2,     3,     4,  -196,     0,     0,
    -186,  -186,     0,  -186,     6,  -186,     0,     0,  -186,     7,
       0,     0,     8,     9,     0,     0,     0,     0,    13,     0,
       0,    14,     0,     0,     0,  -192,  -192,    10,     0,    11,
       0,     0,     1,     2,     3,     4,     0,     0,     0,     0,
       0,     0,     0,     6,    12,     0,     0,     0,     7,     0,
       0,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,     0,    11,  -259,
      13,     0,     0,    14,  -192,     0,     0,  -194,  -194,     0,
       0,     0,     0,    12,     0,     0,     0,  -192,  -192,     0,
    -192,     0,  -192,     0,     0,  -192,     0,     0,     0,  -198,
       0,     0,     0,     0,     0,     2,     3,     4,     0,    13,
       0,     0,    14,     0,     0,     6,  -196,  -196,     0,     0,
       7,  -188,     0,     0,     0,     0,  -194,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,    10,  -194,
    -194,     0,  -194,     0,  -194,     6,     0,  -194,     0,     0,
       7,     0,     0,     8,     9,    12,     1,     2,     3,     4,
       0,     0,     0,     0,     0,  -196,     0,     6,    10,     0,
      11,     0,     7,     0,     0,     8,     9,     0,  -196,  -196,
       0,  -196,     0,  -196,     0,    12,  -196,     0,  -259,  -259,
      10,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,  -190,     0,
       0,    13,     0,     0,    14,     0,     0,     0,  -198,  -198,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,    14,  -259,     0,     0,
    -188,  -188,     0,     1,     2,     3,     4,  -259,     0,     0,
    -259,  -259,     0,     0,     6,  -259,     0,     0,  -259,     7,
    -257,     0,     8,     9,     0,     0,     0,  -198,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     0,    11,
    -198,  -198,     0,  -198,     0,  -198,     0,     0,  -198,  -188,
       0,     0,     0,     0,    12,     0,     2,     3,     4,     0,
       0,     0,  -188,  -188,     0,  -188,     6,  -188,     0,     0,
    -188,     7,     0,     0,     0,     0,     0,     0,     0,     0,
      13,     0,     0,    14,     0,     0,     0,  -190,  -190,    10,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   387,    98,    99,   100,   101,   102,
       0,   103,   104,     0,   105,   106,  -190,     0,     0,  -257,
    -257,     0,     0,     0,     0,     0,     0,     0,     0,  -190,
    -190,     0,  -190,     0,  -190,     0,     0,  -190,     0,     1,
       2,     3,     4,     0,     5,     0,     0,     0,   107,     0,
       6,     1,     2,     3,     4,     7,     0,     0,     8,     9,
       0,     0,     6,     0,     0,     0,     0,     7,  -257,     0,
       8,     9,     0,    10,     0,    11,     0,   108,  -257,     0,
       0,  -257,  -257,     0,     0,    10,  -257,    11,     0,  -257,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,   388,   389,   390,     0,   391,   392,
     393,   394,   395,   396,   397,   398,    13,   109,   110,    14,
      15,    16,     0,   111,   112,   113,   114,     0,    13,     0,
       0,    14,    15,    16,    97,    98,    99,   100,   101,   102,
     166,   103,   104,     0,   105,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   387,    98,
      99,   100,   101,   102,     0,   103,   104,     0,   105,   106,
     115,   116,   117,     0,     0,     0,   118,     0,   107,     0,
       0,     0,     0,   119,   120,     7,   121,     0,     0,     0,
     399,  -366,   400,     1,     2,     3,     4,     0,     5,     0,
       0,     0,   107,   -12,     6,     0,     0,   108,     0,     7,
       0,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,     0,    11,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,     0,   388,   389,
     390,     0,   391,   392,   393,   394,   395,   396,   397,   398,
      13,   109,   110,    14,    15,    16,     0,   111,   112,   113,
     114,     0,     0,    97,    98,    99,   100,   101,   102,     0,
     103,   104,     0,   105,   106,     0,     0,     0,     0,     0,
     115,   116,   117,     0,     0,     0,   118,     0,     0,     0,
       0,     0,     0,   119,   120,   517,   121,   518,     0,     0,
       0,   414,   635,     0,   115,   116,   117,   107,     0,     0,
     118,     0,     0,     0,     7,     0,     0,   119,   120,     0,
     121,     0,     0,     0,   399,  -366,   515,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,    97,    98,    99,   100,   101,   102,     0,   103,
     104,     0,   105,   106,     0,     0,     0,     0,     0,     0,
      97,    98,    99,   100,   101,   102,     0,   103,   104,     0,
     105,   106,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,   107,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     1,     2,
       3,     4,     0,     0,   107,     0,     0,     0,     0,     6,
       0,     7,     0,     0,     7,   108,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
     116,   117,    10,   108,    11,   118,     0,     0,     0,     0,
       0,     0,   119,   120,   517,   121,   518,     0,     0,    12,
     414,   642,     0,     0,     0,   109,   110,     0,     0,     0,
       0,   111,   112,   113,   114,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,    13,     0,     0,    14,   111,
     112,   113,   114,     0,     0,     0,    97,    98,    99,   100,
     101,   102,     0,   103,   104,     0,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   115,   116,
     117,     0,     0,     0,   118,     0,     0,     0,     0,     0,
       0,   119,   120,   517,   121,   518,   115,   116,   117,   414,
     107,    44,   118,     0,     0,     0,     0,     7,     0,   119,
     120,     0,   121,     0,   231,   425,     0,   414,     0,     0,
       0,     0,   350,     1,     2,     3,     4,     0,     0,   108,
       0,     0,     0,     0,     6,     0,     0,     0,     0,     7,
       0,     0,     8,     9,    97,    98,    99,   100,   101,   102,
       0,   103,   104,     0,   105,   106,     0,    10,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     0,     0,    12,   111,   112,   113,   114,     1,
       2,     3,     4,     0,     0,     0,     0,     0,   107,     0,
       6,     0,     0,     0,     0,     7,     0,     0,     8,     9,
      13,     0,     0,    14,    15,    16,     0,     0,     0,     0,
       0,     0,     0,    10,     0,    11,     0,   108,     0,     0,
       0,     0,   115,   116,   117,     0,     0,     0,   118,     0,
      12,     0,     0,     0,     0,   119,   120,     0,   121,     0,
       0,     0,     0,   454,   387,    98,    99,   100,   101,   102,
       0,   103,   104,     0,   105,   106,    13,   109,   110,    14,
      15,    16,     0,   111,   112,   113,   114,     0,     0,    97,
      98,    99,   100,   101,   102,   -15,   103,   104,     0,   105,
     106,     0,     0,     0,     5,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   107,     0,     0,   118,   108,     0,     0,
       7,     0,     0,   119,   120,     0,   121,     0,     0,     0,
     399,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   108,     0,   388,   389,   390,     0,   391,   392,
     393,   394,   395,   396,   397,   398,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,     0,     0,    97,
      98,    99,   100,   101,   102,     0,   103,   104,     0,   105,
     106,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     115,   116,   117,   107,     0,     0,   118,     0,     0,     0,
       7,     0,     0,   119,   120,     0,   121,     0,     0,     0,
     399,     0,     0,     0,     0,   115,   116,   117,     0,     0,
       0,   118,   108,     0,     0,     0,     0,     0,   119,   120,
       0,   121,     0,     0,     0,   511,    97,    98,    99,   100,
     101,   102,     0,   103,   104,     0,   105,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   110,     0,     0,     0,     0,   111,   112,
     113,   114,     2,     3,     4,     0,     0,     0,     0,     0,
     107,     0,     6,     0,     0,     0,     0,     7,     0,     0,
       0,     1,     2,     3,     4,   530,     0,     0,     0,     0,
       0,     0,     6,     0,     0,    10,     0,     7,     0,   108,
       8,     9,     0,     0,     0,   115,   116,   117,     0,     0,
       0,   118,    12,     0,     0,    10,     0,    11,   119,   120,
       0,   121,     0,     0,     0,   399,    97,    98,    99,   100,
     101,   102,    12,   103,   104,     0,   105,   106,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,     1,
       2,     3,     4,     0,     0,     0,     0,     0,    13,     0,
       6,    14,     2,     3,     4,     7,     0,     0,     8,     9,
     107,     0,     6,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     0,    10,     0,    11,     0,     0,     0,     0,
       0,     0,   115,   116,   117,    10,     0,     0,   118,   108,
      12,     0,     0,     0,     0,   119,   120,     0,   121,     0,
       0,     0,    12,    97,    98,    99,   100,   101,   102,     0,
     103,   104,     0,   105,   106,     0,    13,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   109,
     110,     0,     0,     0,     0,   111,   112,   113,   114,     2,
       3,     4,     0,     0,     0,     0,     0,   107,     0,     6,
       0,     0,     0,     0,     7,     0,     0,     0,     1,     2,
       3,     4,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     0,    10,     0,     7,     0,   108,     8,     9,     0,
       0,     0,   115,   116,   117,     0,     0,     0,   118,    12,
       0,     0,    10,     0,    11,   119,   120,     0,   121,     0,
       0,     0,     0,    97,    98,    99,   100,   101,   102,    12,
     103,   104,     0,   105,   106,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,     1,     2,     3,     4,
       0,     0,     0,     0,     0,    13,     0,     6,    14,     2,
       3,     4,     7,     0,     0,     8,     9,   107,     0,     6,
       0,     0,     0,     0,     7,     0,     0,     0,     0,     0,
      10,     0,    11,     0,     0,     0,     0,     0,     0,   115,
     116,   117,    10,     0,     0,   118,   108,    12,     0,     0,
       0,     0,   119,   120,     0,   121,     0,     0,     0,    12,
      97,    98,    99,   100,   101,   102,     0,   103,   104,     0,
     105,   106,     0,    13,     0,     0,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,     0,   111,   112,   113,   114,     2,     3,     4,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,    97,    98,    99,   100,
     101,   102,     0,   103,   104,     0,   105,   106,     0,    10,
       0,     0,     0,   108,     0,     0,     0,     0,     0,   115,
     116,   117,     0,     0,     0,   118,    12,     0,     0,     0,
       0,     0,   119,   120,     0,   121,     0,     0,     0,     0,
     107,     0,     6,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     0,   109,   110,     0,     0,     0,     0,   111,
     112,   113,   114,     0,     0,     0,     0,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    99,
     100,   101,   102,     0,   103,   104,     0,   105,   106,     0,
       0,     0,     0,     0,    97,    98,    99,   100,   101,   102,
       0,   103,   104,     0,   105,   106,   115,   116,   117,   109,
     110,     0,   118,     0,     0,   111,   112,   113,   114,   119,
     120,   107,   121,     6,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   115,   116,   117,     0,     0,   108,   118,     0,
       0,     0,     0,     0,     0,   119,   120,     0,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     109,   110,     0,    -2,     0,     0,   111,   112,   113,   114,
       0,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,     0,   111,   112,   113,   114,     0,     0,    97,
      98,    99,   100,   101,   102,     0,   103,   104,     0,   105,
     106,     1,     2,     3,     4,     0,     5,     0,     0,     0,
       0,     0,     6,   115,   116,   117,     0,     7,     0,   118,
       8,     9,     0,     0,     0,     0,   119,   120,     0,   121,
     115,   116,   117,   107,     0,    10,   118,    11,     0,     0,
       7,     0,     0,   119,   120,     0,   121,     0,     0,     0,
       0,     0,    12,    97,    98,    99,   100,   101,   102,     0,
     103,   104,   108,   105,   106,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   107,     0,     0,
      17,     0,   109,   110,     7,     0,     0,     0,   111,   112,
     113,   114,     0,    52,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,    54,
      55,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   115,   116,   117,     0,     0,
       0,   118,     0,     0,     0,     0,   109,   110,   119,   120,
       0,   188,   111,   112,   113,   114,     0,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,     0,     0,
       0,     1,     2,     3,     4,     0,     5,     0,     0,   115,
     116,   117,     6,     0,     0,   118,    84,     7,     0,     0,
       8,     9,   119,   120,     0,   190,     0,     0,     1,     2,
       3,     4,     0,     5,     0,    10,     0,    11,     0,     6,
     244,     0,     0,     0,     7,     0,     0,     8,     9,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,    11,     0,     0,   244,     0,     0,
       0,     0,     0,     0,   272,     0,     0,     0,    13,    12,
       0,    14,     0,     1,     2,     3,     4,     0,     5,     0,
       0,     0,     0,     0,     6,     0,     0,   245,   246,     7,
       0,     0,     8,     9,     0,    13,     0,     0,    14,     0,
       1,     2,     3,     4,     0,     5,     0,    10,     0,    11,
       0,     6,   244,     0,   245,   246,     7,     0,    -3,     8,
       9,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,    11,     0,     0,   244,
       0,     0,     0,     0,   -19,     0,     0,     0,     0,     0,
      13,    12,     0,    14,     0,     0,     1,     2,     3,     4,
       0,     5,     0,     0,     0,     0,     0,     6,     0,   245,
     372,   -20,     7,     0,     0,     8,     9,    13,     0,     0,
      14,     0,   163,     0,     0,     0,     0,    52,     0,     0,
      10,     0,    11,     0,     0,     0,   245,   372,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,    53,    54,    55,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   -33,     0,     0,     0,
       0,     0,     0,    13,     0,     0,    14,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,     0,
       0,     0,     0,   -34,     0,    17,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,   429,     0,     0,     0,     0,    52,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    52,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     1,     2,     3,
       4,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     7,     0,    84,     8,     9,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     0,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,    14
};

static const yytype_int16 yycheck[] =
{
       0,    35,    37,    38,    39,    48,   233,    49,   272,    26,
      22,    38,    39,   173,     3,     3,    26,   292,     3,    19,
      51,   167,   168,    49,     3,   172,   261,    37,   146,     8,
      30,    31,    32,    33,    34,    45,    35,    37,    37,    49,
       3,    51,     0,   185,     3,   595,     3,   137,    44,    49,
     145,     8,   147,     3,   261,     3,   127,     3,   148,   431,
     610,    19,   152,   126,     8,   185,     3,   181,   171,   127,
      12,    13,    14,   187,    17,    18,     0,   187,    49,   185,
      47,   184,   185,   193,   231,   179,   181,   187,   121,   189,
     184,    35,   186,    49,   181,    95,    96,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,   187,    39,    40,
      41,   121,   192,    19,    20,    49,   159,    49,   189,   190,
      37,   121,   121,   186,   190,    50,   273,   169,   218,   219,
     220,   189,   190,   166,     8,   145,   124,   147,   148,   374,
     185,    72,   261,   238,   161,   145,   145,   147,   147,   148,
     146,   161,   261,   170,   154,   188,   127,   190,    89,   185,
     170,   279,   158,   173,    49,   124,   176,   374,   180,   169,
     203,   181,   447,   173,   122,   123,   176,   176,   188,   222,
     190,   181,   181,   193,   227,   122,   123,     8,   188,   188,
     190,   190,   225,   193,   193,   355,   154,   292,   345,   571,
     427,   296,   191,    37,   121,   292,   191,   354,   171,   296,
      44,   190,    37,    38,    39,   171,   362,   184,   185,   190,
     230,   171,   368,   507,   370,   171,   268,   317,   238,   185,
       3,   230,   232,   190,   177,   178,   232,   171,   238,   238,
     171,   189,   184,   185,   186,   245,   246,   181,   248,   187,
     175,   185,   189,   179,   192,   374,   266,   521,   261,   176,
     406,   261,   279,   261,   260,   374,   187,   187,   268,   279,
     191,   188,   192,   190,   435,   185,   193,   294,   185,   104,
     105,   106,   292,   279,   294,   261,   296,   121,   261,   187,
     248,   187,   292,   292,   192,   191,   296,   296,     3,   184,
     185,   174,   187,   261,     3,   589,   590,   192,    15,    16,
     187,   145,   137,   147,   404,   192,   187,    21,    49,   393,
     176,   192,   469,   148,   158,     3,   175,   152,   187,   489,
     187,   595,   187,   192,   187,   192,   482,   192,   172,   192,
     187,   192,   176,   187,   192,   192,   610,   181,   192,   122,
     123,   190,   447,   388,   188,   355,   190,   192,   368,   193,
     447,   388,   171,   172,   173,   398,   408,   363,   364,     3,
     404,   374,   372,   637,   374,   536,   374,   202,   190,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   427,   231,   374,   442,
     190,   374,   437,   187,   238,   404,   441,   191,   408,   187,
     437,   169,   170,   191,   441,   425,   374,   427,   184,   185,
     580,   456,   432,   122,   123,   425,   500,   190,   502,   425,
     187,   431,   189,   192,   187,   445,   189,   447,     4,   273,
     171,   451,   189,   277,   122,   123,     4,   447,   447,   184,
     185,   451,   451,   184,   185,   189,   187,   490,   292,   189,
     190,   192,   296,   125,     0,   507,     3,   187,   191,   189,
     503,   504,   505,   210,   211,   212,   213,   187,   187,   189,
     189,   193,   517,    19,   192,   187,   529,   189,   179,   489,
     517,   187,   317,   189,    30,    31,    32,    33,    34,   189,
     190,   497,    39,    40,    41,   189,   190,   507,   193,   583,
     187,   345,    49,    49,   172,   349,   192,    54,   216,   217,
     354,   208,   209,   540,   192,   214,   215,   192,   192,   192,
     540,   187,   193,   193,   567,    72,   194,   192,   192,   572,
     192,   185,   185,    39,    40,    41,   191,   179,   181,   185,
     181,     3,    89,    49,   628,   629,   630,   185,    54,    95,
      96,   185,   185,   388,   189,     3,   193,   189,   226,   189,
     605,   571,   193,   231,   193,   190,    72,   193,   605,   404,
     580,   655,   193,   657,   418,   122,   123,   661,   193,   193,
     664,   192,   666,    89,   189,   192,   185,   607,   631,   632,
     633,   185,     3,   189,   185,   181,   108,   607,   607,   189,
       3,   193,   437,   447,   272,   273,   441,   451,   154,   277,
     193,     3,   181,   119,   120,   181,   181,   461,    39,    40,
      41,   456,   193,   169,   171,   469,   193,    39,    49,   473,
     193,   193,   192,    54,   181,   303,   192,   184,   185,   193,
     185,   193,   189,   193,    39,   192,    39,   106,   316,   192,
     192,    72,     3,     4,     5,     6,     7,     8,    39,    10,
      11,   189,    13,    14,    39,    40,    41,    19,    89,   169,
     248,   374,   484,   371,    49,   488,   497,   345,   202,    54,
     205,   349,   517,   104,    35,   191,   354,   204,    39,    40,
      41,   206,   607,   207,   161,    28,    47,    72,    86,   245,
     246,   296,   248,    54,   540,   290,   454,    38,    39,    40,
      41,   522,   556,    -1,    89,   261,   408,    -1,    49,    -1,
      -1,    72,   268,    54,    -1,    76,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    72,    -1,    74,   119,   120,   414,    -1,    -1,    -1,
     418,    -1,    -1,   421,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,   607,    -1,   116,   117,    39,    40,    41,
     605,   122,   123,   124,   125,    -1,    -1,    49,    38,    39,
      40,    41,    54,    -1,   115,    -1,   454,   118,    -1,    49,
     458,    -1,    -1,   461,    54,    -1,   464,    57,    58,    -1,
      72,   469,    -1,    -1,    -1,   473,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    74,    -1,   191,    89,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,   372,    -1,   374,    89,
      -1,   182,   183,    -1,   185,    -1,     3,     4,     5,     6,
       7,     8,   193,    10,    11,    -1,    13,    14,    -1,    39,
      40,    41,    -1,   521,    -1,   115,    -1,    -1,   118,    49,
      -1,   192,   408,    -1,    54,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    72,    39,    40,    41,    -1,    54,   556,    -1,
      -1,   559,    -1,    49,    -1,    -1,    -1,    -1,    54,    89,
      -1,    38,    39,    40,    41,    72,    -1,    -1,    -1,    76,
      -1,   171,    49,    -1,   104,    -1,    72,    54,    -1,    -1,
      57,    58,    89,    -1,   184,   185,    -1,   595,    -1,    -1,
      -1,    -1,   192,    89,    -1,    72,    -1,    74,   606,    -1,
      -1,   609,   610,    -1,    39,    40,    41,    -1,    -1,   116,
     117,    -1,    89,    -1,    49,   122,   123,   124,   125,    54,
      -1,   507,    -1,     3,     4,     5,     6,     7,     8,   637,
      10,    11,    -1,    13,    14,    -1,    -1,    72,   115,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    35,    -1,    -1,    -1,    39,
      40,    41,   169,   170,   171,    -1,    -1,    47,   175,    -1,
      -1,    -1,    -1,    -1,    54,   182,   183,    -1,   185,    -1,
      -1,    -1,    -1,    -1,   119,   120,   193,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,    76,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    13,    14,    89,
      -1,    -1,    -1,    -1,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,    -1,    39,    40,    41,   116,   117,    -1,    -1,
      -1,    47,   122,   123,   124,   125,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    72,    -1,    -1,    49,
      76,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,   169,
     170,   171,    72,    -1,    74,   175,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,    -1,   185,    -1,    -1,    -1,    89,
     116,   117,    -1,   193,    -1,    -1,   122,   123,   124,   125,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    14,    -1,   115,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,
      41,    -1,    -1,   169,   170,   171,    47,    -1,    -1,   175,
      -1,    -1,    -1,    54,    -1,    -1,   182,   183,    -1,   185,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    76,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    13,    14,    89,    -1,
      -1,    -1,   192,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    39,    40,    41,   116,   117,    -1,    -1,    -1,
      47,   122,   123,   124,   125,    -1,    -1,    54,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    47,    49,    -1,
      -1,    -1,    -1,    54,    54,    72,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    89,    -1,    -1,    -1,    76,    -1,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    89,    -1,
      -1,   182,   183,    -1,   185,    -1,    -1,    -1,    -1,   116,
     117,    -1,   193,    -1,    -1,   122,   123,   124,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,   119,   120,
      -1,    -1,   122,   123,   124,   125,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    14,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,   169,   170,   171,    49,    -1,    -1,   175,    -1,
      54,    -1,    -1,    57,    58,   182,   183,    -1,   185,   169,
     170,   171,    47,    -1,    -1,   175,   193,    -1,    72,    54,
      74,    -1,   182,   183,    -1,   185,    -1,    -1,    -1,    -1,
     191,    -1,   192,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    76,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,     3,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,   117,    -1,    -1,    -1,    47,   122,   123,   124,
     125,    -1,    -1,    54,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      54,    -1,    -1,    57,    58,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
      74,    -1,    -1,    -1,   169,   170,   171,    -1,   192,    -1,
     175,    -1,    -1,    -1,    -1,    89,     3,   182,   183,    -1,
     185,    -1,    -1,    -1,    -1,   116,   117,   192,    -1,    -1,
      -1,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
      -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    54,     3,    -1,
      57,    58,    -1,    -1,    -1,    -1,    -1,    -1,   169,   170,
     171,    -1,    -1,    -1,   175,    72,    -1,    74,    -1,    -1,
      -1,   182,   183,    -1,   185,    -1,    -1,   171,    -1,    -1,
      -1,   192,    89,    38,    39,    40,    41,     3,    -1,    -1,
     184,   185,    -1,   187,    49,   189,    -1,    -1,   192,    54,
      -1,    -1,    57,    58,    -1,    -1,    -1,    -1,   115,    -1,
      -1,   118,    -1,    -1,    -1,   122,   123,    72,    -1,    74,
      -1,    -1,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    89,    -1,    -1,    -1,    54,    -1,
      -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    74,     3,
     115,    -1,    -1,   118,   171,    -1,    -1,   122,   123,    -1,
      -1,    -1,    -1,    89,    -1,    -1,    -1,   184,   185,    -1,
     187,    -1,   189,    -1,    -1,   192,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    39,    40,    41,    -1,   115,
      -1,    -1,   118,    -1,    -1,    49,   122,   123,    -1,    -1,
      54,     3,    -1,    -1,    -1,    -1,   171,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    39,    40,    41,    72,   184,
     185,    -1,   187,    -1,   189,    49,    -1,   192,    -1,    -1,
      54,    -1,    -1,    57,    58,    89,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,   171,    -1,    49,    72,    -1,
      74,    -1,    54,    -1,    -1,    57,    58,    -1,   184,   185,
      -1,   187,    -1,   189,    -1,    89,   192,    -1,   122,   123,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,     3,    -1,
      -1,   115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,   118,   171,    -1,    -1,
     122,   123,    -1,    38,    39,    40,    41,   181,    -1,    -1,
     184,   185,    -1,    -1,    49,   189,    -1,    -1,   192,    54,
       3,    -1,    57,    58,    -1,    -1,    -1,   171,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    74,
     184,   185,    -1,   187,    -1,   189,    -1,    -1,   192,   171,
      -1,    -1,    -1,    -1,    89,    -1,    39,    40,    41,    -1,
      -1,    -1,   184,   185,    -1,   187,    49,   189,    -1,    -1,
     192,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     115,    -1,    -1,   118,    -1,    -1,    -1,   122,   123,    72,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    13,    14,   171,    -1,    -1,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
     185,    -1,   187,    -1,   189,    -1,    -1,   192,    -1,    38,
      39,    40,    41,    -1,    43,    -1,    -1,    -1,    47,    -1,
      49,    38,    39,    40,    41,    54,    -1,    -1,    57,    58,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    54,   171,    -1,
      57,    58,    -1,    72,    -1,    74,    -1,    76,   181,    -1,
      -1,   184,   185,    -1,    -1,    72,   189,    74,    -1,   192,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    -1,   103,   104,   105,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,   122,   123,   124,   125,    -1,   115,    -1,
      -1,   118,   119,   120,     3,     4,     5,     6,     7,     8,
     127,    10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,    -1,    10,    11,    -1,    13,    14,
     169,   170,   171,    -1,    -1,    -1,   175,    -1,    47,    -1,
      -1,    -1,    -1,   182,   183,    54,   185,    -1,    -1,    -1,
     189,   190,   191,    38,    39,    40,    41,    -1,    43,    -1,
      -1,    -1,    47,   190,    49,    -1,    -1,    76,    -1,    54,
      -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,    74,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    -1,    -1,   116,   117,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,    -1,   103,   104,
     105,    -1,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,   122,   123,   124,
     125,    -1,    -1,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,
     169,   170,   171,    -1,    -1,    -1,   175,    -1,    -1,    -1,
      -1,    -1,    -1,   182,   183,   184,   185,   186,    -1,    -1,
      -1,   190,   191,    -1,   169,   170,   171,    47,    -1,    -1,
     175,    -1,    -1,    -1,    54,    -1,    -1,   182,   183,    -1,
     185,    -1,    -1,    -1,   189,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    14,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,    47,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    47,    -1,    -1,    -1,    -1,    49,
      -1,    54,    -1,    -1,    54,    76,    -1,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
     170,   171,    72,    76,    74,   175,    -1,    -1,    -1,    -1,
      -1,    -1,   182,   183,   184,   185,   186,    -1,    -1,    89,
     190,   191,    -1,    -1,    -1,   116,   117,    -1,    -1,    -1,
      -1,   122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,   117,   115,    -1,    -1,   118,   122,
     123,   124,   125,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
      -1,   182,   183,   184,   185,   186,   169,   170,   171,   190,
      47,   171,   175,    -1,    -1,    -1,    -1,    54,    -1,   182,
     183,    -1,   185,    -1,   184,   185,    -1,   190,    -1,    -1,
      -1,    -1,   192,    38,    39,    40,    41,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    57,    58,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    13,    14,    -1,    72,    -1,    74,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,    -1,    -1,    89,   122,   123,   124,   125,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      49,    -1,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,
     115,    -1,    -1,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    74,    -1,    76,    -1,    -1,
      -1,    -1,   169,   170,   171,    -1,    -1,    -1,   175,    -1,
      89,    -1,    -1,    -1,    -1,   182,   183,    -1,   185,    -1,
      -1,    -1,    -1,   190,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    13,    14,   115,   116,   117,   118,
     119,   120,    -1,   122,   123,   124,   125,    -1,    -1,     3,
       4,     5,     6,     7,     8,   190,    10,    11,    -1,    13,
      14,    -1,    -1,    -1,    43,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   170,   171,    47,    -1,    -1,   175,    76,    -1,    -1,
      54,    -1,    -1,   182,   183,    -1,   185,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,   103,   104,   105,    -1,   107,   108,
     109,   110,   111,   112,   113,   114,    -1,   116,   117,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    13,
      14,    -1,   116,   117,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   170,   171,    47,    -1,    -1,   175,    -1,    -1,    -1,
      54,    -1,    -1,   182,   183,    -1,   185,    -1,    -1,    -1,
     189,    -1,    -1,    -1,    -1,   169,   170,   171,    -1,    -1,
      -1,   175,    76,    -1,    -1,    -1,    -1,    -1,   182,   183,
      -1,   185,    -1,    -1,    -1,   189,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,   117,    -1,    -1,    -1,    -1,   122,   123,
     124,   125,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    -1,    -1,    72,    -1,    54,    -1,    76,
      57,    58,    -1,    -1,    -1,   169,   170,   171,    -1,    -1,
      -1,   175,    89,    -1,    -1,    72,    -1,    74,   182,   183,
      -1,   185,    -1,    -1,    -1,   189,     3,     4,     5,     6,
       7,     8,    89,    10,    11,    -1,    13,    14,    -1,   116,
     117,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      49,   118,    39,    40,    41,    54,    -1,    -1,    57,    58,
      47,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,    72,    -1,    74,    -1,    -1,    -1,    -1,
      -1,    -1,   169,   170,   171,    72,    -1,    -1,   175,    76,
      89,    -1,    -1,    -1,    -1,   182,   183,    -1,   185,    -1,
      -1,    -1,    89,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    -1,    13,    14,    -1,   115,    -1,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,    -1,    -1,    -1,   122,   123,   124,   125,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    72,    -1,    54,    -1,    76,    57,    58,    -1,
      -1,    -1,   169,   170,   171,    -1,    -1,    -1,   175,    89,
      -1,    -1,    72,    -1,    74,   182,   183,    -1,   185,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    89,
      10,    11,    -1,    13,    14,    -1,   116,   117,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,   115,    -1,    49,   118,    39,
      40,    41,    54,    -1,    -1,    57,    58,    47,    -1,    49,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,   169,
     170,   171,    72,    -1,    -1,   175,    76,    89,    -1,    -1,
      -1,    -1,   182,   183,    -1,   185,    -1,    -1,    -1,    89,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    -1,
      13,    14,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,    -1,
      -1,    -1,   122,   123,   124,   125,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    13,    14,    -1,    72,
      -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,   169,
     170,   171,    -1,    -1,    -1,   175,    89,    -1,    -1,    -1,
      -1,    -1,   182,   183,    -1,   185,    -1,    -1,    -1,    -1,
      47,    -1,    49,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      -1,    -1,    -1,   116,   117,    -1,    -1,    -1,    -1,   122,
     123,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    13,    14,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    13,    14,   169,   170,   171,   116,
     117,    -1,   175,    -1,    -1,   122,   123,   124,   125,   182,
     183,    47,   185,    49,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   169,   170,   171,    -1,    -1,    76,   175,    -1,
      -1,    -1,    -1,    -1,    -1,   182,   183,    -1,   185,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     116,   117,    -1,     0,    -1,    -1,   122,   123,   124,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,
      -1,    -1,    -1,   122,   123,   124,   125,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    13,
      14,    38,    39,    40,    41,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    49,   169,   170,   171,    -1,    54,    -1,   175,
      57,    58,    -1,    -1,    -1,    -1,   182,   183,    -1,   185,
     169,   170,   171,    47,    -1,    72,   175,    74,    -1,    -1,
      54,    -1,    -1,   182,   183,    -1,   185,    -1,    -1,    -1,
      -1,    -1,    89,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    76,    13,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,    -1,
      -1,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
     137,    -1,   116,   117,    54,    -1,    -1,    -1,   122,   123,
     124,   125,    -1,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   169,   170,   171,    -1,    -1,
      -1,   175,    -1,    -1,    -1,    -1,   116,   117,   182,   183,
      -1,   185,   122,   123,   124,   125,    -1,    -1,    -1,    -1,
      -1,    -1,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    38,    39,    40,    41,    -1,    43,    -1,    -1,   169,
     170,   171,    49,    -1,    -1,   175,   121,    54,    -1,    -1,
      57,    58,   182,   183,    -1,   185,    -1,    -1,    38,    39,
      40,    41,    -1,    43,    -1,    72,    -1,    74,    -1,    49,
      77,    -1,    -1,    -1,    54,    -1,    -1,    57,    58,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,   179,    -1,    -1,    -1,   115,    89,
      -1,   118,    -1,    38,    39,    40,    41,    -1,    43,    -1,
      -1,    -1,    -1,    -1,    49,    -1,    -1,   134,   135,    54,
      -1,    -1,    57,    58,    -1,   115,    -1,    -1,   118,    -1,
      38,    39,    40,    41,    -1,    43,    -1,    72,    -1,    74,
      -1,    49,    77,    -1,   134,   135,    54,    -1,     0,    57,
      58,    -1,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,
     115,    89,    -1,   118,    -1,    -1,    38,    39,    40,    41,
      -1,    43,    -1,    -1,    -1,    -1,    -1,    49,    -1,   134,
     135,   191,    54,    -1,    -1,    57,    58,   115,    -1,    -1,
     118,    -1,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      72,    -1,    74,    -1,    -1,    -1,   134,   135,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,
      -1,    -1,    -1,   115,    -1,    -1,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,
      -1,    -1,    -1,   191,    -1,   137,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    38,    39,    40,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,    54,    -1,   121,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    74,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   115,    -1,    -1,   118
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    38,    39,    40,    41,    43,    49,    54,    57,    58,
      72,    74,    89,   115,   118,   119,   120,   137,   195,   196,
     197,   198,   200,   202,   228,   256,   257,   260,   261,   262,
     263,   264,   278,   279,   280,   283,   299,   185,   185,   185,
       8,    35,     0,   197,   171,   185,   258,   259,   260,   281,
     282,   285,     8,    33,    34,    35,    36,    37,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   121,   265,   267,   273,   277,   262,
     257,   257,   257,   257,   257,   263,   264,     3,     4,     5,
       6,     7,     8,    10,    11,    13,    14,    47,    76,   116,
     117,   122,   123,   124,   125,   169,   170,   171,   175,   182,
     183,   185,   214,   227,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     249,   250,   251,   255,   260,   264,   270,   278,   283,   284,
     291,   255,   283,   255,   190,     8,   278,   285,   286,   260,
     281,   187,   189,     3,   189,   214,   127,   199,   201,   256,
     257,   260,   184,   185,   284,   282,   185,     3,     8,   190,
     266,   190,   266,   257,   257,   126,   186,   248,   185,   244,
     185,   244,   244,   185,   185,     8,     3,   229,   230,   232,
     244,   291,    22,   180,    21,   174,   176,   175,    19,    20,
      17,    18,   177,   178,    15,    16,   169,   170,   171,   172,
     173,   243,    12,    13,    14,   184,   185,   186,   192,   270,
     283,   184,   185,   285,   292,   293,   270,   243,   264,   192,
     187,   192,   187,   192,    77,   134,   135,   203,   204,   205,
     209,   210,   211,   215,   218,   221,   222,   223,   225,   228,
     257,   190,   278,   285,   192,   259,   281,   229,   190,   303,
     303,   201,   179,    35,   171,   193,   230,   286,   192,   257,
     260,   287,   288,   289,   290,   291,     3,   274,   275,   276,
     190,   191,   268,   269,   270,   299,   190,     3,   124,   291,
     291,   291,   230,   187,   192,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   179,   231,   192,   234,   229,
     235,   236,   237,   238,   239,   239,   240,   240,   240,   240,
     241,   241,   242,   242,   243,   243,   243,     3,   214,   229,
     192,   230,   254,     3,   214,    35,   171,   193,   230,   286,
     192,   287,   292,   293,   184,   185,   270,     4,   189,     4,
     189,   125,   226,   257,   257,   191,   205,     3,   212,   213,
     224,   285,   135,   206,   207,   208,   209,   210,   211,   215,
     218,   221,   223,   225,   228,   260,   189,     3,   103,   104,
     105,   107,   108,   109,   110,   111,   112,   113,   114,   189,
     191,   228,   229,   256,   283,   300,   301,   302,   304,   305,
     306,   307,   308,   309,   190,   230,   294,   230,   286,   193,
     193,    35,   171,   193,   230,   185,   281,   285,   292,     3,
     192,   187,   187,   192,   192,   187,   191,   179,   274,   191,
     269,   181,   260,   271,   272,   281,   191,   268,   192,   192,
     192,   187,   230,   230,   190,   243,   181,   193,   187,   192,
     230,   286,   193,   193,    35,   193,   230,   192,   192,    35,
     171,   193,   230,   286,   192,   287,   192,   192,   185,   189,
     303,     3,   216,   217,   285,     3,   219,   220,   285,   185,
     127,   260,   303,   189,   303,   124,   213,   257,   191,   208,
     181,   255,   181,   185,   185,   185,   300,   185,     3,   189,
     189,   189,   229,   189,   303,   191,   305,   184,   186,   294,
     295,   296,   297,   298,   193,   230,   230,   193,   193,   260,
      42,   289,   260,   191,   275,   255,   187,   191,   255,   189,
     187,   189,   260,   191,   104,   252,   253,   291,   295,   232,
     230,   193,   230,   230,   193,   230,   286,   193,   193,    35,
     193,   230,   192,   189,   189,   192,   185,   127,   189,   303,
     217,   185,   127,   189,   303,   220,   192,   287,   229,   189,
     185,   219,   300,   181,   300,   229,   229,   229,   108,   256,
     306,   189,   189,   255,     3,   187,   191,   294,   179,   298,
     193,   193,     3,   191,   272,   181,   181,   187,   192,   181,
     187,   191,   193,   193,   193,   230,   230,   193,   192,   229,
     289,   229,    39,   192,   189,   192,   287,   300,   192,   192,
     192,   185,   306,   306,   193,   191,   294,   296,   255,   230,
     253,   230,   191,   193,   193,    39,   189,   192,   189,    39,
     192,   300,   300,   300,   229,   192,   229,   192,   229,   294,
      39,   106,   192,   300,   192,   300,   192,   300,   189,   300,
     300
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   194,   195,   195,   196,   196,   197,   197,   197,   197,
     197,   198,   199,   198,   200,   201,   201,   202,   202,   203,
     203,   204,   204,   205,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   206,   206,   207,   207,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   209,   210,   211,   212,
     212,   213,   213,   213,   213,   214,   214,   215,   215,   216,
     216,   217,   217,   218,   218,   219,   219,   220,   220,   221,
     222,   223,   223,   224,   224,   225,   225,   226,   227,   227,
     228,   229,   229,   230,   230,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   232,   232,   233,   233,
     234,   234,   235,   235,   236,   236,   237,   237,   238,   238,
     238,   239,   239,   239,   239,   239,   240,   240,   240,   241,
     241,   241,   242,   242,   242,   242,   243,   243,   244,   244,
     244,   244,   244,   244,   244,   244,   245,   245,   245,   245,
     245,   245,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   248,   248,   249,
     249,   249,   250,   250,   251,   252,   252,   253,   253,   254,
     254,   255,   256,   256,   256,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   258,
     258,   259,   259,   260,   260,   261,   261,   262,   263,   263,
     263,   263,   263,   263,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     265,   265,   265,   265,   265,   266,   266,   267,   267,   268,
     268,   269,   269,   269,   270,   270,   270,   270,   270,   270,
     271,   271,   272,   272,   272,   273,   273,   273,   273,   273,
     274,   274,   275,   275,   276,   277,   278,   278,   278,   278,
     278,   279,   279,   279,   279,   279,   280,   280,   281,   281,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   283,   284,   285,   285,
     285,   285,   286,   286,   287,   287,   288,   288,   289,   289,
     289,   290,   290,   291,   291,   292,   292,   292,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   293,   293,   293,   293,   293,   293,   294,
     294,   294,   295,   295,   295,   295,   296,   297,   297,   298,
     298,   299,   299,   299,   299,   300,   301,   300,   300,   300,
     300,   300,   300,   302,   302,   302,   303,   303,   304,   304,
     305,   305,   306,   306,   307,   307,   307,   308,   308,   308,
     308,   308,   308,   309,   309,   309,   309,   309
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     4,     0,     4,     5,     1,     2,     5,     6,     0,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     3,     4,     2,
       1,     4,     3,     5,     4,     1,     1,     4,     4,     2,
       1,     3,     4,     4,     4,     2,     1,     4,     5,     6,
       6,     3,     3,     4,     5,     3,     3,     3,     2,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     4,     1,     2,
       2,     2,     2,     4,     4,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     3,     3,     3,
       2,     2,     6,     7,     1,     1,     1,     3,     1,     1,
       1,     2,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     6,     1,     3,     3,     3,     1,
       3,     1,     3,     3,     1,     2,     1,     3,     2,     3,
       2,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       3,     4,     2,     0,     1,     1,     2,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       3,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       2,     3,     3,     1,     2,     1,     3,     2,     2,     1,
       1,     3,     2,     4,     2,     4,     5,     5,     6,     2,
       1,     3,     3,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     2,     1,
       2,     2,     3,     3,     4,     6,     5,     5,     6,     5,
       4,     4,     4,     3,     4,     2,     1,     1,     3,     2,
       2,     1,     1,     2,     3,     1,     1,     3,     2,     2,
       1,     2,     4,     2,     1,     2,     1,     1,     3,     2,
       3,     5,     4,     5,     4,     3,     3,     3,     4,     6,
       5,     5,     6,     4,     4,     2,     3,     3,     4,     3,
       4,     1,     2,     1,     4,     3,     2,     1,     2,     3,
       2,     7,     5,     7,     5,     1,     0,     2,     1,     1,
       1,     1,     1,     3,     4,     3,     2,     3,     1,     2,
       1,     1,     1,     2,     7,     5,     5,     5,     7,     6,
       7,     6,     7,     3,     2,     2,     2,     3
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_uint8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   121,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    73,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   131,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   203,     0,   203,     0,   186,     0,   203,     0,   192,
       0,   203,     0,   194,     0,   203,     0,   196,     0,   203,
       0,   198,     0,   203,     0,   203,     0,   203,     0,   203,
       0,   188,     0,   203,     0,   190,     0,   203,     0,   203,
       0,   203,     0,   255,     0,   203,     0,   259,     0,   203,
       0,   203,     0,   203,     0,   203,     0,   203,     0,   203,
       0,   203,     0,   203,     0,   203,     0,   203,     0,   203,
       0,   203,     0,   203,     0,   203,     0,   257,     0,   203,
       0,   203,     0,   203,     0,   203,     0,   203,     0,   203,
       0,   203,     0,   203,     0,   203,     0,   203,     0,   203,
       0,   203,     0,   203,     0,   203,     0,   203,     0,   203,
       0,   203,     0,   203,     0,   203,     0,   203,     0,   203,
       0,   203,     0,   203,     0,   203,     0,   203,     0,   203,
       0,   203,     0,   203,     0,   385,     0
};

/* Error token number */
#define YYTERROR 1


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)


YYSTYPE yylval;
YYLTYPE yylloc;

int yynerrs;
int yychar;

static const int YYEOF = 0;
static const int YYEMPTY = -2;

typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif



/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Type, Value, Location);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

struct yyGLRStack;
static void yypstack (struct yyGLRStack* yystackp, ptrdiff_t yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (struct yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)

#endif /* !YYDEBUG */

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif


#if YYERROR_VERBOSE

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static ptrdiff_t
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      ptrdiff_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return YY_CAST (ptrdiff_t, strlen (yystr));
}
# endif

#endif /* !YYERROR_VERBOSE */

/** State numbers. */
typedef int yyStateNum;

/** Rule numbers. */
typedef int yyRuleNum;

/** Grammar symbol. */
typedef int yySymbol;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState {
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yysval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yyStateNum yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  ptrdiff_t yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yysval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet {
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  ptrdiff_t yysize;
  ptrdiff_t yycapacity;
};

struct yySemanticOption {
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  ptrdiff_t yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

#if YYDEBUG || YYERROR_VERBOSE
/** A printable representation of TOKEN.  */
static inline const char*
yytokenName (yySymbol yytoken)
{
  return yytoken == YYEMPTY ? "" : yytname[yytoken];
}
#endif

/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
      else
        /* The effect of using yysval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yySymbol
yygetToken (int *yycharp)
{
  yySymbol yytoken;
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token: "));
      *yycharp = yylex ();
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = yytoken = YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp,
              YYSTYPE* yyvalp, YYLTYPE *yylocp)
{
  yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow;
  YYUSE (yyvalp);
  YYUSE (yylocp);
  YYUSE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  yylow = 1;
  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yysval;
  /* Default location. */
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;

  switch (yyn)
    {
  case 2:
#line 647 "parser.y"
        { ast_root = ((*yyvalp).node) = NULL; }
#line 2930 "parser.tab.c"
    break;

  case 3:
#line 649 "parser.y"
        { ast_root = ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2936 "parser.tab.c"
    break;

  case 4:
#line 654 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2942 "parser.tab.c"
    break;

  case 5:
#line 656 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 2948 "parser.tab.c"
    break;

  case 6:
#line 661 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2954 "parser.tab.c"
    break;

  case 7:
#line 663 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2960 "parser.tab.c"
    break;

  case 8:
#line 665 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2966 "parser.tab.c"
    break;

  case 9:
#line 668 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2972 "parser.tab.c"
    break;

  case 10:
#line 676 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2978 "parser.tab.c"
    break;

  case 11:
#line 681 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2984 "parser.tab.c"
    break;

  case 12:
#line 683 "parser.y"
        { symbol_table_push_scope(); }
#line 2990 "parser.tab.c"
    break;

  case 13:
#line 685 "parser.y"
        { symbol_table_pop_scope(); ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2996 "parser.tab.c"
    break;

  case 14:
#line 705 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3002 "parser.tab.c"
    break;

  case 15:
#line 710 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3008 "parser.tab.c"
    break;

  case 16:
#line 712 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3014 "parser.tab.c"
    break;

  case 17:
#line 724 "parser.y"
        { ((*yyvalp).node) = create_impl_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3020 "parser.tab.c"
    break;

  case 18:
#line 726 "parser.y"
        { ((*yyvalp).node) = create_static_impl_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3026 "parser.tab.c"
    break;

  case 19:
#line 734 "parser.y"
                 { ((*yyvalp).node) = NULL; }
#line 3032 "parser.tab.c"
    break;

  case 20:
#line 735 "parser.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3038 "parser.tab.c"
    break;

  case 21:
#line 740 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3044 "parser.tab.c"
    break;

  case 22:
#line 742 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3050 "parser.tab.c"
    break;

  case 23:
#line 747 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3056 "parser.tab.c"
    break;

  case 24:
#line 749 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3062 "parser.tab.c"
    break;

  case 25:
#line 751 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3068 "parser.tab.c"
    break;

  case 26:
#line 753 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3074 "parser.tab.c"
    break;

  case 27:
#line 755 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3080 "parser.tab.c"
    break;

  case 28:
#line 757 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3086 "parser.tab.c"
    break;

  case 29:
#line 759 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3092 "parser.tab.c"
    break;

  case 30:
#line 761 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3098 "parser.tab.c"
    break;

  case 31:
#line 763 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3104 "parser.tab.c"
    break;

  case 32:
#line 765 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3110 "parser.tab.c"
    break;

  case 33:
#line 770 "parser.y"
                 { ((*yyvalp).node) = NULL; }
#line 3116 "parser.tab.c"
    break;

  case 34:
#line 771 "parser.y"
                                   { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3122 "parser.tab.c"
    break;

  case 35:
#line 776 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3128 "parser.tab.c"
    break;

  case 36:
#line 778 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3134 "parser.tab.c"
    break;

  case 37:
#line 783 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3140 "parser.tab.c"
    break;

  case 38:
#line 785 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3146 "parser.tab.c"
    break;

  case 39:
#line 787 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3152 "parser.tab.c"
    break;

  case 40:
#line 789 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3158 "parser.tab.c"
    break;

  case 41:
#line 791 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3164 "parser.tab.c"
    break;

  case 42:
#line 793 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3170 "parser.tab.c"
    break;

  case 43:
#line 795 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3176 "parser.tab.c"
    break;

  case 44:
#line 797 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3182 "parser.tab.c"
    break;

  case 45:
#line 799 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3188 "parser.tab.c"
    break;

  case 46:
#line 806 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3194 "parser.tab.c"
    break;

  case 47:
#line 829 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3200 "parser.tab.c"
    break;

  case 48:
#line 834 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL, NULL); }
#line 3206 "parser.tab.c"
    break;

  case 49:
#line 839 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3212 "parser.tab.c"
    break;

  case 50:
#line 841 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3218 "parser.tab.c"
    break;

  case 51:
#line 846 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3224 "parser.tab.c"
    break;

  case 52:
#line 848 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 3230 "parser.tab.c"
    break;

  case 53:
#line 856 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (void *) & const_node); }
#line 3236 "parser.tab.c"
    break;

  case 54:
#line 858 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (void *) & const_node); }
#line 3242 "parser.tab.c"
    break;

  case 55:
#line 877 "parser.y"
               { ((*yyvalp).node) = (void *) & this_node; }
#line 3248 "parser.tab.c"
    break;

  case 56:
#line 878 "parser.y"
               { ((*yyvalp).node) = (void *) & self_node; }
#line 3254 "parser.tab.c"
    break;

  case 57:
#line 883 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3260 "parser.tab.c"
    break;

  case 58:
#line 891 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3266 "parser.tab.c"
    break;

  case 59:
#line 900 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3272 "parser.tab.c"
    break;

  case 60:
#line 902 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3278 "parser.tab.c"
    break;

  case 61:
#line 907 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 3284 "parser.tab.c"
    break;

  case 62:
#line 909 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (void *) & const_node); }
#line 3290 "parser.tab.c"
    break;

  case 63:
#line 914 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3296 "parser.tab.c"
    break;

  case 64:
#line 922 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3302 "parser.tab.c"
    break;

  case 65:
#line 931 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3308 "parser.tab.c"
    break;

  case 66:
#line 933 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3314 "parser.tab.c"
    break;

  case 67:
#line 938 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3320 "parser.tab.c"
    break;

  case 68:
#line 940 "parser.y"
        { ((*yyvalp).node) = (void *) & error_node; fprintf(stderr, "'setter' functions cannot be 'const'!\n"); exit(EXIT_FAILURE); }
#line 3326 "parser.tab.c"
    break;

  case 69:
#line 945 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3332 "parser.tab.c"
    break;

  case 70:
#line 954 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3338 "parser.tab.c"
    break;

  case 71:
#line 987 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3344 "parser.tab.c"
    break;

  case 72:
#line 989 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3350 "parser.tab.c"
    break;

  case 73:
#line 995 "parser.y"
        { ((*yyvalp).node) = create_new_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 3356 "parser.tab.c"
    break;

  case 74:
#line 997 "parser.y"
        { ((*yyvalp).node) = create_new_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3362 "parser.tab.c"
    break;

  case 75:
#line 1003 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((void *) & void_node, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3368 "parser.tab.c"
    break;

  case 76:
#line 1005 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((void *) & void_node, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3374 "parser.tab.c"
    break;

  case 77:
#line 1010 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node(NULL, NULL, NULL); }
#line 3380 "parser.tab.c"
    break;

  case 78:
#line 1078 "parser.y"
        { ((*yyvalp).node) = create_function_call_node(create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), (void *) & delete_as_id_node), NULL); }
#line 3386 "parser.tab.c"
    break;

  case 79:
#line 1080 "parser.y"
        { ((*yyvalp).node) = (void *) & delete_as_id_node; }
#line 3392 "parser.tab.c"
    break;

  case 80:
#line 1102 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3398 "parser.tab.c"
    break;

  case 81:
#line 1118 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3404 "parser.tab.c"
    break;

  case 82:
#line 1120 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 3410 "parser.tab.c"
    break;

  case 83:
#line 1125 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3416 "parser.tab.c"
    break;

  case 84:
#line 1127 "parser.y"
        { ((*yyvalp).node) = create_binary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3422 "parser.tab.c"
    break;

  case 85:
#line 1131 "parser.y"
                     { ((*yyvalp).type) = AST_ASSIGN; }
#line 3428 "parser.tab.c"
    break;

  case 86:
#line 1132 "parser.y"
                     { ((*yyvalp).type) = AST_MUL_ASSIGN; }
#line 3434 "parser.tab.c"
    break;

  case 87:
#line 1133 "parser.y"
                     { ((*yyvalp).type) = AST_DIV_ASSIGN; }
#line 3440 "parser.tab.c"
    break;

  case 88:
#line 1134 "parser.y"
                     { ((*yyvalp).type) = AST_MOD_ASSIGN; }
#line 3446 "parser.tab.c"
    break;

  case 89:
#line 1135 "parser.y"
                     { ((*yyvalp).type) = AST_ADD_ASSIGN; }
#line 3452 "parser.tab.c"
    break;

  case 90:
#line 1136 "parser.y"
                     { ((*yyvalp).type) = AST_SUB_ASSIGN; }
#line 3458 "parser.tab.c"
    break;

  case 91:
#line 1137 "parser.y"
                     { ((*yyvalp).type) = AST_SHL_ASSIGN; }
#line 3464 "parser.tab.c"
    break;

  case 92:
#line 1138 "parser.y"
                     { ((*yyvalp).type) = AST_SHR_ASSIGN; }
#line 3470 "parser.tab.c"
    break;

  case 93:
#line 1139 "parser.y"
                     { ((*yyvalp).type) = AST_AND_ASSIGN; }
#line 3476 "parser.tab.c"
    break;

  case 94:
#line 1140 "parser.y"
                     { ((*yyvalp).type) = AST_XOR_ASSIGN; }
#line 3482 "parser.tab.c"
    break;

  case 95:
#line 1141 "parser.y"
                     { ((*yyvalp).type) = AST_OR_ASSIGN; }
#line 3488 "parser.tab.c"
    break;

  case 96:
#line 1147 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3494 "parser.tab.c"
    break;

  case 97:
#line 1149 "parser.y"
        { ((*yyvalp).node) = create_ternary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3500 "parser.tab.c"
    break;

  case 98:
#line 1154 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3506 "parser.tab.c"
    break;

  case 99:
#line 1156 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_OR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3512 "parser.tab.c"
    break;

  case 100:
#line 1161 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3518 "parser.tab.c"
    break;

  case 101:
#line 1163 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_AND, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3524 "parser.tab.c"
    break;

  case 102:
#line 1168 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3530 "parser.tab.c"
    break;

  case 103:
#line 1170 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_OR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3536 "parser.tab.c"
    break;

  case 104:
#line 1175 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3542 "parser.tab.c"
    break;

  case 105:
#line 1177 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_XOR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3548 "parser.tab.c"
    break;

  case 106:
#line 1182 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3554 "parser.tab.c"
    break;

  case 107:
#line 1184 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_AND, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3560 "parser.tab.c"
    break;

  case 108:
#line 1189 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3566 "parser.tab.c"
    break;

  case 109:
#line 1191 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_EQ, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3572 "parser.tab.c"
    break;

  case 110:
#line 1193 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3578 "parser.tab.c"
    break;

  case 111:
#line 1198 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3584 "parser.tab.c"
    break;

  case 112:
#line 1200 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_LT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3590 "parser.tab.c"
    break;

  case 113:
#line 1202 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_GT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3596 "parser.tab.c"
    break;

  case 114:
#line 1204 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_LE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3602 "parser.tab.c"
    break;

  case 115:
#line 1206 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_GE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3608 "parser.tab.c"
    break;

  case 116:
#line 1211 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3614 "parser.tab.c"
    break;

  case 117:
#line 1213 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SHL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3620 "parser.tab.c"
    break;

  case 118:
#line 1215 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SHR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3626 "parser.tab.c"
    break;

  case 119:
#line 1220 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3632 "parser.tab.c"
    break;

  case 120:
#line 1222 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ADD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3638 "parser.tab.c"
    break;

  case 121:
#line 1224 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SUB, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3644 "parser.tab.c"
    break;

  case 122:
#line 1229 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3650 "parser.tab.c"
    break;

  case 123:
#line 1231 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_MUL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3656 "parser.tab.c"
    break;

  case 124:
#line 1233 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_DIV, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3662 "parser.tab.c"
    break;

  case 125:
#line 1235 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_MOD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3668 "parser.tab.c"
    break;

  case 126:
#line 1249 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3674 "parser.tab.c"
    break;

  case 127:
#line 1253 "parser.y"
        { ((*yyvalp).node) = create_cast_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3680 "parser.tab.c"
    break;

  case 128:
#line 1258 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3686 "parser.tab.c"
    break;

  case 129:
#line 1260 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_PRE_INC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3692 "parser.tab.c"
    break;

  case 130:
#line 1262 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_PRE_DEC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3698 "parser.tab.c"
    break;

  case 131:
#line 1264 "parser.y"
        { ((*yyvalp).node) = create_unary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3704 "parser.tab.c"
    break;

  case 132:
#line 1266 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_SIZEOF_EXPR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3710 "parser.tab.c"
    break;

  case 133:
#line 1268 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_SIZEOF_TYPE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3716 "parser.tab.c"
    break;

  case 134:
#line 1270 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_ALIGNOF, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3722 "parser.tab.c"
    break;

  case 135:
#line 1277 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3728 "parser.tab.c"
    break;

  case 136:
#line 1281 "parser.y"
              { ((*yyvalp).type) = AST_ADDRESS_OF; }
#line 3734 "parser.tab.c"
    break;

  case 137:
#line 1282 "parser.y"
              { ((*yyvalp).type) = AST_DEREFERENCE; }
#line 3740 "parser.tab.c"
    break;

  case 138:
#line 1283 "parser.y"
              { ((*yyvalp).type) = AST_POSITIVE; }
#line 3746 "parser.tab.c"
    break;

  case 139:
#line 1284 "parser.y"
              { ((*yyvalp).type) = AST_NEGATIVE; }
#line 3752 "parser.tab.c"
    break;

  case 140:
#line 1285 "parser.y"
              { ((*yyvalp).type) = AST_BITWISE_NOT; }
#line 3758 "parser.tab.c"
    break;

  case 141:
#line 1286 "parser.y"
              { ((*yyvalp).type) = AST_LOGICAL_NOT; }
#line 3764 "parser.tab.c"
    break;

  case 142:
#line 1291 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3770 "parser.tab.c"
    break;

  case 143:
#line 1293 "parser.y"
        { ((*yyvalp).node) = create_array_subscript_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3776 "parser.tab.c"
    break;

  case 144:
#line 1295 "parser.y"
        { ((*yyvalp).node) = create_function_call_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 3782 "parser.tab.c"
    break;

  case 145:
#line 1297 "parser.y"
        { ((*yyvalp).node) = create_function_call_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3788 "parser.tab.c"
    break;

  case 146:
#line 1307 "parser.y"
        { ((*yyvalp).node) = create_member_access_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_THIS || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_SELF ? AST_MEMBER_ACCESS_POINTER : AST_MEMBER_ACCESS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3794 "parser.tab.c"
    break;

  case 147:
#line 1311 "parser.y"
        { ((*yyvalp).node) = create_member_access_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_THIS || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_SELF ? AST_MEMBER_ACCESS_POINTER : AST_MEMBER_ACCESS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3800 "parser.tab.c"
    break;

  case 148:
#line 1313 "parser.y"
        { ((*yyvalp).node) = create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3806 "parser.tab.c"
    break;

  case 149:
#line 1322 "parser.y"
        { ((*yyvalp).node) = create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3812 "parser.tab.c"
    break;

  case 150:
#line 1324 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_POST_INC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3818 "parser.tab.c"
    break;

  case 151:
#line 1326 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_POST_DEC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3824 "parser.tab.c"
    break;

  case 152:
#line 1329 "parser.y"
        { ((*yyvalp).node) = create_compound_literal_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3830 "parser.tab.c"
    break;

  case 153:
#line 1331 "parser.y"
        { ((*yyvalp).node) = create_compound_literal_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 3836 "parser.tab.c"
    break;

  case 154:
#line 1336 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3842 "parser.tab.c"
    break;

  case 155:
#line 1338 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3848 "parser.tab.c"
    break;

  case 156:
#line 1340 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3854 "parser.tab.c"
    break;

  case 157:
#line 1342 "parser.y"
        { ((*yyvalp).node) = create_expression_group_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3860 "parser.tab.c"
    break;

  case 158:
#line 1344 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3866 "parser.tab.c"
    break;

  case 159:
#line 1352 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3872 "parser.tab.c"
    break;

  case 160:
#line 1361 "parser.y"
        { ((*yyvalp).node) = (void *) & in_as_id_node; }
#line 3878 "parser.tab.c"
    break;

  case 161:
#line 1371 "parser.y"
        {
		sprintf(func_name, "%s__new", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id);
		((*yyvalp).node) = create_id_node(func_name);
	}
#line 3887 "parser.tab.c"
    break;

  case 162:
#line 1376 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NS_OP, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (void *) & new_as_id_node); }
#line 3893 "parser.tab.c"
    break;

  case 163:
#line 1378 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NS_OP, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3899 "parser.tab.c"
    break;

  case 164:
#line 1388 "parser.y"
        { ((*yyvalp).node) = (void *) & new_as_id_node; }
#line 3905 "parser.tab.c"
    break;

  case 165:
#line 1392 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3911 "parser.tab.c"
    break;

  case 166:
#line 1396 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3917 "parser.tab.c"
    break;

  case 169:
#line 1407 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3923 "parser.tab.c"
    break;

  case 170:
#line 1409 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3929 "parser.tab.c"
    break;

  case 171:
#line 1411 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3935 "parser.tab.c"
    break;

  case 172:
#line 1421 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3941 "parser.tab.c"
    break;

  case 173:
#line 1423 "parser.y"
        { ((*yyvalp).node) = (void *) & ___func__node; }
#line 3947 "parser.tab.c"
    break;

  case 174:
#line 1428 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 3953 "parser.tab.c"
    break;

  case 179:
#line 1443 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3959 "parser.tab.c"
    break;

  case 180:
#line 1445 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 3965 "parser.tab.c"
    break;

  case 181:
#line 1471 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3971 "parser.tab.c"
    break;

  case 182:
#line 1476 "parser.y"
        { ((*yyvalp).node) = create_declaration_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL); }
#line 3977 "parser.tab.c"
    break;

  case 183:
#line 1478 "parser.y"
        { ((*yyvalp).node) = create_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); register_typedef((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3983 "parser.tab.c"
    break;

  case 184:
#line 1491 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3989 "parser.tab.c"
    break;

  case 185:
#line 1497 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3995 "parser.tab.c"
    break;

  case 186:
#line 1499 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4001 "parser.tab.c"
    break;

  case 187:
#line 1501 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 4007 "parser.tab.c"
    break;

  case 188:
#line 1503 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4013 "parser.tab.c"
    break;

  case 189:
#line 1506 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 4019 "parser.tab.c"
    break;

  case 190:
#line 1508 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4025 "parser.tab.c"
    break;

  case 191:
#line 1511 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4031 "parser.tab.c"
    break;

  case 192:
#line 1513 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4037 "parser.tab.c"
    break;

  case 193:
#line 1516 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4043 "parser.tab.c"
    break;

  case 194:
#line 1518 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4049 "parser.tab.c"
    break;

  case 195:
#line 1521 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4055 "parser.tab.c"
    break;

  case 196:
#line 1523 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4061 "parser.tab.c"
    break;

  case 197:
#line 1526 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4067 "parser.tab.c"
    break;

  case 198:
#line 1528 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4073 "parser.tab.c"
    break;

  case 199:
#line 1533 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4079 "parser.tab.c"
    break;

  case 200:
#line 1535 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4085 "parser.tab.c"
    break;

  case 201:
#line 1540 "parser.y"
        { ((*yyvalp).node) = create_init_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4091 "parser.tab.c"
    break;

  case 202:
#line 1542 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4097 "parser.tab.c"
    break;

  case 203:
#line 1560 "parser.y"
                     { ((*yyvalp).node) = NULL; }
#line 4103 "parser.tab.c"
    break;

  case 204:
#line 1561 "parser.y"
                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4109 "parser.tab.c"
    break;

  case 205:
#line 1566 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4115 "parser.tab.c"
    break;

  case 206:
#line 1568 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4121 "parser.tab.c"
    break;

  case 207:
#line 1573 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4127 "parser.tab.c"
    break;

  case 208:
#line 1589 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & typedef_node); }
#line 4133 "parser.tab.c"
    break;

  case 209:
#line 1597 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & extern_node); }
#line 4139 "parser.tab.c"
    break;

  case 210:
#line 1601 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & static_node); }
#line 4145 "parser.tab.c"
    break;

  case 211:
#line 1603 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & thread_local_node); }
#line 4151 "parser.tab.c"
    break;

  case 212:
#line 1605 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & auto_node); }
#line 4157 "parser.tab.c"
    break;

  case 213:
#line 1607 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & register_node); }
#line 4163 "parser.tab.c"
    break;

  case 214:
#line 1618 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & void_node); }
#line 4169 "parser.tab.c"
    break;

  case 215:
#line 1620 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & char_node); }
#line 4175 "parser.tab.c"
    break;

  case 216:
#line 1622 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & short_node); }
#line 4181 "parser.tab.c"
    break;

  case 217:
#line 1624 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & int_node); }
#line 4187 "parser.tab.c"
    break;

  case 218:
#line 1626 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & long_node); }
#line 4193 "parser.tab.c"
    break;

  case 219:
#line 1628 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & float_node); }
#line 4199 "parser.tab.c"
    break;

  case 220:
#line 1630 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & double_node); }
#line 4205 "parser.tab.c"
    break;

  case 221:
#line 1632 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & signed_node); }
#line 4211 "parser.tab.c"
    break;

  case 222:
#line 1634 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & unsigned_node); }
#line 4217 "parser.tab.c"
    break;

  case 223:
#line 1636 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & bool_node); }
#line 4223 "parser.tab.c"
    break;

  case 224:
#line 1638 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & complex_node); }
#line 4229 "parser.tab.c"
    break;

  case 225:
#line 1640 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & imaginary_node); }
#line 4235 "parser.tab.c"
    break;

  case 226:
#line 1642 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4241 "parser.tab.c"
    break;

  case 227:
#line 1644 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4247 "parser.tab.c"
    break;

  case 228:
#line 1646 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4253 "parser.tab.c"
    break;

  case 229:
#line 1648 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4259 "parser.tab.c"
    break;

  case 230:
#line 1663 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & builtin_va_list_node); }
#line 4265 "parser.tab.c"
    break;

  case 231:
#line 1667 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___decimal32_node); }
#line 4271 "parser.tab.c"
    break;

  case 232:
#line 1669 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___decimal64_node); }
#line 4277 "parser.tab.c"
    break;

  case 233:
#line 1671 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___decimal128_node); }
#line 4283 "parser.tab.c"
    break;

  case 234:
#line 1674 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___float128_node); }
#line 4289 "parser.tab.c"
    break;

  case 235:
#line 1676 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___int128_node); }
#line 4295 "parser.tab.c"
    break;

  case 236:
#line 1678 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___int128_t_node); }
#line 4301 "parser.tab.c"
    break;

  case 237:
#line 1680 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___uint128_t_node); }
#line 4307 "parser.tab.c"
    break;

  case 238:
#line 1683 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___bitint128_node); }
#line 4313 "parser.tab.c"
    break;

  case 239:
#line 1685 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4319 "parser.tab.c"
    break;

  case 240:
#line 1690 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.type), NULL, NULL); }
#line 4325 "parser.tab.c"
    break;

  case 241:
#line 1692 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4331 "parser.tab.c"
    break;

  case 242:
#line 1699 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4337 "parser.tab.c"
    break;

  case 243:
#line 1701 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4343 "parser.tab.c"
    break;

  case 244:
#line 1704 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4349 "parser.tab.c"
    break;

  case 247:
#line 1715 "parser.y"
                 { ((*yyvalp).type) = AST_STRUCT; }
#line 4355 "parser.tab.c"
    break;

  case 248:
#line 1716 "parser.y"
                 { ((*yyvalp).type) = AST_UNION; }
#line 4361 "parser.tab.c"
    break;

  case 249:
#line 1721 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4367 "parser.tab.c"
    break;

  case 250:
#line 1723 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 4373 "parser.tab.c"
    break;

  case 251:
#line 1728 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declaration_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL); }
#line 4379 "parser.tab.c"
    break;

  case 252:
#line 1730 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4385 "parser.tab.c"
    break;

  case 253:
#line 1736 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4391 "parser.tab.c"
    break;

  case 254:
#line 1741 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4397 "parser.tab.c"
    break;

  case 255:
#line 1743 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4403 "parser.tab.c"
    break;

  case 256:
#line 1747 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 4409 "parser.tab.c"
    break;

  case 257:
#line 1749 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4415 "parser.tab.c"
    break;

  case 258:
#line 1754 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4421 "parser.tab.c"
    break;

  case 259:
#line 1756 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4427 "parser.tab.c"
    break;

  case 260:
#line 1761 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4433 "parser.tab.c"
    break;

  case 261:
#line 1763 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4439 "parser.tab.c"
    break;

  case 262:
#line 1768 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), NULL); }
#line 4445 "parser.tab.c"
    break;

  case 263:
#line 1771 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4451 "parser.tab.c"
    break;

  case 264:
#line 1774 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4457 "parser.tab.c"
    break;

  case 265:
#line 1779 "parser.y"
        { ((*yyvalp).node) = create_enum_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4463 "parser.tab.c"
    break;

  case 266:
#line 1782 "parser.y"
        { ((*yyvalp).node) = create_enum_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4469 "parser.tab.c"
    break;

  case 267:
#line 1785 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4475 "parser.tab.c"
    break;

  case 268:
#line 1788 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4481 "parser.tab.c"
    break;

  case 269:
#line 1791 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4487 "parser.tab.c"
    break;

  case 270:
#line 1796 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4493 "parser.tab.c"
    break;

  case 271:
#line 1798 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ",\n"); }
#line 4499 "parser.tab.c"
    break;

  case 272:
#line 1803 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ENUM_INIT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); symbol_add_enum_constant((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->id.id, ((*yyvalp).node)); }
#line 4505 "parser.tab.c"
    break;

  case 273:
#line 1806 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ENUM_INIT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); symbol_add_enum_constant((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id, ((*yyvalp).node)); }
#line 4511 "parser.tab.c"
    break;

  case 274:
#line 1810 "parser.y"
                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4517 "parser.tab.c"
    break;

  case 275:
#line 1816 "parser.y"
        { ((*yyvalp).node) = create_atomic_type_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4523 "parser.tab.c"
    break;

  case 276:
#line 1820 "parser.y"
                     { ((*yyvalp).node) = (void *) & const_node; }
#line 4529 "parser.tab.c"
    break;

  case 277:
#line 1821 "parser.y"
                     { ((*yyvalp).node) = (void *) & restrict_node; }
#line 4535 "parser.tab.c"
    break;

  case 278:
#line 1822 "parser.y"
                     { ((*yyvalp).node) = (void *) & ___restrict_node; }
#line 4541 "parser.tab.c"
    break;

  case 279:
#line 1823 "parser.y"
                     { ((*yyvalp).node) = (void *) & volatile_node; }
#line 4547 "parser.tab.c"
    break;

  case 280:
#line 1824 "parser.y"
                     { ((*yyvalp).node) = (void *) & atomic_node; }
#line 4553 "parser.tab.c"
    break;

  case 281:
#line 1828 "parser.y"
                        { ((*yyvalp).node) = (void *) & inline_node; }
#line 4559 "parser.tab.c"
    break;

  case 282:
#line 1829 "parser.y"
                        { ((*yyvalp).node) = (void *) & noreturn_node; }
#line 4565 "parser.tab.c"
    break;

  case 283:
#line 1831 "parser.y"
                        { ((*yyvalp).node) = (void *) & ___inline_node; }
#line 4571 "parser.tab.c"
    break;

  case 284:
#line 1832 "parser.y"
                        { ((*yyvalp).node) = (void *) & ___inline__node; }
#line 4577 "parser.tab.c"
    break;

  case 285:
#line 1834 "parser.y"
                        { ((*yyvalp).node) = (void *) & ___forceinline_node; }
#line 4583 "parser.tab.c"
    break;

  case 286:
#line 1839 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 4589 "parser.tab.c"
    break;

  case 287:
#line 1841 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 4595 "parser.tab.c"
    break;

  case 288:
#line 1846 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4601 "parser.tab.c"
    break;

  case 289:
#line 1848 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4607 "parser.tab.c"
    break;

  case 290:
#line 1854 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4613 "parser.tab.c"
    break;

  case 291:
#line 1857 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4619 "parser.tab.c"
    break;

  case 292:
#line 1860 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4625 "parser.tab.c"
    break;

  case 293:
#line 1862 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4631 "parser.tab.c"
    break;

  case 294:
#line 1864 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 4637 "parser.tab.c"
    break;

  case 295:
#line 1866 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4643 "parser.tab.c"
    break;

  case 296:
#line 1868 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4649 "parser.tab.c"
    break;

  case 297:
#line 1870 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4655 "parser.tab.c"
    break;

  case 298:
#line 1872 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4661 "parser.tab.c"
    break;

  case 299:
#line 1874 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4667 "parser.tab.c"
    break;

  case 300:
#line 1876 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4673 "parser.tab.c"
    break;

  case 301:
#line 1878 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4679 "parser.tab.c"
    break;

  case 302:
#line 1889 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 4685 "parser.tab.c"
    break;

  case 303:
#line 1891 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 4691 "parser.tab.c"
    break;

  case 304:
#line 1893 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4697 "parser.tab.c"
    break;

  case 305:
#line 1900 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4703 "parser.tab.c"
    break;

  case 306:
#line 1907 "parser.y"
                        { ((*yyvalp).node) = (void *) & ___extension___node; }
#line 4709 "parser.tab.c"
    break;

  case 307:
#line 1913 "parser.y"
                  { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4715 "parser.tab.c"
    break;

  case 308:
#line 1919 "parser.y"
        { ((*yyvalp).node) = create_pointer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4721 "parser.tab.c"
    break;

  case 309:
#line 1921 "parser.y"
        { ((*yyvalp).node) = create_pointer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4727 "parser.tab.c"
    break;

  case 310:
#line 1923 "parser.y"
        { ((*yyvalp).node) = create_pointer_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4733 "parser.tab.c"
    break;

  case 311:
#line 1925 "parser.y"
        { ((*yyvalp).node) = (void *) & pointer_node; }
#line 4739 "parser.tab.c"
    break;

  case 312:
#line 1930 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4745 "parser.tab.c"
    break;

  case 313:
#line 1932 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), " "); }
#line 4751 "parser.tab.c"
    break;

  case 314:
#line 1937 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (void *) & ellipsis_node, ", "); }
#line 4757 "parser.tab.c"
    break;

  case 315:
#line 1939 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4763 "parser.tab.c"
    break;

  case 316:
#line 1944 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4769 "parser.tab.c"
    break;

  case 317:
#line 1946 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4775 "parser.tab.c"
    break;

  case 318:
#line 1951 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4781 "parser.tab.c"
    break;

  case 319:
#line 1953 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4787 "parser.tab.c"
    break;

  case 320:
#line 1955 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4793 "parser.tab.c"
    break;

  case 321:
#line 1963 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4799 "parser.tab.c"
    break;

  case 322:
#line 1966 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), ", "); }
#line 4805 "parser.tab.c"
    break;

  case 323:
#line 1971 "parser.y"
        { ((*yyvalp).node) = create_abstract_type_name_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4811 "parser.tab.c"
    break;

  case 324:
#line 1973 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4817 "parser.tab.c"
    break;

  case 325:
#line 1978 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4823 "parser.tab.c"
    break;

  case 326:
#line 1980 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4829 "parser.tab.c"
    break;

  case 327:
#line 1982 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4835 "parser.tab.c"
    break;

  case 328:
#line 1988 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4841 "parser.tab.c"
    break;

  case 329:
#line 1990 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node(NULL, NULL); }
#line 4847 "parser.tab.c"
    break;

  case 330:
#line 1992 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node(NULL, NULL); }
#line 4853 "parser.tab.c"
    break;

  case 331:
#line 1994 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4859 "parser.tab.c"
    break;

  case 332:
#line 1996 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4865 "parser.tab.c"
    break;

  case 333:
#line 1998 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4871 "parser.tab.c"
    break;

  case 334:
#line 2000 "parser.y"
        { ((*yyvalp).node) = create_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4877 "parser.tab.c"
    break;

  case 335:
#line 2002 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4883 "parser.tab.c"
    break;

  case 336:
#line 2004 "parser.y"
        { ((*yyvalp).node) = create_array_node(NULL, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4889 "parser.tab.c"
    break;

  case 337:
#line 2006 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4895 "parser.tab.c"
    break;

  case 338:
#line 2008 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 4901 "parser.tab.c"
    break;

  case 339:
#line 2010 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4907 "parser.tab.c"
    break;

  case 340:
#line 2012 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4913 "parser.tab.c"
    break;

  case 341:
#line 2014 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4919 "parser.tab.c"
    break;

  case 342:
#line 2016 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4925 "parser.tab.c"
    break;

  case 343:
#line 2018 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4931 "parser.tab.c"
    break;

  case 344:
#line 2020 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4937 "parser.tab.c"
    break;

  case 345:
#line 2022 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node(NULL); }
#line 4943 "parser.tab.c"
    break;

  case 346:
#line 2024 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 4949 "parser.tab.c"
    break;

  case 347:
#line 2026 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 4955 "parser.tab.c"
    break;

  case 348:
#line 2028 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 4961 "parser.tab.c"
    break;

  case 349:
#line 2033 "parser.y"
        { ((*yyvalp).node) = create_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4967 "parser.tab.c"
    break;

  case 350:
#line 2035 "parser.y"
        { ((*yyvalp).node) = create_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4973 "parser.tab.c"
    break;

  case 351:
#line 2037 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4979 "parser.tab.c"
    break;

  case 352:
#line 2042 "parser.y"
        { ((*yyvalp).node) = create_designation_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4985 "parser.tab.c"
    break;

  case 353:
#line 2044 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4991 "parser.tab.c"
    break;

  case 354:
#line 2046 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_designation_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), ", "); }
#line 4997 "parser.tab.c"
    break;

  case 355:
#line 2048 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 5003 "parser.tab.c"
    break;

  case 356:
#line 2053 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 5009 "parser.tab.c"
    break;

  case 357:
#line 2058 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5015 "parser.tab.c"
    break;

  case 358:
#line 2060 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 5021 "parser.tab.c"
    break;

  case 359:
#line 2065 "parser.y"
        { ((*yyvalp).node) = create_designator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 5027 "parser.tab.c"
    break;

  case 360:
#line 2067 "parser.y"
        { ((*yyvalp).node) = create_designator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5033 "parser.tab.c"
    break;

  case 361:
#line 2083 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST__STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5039 "parser.tab.c"
    break;

  case 362:
#line 2085 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST__STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 5045 "parser.tab.c"
    break;

  case 363:
#line 2087 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST_STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5051 "parser.tab.c"
    break;

  case 364:
#line 2089 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST_STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 5057 "parser.tab.c"
    break;

  case 365:
#line 2093 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5063 "parser.tab.c"
    break;

  case 366:
#line 2095 "parser.y"
        { symbol_table_push_scope(); }
#line 5069 "parser.tab.c"
    break;

  case 367:
#line 2097 "parser.y"
        { symbol_table_pop_scope(); ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5075 "parser.tab.c"
    break;

  case 368:
#line 2098 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5081 "parser.tab.c"
    break;

  case 369:
#line 2099 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5087 "parser.tab.c"
    break;

  case 370:
#line 2100 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5093 "parser.tab.c"
    break;

  case 371:
#line 2101 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5099 "parser.tab.c"
    break;

  case 372:
#line 2103 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5105 "parser.tab.c"
    break;

  case 373:
#line 2108 "parser.y"
        { ((*yyvalp).node) = create_labeled_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5111 "parser.tab.c"
    break;

  case 374:
#line 2110 "parser.y"
        { ((*yyvalp).node) = create_case_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5117 "parser.tab.c"
    break;

  case 375:
#line 2112 "parser.y"
        { ((*yyvalp).node) = create_default_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5123 "parser.tab.c"
    break;

  case 376:
#line 2117 "parser.y"
        { ((*yyvalp).node) = create_block_node(NULL); }
#line 5129 "parser.tab.c"
    break;

  case 377:
#line 2121 "parser.y"
                {
			((*yyvalp).node) = create_block_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
		// symbol_table_pop_scope();
		}
#line 5138 "parser.tab.c"
    break;

  case 378:
#line 2130 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5144 "parser.tab.c"
    break;

  case 379:
#line 2132 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 5150 "parser.tab.c"
    break;

  case 380:
#line 2136 "parser.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5156 "parser.tab.c"
    break;

  case 381:
#line 2137 "parser.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5162 "parser.tab.c"
    break;

  case 382:
#line 2142 "parser.y"
        { ((*yyvalp).node) = create_expression_statement_node(NULL); }
#line 5168 "parser.tab.c"
    break;

  case 383:
#line 2144 "parser.y"
        { ((*yyvalp).node) = create_expression_statement_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5174 "parser.tab.c"
    break;

  case 384:
#line 2151 "parser.y"
        { ((*yyvalp).node) = create_if_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5180 "parser.tab.c"
    break;

  case 385:
#line 2153 "parser.y"
        { ((*yyvalp).node) = create_if_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 5186 "parser.tab.c"
    break;

  case 386:
#line 2155 "parser.y"
        { ((*yyvalp).node) = create_switch_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5192 "parser.tab.c"
    break;

  case 387:
#line 2160 "parser.y"
        { ((*yyvalp).node) = create_while_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5198 "parser.tab.c"
    break;

  case 388:
#line 2162 "parser.y"
        { ((*yyvalp).node) = create_do_while_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5204 "parser.tab.c"
    break;

  case 389:
#line 2164 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5210 "parser.tab.c"
    break;

  case 390:
#line 2166 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5216 "parser.tab.c"
    break;

  case 391:
#line 2168 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5222 "parser.tab.c"
    break;

  case 392:
#line 2170 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5228 "parser.tab.c"
    break;

  case 393:
#line 2174 "parser.y"
                                { ((*yyvalp).node) = create_goto_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5234 "parser.tab.c"
    break;

  case 394:
#line 2175 "parser.y"
                                { ((*yyvalp).node) = (void *) & continue_node; }
#line 5240 "parser.tab.c"
    break;

  case 395:
#line 2176 "parser.y"
                                { ((*yyvalp).node) = (void *) & break_node; }
#line 5246 "parser.tab.c"
    break;

  case 396:
#line 2177 "parser.y"
                                { ((*yyvalp).node) = (void *) & return_node; }
#line 5252 "parser.tab.c"
    break;

  case 397:
#line 2178 "parser.y"
                                { ((*yyvalp).node) = create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5258 "parser.tab.c"
    break;


#line 5262 "parser.tab.c"

      default: break;
    }

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YYUSE (yy0);
  YYUSE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yystos[yys->yylrState],
                &yys->yysemantics.yysval, &yys->yyloc);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yystos[yys->yylrState], YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh);
        }
    }
}

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yySymbol
yylhsNonterm (yyRuleNum yyrule)
{
  return yyr1[yyrule];
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yyStateNum yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yyStateNum yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yyStateNum yystate, yySymbol yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yyisDefaultedState (yystate)
      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yyStateNum
yyLRgotoState (yyStateNum yystate, yySymbol yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (size_t, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (size_t, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, ptrdiff_t yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (size_t, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  ptrdiff_t yynewSize;
  ptrdiff_t yyn;
  ptrdiff_t yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (size_t, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  ptrdiff_t yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
            ptrdiff_t yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yysval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, ptrdiff_t yyk, yyStateNum yylrState,
                 ptrdiff_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if !YYDEBUG
# define YY_REDUCE_PRINT(Args)
#else
# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, ptrdiff_t yyk,
                 yyRuleNum yyrule)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yystos[yyvsp[yyi - yynrhs + 1].yystate.yylrState],
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yysval,
                       &(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       );
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      YY_REDUCE_PRINT ((yytrue, yyrhs, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp,
                           yyvalp, yylocp);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      YY_REDUCE_PRINT ((yyfalse, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1, yyk, yyrule));
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, ptrdiff_t yyk, yyRuleNum yyrule,
             yybool yyforceEval)
{
  ptrdiff_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yysval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yysval, &yyloc);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1]));
      if (yyflag != yyok)
        return yyflag;
      YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yysval, &yyloc);
    }
  else
    {
      ptrdiff_t yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yyStateNum yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule - 1],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static ptrdiff_t
yysplitStack (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      ptrdiff_t state_size = sizeof yystackp->yytops.yystates[0];
      ptrdiff_t half_max_capacity = YYSIZEMAX / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (size_t, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG yyresolveValue (yyGLRState* yys,
                                   yyGLRStack* yystackp);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyvalp, yylocp);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yytokenName (yystos[yystates[yyi]->yylrState])));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yytokenName (yystos[yystates[yyi]->yylrState]),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1)
{
  YYUSE (yyx0);
  YYUSE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState *yys1, int yyn1,
                    yyGLRStack *yystackp)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YY_ASSERT (yyoption);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (0 < yynrhs)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yysval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp);
              return yyreportAmbiguity (yybest, yyp);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yysval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yysval_other, &yydummy);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yystos[yys->yylrState],
                                &yysval, yylocp);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yysval, yylocp);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yysval = yysval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             ));
    }
  return yyok;
}

static void
yycompressStack (yyGLRStack* yystackp)
{
  yyGLRState* yyp, *yyq, *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
       yyp != yystackp->yysplitPoint;
       yyr = yyp, yyp = yyq, yyq = yyp->yypred)
    yyp->yypred = yyr;

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
                   ptrdiff_t yyposn)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule]);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yySymbol yytoken = yygetToken (&yychar);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          while (*yyconflicts != 0)
            {
              YYRESULTTAG yyflag;
              ptrdiff_t yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts]);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
              yyconflicts += 1;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction]);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

static void
yyreportSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState != 0)
    return;
#if ! YYERROR_VERBOSE
  yyerror (YY_("syntax error"));
#else
  {
  yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  ptrdiff_t yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
      ptrdiff_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
      yysize = yysize0;
      yyarg[yycount++] = yytokenName (yytoken);
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for this
             state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;
          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytokenName (yyx);
                {
                  ptrdiff_t yysz = yytnamerr (YY_NULLPTR, yytokenName (yyx));
                  if (YYSIZEMAX - yysize < yysz)
                    yysize_overflow = yytrue;
                  else
                    yysize += yysz;
                }
              }
        }
    }

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    ptrdiff_t yysz = YY_CAST (ptrdiff_t, strlen (yyformat)) - 2 * yycount + 1;
    if (YYSIZEMAX - yysize < yysz)
      yysize_overflow = yytrue;
    else
      yysize += yysz;
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (size_t, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yyarg[yyi++]);
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
#endif /* YYERROR_VERBOSE */
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yySymbol yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    ptrdiff_t yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Now pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += YYTERROR;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yystos[yyaction],
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, YY_NULLPTR);
}

#define YYCHK1(YYE)                                                          \
  do {                                                                       \
    switch (YYE) {                                                           \
    case yyok:                                                               \
      break;                                                                 \
    case yyabort:                                                            \
      goto yyabortlab;                                                       \
    case yyaccept:                                                           \
      goto yyacceptlab;                                                      \
    case yyerr:                                                              \
      goto yyuser_error;                                                     \
    default:                                                                 \
      goto yybuglab;                                                         \
    }                                                                        \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  ptrdiff_t yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode */
      while (yytrue)
        {
          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
            }
          else
            {
              yySymbol yytoken = yygetToken (&yychar);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts != 0)
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;                  yyreportSyntaxError (&yystack);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue));
            }
        }

      while (yytrue)
        {
          yySymbol yytoken_to_shift;
          ptrdiff_t yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YY_DPRINTF ((stderr, "Stack %ld now in state #%d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturn;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturn;

 yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;

 yyreturn:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          ptrdiff_t yysize = yystack.yytops.yysize;
          ptrdiff_t yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

static void
yypstates (yyGLRState* yyst)
{
  if (yyst == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yyst);
  YY_FPRINTF ((stderr, "\n"));
}

static void
yypstack (yyGLRStack* yystackp, ptrdiff_t yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    ptrdiff_t yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc



#line 2181 "parser.y"

#include <stdio.h>

/* void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "ERROR: %s\n", s);
} */







void yyerror(const char *s)
{
	if (yyfilename == NULL || yyfilename[0] == '\0') {
		fprintf(stderr, "%s on line %d\n", s, yylineno);
	}

	fprintf(stderr, "%s:%d: %s\n", yyfilename, yylineno, s);

#	define MAX_LINE_LENGTH 1024
	static char line[MAX_LINE_LENGTH];

	FILE *fp = fopen(yyfilename, "r");
	if (fp == NULL) {
		fprintf(stderr, "Error opening file: %s\n", yyfilename);
		exit(EXIT_FAILURE);
	}

	int current_line = 0;
	while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
		current_line++;
		if (current_line >= yylineno - 1 && current_line <= yylineno + 1) {
			fprintf(stderr, "%c%5d | %s", current_line == yylineno ? '>' : ' ', current_line, line);
		}
	}
}

static inline union ast_node* maybe_attributes(union ast_node *left, union ast_node *right)
{
	if (left == NULL) return right;
	if (right == NULL) return left;
	return create_list_node(left, right, " ");
}



void register_typedef(union ast_node *decl_specs, union ast_node *declarator)
{
	//NOTE: Here, we need to check if the declaration is a `typedef` declaration.
	//	We first scan the declaration_specifiers to see if there is a `typedef` keyword, by checking for an AST_TYPEDEF node.
	//	Then we scan the init_declarator_list to see if there is a declarator with an identifier.

	//	Scan the declaration_specifiers
	union ast_node *node;

	if ( ! is_typedef_node(decl_specs))
		return;

	node = get_id_node(declarator);

	if (node) {
		symbol_add_typedef(node->id.id, node);
	} else {
		//	NOTE: This might be the case for a typedef that is defined more than once ???. Or a symbol that doesn't have a name??? Anonymous struct? But I think the typedef will be named!
		fprintf(stderr, "FATAL ERROR: typedef ID node is NULL\n");
		exit(EXIT_FAILURE);
	}
	return;
}
