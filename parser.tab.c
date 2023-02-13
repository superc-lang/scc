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

extern int error_count;
char func_name[512];


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
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  153
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  116
/* YYNRULES -- Number of rules.  */
#define YYNRULES  397
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  674
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 7
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token number (for yychar).  */
#define YYMAXUTOK   383
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
       2,     2,     2,   141,     2,     2,     2,   132,   134,     2,
     144,   151,   130,   128,   146,   129,   145,   131,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   140,   148,
     136,   138,   137,   139,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   143,     2,   152,   135,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   149,   133,   150,   142,     2,     2,     2,
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
     125,   126,   127,   147
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   595,   595,   597,   602,   604,   609,   611,   613,   616,
     624,   629,   632,   631,   653,   658,   660,   672,   674,   683,
     684,   688,   690,   695,   697,   699,   701,   703,   705,   707,
     709,   711,   713,   719,   720,   724,   726,   731,   733,   735,
     737,   739,   741,   743,   745,   747,   754,   777,   782,   787,
     789,   794,   796,   804,   806,   826,   827,   831,   839,   848,
     850,   855,   857,   862,   870,   879,   881,   886,   888,   893,
     902,   935,   937,   939,   948,   950,   956,   959,   962,   967,
    1035,  1037,  1059,  1075,  1077,  1082,  1084,  1089,  1090,  1091,
    1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,  1104,  1106,
    1111,  1113,  1118,  1120,  1125,  1127,  1132,  1134,  1139,  1141,
    1146,  1148,  1150,  1155,  1157,  1159,  1161,  1163,  1168,  1170,
    1172,  1177,  1179,  1181,  1186,  1188,  1190,  1192,  1206,  1210,
    1215,  1217,  1219,  1221,  1223,  1225,  1227,  1234,  1239,  1240,
    1241,  1242,  1243,  1244,  1248,  1250,  1252,  1254,  1264,  1268,
    1270,  1279,  1281,  1283,  1286,  1288,  1293,  1295,  1297,  1299,
    1301,  1309,  1324,  1329,  1331,  1341,  1345,  1349,  1354,  1355,
    1360,  1362,  1364,  1374,  1376,  1381,  1386,  1387,  1391,  1392,
    1396,  1398,  1424,  1429,  1431,  1444,  1450,  1452,  1454,  1456,
    1459,  1461,  1464,  1466,  1469,  1471,  1474,  1476,  1479,  1481,
    1486,  1488,  1493,  1495,  1514,  1515,  1519,  1521,  1526,  1542,
    1550,  1554,  1556,  1558,  1560,  1571,  1573,  1575,  1577,  1579,
    1581,  1583,  1585,  1587,  1589,  1591,  1593,  1595,  1597,  1599,
    1601,  1616,  1620,  1622,  1624,  1627,  1629,  1631,  1633,  1636,
    1638,  1643,  1645,  1652,  1654,  1657,  1663,  1664,  1669,  1670,
    1674,  1676,  1681,  1683,  1689,  1694,  1696,  1700,  1702,  1707,
    1709,  1714,  1716,  1721,  1724,  1727,  1732,  1735,  1738,  1741,
    1744,  1749,  1751,  1756,  1758,  1764,  1769,  1774,  1775,  1776,
    1777,  1778,  1782,  1783,  1785,  1786,  1790,  1792,  1797,  1799,
    1804,  1807,  1810,  1812,  1814,  1816,  1818,  1820,  1822,  1824,
    1826,  1828,  1839,  1841,  1843,  1850,  1858,  1864,  1869,  1871,
    1873,  1875,  1880,  1882,  1887,  1889,  1894,  1896,  1901,  1903,
    1905,  1913,  1916,  1921,  1923,  1928,  1930,  1932,  1938,  1940,
    1942,  1944,  1946,  1948,  1950,  1952,  1954,  1956,  1958,  1960,
    1962,  1964,  1966,  1968,  1970,  1972,  1974,  1976,  1978,  1983,
    1985,  1987,  1992,  1994,  1996,  1998,  2003,  2008,  2010,  2015,
    2017,  2033,  2035,  2037,  2039,  2044,  2046,  2046,  2049,  2050,
    2051,  2052,  2054,  2058,  2060,  2062,  2067,  2069,  2080,  2082,
    2087,  2088,  2092,  2094,  2101,  2103,  2105,  2110,  2112,  2114,
    2116,  2118,  2120,  2125,  2126,  2127,  2128,  2129
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "I_CONSTANT", "F_CONSTANT", "ENUMERATION_CONSTANT", "TYPEDEF_NAME",
  "FUNC_NAME", "SIZEOF", "ARROW", "INC", "DEC", "SHL", "SHR", "LE", "GE",
  "EQ", "NE", "AND", "OR", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF", "EXTERN", "STATIC", "AUTO",
  "REGISTER", "INLINE", "CONST", "RESTRICT", "VOLATILE", "ELLIPSIS",
  "PRAGMA", "__ALIGNOF", "__ALIGNOF__", "__ASM", "__ASM__", "__ATTRIBUTE",
  "__ATTRIBUTE__", "__COMPLEX", "__COMPLEX__", "__CONST", "__CONST__",
  "__EXTENSION__", "__IMAG", "__IMAG__", "__INLINE", "__INLINE__",
  "__INTERATOR", "__INTERATOR__", "__LABEL__", "__REAL", "__REAL__",
  "__SIGNED", "__SIGNED__", "__TYPEOF", "__TYPEOF__", "__VOLATILE",
  "__VOLATILE__", "ASM", "TYPEOF", "__RESTRICT", "__AUTO_TYPE", "VOID",
  "CHAR", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE", "SIGNED", "UNSIGNED",
  "BOOL", "COMPLEX", "IMAGINARY", "ATOMIC", "STRUCT", "UNION", "ENUM",
  "__BUILTIN_VA_LIST", "_DECIMAL32", "_DECIMAL64", "_DECIMAL128",
  "_FLOAT128", "__INT128", "__INT128_T", "__UINT128_T", "_BITINT128",
  "_BITINT", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "ALIGNAS", "ALIGNOF",
  "GENERIC", "NORETURN", "_STATIC_ASSERT", "STATIC_ASSERT", "THREAD_LOCAL",
  "THIS", "SELF", "NEW", "DELETE", "NS", "FAT_ARROW", "GET", "SET", "IMPL",
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

