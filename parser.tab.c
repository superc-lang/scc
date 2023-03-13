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
#include "print_ast_tree.h"
#include "symbol_table.h"
#include "scc.h"
#include "print_syntax.h"

extern int yylineno;
extern const char *yyfilename;

extern int error_count;
char func_name[512];

void yyerror(const char *s);
// void register_typedef(union ast_node *decl_specs, union ast_node *declarator);
static inline union ast_node *maybe_attributes(union ast_node *left, union ast_node *right);


#line 91 "parser.tab.c"

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4572

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  155
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  122
/* YYNRULES -- Number of rules.  */
#define YYNRULES  414
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  700
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 7
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token number (for yychar).  */
#define YYMAXUTOK   385
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
       2,     2,     2,   143,     2,     2,     2,   134,   136,     2,
     146,   153,   132,   130,   148,   131,   147,   133,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   142,   150,
     138,   140,   139,   141,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   145,     2,   154,   137,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   151,   135,   152,   144,     2,     2,     2,
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
     125,   126,   127,   128,   129,   149
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   620,   620,   622,   627,   629,   634,   636,   638,   641,
     650,   655,   658,   657,   679,   684,   686,   698,   700,   705,
     706,   710,   712,   717,   719,   721,   723,   725,   727,   729,
     731,   733,   735,   741,   742,   746,   748,   753,   755,   757,
     759,   761,   763,   765,   767,   769,   776,   799,   804,   809,
     811,   816,   818,   826,   828,   848,   849,   853,   861,   870,
     872,   877,   879,   884,   892,   901,   903,   908,   910,   915,
     924,   957,   959,   961,   970,   972,   978,   981,   984,   989,
    1057,  1059,  1081,  1097,  1099,  1104,  1106,  1111,  1112,  1113,
    1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1126,  1128,
    1133,  1135,  1140,  1142,  1147,  1149,  1154,  1156,  1161,  1163,
    1168,  1170,  1172,  1177,  1179,  1181,  1183,  1185,  1190,  1192,
    1194,  1199,  1201,  1203,  1208,  1210,  1212,  1214,  1228,  1232,
    1237,  1239,  1241,  1243,  1245,  1247,  1249,  1256,  1261,  1262,
    1263,  1264,  1265,  1266,  1270,  1272,  1274,  1276,  1286,  1290,
    1292,  1301,  1303,  1305,  1308,  1310,  1315,  1317,  1319,  1321,
    1323,  1332,  1341,  1346,  1348,  1351,  1354,  1357,  1362,  1363,
    1368,  1370,  1372,  1382,  1384,  1389,  1394,  1395,  1399,  1400,
    1404,  1406,  1432,  1437,  1439,  1452,  1458,  1460,  1462,  1464,
    1467,  1469,  1472,  1474,  1477,  1479,  1482,  1484,  1487,  1489,
    1494,  1496,  1501,  1503,  1522,  1523,  1527,  1529,  1534,  1550,
    1558,  1562,  1564,  1566,  1568,  1579,  1581,  1583,  1585,  1587,
    1589,  1591,  1593,  1595,  1597,  1599,  1601,  1603,  1605,  1607,
    1609,  1617,  1620,  1635,  1639,  1641,  1643,  1646,  1648,  1650,
    1652,  1655,  1657,  1664,  1666,  1668,  1670,  1672,  1675,  1681,
    1697,  1697,  1702,  1704,  1709,  1711,  1713,  1725,  1727,  1732,
    1737,  1739,  1741,  1783,  1784,  1789,  1790,  1794,  1796,  1801,
    1803,  1805,  1810,  1812,  1815,  1817,  1820,  1822,  1827,  1829,
    1834,  1837,  1840,  1845,  1848,  1851,  1854,  1857,  1862,  1864,
    1869,  1871,  1877,  1882,  1887,  1888,  1889,  1890,  1891,  1895,
    1896,  1898,  1899,  1903,  1905,  1910,  1912,  1917,  1920,  1923,
    1925,  1927,  1929,  1931,  1933,  1935,  1937,  1939,  1941,  1945,
    1947,  1949,  1956,  1964,  1970,  1975,  1977,  1979,  1981,  1986,
    1988,  1993,  1995,  2000,  2002,  2007,  2009,  2011,  2019,  2022,
    2027,  2029,  2034,  2036,  2038,  2044,  2046,  2048,  2050,  2052,
    2054,  2056,  2058,  2060,  2062,  2064,  2066,  2068,  2070,  2072,
    2074,  2076,  2078,  2080,  2082,  2084,  2089,  2091,  2093,  2098,
    2100,  2102,  2104,  2109,  2114,  2116,  2121,  2123,  2139,  2141,
    2143,  2145,  2150,  2152,  2152,  2155,  2156,  2157,  2158,  2160,
    2164,  2166,  2168,  2173,  2175,  2186,  2188,  2193,  2194,  2198,
    2200,  2207,  2209,  2211,  2216,  2218,  2220,  2222,  2224,  2226,
    2231,  2232,  2233,  2234,  2235
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "I_CONSTANT", "F_CONSTANT", "ENUMERATION_CONSTANT", "TYPEDEF_NAME",
  "GENERIC_TYPE", "GENERIC_NAME", "FUNC_NAME", "SIZEOF", "ARROW", "INC",
  "DEC", "SHL", "SHR", "LE", "GE", "EQ", "NE", "AND", "OR", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "SHL_ASSIGN",
  "SHR_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPEDEF",
  "EXTERN", "STATIC", "AUTO", "REGISTER", "INLINE", "CONST", "RESTRICT",
  "VOLATILE", "ELLIPSIS", "PRAGMA", "__ALIGNOF", "__ALIGNOF__", "__ASM",
  "__ASM__", "__ATTRIBUTE", "__ATTRIBUTE__", "__COMPLEX", "__COMPLEX__",
  "__CONST", "__CONST__", "__EXTENSION__", "__IMAG", "__IMAG__",
  "__INLINE", "__INLINE__", "__INTERATOR", "__INTERATOR__", "__LABEL__",
  "__REAL", "__REAL__", "__SIGNED", "__SIGNED__", "__TYPEOF", "__TYPEOF__",
  "__VOLATILE", "__VOLATILE__", "ASM", "TYPEOF", "__RESTRICT",
  "__AUTO_TYPE", "VOID", "CHAR", "SHORT", "INT", "LONG", "FLOAT", "DOUBLE",
  "SIGNED", "UNSIGNED", "BOOL", "COMPLEX", "IMAGINARY", "ATOMIC", "STRUCT",
  "UNION", "ENUM", "__BUILTIN_VA_LIST", "_DECIMAL32", "_DECIMAL64",
  "_DECIMAL128", "_FLOAT128", "__INT128", "__INT128_T", "__UINT128_T",
  "_BITINT128", "_BITINT", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH",
  "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "ALIGNAS",
  "ALIGNOF", "GENERIC", "NORETURN", "_STATIC_ASSERT", "STATIC_ASSERT",
  "THREAD_LOCAL", "THIS", "SELF", "NEW", "DELETE", "NS", "FAT_ARROW",
  "GET", "SET", "IMPL", "END_OF_FILE", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'|'", "'&'", "'^'", "'<'", "'>'", "'='", "'?'", "':'", "'!'", "'~'",
  "'['", "'('", "'.'", "','", "UNARY", "';'", "'{'", "'}'", "')'", "']'",
  "$accept", "translation_unit", "external_declarations",
  "external_declaration", "function_definition", "$@1",
  "fat_arrow_function_definition", "declaration_list", "impl_definition",
  "impl_body", "impl_declarations", "impl_declaration", "static_impl_body",
  "static_impl_declarations", "static_impl_declaration",
  "impl_fat_arrow_function_definition", "impl_function_definition",
  "impl_function_declaration", "impl_function_declarator",
  "impl_direct_declarator", "this_or_self", "getters", "getter_declarator",
  "getter_direct_declarator", "setters", "setter_declarator",
  "setter_direct_declarator", "getter_fat_arrow_definition",
  "setter_fat_arrow_definition", "new_function_definition",
  "new_function_declarator", "delete_function_definition",
  "delete_function_declarator", "delete_expression", "pragma",
  "expression", "assignment_expression", "assignment_operator",
  "conditional_expression", "logical_or_expression",
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
  "struct_or_union_specifier", "generic_declaration", "$@2",
  "generic_id_or_generic_name", "generic_id_list", "generic_specifier",
  "generic_specifier_qualifier_list", "identifier", "struct_or_union",
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
  "designator", "static_assert_declaration", "statement", "$@3",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", YY_NULLPTR
};
#endif

#define YYPACT_NINF (-555)
#define YYTABLE_NINF (-384)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2782,  -120,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
    -555,  -555,  -555,   -96,  -555,   -66,   -57,    51,    77,  4111,
    -555,  -555,  -555,  -555,  -555,  -555,   219,  4359,    45,  -555,
    1524,  1593,  -555,  1678,  1719,  1763,    43,  -555,   900,  3194,
    3710,  3710,   -30,   132,  -555,  -555,   366,   219,   -44,  -555,
      94,  3957,   195,   107,  -555,  -555,  -555,  -555,  -555,  -555,
    -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
    -555,  -555,  -555,   -11,  -555,  -555,    53,  -555,  -555,  -555,
    -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,    44,
    -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  1804,  1889,
    -555,  2446,  1930,   -65,  -555,  1974,    43,  -555,  -555,  -555,
    -555,  -555,   -82,  -555,  3729,  3748,  3748,  -555,     6,    32,
    -555,  -555,   229,   143,  -555,  -555,  -555,  -555,  -555,  -555,
    3213,  -555,  -555,  -555,    13,   238,   174,   130,   150,   352,
     162,   451,   342,   331,  -555,  -555,  3710,    95,  -555,  -555,
    -555,  -555,   172,   -29,  3539,  -555,   178,   -35,  3710,    -4,
    3856,   250,  -555,  -555,   366,   193,   202,   219,  -555,  -555,
    -555,  -555,  3710,   269,   269,  2262,   219,  4049,   748,   769,
    -555,   195,   925,  -555,  -555,   409,   273,   289,  -555,   649,
     286,   305,   310,  -555,  -555,  -555,  -555,  1531,  -555,  2015,
    -555,  -555,    19,  3357,  -555,  3376,  -555,  -555,  1618,  3710,
    -555,  -555,    73,  -555,  -555,   717,   339,  3710,  3710,  3710,
    3710,  3710,  3710,  3710,  3710,  3710,  3710,  3710,  3710,  3710,
    3710,  3710,  3710,  3710,  3710,  3710,  -555,   197,  -555,  -555,
    3710,  1326,   209,  -555,   922,  2635,   349,  -555,   354,  -555,
    -555,   454,   334,   498,   360,  2146,  3978,   373,  3877,  -555,
    -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
      41,  3898,  -555,  -555,  -555,  -555,    45,   101,  2134,  -555,
    -555,  -555,  2584,  3520,   364,  -555,   374,  1015,  -555,   215,
    4266,   382,   379,  -555,   127,   384,  -555,   -24,  -555,   398,
     409,  -555,   865,  -555,   303,  -555,  1507,  -555,   991,  -555,
    -555,  -555,  -555,   386,   387,   392,   403,  3710,  -555,  -555,
    -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,
    3710,  2654,   238,   -69,   174,   130,   150,   352,   162,   162,
     451,   451,   451,   451,   342,   342,   331,   331,  -555,  -555,
    -555,  -555,  -555,   -54,  -555,  -555,   142,  -555,  -555,  3520,
     399,  -555,   402,  1079,  -555,   393,   404,   354,  1172,  1848,
     406,  -555,   407,  -555,    38,    59,  -555,  -555,   419,   422,
     -13,  -555,   -59,   138,    37,  4421,   400,  3936,  -555,  -555,
    -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,   433,  -555,
     432,  3710,   435,   429,   436,   437,  2860,   438,   575,   431,
     439,  3008,  -555,  -555,  -555,   109,  -555,  3566,  -555,   269,
    -555,  2284,  -555,  -555,  -555,  -555,  -555,  2505,  -555,  -555,
     425,  3520,  -555,  -555,  3710,   440,  -555,   441,  2989,  -555,
     204,  -555,  -555,  -555,  3732,    45,  -555,  -555,    14,  -555,
    3710,   163,  -555,  -555,  3710,   126,   196,  -555,    45,  1225,
     471,  -555,  1379,   434,   434,  -555,   685,  -555,  -555,  2505,
    -555,  3710,  -555,  3710,  -555,   445,  3520,  -555,  -555,  3710,
    -555,   446,  -555,  -555,  3520,   448,  -555,   450,  1236,  -555,
     453,   442,   457,   444,   266,  -555,   583,   463,   327,  -555,
     608,  2872,   460,  3710,   464,  -555,  3710,  -555,  -555,  3710,
    -555,  -555,   470,  -555,    59,  -555,  -555,  2860,   475,  2860,
    3710,  3710,  3710,   512,  2803,   472,  -555,  -555,  -555,   208,
    -555,  -555,  -555,  -555,  3710,   617,  -555,   175,  2584,   158,
    -555,  -555,   467,   469,  -555,  -555,  4168,  -555,  -555,   621,
    -555,  -555,  -555,    25,  -555,  -555,  -555,   303,  -555,   483,
    -555,  -555,   -63,  -555,  -555,   484,   151,  -555,   486,   270,
    -555,  -555,  -555,   477,   479,  -555,   482,  3520,  -555,  -555,
    3710,  -555,   485,  -555,  -555,  -555,   476,  3710,  -555,  -555,
    -555,  4456,  3710,  -555,  -555,  -555,   597,   487,  -555,   216,
    -555,   232,   283,  3030,   358,  -555,  2860,  -555,   190,   214,
     226,   492,  3046,  3046,  -555,  -555,   488,  -555,  2355,  -555,
    -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  3710,  -555,
    1480,  3710,  1363,  -555,  3710,  2434,  -555,  -555,  -555,  -555,
     489,   490,  -555,   601,   298,   493,   307,  -555,   605,  -555,
    -555,  -555,  -555,   494,  -555,  2860,  2860,  2860,  3710,  1380,
    1470,  -555,  -555,  -555,  2584,  -555,  -555,  -555,  -555,  -555,
    -555,  -555,  -555,  -555,  -555,  -555,   609,  -555,  -555,  -555,
     544,  -555,  -555,   247,  2860,   261,  2860,   262,  -555,  -555,
    2860,   501,  -555,  2860,  -555,  2860,  -555,  -555,  -555,  -555
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     204,     0,   299,   294,   295,   297,    82,   208,   323,   301,
     302,   296,   298,     0,   300,     0,     0,     0,     0,   204,
       4,     6,     7,     9,    10,     8,   204,     0,   205,   206,
     204,   204,   232,   204,   204,   204,   204,   185,   204,   204,
       0,     0,     0,     0,     1,     5,   328,   204,     0,   200,
       0,   204,   306,   204,   230,   231,   209,   210,   211,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,     0,   265,   266,     0,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   212,   228,     0,
     229,   227,   207,   186,   192,   194,   196,   198,   204,   204,
     262,     0,   204,     0,   260,   204,   204,   156,   173,   170,
     171,   172,     0,   174,     0,     0,     0,   324,     0,     0,
      55,    56,   165,    81,   140,   141,   139,   138,   143,   142,
     204,   161,   166,   182,    98,   100,   102,   104,   106,   108,
     110,   113,   118,   121,   124,   128,     0,   130,   144,   157,
     158,   160,     0,   341,   204,   167,     0,     0,     0,     0,
     204,     0,   329,   327,   326,     0,     0,   204,   184,   307,
     183,   308,     0,     0,     0,   204,   204,   203,     0,   204,
     322,   305,   204,   263,   264,     0,   287,   263,   253,   204,
     249,     0,   247,   188,   190,   272,   259,   204,   276,   204,
     168,   169,     0,   204,   134,   204,   131,   132,   204,     0,
     162,    80,     0,    83,    85,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,   152,   153,
       0,     0,     0,   304,     0,   204,   343,   340,   344,   137,
     303,     0,     0,     0,     0,   204,   204,     0,   204,    21,
      24,    23,    31,    29,    30,    25,    26,    27,    28,    32,
       0,   204,   330,   325,   309,   201,   204,     0,   204,    13,
      11,    16,     0,     0,   139,   310,     0,     0,   320,   204,
       0,     0,   332,   333,     0,     0,   292,     0,   288,   291,
       0,   243,   204,   267,   204,   271,   204,   250,   204,   261,
     274,   164,   163,     0,     0,     0,     0,     0,   159,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    87,
       0,     0,   101,     0,   103,   105,   107,   109,   111,   112,
     116,   117,   114,   115,   119,   120,   122,   123,   125,   126,
     127,   151,   150,     0,   146,   180,     0,   148,   149,     0,
     139,   346,     0,     0,   362,     0,     0,   342,     0,   204,
       0,   379,     0,   381,     0,     0,    17,    22,     0,     0,
     204,    50,     0,     0,     0,   204,     0,   204,    35,    38,
      37,    44,    42,    43,    39,    40,    41,    45,   203,    14,
     156,     0,     0,     0,     0,     0,   383,     0,     0,     0,
       0,     0,   399,   393,   389,     0,   397,   204,   398,     0,
     382,   204,   395,   385,   386,   387,   388,     0,   368,   202,
       0,     0,   311,   318,     0,   139,   317,     0,   204,   335,
     204,   336,   338,   319,   204,   204,   321,   293,     0,   283,
       0,     0,   244,   268,     0,     0,     0,   278,   204,   204,
     204,   245,   204,   135,     0,   136,   204,    84,    86,     0,
     129,     0,   145,     0,   147,     0,     0,   347,   353,     0,
     352,     0,   363,   345,     0,   139,   354,     0,     0,   364,
       0,     0,     0,     0,     0,    60,     0,     0,     0,    66,
       0,   204,     0,     0,     0,    47,     0,    72,    71,     0,
      77,    76,     0,    49,     0,    18,    36,   383,     0,   383,
       0,     0,     0,     0,   204,     0,   411,   412,   413,     0,
     400,   384,   394,   396,     0,     0,   370,     0,     0,     0,
     374,   313,     0,     0,   314,   316,     0,   331,   334,     0,
     284,   289,   290,     0,   285,   282,   269,   204,   270,   280,
     248,   255,     0,   257,   246,     0,     0,   176,     0,     0,
      99,   181,   349,     0,     0,   351,     0,     0,   355,   361,
       0,   360,     0,   365,   378,   380,     0,     0,    58,    57,
      59,   204,     0,    64,    63,    65,    52,     0,    79,     0,
      48,     0,     0,   204,     0,   390,   383,   392,     0,     0,
       0,     0,     0,     0,   410,   414,     0,   377,     0,   366,
     369,   373,   375,   312,   315,   339,   286,   279,     0,   251,
     204,     0,   204,   175,     0,     0,   154,   348,   350,   357,
       0,     0,   358,    61,     0,     0,     0,    54,    51,    46,
      73,    78,    74,     0,   391,   383,   383,   383,     0,     0,
       0,   376,   367,   372,     0,   281,   256,   258,   179,   177,
     178,   155,   356,   359,    62,    69,    67,    70,    53,    75,
     402,   403,   404,     0,   383,     0,   383,     0,   371,    68,
     383,     0,   408,   383,   406,   383,   401,   405,   409,   407
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -555,  -555,  -555,   633,  -555,  -555,  -555,   480,  -555,  -555,
    -555,   426,  -555,  -555,   275,  -225,  -211,  -204,  -555,   272,
     -26,  -181,  -555,   161,  -164,   146,   183,  -160,  -555,  -156,
    -555,  -152,  -555,  -555,    26,  -117,   371,  -555,   -31,  -555,
     468,   473,   466,   481,   465,   292,   279,   293,   302,   296,
     447,  -555,  -555,  -555,  -555,  -555,  -555,  -555,  -555,    61,
    -555,   -20,   -28,   536,  -555,   527,    31,  -555,   669,   -33,
     -34,  -555,  -555,  -555,  -555,  -555,  -555,  -555,   611,  -555,
     177,  -275,    20,  -555,   141,  -555,   405,  -385,  -555,  -555,
      88,  -555,  -555,   -25,   -42,     0,   -23,     3,  -130,  -167,
    -555,  -419,  -555,   194,  -139,  -239,  -276,   234,  -554,  -555,
     167,  -114,  -374,  -555,  -555,  -158,  -555,   287,  -481,  -555,
    -555,  -555
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,    21,   173,    22,   174,    23,   257,
     258,   259,   386,   387,   388,   260,   261,   262,   380,   381,
     131,   263,   494,   495,   264,   498,   499,   265,   266,   267,
     382,   268,   383,   132,   414,   415,   213,   330,   214,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     215,   146,   147,   148,   202,   149,   150,   151,   566,   567,
     356,   152,    25,   289,    48,    49,    27,    28,    29,    30,
      31,    88,   190,   460,   191,   562,    32,   103,   186,    89,
     302,   303,   153,   456,   457,    90,   297,   298,   299,    91,
      33,    34,    35,   166,    52,   158,   155,    53,   164,   365,
     292,   293,   294,   568,   366,   248,   536,   537,   538,   539,
     540,    37,   418,   419,   420,   594,   421,   422,   423,   424,
     425,   426
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    51,    99,    98,   102,   102,   429,   367,   133,   133,
     133,   181,   291,   212,   247,   279,   280,   296,    38,    36,
     157,   159,   311,   175,   171,   548,    24,   453,   296,   180,
      36,    36,   523,    36,    36,    36,   217,     7,   106,   154,
     378,   493,   200,   613,   378,    24,   389,   187,   287,   163,
      39,    36,   184,     1,   188,   277,   183,    50,   104,    42,
     390,   184,   497,   551,   664,   201,   506,   391,   102,   101,
     101,   102,   199,   471,   196,   305,   629,    44,   165,   317,
      40,   664,   177,   197,   165,   630,   212,    43,   212,    41,
     392,   507,   278,     7,   317,     7,   102,   169,    36,    36,
     472,   333,   106,    46,   167,   106,   168,   393,   237,   238,
     239,   394,   503,   251,   363,   395,   244,   245,   252,   396,
     199,   160,   195,   353,   448,   198,   105,   105,   449,   169,
     154,   659,   660,   101,   162,   182,   101,   101,   278,   171,
     161,   312,   276,   605,   253,   607,   211,   175,   102,   254,
     441,   276,   208,   431,   218,   102,   246,     7,   180,   512,
      36,   101,   389,   102,   379,   102,   550,   273,   551,   102,
      46,   102,   645,    46,   102,    36,   390,   626,   209,    36,
     225,   226,   106,   391,   453,   101,   269,   453,   305,   106,
     105,    46,   305,   105,   305,   189,   169,   106,   165,   106,
     351,   367,   490,   154,   185,   154,   392,    50,   106,   304,
     290,   352,   357,   101,   120,   121,   358,   309,   105,   310,
     101,   317,   505,   393,   508,   511,   318,   394,   101,   476,
     101,   395,   654,   156,   101,   396,   101,   210,   488,   101,
     240,   241,   242,   117,   170,    36,   120,   121,   246,   317,
     416,   399,   272,    47,     7,    36,    36,   317,    36,   530,
     219,   531,   620,   509,   439,     7,   162,   221,   102,     7,
     105,    36,   102,   384,   102,   445,   556,   105,   417,   458,
     446,   680,   681,   682,   269,   105,   222,   105,   510,   278,
     473,   105,   440,   105,   529,   474,   105,   397,   621,   632,
     227,   228,   106,   534,   633,   535,   106,   398,   106,   220,
     692,   553,   694,   120,   121,   554,   696,   120,   121,   698,
     165,   699,   304,   618,   216,   243,   304,   619,   304,   120,
     121,   250,   162,   101,   597,   455,   589,   101,   317,   101,
     178,   179,   663,   655,   557,   305,   558,    46,   305,   244,
     438,    46,  -343,     7,   577,   274,   317,  -343,   615,   663,
     244,   438,   317,  -337,   317,    47,   649,   656,  -337,    36,
     133,   162,   223,   224,   317,   272,   295,   496,   500,   657,
     317,   518,   650,    99,    98,    36,   599,    36,   688,   601,
     105,   587,   602,   416,   105,   317,   105,   313,   181,   314,
     691,   271,   315,   608,   609,   610,     3,     4,     5,   317,
     317,   504,   296,   397,   693,   695,   588,   278,   635,   133,
     278,   417,   636,   133,   300,   102,   102,  -252,   102,   171,
     552,   317,   102,   651,   555,    46,   653,   306,    36,    11,
     570,   440,   236,   307,    36,   454,   317,   162,   675,    47,
     249,   272,   592,    12,   249,   317,   162,   677,   370,   106,
     106,   308,   106,   233,   234,   235,   106,   229,   230,   546,
     644,   165,   231,   232,   561,   646,   549,   593,   278,   304,
     563,     1,   304,   459,   371,   462,   145,   145,   145,   559,
     101,   101,   331,   101,   244,   245,   612,   101,    46,   368,
     369,    36,   372,   133,   340,   341,   342,   343,   593,   278,
     373,     3,     4,     5,   616,   338,   339,   500,   432,   272,
     171,     7,   344,   345,   417,   376,     8,   444,   433,   348,
     349,   350,   458,   346,   347,   443,    26,   447,   450,   463,
     464,   683,   685,   687,    11,   465,   482,   105,   105,   286,
     105,   466,   515,   477,   105,    26,   478,   483,    12,   491,
     492,   204,   206,   207,   272,   501,    93,    94,   502,    95,
      96,    97,   162,   282,   517,   520,   272,   519,   525,   541,
     316,   526,   521,   522,   524,   469,   493,   176,   165,   527,
     586,    36,   584,   145,   544,   545,   102,   133,   102,   572,
     575,   145,   578,    36,   579,   145,   583,   585,   665,   591,
    -254,   497,   355,   598,   600,   362,   603,   606,   611,  -254,
     617,   623,   614,   624,   625,   628,   631,   470,   634,   643,
     106,   637,   106,   638,   193,   194,   639,   647,   658,   642,
     648,   674,   661,   672,   673,   678,   676,   679,   690,   689,
     667,   697,    45,   428,   430,   281,   513,   590,   437,     1,
     604,   101,   516,   101,   145,   272,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   595,   377,   332,   335,   337,   467,     3,
       4,     5,   334,   669,   275,     1,   270,    92,   627,     7,
     192,   468,   336,   569,     8,   451,   622,     0,   533,     0,
       0,   176,     0,   249,     0,     0,     0,     0,   105,     0,
     105,     0,    11,     0,     0,     3,     4,     5,     0,     0,
     475,     0,     0,     0,   481,     7,    12,     0,     0,   487,
       8,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   107,   108,   109,   110,   111,   112,     0,    11,   113,
     114,     0,   115,   116,     0,     0,    15,    16,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,   145,     1,
       0,     0,     0,     0,   283,     0,     0,   565,     3,     4,
       5,   374,   375,     0,   270,     0,   117,     0,   428,     0,
       0,   301,   542,     8,     0,   543,     0,   270,     2,     3,
       4,     5,     0,     0,   176,     0,     0,     0,     0,     7,
       0,    11,     0,     0,     8,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,    12,     0,     0,     0,     0,
     428,     0,    11,     0,   571,     0,     0,   573,   145,     0,
     574,     0,     0,     0,     0,   576,    12,   329,     0,   582,
       0,     0,   118,   119,   145,     0,     0,     0,   120,   121,
     122,   123,     0,     0,     0,     1,     0,     0,   124,   125,
     284,     0,    13,     0,   127,    14,     0,     0,     0,     0,
       0,   128,   129,     0,   130,     0,     0,   145,     0,     0,
       0,   145,   285,   100,     0,     3,     4,     5,     0,   428,
       1,     0,     0,     0,     0,     7,     0,     0,   145,     0,
       8,   514,   288,   270,     0,   107,   108,   109,   110,   111,
     112,     0,     0,   113,   114,     1,   115,   116,    11,     0,
       3,     4,     5,     0,     0,     0,     0,     0,   640,     0,
       7,   641,    12,     0,     0,     8,     0,   176,   359,     0,
       0,     0,     3,     4,     5,     3,     4,     5,     0,     0,
     117,     0,     0,    11,     0,     7,     0,     8,     0,     0,
       8,   145,    15,    16,     0,     0,     0,    12,     0,   428,
       0,     0,     0,     0,     0,    11,     0,     0,    11,     0,
       0,     1,   668,     0,     0,   670,   428,     0,     0,    12,
       0,     0,    12,     0,     0,     0,     0,   452,   107,   108,
     109,   110,   111,   112,     0,     0,   113,   114,     0,   115,
     116,     3,     4,     5,     0,   428,   118,   119,     0,     0,
       0,     7,   120,   121,   122,   123,     8,     0,     0,     0,
       0,   434,   124,   125,   360,     3,     4,     5,   127,     0,
     176,     0,     0,   117,    11,   128,   129,     0,   130,     0,
       8,     0,     0,     0,     0,   145,   361,     0,    12,     0,
       0,     0,   107,   108,   109,   110,   111,   112,    11,     0,
     113,   114,     0,   115,   116,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,    15,    16,
       0,     0,     0,     0,     0,   479,     0,     0,     0,     3,
       4,     5,     0,     0,     0,     0,     0,   117,     0,   118,
     119,     0,     0,     0,     8,   120,   121,   122,   123,     0,
       0,     0,     0,   461,     0,   124,   125,   435,     0,     0,
       0,   127,    11,     0,     0,     0,     0,     0,   128,   129,
       0,   130,     0,     0,     0,     0,    12,     0,     0,   436,
       0,     0,     0,     0,     0,   107,   108,   109,   110,   111,
     112,     0,     0,   113,   114,     0,   115,   116,     0,     0,
       0,     0,     0,   118,   119,     0,     0,     0,     0,   120,
     121,   122,   123,     0,     0,     0,     0,     0,   484,   124,
     125,   126,     3,     4,     5,   127,     0,     0,     0,     0,
     117,     0,   128,   129,     0,   130,     0,     8,     0,     0,
       0,     0,     0,   480,     0,     1,     0,     0,     0,   107,
     108,   109,   110,   111,   112,    11,     0,   113,   114,     0,
     115,   116,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     3,     4,     5,     0,     0,
       0,     0,   580,     0,     0,     7,     3,     4,     5,     0,
       8,     0,     0,     0,   117,     0,   118,   119,     0,     0,
       0,     8,   120,   121,   122,   123,     0,     0,    11,     0,
       0,     0,   124,   125,   485,     0,     0,     0,   127,    11,
       0,     0,    12,     0,     0,   128,   129,     0,   130,     0,
       0,     0,     0,    12,     0,     0,   486,     0,     0,   107,
     108,   109,   110,   111,   112,     0,     0,   113,   114,     0,
     115,   116,    15,    16,     0,     0,     0,     0,     0,     0,
     118,   119,     0,     0,     0,     0,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,   124,   125,   126,     0,
       0,     0,   127,     1,   117,     0,     0,   560,     0,   128,
     129,     8,   130,   107,   108,   109,   110,   111,   112,     1,
     581,   113,   114,     0,   115,   116,     0,     0,     0,     0,
       0,     0,     0,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     8,     3,
       4,     5,     0,     0,     0,     0,     0,     0,   117,     7,
       0,     0,     0,     0,     8,     8,    11,     0,     0,     0,
     118,   119,     0,     0,     0,     0,   120,   121,   122,   123,
      12,     0,    11,     0,     0,     0,   124,   125,   126,     0,
       0,     0,   127,     0,     0,   565,    12,     0,     0,   128,
     129,     0,   130,   107,   108,   109,   110,   111,   112,   354,
       0,   113,   114,   666,   115,   116,     0,     0,     0,     0,
       1,     0,     0,     0,   118,   119,    15,    16,     0,     0,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
     124,   125,   126,     0,     0,     0,   127,     1,   117,     0,
       3,     4,     5,   128,   129,     8,   130,  -187,     0,     0,
       7,   564,     0,   684,     1,     8,     0,     0,     0,     0,
       0,     1,     0,     0,     0,     0,     0,     3,     4,     5,
       0,     0,     0,    11,     0,     0,     0,     7,     0,     0,
       0,     0,     8,     2,     3,     4,     5,    12,     0,     0,
       0,     3,     4,     5,     7,     0,     0,     0,     0,     8,
      11,     7,     9,    10,   118,   119,     8,     0,     0,     0,
     120,   121,   122,   123,    12,     0,  -193,    11,     0,     0,
     124,   125,   126,     1,    11,     0,   127,     0,     0,     0,
       0,    12,     0,   128,   129,     0,   130,     0,    12,     0,
       0,     0,     0,   686,    15,    16,     0,     0,     1,     0,
       0,     0,     2,     3,     4,     5,     0,    13,     0,     0,
      14,     0,     0,     7,  -187,  -187,     0,  -187,     8,     0,
       0,     9,    10,     0,     0,     0,  -187,     0,     3,     4,
       5,     0,     0,     0,     0,     0,    11,     0,     7,  -187,
    -187,     0,  -187,     8,  -187,     0,     0,  -187,     0,     0,
      12,  -195,     0,     0,     0,     0,     0,     0,     1,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    12,    13,     0,     0,    14,
       0,     0,     0,  -193,  -193,     0,  -193,     2,     3,     4,
       5,     0,  -197,     0,     0,  -193,     0,     0,     7,     1,
       0,     0,     0,     8,     0,     0,     9,    10,  -193,  -193,
       0,  -193,     0,  -193,     0,     0,  -193,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     2,     3,
       4,     5,     0,     0,     0,    12,  -199,     0,     0,     7,
       0,     0,     0,     1,     8,     0,     0,     9,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,    11,     0,    14,     0,     0,     0,  -195,  -195,
       0,  -195,     2,     3,     4,     5,    12,  -189,     0,     0,
    -195,     0,     0,     7,     1,     0,     0,     0,     8,     0,
       0,     9,    10,  -195,  -195,     0,  -195,     0,  -195,     0,
       0,  -195,    13,     0,     0,    14,    11,     0,     0,  -197,
    -197,     0,  -197,     2,     3,     4,     5,     0,     0,     0,
      12,  -197,     0,     0,     7,     0,     0,     0,     1,     8,
       0,     0,     9,    10,  -197,  -197,     0,  -197,     0,  -197,
       0,     0,  -197,     0,     0,     0,    13,    11,     0,    14,
       0,     0,     0,  -199,  -199,     0,  -199,     2,     3,     4,
       5,    12,  -191,     0,     0,  -199,     0,     0,     7,     1,
       0,     0,     0,     8,     0,     0,     9,    10,  -199,  -199,
       0,  -199,     0,  -199,     0,     0,  -199,    13,     0,     0,
      14,    11,     0,     0,  -189,  -189,     0,  -189,     2,     3,
       4,     5,     0,  -273,     0,    12,  -189,     0,     0,     7,
       1,     0,     0,     0,     8,     0,     0,     9,    10,  -189,
    -189,     0,  -189,     0,  -189,     0,     0,  -189,     0,     0,
       0,    13,    11,     0,    14,     0,     0,     0,     0,     0,
       3,     4,     5,     0,     0,     0,    12,  -277,     0,     0,
       7,     0,     0,     0,     1,     8,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   489,    13,    11,     0,    14,     0,     0,     0,  -191,
    -191,     0,  -191,     0,     3,     4,     5,    12,  -275,     0,
       0,  -191,     0,     0,     7,     1,     0,     0,     0,     8,
       0,     0,     0,     0,  -191,  -191,     0,  -191,     0,  -191,
       0,     0,  -191,     0,     0,     0,     0,    11,     0,     0,
    -273,  -273,     0,     0,     0,     3,     4,     5,     0,     0,
       0,    12,  -273,     0,     0,     7,     0,     0,     0,  -273,
       8,     0,  -273,     0,     0,  -273,  -273,     0,  -273,     0,
    -273,     0,     0,  -273,     0,     0,     0,     0,    11,     0,
       0,     0,     0,     0,  -277,  -277,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,  -277,     0,     0,     0,
       0,     0,     0,  -277,     0,     0,  -277,     0,     0,  -277,
    -277,     0,  -277,     0,  -277,     0,     0,  -277,     0,     0,
       0,     0,     0,     0,     0,  -275,  -275,   400,   108,   109,
     110,   111,   112,     0,     1,   113,   114,  -275,   115,   116,
       0,     0,     0,     0,  -275,     0,     1,  -275,     0,     0,
    -275,  -275,     0,  -275,     0,  -275,     0,     0,  -275,     0,
       0,     0,     0,     2,     3,     4,     5,     0,     6,     0,
       0,     0,   117,     0,     7,     2,     3,     4,     5,     8,
       0,     0,     9,    10,     0,     0,     7,     0,     0,     0,
       0,     8,     0,     0,     9,    10,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,   401,   402,   403,     0,   404,
     405,   406,   407,   408,   409,   410,   411,    13,   118,   119,
      14,    15,    16,     0,   120,   121,   122,   123,     0,    13,
       0,     0,    14,     0,   124,   125,   126,     0,     0,     0,
     127,     0,     1,     0,     0,     0,     0,   128,   129,     0,
     130,     0,     0,     0,   412,  -383,   413,   400,   108,   109,
     110,   111,   112,     0,     1,   113,   114,     0,   115,   116,
       0,     2,     3,     4,     5,     0,     0,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     0,     8,     0,     0,
       9,    10,     0,     2,     3,     4,     5,     0,     6,     0,
       0,     0,   117,     0,     7,    11,     0,     0,     0,     8,
       0,     0,     9,    10,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,    11,   107,   108,
     109,   110,   111,   112,     0,     0,   113,   114,     0,   115,
     116,    12,     0,     0,     0,    13,     0,     0,    14,    15,
      16,     0,     0,     0,     0,   401,   402,   403,     0,   404,
     405,   406,   407,   408,   409,   410,   411,    13,   118,   119,
      14,    15,    16,   117,   120,   121,   122,   123,     0,     0,
       8,     0,     0,   -15,   124,   125,   126,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,   128,   129,     0,
     130,     0,     0,     0,   412,  -383,   532,   107,   108,   109,
     110,   111,   112,     0,     0,   113,   114,     0,   115,   116,
       0,     0,     0,     0,    54,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,     0,     0,     0,     0,   120,   121,   122,   123,     0,
       0,     0,   117,     0,     0,   124,   125,   126,     0,     8,
       0,   127,     0,     0,     0,     0,     0,     0,   128,   129,
     534,   130,   535,     0,     0,     0,   427,   662,   107,   108,
     109,   110,   111,   112,     0,     0,   113,   114,     0,   115,
     116,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,     0,   118,   119,
       0,     0,     0,   117,   120,   121,   122,   123,     0,     0,
       8,     0,     0,     0,   124,   125,   126,     0,     0,     0,
     127,     0,     0,     0,     0,     0,     0,   128,   129,   534,
     130,   535,     0,     0,     0,   427,   671,   107,   108,   109,
     110,   111,   112,     0,     0,   113,   114,     0,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119,     0,     0,     0,     0,   120,   121,   122,   123,     0,
       0,     0,   117,     0,     0,   124,   125,   126,     0,     8,
       0,   127,     0,     0,     0,     1,     0,     0,   128,   129,
     534,   130,   535,     0,     0,     0,   427,   107,   108,   109,
     110,   111,   112,     0,     0,   113,   114,     0,   115,   116,
       0,     0,     0,     0,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       8,     0,     0,     9,    10,     0,     0,     0,   118,   119,
       0,     0,   117,     0,   120,   121,   122,   123,    11,     8,
       0,     0,     0,     0,   124,   125,   126,     0,     0,     0,
     127,     0,    12,     0,     0,     0,     0,   128,   129,     0,
     130,     0,     0,     0,     0,   427,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,   118,   119,
       0,     0,     0,     0,   120,   121,   122,   123,     0,     0,
     244,   245,    -2,     0,   124,   125,   126,     0,   364,     0,
     127,     0,     1,     0,     0,     0,     0,   128,   129,     0,
     130,     0,     0,     0,     0,   469,   107,   108,   109,   110,
     111,   112,     0,     1,   113,   114,     0,   115,   116,     0,
       0,     2,     3,     4,     5,     0,     6,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     0,     8,     0,     0,
       9,    10,     2,     3,     4,     5,     0,     0,     0,     0,
       0,   117,     0,     7,     0,    11,     0,     0,     8,     0,
       0,     9,    10,   400,   108,   109,   110,   111,   112,    12,
       0,   113,   114,     0,   115,   116,    11,     0,     0,     0,
       0,     0,     1,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,    13,     0,     0,    14,    15,
      16,     0,     0,     0,     6,     0,     0,     0,   117,     0,
      17,     2,     3,     4,     5,     8,    13,   118,   119,    14,
      15,    16,     7,   120,   121,   122,   123,     8,     0,     0,
       9,    10,     0,   124,   125,   126,     0,     0,     0,   127,
       0,     0,     0,     0,     0,    11,   128,   129,     0,   130,
       0,     0,     0,   412,     0,     0,     0,     0,     0,    12,
       0,   401,   402,   403,     0,   404,   405,   406,   407,   408,
     409,   410,   411,     0,   118,   119,     0,     0,     0,     0,
     120,   121,   122,   123,     0,    13,     0,     0,    14,     0,
     124,   125,   126,     0,     0,     0,   127,     0,     0,     1,
       0,     0,     0,   128,   129,     0,   130,     0,     0,     0,
     412,   107,   108,   109,   110,   111,   112,     0,     0,   113,
     114,     0,   115,   116,     0,   596,     0,     0,     2,     3,
       4,     5,     0,     0,     0,     0,     0,     0,     0,     7,
       1,     0,     0,     0,     8,     0,     0,     9,    10,   107,
     108,   109,   110,   111,   112,     0,   117,   113,   114,     0,
     115,   116,    11,     8,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     0,     0,     0,    12,     0,     0,     0,
       7,     0,     0,     0,     0,     8,     0,     0,     9,    10,
       0,     0,     0,     0,   117,     0,     0,     0,     0,     0,
       0,     8,    13,    11,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       0,    46,   118,   119,     0,     0,     0,     0,   120,   121,
     122,   123,     0,     0,   244,   438,     0,     0,   124,   125,
     126,     0,   364,    13,   127,     0,    14,     0,     0,     0,
       0,   128,   129,     0,   130,     0,     0,     0,   528,     0,
     118,   119,     0,     0,     0,     0,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,   124,   125,   126,     0,
       0,     0,   127,   652,     0,     0,     0,     0,     0,   128,
     129,     0,   130,     0,     0,     0,   412,   107,   108,   109,
     110,   111,   112,     0,     1,   113,   114,     0,   115,   116,
       0,     0,     0,     0,     0,     0,   107,   108,   109,   110,
     111,   112,     0,     1,   113,   114,     0,   115,   116,     0,
       0,     0,     0,     0,     3,     4,     5,     0,     0,     0,
       0,     0,   117,     0,     7,     0,     0,     0,     0,     8,
       0,     0,     0,     3,     4,     5,     0,     0,     0,     0,
       0,   117,     0,     7,     0,     0,     0,    11,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,   118,   119,
       0,     0,     0,     0,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,   124,   125,   126,   118,   119,     0,
     127,     0,     0,   120,   121,   122,   123,   128,   129,     0,
     130,     0,     0,   124,   125,   126,     0,     0,     0,   127,
       0,     0,     0,     0,     0,     0,   128,   129,     0,   130,
     107,   108,   109,   110,   111,   112,     0,     1,   113,   114,
       0,   115,   116,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,     0,     1,   113,   114,     0,
     115,   116,     0,     0,     0,     0,     0,     3,     4,     5,
       0,     0,     0,     0,     0,   117,     0,     7,     0,     0,
       0,     0,     8,     0,     0,     0,     3,     4,     5,     0,
       0,     0,     0,     0,   117,     0,     7,     0,     0,     0,
      11,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,   118,   119,     0,     0,     0,     0,   120,   121,   122,
     123,     0,     0,     0,     0,     0,     0,   124,   125,   126,
     118,   119,     0,   127,     0,     0,   120,   121,   122,   123,
     128,   129,     0,   130,     0,     0,   124,   125,   126,     0,
       0,     0,   127,     0,     0,     0,     0,     0,     0,   128,
     129,     0,   130,   107,   108,   109,   110,   111,   112,     0,
       0,   113,   114,     0,   115,   116,     0,     0,     0,     0,
       0,     0,   107,   108,   109,   110,   111,   112,     0,     1,
     113,   114,     0,   115,   116,     0,     0,     0,     0,     0,
       3,     4,     5,     0,     0,     0,     0,     0,   117,   107,
     108,   109,   110,   111,   112,     8,     1,   113,   114,     0,
     115,   116,     0,     0,     0,     0,     0,   117,     0,     7,
       0,     0,     0,    11,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,   117,     0,     7,     0,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   119,     0,     0,     0,     0,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   118,   119,     0,   127,     0,     0,   120,
     121,   122,   123,   128,   129,     0,   130,     0,     0,   124,
     125,   126,     0,     0,     0,   127,     0,     0,     0,     0,
     118,   119,   128,   129,     0,   130,   120,   121,   122,   123,
       0,     0,     0,     0,     0,     0,   124,   125,   126,     0,
       0,     0,   127,     0,     0,     0,     0,     0,     0,   128,
     129,     0,   130,   107,   108,   109,   110,   111,   112,     0,
       0,   113,   114,     0,   115,   116,     0,     0,     0,     0,
       0,     0,   107,   108,   109,   110,   111,   112,     0,     0,
     113,   114,     1,   115,   116,     0,     0,     0,     0,     0,
       0,   107,   108,   109,   110,   111,   112,     0,   117,   113,
     114,     0,   115,   116,     0,     8,     0,     0,     0,     0,
       0,     2,     3,     4,     5,   547,     0,   117,     0,     0,
       0,     0,     7,     0,     8,     0,     0,     8,     0,     0,
       9,    10,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     8,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,   118,   119,     0,     0,     0,     0,
     120,   121,   122,   123,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   118,   119,    13,   127,     0,    14,   120,
     121,   122,   123,   128,   129,     0,   130,     0,     0,   124,
     125,   126,   118,   119,     0,   127,     1,     0,   120,   121,
     122,   123,   128,   129,     0,   203,     0,     0,   124,   125,
     126,     0,     0,     0,   127,     0,     0,     1,     0,     0,
       0,   128,   129,     0,   205,     2,     3,     4,     5,     0,
       6,     0,     0,     0,     0,     0,     7,     0,     1,     0,
       0,     8,     0,     0,     9,    10,     2,     3,     4,     5,
       0,     6,     0,     0,     0,     0,     0,     7,     0,    11,
       0,     0,     8,     0,     0,     9,    10,     2,     3,     4,
       5,     0,     6,    12,     0,     0,     1,     0,     7,     0,
      11,     0,     0,     8,     0,     0,     9,    10,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     1,     0,    13,
       0,    11,    14,     0,     0,     2,     3,     4,     5,     0,
       6,     0,   255,   256,     0,    12,     7,     0,     1,     0,
      13,     8,     0,    14,     9,    10,     2,     3,     4,     5,
       0,     0,     0,   255,   256,     0,     0,     7,   -19,    11,
       0,    13,     8,     0,    14,     9,    10,     2,     3,     4,
       5,     0,     0,    12,   255,   385,     0,     0,     7,   -20,
      11,     0,     0,     8,     0,     0,     9,    10,     0,     0,
       0,     0,     0,     0,    12,     0,     0,     0,     0,    13,
     -33,    11,    14,     0,     0,     0,     0,    54,    55,     0,
       0,     0,   255,   385,     0,    12,     0,     0,     0,     0,
      13,     0,     0,    14,    15,    16,     0,     0,     0,     0,
       0,     0,   172,    56,    57,    58,    59,    60,   -34,     0,
       0,    13,     0,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -12,     0,
       0,    -3,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       2,     3,     4,     5,     0,     6,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     8,     0,    87,     9,
      10,   169,     0,     0,     0,     0,    54,    55,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,   282,
       0,     0,     0,     0,     0,     0,     0,     0,    12,     0,
       0,     0,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,     0,    14,    15,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,   442,
       0,     0,     0,     0,    54,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    87,   120,   121,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    54,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       0,     0,     0,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     0,     0,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
       2,     3,     4,     5,     0,     0,     1,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     8,     0,    87,     9,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     2,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     7,     0,    12,     0,
       0,     8,     0,     0,     9,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,    13,     0,     0,    14,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
       0,     0,    14
};