#define YYPACT_NINF (-550)
#define YYTABLE_NINF (-367)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1475,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,
    -550,  -550,   -70,  -550,   -67,   -59,    48,   115,  2418,  -550,
    -550,  -550,  -550,  -550,  -550,   196,  4010,    92,  -550,  1527,
    1626,  1664,  1749,  1787,    92,  -550,  3077,  3563,  3563,     4,
     215,  -550,  -550,   472,   196,   132,  -550,    65,   699,   217,
      13,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,
    -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,   104,
    -550,  -550,    11,  -550,  -550,  -550,  -550,  -550,  -550,  -550,
    -550,  -550,  -550,  -550,  -550,    36,  -550,  -550,  -550,  -550,
    -550,  -550,  -550,  -550,  1793,  1910,  -550,  -550,  -550,  -550,
    -550,   -80,  -550,  3582,  3660,  3660,  -550,   107,   110,  -550,
    -550,   310,   257,  -550,  -550,  -550,  -550,  -550,  -550,  3128,
    -550,  -550,  -550,    -1,   315,   218,   227,   239,   111,    80,
     366,   256,   236,  -550,  -550,  3563,    67,  -550,  -550,  -550,
    -550,   225,  3792,   522,   -72,   706,  3420,  -550,   241,   -14,
    3563,   106,  2079,   248,  -550,  -550,   472,    86,   250,   196,
    -550,  -550,  -550,  -550,  3563,   276,   276,  2193,   196,  2922,
     677,   803,  -550,   217,   831,  -550,  -550,   418,   294,  1200,
     298,  -550,  -550,  -550,  -550,    42,  3225,  -550,  3276,  -550,
    -550,   953,  3563,  -550,  -550,   121,  -550,  -550,    77,   285,
    3563,  3563,  3563,  3563,  3563,  3563,  3563,  3563,  3563,  3563,
    3563,  3563,  3563,  3563,  3563,  3563,  3563,  3563,  3563,  -550,
     128,  -550,  -550,  3563,  1314,   131,  -550,  -550,    92,   891,
    1670,   272,  -550,   286,  -550,  -550,  1948,  -550,   452,   313,
     475,   334,  2564,  2766,   338,  2558,  -550,  -550,  -550,  -550,
    -550,  -550,  -550,  -550,  -550,  -550,  -550,    78,  3902,  -550,
    -550,  -550,  -550,    92,   140,  2067,  -550,  -550,  -550,  2512,
    3369,   339,  -550,   341,   943,  -550,   171,  3828,   347,   354,
    -550,   122,   350,  -550,   -83,  -550,   369,   418,  -550,  1487,
    -550,   179,  -550,  1583,  -550,  -550,   367,   373,   375,   374,
    3563,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,
    -550,  -550,  -550,  3563,  2581,   315,   -91,   218,   227,   239,
     111,    80,    80,   366,   366,   366,   366,   256,   256,   236,
     236,  -550,  -550,  -550,  -550,  -550,   -76,  -550,  -550,   124,
    -550,  -550,  3369,   376,  -550,   378,  1093,  -550,   380,   382,
     286,  1145,   931,  -550,   383,  -550,   384,  -550,    25,    66,
    -550,  -550,   393,   395,   184,  -550,   -57,   -36,    50,  3423,
     377,  3914,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,
    -550,  -550,   402,  -550,   404,  3563,   405,   398,   403,   412,
    2783,   414,   545,   415,   417,  2929,  -550,  -550,  -550,   182,
    -550,  3512,  -550,   276,  -550,  2215,  -550,  -550,  -550,  -550,
    -550,  2434,  -550,  -550,   416,  3369,  -550,  -550,  3563,   421,
    -550,   425,  3890,  -550,   346,  -550,  -550,  -550,  1937,    92,
    -550,  -550,    18,  -550,  3563,   149,  -550,  -550,  3563,    83,
     201,  -550,    92,  -550,  1931,   431,   431,  -550,   511,  -550,
    -550,  2434,  -550,  3563,  -550,  3563,  -550,   436,  3369,  -550,
    -550,  3563,  -550,   437,  -550,  -550,  3369,   438,  -550,   440,
    1295,  -550,   443,   419,   447,   422,   -25,  -550,   594,   455,
     136,  -550,   597,  1133,   453,  3563,   458,  -550,  3563,  -550,
    -550,  3563,  -550,  -550,   459,  -550,    66,  -550,  -550,  2783,
     473,  2783,  3563,  3563,  3563,   510,  2728,   470,  -550,  -550,
    -550,   252,  -550,  -550,  -550,  -550,  3563,   617,  -550,   162,
    2512,   -27,  -550,  -550,   474,   476,  -550,  -550,  3732,  -550,
    -550,   619,  -550,  -550,  -550,    40,  -550,  -550,  -550,   179,
    -550,   489,  -550,   491,   141,  -550,   492,   170,  -550,  -550,
    -550,   481,   482,  -550,   483,  3369,  -550,  -550,  3563,  -550,
     485,  -550,  -550,  -550,   487,  3563,  -550,  -550,  -550,  3566,
    3563,  -550,  -550,  -550,   586,   488,  -550,   261,  -550,   265,
     278,  1335,   306,  -550,  2783,  -550,   159,   160,   178,   498,
    2980,  2980,  -550,  -550,   494,  -550,  2286,  -550,  -550,  -550,
    -550,  -550,  -550,  -550,  -550,  -550,  3563,  3563,   838,  -550,
    3563,  2364,  -550,  -550,  -550,  -550,   495,   496,  -550,   605,
     287,   493,   291,  -550,   611,  -550,  -550,  -550,  -550,   499,
    -550,  2783,  2783,  2783,  3563,  1349,  1498,  -550,  -550,  -550,
    2512,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,
     615,  -550,  -550,  -550,   552,  -550,  -550,   186,  2783,   193,
    2783,   195,  -550,  -550,  2783,   507,  -550,  2783,  -550,  2783,
    -550,  -550,  -550,  -550
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     204,   282,   277,   278,   280,    82,   208,   306,   284,   285,
     279,   281,     0,   283,     0,     0,     0,     0,   204,     4,
       6,     7,     9,    10,     8,   204,     0,   205,   206,   204,
     204,   204,   204,   204,   204,   185,   204,     0,     0,     0,
       0,     1,     5,   311,   204,     0,   200,     0,   204,   289,
     204,   230,   209,   210,   211,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,     0,
     248,   249,     0,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   212,   228,     0,   229,   227,   207,   186,
     192,   194,   196,   198,   204,   204,   156,   173,   170,   171,
     172,     0,   174,     0,     0,     0,   307,     0,     0,    55,
      56,   165,    81,   140,   141,   139,   138,   143,   142,   204,
     161,   166,   182,    98,   100,   102,   104,   106,   108,   110,
     113,   118,   121,   124,   128,     0,   130,   144,   157,   158,
     160,     0,     0,   204,   324,   204,   204,   167,     0,     0,
       0,     0,   204,     0,   312,   310,   309,     0,     0,   204,
     184,   290,   183,   291,     0,     0,     0,   204,   204,   203,
       0,   204,   305,   288,   204,   246,   247,     0,   270,   204,
     245,   188,   190,   168,   169,     0,   204,   134,   204,   131,
     132,   204,     0,   162,    80,     0,    83,    85,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   133,
       0,   152,   153,     0,     0,     0,   287,   255,   204,     0,
     204,   326,   323,   327,   259,   137,   204,   286,     0,     0,
       0,     0,   204,   204,     0,   204,    21,    24,    23,    31,
      29,    30,    25,    26,    27,    28,    32,     0,   204,   313,
     308,   292,   201,   204,     0,   204,    13,    11,    16,     0,
       0,   139,   293,     0,     0,   303,   204,     0,     0,   315,
     316,     0,     0,   275,     0,   271,   274,     0,   241,   204,
     250,   204,   254,   204,   164,   163,     0,     0,     0,     0,
       0,   159,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    87,     0,     0,   101,     0,   103,   105,   107,
     109,   111,   112,   116,   117,   114,   115,   119,   120,   122,
     123,   125,   126,   127,   151,   150,     0,   146,   180,     0,
     148,   149,     0,   139,   329,     0,     0,   345,     0,     0,
     325,     0,   204,   257,     0,   362,     0,   364,     0,     0,
      17,    22,     0,     0,   204,    50,     0,     0,     0,   204,
       0,   204,    35,    38,    37,    44,    42,    43,    39,    40,
      41,    45,   203,    14,   156,     0,     0,     0,     0,     0,
     366,     0,     0,     0,     0,     0,   382,   376,   372,     0,
     380,   204,   381,     0,   365,   204,   378,   368,   369,   370,
     371,     0,   351,   202,     0,     0,   294,   301,     0,   139,
     300,     0,   204,   318,   204,   319,   321,   302,   204,   204,
     304,   276,     0,   266,     0,     0,   242,   251,     0,     0,
       0,   261,   204,   243,   204,   135,     0,   136,   204,    84,
      86,     0,   129,     0,   145,     0,   147,     0,     0,   330,
     336,     0,   335,     0,   346,   328,     0,   139,   337,     0,
       0,   347,     0,     0,     0,     0,     0,    60,     0,     0,
       0,    66,     0,   204,     0,     0,     0,    47,     0,    72,
      71,     0,    77,    76,     0,    49,     0,    18,    36,   366,
       0,   366,     0,     0,     0,     0,   204,     0,   394,   395,
     396,     0,   383,   367,   377,   379,     0,     0,   353,     0,
       0,     0,   357,   296,     0,     0,   297,   299,     0,   314,
     317,     0,   267,   272,   273,     0,   268,   265,   252,   204,
     253,   263,   244,     0,     0,   176,     0,     0,    99,   181,
     332,     0,     0,   334,     0,     0,   338,   344,     0,   343,
       0,   348,   361,   363,     0,     0,    58,    57,    59,   204,
       0,    64,    63,    65,    52,     0,    79,     0,    48,     0,
       0,   204,     0,   373,   366,   375,     0,     0,     0,     0,
       0,     0,   393,   397,     0,   360,     0,   349,   352,   356,
     358,   295,   298,   322,   269,   262,     0,     0,   204,   175,
       0,     0,   154,   331,   333,   340,     0,     0,   341,    61,
       0,     0,     0,    54,    51,    46,    73,    78,    74,     0,
     374,   366,   366,   366,     0,     0,     0,   359,   350,   355,
       0,   264,   179,   177,   178,   155,   339,   342,    62,    69,
      67,    70,    53,    75,   385,   386,   387,     0,   366,     0,
     366,     0,   354,    68,   366,     0,   391,   366,   389,   366,
     384,   388,   392,   390
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -550,  -550,  -550,   638,  -550,  -550,  -550,   490,  -550,  -550,
    -550,   413,  -550,  -550,   293,  -208,  -206,  -198,  -550,   292,
     -43,  -137,  -550,   189,  -131,   173,   190,  -130,  -550,  -107,
    -550,  -102,  -550,  -550,    46,  -113,   317,  -550,   -35,  -550,
     471,   477,   497,   500,   469,   289,   344,   246,   290,   224,
     260,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,    68,
    -550,   -30,   -26,   484,  -550,   516,   -10,  -550,   650,   -24,
       1,  -550,   593,  -550,   399,  -272,   -86,  -550,   152,  -550,
     401,  -315,  -550,  -550,   157,  -550,  -550,   -20,   -41,     0,
      41,    -2,  -145,  -158,  -550,  -374,  -550,    47,  -117,  -215,
    -258,   242,  -549,  -550,   174,  -167,   -48,  -550,  -550,  -142,
    -550,   296,  -203,  -550,  -550,  -550
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,   165,    21,   166,    22,   244,
     245,   246,   370,   371,   372,   247,   248,   249,   364,   365,
     120,   250,   476,   477,   251,   480,   481,   252,   253,   254,
     366,   255,   367,   121,   398,   399,   196,   313,   197,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     198,   135,   136,   137,   185,   138,   139,   140,   544,   545,
     339,   141,    24,   276,    45,    46,    26,    27,    28,    29,
      30,    84,   178,    85,   289,   290,   144,   440,   441,    86,
     284,   285,   286,    87,    31,    32,    33,   158,    49,   150,
     147,    50,   156,   348,   279,   280,   281,   546,   349,   233,
     518,   519,   520,   521,   522,    35,   402,   403,   404,   572,
     405,   406,   407,   408,   409,   410
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,   122,   122,   122,   163,    48,   195,   149,   151,   173,
      94,   413,   292,   278,   175,    47,   350,   437,    34,   176,
     200,   283,   167,   266,   267,   274,   142,   232,   475,    34,
      34,    34,    34,    34,   157,    95,   146,   143,   169,   175,
     157,   155,   183,   283,   176,   294,    23,   640,    34,   453,
     373,   264,   374,   362,   530,   300,    39,   227,    43,   234,
     375,     6,   640,   432,    23,   184,   488,   433,   161,   479,
     300,   229,   230,   195,    36,   195,   454,    37,   220,   221,
     222,   362,    40,   148,   346,    38,   161,   491,   316,   161,
     172,   489,   265,   291,    34,    34,   208,   209,   565,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   142,
     336,   599,   492,   265,   163,    41,   516,   533,   517,   146,
     143,   376,   292,   566,   265,   415,   292,   377,   378,   206,
     207,   334,   238,   142,   340,   142,   142,   239,   201,   263,
       6,   167,   231,   228,   143,   228,   143,   236,   263,   157,
     353,   379,    34,   152,   260,    43,   380,    44,    47,   425,
     177,   277,   295,   373,   142,   374,   199,    34,   532,   142,
     494,    34,   437,   375,   228,   143,   142,   335,   142,   228,
     143,   142,   341,   109,   110,   179,   146,   143,   146,   143,
     604,   228,   143,   145,   472,   621,    43,   458,   256,   363,
     154,   109,   110,   291,   109,   110,   470,   291,    43,   350,
     223,   224,   225,   162,   172,   312,   210,   211,   142,     6,
     533,   282,   487,   153,   490,   493,   142,     6,   231,   236,
      34,   538,     6,   296,   376,   297,   228,   143,   298,   400,
     377,   378,    34,    34,     6,    34,   109,   110,   174,   109,
     110,   191,   240,   382,   192,   368,   423,   241,    34,   570,
     194,   513,   598,   106,   379,   401,   157,   300,   429,   380,
     455,   442,   301,   430,   424,   456,   145,   292,   159,   142,
     160,   439,   511,   142,   571,   265,   300,   608,   383,   228,
     143,   256,   609,   228,   143,   535,   134,   134,   134,   536,
     145,    43,   145,   591,   381,   300,   300,   485,   596,    43,
     631,   632,   597,   259,   229,   422,   611,  -320,   193,   438,
     612,   555,  -320,    44,   300,   575,    43,   154,   300,   633,
     512,   145,   300,   265,   567,   202,   145,   665,   639,   300,
      44,   300,   505,   145,   667,   145,   669,   539,   145,   540,
     122,   203,    34,   639,   486,   500,   478,   482,   291,   219,
     170,   171,   204,   187,   189,   190,   216,   217,   218,    34,
     235,    34,   577,   205,   235,   579,   226,    94,   580,   400,
     212,   213,   662,   173,   214,   215,   154,   635,   636,   586,
     587,   588,   237,   145,     6,   134,   163,   258,   300,   122,
     593,   261,    95,   122,   534,   401,   134,   300,   537,   625,
     134,   300,   528,   626,   157,   229,   230,   381,   548,   531,
     424,   283,    34,   629,   300,   265,   627,   154,    34,   351,
     352,   259,   541,   300,   142,   649,   314,   300,   142,   651,
     331,   332,   333,   287,   228,   143,   145,   293,   228,   143,
     145,   583,   620,   585,   571,   265,   354,   622,   327,   328,
     134,   355,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   356,
     590,   122,   357,    34,    25,   163,   594,   273,   360,   229,
     422,   416,  -326,   417,   482,   321,   322,  -326,   427,   154,
     428,   431,    25,   259,   329,   330,   401,   434,   154,   299,
       2,     3,     4,    89,    90,    91,    92,    93,   445,   442,
     448,   657,   659,   661,   446,  -256,   447,   497,   459,   157,
     460,   464,   168,   465,   473,   474,   630,   483,   452,   484,
     269,   338,   502,    10,   499,   501,   345,   503,   507,     2,
       3,     4,   323,   324,   325,   326,   504,    11,   506,     6,
       2,     3,     4,   508,     7,   509,   564,   562,   523,    34,
       6,   122,   259,   526,   134,     7,   641,   527,   181,   182,
     451,    34,    10,   654,   655,   656,   412,   414,   550,   553,
     556,   421,   557,    10,   561,   563,    11,   475,   142,   569,
     479,   145,    43,   581,   576,   145,   578,    11,   228,   143,
     666,   543,   668,   584,   589,   259,   670,   449,   592,   672,
     595,   673,   603,   154,   623,   235,   601,   259,   602,   606,
     450,   607,   610,   613,   614,   615,   257,   618,   619,   624,
    -256,  -256,   634,   648,   650,   134,   637,   646,   647,   652,
     653,   168,  -256,   663,   664,   671,    42,   268,   361,   457,
     495,   134,  -256,   463,   498,  -256,  -256,   568,   469,   582,
    -256,   315,   573,  -256,   320,   262,   643,    88,   180,   317,
      96,    97,    98,    99,   100,   101,   102,   103,   435,   104,
     105,   605,   444,   547,   134,   600,     0,     0,   134,     0,
     318,   515,     0,     0,   319,     0,     0,     0,     0,  -260,
       0,   270,   259,   134,     0,     2,     3,     4,     0,     0,
       0,     0,     0,   106,     0,     0,   358,   359,   412,   257,
       7,     0,   524,     0,     0,   525,     1,     2,     3,     4,
       0,     0,   257,     0,     2,     3,     4,     6,    10,   168,
       0,     0,     7,     0,     6,     8,     9,     0,     0,     7,
       0,     0,    11,     0,     0,   145,     0,     0,   412,     0,
      10,     0,   549,     0,     0,   551,   134,    10,   552,     0,
       0,     0,     0,   554,    11,     0,     0,   560,     0,   107,
     108,    11,     0,     0,     0,   109,   110,   111,   112,     0,
       0,     0,     0,     0,     0,   113,   114,   271,     0,     0,
      12,   116,     0,    13,    14,    15,     0,     0,   117,   118,
       0,   119,   164,     0,  -260,  -260,     0,     0,     0,   272,
       0,     0,     0,     0,     0,     0,  -260,   412,     0,     0,
       1,     2,     3,     4,     0,     0,  -260,     0,   -12,  -260,
    -260,     6,     0,   496,  -260,   257,     7,  -260,     0,     8,
       9,     0,     0,     0,     0,     0,   134,     0,     0,     2,
       3,     4,   616,     0,    10,   617,     2,     3,     4,     6,
       0,     0,     0,     0,     7,     0,     6,     0,    11,   168,
       0,     7,     0,     0,    96,    97,    98,    99,   100,   101,
     102,   103,    10,   104,   105,     0,     0,     0,     0,    10,
       0,     0,     0,   412,    12,     0,    11,    13,     0,     0,
       0,     0,     0,    11,   642,   342,     0,   644,   412,     2,
       3,     4,     0,     0,     0,     0,     0,   106,   543,     0,
       0,     0,     0,     0,     7,     0,    96,    97,    98,    99,
     100,   101,   102,   103,   275,   104,   105,   412,     0,     0,
       0,     0,    10,     0,     0,     0,     0,     0,     1,     2,
       3,     4,     0,     0,     0,     0,    11,   418,     0,     6,
       0,     2,     3,     4,     7,     0,     0,     8,     9,   106,
     168,     2,     3,     4,     0,     0,     7,     0,     0,     0,
       0,     6,    10,   107,   108,     0,     7,     0,     0,   109,
     110,   111,   112,     0,    10,     0,    11,     0,     0,   113,
     114,   343,     0,     0,    10,   116,     0,     0,    11,     0,
       0,     0,   117,   118,     0,   119,     0,     0,    11,     0,
       0,     0,    12,   344,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,   113,   114,   419,     0,     0,     0,   116,     0,     0,
       0,     0,   471,     0,   117,   118,     0,   119,     0,     0,
       0,     0,     0,     0,     0,   420,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   104,   105,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   461,     0,     0,
       0,     2,     3,     4,     0,     0,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     7,     0,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,     0,    10,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     0,     0,     0,     0,    11,   466,
       0,     6,     0,     2,     3,     4,     7,     0,     0,     8,
       9,   106,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     0,    10,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,     0,    10,     0,    11,     0,
       0,   113,   114,   115,     0,     0,     0,   116,     0,     0,
      11,     0,     0,     0,   117,   118,     0,   119,     2,     3,
       4,     0,     0,     0,    12,   462,     0,    13,     6,     0,
       0,     0,     0,     7,     0,     0,     0,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,     0,     0,     0,
       0,    10,     0,   113,   114,   467,     0,     0,     0,   116,
       0,     0,     0,     0,   574,    11,   117,   118,     0,   119,
       0,     0,     0,     0,     0,     0,     0,   468,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
       0,     0,     0,     0,     0,    14,    15,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   104,   105,     0,   558,
       0,     0,     0,     2,     3,     4,     0,     0,     0,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     7,     0,
     288,     0,    96,    97,    98,    99,   100,   101,   102,   103,
     106,   104,   105,     0,     0,     0,    10,     7,     0,     0,
       0,     0,     1,     2,     3,     4,     0,     0,     0,     0,
      11,     0,     0,     6,     0,     0,     0,     0,     7,     0,
       0,     8,     9,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     7,     0,     0,     0,    10,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,     0,     0,     0,
      11,     0,     0,   113,   114,   115,   107,   108,     0,   116,
       0,     0,   109,   110,   111,   112,   117,   118,     0,   119,
       0,     0,   113,   114,   115,     0,    12,   559,   116,    13,
       0,     0,     0,     0,     0,   117,   118,     0,   119,     0,
       0,   107,   108,     0,     0,   337,     0,   109,   110,   111,
     112,     0,     0,     0,     0,    -2,     0,   113,   114,   115,
       0,     0,     0,   116,     0,     0,   628,     0,     0,     0,
     117,   118,     0,   119,     0,     0,     0,     0,     0,     0,
     658,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     104,   105,     1,     2,     3,     4,     0,     5,     0,     0,
       0,     0,     0,     6,     0,     2,     3,     4,     7,     0,
    -187,     8,     9,     0,     0,     6,     0,     0,     0,     0,
       7,     0,     0,     0,   106,     0,    10,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,    10,     0,
      11,     0,     0,     0,     1,     2,     3,     4,     0,     0,
       0,     0,    11,     0,     0,     6,     0,     0,     0,     0,
       7,     0,     0,     8,     9,     0,    12,     0,     0,    13,
      14,    15,     0,     0,     0,     0,     0,     0,    10,     0,
       0,    16,    14,    15,     0,     0,     0,     0,     0,     0,
     107,   108,    11,     0,     0,     0,   109,   110,   111,   112,
       0,     2,     3,     4,     0,     0,   113,   114,   115,  -193,
       0,     6,   116,     0,     0,     0,     7,   436,    12,   117,
     118,    13,   119,     0,     0,  -187,  -187,     0,  -187,   660,
       0,     0,     0,     0,    10,     0,     0,  -187,     0,     0,
       0,     0,     0,     1,     2,     3,     4,  -195,    11,     0,
    -187,  -187,     0,  -187,     6,  -187,     0,     0,  -187,     7,
       0,     0,     8,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    14,    15,
       0,     1,     2,     3,     4,     0,     0,     1,     2,     3,
       4,    11,     6,     0,     0,     0,     0,     7,     6,     0,
       8,     9,     0,     7,     0,     0,     8,     9,     0,     0,
       0,     0,     0,   443,     0,    10,     0,    12,     0,     0,
      13,    10,     0,     0,  -193,  -193,     0,  -193,     0,    11,
       0,     0,  -197,     0,     0,    11,  -193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -193,
    -193,     0,  -193,     0,  -193,    12,     0,  -193,    13,     0,
       0,    12,  -195,  -195,    13,  -195,     1,     2,     3,     4,
    -199,     0,     0,     0,  -195,     0,  -189,     6,     0,     0,
      43,     0,     7,     0,     0,     8,     9,  -195,  -195,     0,
    -195,     0,  -195,   229,   230,  -195,     0,     0,     0,     0,
      10,   347,     0,     0,     1,     2,     3,     4,     0,     0,
       1,     2,     3,     4,    11,     6,     0,     0,     0,     0,
       7,     6,     0,     8,     9,     0,     7,     0,     0,     8,
       9,     0,     0,     0,     0,     0,     0,     0,    10,     0,
      12,     0,     0,    13,    10,     0,     0,  -197,  -197,     0,
    -197,     0,    11,     0,     0,     0,     0,     0,    11,  -197,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -197,  -197,     0,  -197,     0,  -197,    12,     0,
    -197,    13,     0,     0,    12,  -199,  -199,    13,  -199,     0,
       0,  -189,  -189,  -191,  -189,     0,     0,  -199,     0,     0,
       0,     0,     0,  -189,     0,     0,     0,     0,     0,     0,
    -199,  -199,     0,  -199,     0,  -199,  -189,  -189,  -199,  -189,
       0,  -189,     0,     0,  -189,     0,     0,     1,     2,     3,
       4,  -258,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     7,     0,     0,     8,     9,     0,     2,
       3,     4,     0,     0,     1,     2,     3,     4,   529,     6,
       0,    10,     0,     0,     7,     6,     2,     3,     4,     0,
       7,     0,     0,     8,     9,    11,     6,     0,     0,     0,
       0,     7,    10,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,    10,
       0,    12,    11,     0,    13,     0,     0,     0,  -191,  -191,
       0,  -191,     0,    11,     0,     0,     0,     0,     0,     0,
    -191,     0,     0,     0,     0,     0,    14,    15,    12,     0,
       0,    13,     0,  -191,  -191,     0,  -191,     0,  -191,     0,
       0,  -191,     0,     0,     0,     0,  -258,  -258,     0,     0,
     384,    97,    98,    99,   100,   101,   102,   103,  -258,   104,
     105,   542,     0,     0,     0,     0,     0,     0,  -258,     0,
       0,  -258,  -258,     0,     0,     0,  -258,     0,     0,  -258,
       0,     0,     0,     0,     1,     2,     3,     4,     0,     5,
       0,     0,     0,   106,     0,     6,     1,     2,     3,     4,
       7,     5,     0,     8,     9,     0,     0,     6,     0,     0,
       0,     0,     7,     0,     0,     8,     9,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,   385,   386,   387,     0,
     388,   389,   390,   391,   392,   393,   394,   395,    12,   107,
     108,    13,    14,    15,     0,   109,   110,   111,   112,     0,
      12,     0,     0,    13,     0,   113,   114,   115,     0,     0,
       0,   116,     0,   242,   243,     0,     0,     0,   117,   118,
       0,   119,     0,     0,     0,   396,  -366,   397,   384,    97,
      98,    99,   100,   101,   102,   103,     0,   104,   105,   -19,
       1,     2,     3,     4,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     7,     0,     0,     8,
       9,     0,     1,     2,     3,     4,     0,     5,     0,     0,
       0,   106,     0,     6,    10,     0,     0,     0,     7,     0,
       0,     8,     9,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   104,   105,
      11,     0,     0,     0,    12,     0,     0,    13,    14,    15,
       0,     0,     0,     0,   385,   386,   387,     0,   388,   389,
     390,   391,   392,   393,   394,   395,    12,   107,   108,    13,
      14,    15,   106,   109,   110,   111,   112,     0,     0,     7,
       0,     0,   -15,   113,   114,   115,     0,     0,     0,   116,
       0,     0,     0,     0,     0,     0,   117,   118,     0,   119,
       0,     0,     0,   396,  -366,   514,     0,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,     0,     0,
     106,     0,     0,     0,   113,   114,   115,     7,    -3,     0,
     116,     0,     0,     0,     0,     0,     0,   117,   118,   516,
     119,   517,     0,     0,     0,   411,   638,    96,    97,    98,
      99,   100,   101,   102,   103,     0,   104,   105,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     0,
       5,     0,     0,     0,     0,     0,     6,     0,     0,     0,
       0,     7,     0,     0,     8,     9,   107,   108,     0,     0,
     106,     0,   109,   110,   111,   112,     0,     7,     0,    10,
       0,     0,   113,   114,   115,     0,     0,     0,   116,     0,
       0,     0,     0,    11,     0,   117,   118,   516,   119,   517,
       0,     0,     0,   411,   645,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   104,   105,     0,     0,     0,    12,
       0,     0,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,   107,   108,     0,     0,
       0,     0,   109,   110,   111,   112,     0,     0,   106,     0,
       0,     0,   113,   114,   115,     7,     0,     0,   116,     0,
       0,     0,     0,     0,     0,   117,   118,   516,   119,   517,
       0,     0,     0,   411,    96,    97,    98,    99,   100,   101,
     102,   103,     0,   104,   105,     1,     2,     3,     4,     0,
       5,     1,     2,     3,     4,     0,     6,     0,     0,     0,
       0,     7,     6,     0,     8,     9,     0,     7,     0,     0,
       8,     9,     0,     0,   107,   108,     0,   106,     0,    10,
     109,   110,   111,   112,     7,    10,     0,     0,     0,     0,
     113,   114,   115,    11,     0,     0,   116,     0,     0,    11,
       0,     0,     0,   117,   118,     0,   119,     0,     0,     0,
       0,   411,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,    13,     0,     0,    12,     0,     0,    13,     0,
       0,     0,   242,   243,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,   108,     0,     0,     0,     0,   109,
     110,   111,   112,     0,     0,     0,     0,     0,   -20,   113,
     114,   115,     0,     0,     0,   116,     0,     0,     0,     0,
       0,     0,   117,   118,     0,   119,     0,     0,     0,     0,
     451,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     104,   105,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     0,
       0,     0,     0,     0,   106,     0,     6,     0,     0,     0,
       0,     7,     0,     0,     8,     9,   384,    97,    98,    99,
     100,   101,   102,   103,     0,   104,   105,     0,     0,    10,
       0,     0,     0,     1,     2,     3,     4,     0,     0,     0,
       0,     0,     0,    11,     6,     0,     0,     0,     0,     7,
       0,     0,     8,     9,     0,     5,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     7,    10,     0,    12,
     107,   108,    13,    14,    15,     0,   109,   110,   111,   112,
       0,    11,     0,     0,     0,     0,   113,   114,   115,     0,
       0,     0,   116,     0,     0,     0,     0,     0,     0,   117,
     118,     0,   119,     0,     0,     0,   396,    12,     0,     0,
      13,     0,   385,   386,   387,     0,   388,   389,   390,   391,
     392,   393,   394,   395,     0,   107,   108,     0,     0,     0,
       0,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,   113,   114,   115,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,   117,   118,     0,   119,     0,     0,
      51,   396,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   104,   105,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,     0,     0,
       0,     0,     7,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,     0,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,     0,     0,   106,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,    83,
       0,   107,   108,     0,     0,     0,     0,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,   113,   114,   115,
     269,     0,     0,   116,     0,     0,     0,     0,     0,     0,
     117,   118,     0,   119,     0,     0,     0,   510,     0,     0,
      96,    97,    98,    99,   100,   101,   102,   103,     0,   104,
     105,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,   113,   114,
     115,     0,     0,     0,   116,     2,     3,     4,     0,     0,
       0,   117,   118,   106,   119,     6,     0,     0,   396,     0,
       7,    96,    97,    98,    99,   100,   101,   102,   103,     0,
     104,   105,     0,     0,     0,     0,     0,     0,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     2,     3,     4,     0,
       0,     0,     0,     0,   106,     0,     6,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,   107,
     108,     0,     0,     0,     0,   109,   110,   111,   112,    10,
       0,     0,     0,     0,     0,   113,   114,   115,     0,     0,
       0,   116,     0,    11,     0,     0,     0,     0,   117,   118,
       0,   119,     0,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,   102,   103,     0,   104,   105,     0,
     107,   108,     0,     0,     0,     0,   109,   110,   111,   112,
       0,     0,     0,     0,     0,     0,   113,   114,   115,     0,
       0,     0,   116,     2,     3,     4,     0,     0,     0,   117,
     118,   106,   119,     6,     0,     0,     0,     0,     7,    96,
      97,    98,    99,   100,   101,   102,   103,     0,   104,   105,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     2,     3,     4,     0,     0,     0,
       0,     0,   106,     0,     6,     0,     0,     0,     0,     7,
       0,     0,     0,     0,     0,     0,     0,   107,   108,     0,
       0,     0,     0,   109,   110,   111,   112,    10,     0,     0,
       0,     0,     0,   113,   114,   115,     0,     0,     0,   116,
       0,    11,     0,     0,     0,     0,   117,   118,     0,   119,
       0,     0,    96,    97,    98,    99,   100,   101,   102,   103,
       0,   104,   105,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,     0,   109,   110,   111,   112,     0,     0,
       0,     0,     0,     0,   113,   114,   115,     2,     3,     4,
     116,     0,     0,     0,     0,   106,     0,   117,   118,     0,
     119,     0,     7,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,     0,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     0,     0,   106,     0,     6,     0,
       0,     6,     0,     7,     0,     0,     7,     0,     0,     8,
       9,   107,   108,     0,     0,     0,     0,   109,   110,   111,
     112,     0,     0,     0,    10,     0,     0,   113,   114,   115,
       0,     0,     0,   116,     0,     0,     0,     0,    11,     0,
     117,   118,     0,   119,     0,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   104,   105,     0,     0,     0,     0,
       0,     0,   107,   108,    12,     0,     0,    13,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,   113,   114,
     115,     0,     0,     0,   116,     0,     0,     0,   106,     0,
       6,   117,   118,     0,   119,     7,    96,    97,    98,    99,
     100,   101,   102,   103,     0,   104,   105,     0,     0,     0,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,   102,   103,     0,   104,   105,     0,     0,     0,     0,
       0,     0,     0,     1,     2,     3,     4,     0,     0,   106,
       0,     0,     0,     0,     6,     0,     7,     0,     0,     7,
       0,     0,     8,     9,   107,   108,     0,     0,   106,     0,
     109,   110,   111,   112,     0,     7,     0,    10,     0,     0,
     113,   114,   115,     0,     0,     0,   116,     0,     0,     0,
       0,    11,     0,   117,   118,     0,   119,     0,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,   102,
     103,     0,   104,   105,     0,   107,   108,    12,     0,     0,
      13,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,   113,   114,   115,   107,   108,     0,   116,     0,     0,
     109,   110,   111,   112,   117,   118,   106,   119,     0,     0,
     113,   114,   115,     7,     0,     0,   116,     0,     0,     0,
       0,     0,     0,   117,   118,     0,   186,     0,     0,     0,
       0,     0,     0,     0,     0,   161,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    54,    55,    56,     0,
       0,     0,   107,   108,     0,     0,     0,     0,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,   113,   114,
     115,     0,     0,     0,   116,     0,     0,     0,     0,     0,
      51,   117,   118,     0,   188,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,   426,     0,     0,     0,     0,    51,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
     109,   110,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     1,     2,     3,
       4,     0,     0,     0,     0,     0,     0,     0,     6,     1,
       2,     3,     4,     7,     5,    83,     8,     9,     0,     0,
       6,     1,     2,     3,     4,     7,     5,     0,     8,     9,
       0,    10,     6,     0,     0,     0,     0,     7,     0,     0,
       8,     9,     0,    10,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    12,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,    13,     0,    51,     0,
      43,     0,     0,     0,     0,    12,   242,   369,    13,     0,
       0,     0,     0,   229,   422,     0,     0,     0,   242,   369,
       0,   347,    52,    53,    54,    55,    56,     0,     0,     0,
       0,     0,   -33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83
};