static const yytype_int16 yycheck[] =
{
       0,    26,    36,    36,    38,    39,   282,   246,    39,    40,
      41,    53,   179,   130,   153,   173,   174,     3,   138,    19,
      40,    41,     3,    51,    50,   444,     0,   302,     3,    52,
      30,    31,   406,    33,    34,    35,    23,    50,    38,    39,
       3,     3,   124,   524,     3,    19,   271,     3,   178,    46,
     146,    51,     8,    10,    10,   172,     3,    26,    38,     8,
     271,     8,     3,   448,   618,   147,   125,   271,   102,    38,
      39,   105,   106,   142,   139,   189,   139,     0,    47,   148,
     146,   635,    51,   148,    53,   148,   203,    36,   205,   146,
     271,   150,   151,    50,   148,    50,   130,     3,    98,    99,
     154,   218,   102,   132,   148,   105,   150,   271,    13,    14,
      15,   271,   125,   148,   244,   271,   145,   146,   153,   271,
     154,   151,   102,   240,   148,   105,    38,    39,   152,     3,
     130,   612,   613,   102,    46,   146,   105,   106,   151,   165,
       8,   122,   167,   517,   148,   519,     3,   175,   182,   153,
     289,   176,   146,   283,   141,   189,   153,    50,   181,   122,
     160,   130,   387,   197,   123,   199,   152,   164,   553,   203,
     132,   205,   591,   132,   208,   175,   387,   152,   146,   179,
      18,    19,   182,   387,   459,   154,   160,   462,   302,   189,
     102,   132,   306,   105,   308,   151,     3,   197,   167,   199,
       3,   440,   369,   203,   151,   205,   387,   176,   208,   189,
     179,   237,     3,   182,   120,   121,   242,   197,   130,   199,
     189,   148,   380,   387,   382,   383,   153,   387,   197,   359,
     199,   387,   606,    39,   203,   387,   205,     8,   368,   208,
     145,   146,   147,    48,   150,   245,   120,   121,   245,   148,
     278,   150,   164,   146,    50,   255,   256,   148,   258,   150,
      22,   419,   538,   125,   289,    50,   178,   137,   302,    50,
     182,   271,   306,   270,   308,   148,   150,   189,   278,   304,
     153,   655,   656,   657,   258,   197,   136,   199,   150,   151,
     148,   203,   289,   205,   411,   153,   208,   271,   140,   148,
     138,   139,   302,   145,   153,   147,   306,   276,   308,   135,
     684,   148,   686,   120,   121,   152,   690,   120,   121,   693,
     289,   695,   302,   148,   130,   153,   306,   152,   308,   120,
     121,   153,   244,   302,   501,   304,   494,   306,   148,   308,
     145,   146,   618,   153,   148,   459,   150,   132,   462,   145,
     146,   132,   148,    50,   484,   153,   148,   153,   150,   635,
     145,   146,   148,   148,   148,   146,   150,   153,   153,   369,
     401,   283,    20,    21,   148,   287,   182,   374,   375,   153,
     148,   401,   150,   417,   417,   385,   503,   387,   664,   506,
     302,   125,   509,   421,   306,   148,   308,   203,   440,   205,
     153,   151,   208,   520,   521,   522,    40,    41,    42,   148,
     148,   380,     3,   387,   153,   153,   150,   151,   148,   450,
     151,   421,   152,   454,   151,   459,   460,   138,   462,   455,
     450,   148,   466,   150,   454,   132,   603,   151,   438,    73,
     471,   438,   146,   138,   444,   142,   148,   359,   150,   146,
     154,   363,   125,    87,   158,   148,   368,   150,     4,   459,
     460,   151,   462,   132,   133,   134,   466,    16,    17,   438,
     587,   440,   130,   131,     3,   592,   445,   150,   151,   459,
     460,    10,   462,   306,   150,   308,    39,    40,    41,   458,
     459,   460,   153,   462,   145,   146,   524,   466,   132,   145,
     146,   501,     4,   534,   225,   226,   227,   228,   150,   151,
     150,    40,    41,    42,   534,   223,   224,   514,   154,   431,
     546,    50,   229,   230,   524,   152,    55,   148,   154,   233,
     234,   235,   557,   231,   232,   153,     0,   153,   140,   153,
     153,   658,   659,   660,    73,   153,   153,   459,   460,   178,
     462,   148,   152,   154,   466,    19,   154,   153,    87,   153,
     153,   114,   115,   116,   476,   146,    30,    31,   146,    33,
      34,    35,   484,   140,   142,   146,   488,   142,     3,   154,
     209,   150,   146,   146,   146,   151,     3,    51,   557,   150,
     146,   591,   150,   146,   154,   154,   630,   628,   632,   154,
     154,   154,   154,   603,   154,   158,   153,   150,   628,   146,
     139,     3,   241,   153,   150,   244,   146,   142,   106,   148,
       3,   154,   150,   154,     3,   142,   142,   331,   142,   153,
     630,   154,   632,   154,    98,    99,   154,    40,   146,   154,
     153,    40,   154,   154,   154,    40,   153,   153,   104,    40,
     630,   150,    19,   282,   283,   175,   384,   496,   287,    10,
     514,   630,   387,   632,   217,   577,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   500,   258,   217,   220,   222,   317,    40,
      41,    42,   219,   632,   167,    10,   160,    28,   557,    50,
      89,   330,   221,   469,    55,   300,   539,    -1,   421,    -1,
      -1,   175,    -1,   417,    -1,    -1,    -1,    -1,   630,    -1,
     632,    -1,    73,    -1,    -1,    40,    41,    42,    -1,    -1,
     359,    -1,    -1,    -1,   363,    50,    87,    -1,    -1,   368,
      55,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     3,     4,     5,     6,     7,     8,    -1,    73,    11,
      12,    -1,    14,    15,    -1,    -1,   117,   118,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,   331,    10,
      -1,    -1,    -1,    -1,    36,    -1,    -1,   102,    40,    41,
      42,   255,   256,    -1,   258,    -1,    48,    -1,   427,    -1,
      -1,   152,   431,    55,    -1,   434,    -1,   271,    39,    40,
      41,    42,    -1,    -1,   278,    -1,    -1,    -1,    -1,    50,
      -1,    73,    -1,    -1,    55,    -1,    -1,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,
     469,    -1,    73,    -1,   473,    -1,    -1,   476,   401,    -1,
     479,    -1,    -1,    -1,    -1,   484,    87,   140,    -1,   488,
      -1,    -1,   114,   115,   417,    -1,    -1,    -1,   120,   121,
     122,   123,    -1,    -1,    -1,    10,    -1,    -1,   130,   131,
     132,    -1,   113,    -1,   136,   116,    -1,    -1,    -1,    -1,
      -1,   143,   144,    -1,   146,    -1,    -1,   450,    -1,    -1,
      -1,   454,   154,     3,    -1,    40,    41,    42,    -1,   538,
      10,    -1,    -1,    -1,    -1,    50,    -1,    -1,   471,    -1,
      55,   385,   153,   387,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    10,    14,    15,    73,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,   577,    -1,
      50,   580,    87,    -1,    -1,    55,    -1,   421,    36,    -1,
      -1,    -1,    40,    41,    42,    40,    41,    42,    -1,    -1,
      48,    -1,    -1,    73,    -1,    50,    -1,    55,    -1,    -1,
      55,   534,   117,   118,    -1,    -1,    -1,    87,    -1,   618,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    73,    -1,
      -1,    10,   631,    -1,    -1,   634,   635,    -1,    -1,    87,
      -1,    -1,    87,    -1,    -1,    -1,    -1,   152,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    40,    41,    42,    -1,   664,   114,   115,    -1,    -1,
      -1,    50,   120,   121,   122,   123,    55,    -1,    -1,    -1,
      -1,    36,   130,   131,   132,    40,    41,    42,   136,    -1,
     524,    -1,    -1,    48,    73,   143,   144,    -1,   146,    -1,
      55,    -1,    -1,    -1,    -1,   628,   154,    -1,    87,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    73,    -1,
      11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,   117,   118,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,    -1,   114,
     115,    -1,    -1,    -1,    55,   120,   121,   122,   123,    -1,
      -1,    -1,    -1,   152,    -1,   130,   131,   132,    -1,    -1,
      -1,   136,    73,    -1,    -1,    -1,    -1,    -1,   143,   144,
      -1,   146,    -1,    -1,    -1,    -1,    87,    -1,    -1,   154,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,   120,
     121,   122,   123,    -1,    -1,    -1,    -1,    -1,    36,   130,
     131,   132,    40,    41,    42,   136,    -1,    -1,    -1,    -1,
      48,    -1,   143,   144,    -1,   146,    -1,    55,    -1,    -1,
      -1,    -1,    -1,   154,    -1,    10,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    73,    -1,    11,    12,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    50,    40,    41,    42,    -1,
      55,    -1,    -1,    -1,    48,    -1,   114,   115,    -1,    -1,
      -1,    55,   120,   121,   122,   123,    -1,    -1,    73,    -1,
      -1,    -1,   130,   131,   132,    -1,    -1,    -1,   136,    73,
      -1,    -1,    87,    -1,    -1,   143,   144,    -1,   146,    -1,
      -1,    -1,    -1,    87,    -1,    -1,   154,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    -1,    11,    12,    -1,
      14,    15,   117,   118,    -1,    -1,    -1,    -1,    -1,    -1,
     114,   115,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,
      -1,    -1,   136,    10,    48,    -1,    -1,   152,    -1,   143,
     144,    55,   146,     3,     4,     5,     6,     7,     8,    10,
     154,    11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    48,    50,
      -1,    -1,    -1,    -1,    55,    55,    73,    -1,    -1,    -1,
     114,   115,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
      87,    -1,    73,    -1,    -1,    -1,   130,   131,   132,    -1,
      -1,    -1,   136,    -1,    -1,   102,    87,    -1,    -1,   143,
     144,    -1,   146,     3,     4,     5,     6,     7,     8,   153,
      -1,    11,    12,     3,    14,    15,    -1,    -1,    -1,    -1,
      10,    -1,    -1,    -1,   114,   115,   117,   118,    -1,    -1,
     120,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,    -1,    -1,    -1,   136,    10,    48,    -1,
      40,    41,    42,   143,   144,    55,   146,     3,    -1,    -1,
      50,   152,    -1,   153,    10,    55,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    -1,    73,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    55,    39,    40,    41,    42,    87,    -1,    -1,
      -1,    40,    41,    42,    50,    -1,    -1,    -1,    -1,    55,
      73,    50,    58,    59,   114,   115,    55,    -1,    -1,    -1,
     120,   121,   122,   123,    87,    -1,     3,    73,    -1,    -1,
     130,   131,   132,    10,    73,    -1,   136,    -1,    -1,    -1,
      -1,    87,    -1,   143,   144,    -1,   146,    -1,    87,    -1,
      -1,    -1,    -1,   153,   117,   118,    -1,    -1,    10,    -1,
      -1,    -1,    39,    40,    41,    42,    -1,   113,    -1,    -1,
     116,    -1,    -1,    50,   120,   121,    -1,   123,    55,    -1,
      -1,    58,    59,    -1,    -1,    -1,   132,    -1,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    73,    -1,    50,   145,
     146,    -1,   148,    55,   150,    -1,    -1,   153,    -1,    -1,
      87,     3,    -1,    -1,    -1,    -1,    -1,    -1,    10,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,   113,    -1,    -1,   116,
      -1,    -1,    -1,   120,   121,    -1,   123,    39,    40,    41,
      42,    -1,     3,    -1,    -1,   132,    -1,    -1,    50,    10,
      -1,    -1,    -1,    55,    -1,    -1,    58,    59,   145,   146,
      -1,   148,    -1,   150,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    -1,    -1,    -1,    87,     3,    -1,    -1,    50,
      -1,    -1,    -1,    10,    55,    -1,    -1,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    73,    -1,   116,    -1,    -1,    -1,   120,   121,
      -1,   123,    39,    40,    41,    42,    87,     3,    -1,    -1,
     132,    -1,    -1,    50,    10,    -1,    -1,    -1,    55,    -1,
      -1,    58,    59,   145,   146,    -1,   148,    -1,   150,    -1,
      -1,   153,   113,    -1,    -1,   116,    73,    -1,    -1,   120,
     121,    -1,   123,    39,    40,    41,    42,    -1,    -1,    -1,
      87,   132,    -1,    -1,    50,    -1,    -1,    -1,    10,    55,
      -1,    -1,    58,    59,   145,   146,    -1,   148,    -1,   150,
      -1,    -1,   153,    -1,    -1,    -1,   113,    73,    -1,   116,
      -1,    -1,    -1,   120,   121,    -1,   123,    39,    40,    41,
      42,    87,     3,    -1,    -1,   132,    -1,    -1,    50,    10,
      -1,    -1,    -1,    55,    -1,    -1,    58,    59,   145,   146,
      -1,   148,    -1,   150,    -1,    -1,   153,   113,    -1,    -1,
     116,    73,    -1,    -1,   120,   121,    -1,   123,    39,    40,
      41,    42,    -1,     3,    -1,    87,   132,    -1,    -1,    50,
      10,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,   145,
     146,    -1,   148,    -1,   150,    -1,    -1,   153,    -1,    -1,
      -1,   113,    73,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    87,     3,    -1,    -1,
      50,    -1,    -1,    -1,    10,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,   113,    73,    -1,   116,    -1,    -1,    -1,   120,
     121,    -1,   123,    -1,    40,    41,    42,    87,     3,    -1,
      -1,   132,    -1,    -1,    50,    10,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,   145,   146,    -1,   148,    -1,   150,
      -1,    -1,   153,    -1,    -1,    -1,    -1,    73,    -1,    -1,
     120,   121,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    87,   132,    -1,    -1,    50,    -1,    -1,    -1,   139,
      55,    -1,   142,    -1,    -1,   145,   146,    -1,   148,    -1,
     150,    -1,    -1,   153,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,   120,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,   142,    -1,    -1,   145,
     146,    -1,   148,    -1,   150,    -1,    -1,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,   121,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,   132,    14,    15,
      -1,    -1,    -1,    -1,   139,    -1,    10,   142,    -1,    -1,
     145,   146,    -1,   148,    -1,   150,    -1,    -1,   153,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    39,    40,    41,    42,    55,
      -1,    -1,    58,    59,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    58,    59,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,   101,   102,   103,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    -1,   120,   121,   122,   123,    -1,   113,
      -1,    -1,   116,    -1,   130,   131,   132,    -1,    -1,    -1,
     136,    -1,    10,    -1,    -1,    -1,    -1,   143,   144,    -1,
     146,    -1,    -1,    -1,   150,   151,   152,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    -1,    14,    15,
      -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    59,    -1,    39,    40,    41,    42,    -1,    44,    -1,
      -1,    -1,    48,    -1,    50,    73,    -1,    -1,    -1,    55,
      -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    87,    -1,    -1,    -1,   113,    -1,    -1,   116,   117,
     118,    -1,    -1,    -1,    -1,   101,   102,   103,    -1,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    48,   120,   121,   122,   123,    -1,    -1,
      55,    -1,    -1,   151,   130,   131,   132,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,
     146,    -1,    -1,    -1,   150,   151,   152,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    -1,    14,    15,
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,
      -1,    -1,    48,    -1,    -1,   130,   131,   132,    -1,    55,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
     145,   146,   147,    -1,    -1,    -1,   151,   152,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,    -1,   114,   115,
      -1,    -1,    -1,    48,   120,   121,   122,   123,    -1,    -1,
      55,    -1,    -1,    -1,   130,   131,   132,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,   152,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,
     115,    -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,
      -1,    -1,    48,    -1,    -1,   130,   131,   132,    -1,    55,
      -1,   136,    -1,    -1,    -1,    10,    -1,    -1,   143,   144,
     145,   146,   147,    -1,    -1,    -1,   151,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    -1,    14,    15,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      55,    -1,    -1,    58,    59,    -1,    -1,    -1,   114,   115,
      -1,    -1,    48,    -1,   120,   121,   122,   123,    73,    55,
      -1,    -1,    -1,    -1,   130,   131,   132,    -1,    -1,    -1,
     136,    -1,    87,    -1,    -1,    -1,    -1,   143,   144,    -1,
     146,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   132,   114,   115,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,    -1,
     145,   146,     0,    -1,   130,   131,   132,    -1,   153,    -1,
     136,    -1,    10,    -1,    -1,    -1,    -1,   143,   144,    -1,
     146,    -1,    -1,    -1,    -1,   151,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    12,    -1,    14,    15,    -1,
      -1,    39,    40,    41,    42,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    59,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    50,    -1,    73,    -1,    -1,    55,    -1,
      -1,    58,    59,     3,     4,     5,     6,     7,     8,    87,
      -1,    11,    12,    -1,    14,    15,    73,    -1,    -1,    -1,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,   117,
     118,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
     128,    39,    40,    41,    42,    55,   113,   114,   115,   116,
     117,   118,    50,   120,   121,   122,   123,    55,    -1,    -1,
      58,    59,    -1,   130,   131,   132,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,    73,   143,   144,    -1,   146,
      -1,    -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    87,
      -1,   101,   102,   103,    -1,   105,   106,   107,   108,   109,
     110,   111,   112,    -1,   114,   115,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,    -1,   113,    -1,    -1,   116,    -1,
     130,   131,   132,    -1,    -1,    -1,   136,    -1,    -1,    10,
      -1,    -1,    -1,   143,   144,    -1,   146,    -1,    -1,    -1,
     150,     3,     4,     5,     6,     7,     8,    -1,    -1,    11,
      12,    -1,    14,    15,    -1,   153,    -1,    -1,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,
      10,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,     3,
       4,     5,     6,     7,     8,    -1,    48,    11,    12,    -1,
      14,    15,    73,    55,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    55,   113,    73,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,   132,   114,   115,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,    -1,    -1,   145,   146,    -1,    -1,   130,   131,
     132,    -1,   153,   113,   136,    -1,   116,    -1,    -1,    -1,
      -1,   143,   144,    -1,   146,    -1,    -1,    -1,   150,    -1,
     114,   115,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,
      -1,    -1,   136,   153,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,   146,    -1,    -1,    -1,   150,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    12,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    12,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,    -1,    50,    -1,    -1,    -1,    73,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,    -1,
      -1,    -1,    -1,    -1,   130,   131,   132,   114,   115,    -1,
     136,    -1,    -1,   120,   121,   122,   123,   143,   144,    -1,
     146,    -1,    -1,   130,   131,   132,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,   146,
       3,     4,     5,     6,     7,     8,    -1,    10,    11,    12,
      -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    12,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,
      73,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,   115,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
     114,   115,    -1,   136,    -1,    -1,   120,   121,   122,   123,
     143,   144,    -1,   146,    -1,    -1,   130,   131,   132,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,   146,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,     3,
       4,     5,     6,     7,     8,    55,    10,    11,    12,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,
      -1,    -1,    -1,    73,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   114,   115,    -1,   136,    -1,    -1,   120,
     121,   122,   123,   143,   144,    -1,   146,    -1,    -1,   130,
     131,   132,    -1,    -1,    -1,   136,    -1,    -1,    -1,    -1,
     114,   115,   143,   144,    -1,   146,   120,   121,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,
     144,    -1,   146,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    10,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    48,    11,
      12,    -1,    14,    15,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    -1,    48,    -1,    -1,
      -1,    -1,    50,    -1,    55,    -1,    -1,    55,    -1,    -1,
      58,    59,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,   114,   115,    -1,    -1,    -1,    -1,
     120,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,   114,   115,   113,   136,    -1,   116,   120,
     121,   122,   123,   143,   144,    -1,   146,    -1,    -1,   130,
     131,   132,   114,   115,    -1,   136,    10,    -1,   120,   121,
     122,   123,   143,   144,    -1,   146,    -1,    -1,   130,   131,
     132,    -1,    -1,    -1,   136,    -1,    -1,    10,    -1,    -1,
      -1,   143,   144,    -1,   146,    39,    40,    41,    42,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    10,    -1,
      -1,    55,    -1,    -1,    58,    59,    39,    40,    41,    42,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    73,
      -1,    -1,    55,    -1,    -1,    58,    59,    39,    40,    41,
      42,    -1,    44,    87,    -1,    -1,    10,    -1,    50,    -1,
      73,    -1,    -1,    55,    -1,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    10,    -1,   113,
      -1,    73,   116,    -1,    -1,    39,    40,    41,    42,    -1,
      44,    -1,   126,   127,    -1,    87,    50,    -1,    10,    -1,
     113,    55,    -1,   116,    58,    59,    39,    40,    41,    42,
      -1,    -1,    -1,   126,   127,    -1,    -1,    50,   152,    73,
      -1,   113,    55,    -1,   116,    58,    59,    39,    40,    41,
      42,    -1,    -1,    87,   126,   127,    -1,    -1,    50,   152,
      73,    -1,    -1,    55,    -1,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,   113,
     152,    73,   116,    -1,    -1,    -1,    -1,     8,     9,    -1,
      -1,    -1,   126,   127,    -1,    87,    -1,    -1,    -1,    -1,
     113,    -1,    -1,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,   125,    34,    35,    36,    37,    38,   152,    -1,
      -1,   113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,
      -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      39,    40,    41,    42,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    55,    -1,   119,    58,
      59,     3,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,   117,   118,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     3,
      -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,   120,   121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    10,    -1,    -1,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
      39,    40,    41,    42,    -1,    -1,    10,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    55,    -1,   119,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    73,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,    87,    -1,
      -1,    55,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,   113,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,    -1,   116
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    10,    39,    40,    41,    42,    44,    50,    55,    58,
      59,    73,    87,   113,   116,   117,   118,   128,   156,   157,
     158,   159,   161,   163,   189,   217,   218,   221,   222,   223,
     224,   225,   231,   245,   246,   247,   250,   266,   138,   146,
     146,   146,     8,    36,     0,   158,   132,   146,   219,   220,
     221,   248,   249,   252,     8,     9,    34,    35,    36,    37,
      38,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   119,   226,   234,
     240,   244,   223,   218,   218,   218,   218,   218,   224,   225,
       3,   221,   225,   232,   237,   245,   250,     3,     4,     5,
       6,     7,     8,    11,    12,    14,    15,    48,   114,   115,
     120,   121,   122,   123,   130,   131,   132,   136,   143,   144,
     146,   175,   188,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   210,
     211,   212,   216,   237,   250,   251,   258,   216,   250,   216,
     151,     8,   245,   252,   253,   221,   248,   148,   150,     3,
     150,   175,   125,   160,   162,   217,   218,   221,   145,   146,
     251,   249,   146,     3,     8,   151,   233,     3,    10,   151,
     227,   229,   233,   218,   218,   237,   139,   148,   237,   225,
     124,   147,   209,   146,   205,   146,   205,   205,   146,   146,
       8,     3,   190,   191,   193,   205,   258,    23,   141,    22,
     135,   137,   136,    20,    21,    18,    19,   138,   139,    16,
      17,   130,   131,   132,   133,   134,   204,    13,    14,    15,
     145,   146,   147,   153,   145,   146,   252,   259,   260,   204,
     153,   148,   153,   148,   153,   126,   127,   164,   165,   166,
     170,   171,   172,   176,   179,   182,   183,   184,   186,   189,
     218,   151,   245,   252,   153,   220,   248,   190,   151,   270,
     270,   162,   140,    36,   132,   154,   191,   253,   153,   218,
     221,   254,   255,   256,   257,   258,     3,   241,   242,   243,
     151,   152,   235,   236,   237,   266,   151,   138,   151,   237,
     237,     3,   122,   258,   258,   258,   191,   148,   153,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,   140,
     192,   153,   195,   190,   196,   197,   198,   199,   200,   200,
     201,   201,   201,   201,   202,   202,   203,   203,   204,   204,
     204,     3,   175,   190,   153,   191,   215,     3,   175,    36,
     132,   154,   191,   253,   153,   254,   259,   260,   145,   146,
       4,   150,     4,   150,   218,   218,   152,   166,     3,   123,
     173,   174,   185,   187,   252,   127,   167,   168,   169,   170,
     171,   172,   176,   179,   182,   184,   186,   189,   221,   150,
       3,   101,   102,   103,   105,   106,   107,   108,   109,   110,
     111,   112,   150,   152,   189,   190,   217,   250,   267,   268,
     269,   271,   272,   273,   274,   275,   276,   151,   191,   261,
     191,   253,   154,   154,    36,   132,   154,   191,   146,   248,
     252,   259,     3,   153,   148,   148,   153,   153,   148,   152,
     140,   241,   152,   236,   142,   221,   238,   239,   248,   235,
     228,   152,   235,   153,   153,   153,   148,   191,   191,   151,
     204,   142,   154,   148,   153,   191,   253,   154,   154,    36,
     154,   191,   153,   153,    36,   132,   154,   191,   253,   153,
     254,   153,   153,     3,   177,   178,   252,     3,   180,   181,
     252,   146,   146,   125,   221,   270,   125,   150,   270,   125,
     150,   270,   122,   174,   218,   152,   169,   142,   216,   142,
     146,   146,   146,   267,   146,     3,   150,   150,   150,   190,
     150,   270,   152,   272,   145,   147,   261,   262,   263,   264,
     265,   154,   191,   191,   154,   154,   221,    43,   256,   221,
     152,   242,   216,   148,   152,   216,   150,   148,   150,   221,
     152,     3,   230,   237,   152,   102,   213,   214,   258,   262,
     193,   191,   154,   191,   191,   154,   191,   253,   154,   154,
      36,   154,   191,   153,   150,   150,   146,   125,   150,   270,
     178,   146,   125,   150,   270,   181,   153,   254,   153,   190,
     150,   190,   190,   146,   180,   267,   142,   267,   190,   190,
     190,   106,   217,   273,   150,   150,   216,     3,   148,   152,
     261,   140,   265,   154,   154,     3,   152,   239,   142,   139,
     148,   142,   148,   153,   142,   148,   152,   154,   154,   154,
     191,   191,   154,   153,   190,   256,   190,    40,   153,   150,
     150,   150,   153,   254,   267,   153,   153,   153,   146,   273,
     273,   154,   152,   261,   263,   216,     3,   237,   191,   214,
     191,   152,   154,   154,    40,   150,   153,   150,    40,   153,
     267,   267,   267,   190,   153,   190,   153,   190,   261,    40,
     104,   153,   267,   153,   267,   153,   267,   150,   267,   267
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   155,   156,   156,   157,   157,   158,   158,   158,   158,
     158,   159,   160,   159,   161,   162,   162,   163,   163,   164,
     164,   165,   165,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   167,   167,   168,   168,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   170,   171,   172,   173,
     173,   174,   174,   174,   174,   175,   175,   176,   176,   177,
     177,   178,   178,   179,   179,   180,   180,   181,   181,   182,
     183,   184,   184,   184,   185,   185,   186,   186,   186,   187,
     188,   188,   189,   190,   190,   191,   191,   192,   192,   192,
     192,   192,   192,   192,   192,   192,   192,   192,   193,   193,
     194,   194,   195,   195,   196,   196,   197,   197,   198,   198,
     199,   199,   199,   200,   200,   200,   200,   200,   201,   201,
     201,   202,   202,   202,   203,   203,   203,   203,   204,   204,
     205,   205,   205,   205,   205,   205,   205,   205,   206,   206,
     206,   206,   206,   206,   207,   207,   207,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   208,   208,   208,   208,
     208,   208,   208,   208,   208,   208,   208,   208,   209,   209,
     210,   210,   210,   211,   211,   212,   213,   213,   214,   214,
     215,   215,   216,   217,   217,   217,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     219,   219,   220,   220,   221,   221,   222,   222,   223,   224,
     224,   224,   224,   224,   224,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   226,   226,   226,   226,   226,   226,   226,
     228,   227,   229,   229,   230,   230,   230,   230,   230,   231,
     232,   232,   232,   233,   233,   234,   234,   235,   235,   236,
     236,   236,   237,   237,   237,   237,   237,   237,   238,   238,
     239,   239,   239,   240,   240,   240,   240,   240,   241,   241,
     242,   242,   243,   244,   245,   245,   245,   245,   245,   246,
     246,   246,   246,   247,   247,   248,   248,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   250,   251,   252,   252,   252,   252,   253,
     253,   254,   254,   255,   255,   256,   256,   256,   257,   257,
     258,   258,   259,   259,   259,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   261,   261,   261,   262,
     262,   262,   262,   263,   264,   264,   265,   265,   266,   266,
     266,   266,   267,   268,   267,   267,   267,   267,   267,   267,
     269,   269,   269,   270,   270,   271,   271,   272,   272,   273,
     273,   274,   274,   274,   275,   275,   275,   275,   275,   275,
     276,   276,   276,   276,   276
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
       2,     2,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     3,     4,     4,     5,     2,     5,     2,
       0,     5,     1,     1,     0,     1,     3,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     2,     3,
       3,     1,     2,     1,     3,     2,     2,     1,     1,     3,
       2,     4,     2,     4,     5,     5,     6,     2,     1,     3,
       3,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     2,     1,     2,     2,     3,
       3,     4,     6,     5,     5,     6,     5,     4,     4,     4,
       3,     4,     2,     1,     1,     3,     2,     2,     1,     1,
       2,     3,     1,     1,     3,     2,     2,     1,     2,     4,
       2,     1,     2,     1,     1,     3,     2,     3,     5,     4,
       5,     4,     3,     3,     3,     4,     6,     5,     5,     6,
       4,     4,     2,     3,     3,     4,     3,     4,     1,     2,
       1,     4,     3,     2,     1,     2,     3,     2,     7,     5,
       7,     5,     1,     0,     2,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     1,     2,     1,     1,     1,
       2,     7,     5,     5,     5,     7,     6,     7,     6,     7,
       3,     2,     2,     2,     3
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0
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
       0,     0,     0,     0,     0,     0,     0,     0,   139,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   135,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    97,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,    65,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,    67,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     3,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   204,     0,   204,     0,   187,     0,   204,     0,   193,
       0,   204,     0,   195,     0,   204,     0,   197,     0,   204,
       0,   199,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   189,     0,   204,     0,   191,     0,   204,
       0,   273,     0,   204,     0,   277,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   275,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   204,
       0,   204,     0,   204,     0,   204,     0,   204,     0,   402,
       0
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
#line 621 "parser.y"
        { root_node = ((*yyvalp).node) = NULL; }
#line 2968 "parser.tab.c"
    break;

  case 3:
#line 623 "parser.y"
        { root_node = ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2974 "parser.tab.c"
    break;

  case 4:
#line 628 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2980 "parser.tab.c"
    break;

  case 5:
#line 630 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 2986 "parser.tab.c"
    break;

  case 6:
#line 635 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2992 "parser.tab.c"
    break;

  case 7:
#line 637 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 2998 "parser.tab.c"
    break;

  case 8:
#line 639 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3004 "parser.tab.c"
    break;

  case 9:
#line 642 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3010 "parser.tab.c"
    break;

  case 10:
#line 651 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3016 "parser.tab.c"
    break;

  case 11:
#line 656 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3022 "parser.tab.c"
    break;

  case 12:
#line 658 "parser.y"
                { symbol_table_push_scope(); }
#line 3028 "parser.tab.c"
    break;

  case 13:
#line 660 "parser.y"
                { symbol_table_pop_scope(); ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3034 "parser.tab.c"
    break;

  case 14:
#line 680 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3040 "parser.tab.c"
    break;

  case 15:
#line 685 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3046 "parser.tab.c"
    break;

  case 16:
#line 687 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3052 "parser.tab.c"
    break;

  case 17:
#line 699 "parser.y"
        { ((*yyvalp).node) = create_impl_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3058 "parser.tab.c"
    break;

  case 18:
#line 701 "parser.y"
        { ((*yyvalp).node) = create_static_impl_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3064 "parser.tab.c"
    break;

  case 19:
#line 705 "parser.y"
                 { ((*yyvalp).node) = NULL; }
#line 3070 "parser.tab.c"
    break;

  case 20:
#line 706 "parser.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3076 "parser.tab.c"
    break;

  case 21:
#line 711 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3082 "parser.tab.c"
    break;

  case 22:
#line 713 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3088 "parser.tab.c"
    break;

  case 23:
#line 718 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3094 "parser.tab.c"
    break;

  case 24:
#line 720 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3100 "parser.tab.c"
    break;

  case 25:
#line 722 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3106 "parser.tab.c"
    break;

  case 26:
#line 724 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3112 "parser.tab.c"
    break;

  case 27:
#line 726 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3118 "parser.tab.c"
    break;

  case 28:
#line 728 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3124 "parser.tab.c"
    break;

  case 29:
#line 730 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3130 "parser.tab.c"
    break;

  case 30:
#line 732 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3136 "parser.tab.c"
    break;

  case 31:
#line 734 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3142 "parser.tab.c"
    break;

  case 32:
#line 736 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3148 "parser.tab.c"
    break;

  case 33:
#line 741 "parser.y"
                 { ((*yyvalp).node) = NULL; }
#line 3154 "parser.tab.c"
    break;

  case 34:
#line 742 "parser.y"
                                   { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3160 "parser.tab.c"
    break;

  case 35:
#line 747 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3166 "parser.tab.c"
    break;

  case 36:
#line 749 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3172 "parser.tab.c"
    break;

  case 37:
#line 754 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3178 "parser.tab.c"
    break;

  case 38:
#line 756 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3184 "parser.tab.c"
    break;

  case 39:
#line 758 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3190 "parser.tab.c"
    break;

  case 40:
#line 760 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3196 "parser.tab.c"
    break;

  case 41:
#line 762 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3202 "parser.tab.c"
    break;

  case 42:
#line 764 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3208 "parser.tab.c"
    break;

  case 43:
#line 766 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3214 "parser.tab.c"
    break;

  case 44:
#line 768 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3220 "parser.tab.c"
    break;

  case 45:
#line 770 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3226 "parser.tab.c"
    break;

  case 46:
#line 777 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3232 "parser.tab.c"
    break;

  case 47:
#line 800 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3238 "parser.tab.c"
    break;

  case 48:
#line 805 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL, NULL); }
#line 3244 "parser.tab.c"
    break;

  case 49:
#line 810 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3250 "parser.tab.c"
    break;

  case 50:
#line 812 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3256 "parser.tab.c"
    break;

  case 51:
#line 817 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3262 "parser.tab.c"
    break;

  case 52:
#line 819 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 3268 "parser.tab.c"
    break;

  case 53:
#line 827 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), CONST_NODE); }
#line 3274 "parser.tab.c"
    break;

  case 54:
#line 829 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, CONST_NODE); }
#line 3280 "parser.tab.c"
    break;

  case 55:
#line 848 "parser.y"
               { ((*yyvalp).node) = THIS_NODE; }
#line 3286 "parser.tab.c"
    break;

  case 56:
#line 849 "parser.y"
               { ((*yyvalp).node) = SELF_NODE; }
#line 3292 "parser.tab.c"
    break;

  case 57:
#line 854 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3298 "parser.tab.c"
    break;

  case 58:
#line 862 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3304 "parser.tab.c"
    break;

  case 59:
#line 871 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3310 "parser.tab.c"
    break;

  case 60:
#line 873 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3316 "parser.tab.c"
    break;

  case 61:
#line 878 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 3322 "parser.tab.c"
    break;

  case 62:
#line 880 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, CONST_NODE); }
#line 3328 "parser.tab.c"
    break;

  case 63:
#line 885 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3334 "parser.tab.c"
    break;

  case 64:
#line 893 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3340 "parser.tab.c"
    break;

  case 65:
#line 902 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3346 "parser.tab.c"
    break;

  case 66:
#line 904 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3352 "parser.tab.c"
    break;

  case 67:
#line 909 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3358 "parser.tab.c"
    break;

  case 68:
#line 911 "parser.y"
        { ((*yyvalp).node) = (void *) & error_node; fprintf(stderr, "'setter' functions cannot be 'const'!\n"); exit(EXIT_FAILURE); }
#line 3364 "parser.tab.c"
    break;

  case 69:
#line 916 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3370 "parser.tab.c"
    break;

  case 70:
#line 925 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3376 "parser.tab.c"
    break;

  case 71:
#line 958 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3382 "parser.tab.c"
    break;

  case 72:
#line 960 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3388 "parser.tab.c"
    break;

  case 73:
#line 962 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3394 "parser.tab.c"
    break;

  case 74:
#line 971 "parser.y"
        { ((*yyvalp).node) = create_new_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 3400 "parser.tab.c"
    break;

  case 75:
#line 973 "parser.y"
        { ((*yyvalp).node) = create_new_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3406 "parser.tab.c"
    break;

  case 76:
#line 979 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3412 "parser.tab.c"
    break;

  case 77:
#line 982 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3418 "parser.tab.c"
    break;

  case 78:
#line 985 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3424 "parser.tab.c"
    break;

  case 79:
#line 990 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node(NULL, NULL, NULL); }
#line 3430 "parser.tab.c"
    break;

  case 80:
#line 1058 "parser.y"
        { ((*yyvalp).node) = create_function_call_node(create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), (void *) & delete_as_id_node), NULL); }
#line 3436 "parser.tab.c"
    break;

  case 81:
#line 1060 "parser.y"
        { ((*yyvalp).node) = (void *) & delete_as_id_node; }
#line 3442 "parser.tab.c"
    break;

  case 82:
#line 1082 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3448 "parser.tab.c"
    break;

  case 83:
#line 1098 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3454 "parser.tab.c"
    break;

  case 84:
#line 1100 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 3460 "parser.tab.c"
    break;

  case 85:
#line 1105 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3466 "parser.tab.c"
    break;

  case 86:
#line 1107 "parser.y"
        { ((*yyvalp).node) = create_binary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3472 "parser.tab.c"
    break;

  case 87:
#line 1111 "parser.y"
                     { ((*yyvalp).type) = AST_ASSIGN; }
#line 3478 "parser.tab.c"
    break;

  case 88:
#line 1112 "parser.y"
                     { ((*yyvalp).type) = AST_MUL_ASSIGN; }
#line 3484 "parser.tab.c"
    break;

  case 89:
#line 1113 "parser.y"
                     { ((*yyvalp).type) = AST_DIV_ASSIGN; }
#line 3490 "parser.tab.c"
    break;

  case 90:
#line 1114 "parser.y"
                     { ((*yyvalp).type) = AST_MOD_ASSIGN; }
#line 3496 "parser.tab.c"
    break;

  case 91:
#line 1115 "parser.y"
                     { ((*yyvalp).type) = AST_ADD_ASSIGN; }
#line 3502 "parser.tab.c"
    break;

  case 92:
#line 1116 "parser.y"
                     { ((*yyvalp).type) = AST_SUB_ASSIGN; }
#line 3508 "parser.tab.c"
    break;

  case 93:
#line 1117 "parser.y"
                     { ((*yyvalp).type) = AST_SHL_ASSIGN; }
#line 3514 "parser.tab.c"
    break;

  case 94:
#line 1118 "parser.y"
                     { ((*yyvalp).type) = AST_SHR_ASSIGN; }
#line 3520 "parser.tab.c"
    break;

  case 95:
#line 1119 "parser.y"
                     { ((*yyvalp).type) = AST_AND_ASSIGN; }
#line 3526 "parser.tab.c"
    break;

  case 96:
#line 1120 "parser.y"
                     { ((*yyvalp).type) = AST_XOR_ASSIGN; }
#line 3532 "parser.tab.c"
    break;

  case 97:
#line 1121 "parser.y"
                     { ((*yyvalp).type) = AST_OR_ASSIGN; }
#line 3538 "parser.tab.c"
    break;

  case 98:
#line 1127 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3544 "parser.tab.c"
    break;

  case 99:
#line 1129 "parser.y"
        { ((*yyvalp).node) = create_ternary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3550 "parser.tab.c"
    break;

  case 100:
#line 1134 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3556 "parser.tab.c"
    break;

  case 101:
#line 1136 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_OR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3562 "parser.tab.c"
    break;

  case 102:
#line 1141 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3568 "parser.tab.c"
    break;

  case 103:
#line 1143 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_AND, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3574 "parser.tab.c"
    break;

  case 104:
#line 1148 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3580 "parser.tab.c"
    break;

  case 105:
#line 1150 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_OR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3586 "parser.tab.c"
    break;

  case 106:
#line 1155 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3592 "parser.tab.c"
    break;

  case 107:
#line 1157 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_XOR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3598 "parser.tab.c"
    break;

  case 108:
#line 1162 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3604 "parser.tab.c"
    break;

  case 109:
#line 1164 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_AND, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3610 "parser.tab.c"
    break;

  case 110:
#line 1169 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3616 "parser.tab.c"
    break;

  case 111:
#line 1171 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_EQ, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3622 "parser.tab.c"
    break;

  case 112:
#line 1173 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3628 "parser.tab.c"
    break;

  case 113:
#line 1178 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3634 "parser.tab.c"
    break;

  case 114:
#line 1180 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_LT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3640 "parser.tab.c"
    break;

  case 115:
#line 1182 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_GT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3646 "parser.tab.c"
    break;

  case 116:
#line 1184 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_LE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3652 "parser.tab.c"
    break;

  case 117:
#line 1186 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_GE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3658 "parser.tab.c"
    break;

  case 118:
#line 1191 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3664 "parser.tab.c"
    break;

  case 119:
#line 1193 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SHL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3670 "parser.tab.c"
    break;

  case 120:
#line 1195 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SHR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3676 "parser.tab.c"
    break;

  case 121:
#line 1200 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3682 "parser.tab.c"
    break;

  case 122:
#line 1202 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ADD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3688 "parser.tab.c"
    break;

  case 123:
#line 1204 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SUB, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3694 "parser.tab.c"
    break;

  case 124:
#line 1209 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3700 "parser.tab.c"
    break;

  case 125:
#line 1211 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_MUL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3706 "parser.tab.c"
    break;

  case 126:
#line 1213 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_DIV, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3712 "parser.tab.c"
    break;

  case 127:
#line 1215 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_MOD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3718 "parser.tab.c"
    break;

  case 128:
#line 1229 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3724 "parser.tab.c"
    break;

  case 129:
#line 1233 "parser.y"
        { ((*yyvalp).node) = create_cast_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3730 "parser.tab.c"
    break;

  case 130:
#line 1238 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3736 "parser.tab.c"
    break;

  case 131:
#line 1240 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_PRE_INC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3742 "parser.tab.c"
    break;

  case 132:
#line 1242 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_PRE_DEC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3748 "parser.tab.c"
    break;

  case 133:
#line 1244 "parser.y"
        { ((*yyvalp).node) = create_unary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3754 "parser.tab.c"
    break;

  case 134:
#line 1246 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_SIZEOF_EXPR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3760 "parser.tab.c"
    break;

  case 135:
#line 1248 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_SIZEOF_TYPE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3766 "parser.tab.c"
    break;

  case 136:
#line 1250 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_ALIGNOF, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3772 "parser.tab.c"
    break;

  case 137:
#line 1257 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3778 "parser.tab.c"
    break;

  case 138:
#line 1261 "parser.y"
              { ((*yyvalp).type) = AST_ADDRESS_OF; }
#line 3784 "parser.tab.c"
    break;

  case 139:
#line 1262 "parser.y"
              { ((*yyvalp).type) = AST_DEREFERENCE; }
#line 3790 "parser.tab.c"
    break;

  case 140:
#line 1263 "parser.y"
              { ((*yyvalp).type) = AST_POSITIVE; }
#line 3796 "parser.tab.c"
    break;

  case 141:
#line 1264 "parser.y"
              { ((*yyvalp).type) = AST_NEGATIVE; }
#line 3802 "parser.tab.c"
    break;

  case 142:
#line 1265 "parser.y"
              { ((*yyvalp).type) = AST_BITWISE_NOT; }
#line 3808 "parser.tab.c"
    break;

  case 143:
#line 1266 "parser.y"
              { ((*yyvalp).type) = AST_LOGICAL_NOT; }
#line 3814 "parser.tab.c"
    break;

  case 144:
#line 1271 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3820 "parser.tab.c"
    break;

  case 145:
#line 1273 "parser.y"
        { ((*yyvalp).node) = create_array_subscript_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3826 "parser.tab.c"
    break;

  case 146:
#line 1275 "parser.y"
        { ((*yyvalp).node) = create_function_call_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 3832 "parser.tab.c"
    break;

  case 147:
#line 1277 "parser.y"
        { ((*yyvalp).node) = create_function_call_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3838 "parser.tab.c"
    break;

  case 148:
#line 1287 "parser.y"
        { ((*yyvalp).node) = create_member_access_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_THIS || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_SELF ? AST_MEMBER_ACCESS_POINTER : AST_MEMBER_ACCESS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3844 "parser.tab.c"
    break;

  case 149:
#line 1291 "parser.y"
        { ((*yyvalp).node) = create_member_access_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_THIS || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_SELF ? AST_MEMBER_ACCESS_POINTER : AST_MEMBER_ACCESS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3850 "parser.tab.c"
    break;

  case 150:
#line 1293 "parser.y"
        { ((*yyvalp).node) = create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3856 "parser.tab.c"
    break;

  case 151:
#line 1302 "parser.y"
        { ((*yyvalp).node) = create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3862 "parser.tab.c"
    break;

  case 152:
#line 1304 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_POST_INC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3868 "parser.tab.c"
    break;

  case 153:
#line 1306 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_POST_DEC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3874 "parser.tab.c"
    break;

  case 154:
#line 1309 "parser.y"
        { ((*yyvalp).node) = create_compound_literal_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3880 "parser.tab.c"
    break;

  case 155:
#line 1311 "parser.y"
        { ((*yyvalp).node) = create_compound_literal_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 3886 "parser.tab.c"
    break;

  case 156:
#line 1316 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3892 "parser.tab.c"
    break;

  case 157:
#line 1318 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3898 "parser.tab.c"
    break;

  case 158:
#line 1320 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3904 "parser.tab.c"
    break;

  case 159:
#line 1322 "parser.y"
        { ((*yyvalp).node) = create_expression_group_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3910 "parser.tab.c"
    break;

  case 160:
#line 1324 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3916 "parser.tab.c"
    break;

  case 161:
#line 1333 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3922 "parser.tab.c"
    break;

  case 162:
#line 1342 "parser.y"
        {
		sprintf(func_name, "%s__new", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id);
		((*yyvalp).node) = create_id_node(func_name);
	}
#line 3931 "parser.tab.c"
    break;

  case 163:
#line 1347 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NS_OP, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (void *) & new_as_id_node); }
#line 3937 "parser.tab.c"
    break;

  case 164:
#line 1349 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NS_OP, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3943 "parser.tab.c"
    break;

  case 165:
#line 1352 "parser.y"
        { ((*yyvalp).node) = (void *) & new_as_id_node; }
#line 3949 "parser.tab.c"
    break;

  case 166:
#line 1355 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3955 "parser.tab.c"
    break;

  case 167:
#line 1358 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3961 "parser.tab.c"
    break;

  case 170:
#line 1369 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3967 "parser.tab.c"
    break;

  case 171:
#line 1371 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3973 "parser.tab.c"
    break;

  case 172:
#line 1373 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3979 "parser.tab.c"
    break;

  case 173:
#line 1383 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3985 "parser.tab.c"
    break;

  case 174:
#line 1385 "parser.y"
        { ((*yyvalp).node) = (void *) & ___func__node; }
#line 3991 "parser.tab.c"
    break;

  case 175:
#line 1390 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 3997 "parser.tab.c"
    break;

  case 180:
#line 1405 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4003 "parser.tab.c"
    break;

  case 181:
#line 1407 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4009 "parser.tab.c"
    break;

  case 182:
#line 1433 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4015 "parser.tab.c"
    break;

  case 183:
#line 1438 "parser.y"
        { ((*yyvalp).node) = create_declaration_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL); }
#line 4021 "parser.tab.c"
    break;

  case 184:
#line 1440 "parser.y"
        { ((*yyvalp).node) = create_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); register_typedef((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4027 "parser.tab.c"
    break;

  case 185:
#line 1453 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4033 "parser.tab.c"
    break;

  case 186:
#line 1459 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4039 "parser.tab.c"
    break;

  case 187:
#line 1461 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4045 "parser.tab.c"
    break;

  case 188:
#line 1463 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 4051 "parser.tab.c"
    break;

  case 189:
#line 1465 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4057 "parser.tab.c"
    break;

  case 190:
#line 1468 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 4063 "parser.tab.c"
    break;

  case 191:
#line 1470 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4069 "parser.tab.c"
    break;

  case 192:
#line 1473 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4075 "parser.tab.c"
    break;

  case 193:
#line 1475 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4081 "parser.tab.c"
    break;

  case 194:
#line 1478 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4087 "parser.tab.c"
    break;

  case 195:
#line 1480 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4093 "parser.tab.c"
    break;

  case 196:
#line 1483 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4099 "parser.tab.c"
    break;

  case 197:
#line 1485 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4105 "parser.tab.c"
    break;

  case 198:
#line 1488 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4111 "parser.tab.c"
    break;

  case 199:
#line 1490 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4117 "parser.tab.c"
    break;

  case 200:
#line 1495 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4123 "parser.tab.c"
    break;

  case 201:
#line 1497 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4129 "parser.tab.c"
    break;

  case 202:
#line 1502 "parser.y"
        { ((*yyvalp).node) = create_init_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4135 "parser.tab.c"
    break;

  case 203:
#line 1504 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4141 "parser.tab.c"
    break;

  case 204:
#line 1522 "parser.y"
                     { ((*yyvalp).node) = NULL; }
#line 4147 "parser.tab.c"
    break;

  case 205:
#line 1523 "parser.y"
                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4153 "parser.tab.c"
    break;

  case 206:
#line 1528 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4159 "parser.tab.c"
    break;

  case 207:
#line 1530 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4165 "parser.tab.c"
    break;

  case 208:
#line 1535 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4171 "parser.tab.c"
    break;

  case 209:
#line 1551 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), TYPEDEF_NODE); }
#line 4177 "parser.tab.c"
    break;

  case 210:
#line 1559 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), EXTERN_NODE); }
#line 4183 "parser.tab.c"
    break;

  case 211:
#line 1563 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), STATIC_NODE); }
#line 4189 "parser.tab.c"
    break;

  case 212:
#line 1565 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), THREAD_LOCAL_NODE); }
#line 4195 "parser.tab.c"
    break;

  case 213:
#line 1567 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), AUTO_NODE); }
#line 4201 "parser.tab.c"
    break;

  case 214:
#line 1569 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), REGISTER_NODE); }
#line 4207 "parser.tab.c"
    break;

  case 215:
#line 1580 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), VOID_NODE); }
#line 4213 "parser.tab.c"
    break;

  case 216:
#line 1582 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), CHAR_NODE); }
#line 4219 "parser.tab.c"
    break;

  case 217:
#line 1584 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), SHORT_NODE); }
#line 4225 "parser.tab.c"
    break;

  case 218:
#line 1586 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), INT_NODE); }
#line 4231 "parser.tab.c"
    break;

  case 219:
#line 1588 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), LONG_NODE); }
#line 4237 "parser.tab.c"
    break;

  case 220:
#line 1590 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), FLOAT_NODE); }
#line 4243 "parser.tab.c"
    break;

  case 221:
#line 1592 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), DOUBLE_NODE); }
#line 4249 "parser.tab.c"
    break;

  case 222:
#line 1594 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), SIGNED_NODE); }
#line 4255 "parser.tab.c"
    break;

  case 223:
#line 1596 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), UNSIGNED_NODE); }
#line 4261 "parser.tab.c"
    break;

  case 224:
#line 1598 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), BOOL_NODE); }
#line 4267 "parser.tab.c"
    break;

  case 225:
#line 1600 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), COMPLEX_NODE); }
#line 4273 "parser.tab.c"
    break;

  case 226:
#line 1602 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), IMAGINARY_NODE); }
#line 4279 "parser.tab.c"
    break;

  case 227:
#line 1604 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4285 "parser.tab.c"
    break;

  case 228:
#line 1606 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4291 "parser.tab.c"
    break;

  case 229:
#line 1608 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4297 "parser.tab.c"
    break;

  case 230:
#line 1610 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4303 "parser.tab.c"
    break;

  case 231:
#line 1618 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4309 "parser.tab.c"
    break;

  case 232:
#line 1621 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4315 "parser.tab.c"
    break;

  case 233:
#line 1636 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), BUILTIN_VA_LIST_NODE); }
#line 4321 "parser.tab.c"
    break;

  case 234:
#line 1640 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), DECIMAL32_NODE); }
#line 4327 "parser.tab.c"
    break;

  case 235:
#line 1642 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), DECIMAL64_NODE); }
#line 4333 "parser.tab.c"
    break;

  case 236:
#line 1644 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), DECIMAL128_NODE); }
#line 4339 "parser.tab.c"
    break;

  case 237:
#line 1647 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), FLOAT128_NODE); }
#line 4345 "parser.tab.c"
    break;

  case 238:
#line 1649 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), INT128_NODE); }
#line 4351 "parser.tab.c"
    break;

  case 239:
#line 1651 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), INT128_T_NODE); }
#line 4357 "parser.tab.c"
    break;

  case 240:
#line 1653 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), UINT128_T_NODE); }
#line 4363 "parser.tab.c"
    break;

  case 241:
#line 1656 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), BITINT128_NODE); }
#line 4369 "parser.tab.c"
    break;

  case 242:
#line 1658 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4375 "parser.tab.c"
    break;

  case 243:
#line 1665 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.type), NULL, NULL); }
#line 4381 "parser.tab.c"
    break;

  case 244:
#line 1667 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4387 "parser.tab.c"
    break;

  case 245:
#line 1669 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4393 "parser.tab.c"
    break;

  case 246:
#line 1671 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4399 "parser.tab.c"
    break;

  case 247:
#line 1673 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4405 "parser.tab.c"
    break;

  case 248:
#line 1676 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type) == AST_STRUCT ? AST_GENERIC_STRUCT : AST_GENERIC_UNION, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
		// symbol_update_generic(get_id_node($2)->id.id, $$);
	}
#line 4415 "parser.tab.c"
    break;

  case 249:
#line 1682 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type) == AST_STRUCT ? AST_GENERIC_STRUCT : AST_GENERIC_UNION, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL);
		// symbol_add_generic_name(get_id_node($2)->id.id, NULL);
	}
#line 4425 "parser.tab.c"
    break;

  case 250:
#line 1697 "parser.y"
                                         { symbol_table_push_scope(); }
#line 4431 "parser.tab.c"
    break;

  case 251:
#line 1698 "parser.y"
        { ((*yyvalp).node) = create_generic_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), yyfilename, yylineno); }
#line 4437 "parser.tab.c"
    break;

  case 252:
#line 1703 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); symbol_add_generic((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id, NULL); }
#line 4443 "parser.tab.c"
    break;

  case 253:
#line 1705 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4449 "parser.tab.c"
    break;

  case 254:
#line 1710 "parser.y"
        { ((*yyvalp).node) = NULL; }
#line 4455 "parser.tab.c"
    break;

  case 255:
#line 1712 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); symbol_add_generic_type((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4461 "parser.tab.c"
    break;

  case 256:
#line 1714 "parser.y"
        { ((*yyvalp).node) = create_generic_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); symbol_add_generic_type((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4467 "parser.tab.c"
    break;

  case 257:
#line 1726 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4473 "parser.tab.c"
    break;

  case 258:
#line 1728 "parser.y"
        { ((*yyvalp).node) = create_generic_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4479 "parser.tab.c"
    break;

  case 259:
#line 1733 "parser.y"
        { ((*yyvalp).node) = create_generic_specifier_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), yyfilename, yylineno); }
#line 4485 "parser.tab.c"
    break;

  case 260:
#line 1738 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4491 "parser.tab.c"
    break;

  case 261:
#line 1740 "parser.y"
        { ((*yyvalp).node) = create_generic_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4497 "parser.tab.c"
    break;

  case 262:
#line 1742 "parser.y"
        {
		char buf[512];
		snprintf(buf, 512,
			"Syntax error: unexpected token `%s` on line %d.\n"
			"> Only concrete types or pre-defined generic types within a generic struct allowed.\n"
			"> Are you trying to declare a generic typedef with `typedef struct Foo<> Foo<%s>;`\n"
			"> Or are you trying to declare a variable with a generic typename `Foo<%s> foo;` outside a generic struct?\n"
			"> You cannot declare a generic typedef or variable this way,"
			" as the <%s> is not valid outside a generic struct or `impl` block!",
			(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id,
			yylineno,
			(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id,
			(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id,
			(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id);
		yyerror(buf);
		// fprintf(stderr, "Syntax error: unexpected token %s at line %d\n", $1->id.id, @1.first_line);
		YYERROR;
	}
#line 4520 "parser.tab.c"
    break;

  case 265:
#line 1789 "parser.y"
                 { ((*yyvalp).type) = AST_STRUCT; }
#line 4526 "parser.tab.c"
    break;

  case 266:
#line 1790 "parser.y"
                 { ((*yyvalp).type) = AST_UNION; }
#line 4532 "parser.tab.c"
    break;

  case 267:
#line 1795 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4538 "parser.tab.c"
    break;

  case 268:
#line 1797 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 4544 "parser.tab.c"
    break;

  case 269:
#line 1802 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declaration_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL); }
#line 4550 "parser.tab.c"
    break;

  case 270:
#line 1804 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4556 "parser.tab.c"
    break;

  case 271:
#line 1806 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4562 "parser.tab.c"
    break;

  case 272:
#line 1811 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4568 "parser.tab.c"
    break;

  case 273:
#line 1813 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4574 "parser.tab.c"
    break;

  case 274:
#line 1816 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 4580 "parser.tab.c"
    break;

  case 275:
#line 1818 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4586 "parser.tab.c"
    break;

  case 276:
#line 1821 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4592 "parser.tab.c"
    break;

  case 277:
#line 1823 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4598 "parser.tab.c"
    break;

  case 278:
#line 1828 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4604 "parser.tab.c"
    break;

  case 279:
#line 1830 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4610 "parser.tab.c"
    break;

  case 280:
#line 1835 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), NULL); }
#line 4616 "parser.tab.c"
    break;

  case 281:
#line 1838 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4622 "parser.tab.c"
    break;

  case 282:
#line 1841 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4628 "parser.tab.c"
    break;

  case 283:
#line 1846 "parser.y"
        { ((*yyvalp).node) = create_enum_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4634 "parser.tab.c"
    break;

  case 284:
#line 1849 "parser.y"
        { ((*yyvalp).node) = create_enum_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4640 "parser.tab.c"
    break;

  case 285:
#line 1852 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4646 "parser.tab.c"
    break;

  case 286:
#line 1855 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4652 "parser.tab.c"
    break;

  case 287:
#line 1858 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4658 "parser.tab.c"
    break;

  case 288:
#line 1863 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4664 "parser.tab.c"
    break;

  case 289:
#line 1865 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ",\n"); }
#line 4670 "parser.tab.c"
    break;

  case 290:
#line 1870 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ENUM_INIT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); symbol_add_enum_constant((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->id.id, ((*yyvalp).node)); }
#line 4676 "parser.tab.c"
    break;

  case 291:
#line 1873 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ENUM_INIT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); symbol_add_enum_constant((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id, ((*yyvalp).node)); }
#line 4682 "parser.tab.c"
    break;

  case 292:
#line 1877 "parser.y"
                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4688 "parser.tab.c"
    break;

  case 293:
#line 1883 "parser.y"
        { ((*yyvalp).node) = create_atomic_type_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4694 "parser.tab.c"
    break;

  case 294:
#line 1887 "parser.y"
                     { ((*yyvalp).node) = CONST_NODE; }
#line 4700 "parser.tab.c"
    break;

  case 295:
#line 1888 "parser.y"
                     { ((*yyvalp).node) = RESTRICT_NODE; }
#line 4706 "parser.tab.c"
    break;

  case 296:
#line 1889 "parser.y"
                     { ((*yyvalp).node) = _RESTRICT_NODE; }
#line 4712 "parser.tab.c"
    break;

  case 297:
#line 1890 "parser.y"
                     { ((*yyvalp).node) = VOLATILE_NODE; }
#line 4718 "parser.tab.c"
    break;

  case 298:
#line 1891 "parser.y"
                     { ((*yyvalp).node) = ATOMIC_NODE; }
#line 4724 "parser.tab.c"
    break;

  case 299:
#line 1895 "parser.y"
                        { ((*yyvalp).node) = INLINE_NODE; }
#line 4730 "parser.tab.c"
    break;

  case 300:
#line 1896 "parser.y"
                        { ((*yyvalp).node) = NORETURN_NODE; }
#line 4736 "parser.tab.c"
    break;

  case 301:
#line 1898 "parser.y"
                        { ((*yyvalp).node) = ___INLINE_NODE; }
#line 4742 "parser.tab.c"
    break;

  case 302:
#line 1899 "parser.y"
                        { ((*yyvalp).node) = ___INLINE___NODE; }
#line 4748 "parser.tab.c"
    break;

  case 303:
#line 1904 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 4754 "parser.tab.c"
    break;

  case 304:
#line 1906 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 4760 "parser.tab.c"
    break;

  case 305:
#line 1911 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4766 "parser.tab.c"
    break;

  case 306:
#line 1913 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4772 "parser.tab.c"
    break;

  case 307:
#line 1918 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4778 "parser.tab.c"
    break;

  case 308:
#line 1921 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4784 "parser.tab.c"
    break;

  case 309:
#line 1924 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4790 "parser.tab.c"
    break;

  case 310:
#line 1926 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4796 "parser.tab.c"
    break;

  case 311:
#line 1928 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 4802 "parser.tab.c"
    break;

  case 312:
#line 1930 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4808 "parser.tab.c"
    break;

  case 313:
#line 1932 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4814 "parser.tab.c"
    break;

  case 314:
#line 1934 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4820 "parser.tab.c"
    break;

  case 315:
#line 1936 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4826 "parser.tab.c"
    break;

  case 316:
#line 1938 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4832 "parser.tab.c"
    break;

  case 317:
#line 1940 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4838 "parser.tab.c"
    break;

  case 318:
#line 1942 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4844 "parser.tab.c"
    break;

  case 319:
#line 1946 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 4850 "parser.tab.c"
    break;

  case 320:
#line 1948 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 4856 "parser.tab.c"
    break;

  case 321:
#line 1950 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4862 "parser.tab.c"
    break;

  case 322:
#line 1957 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4868 "parser.tab.c"
    break;

  case 323:
#line 1964 "parser.y"
                        { ((*yyvalp).node) = ___EXTENSION___NODE; }
#line 4874 "parser.tab.c"
    break;

  case 324:
#line 1970 "parser.y"
                  { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4880 "parser.tab.c"
    break;

  case 325:
#line 1976 "parser.y"
        { ((*yyvalp).node) = create_pointer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4886 "parser.tab.c"
    break;

  case 326:
#line 1978 "parser.y"
        { ((*yyvalp).node) = create_pointer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4892 "parser.tab.c"
    break;

  case 327:
#line 1980 "parser.y"
        { ((*yyvalp).node) = create_pointer_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4898 "parser.tab.c"
    break;

  case 328:
#line 1982 "parser.y"
        { ((*yyvalp).node) = POINTER_NODE; }
#line 4904 "parser.tab.c"
    break;

  case 329:
#line 1987 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4910 "parser.tab.c"
    break;

  case 330:
#line 1989 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), " "); }
#line 4916 "parser.tab.c"
    break;

  case 331:
#line 1994 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), ELLIPSIS_NODE, ", "); }
#line 4922 "parser.tab.c"
    break;

  case 332:
#line 1996 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4928 "parser.tab.c"
    break;

  case 333:
#line 2001 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4934 "parser.tab.c"
    break;

  case 334:
#line 2003 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4940 "parser.tab.c"
    break;

  case 335:
#line 2008 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4946 "parser.tab.c"
    break;

  case 336:
#line 2010 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4952 "parser.tab.c"
    break;

  case 337:
#line 2012 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4958 "parser.tab.c"
    break;

  case 338:
#line 2020 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4964 "parser.tab.c"
    break;

  case 339:
#line 2023 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), ", "); }
#line 4970 "parser.tab.c"
    break;

  case 340:
#line 2028 "parser.y"
        { ((*yyvalp).node) = create_abstract_type_name_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4976 "parser.tab.c"
    break;

  case 341:
#line 2030 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4982 "parser.tab.c"
    break;

  case 342:
#line 2035 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4988 "parser.tab.c"
    break;

  case 343:
#line 2037 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4994 "parser.tab.c"
    break;

  case 344:
#line 2039 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5000 "parser.tab.c"
    break;

  case 345:
#line 2045 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5006 "parser.tab.c"
    break;

  case 346:
#line 2047 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node(NULL, NULL); }
#line 5012 "parser.tab.c"
    break;

  case 347:
#line 2049 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node(NULL, NULL); }
#line 5018 "parser.tab.c"
    break;

  case 348:
#line 2051 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5024 "parser.tab.c"
    break;

  case 349:
#line 2053 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5030 "parser.tab.c"
    break;

  case 350:
#line 2055 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5036 "parser.tab.c"
    break;

  case 351:
#line 2057 "parser.y"
        { ((*yyvalp).node) = create_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5042 "parser.tab.c"
    break;

  case 352:
#line 2059 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5048 "parser.tab.c"
    break;

  case 353:
#line 2061 "parser.y"
        { ((*yyvalp).node) = create_array_node(NULL, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5054 "parser.tab.c"
    break;

  case 354:
#line 2063 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 5060 "parser.tab.c"
    break;

  case 355:
#line 2065 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 5066 "parser.tab.c"
    break;

  case 356:
#line 2067 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5072 "parser.tab.c"
    break;

  case 357:
#line 2069 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5078 "parser.tab.c"
    break;

  case 358:
#line 2071 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5084 "parser.tab.c"
    break;

  case 359:
#line 2073 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5090 "parser.tab.c"
    break;

  case 360:
#line 2075 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5096 "parser.tab.c"
    break;

  case 361:
#line 2077 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5102 "parser.tab.c"
    break;

  case 362:
#line 2079 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node(NULL); }
#line 5108 "parser.tab.c"
    break;

  case 363:
#line 2081 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 5114 "parser.tab.c"
    break;

  case 364:
#line 2083 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 5120 "parser.tab.c"
    break;

  case 365:
#line 2085 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 5126 "parser.tab.c"
    break;

  case 366:
#line 2090 "parser.y"
        { ((*yyvalp).node) = create_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5132 "parser.tab.c"
    break;

  case 367:
#line 2092 "parser.y"
        { ((*yyvalp).node) = create_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5138 "parser.tab.c"
    break;

  case 368:
#line 2094 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5144 "parser.tab.c"
    break;

  case 369:
#line 2099 "parser.y"
        { ((*yyvalp).node) = create_designation_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5150 "parser.tab.c"
    break;

  case 370:
#line 2101 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5156 "parser.tab.c"
    break;

  case 371:
#line 2103 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_designation_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), ", "); }
#line 5162 "parser.tab.c"
    break;

  case 372:
#line 2105 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 5168 "parser.tab.c"
    break;

  case 373:
#line 2110 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 5174 "parser.tab.c"
    break;

  case 374:
#line 2115 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5180 "parser.tab.c"
    break;

  case 375:
#line 2117 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 5186 "parser.tab.c"
    break;

  case 376:
#line 2122 "parser.y"
        { ((*yyvalp).node) = create_designator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 5192 "parser.tab.c"
    break;

  case 377:
#line 2124 "parser.y"
        { ((*yyvalp).node) = create_designator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5198 "parser.tab.c"
    break;

  case 378:
#line 2140 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST__STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5204 "parser.tab.c"
    break;

  case 379:
#line 2142 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST__STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 5210 "parser.tab.c"
    break;

  case 380:
#line 2144 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST_STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5216 "parser.tab.c"
    break;

  case 381:
#line 2146 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST_STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 5222 "parser.tab.c"
    break;

  case 382:
#line 2150 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5228 "parser.tab.c"
    break;

  case 383:
#line 2152 "parser.y"
                { symbol_table_push_scope(); }
#line 5234 "parser.tab.c"
    break;

  case 384:
#line 2154 "parser.y"
                { symbol_table_pop_scope(); ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5240 "parser.tab.c"
    break;

  case 385:
#line 2155 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5246 "parser.tab.c"
    break;

  case 386:
#line 2156 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5252 "parser.tab.c"
    break;

  case 387:
#line 2157 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5258 "parser.tab.c"
    break;

  case 388:
#line 2158 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5264 "parser.tab.c"
    break;

  case 389:
#line 2160 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5270 "parser.tab.c"
    break;

  case 390:
#line 2165 "parser.y"
        { ((*yyvalp).node) = create_labeled_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5276 "parser.tab.c"
    break;

  case 391:
#line 2167 "parser.y"
        { ((*yyvalp).node) = create_case_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5282 "parser.tab.c"
    break;

  case 392:
#line 2169 "parser.y"
        { ((*yyvalp).node) = create_default_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5288 "parser.tab.c"
    break;

  case 393:
#line 2174 "parser.y"
        { ((*yyvalp).node) = create_block_node(NULL); }
#line 5294 "parser.tab.c"
    break;

  case 394:
#line 2178 "parser.y"
                {
			((*yyvalp).node) = create_block_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
		// symbol_table_pop_scope();
		}
#line 5303 "parser.tab.c"
    break;

  case 395:
#line 2187 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5309 "parser.tab.c"
    break;

  case 396:
#line 2189 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 5315 "parser.tab.c"
    break;

  case 397:
#line 2193 "parser.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5321 "parser.tab.c"
    break;

  case 398:
#line 2194 "parser.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5327 "parser.tab.c"
    break;

  case 399:
#line 2199 "parser.y"
        { ((*yyvalp).node) = create_expression_statement_node(NULL); }
#line 5333 "parser.tab.c"
    break;

  case 400:
#line 2201 "parser.y"
        { ((*yyvalp).node) = create_expression_statement_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5339 "parser.tab.c"
    break;

  case 401:
#line 2208 "parser.y"
        { ((*yyvalp).node) = create_if_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5345 "parser.tab.c"
    break;

  case 402:
#line 2210 "parser.y"
        { ((*yyvalp).node) = create_if_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 5351 "parser.tab.c"
    break;

  case 403:
#line 2212 "parser.y"
        { ((*yyvalp).node) = create_switch_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5357 "parser.tab.c"
    break;

  case 404:
#line 2217 "parser.y"
        { ((*yyvalp).node) = create_while_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5363 "parser.tab.c"
    break;

  case 405:
#line 2219 "parser.y"
        { ((*yyvalp).node) = create_do_while_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5369 "parser.tab.c"
    break;

  case 406:
#line 2221 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5375 "parser.tab.c"
    break;

  case 407:
#line 2223 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5381 "parser.tab.c"
    break;

  case 408:
#line 2225 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5387 "parser.tab.c"
    break;

  case 409:
#line 2227 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5393 "parser.tab.c"
    break;

  case 410:
#line 2231 "parser.y"
                                { ((*yyvalp).node) = create_goto_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5399 "parser.tab.c"
    break;

  case 411:
#line 2232 "parser.y"
                                { ((*yyvalp).node) = CONTINUE_NODE; }
#line 5405 "parser.tab.c"
    break;

  case 412:
#line 2233 "parser.y"
                                { ((*yyvalp).node) = BREAK_NODE; }
#line 5411 "parser.tab.c"
    break;

  case 413:
#line 2234 "parser.y"
                                { ((*yyvalp).node) = RETURN_NODE; }
#line 5417 "parser.tab.c"
    break;

  case 414:
#line 2235 "parser.y"
                                { ((*yyvalp).node) = create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5423 "parser.tab.c"
    break;


#line 5427 "parser.tab.c"

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



#line 2238 "parser.y"

#include <stdio.h>

/* void yyerror(const char *s)
{
	fflush(stdout);
	fprintf(stderr, "ERROR: %s\n", s);
} */







void yyerror(const char *s)
{
	print_original_syntax(yyfilename, yylineno, s);
return;


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