static const yytype_int16 yycheck[] =
{
       0,    36,    37,    38,    47,    25,   119,    37,    38,    50,
      34,   269,   179,   171,     3,    25,   231,   289,    18,     8,
      21,     3,    48,   165,   166,   170,    36,   144,     3,    29,
      30,    31,    32,    33,    44,    34,    36,    36,    48,     3,
      50,    43,   122,     3,     8,     3,     0,   596,    48,   140,
     258,   164,   258,     3,   428,   146,     8,   143,   130,   145,
     258,    48,   611,   146,    18,   145,   123,   150,     3,     3,
     146,   143,   144,   186,   144,   188,   152,   144,    11,    12,
      13,     3,    34,    36,   229,   144,     3,   123,   201,     3,
      49,   148,   149,   179,    94,    95,    16,    17,   123,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,   119,
     223,   138,   148,   149,   157,     0,   143,   432,   145,   119,
     119,   258,   289,   148,   149,   270,   293,   258,   258,    18,
      19,     3,   146,   143,     3,   145,   146,   151,   139,   159,
      48,   167,   144,   143,   143,   145,   145,   146,   168,   159,
     236,   258,   152,   149,   156,   130,   258,   144,   168,   276,
     149,   171,   120,   371,   174,   371,   119,   167,   150,   179,
     120,   171,   444,   371,   174,   174,   186,   220,   188,   179,
     179,   191,   225,   118,   119,   149,   186,   186,   188,   188,
     150,   191,   191,    36,   352,   569,   130,   342,   152,   121,
      43,   118,   119,   289,   118,   119,   351,   293,   130,   424,
     143,   144,   145,   148,   173,   138,   136,   137,   228,    48,
     535,   174,   364,     8,   366,   367,   236,    48,   230,   228,
     230,   148,    48,   186,   371,   188,   236,   236,   191,   265,
     371,   371,   242,   243,    48,   245,   118,   119,   144,   118,
     119,   144,   146,   263,   144,   257,   276,   151,   258,   123,
       3,   403,   520,    46,   371,   265,   276,   146,   146,   371,
     146,   291,   151,   151,   276,   151,   119,   444,   146,   289,
     148,   291,   395,   293,   148,   149,   146,   146,   148,   289,
     289,   245,   151,   293,   293,   146,    36,    37,    38,   150,
     143,   130,   145,   506,   258,   146,   146,   123,   146,   130,
     151,   151,   150,   156,   143,   144,   146,   146,     8,   140,
     150,   466,   151,   144,   146,   483,   130,   170,   146,   151,
     148,   174,   146,   149,   476,    20,   179,   151,   596,   146,
     144,   146,   390,   186,   151,   188,   151,   146,   191,   148,
     385,   133,   352,   611,   364,   385,   358,   359,   444,   135,
     143,   144,   135,   103,   104,   105,   130,   131,   132,   369,
     146,   371,   485,   134,   150,   488,   151,   401,   491,   405,
      14,    15,   640,   424,   128,   129,   229,   590,   591,   502,
     503,   504,   151,   236,    48,   135,   439,   149,   146,   434,
     148,   151,   401,   438,   434,   405,   146,   146,   438,   148,
     150,   146,   422,   148,   424,   143,   144,   371,   453,   429,
     422,     3,   422,   581,   146,   149,   148,   270,   428,   143,
     144,   274,   442,   146,   444,   148,   151,   146,   448,   148,
     216,   217,   218,   149,   444,   444,   289,   149,   448,   448,
     293,   499,   565,   501,   148,   149,     4,   570,   212,   213,
     200,   148,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,     4,
     506,   516,   148,   483,     0,   528,   516,   170,   150,   143,
     144,   152,   146,   152,   496,   206,   207,   151,   151,   342,
     146,   151,    18,   346,   214,   215,   506,   138,   351,   192,
      38,    39,    40,    29,    30,    31,    32,    33,   151,   539,
     146,   634,   635,   636,   151,     3,   151,   150,   152,   539,
     152,   151,    48,   151,   151,   151,   584,   144,   314,   144,
     138,   224,   144,    71,   140,   140,   229,   144,     3,    38,
      39,    40,   208,   209,   210,   211,   144,    85,   144,    48,
      38,    39,    40,   148,    53,   148,   144,   148,   152,   569,
      48,   606,   415,   152,   314,    53,   606,   152,    94,    95,
     149,   581,    71,   631,   632,   633,   269,   270,   152,   152,
     152,   274,   152,    71,   151,   148,    85,     3,   608,   144,
       3,   444,   130,   144,   151,   448,   148,    85,   608,   608,
     658,   100,   660,   140,   104,   458,   664,   300,   148,   667,
       3,   669,     3,   466,    38,   401,   152,   470,   152,   140,
     313,   140,   140,   152,   152,   152,   152,   152,   151,   151,
     118,   119,   144,    38,   151,   385,   152,   152,   152,    38,
     151,   167,   130,    38,   102,   148,    18,   167,   245,   342,
     368,   401,   140,   346,   371,   143,   144,   478,   351,   496,
     148,   200,   482,   151,   205,   159,   608,    27,    85,   202,
       3,     4,     5,     6,     7,     8,     9,    10,   287,    12,
      13,   539,   293,   451,   434,   521,    -1,    -1,   438,    -1,
     203,   405,    -1,    -1,   204,    -1,    -1,    -1,    -1,     3,
      -1,    34,   555,   453,    -1,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,   242,   243,   411,   245,
      53,    -1,   415,    -1,    -1,   418,    37,    38,    39,    40,
      -1,    -1,   258,    -1,    38,    39,    40,    48,    71,   265,
      -1,    -1,    53,    -1,    48,    56,    57,    -1,    -1,    53,
      -1,    -1,    85,    -1,    -1,   608,    -1,    -1,   451,    -1,
      71,    -1,   455,    -1,    -1,   458,   516,    71,   461,    -1,
      -1,    -1,    -1,   466,    85,    -1,    -1,   470,    -1,   112,
     113,    85,    -1,    -1,    -1,   118,   119,   120,   121,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,    -1,
     111,   134,    -1,   114,   115,   116,    -1,    -1,   141,   142,
      -1,   144,   123,    -1,   118,   119,    -1,    -1,    -1,   152,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   520,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,   140,    -1,   149,   143,
     144,    48,    -1,   369,   148,   371,    53,   151,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,   606,    -1,    -1,    38,
      39,    40,   555,    -1,    71,   558,    38,    39,    40,    48,
      -1,    -1,    -1,    -1,    53,    -1,    48,    -1,    85,   405,
      -1,    53,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    71,    12,    13,    -1,    -1,    -1,    -1,    71,
      -1,    -1,    -1,   596,   111,    -1,    85,   114,    -1,    -1,
      -1,    -1,    -1,    85,   607,    34,    -1,   610,   611,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    46,   100,    -1,
      -1,    -1,    -1,    -1,    53,    -1,     3,     4,     5,     6,
       7,     8,     9,    10,   151,    12,    13,   640,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    85,    34,    -1,    48,
      -1,    38,    39,    40,    53,    -1,    -1,    56,    57,    46,
     506,    38,    39,    40,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    48,    71,   112,   113,    -1,    53,    -1,    -1,   118,
     119,   120,   121,    -1,    71,    -1,    85,    -1,    -1,   128,
     129,   130,    -1,    -1,    71,   134,    -1,    -1,    85,    -1,
      -1,    -1,   141,   142,    -1,   144,    -1,    -1,    85,    -1,
      -1,    -1,   111,   152,    -1,   114,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,    -1,    -1,    -1,   134,    -1,    -1,
      -1,    -1,   151,    -1,   141,   142,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    85,    34,
      -1,    48,    -1,    38,    39,    40,    53,    -1,    -1,    56,
      57,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    71,   112,   113,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    71,    -1,    85,    -1,
      -1,   128,   129,   130,    -1,    -1,    -1,   134,    -1,    -1,
      85,    -1,    -1,    -1,   141,   142,    -1,   144,    38,    39,
      40,    -1,    -1,    -1,   111,   152,    -1,   114,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,   112,   113,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,    -1,
      -1,    71,    -1,   128,   129,   130,    -1,    -1,    -1,   134,
      -1,    -1,    -1,    -1,   151,    85,   141,   142,    -1,   144,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
      -1,    -1,    -1,    -1,    -1,   115,   116,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    34,
      -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
     150,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      46,    12,    13,    -1,    -1,    -1,    71,    53,    -1,    -1,
      -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    71,   112,   113,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,    -1,
      85,    -1,    -1,   128,   129,   130,   112,   113,    -1,   134,
      -1,    -1,   118,   119,   120,   121,   141,   142,    -1,   144,
      -1,    -1,   128,   129,   130,    -1,   111,   152,   134,   114,
      -1,    -1,    -1,    -1,    -1,   141,   142,    -1,   144,    -1,
      -1,   112,   113,    -1,    -1,   151,    -1,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,     0,    -1,   128,   129,   130,
      -1,    -1,    -1,   134,    -1,    -1,   151,    -1,    -1,    -1,
     141,   142,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
     151,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    38,    39,    40,    53,    -1,
       3,    56,    57,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    46,    -1,    71,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      85,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    56,    57,    -1,   111,    -1,    -1,   114,
     115,   116,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,   126,   115,   116,    -1,    -1,    -1,    -1,    -1,    -1,
     112,   113,    85,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,    38,    39,    40,    -1,    -1,   128,   129,   130,     3,
      -1,    48,   134,    -1,    -1,    -1,    53,   150,   111,   141,
     142,   114,   144,    -1,    -1,   118,   119,    -1,   121,   151,
      -1,    -1,    -1,    -1,    71,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,     3,    85,    -1,
     143,   144,    -1,   146,    48,   148,    -1,    -1,   151,    53,
      -1,    -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,   115,   116,
      -1,    37,    38,    39,    40,    -1,    -1,    37,    38,    39,
      40,    85,    48,    -1,    -1,    -1,    -1,    53,    48,    -1,
      56,    57,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,
      -1,    -1,    -1,   150,    -1,    71,    -1,   111,    -1,    -1,
     114,    71,    -1,    -1,   118,   119,    -1,   121,    -1,    85,
      -1,    -1,     3,    -1,    -1,    85,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,   146,    -1,   148,   111,    -1,   151,   114,    -1,
      -1,   111,   118,   119,   114,   121,    37,    38,    39,    40,
       3,    -1,    -1,    -1,   130,    -1,     3,    48,    -1,    -1,
     130,    -1,    53,    -1,    -1,    56,    57,   143,   144,    -1,
     146,    -1,   148,   143,   144,   151,    -1,    -1,    -1,    -1,
      71,   151,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      37,    38,    39,    40,    85,    48,    -1,    -1,    -1,    -1,
      53,    48,    -1,    56,    57,    -1,    53,    -1,    -1,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
     111,    -1,    -1,   114,    71,    -1,    -1,   118,   119,    -1,
     121,    -1,    85,    -1,    -1,    -1,    -1,    -1,    85,   130,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   143,   144,    -1,   146,    -1,   148,   111,    -1,
     151,   114,    -1,    -1,   111,   118,   119,   114,   121,    -1,
      -1,   118,   119,     3,   121,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
     143,   144,    -1,   146,    -1,   148,   143,   144,   151,   146,
      -1,   148,    -1,    -1,   151,    -1,    -1,    37,    38,    39,
      40,     3,    -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,    38,
      39,    40,    -1,    -1,    37,    38,    39,    40,    41,    48,
      -1,    71,    -1,    -1,    53,    48,    38,    39,    40,    -1,
      53,    -1,    -1,    56,    57,    85,    48,    -1,    -1,    -1,
      -1,    53,    71,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    71,
      -1,   111,    85,    -1,   114,    -1,    -1,    -1,   118,   119,
      -1,   121,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,   115,   116,   111,    -1,
      -1,   114,    -1,   143,   144,    -1,   146,    -1,   148,    -1,
      -1,   151,    -1,    -1,    -1,    -1,   118,   119,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,   130,    12,
      13,   150,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,   143,   144,    -1,    -1,    -1,   148,    -1,    -1,   151,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    42,
      -1,    -1,    -1,    46,    -1,    48,    37,    38,    39,    40,
      53,    42,    -1,    56,    57,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    56,    57,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    99,   100,   101,    -1,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,    -1,   118,   119,   120,   121,    -1,
     111,    -1,    -1,   114,    -1,   128,   129,   130,    -1,    -1,
      -1,   134,    -1,   124,   125,    -1,    -1,    -1,   141,   142,
      -1,   144,    -1,    -1,    -1,   148,   149,   150,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,   150,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    56,
      57,    -1,    37,    38,    39,    40,    -1,    42,    -1,    -1,
      -1,    46,    -1,    48,    71,    -1,    -1,    -1,    53,    -1,
      -1,    56,    57,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      85,    -1,    -1,    -1,   111,    -1,    -1,   114,   115,   116,
      -1,    -1,    -1,    -1,    99,   100,   101,    -1,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,    46,   118,   119,   120,   121,    -1,    -1,    53,
      -1,    -1,   149,   128,   129,   130,    -1,    -1,    -1,   134,
      -1,    -1,    -1,    -1,    -1,    -1,   141,   142,    -1,   144,
      -1,    -1,    -1,   148,   149,   150,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,
      46,    -1,    -1,    -1,   128,   129,   130,    53,     0,    -1,
     134,    -1,    -1,    -1,    -1,    -1,    -1,   141,   142,   143,
     144,   145,    -1,    -1,    -1,   149,   150,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    57,   112,   113,    -1,    -1,
      46,    -1,   118,   119,   120,   121,    -1,    53,    -1,    71,
      -1,    -1,   128,   129,   130,    -1,    -1,    -1,   134,    -1,
      -1,    -1,    -1,    85,    -1,   141,   142,   143,   144,   145,
      -1,    -1,    -1,   149,   150,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,   111,
      -1,    -1,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   126,    -1,   112,   113,    -1,    -1,
      -1,    -1,   118,   119,   120,   121,    -1,    -1,    46,    -1,
      -1,    -1,   128,   129,   130,    53,    -1,    -1,   134,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   142,   143,   144,   145,
      -1,    -1,    -1,   149,     3,     4,     5,     6,     7,     8,
       9,    10,    -1,    12,    13,    37,    38,    39,    40,    -1,
      42,    37,    38,    39,    40,    -1,    48,    -1,    -1,    -1,
      -1,    53,    48,    -1,    56,    57,    -1,    53,    -1,    -1,
      56,    57,    -1,    -1,   112,   113,    -1,    46,    -1,    71,
     118,   119,   120,   121,    53,    71,    -1,    -1,    -1,    -1,
     128,   129,   130,    85,    -1,    -1,   134,    -1,    -1,    85,
      -1,    -1,    -1,   141,   142,    -1,   144,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
      -1,    -1,   114,    -1,    -1,   111,    -1,    -1,   114,    -1,
      -1,    -1,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   112,   113,    -1,    -1,    -1,    -1,   118,
     119,   120,   121,    -1,    -1,    -1,    -1,    -1,   150,   128,
     129,   130,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,
      -1,    -1,   141,   142,    -1,   144,    -1,    -1,    -1,    -1,
     149,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    57,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    71,
      -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    56,    57,    -1,    42,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    71,    -1,   111,
     112,   113,   114,   115,   116,    -1,   118,   119,   120,   121,
      -1,    85,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,
      -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,   141,
     142,    -1,   144,    -1,    -1,    -1,   148,   111,    -1,    -1,
     114,    -1,    99,   100,   101,    -1,   103,   104,   105,   106,
     107,   108,   109,   110,    -1,   112,   113,    -1,    -1,    -1,
      -1,   118,   119,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,    -1,    -1,    -1,   134,    -1,    -1,
      -1,    -1,    -1,    -1,   141,   142,    -1,   144,    -1,    -1,
       8,   148,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    53,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,   117,
      -1,   112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,
     138,    -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,    -1,
     141,   142,    -1,   144,    -1,    -1,    -1,   148,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    12,
      13,    -1,   112,   113,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,   134,    38,    39,    40,    -1,    -1,
      -1,   141,   142,    46,   144,    48,    -1,    -1,   148,    -1,
      53,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
     113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,    71,
      -1,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,    -1,
      -1,   134,    -1,    85,    -1,    -1,    -1,    -1,   141,   142,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    -1,    12,    13,    -1,
     112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,   121,
      -1,    -1,    -1,    -1,    -1,    -1,   128,   129,   130,    -1,
      -1,    -1,   134,    38,    39,    40,    -1,    -1,    -1,   141,
     142,    46,   144,    48,    -1,    -1,    -1,    -1,    53,     3,
       4,     5,     6,     7,     8,     9,    10,    -1,    12,    13,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,   113,    -1,
      -1,    -1,    -1,   118,   119,   120,   121,    71,    -1,    -1,
      -1,    -1,    -1,   128,   129,   130,    -1,    -1,    -1,   134,
      -1,    85,    -1,    -1,    -1,    -1,   141,   142,    -1,   144,
      -1,    -1,     3,     4,     5,     6,     7,     8,     9,    10,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,   112,   113,
      -1,    -1,    -1,    -1,   118,   119,   120,   121,    -1,    -1,
      -1,    -1,    -1,    -1,   128,   129,   130,    38,    39,    40,
     134,    -1,    -1,    -1,    -1,    46,    -1,   141,   142,    -1,
     144,    -1,    53,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    46,    -1,    48,    -1,
      -1,    48,    -1,    53,    -1,    -1,    53,    -1,    -1,    56,
      57,   112,   113,    -1,    -1,    -1,    -1,   118,   119,   120,
     121,    -1,    -1,    -1,    71,    -1,    -1,   128,   129,   130,
      -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    85,    -1,
     141,   142,    -1,   144,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,   112,   113,   111,    -1,    -1,   114,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,   134,    -1,    -1,    -1,    46,    -1,
      48,   141,   142,    -1,   144,    53,     3,     4,     5,     6,
       7,     8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    48,    -1,    53,    -1,    -1,    53,
      -1,    -1,    56,    57,   112,   113,    -1,    -1,    46,    -1,
     118,   119,   120,   121,    -1,    53,    -1,    71,    -1,    -1,
     128,   129,   130,    -1,    -1,    -1,   134,    -1,    -1,    -1,
      -1,    85,    -1,   141,   142,    -1,   144,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    12,    13,    -1,   112,   113,   111,    -1,    -1,
     114,   118,   119,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,   130,   112,   113,    -1,   134,    -1,    -1,
     118,   119,   120,   121,   141,   142,    46,   144,    -1,    -1,
     128,   129,   130,    53,    -1,    -1,   134,    -1,    -1,    -1,
      -1,    -1,    -1,   141,   142,    -1,   144,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    -1,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    -1,
      -1,    -1,   112,   113,    -1,    -1,    -1,    -1,   118,   119,
     120,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,
     130,    -1,    -1,    -1,   134,    -1,    -1,    -1,    -1,    -1,
       8,   141,   142,    -1,   144,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,     3,    -1,    -1,    -1,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
     118,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    37,
      38,    39,    40,    53,    42,   117,    56,    57,    -1,    -1,
      48,    37,    38,    39,    40,    53,    42,    -1,    56,    57,
      -1,    71,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      56,    57,    -1,    71,    -1,    85,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,   111,    -1,    -1,   114,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,    -1,    -1,   114,    -1,     8,    -1,
     130,    -1,    -1,    -1,    -1,   111,   124,   125,   114,    -1,
      -1,    -1,    -1,   143,   144,    -1,    -1,    -1,   124,   125,
      -1,   151,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    37,    38,    39,    40,    42,    48,    53,    56,    57,
      71,    85,   111,   114,   115,   116,   126,   154,   155,   156,
     157,   159,   161,   187,   215,   216,   219,   220,   221,   222,
     223,   237,   238,   239,   242,   258,   144,   144,   144,     8,
      34,     0,   156,   130,   144,   217,   218,   219,   240,   241,
     244,     8,    32,    33,    34,    35,    36,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,   117,   224,   226,   232,   236,   221,   216,
     216,   216,   216,   216,   222,   223,     3,     4,     5,     6,
       7,     8,     9,    10,    12,    13,    46,   112,   113,   118,
     119,   120,   121,   128,   129,   130,   134,   141,   142,   144,
     173,   186,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   208,   209,
     210,   214,   219,   223,   229,   237,   242,   243,   250,   214,
     242,   214,   149,     8,   237,   244,   245,   219,   240,   146,
     148,     3,   148,   173,   123,   158,   160,   215,   216,   219,
     143,   144,   243,   241,   144,     3,     8,   149,   225,   149,
     225,   216,   216,   122,   145,   207,   144,   203,   144,   203,
     203,   144,   144,     8,     3,   188,   189,   191,   203,   250,
      21,   139,    20,   133,   135,   134,    18,    19,    16,    17,
     136,   137,    14,    15,   128,   129,   130,   131,   132,   202,
      11,    12,    13,   143,   144,   145,   151,   229,   242,   143,
     144,   244,   251,   252,   229,   202,   223,   151,   146,   151,
     146,   151,   124,   125,   162,   163,   164,   168,   169,   170,
     174,   177,   180,   181,   182,   184,   187,   216,   149,   237,
     244,   151,   218,   240,   188,   149,   262,   262,   160,   138,
      34,   130,   152,   189,   245,   151,   216,   219,   246,   247,
     248,   249,   250,     3,   233,   234,   235,   149,   150,   227,
     228,   229,   258,   149,     3,   120,   250,   250,   250,   189,
     146,   151,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,   138,   190,   151,   193,   188,   194,   195,   196,
     197,   198,   198,   199,   199,   199,   199,   200,   200,   201,
     201,   202,   202,   202,     3,   173,   188,   151,   189,   213,
       3,   173,    34,   130,   152,   189,   245,   151,   246,   251,
     252,   143,   144,   229,     4,   148,     4,   148,   216,   216,
     150,   164,     3,   121,   171,   172,   183,   185,   244,   125,
     165,   166,   167,   168,   169,   170,   174,   177,   180,   182,
     184,   187,   219,   148,     3,    99,   100,   101,   103,   104,
     105,   106,   107,   108,   109,   110,   148,   150,   187,   188,
     215,   242,   259,   260,   261,   263,   264,   265,   266,   267,
     268,   149,   189,   253,   189,   245,   152,   152,    34,   130,
     152,   189,   144,   240,   244,   251,     3,   151,   146,   146,
     151,   151,   146,   150,   138,   233,   150,   228,   140,   219,
     230,   231,   240,   150,   227,   151,   151,   151,   146,   189,
     189,   149,   202,   140,   152,   146,   151,   189,   245,   152,
     152,    34,   152,   189,   151,   151,    34,   130,   152,   189,
     245,   151,   246,   151,   151,     3,   175,   176,   244,     3,
     178,   179,   244,   144,   144,   123,   219,   262,   123,   148,
     262,   123,   148,   262,   120,   172,   216,   150,   167,   140,
     214,   140,   144,   144,   144,   259,   144,     3,   148,   148,
     148,   188,   148,   262,   150,   264,   143,   145,   253,   254,
     255,   256,   257,   152,   189,   189,   152,   152,   219,    41,
     248,   219,   150,   234,   214,   146,   150,   214,   148,   146,
     148,   219,   150,   100,   211,   212,   250,   254,   191,   189,
     152,   189,   189,   152,   189,   245,   152,   152,    34,   152,
     189,   151,   148,   148,   144,   123,   148,   262,   176,   144,
     123,   148,   262,   179,   151,   246,   151,   188,   148,   188,
     188,   144,   178,   259,   140,   259,   188,   188,   188,   104,
     215,   265,   148,   148,   214,     3,   146,   150,   253,   138,
     257,   152,   152,     3,   150,   231,   140,   140,   146,   151,
     140,   146,   150,   152,   152,   152,   189,   189,   152,   151,
     188,   248,   188,    38,   151,   148,   148,   148,   151,   246,
     259,   151,   151,   151,   144,   265,   265,   152,   150,   253,
     255,   214,   189,   212,   189,   150,   152,   152,    38,   148,
     151,   148,    38,   151,   259,   259,   259,   188,   151,   188,
     151,   188,   253,    38,   102,   151,   259,   151,   259,   151,
     259,   148,   259,   259
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   153,   154,   154,   155,   155,   156,   156,   156,   156,
     156,   157,   158,   157,   159,   160,   160,   161,   161,   162,
     162,   163,   163,   164,   164,   164,   164,   164,   164,   164,
     164,   164,   164,   165,   165,   166,   166,   167,   167,   167,
     167,   167,   167,   167,   167,   167,   168,   169,   170,   171,
     171,   172,   172,   172,   172,   173,   173,   174,   174,   175,
     175,   176,   176,   177,   177,   178,   178,   179,   179,   180,
     181,   182,   182,   182,   183,   183,   184,   184,   184,   185,
     186,   186,   187,   188,   188,   189,   189,   190,   190,   190,
     190,   190,   190,   190,   190,   190,   190,   190,   191,   191,
     192,   192,   193,   193,   194,   194,   195,   195,   196,   196,
     197,   197,   197,   198,   198,   198,   198,   198,   199,   199,
     199,   200,   200,   200,   201,   201,   201,   201,   202,   202,
     203,   203,   203,   203,   203,   203,   203,   203,   204,   204,
     204,   204,   204,   204,   205,   205,   205,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   207,   207,
     208,   208,   208,   209,   209,   210,   211,   211,   212,   212,
     213,   213,   214,   215,   215,   215,   216,   216,   216,   216,
     216,   216,   216,   216,   216,   216,   216,   216,   216,   216,
     217,   217,   218,   218,   219,   219,   220,   220,   221,   222,
     222,   222,   222,   222,   222,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   224,   224,   224,   224,   224,   225,   225,   226,   226,
     227,   227,   228,   228,   228,   229,   229,   229,   229,   229,
     229,   230,   230,   231,   231,   231,   232,   232,   232,   232,
     232,   233,   233,   234,   234,   235,   236,   237,   237,   237,
     237,   237,   238,   238,   238,   238,   239,   239,   240,   240,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   242,   243,   244,   244,
     244,   244,   245,   245,   246,   246,   247,   247,   248,   248,
     248,   249,   249,   250,   250,   251,   251,   251,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   253,
     253,   253,   254,   254,   254,   254,   255,   256,   256,   257,
     257,   258,   258,   258,   258,   259,   260,   259,   259,   259,
     259,   259,   259,   261,   261,   261,   262,   262,   263,   263,
     264,   264,   265,   265,   266,   266,   266,   267,   267,   267,
     267,   267,   267,   268,   268,   268,   268,   268
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
       6,     3,     3,     5,     4,     5,     3,     3,     5,     3,
       2,     1,     1,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     4,
       1,     2,     2,     2,     2,     4,     4,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     4,     3,     3,
       3,     3,     2,     2,     6,     7,     1,     1,     1,     3,
       1,     1,     2,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     1,     3,     3,     3,
       1,     3,     1,     3,     3,     1,     2,     1,     3,     2,
       3,     2,     2,     1,     2,     1,     2,     1,     2,     1,
       1,     3,     4,     2,     0,     1,     1,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     3,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     2,     3,     3,     1,     2,     1,     3,     2,     2,
       1,     1,     3,     2,     4,     2,     4,     5,     5,     6,
       2,     1,     3,     3,     1,     1,     4,     1,     1,     1,
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
static const yytype_int8 yyconflp[] =
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    71,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,     0,     0,     0,     0,
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
     123,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       1,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,     5,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    21,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   111,     0,     0,     0,
       0,     0,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     105,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,    83,     0,     0,     0,     0,     0,    79,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     101,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,   121,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    99,
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

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   204,     0,   204,     0,   187,     0,   204,     0,   193,
       0,   204,     0,   195,     0,   204,     0,   197,     0,   204,
       0,   199,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   189,     0,   204,     0,   191,     0,   204,     0,   204,
       0,   204,     0,   256,     0,   204,     0,   260,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   258,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   385,     0
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
#line 596 "parser.y"
        { ast_root = ((*yyvalp).node) = NULL; }
#line 2846 "parser.tab.c"
    break;

  case 3:
#line 598 "parser.y"
        { ast_root = ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2852 "parser.tab.c"
    break;

  case 4:
#line 603 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2858 "parser.tab.c"
    break;

  case 5:
#line 605 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 2864 "parser.tab.c"
    break;

  case 6:
#line 610 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2870 "parser.tab.c"
    break;

  case 7:
#line 612 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2876 "parser.tab.c"
    break;

  case 8:
#line 614 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2882 "parser.tab.c"
    break;

  case 9:
#line 617 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2888 "parser.tab.c"
    break;

  case 10:
#line 625 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2894 "parser.tab.c"
    break;

  case 11:
#line 630 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2900 "parser.tab.c"
    break;

  case 12:
#line 632 "parser.y"
        { symbol_table_push_scope(); }
#line 2906 "parser.tab.c"
    break;

  case 13:
#line 634 "parser.y"
        { symbol_table_pop_scope(); ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 2912 "parser.tab.c"
    break;

  case 14:
#line 654 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 2918 "parser.tab.c"
    break;

  case 15:
#line 659 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2924 "parser.tab.c"
    break;

  case 16:
#line 661 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 2930 "parser.tab.c"
    break;

  case 17:
#line 673 "parser.y"
        { ((*yyvalp).node) = create_impl_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 2936 "parser.tab.c"
    break;

  case 18:
#line 675 "parser.y"
        { ((*yyvalp).node) = create_static_impl_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 2942 "parser.tab.c"
    break;

  case 19:
#line 683 "parser.y"
                 { ((*yyvalp).node) = NULL; }
#line 2948 "parser.tab.c"
    break;

  case 20:
#line 684 "parser.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2954 "parser.tab.c"
    break;

  case 21:
#line 689 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2960 "parser.tab.c"
    break;

  case 22:
#line 691 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 2966 "parser.tab.c"
    break;

  case 23:
#line 696 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2972 "parser.tab.c"
    break;

  case 24:
#line 698 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2978 "parser.tab.c"
    break;

  case 25:
#line 700 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2984 "parser.tab.c"
    break;

  case 26:
#line 702 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2990 "parser.tab.c"
    break;

  case 27:
#line 704 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2996 "parser.tab.c"
    break;

  case 28:
#line 706 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3002 "parser.tab.c"
    break;

  case 29:
#line 708 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3008 "parser.tab.c"
    break;

  case 30:
#line 710 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3014 "parser.tab.c"
    break;

  case 31:
#line 712 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3020 "parser.tab.c"
    break;

  case 32:
#line 714 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3026 "parser.tab.c"
    break;

  case 33:
#line 719 "parser.y"
                 { ((*yyvalp).node) = NULL; }
#line 3032 "parser.tab.c"
    break;

  case 34:
#line 720 "parser.y"
                                   { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3038 "parser.tab.c"
    break;

  case 35:
#line 725 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3044 "parser.tab.c"
    break;

  case 36:
#line 727 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3050 "parser.tab.c"
    break;

  case 37:
#line 732 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3056 "parser.tab.c"
    break;

  case 38:
#line 734 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3062 "parser.tab.c"
    break;

  case 39:
#line 736 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3068 "parser.tab.c"
    break;

  case 40:
#line 738 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3074 "parser.tab.c"
    break;

  case 41:
#line 740 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3080 "parser.tab.c"
    break;

  case 42:
#line 742 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3086 "parser.tab.c"
    break;

  case 43:
#line 744 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3092 "parser.tab.c"
    break;

  case 44:
#line 746 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3098 "parser.tab.c"
    break;

  case 45:
#line 748 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3104 "parser.tab.c"
    break;

  case 46:
#line 755 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3110 "parser.tab.c"
    break;

  case 47:
#line 778 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3116 "parser.tab.c"
    break;

  case 48:
#line 783 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL, NULL); }
#line 3122 "parser.tab.c"
    break;

  case 49:
#line 788 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3128 "parser.tab.c"
    break;

  case 50:
#line 790 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3134 "parser.tab.c"
    break;

  case 51:
#line 795 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3140 "parser.tab.c"
    break;

  case 52:
#line 797 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 3146 "parser.tab.c"
    break;

  case 53:
#line 805 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (void *) & const_node); }
#line 3152 "parser.tab.c"
    break;

  case 54:
#line 807 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (void *) & const_node); }
#line 3158 "parser.tab.c"
    break;

  case 55:
#line 826 "parser.y"
               { ((*yyvalp).node) = (void *) & this_node; }
#line 3164 "parser.tab.c"
    break;

  case 56:
#line 827 "parser.y"
               { ((*yyvalp).node) = (void *) & self_node; }
#line 3170 "parser.tab.c"
    break;

  case 57:
#line 832 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3176 "parser.tab.c"
    break;

  case 58:
#line 840 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3182 "parser.tab.c"
    break;

  case 59:
#line 849 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3188 "parser.tab.c"
    break;

  case 60:
#line 851 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3194 "parser.tab.c"
    break;

  case 61:
#line 856 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 3200 "parser.tab.c"
    break;

  case 62:
#line 858 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (void *) & const_node); }
#line 3206 "parser.tab.c"
    break;

  case 63:
#line 863 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3212 "parser.tab.c"
    break;

  case 64:
#line 871 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3218 "parser.tab.c"
    break;

  case 65:
#line 880 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3224 "parser.tab.c"
    break;

  case 66:
#line 882 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3230 "parser.tab.c"
    break;

  case 67:
#line 887 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3236 "parser.tab.c"
    break;

  case 68:
#line 889 "parser.y"
        { ((*yyvalp).node) = (void *) & error_node; fprintf(stderr, "'setter' functions cannot be 'const'!\n"); exit(EXIT_FAILURE); }
#line 3242 "parser.tab.c"
    break;

  case 69:
#line 894 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3248 "parser.tab.c"
    break;

  case 70:
#line 903 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3254 "parser.tab.c"
    break;

  case 71:
#line 936 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3260 "parser.tab.c"
    break;

  case 72:
#line 938 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3266 "parser.tab.c"
    break;

  case 73:
#line 940 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3272 "parser.tab.c"
    break;

  case 74:
#line 949 "parser.y"
        { ((*yyvalp).node) = create_new_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 3278 "parser.tab.c"
    break;

  case 75:
#line 951 "parser.y"
        { ((*yyvalp).node) = create_new_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3284 "parser.tab.c"
    break;

  case 76:
#line 957 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3290 "parser.tab.c"
    break;

  case 77:
#line 960 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3296 "parser.tab.c"
    break;

  case 78:
#line 963 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3302 "parser.tab.c"
    break;

  case 79:
#line 968 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node(NULL, NULL, NULL); }
#line 3308 "parser.tab.c"
    break;

  case 80:
#line 1036 "parser.y"
        { ((*yyvalp).node) = create_function_call_node(create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), (void *) & delete_as_id_node), NULL); }
#line 3314 "parser.tab.c"
    break;

  case 81:
#line 1038 "parser.y"
        { ((*yyvalp).node) = (void *) & delete_as_id_node; }
#line 3320 "parser.tab.c"
    break;

  case 82:
#line 1060 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3326 "parser.tab.c"
    break;

  case 83:
#line 1076 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3332 "parser.tab.c"
    break;

  case 84:
#line 1078 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 3338 "parser.tab.c"
    break;

  case 85:
#line 1083 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3344 "parser.tab.c"
    break;

  case 86:
#line 1085 "parser.y"
        { ((*yyvalp).node) = create_binary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3350 "parser.tab.c"
    break;

  case 87:
#line 1089 "parser.y"
                     { ((*yyvalp).type) = AST_ASSIGN; }
#line 3356 "parser.tab.c"
    break;

  case 88:
#line 1090 "parser.y"
                     { ((*yyvalp).type) = AST_MUL_ASSIGN; }
#line 3362 "parser.tab.c"
    break;

  case 89:
#line 1091 "parser.y"
                     { ((*yyvalp).type) = AST_DIV_ASSIGN; }
#line 3368 "parser.tab.c"
    break;

  case 90:
#line 1092 "parser.y"
                     { ((*yyvalp).type) = AST_MOD_ASSIGN; }
#line 3374 "parser.tab.c"
    break;

  case 91:
#line 1093 "parser.y"
                     { ((*yyvalp).type) = AST_ADD_ASSIGN; }
#line 3380 "parser.tab.c"
    break;

  case 92:
#line 1094 "parser.y"
                     { ((*yyvalp).type) = AST_SUB_ASSIGN; }
#line 3386 "parser.tab.c"
    break;

  case 93:
#line 1095 "parser.y"
                     { ((*yyvalp).type) = AST_SHL_ASSIGN; }
#line 3392 "parser.tab.c"
    break;

  case 94:
#line 1096 "parser.y"
                     { ((*yyvalp).type) = AST_SHR_ASSIGN; }
#line 3398 "parser.tab.c"
    break;

  case 95:
#line 1097 "parser.y"
                     { ((*yyvalp).type) = AST_AND_ASSIGN; }
#line 3404 "parser.tab.c"
    break;

  case 96:
#line 1098 "parser.y"
                     { ((*yyvalp).type) = AST_XOR_ASSIGN; }
#line 3410 "parser.tab.c"
    break;

  case 97:
#line 1099 "parser.y"
                     { ((*yyvalp).type) = AST_OR_ASSIGN; }
#line 3416 "parser.tab.c"
    break;

  case 98:
#line 1105 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3422 "parser.tab.c"
    break;

  case 99:
#line 1107 "parser.y"
        { ((*yyvalp).node) = create_ternary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3428 "parser.tab.c"
    break;

  case 100:
#line 1112 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3434 "parser.tab.c"
    break;

  case 101:
#line 1114 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_OR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3440 "parser.tab.c"
    break;

  case 102:
#line 1119 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3446 "parser.tab.c"
    break;

  case 103:
#line 1121 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_AND, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3452 "parser.tab.c"
    break;

  case 104:
#line 1126 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3458 "parser.tab.c"
    break;

  case 105:
#line 1128 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_OR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3464 "parser.tab.c"
    break;

  case 106:
#line 1133 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3470 "parser.tab.c"
    break;

  case 107:
#line 1135 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_XOR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3476 "parser.tab.c"
    break;

  case 108:
#line 1140 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3482 "parser.tab.c"
    break;

  case 109:
#line 1142 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_AND, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3488 "parser.tab.c"
    break;

  case 110:
#line 1147 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3494 "parser.tab.c"
    break;

  case 111:
#line 1149 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_EQ, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3500 "parser.tab.c"
    break;

  case 112:
#line 1151 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3506 "parser.tab.c"
    break;

  case 113:
#line 1156 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3512 "parser.tab.c"
    break;

  case 114:
#line 1158 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_LT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3518 "parser.tab.c"
    break;

  case 115:
#line 1160 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_GT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3524 "parser.tab.c"
    break;

  case 116:
#line 1162 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_LE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3530 "parser.tab.c"
    break;

  case 117:
#line 1164 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_GE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3536 "parser.tab.c"
    break;

  case 118:
#line 1169 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3542 "parser.tab.c"
    break;

  case 119:
#line 1171 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SHL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3548 "parser.tab.c"
    break;

  case 120:
#line 1173 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SHR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3554 "parser.tab.c"
    break;

  case 121:
#line 1178 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3560 "parser.tab.c"
    break;

  case 122:
#line 1180 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ADD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3566 "parser.tab.c"
    break;

  case 123:
#line 1182 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SUB, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3572 "parser.tab.c"
    break;

  case 124:
#line 1187 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3578 "parser.tab.c"
    break;

  case 125:
#line 1189 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_MUL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3584 "parser.tab.c"
    break;

  case 126:
#line 1191 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_DIV, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3590 "parser.tab.c"
    break;

  case 127:
#line 1193 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_MOD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3596 "parser.tab.c"
    break;

  case 128:
#line 1207 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3602 "parser.tab.c"
    break;

  case 129:
#line 1211 "parser.y"
        { ((*yyvalp).node) = create_cast_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3608 "parser.tab.c"
    break;

  case 130:
#line 1216 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3614 "parser.tab.c"
    break;

  case 131:
#line 1218 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_PRE_INC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3620 "parser.tab.c"
    break;

  case 132:
#line 1220 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_PRE_DEC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3626 "parser.tab.c"
    break;

  case 133:
#line 1222 "parser.y"
        { ((*yyvalp).node) = create_unary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3632 "parser.tab.c"
    break;

  case 134:
#line 1224 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_SIZEOF_EXPR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3638 "parser.tab.c"
    break;

  case 135:
#line 1226 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_SIZEOF_TYPE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3644 "parser.tab.c"
    break;

  case 136:
#line 1228 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_ALIGNOF, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3650 "parser.tab.c"
    break;

  case 137:
#line 1235 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3656 "parser.tab.c"
    break;

  case 138:
#line 1239 "parser.y"
              { ((*yyvalp).type) = AST_ADDRESS_OF; }
#line 3662 "parser.tab.c"
    break;

  case 139:
#line 1240 "parser.y"
              { ((*yyvalp).type) = AST_DEREFERENCE; }
#line 3668 "parser.tab.c"
    break;

  case 140:
#line 1241 "parser.y"
              { ((*yyvalp).type) = AST_POSITIVE; }
#line 3674 "parser.tab.c"
    break;

  case 141:
#line 1242 "parser.y"
              { ((*yyvalp).type) = AST_NEGATIVE; }
#line 3680 "parser.tab.c"
    break;

  case 142:
#line 1243 "parser.y"
              { ((*yyvalp).type) = AST_BITWISE_NOT; }
#line 3686 "parser.tab.c"
    break;

  case 143:
#line 1244 "parser.y"
              { ((*yyvalp).type) = AST_LOGICAL_NOT; }
#line 3692 "parser.tab.c"
    break;

  case 144:
#line 1249 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3698 "parser.tab.c"
    break;

  case 145:
#line 1251 "parser.y"
        { ((*yyvalp).node) = create_array_subscript_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3704 "parser.tab.c"
    break;

  case 146:
#line 1253 "parser.y"
        { ((*yyvalp).node) = create_function_call_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 3710 "parser.tab.c"
    break;

  case 147:
#line 1255 "parser.y"
        { ((*yyvalp).node) = create_function_call_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3716 "parser.tab.c"
    break;

  case 148:
#line 1265 "parser.y"
        { ((*yyvalp).node) = create_member_access_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_THIS || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_SELF ? AST_MEMBER_ACCESS_POINTER : AST_MEMBER_ACCESS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3722 "parser.tab.c"
    break;

  case 149:
#line 1269 "parser.y"
        { ((*yyvalp).node) = create_member_access_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_THIS || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_SELF ? AST_MEMBER_ACCESS_POINTER : AST_MEMBER_ACCESS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3728 "parser.tab.c"
    break;

  case 150:
#line 1271 "parser.y"
        { ((*yyvalp).node) = create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3734 "parser.tab.c"
    break;

  case 151:
#line 1280 "parser.y"
        { ((*yyvalp).node) = create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3740 "parser.tab.c"
    break;

  case 152:
#line 1282 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_POST_INC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3746 "parser.tab.c"
    break;

  case 153:
#line 1284 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_POST_DEC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3752 "parser.tab.c"
    break;

  case 154:
#line 1287 "parser.y"
        { ((*yyvalp).node) = create_compound_literal_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3758 "parser.tab.c"
    break;

  case 155:
#line 1289 "parser.y"
        { ((*yyvalp).node) = create_compound_literal_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 3764 "parser.tab.c"
    break;

  case 156:
#line 1294 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3770 "parser.tab.c"
    break;

  case 157:
#line 1296 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3776 "parser.tab.c"
    break;

  case 158:
#line 1298 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3782 "parser.tab.c"
    break;

  case 159:
#line 1300 "parser.y"
        { ((*yyvalp).node) = create_expression_group_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3788 "parser.tab.c"
    break;

  case 160:
#line 1302 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3794 "parser.tab.c"
    break;

  case 161:
#line 1310 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3800 "parser.tab.c"
    break;

  case 162:
#line 1325 "parser.y"
        {
		sprintf(func_name, "%s__new", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id);
		((*yyvalp).node) = create_id_node(func_name);
	}
#line 3809 "parser.tab.c"
    break;

  case 163:
#line 1330 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NS_OP, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (void *) & new_as_id_node); }
#line 3815 "parser.tab.c"
    break;

  case 164:
#line 1332 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NS_OP, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3821 "parser.tab.c"
    break;

  case 165:
#line 1342 "parser.y"
        { ((*yyvalp).node) = (void *) & new_as_id_node; }
#line 3827 "parser.tab.c"
    break;

  case 166:
#line 1346 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3833 "parser.tab.c"
    break;

  case 167:
#line 1350 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3839 "parser.tab.c"
    break;

  case 170:
#line 1361 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3845 "parser.tab.c"
    break;

  case 171:
#line 1363 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3851 "parser.tab.c"
    break;

  case 172:
#line 1365 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3857 "parser.tab.c"
    break;

  case 173:
#line 1375 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3863 "parser.tab.c"
    break;

  case 174:
#line 1377 "parser.y"
        { ((*yyvalp).node) = (void *) & ___func__node; }
#line 3869 "parser.tab.c"
    break;

  case 175:
#line 1382 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 3875 "parser.tab.c"
    break;

  case 180:
#line 1397 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3881 "parser.tab.c"
    break;

  case 181:
#line 1399 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 3887 "parser.tab.c"
    break;

  case 182:
#line 1425 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3893 "parser.tab.c"
    break;

  case 183:
#line 1430 "parser.y"
        { ((*yyvalp).node) = create_declaration_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL); }
#line 3899 "parser.tab.c"
    break;

  case 184:
#line 1432 "parser.y"
        { ((*yyvalp).node) = create_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); register_typedef((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3905 "parser.tab.c"
    break;

  case 185:
#line 1445 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3911 "parser.tab.c"
    break;

  case 186:
#line 1451 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3917 "parser.tab.c"
    break;

  case 187:
#line 1453 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3923 "parser.tab.c"
    break;

  case 188:
#line 1455 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 3929 "parser.tab.c"
    break;

  case 189:
#line 1457 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3935 "parser.tab.c"
    break;

  case 190:
#line 1460 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 3941 "parser.tab.c"
    break;

  case 191:
#line 1462 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3947 "parser.tab.c"
    break;

  case 192:
#line 1465 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3953 "parser.tab.c"
    break;

  case 193:
#line 1467 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3959 "parser.tab.c"
    break;

  case 194:
#line 1470 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3965 "parser.tab.c"
    break;

  case 195:
#line 1472 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3971 "parser.tab.c"
    break;

  case 196:
#line 1475 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3977 "parser.tab.c"
    break;

  case 197:
#line 1477 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3983 "parser.tab.c"
    break;

  case 198:
#line 1480 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3989 "parser.tab.c"
    break;

  case 199:
#line 1482 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3995 "parser.tab.c"
    break;

  case 200:
#line 1487 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4001 "parser.tab.c"
    break;

  case 201:
#line 1489 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4007 "parser.tab.c"
    break;

  case 202:
#line 1494 "parser.y"
        { ((*yyvalp).node) = create_init_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4013 "parser.tab.c"
    break;

  case 203:
#line 1496 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4019 "parser.tab.c"
    break;

  case 204:
#line 1514 "parser.y"
                     { ((*yyvalp).node) = NULL; }
#line 4025 "parser.tab.c"
    break;

  case 205:
#line 1515 "parser.y"
                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4031 "parser.tab.c"
    break;

  case 206:
#line 1520 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4037 "parser.tab.c"
    break;

  case 207:
#line 1522 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4043 "parser.tab.c"
    break;

  case 208:
#line 1527 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4049 "parser.tab.c"
    break;

  case 209:
#line 1543 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & typedef_node); }
#line 4055 "parser.tab.c"
    break;

  case 210:
#line 1551 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & extern_node); }
#line 4061 "parser.tab.c"
    break;

  case 211:
#line 1555 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & static_node); }
#line 4067 "parser.tab.c"
    break;

  case 212:
#line 1557 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & thread_local_node); }
#line 4073 "parser.tab.c"
    break;

  case 213:
#line 1559 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & auto_node); }
#line 4079 "parser.tab.c"
    break;

  case 214:
#line 1561 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & register_node); }
#line 4085 "parser.tab.c"
    break;

  case 215:
#line 1572 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & void_node); }
#line 4091 "parser.tab.c"
    break;

  case 216:
#line 1574 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & char_node); }
#line 4097 "parser.tab.c"
    break;

  case 217:
#line 1576 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & short_node); }
#line 4103 "parser.tab.c"
    break;

  case 218:
#line 1578 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & int_node); }
#line 4109 "parser.tab.c"
    break;

  case 219:
#line 1580 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & long_node); }
#line 4115 "parser.tab.c"
    break;

  case 220:
#line 1582 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & float_node); }
#line 4121 "parser.tab.c"
    break;

  case 221:
#line 1584 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & double_node); }
#line 4127 "parser.tab.c"
    break;

  case 222:
#line 1586 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & signed_node); }
#line 4133 "parser.tab.c"
    break;

  case 223:
#line 1588 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & unsigned_node); }
#line 4139 "parser.tab.c"
    break;

  case 224:
#line 1590 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & bool_node); }
#line 4145 "parser.tab.c"
    break;

  case 225:
#line 1592 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & complex_node); }
#line 4151 "parser.tab.c"
    break;

  case 226:
#line 1594 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & imaginary_node); }
#line 4157 "parser.tab.c"
    break;

  case 227:
#line 1596 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4163 "parser.tab.c"
    break;

  case 228:
#line 1598 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4169 "parser.tab.c"
    break;

  case 229:
#line 1600 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4175 "parser.tab.c"
    break;

  case 230:
#line 1602 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4181 "parser.tab.c"
    break;

  case 231:
#line 1617 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & builtin_va_list_node); }
#line 4187 "parser.tab.c"
    break;

  case 232:
#line 1621 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___decimal32_node); }
#line 4193 "parser.tab.c"
    break;

  case 233:
#line 1623 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___decimal64_node); }
#line 4199 "parser.tab.c"
    break;

  case 234:
#line 1625 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___decimal128_node); }
#line 4205 "parser.tab.c"
    break;

  case 235:
#line 1628 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___float128_node); }
#line 4211 "parser.tab.c"
    break;

  case 236:
#line 1630 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___int128_node); }
#line 4217 "parser.tab.c"
    break;

  case 237:
#line 1632 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___int128_t_node); }
#line 4223 "parser.tab.c"
    break;

  case 238:
#line 1634 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___uint128_t_node); }
#line 4229 "parser.tab.c"
    break;

  case 239:
#line 1637 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___bitint128_node); }
#line 4235 "parser.tab.c"
    break;

  case 240:
#line 1639 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4241 "parser.tab.c"
    break;

  case 241:
#line 1644 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.type), NULL, NULL); }
#line 4247 "parser.tab.c"
    break;

  case 242:
#line 1646 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4253 "parser.tab.c"
    break;

  case 243:
#line 1653 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4259 "parser.tab.c"
    break;

  case 244:
#line 1655 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4265 "parser.tab.c"
    break;

  case 245:
#line 1658 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4271 "parser.tab.c"
    break;

  case 248:
#line 1669 "parser.y"
                 { ((*yyvalp).type) = AST_STRUCT; }
#line 4277 "parser.tab.c"
    break;

  case 249:
#line 1670 "parser.y"
                 { ((*yyvalp).type) = AST_UNION; }
#line 4283 "parser.tab.c"
    break;

  case 250:
#line 1675 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4289 "parser.tab.c"
    break;

  case 251:
#line 1677 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 4295 "parser.tab.c"
    break;

  case 252:
#line 1682 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declaration_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL); }
#line 4301 "parser.tab.c"
    break;

  case 253:
#line 1684 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4307 "parser.tab.c"
    break;

  case 254:
#line 1690 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4313 "parser.tab.c"
    break;

  case 255:
#line 1695 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4319 "parser.tab.c"
    break;

  case 256:
#line 1697 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4325 "parser.tab.c"
    break;

  case 257:
#line 1701 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 4331 "parser.tab.c"
    break;

  case 258:
#line 1703 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4337 "parser.tab.c"
    break;

  case 259:
#line 1708 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4343 "parser.tab.c"
    break;

  case 260:
#line 1710 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4349 "parser.tab.c"
    break;

  case 261:
#line 1715 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4355 "parser.tab.c"
    break;

  case 262:
#line 1717 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4361 "parser.tab.c"
    break;

  case 263:
#line 1722 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), NULL); }
#line 4367 "parser.tab.c"
    break;

  case 264:
#line 1725 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4373 "parser.tab.c"
    break;

  case 265:
#line 1728 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4379 "parser.tab.c"
    break;

  case 266:
#line 1733 "parser.y"
        { ((*yyvalp).node) = create_enum_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4385 "parser.tab.c"
    break;

  case 267:
#line 1736 "parser.y"
        { ((*yyvalp).node) = create_enum_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4391 "parser.tab.c"
    break;

  case 268:
#line 1739 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4397 "parser.tab.c"
    break;

  case 269:
#line 1742 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4403 "parser.tab.c"
    break;

  case 270:
#line 1745 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4409 "parser.tab.c"
    break;

  case 271:
#line 1750 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4415 "parser.tab.c"
    break;

  case 272:
#line 1752 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ",\n"); }
#line 4421 "parser.tab.c"
    break;

  case 273:
#line 1757 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ENUM_INIT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); symbol_add_enum_constant((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->id.id, ((*yyvalp).node)); }
#line 4427 "parser.tab.c"
    break;

  case 274:
#line 1760 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ENUM_INIT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); symbol_add_enum_constant((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id, ((*yyvalp).node)); }
#line 4433 "parser.tab.c"
    break;

  case 275:
#line 1764 "parser.y"
                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4439 "parser.tab.c"
    break;

  case 276:
#line 1770 "parser.y"
        { ((*yyvalp).node) = create_atomic_type_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4445 "parser.tab.c"
    break;

  case 277:
#line 1774 "parser.y"
                     { ((*yyvalp).node) = (void *) & const_node; }
#line 4451 "parser.tab.c"
    break;

  case 278:
#line 1775 "parser.y"
                     { ((*yyvalp).node) = (void *) & restrict_node; }
#line 4457 "parser.tab.c"
    break;

  case 279:
#line 1776 "parser.y"
                     { ((*yyvalp).node) = (void *) & ___restrict_node; }
#line 4463 "parser.tab.c"
    break;

  case 280:
#line 1777 "parser.y"
                     { ((*yyvalp).node) = (void *) & volatile_node; }
#line 4469 "parser.tab.c"
    break;

  case 281:
#line 1778 "parser.y"
                     { ((*yyvalp).node) = (void *) & atomic_node; }
#line 4475 "parser.tab.c"
    break;

  case 282:
#line 1782 "parser.y"
                        { ((*yyvalp).node) = (void *) & inline_node; }
#line 4481 "parser.tab.c"
    break;

  case 283:
#line 1783 "parser.y"
                        { ((*yyvalp).node) = (void *) & noreturn_node; }
#line 4487 "parser.tab.c"
    break;

  case 284:
#line 1785 "parser.y"
                        { ((*yyvalp).node) = (void *) & ___inline_node; }
#line 4493 "parser.tab.c"
    break;

  case 285:
#line 1786 "parser.y"
                        { ((*yyvalp).node) = (void *) & ___inline__node; }
#line 4499 "parser.tab.c"
    break;

  case 286:
#line 1791 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 4505 "parser.tab.c"
    break;

  case 287:
#line 1793 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 4511 "parser.tab.c"
    break;

  case 288:
#line 1798 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4517 "parser.tab.c"
    break;

  case 289:
#line 1800 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4523 "parser.tab.c"
    break;

  case 290:
#line 1805 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4529 "parser.tab.c"
    break;

  case 291:
#line 1808 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4535 "parser.tab.c"
    break;

  case 292:
#line 1811 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4541 "parser.tab.c"
    break;

  case 293:
#line 1813 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4547 "parser.tab.c"
    break;

  case 294:
#line 1815 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 4553 "parser.tab.c"
    break;

  case 295:
#line 1817 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4559 "parser.tab.c"
    break;

  case 296:
#line 1819 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4565 "parser.tab.c"
    break;

  case 297:
#line 1821 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4571 "parser.tab.c"
    break;

  case 298:
#line 1823 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4577 "parser.tab.c"
    break;

  case 299:
#line 1825 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4583 "parser.tab.c"
    break;

  case 300:
#line 1827 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4589 "parser.tab.c"
    break;

  case 301:
#line 1829 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4595 "parser.tab.c"
    break;

  case 302:
#line 1840 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 4601 "parser.tab.c"
    break;

  case 303:
#line 1842 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 4607 "parser.tab.c"
    break;

  case 304:
#line 1844 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4613 "parser.tab.c"
    break;

  case 305:
#line 1851 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4619 "parser.tab.c"
    break;

  case 306:
#line 1858 "parser.y"
                        { ((*yyvalp).node) = (void *) & ___extension___node; }
#line 4625 "parser.tab.c"
    break;

  case 307:
#line 1864 "parser.y"
                  { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4631 "parser.tab.c"
    break;

  case 308:
#line 1870 "parser.y"
        { ((*yyvalp).node) = create_pointer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4637 "parser.tab.c"
    break;

  case 309:
#line 1872 "parser.y"
        { ((*yyvalp).node) = create_pointer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4643 "parser.tab.c"
    break;

  case 310:
#line 1874 "parser.y"
        { ((*yyvalp).node) = create_pointer_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4649 "parser.tab.c"
    break;

  case 311:
#line 1876 "parser.y"
        { ((*yyvalp).node) = (void *) & pointer_node; }
#line 4655 "parser.tab.c"
    break;

  case 312:
#line 1881 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4661 "parser.tab.c"
    break;

  case 313:
#line 1883 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), " "); }
#line 4667 "parser.tab.c"
    break;

  case 314:
#line 1888 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (void *) & ellipsis_node, ", "); }
#line 4673 "parser.tab.c"
    break;

  case 315:
#line 1890 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4679 "parser.tab.c"
    break;

  case 316:
#line 1895 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4685 "parser.tab.c"
    break;

  case 317:
#line 1897 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4691 "parser.tab.c"
    break;

  case 318:
#line 1902 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4697 "parser.tab.c"
    break;

  case 319:
#line 1904 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4703 "parser.tab.c"
    break;

  case 320:
#line 1906 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4709 "parser.tab.c"
    break;

  case 321:
#line 1914 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4715 "parser.tab.c"
    break;

  case 322:
#line 1917 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), ", "); }
#line 4721 "parser.tab.c"
    break;

  case 323:
#line 1922 "parser.y"
        { ((*yyvalp).node) = create_abstract_type_name_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4727 "parser.tab.c"
    break;

  case 324:
#line 1924 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4733 "parser.tab.c"
    break;

  case 325:
#line 1929 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4739 "parser.tab.c"
    break;

  case 326:
#line 1931 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4745 "parser.tab.c"
    break;

  case 327:
#line 1933 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4751 "parser.tab.c"
    break;

  case 328:
#line 1939 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4757 "parser.tab.c"
    break;

  case 329:
#line 1941 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node(NULL, NULL); }
#line 4763 "parser.tab.c"
    break;

  case 330:
#line 1943 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node(NULL, NULL); }
#line 4769 "parser.tab.c"
    break;

  case 331:
#line 1945 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4775 "parser.tab.c"
    break;

  case 332:
#line 1947 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4781 "parser.tab.c"
    break;

  case 333:
#line 1949 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4787 "parser.tab.c"
    break;

  case 334:
#line 1951 "parser.y"
        { ((*yyvalp).node) = create_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4793 "parser.tab.c"
    break;

  case 335:
#line 1953 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4799 "parser.tab.c"
    break;

  case 336:
#line 1955 "parser.y"
        { ((*yyvalp).node) = create_array_node(NULL, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4805 "parser.tab.c"
    break;

  case 337:
#line 1957 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4811 "parser.tab.c"
    break;

  case 338:
#line 1959 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 4817 "parser.tab.c"
    break;

  case 339:
#line 1961 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4823 "parser.tab.c"
    break;

  case 340:
#line 1963 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4829 "parser.tab.c"
    break;

  case 341:
#line 1965 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4835 "parser.tab.c"
    break;

  case 342:
#line 1967 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4841 "parser.tab.c"
    break;

  case 343:
#line 1969 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4847 "parser.tab.c"
    break;

  case 344:
#line 1971 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4853 "parser.tab.c"
    break;

  case 345:
#line 1973 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node(NULL); }
#line 4859 "parser.tab.c"
    break;

  case 346:
#line 1975 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 4865 "parser.tab.c"
    break;

  case 347:
#line 1977 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 4871 "parser.tab.c"
    break;

  case 348:
#line 1979 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 4877 "parser.tab.c"
    break;

  case 349:
#line 1984 "parser.y"
        { ((*yyvalp).node) = create_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4883 "parser.tab.c"
    break;

  case 350:
#line 1986 "parser.y"
        { ((*yyvalp).node) = create_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4889 "parser.tab.c"
    break;

  case 351:
#line 1988 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4895 "parser.tab.c"
    break;

  case 352:
#line 1993 "parser.y"
        { ((*yyvalp).node) = create_designation_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4901 "parser.tab.c"
    break;

  case 353:
#line 1995 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4907 "parser.tab.c"
    break;

  case 354:
#line 1997 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_designation_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), ", "); }
#line 4913 "parser.tab.c"
    break;

  case 355:
#line 1999 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4919 "parser.tab.c"
    break;

  case 356:
#line 2004 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 4925 "parser.tab.c"
    break;

  case 357:
#line 2009 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4931 "parser.tab.c"
    break;

  case 358:
#line 2011 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4937 "parser.tab.c"
    break;

  case 359:
#line 2016 "parser.y"
        { ((*yyvalp).node) = create_designator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 4943 "parser.tab.c"
    break;

  case 360:
#line 2018 "parser.y"
        { ((*yyvalp).node) = create_designator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4949 "parser.tab.c"
    break;

  case 361:
#line 2034 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST__STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4955 "parser.tab.c"
    break;

  case 362:
#line 2036 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST__STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4961 "parser.tab.c"
    break;

  case 363:
#line 2038 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST_STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4967 "parser.tab.c"
    break;

  case 364:
#line 2040 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST_STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4973 "parser.tab.c"
    break;

  case 365:
#line 2044 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4979 "parser.tab.c"
    break;

  case 366:
#line 2046 "parser.y"
        { symbol_table_push_scope(); }
#line 4985 "parser.tab.c"
    break;

  case 367:
#line 2048 "parser.y"
        { symbol_table_pop_scope(); ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4991 "parser.tab.c"
    break;

  case 368:
#line 2049 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4997 "parser.tab.c"
    break;

  case 369:
#line 2050 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5003 "parser.tab.c"
    break;

  case 370:
#line 2051 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5009 "parser.tab.c"
    break;

  case 371:
#line 2052 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5015 "parser.tab.c"
    break;

  case 372:
#line 2054 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5021 "parser.tab.c"
    break;

  case 373:
#line 2059 "parser.y"
        { ((*yyvalp).node) = create_labeled_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5027 "parser.tab.c"
    break;

  case 374:
#line 2061 "parser.y"
        { ((*yyvalp).node) = create_case_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5033 "parser.tab.c"
    break;

  case 375:
#line 2063 "parser.y"
        { ((*yyvalp).node) = create_default_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5039 "parser.tab.c"
    break;

  case 376:
#line 2068 "parser.y"
        { ((*yyvalp).node) = create_block_node(NULL); }
#line 5045 "parser.tab.c"
    break;

  case 377:
#line 2072 "parser.y"
                {
			((*yyvalp).node) = create_block_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
		// symbol_table_pop_scope();
		}
#line 5054 "parser.tab.c"
    break;

  case 378:
#line 2081 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5060 "parser.tab.c"
    break;

  case 379:
#line 2083 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 5066 "parser.tab.c"
    break;

  case 380:
#line 2087 "parser.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5072 "parser.tab.c"
    break;

  case 381:
#line 2088 "parser.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5078 "parser.tab.c"
    break;

  case 382:
#line 2093 "parser.y"
        { ((*yyvalp).node) = create_expression_statement_node(NULL); }
#line 5084 "parser.tab.c"
    break;

  case 383:
#line 2095 "parser.y"
        { ((*yyvalp).node) = create_expression_statement_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5090 "parser.tab.c"
    break;

  case 384:
#line 2102 "parser.y"
        { ((*yyvalp).node) = create_if_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5096 "parser.tab.c"
    break;

  case 385:
#line 2104 "parser.y"
        { ((*yyvalp).node) = create_if_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 5102 "parser.tab.c"
    break;

  case 386:
#line 2106 "parser.y"
        { ((*yyvalp).node) = create_switch_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5108 "parser.tab.c"
    break;

  case 387:
#line 2111 "parser.y"
        { ((*yyvalp).node) = create_while_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5114 "parser.tab.c"
    break;

  case 388:
#line 2113 "parser.y"
        { ((*yyvalp).node) = create_do_while_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5120 "parser.tab.c"
    break;

  case 389:
#line 2115 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5126 "parser.tab.c"
    break;

  case 390:
#line 2117 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5132 "parser.tab.c"
    break;

  case 391:
#line 2119 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5138 "parser.tab.c"
    break;

  case 392:
#line 2121 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5144 "parser.tab.c"
    break;

  case 393:
#line 2125 "parser.y"
                                { ((*yyvalp).node) = create_goto_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5150 "parser.tab.c"
    break;

  case 394:
#line 2126 "parser.y"
                                { ((*yyvalp).node) = (void *) & continue_node; }
#line 5156 "parser.tab.c"
    break;

  case 395:
#line 2127 "parser.y"
                                { ((*yyvalp).node) = (void *) & break_node; }
#line 5162 "parser.tab.c"
    break;

  case 396:
#line 2128 "parser.y"
                                { ((*yyvalp).node) = (void *) & return_node; }
#line 5168 "parser.tab.c"
    break;

  case 397:
#line 2129 "parser.y"
                                { ((*yyvalp).node) = create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5174 "parser.tab.c"
    break;


#line 5178 "parser.tab.c"

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



#line 2132 "parser.y"

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
