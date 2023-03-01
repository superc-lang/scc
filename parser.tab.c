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

extern int yylineno;
extern const char *yyfilename;

extern int error_count;
char func_name[512];

void yyerror(const char *s);
// void register_typedef(union ast_node *decl_specs, union ast_node *declarator);
static inline union ast_node *maybe_attributes(union ast_node *left, union ast_node *right);


#line 90 "parser.tab.c"

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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   4793

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  155
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  131
/* YYNRULES -- Number of rules.  */
#define YYNRULES  434
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  757
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 10
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
       0,   578,   578,   580,   585,   587,   592,   594,   596,   599,
     610,   615,   618,   617,   639,   644,   646,   658,   660,   664,
     663,   671,   670,   679,   678,   686,   685,   694,   693,   702,
     701,   709,   732,   733,   738,   739,   743,   745,   750,   752,
     754,   756,   758,   760,   762,   764,   766,   768,   774,   775,
     779,   781,   786,   788,   790,   792,   794,   796,   798,   800,
     802,   809,   832,   837,   842,   844,   849,   851,   859,   861,
     881,   882,   886,   894,   903,   905,   910,   912,   917,   925,
     934,   936,   941,   943,   948,   957,   990,   992,   994,  1003,
    1005,  1011,  1014,  1017,  1022,  1090,  1092,  1114,  1130,  1132,
    1137,  1139,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1154,  1159,  1161,  1166,  1168,  1173,  1175,  1180,
    1182,  1187,  1189,  1194,  1196,  1201,  1203,  1205,  1210,  1212,
    1214,  1216,  1218,  1223,  1225,  1227,  1232,  1234,  1236,  1241,
    1243,  1245,  1247,  1261,  1265,  1270,  1272,  1274,  1276,  1278,
    1280,  1282,  1289,  1294,  1295,  1296,  1297,  1298,  1299,  1303,
    1305,  1307,  1309,  1319,  1323,  1325,  1334,  1336,  1338,  1341,
    1343,  1348,  1350,  1352,  1354,  1356,  1386,  1401,  1406,  1408,
    1413,  1427,  1432,  1436,  1441,  1442,  1447,  1449,  1451,  1461,
    1463,  1468,  1473,  1474,  1478,  1479,  1483,  1485,  1511,  1516,
    1518,  1531,  1537,  1539,  1541,  1543,  1546,  1548,  1551,  1553,
    1567,  1569,  1572,  1574,  1577,  1579,  1589,  1591,  1596,  1598,
    1617,  1618,  1622,  1624,  1629,  1645,  1653,  1657,  1659,  1661,
    1663,  1674,  1676,  1678,  1680,  1682,  1684,  1686,  1688,  1690,
    1692,  1694,  1696,  1698,  1700,  1702,  1704,  1711,  1719,  1746,
    1750,  1752,  1754,  1757,  1759,  1761,  1763,  1766,  1768,  1775,
    1777,  1784,  1786,  1789,  1826,  1833,  1869,  1875,  1913,  1912,
    1925,  1927,  1929,  1937,  1936,  1944,  1946,  2003,  2017,  2019,
    2021,  2023,  2032,  2033,  2038,  2039,  2043,  2045,  2050,  2052,
    2076,  2081,  2083,  2117,  2119,  2123,  2125,  2130,  2132,  2137,
    2140,  2143,  2148,  2151,  2154,  2157,  2160,  2165,  2167,  2172,
    2174,  2180,  2185,  2190,  2191,  2192,  2193,  2194,  2198,  2199,
    2201,  2202,  2206,  2208,  2213,  2215,  2220,  2223,  2226,  2228,
    2230,  2232,  2234,  2236,  2238,  2240,  2242,  2244,  2249,  2265,
    2267,  2269,  2276,  2284,  2290,  2295,  2297,  2299,  2301,  2306,
    2308,  2313,  2315,  2320,  2322,  2327,  2329,  2331,  2339,  2342,
    2347,  2349,  2354,  2356,  2358,  2364,  2366,  2368,  2370,  2372,
    2374,  2376,  2378,  2380,  2382,  2384,  2386,  2388,  2390,  2392,
    2394,  2396,  2398,  2400,  2402,  2404,  2409,  2411,  2413,  2418,
    2420,  2422,  2424,  2429,  2434,  2436,  2441,  2443,  2459,  2461,
    2463,  2465,  2470,  2472,  2472,  2475,  2476,  2477,  2478,  2480,
    2484,  2486,  2488,  2493,  2495,  2506,  2508,  2513,  2514,  2518,
    2520,  2527,  2529,  2531,  2536,  2538,  2540,  2542,  2544,  2546,
    2551,  2552,  2553,  2554,  2555
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "I_CONSTANT", "F_CONSTANT", "ENUMERATION_CONSTANT", "TYPEDEF_NAME",
  "GENERIC_NAME", "GENERIC_TYPE", "FUNC_NAME", "SIZEOF", "ARROW", "INC",
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
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "generic_body_or_empty",
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
  "struct_or_union_specifier", "generic_declaration", "$@8",
  "generic_id_list", "generic_id_or_type_declaration", "$@9",
  "generic_id_or_type_specifiers", "generic_specifier",
  "generic_type_specifiers", "identifier", "struct_or_union",
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
  "designator", "static_assert_declaration", "statement", "$@10",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", YY_NULLPTR
};
#endif

#define YYPACT_NINF (-578)
#define YYTABLE_NINF (-404)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    4372,   -52,  -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,
    -578,  -578,  -578,     6,  -578,    16,    29,   132,   172,  4423,
    -578,  -578,  -578,  -578,  -578,  -578,   248,  4674,   201,  -578,
    1688,  1773,  -578,  1815,  1875,  1942,    62,  -578,  1520,  3323,
    3815,  3815,    18,    92,   141,   107,  -578,  -578,    19,   248,
     -81,  -578,    59,  4225,    10,    -2,  -578,  -578,  -578,  -578,
    -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,
    -578,  -578,  -578,  -578,  -578,   151,  -578,  -578,    49,  -578,
    -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,
    -578,    41,  -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,
    2002,  2044,  -578,  4545,  2064,   -67,   -66,  2104,    62,  -578,
    -578,  -578,  -578,  -578,  -578,   -50,  -578,  3893,  3912,  3912,
    -578,   181,   191,  -578,  -578,   376,   346,  -578,  -578,  -578,
    -578,  -578,  -578,  3342,  -578,  -578,  -578,    42,   345,   235,
     254,   275,   401,   108,   413,   310,   304,  -578,  -578,  3815,
     217,  -578,  -578,  -578,  -578,   261,  3668,  -578,   272,   -65,
    3815,   134,   295,  -578,   548,    15,   293,   309,  -578,  -578,
      19,   129,   298,   248,  -578,  -578,  -578,  -578,  3815,   308,
     308,  2391,   248,  4310,  1089,   996,  -578,    10,   724,  -578,
    -578,   459,   319,   328,   336,   786,   335,   352,   364,  -578,
    -578,  -578,  -578,  1664,  1186,  1840,   392,  -578,   398,  -578,
    2178,  -578,  -578,    60,  3486,  -578,  3505,  -578,  -578,  1743,
    3815,  -578,  -578,  -578,   164,  -578,  -578,   464,   326,  3815,
    3815,  3815,  3815,  3815,  3815,  3815,  3815,  3815,  3815,  3815,
    3815,  3815,  3815,  3815,  3815,  3815,  3815,  3815,  -578,   147,
    -578,  -578,  3815,   880,   150,  -578,  -578,  -578,   479,   362,
     514,   370,    48,  2911,  3363,   372,  2617,  -578,  -578,  -578,
    -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,    70,   524,
    1785,  3689,    51,  -578,  -578,  -578,  -578,   201,   155,  2263,
    -578,  -578,  -578,  2713,   375,  3649,   377,  -578,   404,  1283,
    -578,   223,  4581,   400,   416,  -578,   175,   425,  -578,   182,
    -578,   426,   459,  -578,  -578,  -578,   866,  -578,    -3,  -578,
     697,  1078,   869,  -578,  -578,  3649,   429,  -578,   430,  1338,
    -578,   433,   438,   398,  1435,  2970,  -578,  -578,  -578,   440,
     441,   442,   448,  3815,  -578,  -578,  -578,  -578,  -578,  -578,
    -578,  -578,  -578,  -578,  -578,  -578,  3815,  2783,   345,   114,
     235,   254,   275,   401,   108,   108,   413,   413,   413,   413,
     310,   310,   304,   304,  -578,  -578,  -578,  -578,  -578,   165,
    -578,  -578,   176,  -578,  -578,   444,  -578,   447,  -578,   524,
    2546,    34,    65,  -578,  -578,   455,   456,   189,  -578,   -29,
     -26,    95,  -578,   -64,   -54,  3526,   453,  3933,  -578,  -578,
    -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,   524,  2812,
     468,  -578,   467,  3815,   470,   469,   471,   472,  2989,   473,
     617,   480,   486,  3137,  -578,  -578,  -578,   300,  -578,  3746,
    -578,   308,  -578,  2413,  -578,  -578,  -578,  -578,  -578,  2634,
    -578,  -578,  -578,   460,  3649,  -578,  -578,  3815,   474,  -578,
     484,  2764,  -578,   233,  -578,  -578,  -578,  1900,   201,  -578,
    -578,    26,  -578,  3815,   193,   524,   333,  -578,  -578,  3815,
      87,   306,  -578,   201,  1066,  1196,  -578,  2009,   487,  3649,
    -578,  -578,  3815,  -578,   499,  -578,  -578,  3649,   500,  -578,
     501,  1490,  -578,   503,   509,   509,  -578,   989,  -578,  -578,
    2634,  -578,  3815,  -578,  3815,  -578,   513,   515,   -28,   -11,
     476,   140,  -578,   620,   522,   149,  -578,   666,  3118,   518,
    3815,   526,  -578,  3815,  -578,  -578,  3815,  -578,  -578,   531,
    -578,   529,   680,   534,    65,  -578,  -578,    -1,   153,  2989,
     549,  2989,  3815,  3815,  3815,   584,  2932,   543,  -578,  -578,
    -578,   315,  -578,  -578,  -578,  -578,  3815,   692,  -578,   213,
    2713,   162,  -578,  -578,   542,   544,  -578,  -578,  4483,  -578,
    -578,   696,  -578,  -578,  -578,    39,  -578,   156,   559,   570,
     562,  -578,  -578,    -3,  -578,   569,  -578,  -578,  -578,  -578,
     558,   560,  -578,   564,  3649,  -578,  -578,  3815,  -578,   565,
    -578,   574,   178,  -578,   578,   245,  -578,  -578,  -578,  -578,
     581,   397,   568,  3815,  -578,  -578,  -578,  3798,  3815,  -578,
    -578,  -578,   673,   572,  -578,   325,  -578,   332,   350,  3162,
    4022,  -578,  4029,   399,   583,   585,  -578,  2989,  -578,   204,
     234,   255,   576,  3175,  3175,  -578,  -578,   586,  -578,  2484,
    -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,  -578,
    -578,  3815,  -578,  -578,  -578,   587,   588,  -578,  3815,  1620,
    -578,  3815,  2563,  -578,  4073,  -578,  4125,  -578,   695,   354,
     590,   361,  -578,   704,  -578,  -578,  -578,  -578,   592,   596,
     597,  4163,  4187,  -578,  2989,  2989,  2989,  3815,  1580,  1634,
    -578,  -578,  -578,  2713,  -578,  -578,  -578,  -578,  -578,  -578,
    -578,   598,   601,  -578,  -578,   714,  -578,  -578,  -578,  -578,
    -578,   604,   605,   655,  -578,  -578,   256,  2989,   264,  2989,
     265,  -578,  -578,  -578,  -578,  -578,  -578,  2989,   612,  -578,
    2989,  -578,  2989,  -578,  -578,  -578,  -578
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     220,     0,   318,   313,   314,   316,    97,   224,   343,   320,
     321,   315,   317,     0,   319,     0,     0,     0,     0,   220,
       4,     6,     7,     9,    10,     8,   220,     0,   221,   222,
     220,   220,   248,   220,   220,   220,   220,   201,   220,   220,
       0,     0,     0,     0,     0,     0,     1,     5,   348,   220,
       0,   216,     0,   220,   325,   220,   246,   247,   225,   226,
     227,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,     0,   284,   285,     0,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   228,
     244,     0,   245,   243,   223,   202,   208,   210,   212,   214,
     220,   220,   280,     0,   220,     0,   361,   220,   220,   278,
     171,   189,   186,   187,   188,     0,   190,     0,     0,     0,
     344,     0,     0,    70,    71,   181,    96,   155,   156,   154,
     153,   158,   157,   220,   176,   182,   198,   113,   115,   117,
     119,   121,   123,   125,   128,   133,   136,   139,   143,     0,
     145,   159,   172,   173,   175,     0,   220,   183,     0,     0,
       0,     0,     0,    31,   220,    23,     0,     0,   349,   347,
     346,     0,     0,   220,   200,   326,   199,   327,     0,     0,
       0,   220,   220,   219,     0,   220,   342,   324,   220,   282,
     283,     0,   306,   282,     0,   220,   265,   266,   263,   204,
     206,   291,   277,   220,     0,   220,   363,   360,   364,   295,
     220,   184,   185,     0,   220,   149,   220,   146,   147,   220,
       0,   177,   180,    95,     0,    98,   100,   143,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   148,     0,
     167,   168,     0,     0,     0,   323,   152,   322,     0,     0,
       0,     0,    29,   220,   220,     0,   220,    36,    39,    38,
      46,    44,    45,    40,    41,    42,    43,    47,     0,   270,
     220,   220,    25,   350,   345,   328,   217,   220,     0,   220,
      13,    11,    16,     0,     0,     0,   154,   329,     0,     0,
     340,   220,     0,     0,   352,   353,     0,     0,   311,     0,
     307,   310,     0,   268,   273,   259,   220,   286,   220,   290,
     220,   220,   220,   281,   279,     0,   154,   366,     0,     0,
     382,     0,     0,   362,     0,   220,   293,   179,   178,     0,
       0,     0,     0,     0,   174,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   102,     0,     0,   116,     0,
     118,   120,   122,   124,   126,   127,   131,   132,   129,   130,
     134,   135,   137,   138,   140,   141,   142,   166,   165,     0,
     161,   196,     0,   163,   164,     0,   399,     0,   401,   270,
     220,     0,     0,    17,    37,     0,     0,   220,    65,     0,
       0,     0,   271,     0,     0,   220,     0,   220,    50,    53,
      52,    59,    57,    58,    54,    55,    56,    60,   270,   220,
     219,    14,   171,     0,     0,     0,     0,     0,   403,     0,
       0,     0,     0,     0,   419,   413,   409,     0,   417,   220,
     418,     0,   402,   220,   415,   405,   406,   407,   408,     0,
     388,   218,   338,     0,     0,   330,   337,     0,   154,   336,
       0,   220,   355,   220,   356,   358,   339,   220,   220,   341,
     312,     0,   302,     0,     0,   270,   220,   260,   287,     0,
       0,     0,   297,   220,   220,   220,   261,   220,     0,     0,
     367,   373,     0,   372,     0,   383,   365,     0,   154,   374,
       0,     0,   384,     0,   150,     0,   151,   220,    99,   101,
       0,   144,     0,   160,     0,   162,     0,     0,     0,     0,
       0,     0,    75,     0,     0,     0,    81,     0,   220,     0,
       0,     0,    62,     0,    87,    86,     0,    92,    91,     0,
      64,     0,     0,     0,     0,    18,    51,     0,     0,   403,
       0,   403,     0,     0,     0,     0,   220,     0,   431,   432,
     433,     0,   420,   404,   414,   416,     0,     0,   390,     0,
       0,     0,   394,   332,     0,     0,   333,   335,     0,   351,
     354,     0,   303,   308,   309,     0,   304,     0,   275,     0,
     276,   301,   288,   220,   289,   299,   264,   267,   262,   369,
       0,     0,   371,     0,     0,   375,   381,     0,   380,     0,
     385,     0,     0,   192,     0,     0,   114,   197,   398,   400,
       0,     0,     0,     0,    73,    72,    74,   220,     0,    79,
      78,    80,    67,     0,    94,     0,    63,     0,     0,   220,
     220,   272,   220,     0,     0,     0,   410,   403,   412,     0,
       0,     0,     0,     0,     0,   430,   434,     0,   397,     0,
     386,   389,   393,   395,   331,   334,   359,   305,   269,   274,
     298,     0,   368,   370,   377,     0,     0,   378,     0,   220,
     191,     0,     0,   169,   220,    32,   220,    30,    76,     0,
       0,     0,    69,    66,    61,    88,    93,    89,     0,     0,
       0,   220,   220,   411,   403,   403,   403,     0,     0,     0,
     396,   387,   392,     0,   300,   376,   379,   195,   193,   194,
     170,     0,     0,    77,    84,    82,    85,    68,    90,    20,
      24,     0,     0,   422,   423,   424,     0,   403,     0,   403,
       0,   391,    28,    33,    83,    22,    26,   403,     0,   428,
     403,   426,   403,   421,   425,   429,   427
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -578,  -578,  -578,   742,  -578,  -578,  -578,   582,  -578,  -578,
    -578,  -578,  -578,  -578,  -578,  -578,  -132,  -578,   502,  -578,
    -578,   365,  -203,  -192,  -186,  -578,   368,   -48,  -179,  -578,
     253,  -173,   236,   251,  -172,  -578,  -171,  -578,  -167,  -578,
    -578,     3,    80,   571,  -578,   -34,  -578,   552,   551,   553,
     550,   556,   327,   296,   330,   331,  -128,   611,  -578,  -578,
    -578,  -578,  -578,  -578,  -578,  -578,   113,  -578,   -27,   -51,
     546,  -578,   613,    38,  -578,   765,   -24,   239,  -578,  -578,
    -578,   -74,  -578,  -578,  -578,   671,  -254,   710,  -578,   220,
    -260,   -61,  -578,   209,  -578,   492,  -426,  -578,  -578,   478,
    -578,  -578,   -25,   -47,     0,   -13,     7,  -164,  -175,  -578,
    -451,  -578,   -30,   -83,  -191,  -282,   303,  -577,  -578,   237,
      17,   -80,  -578,  -578,  -155,  -578,   363,  -303,  -578,  -578,
    -578
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    18,    19,    20,    21,   179,    22,   180,    23,   279,
     418,   280,   419,   389,   390,   687,   265,   266,   267,   406,
     407,   408,   268,   269,   270,   397,   398,   134,   271,   521,
     522,   272,   525,   526,   273,   274,   275,   399,   276,   400,
     135,   436,   437,   225,   356,   226,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   227,   149,   150,
     151,   213,   152,   153,   154,   612,   613,   382,   155,    25,
     278,    50,    51,    27,    28,    29,    30,    31,    90,   196,
     475,   403,   197,   476,   589,    32,   105,   192,    91,   316,
     317,   106,   481,   482,    92,   309,   310,   311,    93,    33,
      34,    35,   172,    54,   160,   157,    55,   170,   331,   304,
     305,   306,   109,   332,   208,   568,   569,   570,   571,   572,
     319,   440,   441,   442,   630,   443,   444,   445,   446,   447,
     448
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    53,   181,    24,   177,   136,   136,   136,   187,   158,
     303,   451,   100,   159,   161,   333,   580,    37,   -19,    36,
     299,   248,    24,   207,   290,   291,   404,   162,   256,   308,
      36,    36,   256,    36,    36,    36,    37,   520,   108,   156,
     329,   186,   308,   201,   193,   583,   209,     7,     7,   190,
     194,   -27,   189,    36,   -21,   169,   478,   190,   120,     3,
       4,     5,   175,   337,    52,   229,    48,   173,   524,   174,
      37,     1,   202,   395,   211,   541,   103,   103,   409,   204,
     205,   203,   713,   258,   542,   543,    38,   171,   259,   410,
     175,   183,    11,   171,   203,   411,   533,   212,   395,   536,
      36,    36,   412,   228,   108,   713,    12,   108,   413,   414,
     415,   620,     7,   206,   416,   166,   167,   374,   375,   376,
     542,   534,   289,   177,   537,   289,   237,   238,   621,    48,
     181,   454,   175,   156,   318,    42,   519,   203,   644,   479,
      43,    44,   103,    49,    49,   103,   103,   542,   287,   336,
     377,    48,    39,   383,   -19,   184,   185,   287,   307,   583,
     503,   489,    40,   -19,    36,   548,    48,   277,    45,   163,
     501,   103,    46,   324,   186,    41,   690,   284,   582,   123,
     124,    36,   338,   230,   339,    36,   340,   -27,   108,   341,
     -21,   667,   195,   396,   103,   108,   -27,    48,    37,   -21,
     191,   378,    48,   108,   409,    36,   384,   123,   124,   176,
     108,   171,   206,   224,   156,   410,   156,   539,   464,   108,
      52,   411,   590,   302,   478,   478,   103,   478,   412,   511,
     249,   250,   251,   103,   413,   414,   415,   592,   438,     7,
     416,   103,   532,   164,   535,   538,   239,   240,   103,   123,
     124,     7,   103,   654,   103,   318,   512,   103,   288,   318,
     318,   318,   343,    36,    36,   623,    36,   123,   124,   277,
     123,   124,   333,     7,   628,   101,   462,   104,   104,   165,
     108,    36,   260,     7,   417,   401,   563,   261,   661,   439,
     624,   289,   645,   483,   224,   668,   224,   188,     7,   629,
     289,   203,   662,   343,   542,   421,    37,   566,   463,   567,
     359,   256,   343,   343,   530,   518,   108,   344,   103,   513,
     108,   108,   108,   468,   514,   420,   679,   219,   469,   515,
     471,   680,   379,   604,   472,    36,   402,   220,   102,   171,
     289,   585,     1,   104,   547,   586,   104,   210,   555,   223,
     708,   709,   343,   633,   103,    48,   480,   704,   103,   103,
     103,   659,   252,   253,   254,   660,   625,   231,   204,   461,
     232,  -357,   104,     3,     4,     5,  -357,   712,   204,   461,
      48,  -363,   343,     7,   221,     1,  -363,   705,     8,   136,
     108,   233,   438,   682,    49,   210,   550,   683,   523,   527,
     712,   587,   588,   343,   343,    36,    11,    36,   706,   748,
     417,   234,   343,   343,   255,   100,   187,   750,   752,   108,
      12,   235,   236,   318,   318,   257,   318,   104,   103,   241,
     242,   741,   177,   262,   104,   531,   245,   246,   247,   136,
     243,   244,   104,   439,   281,   136,   584,   282,   343,   104,
     562,   285,   591,   104,   593,   104,   594,   103,   104,   289,
      37,    36,   308,   343,   698,   656,   313,    36,   463,   646,
     312,   648,  -270,   343,   314,   694,   108,   614,   616,   357,
     343,  -270,   695,   385,   108,   108,   320,   108,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   343,   578,
     696,   171,   343,   321,   724,   653,   581,   108,   699,   343,
     700,   726,   386,   561,   103,   322,   107,   107,   387,   104,
     388,   595,   103,   103,   393,   103,   168,   402,    36,   452,
     177,   455,   136,   366,   367,   368,   369,   204,   205,   657,
     484,   485,   487,   334,   335,   103,    26,   685,   686,   629,
     289,   527,   721,   466,   722,   104,   439,     1,   456,   104,
     104,   104,   364,   365,   467,    26,   473,   703,   483,   731,
     732,   370,   371,    37,   372,   373,    95,    96,   470,    97,
      98,    99,   107,   490,   491,   107,   495,     2,     3,     4,
       5,   496,     6,   504,   505,   506,   507,   516,     7,   182,
     517,   528,   529,     8,   355,   545,     9,    10,   293,   549,
     635,   107,   551,   637,   573,   552,   638,   553,   554,   556,
     557,    11,   622,   520,   733,   734,   735,    36,   576,   104,
     558,   171,   649,   650,   651,    12,   559,   136,   577,    36,
      36,   599,    36,   277,   714,   277,   199,   200,   283,   614,
     148,   148,   148,   602,   605,   606,   610,   749,   104,   751,
     510,    13,   168,   618,    14,   619,   107,   753,   627,   524,
     755,   634,   756,   107,   263,   264,   636,   639,   101,   108,
     640,   107,   168,   641,    36,   642,    36,   277,   107,   277,
     652,   647,   107,   655,   107,   658,   664,   107,   665,   666,
     -34,    36,    36,   689,   277,   277,     1,   542,   691,   669,
     203,   671,   672,   692,   673,   104,   678,   103,   674,   677,
     681,   688,   707,   104,   104,   693,   104,   182,   215,   217,
     218,   301,   684,     1,   701,   723,   702,     3,     4,     5,
     710,   715,   716,   725,   727,   728,   104,     7,   729,   730,
     742,   301,     8,   743,   744,   298,   745,   746,   107,   747,
     148,    47,   754,   292,     3,     4,     5,   148,   394,   540,
      11,   148,   546,   168,     7,   328,   626,   283,   631,     8,
     643,   358,   360,   362,    12,   361,   286,   736,   738,   740,
     363,   342,   718,    94,   107,     1,   222,    11,   107,   107,
     107,   198,   670,   168,   474,     0,   565,   283,   663,   391,
     392,    12,   168,   615,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,   381,     0,     3,     4,     5,     0,
       0,     0,     0,     0,     0,   182,     7,     0,     0,     0,
     148,     8,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,    11,
       0,     0,     0,     0,   450,     0,   453,     0,   107,     0,
     460,     0,     0,    12,     0,     1,     0,     0,     1,     0,
       0,   301,     0,   110,   111,   112,   113,   114,   115,     0,
       0,   116,   117,     0,   118,   119,   488,   107,     0,     0,
     494,     0,     0,    15,    16,   500,     3,     4,     5,     3,
       4,     5,     0,     0,   508,     0,     7,     0,   104,     7,
       0,     8,     0,     0,     8,     0,     0,   509,   120,     0,
       0,     0,   283,     0,     0,     8,     0,     0,   315,    11,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
       0,   544,     0,    12,   107,     0,    12,     0,     0,     0,
       0,     0,   107,   107,     0,   107,     0,   283,   148,     0,
       0,     0,     0,     0,     0,   168,     0,     0,     0,   283,
       0,     0,     0,    15,    16,   107,    15,    16,     0,   182,
       0,     0,     0,     0,   121,   122,     0,     0,     1,     0,
     123,   124,   125,   126,     0,     1,     0,   301,     0,     0,
     127,   128,   129,   301,     0,     0,   130,     0,   477,     0,
     450,   486,     0,   131,   132,   574,   133,     0,   575,     3,
       4,     5,     0,   380,   148,     2,     3,     4,     5,     7,
       0,     0,     0,     0,     8,     0,     7,     0,     0,     0,
     148,     8,     0,     0,     9,    10,     0,     0,     0,     0,
     600,     0,    11,   601,     0,     0,     0,     0,   603,    11,
       0,     0,   609,     0,   301,     1,    12,     0,     0,     0,
       0,   450,   283,    12,   148,   617,     0,     1,     0,     0,
     148,   611,   110,   111,   112,   113,   114,   115,     0,   294,
     116,   117,   182,   118,   119,     0,     3,     4,     5,    13,
       0,     0,    14,     0,     0,     0,     7,     0,     3,     4,
       5,     8,     0,   148,     0,   295,     0,     0,     7,     3,
       4,     5,     0,     8,     0,     0,     0,   120,     0,    11,
       0,   450,     0,     0,     8,     0,     0,     0,     0,   300,
       0,    11,     0,    12,     0,     0,     0,   107,     0,     0,
       0,     0,    11,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,   301,     0,   675,    12,   148,   676,     0,
       0,     0,     0,    15,    16,   301,     0,     0,     0,   110,
     111,   112,   113,   114,   115,    15,    16,   116,   117,     0,
     118,   119,     0,   121,   122,     1,     0,     0,     0,   123,
     124,   125,   126,     0,     0,     0,     0,     0,   596,   127,
     128,   296,   325,     0,     0,   130,     3,     4,     5,     0,
     450,     0,   131,   132,   120,   133,     3,     4,     5,     0,
       0,     8,     0,   297,     0,     0,     7,     0,     0,   717,
       0,     8,   719,   450,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,     0,   148,    12,   450,     0,   110,   111,   112,   113,
     114,   115,     0,     0,   116,   117,     0,   118,   119,     0,
     121,   122,     0,     0,     0,     0,   123,   124,   125,   126,
       0,     0,     0,    15,    16,     0,   127,   128,   326,   457,
       0,     0,   130,     3,     4,     5,     0,     0,     0,   131,
     132,   120,   133,     0,     0,     0,     0,     0,     8,     0,
     327,   110,   111,   112,   113,   114,   115,     0,   597,   116,
     117,     0,   118,   119,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,   492,     0,     0,     0,     3,     4,
       5,     0,     0,     0,     0,     0,   120,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     0,   121,   122,     0,
       0,     0,     0,   123,   124,   125,   126,     0,     0,     0,
       0,    11,     0,   127,   128,   458,     0,     0,     0,   130,
       0,     0,     0,     0,     0,    12,   131,   132,     0,   133,
       0,     0,     0,     0,     0,     0,     0,   459,   110,   111,
     112,   113,   114,   115,     0,     0,   116,   117,     0,   118,
     119,     0,   121,   122,     0,     0,     0,     0,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,   127,   128,
     129,   497,     0,     0,   130,     3,     4,     5,     0,     0,
       0,   131,   132,   120,   133,     0,     0,     0,     0,     0,
       8,     0,   493,   110,   111,   112,   113,   114,   115,     0,
       0,   116,   117,     0,   118,   119,     0,     0,    11,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    12,     0,     0,   102,   607,     0,     0,     1,
       3,     4,     5,     0,     0,     0,     0,     0,   120,     0,
       0,     0,     0,     0,     0,     8,     0,     0,     0,   121,
     122,     0,     0,     0,     0,   123,   124,   125,   126,     0,
       3,     4,     5,    11,     0,   127,   128,   498,     0,     0,
       7,   130,     0,     0,     0,     8,     0,    12,   131,   132,
       0,   133,     0,   110,   111,   112,   113,   114,   115,   499,
       0,   116,   117,    11,   118,   119,     0,     0,     0,     0,
       0,     0,     0,     0,   121,   122,     0,    12,     0,     0,
     123,   124,   125,   126,     0,     0,     0,     0,     0,     0,
     127,   128,   129,     0,     0,     0,   130,     0,   120,     1,
       0,     0,     0,   131,   132,     8,   133,   110,   111,   112,
     113,   114,   115,     0,   608,   116,   117,     0,   118,   119,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     4,     5,     0,     0,     0,     0,     0,     0,   323,
       7,     0,     0,     1,     0,     8,     0,     0,     0,     0,
       0,     0,   120,     0,     0,     0,     0,     0,     0,     8,
       0,  -203,     0,    11,   121,   122,     0,     1,     0,     0,
     123,   124,   125,   126,     3,     4,     5,    12,     0,     0,
     127,   128,   129,     0,     7,     0,   130,     0,     0,     8,
       0,     0,   611,   131,   132,     0,   133,     2,     3,     4,
       5,     0,     0,   737,     0,     0,     0,    11,     7,     0,
       0,     0,     0,     8,     0,     0,     9,    10,   121,   122,
       0,    12,     1,     0,   123,   124,   125,   126,     0,     0,
       0,    11,     0,     0,   127,   128,   129,     0,     0,     0,
     130,     0,     0,     0,     0,    12,  -209,   131,   132,     0,
     133,     0,     1,     3,     4,     5,     0,   739,     0,     0,
     102,     0,     0,     7,     1,     0,     0,     0,     8,     0,
       0,    13,     0,     0,    14,     0,     0,     0,  -203,  -203,
       0,  -203,     2,     3,     4,     5,    11,     0,  -211,     0,
    -203,     0,     0,     7,     1,     3,     4,     5,     8,     0,
      12,     9,    10,  -203,  -203,     7,  -203,     0,  -203,     0,
       8,  -203,     0,     0,     0,     0,    11,     0,     0,     1,
       0,     0,     0,     0,     2,     3,     4,     5,    11,     0,
      12,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       8,     0,    12,     9,    10,     0,     0,     0,  -213,     2,
       3,     4,     5,     0,     1,     0,    13,     0,    11,    14,
       7,     0,     0,  -209,  -209,     8,  -209,     0,     9,    10,
       0,     0,    12,     0,     0,  -209,     0,     0,     0,     1,
       0,     0,     0,    11,     2,     3,     4,     5,  -209,  -209,
       0,  -209,     0,  -209,     0,     7,  -209,    12,    13,     0,
       8,    14,     0,     9,    10,  -211,  -211,     0,  -211,     2,
       3,     4,     5,   579,     0,  -215,     0,  -211,    11,     0,
       7,     1,     0,    13,     0,     8,    14,     0,     9,    10,
    -211,  -211,    12,  -211,     0,  -211,     0,     0,  -211,     0,
       0,     0,    48,    11,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,   204,   205,    12,    13,     0,
       0,    14,     7,   330,     0,  -213,  -213,     8,  -213,     0,
       9,    10,     0,     0,     0,  -205,     0,  -213,     0,     0,
       0,     1,     0,    13,     0,    11,    14,     0,     1,     0,
    -213,  -213,     0,  -213,     0,  -213,     0,     0,  -213,    12,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,     0,     0,  -207,     0,     3,
       4,     5,     7,     1,     0,    13,     0,     8,    14,     7,
       9,    10,  -215,  -215,     8,  -215,     0,  -292,     0,     0,
       0,     0,     0,     1,  -215,    11,     0,     0,     0,     0,
       0,     0,    11,     2,     3,     4,     5,  -215,  -215,    12,
    -215,     0,  -215,     0,     7,  -215,    12,     0,     0,     8,
       0,     0,     9,    10,     3,     4,     5,  -296,     0,     0,
       0,     0,     0,     1,     7,    13,     0,    11,    14,     8,
       0,     0,  -205,  -205,     0,  -205,    15,    16,     0,     0,
       0,    12,     0,     0,  -205,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     3,     4,     5,  -205,  -205,     0,
    -205,    12,  -205,     0,     7,  -205,     0,    13,     0,     8,
      14,   598,     0,     0,  -207,  -207,     0,  -207,     0,     0,
       0,     0,     0,     0,     0,     0,  -207,    11,     0,     0,
       0,  -294,     0,     0,  -292,  -292,     0,     1,     0,  -207,
    -207,    12,  -207,     0,  -207,     0,  -292,  -207,     0,     0,
       0,     0,     0,  -292,     0,     0,  -292,     0,     0,  -292,
    -292,     0,  -292,     0,  -292,     0,     0,  -292,     3,     4,
       5,     0,     0,     0,  -296,  -296,     0,     0,     7,     0,
       0,     0,     0,     8,     0,     0,  -296,     0,     0,     0,
       0,     0,     0,  -296,     0,     0,  -296,     0,     0,  -296,
    -296,    11,  -296,     0,  -296,     0,     0,  -296,     0,     0,
       0,     0,     0,     0,     0,    12,   422,   111,   112,   113,
     114,   115,     1,     0,   116,   117,     0,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -294,  -294,
       0,     0,     2,     3,     4,     5,     0,     6,     0,     0,
    -294,   120,     0,     7,     0,     0,     0,  -294,     8,     0,
    -294,     9,    10,  -294,  -294,     0,  -294,     0,  -294,     0,
       0,  -294,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   423,   424,   425,     0,   426,   427,
     428,   429,   430,   431,   432,   433,    13,   121,   122,    14,
      15,    16,     0,   123,   124,   125,   126,     0,     0,     0,
       0,     0,     0,   127,   128,   129,     0,     0,     0,   130,
       1,     0,     0,     0,     0,     0,   131,   132,     0,   133,
       0,     0,     0,   434,  -403,   435,   422,   111,   112,   113,
     114,   115,     1,     0,   116,   117,     0,   118,   119,     0,
       2,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     8,     0,     0,     9,
      10,     0,     2,     3,     4,     5,     0,     6,     0,     0,
       0,   120,     0,     7,    11,     0,     0,     0,     8,     0,
       0,     9,    10,     0,     0,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,    11,   110,   111,   112,
     113,   114,   115,     0,     0,   116,   117,     0,   118,   119,
      12,     0,     0,     0,    13,     0,     0,    14,    15,    16,
       0,     0,     0,     0,   423,   424,   425,     0,   426,   427,
     428,   429,   430,   431,   432,   433,    13,   121,   122,    14,
      15,    16,   120,   123,   124,   125,   126,     0,     0,     8,
       0,     0,   -15,   127,   128,   129,     0,     0,     0,   130,
       0,   102,     0,     0,     0,     1,   131,   132,     0,   133,
       0,     0,     0,   434,  -403,   564,   110,   111,   112,   113,
     114,   115,     0,     0,   116,   117,     0,   118,   119,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     7,     0,   121,   122,
       0,     8,     0,     0,   123,   124,   125,   126,     0,     0,
       0,   120,     0,     0,   127,   128,   129,     0,     8,    11,
     130,     0,     0,     0,     0,     0,     1,   131,   132,   566,
     133,   567,     0,    12,     0,   449,   711,   110,   111,   112,
     113,   114,   115,     0,     0,   116,   117,     0,   118,   119,
       0,     0,     0,     0,     0,     0,     2,     3,     4,     5,
       0,     6,     0,     0,     0,     0,     0,     7,     0,     0,
       0,     0,     8,     0,     0,     9,    10,   121,   122,     0,
       0,     0,   120,   123,   124,   125,   126,     0,     0,     8,
      11,     0,     0,   127,   128,   129,     0,     0,     0,   130,
       0,     0,     0,     0,    12,     0,   131,   132,   566,   133,
     567,     0,     0,     0,   449,   720,   110,   111,   112,   113,
     114,   115,     0,     0,   116,   117,     0,   118,   119,     0,
      13,     0,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   263,   264,     0,     0,     0,   121,   122,
       0,     0,     0,     0,   123,   124,   125,   126,     0,     0,
       0,   120,     0,     0,   127,   128,   129,     0,     8,   -35,
     130,     0,     0,     1,     0,     0,     0,   131,   132,   566,
     133,   567,     0,     0,     0,   449,   110,   111,   112,   113,
     114,   115,     0,     0,   116,   117,     0,   118,   119,     0,
       0,     0,     0,     2,     3,     4,     5,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     0,   102,     0,     8,
       0,     1,     9,    10,     0,     0,     0,   121,   122,     0,
       0,   120,     0,   123,   124,   125,   126,    11,     8,     0,
       0,     0,     0,   127,   128,   129,     0,     0,     0,   130,
       0,    12,     3,     4,     5,     0,   131,   132,     0,   133,
       0,     0,     7,     0,   449,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
      14,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,   121,   122,    12,
       0,     0,     0,   123,   124,   125,   126,     0,     0,   204,
     461,     0,     0,   127,   128,   129,     0,   330,     0,   130,
       1,     0,     0,     0,     0,     0,   131,   132,     0,   133,
       0,     0,     0,     0,   510,   110,   111,   112,   113,   114,
     115,     1,     0,   116,   117,     0,   118,   119,     0,     0,
       2,     3,     4,     5,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     8,     0,     0,     9,
      10,     2,     3,     4,     5,     0,     0,     0,     0,     1,
     120,     0,     7,     0,    11,     0,     0,     8,     0,     0,
       9,    10,   422,   111,   112,   113,   114,   115,    12,     0,
     116,   117,     0,   118,   119,    11,     0,     0,     0,     2,
       3,     4,     5,     0,     0,     0,     0,     0,     0,    12,
       7,     0,     0,     0,    13,     8,     0,    14,     9,    10,
       0,     0,     0,     6,     0,     0,     0,   120,     0,     0,
       0,     0,     0,    11,     8,    13,   121,   122,    14,    15,
      16,     0,   123,   124,   125,   126,     0,    12,     0,     0,
       0,     0,   127,   128,   129,     0,     0,     0,   130,     0,
       0,     0,     0,     0,     0,   131,   132,     0,   133,     0,
       0,     0,   434,    13,     0,     0,    14,     0,     0,     0,
     423,   424,   425,     0,   426,   427,   428,   429,   430,   431,
     432,   433,     0,   121,   122,     0,     0,     0,     0,   123,
     124,   125,   126,     0,     0,     0,     0,     0,     0,   127,
     128,   129,     0,   502,     0,   130,     0,     1,     0,     0,
       0,     0,   131,   132,     0,   133,     0,     0,     0,   434,
     110,   111,   112,   113,   114,   115,     0,     0,   116,   117,
       0,   118,   119,     0,     0,     0,     0,     2,     3,     4,
       5,     0,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     1,     0,     8,     0,     0,     9,    10,   110,   111,
     112,   113,   114,   115,     0,   120,   116,   117,     0,   118,
     119,    11,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     2,     3,     4,     5,    12,     0,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     0,     8,     0,     0,
       9,    10,     0,   120,     0,     0,     0,     0,     0,     0,
       8,    13,     0,     0,    14,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,   121,   122,     0,     0,     0,     0,   123,   124,   125,
     126,     0,     0,     0,     0,     0,     0,   127,   128,   129,
       0,   632,     0,   130,     0,    13,     0,     0,    14,     0,
     131,   132,     0,   133,     0,     0,     0,   560,     0,   121,
     122,     0,     0,     0,     0,   123,   124,   125,   126,     0,
       0,     0,     0,     0,     0,   127,   128,   129,     0,     0,
       0,   130,     0,     0,     0,   697,     0,     0,   131,   132,
       0,   133,     0,     0,     0,   434,   110,   111,   112,   113,
     114,   115,     1,     0,   116,   117,     0,   118,   119,     0,
       0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
     115,     1,     0,   116,   117,     0,   118,   119,     0,     0,
       0,     0,     0,     3,     4,     5,     0,     0,     0,     0,
       0,   120,     1,     7,     0,     0,     0,     0,     8,     0,
       0,     0,     3,     4,     5,     0,     0,     0,     0,     0,
     120,     0,     7,     0,     0,     0,    11,     8,     0,     0,
       0,     0,     2,     3,     4,     5,     0,     0,     0,     0,
      12,     0,     0,     7,     0,    11,     0,     0,     8,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,    11,   121,   122,     0,
       0,     0,     0,   123,   124,   125,   126,     0,     0,     0,
      12,     0,     0,   127,   128,   129,   121,   122,     0,   130,
       0,     0,   123,   124,   125,   126,   131,   132,     0,   133,
       0,     0,   127,   128,   129,     0,    13,     0,   130,    14,
       0,     0,     0,     0,     0,   131,   132,     0,   133,   110,
     111,   112,   113,   114,   115,     1,     0,   116,   117,     0,
     118,   119,     0,     0,     0,     0,     0,     0,   110,   111,
     112,   113,   114,   115,     1,     0,   116,   117,     0,   118,
     119,     0,     0,     0,     0,     0,     3,     4,     5,     0,
       0,     0,     0,     0,   120,     1,     7,     0,     0,     0,
       0,     8,     0,     0,     0,     3,     4,     5,     0,     0,
       0,     0,     0,   120,     0,     7,     0,     0,     0,    11,
       8,     0,     0,     0,     0,     2,     3,     4,     5,     0,
       0,     0,     0,    12,     0,     0,     7,     0,    11,     0,
       0,     8,     0,     0,     9,    10,     0,     0,     0,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,    11,
     121,   122,     0,     0,     0,     0,   123,   124,   125,   126,
       0,     0,     0,    12,     0,     0,   127,   128,   129,   121,
     122,     0,   130,     0,     0,   123,   124,   125,   126,   131,
     132,     0,   133,     0,     0,   127,   128,   129,     0,    13,
       0,   130,    14,     0,     0,     0,     0,     0,   131,   132,
       0,   133,   110,   111,   112,   113,   114,   115,     0,     0,
     116,   117,     0,   118,   119,     0,     0,     0,     0,     0,
       0,   110,   111,   112,   113,   114,   115,     1,     0,   116,
     117,     0,   118,   119,     0,     0,     0,     0,     0,     3,
       4,     5,     0,     0,     0,     0,     0,   120,     1,     0,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,     0,     7,     0,
       0,     0,    11,     8,     0,     0,     0,     0,     2,     3,
       4,     5,     0,     6,     0,     0,    12,     0,     0,     7,
       0,     0,     0,     0,     8,     0,     0,     9,    10,   110,
     111,   112,   113,   114,   115,     1,     0,   116,   117,     0,
     118,   119,    11,   121,   122,     0,     0,     0,     0,   123,
     124,   125,   126,     0,     0,     0,    12,     0,     0,   127,
     128,   129,   121,   122,     0,   130,     0,     0,   123,   124,
     125,   126,   131,   132,   120,   133,     7,     0,   127,   128,
     129,     8,    13,     0,   130,    14,     0,     1,     0,     0,
       0,   131,   132,     0,   133,   263,   405,     0,   110,   111,
     112,   113,   114,   115,     0,     0,   116,   117,     0,   118,
     119,     0,     0,     0,     0,     0,     0,     2,     3,     4,
       5,   -48,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     8,     0,     0,     9,    10,     0,     0,
     121,   122,     0,   120,     0,     0,   123,   124,   125,   126,
       8,    11,     0,     0,     0,     0,   127,   128,   129,     0,
       0,     0,   130,     0,     0,    12,     0,     0,     0,   131,
     132,     0,   133,     0,     0,     0,   110,   111,   112,   113,
     114,   115,     0,     0,   116,   117,     0,   118,   119,     0,
       0,    13,     0,     0,    14,   110,   111,   112,   113,   114,
     115,     0,     0,   116,   117,     0,   118,   119,     0,   121,
     122,     0,     0,     0,     0,   123,   124,   125,   126,     0,
       0,   120,     1,     0,     0,   127,   128,   129,     8,     0,
       0,   130,     0,     0,     0,     0,     0,     0,   131,   132,
     120,   133,     0,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     2,     3,     4,     5,     0,     6,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     8,     0,
       0,     9,    10,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,   121,   122,     0,
       0,     0,     0,   123,   124,   125,   126,     0,     0,     0,
      12,     0,     0,   127,   128,   129,   121,   122,     0,   130,
       0,     1,   123,   124,   125,   126,   131,   132,     1,   214,
       0,     0,   127,   128,   129,     0,    13,     0,   130,    14,
       0,     0,     0,     0,     0,   131,   132,     0,   216,   263,
     405,     2,     3,     4,     5,     0,     6,     0,     2,     3,
       4,     5,     7,     6,     0,     0,     0,     8,     0,     7,
       9,    10,     1,     0,     8,   -49,     0,     9,    10,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     2,     3,     4,     5,    12,     6,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     8,     0,
       0,     9,    10,     0,     1,    13,     0,     0,    14,     0,
       0,     0,    13,     0,     0,    14,    11,     0,   263,   264,
       0,     0,     0,     0,     0,   263,   264,     0,     0,     0,
      12,     0,     0,     0,     2,     3,     4,     5,     0,     6,
       0,     0,     1,     0,   -34,     7,     0,     0,     0,     0,
       8,   -34,     0,     9,    10,     0,    13,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     1,     0,    11,   263,
     264,     0,     2,     3,     4,     5,     0,     6,     0,     0,
       0,     0,    12,     7,     0,     0,     0,     0,     8,     0,
       0,     9,    10,     0,     0,   -34,     2,     3,     4,     5,
       0,     6,     0,     0,     1,     0,    11,     7,    13,     0,
       0,    14,     8,     0,     0,     9,    10,     0,     0,     0,
      12,   263,   264,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,    12,     7,    13,   -34,     0,    14,
       8,     0,     0,     9,    10,     0,     0,     0,     0,   263,
     264,     0,     0,     0,     0,     0,     0,     0,    11,     0,
      13,     0,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,    12,   263,   264,   -34,     0,     0,    56,     0,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    13,   -34,
       0,    14,    15,    16,    58,    59,    60,    61,    62,     0,
     178,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    -2,     0,     0,     0,   -12,     0,     0,     0,
       0,     1,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,     2,     3,     4,     5,     0,     6,     0,     0,     0,
       0,     0,     7,    -3,     0,     0,     0,     8,     0,    89,
       9,    10,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
     293,     0,     0,     0,     0,     0,     0,     0,     0,    12,
       0,     0,     2,     3,     4,     5,     0,     6,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     8,     0,
       0,     9,    10,     0,     0,    13,   175,     0,    14,    15,
      16,    56,     0,    57,     0,     0,    11,     0,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,    58,    59,    60,
      61,    62,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,     0,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,    56,     0,    57,     0,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   465,     0,     0,     0,     0,    56,
       0,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    89,   123,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    56,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,    58,    59,
      60,    61,    62,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89
};

static const yytype_int16 yycheck[] =
{
       0,    26,    53,     0,    52,    39,    40,    41,    55,    39,
     185,   293,    36,    40,    41,   206,   467,     0,     3,    19,
     184,   149,    19,   106,   179,   180,   280,     9,   156,     3,
      30,    31,   160,    33,    34,    35,    19,     3,    38,    39,
     204,    54,     3,   104,     3,   471,   107,    50,    50,     8,
       9,     3,     3,    53,     3,    48,   316,     8,    48,    40,
      41,    42,     3,     3,    26,    23,   132,   148,     3,   150,
      53,     9,   139,     3,   124,   139,    38,    39,   281,   145,
     146,   148,   659,   148,   148,   139,   138,    49,   153,   281,
       3,    53,    73,    55,   148,   281,   125,   147,     3,   125,
     100,   101,   281,   133,   104,   682,    87,   107,   281,   281,
     281,   139,    50,   106,   281,     8,     9,   245,   246,   247,
     148,   150,   151,   171,   150,   151,    18,    19,   139,   132,
     181,   295,     3,   133,   195,     3,   390,   148,   139,   142,
       8,     9,   104,   146,   146,   107,   108,   148,   173,   210,
       3,   132,   146,     3,   139,   145,   146,   182,   188,   585,
     335,   325,   146,   148,   164,   419,   132,   164,    36,   151,
     334,   133,     0,   203,   187,   146,   627,   170,   152,   120,
     121,   181,   122,   141,   214,   185,   216,   139,   188,   219,
     139,   152,   151,   123,   156,   195,   148,   132,   181,   148,
     151,   249,   132,   203,   407,   205,   254,   120,   121,   150,
     210,   173,   205,   133,   214,   407,   216,   122,   301,   219,
     182,   407,   476,   185,   484,   485,   188,   487,   407,   357,
      13,    14,    15,   195,   407,   407,   407,   150,   289,    50,
     407,   203,   397,   151,   399,   400,   138,   139,   210,   120,
     121,    50,   214,   556,   216,   316,   142,   219,   178,   320,
     321,   322,   148,   263,   264,   125,   266,   120,   121,   266,
     120,   121,   463,    50,   125,    36,   301,    38,    39,   138,
     280,   281,   148,    50,   281,   278,   441,   153,   570,   289,
     150,   151,   139,   318,   214,   139,   216,   146,    50,   150,
     151,   148,   140,   148,   148,   150,   289,   145,   301,   147,
     230,   439,   148,   148,   125,   389,   316,   153,   280,   154,
     320,   321,   322,   148,   148,   287,   148,   146,   153,   153,
     148,   153,   252,   497,   152,   335,     3,   146,     5,   301,
     151,   148,     9,   104,   418,   152,   107,   108,   428,     3,
     653,   654,   148,   528,   316,   132,   318,   153,   320,   321,
     322,   148,   145,   146,   147,   152,   521,    22,   145,   146,
     135,   148,   133,    40,    41,    42,   153,   659,   145,   146,
     132,   148,   148,    50,     8,     9,   153,   153,    55,   423,
     390,   137,   443,   148,   146,   156,   423,   152,   391,   392,
     682,   475,   476,   148,   148,   405,    73,   407,   153,   153,
     407,   136,   148,   148,   153,   439,   463,   153,   153,   419,
      87,    20,    21,   484,   485,   153,   487,   188,   390,    16,
      17,   713,   480,   138,   195,   397,   132,   133,   134,   473,
     130,   131,   203,   443,   151,   479,   473,   138,   148,   210,
     150,   153,   479,   214,   148,   216,   150,   419,   219,   151,
     443,   461,     3,   148,   639,   150,   138,   467,   461,   549,
     151,   551,   139,   148,   138,   150,   476,   507,   512,   153,
     148,   148,   150,     4,   484,   485,   151,   487,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,   148,   461,
     150,   463,   148,   151,   150,   556,   468,   507,   640,   148,
     642,   150,   150,   433,   476,   151,    38,    39,     4,   280,
     150,   483,   484,   485,   152,   487,    48,     3,   528,   154,
     578,   154,   566,   237,   238,   239,   240,   145,   146,   566,
     320,   321,   322,   145,   146,   507,     0,   150,   151,   150,
     151,   544,   684,   153,   686,   316,   556,     9,   154,   320,
     321,   322,   235,   236,   148,    19,   140,   647,   593,   701,
     702,   241,   242,   556,   243,   244,    30,    31,   153,    33,
      34,    35,   104,   154,   154,   107,   153,    39,    40,    41,
      42,   153,    44,   153,   153,   153,   148,   153,    50,    53,
     153,   146,   146,    55,   140,   152,    58,    59,   140,   142,
     530,   133,   142,   533,   154,   146,   536,   146,   146,   146,
       3,    73,   146,     3,   704,   705,   706,   627,   154,   390,
     150,   593,   552,   553,   554,    87,   150,   671,   154,   639,
     640,   154,   642,   640,   671,   642,   100,   101,   170,   679,
      39,    40,    41,   154,   154,   154,   153,   737,   419,   739,
     151,   113,   184,   150,   116,   150,   188,   747,   146,     3,
     750,   153,   752,   195,   126,   127,   150,   146,   439,   679,
     151,   203,   204,     3,   684,   151,   686,   684,   210,   686,
     106,   142,   214,   150,   216,     3,   154,   219,   154,     3,
     152,   701,   702,   623,   701,   702,     9,   148,   628,   139,
     148,   142,   154,    40,   154,   476,   142,   679,   154,   154,
     142,   153,   146,   484,   485,   153,   487,   181,   117,   118,
     119,   185,   151,     9,   151,    40,   151,    40,    41,    42,
     154,   154,   154,   153,    40,   153,   507,    50,   152,   152,
     152,   205,    55,   152,    40,   184,   152,   152,   280,   104,
     149,    19,   150,   181,    40,    41,    42,   156,   266,   401,
      73,   160,   407,   295,    50,   204,   523,   299,   527,    55,
     544,   229,   231,   233,    87,   232,   173,   707,   708,   709,
     234,   220,   679,    28,   316,     9,   125,    73,   320,   321,
     322,    91,   593,   325,   312,    -1,   443,   329,   571,   263,
     264,    87,   334,   510,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   253,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,   289,    50,    -1,    -1,    -1,
     229,    55,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,    73,
      -1,    -1,    -1,    -1,   293,    -1,   295,    -1,   390,    -1,
     299,    -1,    -1,    87,    -1,     9,    -1,    -1,     9,    -1,
      -1,   335,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    -1,    14,    15,   325,   419,    -1,    -1,
     329,    -1,    -1,   117,   118,   334,    40,    41,    42,    40,
      41,    42,    -1,    -1,   343,    -1,    50,    -1,   679,    50,
      -1,    55,    -1,    -1,    55,    -1,    -1,   356,    48,    -1,
      -1,    -1,   454,    -1,    -1,    55,    -1,    -1,   152,    73,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   405,    -1,    87,   476,    -1,    87,    -1,    -1,    -1,
      -1,    -1,   484,   485,    -1,   487,    -1,   489,   357,    -1,
      -1,    -1,    -1,    -1,    -1,   497,    -1,    -1,    -1,   501,
      -1,    -1,    -1,   117,   118,   507,   117,   118,    -1,   443,
      -1,    -1,    -1,    -1,   114,   115,    -1,    -1,     9,    -1,
     120,   121,   122,   123,    -1,     9,    -1,   461,    -1,    -1,
     130,   131,   132,   467,    -1,    -1,   136,    -1,   152,    -1,
     449,   152,    -1,   143,   144,   454,   146,    -1,   457,    40,
      41,    42,    -1,   153,   423,    39,    40,    41,    42,    50,
      -1,    -1,    -1,    -1,    55,    -1,    50,    -1,    -1,    -1,
     439,    55,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,
     489,    -1,    73,   492,    -1,    -1,    -1,    -1,   497,    73,
      -1,    -1,   501,    -1,   528,     9,    87,    -1,    -1,    -1,
      -1,   510,   604,    87,   473,   514,    -1,     9,    -1,    -1,
     479,   102,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    12,   556,    14,    15,    -1,    40,    41,    42,   113,
      -1,    -1,   116,    -1,    -1,    -1,    50,    -1,    40,    41,
      42,    55,    -1,   512,    -1,    36,    -1,    -1,    50,    40,
      41,    42,    -1,    55,    -1,    -1,    -1,    48,    -1,    73,
      -1,   570,    -1,    -1,    55,    -1,    -1,    -1,    -1,   153,
      -1,    73,    -1,    87,    -1,    -1,    -1,   679,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   627,    -1,   604,    87,   566,   607,    -1,
      -1,    -1,    -1,   117,   118,   639,    -1,    -1,    -1,     3,
       4,     5,     6,     7,     8,   117,   118,    11,    12,    -1,
      14,    15,    -1,   114,   115,     9,    -1,    -1,    -1,   120,
     121,   122,   123,    -1,    -1,    -1,    -1,    -1,   152,   130,
     131,   132,    36,    -1,    -1,   136,    40,    41,    42,    -1,
     659,    -1,   143,   144,    48,   146,    40,    41,    42,    -1,
      -1,    55,    -1,   154,    -1,    -1,    50,    -1,    -1,   678,
      -1,    55,   681,   682,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   671,    87,   713,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,
     114,   115,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
      -1,    -1,    -1,   117,   118,    -1,   130,   131,   132,    36,
      -1,    -1,   136,    40,    41,    42,    -1,    -1,    -1,   143,
     144,    48,   146,    -1,    -1,    -1,    -1,    -1,    55,    -1,
     154,     3,     4,     5,     6,     7,     8,    -1,   152,    11,
      12,    -1,    14,    15,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    -1,   114,   115,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,    -1,    -1,    -1,
      -1,    73,    -1,   130,   131,   132,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,    87,   143,   144,    -1,   146,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   154,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    -1,   114,   115,    -1,    -1,    -1,    -1,   120,   121,
     122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,
     132,    36,    -1,    -1,   136,    40,    41,    42,    -1,    -1,
      -1,   143,   144,    48,   146,    -1,    -1,    -1,    -1,    -1,
      55,    -1,   154,     3,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    -1,    14,    15,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,     5,    36,    -1,    -1,     9,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,   114,
     115,    -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,
      40,    41,    42,    73,    -1,   130,   131,   132,    -1,    -1,
      50,   136,    -1,    -1,    -1,    55,    -1,    87,   143,   144,
      -1,   146,    -1,     3,     4,     5,     6,     7,     8,   154,
      -1,    11,    12,    73,    14,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,    -1,    87,    -1,    -1,
     120,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,
     130,   131,   132,    -1,    -1,    -1,   136,    -1,    48,     9,
      -1,    -1,    -1,   143,   144,    55,   146,     3,     4,     5,
       6,     7,     8,    -1,   154,    11,    12,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      50,    -1,    -1,     9,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,
      -1,     3,    -1,    73,   114,   115,    -1,     9,    -1,    -1,
     120,   121,   122,   123,    40,    41,    42,    87,    -1,    -1,
     130,   131,   132,    -1,    50,    -1,   136,    -1,    -1,    55,
      -1,    -1,   102,   143,   144,    -1,   146,    39,    40,    41,
      42,    -1,    -1,   153,    -1,    -1,    -1,    73,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    59,   114,   115,
      -1,    87,     9,    -1,   120,   121,   122,   123,    -1,    -1,
      -1,    73,    -1,    -1,   130,   131,   132,    -1,    -1,    -1,
     136,    -1,    -1,    -1,    -1,    87,     3,   143,   144,    -1,
     146,    -1,     9,    40,    41,    42,    -1,   153,    -1,    -1,
       5,    -1,    -1,    50,     9,    -1,    -1,    -1,    55,    -1,
      -1,   113,    -1,    -1,   116,    -1,    -1,    -1,   120,   121,
      -1,   123,    39,    40,    41,    42,    73,    -1,     3,    -1,
     132,    -1,    -1,    50,     9,    40,    41,    42,    55,    -1,
      87,    58,    59,   145,   146,    50,   148,    -1,   150,    -1,
      55,   153,    -1,    -1,    -1,    -1,    73,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    73,    -1,
      87,    -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,
      55,    -1,    87,    58,    59,    -1,    -1,    -1,     3,    39,
      40,    41,    42,    -1,     9,    -1,   113,    -1,    73,   116,
      50,    -1,    -1,   120,   121,    55,   123,    -1,    58,    59,
      -1,    -1,    87,    -1,    -1,   132,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    73,    39,    40,    41,    42,   145,   146,
      -1,   148,    -1,   150,    -1,    50,   153,    87,   113,    -1,
      55,   116,    -1,    58,    59,   120,   121,    -1,   123,    39,
      40,    41,    42,    43,    -1,     3,    -1,   132,    73,    -1,
      50,     9,    -1,   113,    -1,    55,   116,    -1,    58,    59,
     145,   146,    87,   148,    -1,   150,    -1,    -1,   153,    -1,
      -1,    -1,   132,    73,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,   145,   146,    87,   113,    -1,
      -1,   116,    50,   153,    -1,   120,   121,    55,   123,    -1,
      58,    59,    -1,    -1,    -1,     3,    -1,   132,    -1,    -1,
      -1,     9,    -1,   113,    -1,    73,   116,    -1,     9,    -1,
     145,   146,    -1,   148,    -1,   150,    -1,    -1,   153,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    -1,    -1,     3,    -1,    40,
      41,    42,    50,     9,    -1,   113,    -1,    55,   116,    50,
      58,    59,   120,   121,    55,   123,    -1,     3,    -1,    -1,
      -1,    -1,    -1,     9,   132,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    39,    40,    41,    42,   145,   146,    87,
     148,    -1,   150,    -1,    50,   153,    87,    -1,    -1,    55,
      -1,    -1,    58,    59,    40,    41,    42,     3,    -1,    -1,
      -1,    -1,    -1,     9,    50,   113,    -1,    73,   116,    55,
      -1,    -1,   120,   121,    -1,   123,   117,   118,    -1,    -1,
      -1,    87,    -1,    -1,   132,    -1,    -1,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    42,   145,   146,    -1,
     148,    87,   150,    -1,    50,   153,    -1,   113,    -1,    55,
     116,   152,    -1,    -1,   120,   121,    -1,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    73,    -1,    -1,
      -1,     3,    -1,    -1,   120,   121,    -1,     9,    -1,   145,
     146,    87,   148,    -1,   150,    -1,   132,   153,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,   142,    -1,    -1,   145,
     146,    -1,   148,    -1,   150,    -1,    -1,   153,    40,    41,
      42,    -1,    -1,    -1,   120,   121,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,   132,    -1,    -1,    -1,
      -1,    -1,    -1,   139,    -1,    -1,   142,    -1,    -1,   145,
     146,    73,   148,    -1,   150,    -1,    -1,   153,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    87,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   121,
      -1,    -1,    39,    40,    41,    42,    -1,    44,    -1,    -1,
     132,    48,    -1,    50,    -1,    -1,    -1,   139,    55,    -1,
     142,    58,    59,   145,   146,    -1,   148,    -1,   150,    -1,
      -1,   153,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   101,   102,   103,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    -1,   120,   121,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,   131,   132,    -1,    -1,    -1,   136,
       9,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,   146,
      -1,    -1,    -1,   150,   151,   152,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    14,    15,    -1,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,
      59,    -1,    39,    40,    41,    42,    -1,    44,    -1,    -1,
      -1,    48,    -1,    50,    73,    -1,    -1,    -1,    55,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    87,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    -1,    14,    15,
      87,    -1,    -1,    -1,   113,    -1,    -1,   116,   117,   118,
      -1,    -1,    -1,    -1,   101,   102,   103,    -1,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    48,   120,   121,   122,   123,    -1,    -1,    55,
      -1,    -1,   151,   130,   131,   132,    -1,    -1,    -1,   136,
      -1,     5,    -1,    -1,    -1,     9,   143,   144,    -1,   146,
      -1,    -1,    -1,   150,   151,   152,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,   114,   115,
      -1,    55,    -1,    -1,   120,   121,   122,   123,    -1,    -1,
      -1,    48,    -1,    -1,   130,   131,   132,    -1,    55,    73,
     136,    -1,    -1,    -1,    -1,    -1,     9,   143,   144,   145,
     146,   147,    -1,    87,    -1,   151,   152,     3,     4,     5,
       6,     7,     8,    -1,    -1,    11,    12,    -1,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    55,    -1,    -1,    58,    59,   114,   115,    -1,
      -1,    -1,    48,   120,   121,   122,   123,    -1,    -1,    55,
      73,    -1,    -1,   130,   131,   132,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    87,    -1,   143,   144,   145,   146,
     147,    -1,    -1,    -1,   151,   152,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,
     113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   126,   127,    -1,    -1,    -1,   114,   115,
      -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,    -1,
      -1,    48,    -1,    -1,   130,   131,   132,    -1,    55,   152,
     136,    -1,    -1,     9,    -1,    -1,    -1,   143,   144,   145,
     146,   147,    -1,    -1,    -1,   151,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,
      -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,     5,    -1,    55,
      -1,     9,    58,    59,    -1,    -1,    -1,   114,   115,    -1,
      -1,    48,    -1,   120,   121,   122,   123,    73,    55,    -1,
      -1,    -1,    -1,   130,   131,   132,    -1,    -1,    -1,   136,
      -1,    87,    40,    41,    42,    -1,   143,   144,    -1,   146,
      -1,    -1,    50,    -1,   151,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   132,   114,   115,    87,
      -1,    -1,    -1,   120,   121,   122,   123,    -1,    -1,   145,
     146,    -1,    -1,   130,   131,   132,    -1,   153,    -1,   136,
       9,    -1,    -1,    -1,    -1,    -1,   143,   144,    -1,   146,
      -1,    -1,    -1,    -1,   151,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    14,    15,    -1,    -1,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,    58,
      59,    39,    40,    41,    42,    -1,    -1,    -1,    -1,     9,
      48,    -1,    50,    -1,    73,    -1,    -1,    55,    -1,    -1,
      58,    59,     3,     4,     5,     6,     7,     8,    87,    -1,
      11,    12,    -1,    14,    15,    73,    -1,    -1,    -1,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      50,    -1,    -1,    -1,   113,    55,    -1,   116,    58,    59,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    73,    55,   113,   114,   115,   116,   117,
     118,    -1,   120,   121,   122,   123,    -1,    87,    -1,    -1,
      -1,    -1,   130,   131,   132,    -1,    -1,    -1,   136,    -1,
      -1,    -1,    -1,    -1,    -1,   143,   144,    -1,   146,    -1,
      -1,    -1,   150,   113,    -1,    -1,   116,    -1,    -1,    -1,
     101,   102,   103,    -1,   105,   106,   107,   108,   109,   110,
     111,   112,    -1,   114,   115,    -1,    -1,    -1,    -1,   120,
     121,   122,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
     131,   132,    -1,   153,    -1,   136,    -1,     9,    -1,    -1,
      -1,    -1,   143,   144,    -1,   146,    -1,    -1,    -1,   150,
       3,     4,     5,     6,     7,     8,    -1,    -1,    11,    12,
      -1,    14,    15,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,     9,    -1,    55,    -1,    -1,    58,    59,     3,     4,
       5,     6,     7,     8,    -1,    48,    11,    12,    -1,    14,
      15,    73,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    87,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      58,    59,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      55,   113,    -1,    -1,   116,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,   114,   115,    -1,    -1,    -1,    -1,   120,   121,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,
      -1,   153,    -1,   136,    -1,   113,    -1,    -1,   116,    -1,
     143,   144,    -1,   146,    -1,    -1,    -1,   150,    -1,   114,
     115,    -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,    -1,
      -1,   136,    -1,    -1,    -1,   153,    -1,    -1,   143,   144,
      -1,   146,    -1,    -1,    -1,   150,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    -1,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    48,     9,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    -1,    50,    -1,    -1,    -1,    73,    55,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    50,    -1,    73,    -1,    -1,    55,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    -1,    -1,    -1,    73,   114,   115,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,    -1,    -1,    -1,
      87,    -1,    -1,   130,   131,   132,   114,   115,    -1,   136,
      -1,    -1,   120,   121,   122,   123,   143,   144,    -1,   146,
      -1,    -1,   130,   131,   132,    -1,   113,    -1,   136,   116,
      -1,    -1,    -1,    -1,    -1,   143,   144,    -1,   146,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      14,    15,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    48,     9,    50,    -1,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    50,    -1,    -1,    -1,    73,
      55,    -1,    -1,    -1,    -1,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    87,    -1,    -1,    50,    -1,    73,    -1,
      -1,    55,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    73,
     114,   115,    -1,    -1,    -1,    -1,   120,   121,   122,   123,
      -1,    -1,    -1,    87,    -1,    -1,   130,   131,   132,   114,
     115,    -1,   136,    -1,    -1,   120,   121,   122,   123,   143,
     144,    -1,   146,    -1,    -1,   130,   131,   132,    -1,   113,
      -1,   136,   116,    -1,    -1,    -1,    -1,    -1,   143,   144,
      -1,   146,     3,     4,     5,     6,     7,     8,    -1,    -1,
      11,    12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    14,    15,    -1,    -1,    -1,    -1,    -1,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    48,     9,    -1,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    -1,    50,    -1,
      -1,    -1,    73,    55,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    -1,    44,    -1,    -1,    87,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    55,    -1,    -1,    58,    59,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      14,    15,    73,   114,   115,    -1,    -1,    -1,    -1,   120,
     121,   122,   123,    -1,    -1,    -1,    87,    -1,    -1,   130,
     131,   132,   114,   115,    -1,   136,    -1,    -1,   120,   121,
     122,   123,   143,   144,    48,   146,    50,    -1,   130,   131,
     132,    55,   113,    -1,   136,   116,    -1,     9,    -1,    -1,
      -1,   143,   144,    -1,   146,   126,   127,    -1,     3,     4,
       5,     6,     7,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,   152,    -1,    -1,    -1,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    55,    -1,    -1,    58,    59,    -1,    -1,
     114,   115,    -1,    48,    -1,    -1,   120,   121,   122,   123,
      55,    73,    -1,    -1,    -1,    -1,   130,   131,   132,    -1,
      -1,    -1,   136,    -1,    -1,    87,    -1,    -1,    -1,   143,
     144,    -1,   146,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,
      -1,   113,    -1,    -1,   116,     3,     4,     5,     6,     7,
       8,    -1,    -1,    11,    12,    -1,    14,    15,    -1,   114,
     115,    -1,    -1,    -1,    -1,   120,   121,   122,   123,    -1,
      -1,    48,     9,    -1,    -1,   130,   131,   132,    55,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,   143,   144,
      48,   146,    -1,    -1,    -1,    -1,    -1,    55,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    73,   114,   115,    -1,
      -1,    -1,    -1,   120,   121,   122,   123,    -1,    -1,    -1,
      87,    -1,    -1,   130,   131,   132,   114,   115,    -1,   136,
      -1,     9,   120,   121,   122,   123,   143,   144,     9,   146,
      -1,    -1,   130,   131,   132,    -1,   113,    -1,   136,   116,
      -1,    -1,    -1,    -1,    -1,   143,   144,    -1,   146,   126,
     127,    39,    40,    41,    42,    -1,    44,    -1,    39,    40,
      41,    42,    50,    44,    -1,    -1,    -1,    55,    -1,    50,
      58,    59,     9,    -1,    55,   152,    -1,    58,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    39,    40,    41,    42,    87,    44,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    59,    -1,     9,   113,    -1,    -1,   116,    -1,
      -1,    -1,   113,    -1,    -1,   116,    73,    -1,   126,   127,
      -1,    -1,    -1,    -1,    -1,   126,   127,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    44,
      -1,    -1,     9,    -1,   152,    50,    -1,    -1,    -1,    -1,
      55,   152,    -1,    58,    59,    -1,   113,    -1,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,    73,   126,
     127,    -1,    39,    40,    41,    42,    -1,    44,    -1,    -1,
      -1,    -1,    87,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    59,    -1,    -1,   152,    39,    40,    41,    42,
      -1,    44,    -1,    -1,     9,    -1,    73,    50,   113,    -1,
      -1,   116,    55,    -1,    -1,    58,    59,    -1,    -1,    -1,
      87,   126,   127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      73,    -1,    -1,    -1,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    50,   113,   152,    -1,   116,
      55,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,   126,
     127,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
     113,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,   126,   127,   152,    -1,    -1,     8,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   152,
      -1,   116,   117,   118,    34,    35,    36,    37,    38,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,    39,    40,    41,    42,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    50,     0,    -1,    -1,    -1,    55,    -1,   119,
      58,    59,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,
     140,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    39,    40,    41,    42,    -1,    44,    -1,    -1,
      -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    58,    59,    -1,    -1,   113,     3,    -1,   116,   117,
     118,     8,    -1,    10,    -1,    -1,    73,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   113,    -1,    -1,   116,
     117,   118,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,     8,    -1,    10,    -1,    -1,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     3,    -1,    -1,    -1,    -1,     8,
      -1,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   119,   120,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     8,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   119
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     9,    39,    40,    41,    42,    44,    50,    55,    58,
      59,    73,    87,   113,   116,   117,   118,   128,   156,   157,
     158,   159,   161,   163,   196,   224,   225,   228,   229,   230,
     231,   232,   240,   254,   255,   256,   259,   275,   138,   146,
     146,   146,     3,     8,     9,    36,     0,   158,   132,   146,
     226,   227,   228,   257,   258,   261,     8,    10,    34,    35,
      36,    37,    38,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   119,
     233,   243,   249,   253,   230,   225,   225,   225,   225,   225,
     231,   232,     5,   228,   232,   241,   246,   254,   259,   267,
       3,     4,     5,     6,     7,     8,    11,    12,    14,    15,
      48,   114,   115,   120,   121,   122,   123,   130,   131,   132,
     136,   143,   144,   146,   182,   195,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   217,   218,   219,   223,   259,   260,   267,   223,
     259,   223,     9,   151,   151,   138,     8,     9,   254,   261,
     262,   228,   257,   148,   150,     3,   150,   182,   125,   160,
     162,   224,   225,   228,   145,   146,   260,   258,   146,     3,
       8,   151,   242,     3,     9,   151,   234,   237,   242,   225,
     225,   246,   139,   148,   145,   146,   261,   268,   269,   246,
     232,   124,   147,   216,   146,   212,   146,   212,   212,   146,
     146,     8,   240,     3,   197,   198,   200,   212,   267,    23,
     141,    22,   135,   137,   136,    20,    21,    18,    19,   138,
     139,    16,    17,   130,   131,   132,   133,   134,   211,    13,
      14,    15,   145,   146,   147,   153,   211,   153,   148,   153,
     148,   153,   138,   126,   127,   171,   172,   173,   177,   178,
     179,   183,   186,   189,   190,   191,   193,   196,   225,   164,
     166,   151,   138,   254,   261,   153,   227,   257,   197,   151,
     279,   279,   162,   140,    10,    36,   132,   154,   198,   262,
     153,   225,   228,   263,   264,   265,   266,   267,     3,   250,
     251,   252,   151,   138,   138,   152,   244,   245,   246,   275,
     151,   151,   151,     5,   267,    36,   132,   154,   198,   262,
     153,   263,   268,   269,   145,   146,   246,     3,   122,   267,
     267,   267,   198,   148,   153,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,   140,   199,   153,   202,   197,
     203,   204,   205,   206,   207,   207,   208,   208,   208,   208,
     209,   209,   210,   210,   211,   211,   211,     3,   182,   197,
     153,   198,   222,     3,   182,     4,   150,     4,   150,   168,
     169,   225,   225,   152,   173,     3,   123,   180,   181,   192,
     194,   261,     3,   236,   241,   127,   174,   175,   176,   177,
     178,   179,   183,   186,   189,   191,   193,   196,   165,   167,
     228,   150,     3,   101,   102,   103,   105,   106,   107,   108,
     109,   110,   111,   112,   150,   152,   196,   197,   224,   259,
     276,   277,   278,   280,   281,   282,   283,   284,   285,   151,
     198,   270,   154,   198,   262,   154,   154,    36,   132,   154,
     198,   146,   257,   261,   268,     3,   153,   148,   148,   153,
     153,   148,   152,   140,   250,   235,   238,   152,   245,   142,
     228,   247,   248,   257,   244,   244,   152,   244,   198,   262,
     154,   154,    36,   154,   198,   153,   153,    36,   132,   154,
     198,   262,   153,   263,   153,   153,   153,   148,   198,   198,
     151,   211,   142,   154,   148,   153,   153,   153,   236,   241,
       3,   184,   185,   261,     3,   187,   188,   261,   146,   146,
     125,   228,   279,   125,   150,   279,   125,   150,   279,   122,
     181,   139,   148,   139,   225,   152,   176,   236,   241,   142,
     223,   142,   146,   146,   146,   276,   146,     3,   150,   150,
     150,   197,   150,   279,   152,   281,   145,   147,   270,   271,
     272,   273,   274,   154,   198,   198,   154,   154,   228,    43,
     265,   228,   152,   251,   223,   148,   152,   236,   236,   239,
     241,   223,   150,   148,   150,   228,   152,   152,   152,   154,
     198,   198,   154,   198,   262,   154,   154,    36,   154,   198,
     153,   102,   220,   221,   267,   271,   200,   198,   150,   150,
     139,   139,   146,   125,   150,   279,   185,   146,   125,   150,
     279,   188,   153,   263,   153,   197,   150,   197,   197,   146,
     151,     3,   151,   187,   139,   139,   276,   142,   276,   197,
     197,   197,   106,   224,   282,   150,   150,   223,     3,   148,
     152,   270,   140,   274,   154,   154,     3,   152,   139,   139,
     248,   142,   154,   154,   154,   198,   198,   154,   142,   148,
     153,   142,   148,   152,   151,   150,   151,   170,   153,   197,
     265,   197,    40,   153,   150,   150,   150,   153,   263,   171,
     171,   151,   151,   276,   153,   153,   153,   146,   282,   282,
     154,   152,   270,   272,   223,   154,   154,   198,   221,   198,
     152,   171,   171,    40,   150,   153,   150,    40,   153,   152,
     152,   171,   171,   276,   276,   276,   197,   153,   197,   153,
     197,   270,   152,   152,    40,   152,   152,   104,   153,   276,
     153,   276,   153,   276,   150,   276,   276
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   155,   156,   156,   157,   157,   158,   158,   158,   158,
     158,   159,   160,   159,   161,   162,   162,   163,   163,   164,
     163,   165,   163,   166,   163,   167,   163,   168,   163,   169,
     163,   163,   170,   170,   171,   171,   172,   172,   173,   173,
     173,   173,   173,   173,   173,   173,   173,   173,   174,   174,
     175,   175,   176,   176,   176,   176,   176,   176,   176,   176,
     176,   177,   178,   179,   180,   180,   181,   181,   181,   181,
     182,   182,   183,   183,   184,   184,   185,   185,   186,   186,
     187,   187,   188,   188,   189,   190,   191,   191,   191,   192,
     192,   193,   193,   193,   194,   195,   195,   196,   197,   197,
     198,   198,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   200,   200,   201,   201,   202,   202,   203,
     203,   204,   204,   205,   205,   206,   206,   206,   207,   207,
     207,   207,   207,   208,   208,   208,   209,   209,   209,   210,
     210,   210,   210,   211,   211,   212,   212,   212,   212,   212,
     212,   212,   212,   213,   213,   213,   213,   213,   213,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   216,   216,   217,   217,   217,   218,
     218,   219,   220,   220,   221,   221,   222,   222,   223,   224,
     224,   224,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   226,   226,   227,   227,
     228,   228,   229,   229,   230,   231,   231,   231,   231,   231,
     231,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   235,   234,
     236,   236,   236,   238,   237,   239,   239,   240,   241,   241,
     241,   241,   242,   242,   243,   243,   244,   244,   245,   245,
     245,   246,   246,   246,   246,   246,   246,   247,   247,   248,
     248,   248,   249,   249,   249,   249,   249,   250,   250,   251,
     251,   252,   253,   254,   254,   254,   254,   254,   255,   255,
     255,   255,   256,   256,   257,   257,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   259,   260,   261,   261,   261,   261,   262,
     262,   263,   263,   264,   264,   265,   265,   265,   266,   266,
     267,   267,   268,   268,   268,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   270,   270,   270,   271,
     271,   271,   271,   272,   273,   273,   274,   274,   275,   275,
     275,   275,   276,   277,   276,   276,   276,   276,   276,   276,
     278,   278,   278,   279,   279,   280,   280,   281,   281,   282,
     282,   283,   283,   283,   284,   284,   284,   284,   284,   284,
     285,   285,   285,   285,   285
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       1,     4,     0,     4,     5,     1,     2,     5,     6,     0,
       9,     0,    10,     0,     9,     0,    10,     0,    10,     0,
       8,     3,     1,     3,     0,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     3,     4,     2,     1,     4,     3,     5,     4,
       1,     1,     4,     4,     2,     1,     3,     4,     4,     4,
       2,     1,     4,     5,     6,     6,     3,     3,     5,     4,
       5,     3,     3,     5,     3,     2,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     4,     1,     2,     2,     2,     2,
       4,     4,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     4,     3,     3,     3,     3,     2,     2,     6,
       7,     1,     1,     1,     3,     1,     1,     2,     3,     3,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     6,     1,     3,     3,     3,     1,     3,     1,     3,
       3,     1,     2,     1,     3,     2,     3,     2,     2,     1,
       2,     1,     2,     1,     2,     1,     1,     3,     4,     2,
       0,     1,     1,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     3,
       4,     4,     5,     2,     5,     2,     2,     5,     0,     5,
       0,     1,     3,     0,     5,     1,     1,     4,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     2,     3,     3,
       1,     2,     1,     3,     2,     2,     1,     1,     3,     2,
       4,     2,     4,     5,     5,     6,     2,     1,     3,     3,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     2,     1,     2,     2,     3,     3,
       4,     6,     5,     5,     6,     5,     4,     4,     4,     4,
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
     125,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   159,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   149,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,     0,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,    67,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,     0,     0,    37,     0,   131,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,     0,     0,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    71,     0,     0,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   107,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,     0,     0,     0,     0,     0,     0,   113,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,     0,     0,     0,     0,     0,     0,     0,     0,
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
       0,     0,     0,    75,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   115,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   145,
       0,     0,     0,     0,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     151,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   153,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     155,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0,   220,     0,   220,     0,   203,     0,   220,     0,   209,
       0,   220,     0,   211,     0,   220,     0,   213,     0,   220,
       0,   215,     0,   220,     0,   220,     0,   220,     0,   220,
       0,   220,     0,   205,     0,   220,     0,   207,     0,   220,
       0,   292,     0,   220,     0,   296,     0,   220,     0,   220,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   220,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   294,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   220,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   220,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   220,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   220,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   220,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   220,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   220,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   220,
       0,   220,     0,   220,     0,   220,     0,   220,     0,   422,
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
#line 579 "parser.y"
        { ast_root = ((*yyvalp).node) = NULL; }
#line 3069 "parser.tab.c"
    break;

  case 3:
#line 581 "parser.y"
        { ast_root = ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3075 "parser.tab.c"
    break;

  case 4:
#line 586 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3081 "parser.tab.c"
    break;

  case 5:
#line 588 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3087 "parser.tab.c"
    break;

  case 6:
#line 593 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3093 "parser.tab.c"
    break;

  case 7:
#line 595 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3099 "parser.tab.c"
    break;

  case 8:
#line 597 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3105 "parser.tab.c"
    break;

  case 9:
#line 600 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3111 "parser.tab.c"
    break;

  case 10:
#line 611 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3117 "parser.tab.c"
    break;

  case 11:
#line 616 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3123 "parser.tab.c"
    break;

  case 12:
#line 618 "parser.y"
        { symbol_table_push_scope(); }
#line 3129 "parser.tab.c"
    break;

  case 13:
#line 620 "parser.y"
        { symbol_table_pop_scope(); ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3135 "parser.tab.c"
    break;

  case 14:
#line 640 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3141 "parser.tab.c"
    break;

  case 15:
#line 645 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3147 "parser.tab.c"
    break;

  case 16:
#line 647 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3153 "parser.tab.c"
    break;

  case 17:
#line 659 "parser.y"
        { ((*yyvalp).node) = create_impl_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3159 "parser.tab.c"
    break;

  case 18:
#line 661 "parser.y"
        { ((*yyvalp).node) = create_static_impl_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3165 "parser.tab.c"
    break;

  case 19:
#line 664 "parser.y"
        { symbol_table_push_scope(); }
#line 3171 "parser.tab.c"
    break;

  case 20:
#line 666 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_generic_impl_node(create_generic_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node)), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
	}
#line 3180 "parser.tab.c"
    break;

  case 21:
#line 671 "parser.y"
        { symbol_table_push_scope(); }
#line 3186 "parser.tab.c"
    break;

  case 22:
#line 673 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_generic_static_impl_node(create_generic_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node)), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
	}
#line 3195 "parser.tab.c"
    break;

  case 23:
#line 679 "parser.y"
        { symbol_table_push_scope(); }
#line 3201 "parser.tab.c"
    break;

  case 24:
#line 681 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_generic_impl_node(create_generic_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node)), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
	}
#line 3210 "parser.tab.c"
    break;

  case 25:
#line 686 "parser.y"
        { symbol_table_push_scope(); }
#line 3216 "parser.tab.c"
    break;

  case 26:
#line 688 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_generic_static_impl_node(create_generic_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node)), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
	}
#line 3225 "parser.tab.c"
    break;

  case 27:
#line 694 "parser.y"
        { symbol_table_push_scope(); }
#line 3231 "parser.tab.c"
    break;

  case 28:
#line 696 "parser.y"
        {
		symbol_table_pop_scope();
		//	Add the generic node to a special list of generic nodes!
		((*yyvalp).node) = create_generic_impl_node(create_generic_declaration_node(create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-7)].yystate.yysemantics.yysval.node), " "), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node)), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
	}
#line 3241 "parser.tab.c"
    break;

  case 29:
#line 702 "parser.y"
        { symbol_table_push_scope(); }
#line 3247 "parser.tab.c"
    break;

  case 30:
#line 704 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_generic_impl_node(create_generic_declaration_node(create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), " "), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node));
	}
#line 3256 "parser.tab.c"
    break;

  case 31:
#line 710 "parser.y"
        {
		fprintf(stderr, "ERROR: `%s` is not a known typedef name! Please make sure you declare a typedef with this name! eg. `typedef struct %s %s;`\n", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)->id.id, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)->id.id, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)->id.id);
		exit(EXIT_FAILURE);
	}
#line 3265 "parser.tab.c"
    break;

  case 32:
#line 732 "parser.y"
              { ((*yyvalp).node) = NULL; }
#line 3271 "parser.tab.c"
    break;

  case 33:
#line 733 "parser.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 3277 "parser.tab.c"
    break;

  case 34:
#line 738 "parser.y"
                 { ((*yyvalp).node) = NULL; }
#line 3283 "parser.tab.c"
    break;

  case 35:
#line 739 "parser.y"
                            { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3289 "parser.tab.c"
    break;

  case 36:
#line 744 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3295 "parser.tab.c"
    break;

  case 37:
#line 746 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3301 "parser.tab.c"
    break;

  case 38:
#line 751 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3307 "parser.tab.c"
    break;

  case 39:
#line 753 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3313 "parser.tab.c"
    break;

  case 40:
#line 755 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3319 "parser.tab.c"
    break;

  case 41:
#line 757 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3325 "parser.tab.c"
    break;

  case 42:
#line 759 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3331 "parser.tab.c"
    break;

  case 43:
#line 761 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3337 "parser.tab.c"
    break;

  case 44:
#line 763 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3343 "parser.tab.c"
    break;

  case 45:
#line 765 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3349 "parser.tab.c"
    break;

  case 46:
#line 767 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3355 "parser.tab.c"
    break;

  case 47:
#line 769 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3361 "parser.tab.c"
    break;

  case 48:
#line 774 "parser.y"
                 { ((*yyvalp).node) = NULL; }
#line 3367 "parser.tab.c"
    break;

  case 49:
#line 775 "parser.y"
                                   { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3373 "parser.tab.c"
    break;

  case 50:
#line 780 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3379 "parser.tab.c"
    break;

  case 51:
#line 782 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 3385 "parser.tab.c"
    break;

  case 52:
#line 787 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3391 "parser.tab.c"
    break;

  case 53:
#line 789 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3397 "parser.tab.c"
    break;

  case 54:
#line 791 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3403 "parser.tab.c"
    break;

  case 55:
#line 793 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3409 "parser.tab.c"
    break;

  case 56:
#line 795 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3415 "parser.tab.c"
    break;

  case 57:
#line 797 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3421 "parser.tab.c"
    break;

  case 58:
#line 799 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3427 "parser.tab.c"
    break;

  case 59:
#line 801 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3433 "parser.tab.c"
    break;

  case 60:
#line 803 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3439 "parser.tab.c"
    break;

  case 61:
#line 810 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3445 "parser.tab.c"
    break;

  case 62:
#line 833 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3451 "parser.tab.c"
    break;

  case 63:
#line 838 "parser.y"
        { ((*yyvalp).node) = create_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL, NULL); }
#line 3457 "parser.tab.c"
    break;

  case 64:
#line 843 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3463 "parser.tab.c"
    break;

  case 65:
#line 845 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3469 "parser.tab.c"
    break;

  case 66:
#line 850 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3475 "parser.tab.c"
    break;

  case 67:
#line 852 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 3481 "parser.tab.c"
    break;

  case 68:
#line 860 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (void *) & const_node); }
#line 3487 "parser.tab.c"
    break;

  case 69:
#line 862 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (void *) & const_node); }
#line 3493 "parser.tab.c"
    break;

  case 70:
#line 881 "parser.y"
               { ((*yyvalp).node) = (void *) & this_node; }
#line 3499 "parser.tab.c"
    break;

  case 71:
#line 882 "parser.y"
               { ((*yyvalp).node) = (void *) & self_node; }
#line 3505 "parser.tab.c"
    break;

  case 72:
#line 887 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3511 "parser.tab.c"
    break;

  case 73:
#line 895 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3517 "parser.tab.c"
    break;

  case 74:
#line 904 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3523 "parser.tab.c"
    break;

  case 75:
#line 906 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3529 "parser.tab.c"
    break;

  case 76:
#line 911 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 3535 "parser.tab.c"
    break;

  case 77:
#line 913 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (void *) & const_node); }
#line 3541 "parser.tab.c"
    break;

  case 78:
#line 918 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3547 "parser.tab.c"
    break;

  case 79:
#line 926 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3553 "parser.tab.c"
    break;

  case 80:
#line 935 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3559 "parser.tab.c"
    break;

  case 81:
#line 937 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3565 "parser.tab.c"
    break;

  case 82:
#line 942 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3571 "parser.tab.c"
    break;

  case 83:
#line 944 "parser.y"
        { ((*yyvalp).node) = (void *) & error_node; fprintf(stderr, "'setter' functions cannot be 'const'!\n"); exit(EXIT_FAILURE); }
#line 3577 "parser.tab.c"
    break;

  case 84:
#line 949 "parser.y"
        { ((*yyvalp).node) = create_getter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3583 "parser.tab.c"
    break;

  case 85:
#line 958 "parser.y"
        { ((*yyvalp).node) = create_setter_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3589 "parser.tab.c"
    break;

  case 86:
#line 991 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3595 "parser.tab.c"
    break;

  case 87:
#line 993 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3601 "parser.tab.c"
    break;

  case 88:
#line 995 "parser.y"
        { ((*yyvalp).node) = create_new_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3607 "parser.tab.c"
    break;

  case 89:
#line 1004 "parser.y"
        { ((*yyvalp).node) = create_new_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 3613 "parser.tab.c"
    break;

  case 90:
#line 1006 "parser.y"
        { ((*yyvalp).node) = create_new_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3619 "parser.tab.c"
    break;

  case 91:
#line 1012 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3625 "parser.tab.c"
    break;

  case 92:
#line 1015 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 3631 "parser.tab.c"
    break;

  case 93:
#line 1018 "parser.y"
        { ((*yyvalp).node) = create_delete_function_definition_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_block_node(create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)))); }
#line 3637 "parser.tab.c"
    break;

  case 94:
#line 1023 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node(NULL, NULL, NULL); }
#line 3643 "parser.tab.c"
    break;

  case 95:
#line 1091 "parser.y"
        { ((*yyvalp).node) = create_function_call_node(create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), (void *) & delete_as_id_node), NULL); }
#line 3649 "parser.tab.c"
    break;

  case 96:
#line 1093 "parser.y"
        { ((*yyvalp).node) = (void *) & delete_as_id_node; }
#line 3655 "parser.tab.c"
    break;

  case 97:
#line 1115 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3661 "parser.tab.c"
    break;

  case 98:
#line 1131 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3667 "parser.tab.c"
    break;

  case 99:
#line 1133 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 3673 "parser.tab.c"
    break;

  case 100:
#line 1138 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3679 "parser.tab.c"
    break;

  case 101:
#line 1140 "parser.y"
        { ((*yyvalp).node) = create_binary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3685 "parser.tab.c"
    break;

  case 102:
#line 1144 "parser.y"
                     { ((*yyvalp).type) = AST_ASSIGN; }
#line 3691 "parser.tab.c"
    break;

  case 103:
#line 1145 "parser.y"
                     { ((*yyvalp).type) = AST_MUL_ASSIGN; }
#line 3697 "parser.tab.c"
    break;

  case 104:
#line 1146 "parser.y"
                     { ((*yyvalp).type) = AST_DIV_ASSIGN; }
#line 3703 "parser.tab.c"
    break;

  case 105:
#line 1147 "parser.y"
                     { ((*yyvalp).type) = AST_MOD_ASSIGN; }
#line 3709 "parser.tab.c"
    break;

  case 106:
#line 1148 "parser.y"
                     { ((*yyvalp).type) = AST_ADD_ASSIGN; }
#line 3715 "parser.tab.c"
    break;

  case 107:
#line 1149 "parser.y"
                     { ((*yyvalp).type) = AST_SUB_ASSIGN; }
#line 3721 "parser.tab.c"
    break;

  case 108:
#line 1150 "parser.y"
                     { ((*yyvalp).type) = AST_SHL_ASSIGN; }
#line 3727 "parser.tab.c"
    break;

  case 109:
#line 1151 "parser.y"
                     { ((*yyvalp).type) = AST_SHR_ASSIGN; }
#line 3733 "parser.tab.c"
    break;

  case 110:
#line 1152 "parser.y"
                     { ((*yyvalp).type) = AST_AND_ASSIGN; }
#line 3739 "parser.tab.c"
    break;

  case 111:
#line 1153 "parser.y"
                     { ((*yyvalp).type) = AST_XOR_ASSIGN; }
#line 3745 "parser.tab.c"
    break;

  case 112:
#line 1154 "parser.y"
                     { ((*yyvalp).type) = AST_OR_ASSIGN; }
#line 3751 "parser.tab.c"
    break;

  case 113:
#line 1160 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3757 "parser.tab.c"
    break;

  case 114:
#line 1162 "parser.y"
        { ((*yyvalp).node) = create_ternary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3763 "parser.tab.c"
    break;

  case 115:
#line 1167 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3769 "parser.tab.c"
    break;

  case 116:
#line 1169 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_OR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3775 "parser.tab.c"
    break;

  case 117:
#line 1174 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3781 "parser.tab.c"
    break;

  case 118:
#line 1176 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_AND, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3787 "parser.tab.c"
    break;

  case 119:
#line 1181 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3793 "parser.tab.c"
    break;

  case 120:
#line 1183 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_OR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3799 "parser.tab.c"
    break;

  case 121:
#line 1188 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3805 "parser.tab.c"
    break;

  case 122:
#line 1190 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_XOR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3811 "parser.tab.c"
    break;

  case 123:
#line 1195 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3817 "parser.tab.c"
    break;

  case 124:
#line 1197 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_BIT_AND, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3823 "parser.tab.c"
    break;

  case 125:
#line 1202 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3829 "parser.tab.c"
    break;

  case 126:
#line 1204 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_EQ, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3835 "parser.tab.c"
    break;

  case 127:
#line 1206 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3841 "parser.tab.c"
    break;

  case 128:
#line 1211 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3847 "parser.tab.c"
    break;

  case 129:
#line 1213 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_LT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3853 "parser.tab.c"
    break;

  case 130:
#line 1215 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_GT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3859 "parser.tab.c"
    break;

  case 131:
#line 1217 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_LE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3865 "parser.tab.c"
    break;

  case 132:
#line 1219 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_GE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3871 "parser.tab.c"
    break;

  case 133:
#line 1224 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3877 "parser.tab.c"
    break;

  case 134:
#line 1226 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SHL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3883 "parser.tab.c"
    break;

  case 135:
#line 1228 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SHR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3889 "parser.tab.c"
    break;

  case 136:
#line 1233 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3895 "parser.tab.c"
    break;

  case 137:
#line 1235 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ADD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3901 "parser.tab.c"
    break;

  case 138:
#line 1237 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_SUB, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3907 "parser.tab.c"
    break;

  case 139:
#line 1242 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3913 "parser.tab.c"
    break;

  case 140:
#line 1244 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_MUL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3919 "parser.tab.c"
    break;

  case 141:
#line 1246 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_DIV, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3925 "parser.tab.c"
    break;

  case 142:
#line 1248 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_MOD, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3931 "parser.tab.c"
    break;

  case 143:
#line 1262 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3937 "parser.tab.c"
    break;

  case 144:
#line 1266 "parser.y"
        { ((*yyvalp).node) = create_cast_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3943 "parser.tab.c"
    break;

  case 145:
#line 1271 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 3949 "parser.tab.c"
    break;

  case 146:
#line 1273 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_PRE_INC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3955 "parser.tab.c"
    break;

  case 147:
#line 1275 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_PRE_DEC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3961 "parser.tab.c"
    break;

  case 148:
#line 1277 "parser.y"
        { ((*yyvalp).node) = create_unary_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3967 "parser.tab.c"
    break;

  case 149:
#line 1279 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_SIZEOF_EXPR, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 3973 "parser.tab.c"
    break;

  case 150:
#line 1281 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_SIZEOF_TYPE, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3979 "parser.tab.c"
    break;

  case 151:
#line 1283 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_ALIGNOF, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 3985 "parser.tab.c"
    break;

  case 152:
#line 1290 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 3991 "parser.tab.c"
    break;

  case 153:
#line 1294 "parser.y"
              { ((*yyvalp).type) = AST_ADDRESS_OF; }
#line 3997 "parser.tab.c"
    break;

  case 154:
#line 1295 "parser.y"
              { ((*yyvalp).type) = AST_DEREFERENCE; }
#line 4003 "parser.tab.c"
    break;

  case 155:
#line 1296 "parser.y"
              { ((*yyvalp).type) = AST_POSITIVE; }
#line 4009 "parser.tab.c"
    break;

  case 156:
#line 1297 "parser.y"
              { ((*yyvalp).type) = AST_NEGATIVE; }
#line 4015 "parser.tab.c"
    break;

  case 157:
#line 1298 "parser.y"
              { ((*yyvalp).type) = AST_BITWISE_NOT; }
#line 4021 "parser.tab.c"
    break;

  case 158:
#line 1299 "parser.y"
              { ((*yyvalp).type) = AST_LOGICAL_NOT; }
#line 4027 "parser.tab.c"
    break;

  case 159:
#line 1304 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4033 "parser.tab.c"
    break;

  case 160:
#line 1306 "parser.y"
        { ((*yyvalp).node) = create_array_subscript_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4039 "parser.tab.c"
    break;

  case 161:
#line 1308 "parser.y"
        { ((*yyvalp).node) = create_function_call_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4045 "parser.tab.c"
    break;

  case 162:
#line 1310 "parser.y"
        { ((*yyvalp).node) = create_function_call_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4051 "parser.tab.c"
    break;

  case 163:
#line 1320 "parser.y"
        { ((*yyvalp).node) = create_member_access_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_THIS || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_SELF ? AST_MEMBER_ACCESS_POINTER : AST_MEMBER_ACCESS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4057 "parser.tab.c"
    break;

  case 164:
#line 1324 "parser.y"
        { ((*yyvalp).node) = create_member_access_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_THIS || (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->type == AST_SELF ? AST_MEMBER_ACCESS_POINTER : AST_MEMBER_ACCESS, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4063 "parser.tab.c"
    break;

  case 165:
#line 1326 "parser.y"
        { ((*yyvalp).node) = create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4069 "parser.tab.c"
    break;

  case 166:
#line 1335 "parser.y"
        { ((*yyvalp).node) = create_member_access_node(AST_MEMBER_ACCESS_POINTER, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4075 "parser.tab.c"
    break;

  case 167:
#line 1337 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_POST_INC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4081 "parser.tab.c"
    break;

  case 168:
#line 1339 "parser.y"
        { ((*yyvalp).node) = create_unary_node(AST_POST_DEC, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4087 "parser.tab.c"
    break;

  case 169:
#line 1342 "parser.y"
        { ((*yyvalp).node) = create_compound_literal_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4093 "parser.tab.c"
    break;

  case 170:
#line 1344 "parser.y"
        { ((*yyvalp).node) = create_compound_literal_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4099 "parser.tab.c"
    break;

  case 171:
#line 1349 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4105 "parser.tab.c"
    break;

  case 172:
#line 1351 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4111 "parser.tab.c"
    break;

  case 173:
#line 1353 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4117 "parser.tab.c"
    break;

  case 174:
#line 1355 "parser.y"
        { ((*yyvalp).node) = create_expression_group_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4123 "parser.tab.c"
    break;

  case 175:
#line 1357 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4129 "parser.tab.c"
    break;

  case 176:
#line 1387 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4135 "parser.tab.c"
    break;

  case 177:
#line 1402 "parser.y"
        {
		sprintf(func_name, "%s__new", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id);
		((*yyvalp).node) = create_id_node(func_name);
	}
#line 4144 "parser.tab.c"
    break;

  case 178:
#line 1407 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NS_OP, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (void *) & new_as_id_node); }
#line 4150 "parser.tab.c"
    break;

  case 179:
#line 1409 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_NS_OP, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4156 "parser.tab.c"
    break;

  case 180:
#line 1414 "parser.y"
        {
		((*yyvalp).node) = create_id_node(get_generic_func_name(GENERIC_FUNC_NEW, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), (void *) & new_as_id_node));
	}
#line 4164 "parser.tab.c"
    break;

  case 181:
#line 1428 "parser.y"
        { ((*yyvalp).node) = (void *) & new_as_id_node; }
#line 4170 "parser.tab.c"
    break;

  case 182:
#line 1433 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4176 "parser.tab.c"
    break;

  case 183:
#line 1437 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4182 "parser.tab.c"
    break;

  case 186:
#line 1448 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4188 "parser.tab.c"
    break;

  case 187:
#line 1450 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4194 "parser.tab.c"
    break;

  case 188:
#line 1452 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4200 "parser.tab.c"
    break;

  case 189:
#line 1462 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4206 "parser.tab.c"
    break;

  case 190:
#line 1464 "parser.y"
        { ((*yyvalp).node) = (void *) & ___func__node; }
#line 4212 "parser.tab.c"
    break;

  case 191:
#line 1469 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 4218 "parser.tab.c"
    break;

  case 196:
#line 1484 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4224 "parser.tab.c"
    break;

  case 197:
#line 1486 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4230 "parser.tab.c"
    break;

  case 198:
#line 1512 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4236 "parser.tab.c"
    break;

  case 199:
#line 1517 "parser.y"
        { ((*yyvalp).node) = create_declaration_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL); }
#line 4242 "parser.tab.c"
    break;

  case 200:
#line 1519 "parser.y"
        { ((*yyvalp).node) = create_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); register_typedef((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4248 "parser.tab.c"
    break;

  case 201:
#line 1532 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4254 "parser.tab.c"
    break;

  case 202:
#line 1538 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4260 "parser.tab.c"
    break;

  case 203:
#line 1540 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4266 "parser.tab.c"
    break;

  case 204:
#line 1542 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 4272 "parser.tab.c"
    break;

  case 205:
#line 1544 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4278 "parser.tab.c"
    break;

  case 206:
#line 1547 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 4284 "parser.tab.c"
    break;

  case 207:
#line 1549 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4290 "parser.tab.c"
    break;

  case 208:
#line 1552 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4296 "parser.tab.c"
    break;

  case 209:
#line 1554 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4302 "parser.tab.c"
    break;

  case 210:
#line 1568 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4308 "parser.tab.c"
    break;

  case 211:
#line 1570 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4314 "parser.tab.c"
    break;

  case 212:
#line 1573 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4320 "parser.tab.c"
    break;

  case 213:
#line 1575 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4326 "parser.tab.c"
    break;

  case 214:
#line 1578 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4332 "parser.tab.c"
    break;

  case 215:
#line 1580 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4338 "parser.tab.c"
    break;

  case 216:
#line 1590 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4344 "parser.tab.c"
    break;

  case 217:
#line 1592 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4350 "parser.tab.c"
    break;

  case 218:
#line 1597 "parser.y"
        { ((*yyvalp).node) = create_init_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4356 "parser.tab.c"
    break;

  case 219:
#line 1599 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4362 "parser.tab.c"
    break;

  case 220:
#line 1617 "parser.y"
                     { ((*yyvalp).node) = NULL; }
#line 4368 "parser.tab.c"
    break;

  case 221:
#line 1618 "parser.y"
                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4374 "parser.tab.c"
    break;

  case 222:
#line 1623 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4380 "parser.tab.c"
    break;

  case 223:
#line 1625 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4386 "parser.tab.c"
    break;

  case 224:
#line 1630 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4392 "parser.tab.c"
    break;

  case 225:
#line 1646 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & typedef_node); }
#line 4398 "parser.tab.c"
    break;

  case 226:
#line 1654 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & extern_node); }
#line 4404 "parser.tab.c"
    break;

  case 227:
#line 1658 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & static_node); }
#line 4410 "parser.tab.c"
    break;

  case 228:
#line 1660 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & thread_local_node); }
#line 4416 "parser.tab.c"
    break;

  case 229:
#line 1662 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & auto_node); }
#line 4422 "parser.tab.c"
    break;

  case 230:
#line 1664 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & register_node); }
#line 4428 "parser.tab.c"
    break;

  case 231:
#line 1675 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & void_node); }
#line 4434 "parser.tab.c"
    break;

  case 232:
#line 1677 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & char_node); }
#line 4440 "parser.tab.c"
    break;

  case 233:
#line 1679 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & short_node); }
#line 4446 "parser.tab.c"
    break;

  case 234:
#line 1681 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & int_node); }
#line 4452 "parser.tab.c"
    break;

  case 235:
#line 1683 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & long_node); }
#line 4458 "parser.tab.c"
    break;

  case 236:
#line 1685 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & float_node); }
#line 4464 "parser.tab.c"
    break;

  case 237:
#line 1687 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & double_node); }
#line 4470 "parser.tab.c"
    break;

  case 238:
#line 1689 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & signed_node); }
#line 4476 "parser.tab.c"
    break;

  case 239:
#line 1691 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & unsigned_node); }
#line 4482 "parser.tab.c"
    break;

  case 240:
#line 1693 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & bool_node); }
#line 4488 "parser.tab.c"
    break;

  case 241:
#line 1695 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & complex_node); }
#line 4494 "parser.tab.c"
    break;

  case 242:
#line 1697 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & imaginary_node); }
#line 4500 "parser.tab.c"
    break;

  case 243:
#line 1699 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4506 "parser.tab.c"
    break;

  case 244:
#line 1701 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4512 "parser.tab.c"
    break;

  case 245:
#line 1703 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4518 "parser.tab.c"
    break;

  case 246:
#line 1705 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4524 "parser.tab.c"
    break;

  case 247:
#line 1712 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4530 "parser.tab.c"
    break;

  case 248:
#line 1720 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4536 "parser.tab.c"
    break;

  case 249:
#line 1747 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & builtin_va_list_node); }
#line 4542 "parser.tab.c"
    break;

  case 250:
#line 1751 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___decimal32_node); }
#line 4548 "parser.tab.c"
    break;

  case 251:
#line 1753 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___decimal64_node); }
#line 4554 "parser.tab.c"
    break;

  case 252:
#line 1755 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___decimal128_node); }
#line 4560 "parser.tab.c"
    break;

  case 253:
#line 1758 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___float128_node); }
#line 4566 "parser.tab.c"
    break;

  case 254:
#line 1760 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___int128_node); }
#line 4572 "parser.tab.c"
    break;

  case 255:
#line 1762 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___int128_t_node); }
#line 4578 "parser.tab.c"
    break;

  case 256:
#line 1764 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___uint128_t_node); }
#line 4584 "parser.tab.c"
    break;

  case 257:
#line 1767 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (void *) & ___bitint128_node); }
#line 4590 "parser.tab.c"
    break;

  case 258:
#line 1769 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4596 "parser.tab.c"
    break;

  case 259:
#line 1776 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.type), NULL, NULL); }
#line 4602 "parser.tab.c"
    break;

  case 260:
#line 1778 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4608 "parser.tab.c"
    break;

  case 261:
#line 1785 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 4614 "parser.tab.c"
    break;

  case 262:
#line 1787 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4620 "parser.tab.c"
    break;

  case 263:
#line 1790 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4626 "parser.tab.c"
    break;

  case 264:
#line 1827 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type) == AST_STRUCT ? AST_GENERIC_STRUCT : AST_GENERIC_UNION, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
		symbol_update_generic_name(get_id_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node))->id.id, ((*yyvalp).node));
	}
#line 4636 "parser.tab.c"
    break;

  case 265:
#line 1834 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type) == AST_STRUCT ? AST_GENERIC_STRUCT : AST_GENERIC_UNION, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL);
		symbol_add_generic_name(get_id_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node))->id.id, NULL);
		// symbol_update_generic_name(get_id_node($2)->id.id, $$);
	}
#line 4647 "parser.tab.c"
    break;

  case 266:
#line 1870 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.type) == AST_STRUCT ? AST_GENERIC_STRUCT : AST_GENERIC_UNION, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL);
		// symbol_add_generic_name(get_id_node($2)->id.id, $$);
	}
#line 4657 "parser.tab.c"
    break;

  case 267:
#line 1876 "parser.y"
        {
		symbol_table_pop_scope();
		((*yyvalp).node) = create_struct_or_union_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.type) == AST_STRUCT ? AST_GENERIC_STRUCT : AST_GENERIC_UNION, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
		// symbol_add_generic_name(get_id_node($2)->id.id, $$);
	}
#line 4667 "parser.tab.c"
    break;

  case 268:
#line 1913 "parser.y"
                {
			//	We need to add the generic name to the outer scope, so that we can potentially reference it internally!
			//	eg. a linked list node that refers to itself! It can't be registered twice!
			//	Once we exit the scope, the symbol will be updated with the complete node!
			symbol_add_generic_name((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)->id.id, NULL);
			symbol_table_push_scope();
		}
#line 4679 "parser.tab.c"
    break;

  case 269:
#line 1921 "parser.y"
                { ((*yyvalp).node) = create_generic_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4685 "parser.tab.c"
    break;

  case 270:
#line 1926 "parser.y"
        { ((*yyvalp).node) = NULL; }
#line 4691 "parser.tab.c"
    break;

  case 271:
#line 1928 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); symbol_add_generic_type((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4697 "parser.tab.c"
    break;

  case 272:
#line 1930 "parser.y"
        { ((*yyvalp).node) = create_generic_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); symbol_add_generic_type((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4703 "parser.tab.c"
    break;

  case 273:
#line 1937 "parser.y"
                { symbol_table_push_scope(); }
#line 4709 "parser.tab.c"
    break;

  case 274:
#line 1940 "parser.y"
                { ((*yyvalp).node) = create_generic_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4715 "parser.tab.c"
    break;

  case 275:
#line 1945 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4721 "parser.tab.c"
    break;

  case 276:
#line 1947 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4727 "parser.tab.c"
    break;

  case 277:
#line 2004 "parser.y"
        { ((*yyvalp).node) = create_generic_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4733 "parser.tab.c"
    break;

  case 278:
#line 2018 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4739 "parser.tab.c"
    break;

  case 279:
#line 2020 "parser.y"
        { ((*yyvalp).node) = create_generic_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4745 "parser.tab.c"
    break;

  case 280:
#line 2022 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4751 "parser.tab.c"
    break;

  case 281:
#line 2024 "parser.y"
        { ((*yyvalp).node) = create_generic_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4757 "parser.tab.c"
    break;

  case 284:
#line 2038 "parser.y"
                 { ((*yyvalp).type) = AST_STRUCT; }
#line 4763 "parser.tab.c"
    break;

  case 285:
#line 2039 "parser.y"
                 { ((*yyvalp).type) = AST_UNION; }
#line 4769 "parser.tab.c"
    break;

  case 286:
#line 2044 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4775 "parser.tab.c"
    break;

  case 287:
#line 2046 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 4781 "parser.tab.c"
    break;

  case 288:
#line 2051 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declaration_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)), NULL); }
#line 4787 "parser.tab.c"
    break;

  case 289:
#line 2053 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4793 "parser.tab.c"
    break;

  case 290:
#line 2077 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4799 "parser.tab.c"
    break;

  case 291:
#line 2082 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4805 "parser.tab.c"
    break;

  case 292:
#line 2084 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4811 "parser.tab.c"
    break;

  case 293:
#line 2118 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "), " "); }
#line 4817 "parser.tab.c"
    break;

  case 294:
#line 2120 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4823 "parser.tab.c"
    break;

  case 295:
#line 2124 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 4829 "parser.tab.c"
    break;

  case 296:
#line 2126 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4835 "parser.tab.c"
    break;

  case 297:
#line 2131 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4841 "parser.tab.c"
    break;

  case 298:
#line 2133 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 4847 "parser.tab.c"
    break;

  case 299:
#line 2138 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), NULL); }
#line 4853 "parser.tab.c"
    break;

  case 300:
#line 2141 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4859 "parser.tab.c"
    break;

  case 301:
#line 2144 "parser.y"
        { ((*yyvalp).node) = create_struct_or_union_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 4865 "parser.tab.c"
    break;

  case 302:
#line 2149 "parser.y"
        { ((*yyvalp).node) = create_enum_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4871 "parser.tab.c"
    break;

  case 303:
#line 2152 "parser.y"
        { ((*yyvalp).node) = create_enum_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4877 "parser.tab.c"
    break;

  case 304:
#line 2155 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4883 "parser.tab.c"
    break;

  case 305:
#line 2158 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 4889 "parser.tab.c"
    break;

  case 306:
#line 2161 "parser.y"
        { ((*yyvalp).node) = create_enum_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 4895 "parser.tab.c"
    break;

  case 307:
#line 2166 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4901 "parser.tab.c"
    break;

  case 308:
#line 2168 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ",\n"); }
#line 4907 "parser.tab.c"
    break;

  case 309:
#line 2173 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ENUM_INIT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); symbol_add_enum_constant((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)->id.id, ((*yyvalp).node)); }
#line 4913 "parser.tab.c"
    break;

  case 310:
#line 2176 "parser.y"
        { ((*yyvalp).node) = create_binary_node(AST_ENUM_INIT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); symbol_add_enum_constant((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)->id.id, ((*yyvalp).node)); }
#line 4919 "parser.tab.c"
    break;

  case 311:
#line 2180 "parser.y"
                     { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 4925 "parser.tab.c"
    break;

  case 312:
#line 2186 "parser.y"
        { ((*yyvalp).node) = create_atomic_type_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 4931 "parser.tab.c"
    break;

  case 313:
#line 2190 "parser.y"
                     { ((*yyvalp).node) = (void *) & const_node; }
#line 4937 "parser.tab.c"
    break;

  case 314:
#line 2191 "parser.y"
                     { ((*yyvalp).node) = (void *) & restrict_node; }
#line 4943 "parser.tab.c"
    break;

  case 315:
#line 2192 "parser.y"
                     { ((*yyvalp).node) = (void *) & ___restrict_node; }
#line 4949 "parser.tab.c"
    break;

  case 316:
#line 2193 "parser.y"
                     { ((*yyvalp).node) = (void *) & volatile_node; }
#line 4955 "parser.tab.c"
    break;

  case 317:
#line 2194 "parser.y"
                     { ((*yyvalp).node) = (void *) & atomic_node; }
#line 4961 "parser.tab.c"
    break;

  case 318:
#line 2198 "parser.y"
                        { ((*yyvalp).node) = (void *) & inline_node; }
#line 4967 "parser.tab.c"
    break;

  case 319:
#line 2199 "parser.y"
                        { ((*yyvalp).node) = (void *) & noreturn_node; }
#line 4973 "parser.tab.c"
    break;

  case 320:
#line 2201 "parser.y"
                        { ((*yyvalp).node) = (void *) & ___inline_node; }
#line 4979 "parser.tab.c"
    break;

  case 321:
#line 2202 "parser.y"
                        { ((*yyvalp).node) = (void *) & ___inline__node; }
#line 4985 "parser.tab.c"
    break;

  case 322:
#line 2207 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 4991 "parser.tab.c"
    break;

  case 323:
#line 2209 "parser.y"
        { ((*yyvalp).node) = create_tmp_node(); }
#line 4997 "parser.tab.c"
    break;

  case 324:
#line 2214 "parser.y"
        { ((*yyvalp).node) = create_pointer_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5003 "parser.tab.c"
    break;

  case 325:
#line 2216 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5009 "parser.tab.c"
    break;

  case 326:
#line 2221 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5015 "parser.tab.c"
    break;

  case 327:
#line 2224 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5021 "parser.tab.c"
    break;

  case 328:
#line 2227 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5027 "parser.tab.c"
    break;

  case 329:
#line 2229 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 5033 "parser.tab.c"
    break;

  case 330:
#line 2231 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 5039 "parser.tab.c"
    break;

  case 331:
#line 2233 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5045 "parser.tab.c"
    break;

  case 332:
#line 2235 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5051 "parser.tab.c"
    break;

  case 333:
#line 2237 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5057 "parser.tab.c"
    break;

  case 334:
#line 2239 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5063 "parser.tab.c"
    break;

  case 335:
#line 2241 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5069 "parser.tab.c"
    break;

  case 336:
#line 2243 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5075 "parser.tab.c"
    break;

  case 337:
#line 2245 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5081 "parser.tab.c"
    break;

  case 338:
#line 2250 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5087 "parser.tab.c"
    break;

  case 339:
#line 2266 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 5093 "parser.tab.c"
    break;

  case 340:
#line 2268 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 5099 "parser.tab.c"
    break;

  case 341:
#line 2270 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5105 "parser.tab.c"
    break;

  case 342:
#line 2277 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 5111 "parser.tab.c"
    break;

  case 343:
#line 2284 "parser.y"
                        { ((*yyvalp).node) = (void *) & ___extension___node; }
#line 5117 "parser.tab.c"
    break;

  case 344:
#line 2290 "parser.y"
                  { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5123 "parser.tab.c"
    break;

  case 345:
#line 2296 "parser.y"
        { ((*yyvalp).node) = create_pointer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5129 "parser.tab.c"
    break;

  case 346:
#line 2298 "parser.y"
        { ((*yyvalp).node) = create_pointer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 5135 "parser.tab.c"
    break;

  case 347:
#line 2300 "parser.y"
        { ((*yyvalp).node) = create_pointer_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5141 "parser.tab.c"
    break;

  case 348:
#line 2302 "parser.y"
        { ((*yyvalp).node) = (void *) & pointer_node; }
#line 5147 "parser.tab.c"
    break;

  case 349:
#line 2307 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5153 "parser.tab.c"
    break;

  case 350:
#line 2309 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), " "); }
#line 5159 "parser.tab.c"
    break;

  case 351:
#line 2314 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (void *) & ellipsis_node, ", "); }
#line 5165 "parser.tab.c"
    break;

  case 352:
#line 2316 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5171 "parser.tab.c"
    break;

  case 353:
#line 2321 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5177 "parser.tab.c"
    break;

  case 354:
#line 2323 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 5183 "parser.tab.c"
    break;

  case 355:
#line 2328 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5189 "parser.tab.c"
    break;

  case 356:
#line 2330 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5195 "parser.tab.c"
    break;

  case 357:
#line 2332 "parser.y"
        { ((*yyvalp).node) = create_parameter_declaration_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 5201 "parser.tab.c"
    break;

  case 358:
#line 2340 "parser.y"
        { ((*yyvalp).node) = maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5207 "parser.tab.c"
    break;

  case 359:
#line 2343 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), maybe_attributes((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), ", "); }
#line 5213 "parser.tab.c"
    break;

  case 360:
#line 2348 "parser.y"
        { ((*yyvalp).node) = create_abstract_type_name_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5219 "parser.tab.c"
    break;

  case 361:
#line 2350 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5225 "parser.tab.c"
    break;

  case 362:
#line 2355 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5231 "parser.tab.c"
    break;

  case 363:
#line 2357 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 5237 "parser.tab.c"
    break;

  case 364:
#line 2359 "parser.y"
        { ((*yyvalp).node) = create_abstract_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5243 "parser.tab.c"
    break;

  case 365:
#line 2365 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5249 "parser.tab.c"
    break;

  case 366:
#line 2367 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node(NULL, NULL); }
#line 5255 "parser.tab.c"
    break;

  case 367:
#line 2369 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node(NULL, NULL); }
#line 5261 "parser.tab.c"
    break;

  case 368:
#line 2371 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5267 "parser.tab.c"
    break;

  case 369:
#line 2373 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5273 "parser.tab.c"
    break;

  case 370:
#line 2375 "parser.y"
        { ((*yyvalp).node) = create_static_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5279 "parser.tab.c"
    break;

  case 371:
#line 2377 "parser.y"
        { ((*yyvalp).node) = create_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5285 "parser.tab.c"
    break;

  case 372:
#line 2379 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5291 "parser.tab.c"
    break;

  case 373:
#line 2381 "parser.y"
        { ((*yyvalp).node) = create_array_node(NULL, NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5297 "parser.tab.c"
    break;

  case 374:
#line 2383 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 5303 "parser.tab.c"
    break;

  case 375:
#line 2385 "parser.y"
        { ((*yyvalp).node) = create_dynamic_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL); }
#line 5309 "parser.tab.c"
    break;

  case 376:
#line 2387 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5315 "parser.tab.c"
    break;

  case 377:
#line 2389 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5321 "parser.tab.c"
    break;

  case 378:
#line 2391 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5327 "parser.tab.c"
    break;

  case 379:
#line 2393 "parser.y"
        { ((*yyvalp).node) = create_static_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5333 "parser.tab.c"
    break;

  case 380:
#line 2395 "parser.y"
        { ((*yyvalp).node) = create_unspecified_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5339 "parser.tab.c"
    break;

  case 381:
#line 2397 "parser.y"
        { ((*yyvalp).node) = create_array_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5345 "parser.tab.c"
    break;

  case 382:
#line 2399 "parser.y"
        { ((*yyvalp).node) = create_grouped_declarator_node(NULL); }
#line 5351 "parser.tab.c"
    break;

  case 383:
#line 2401 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 5357 "parser.tab.c"
    break;

  case 384:
#line 2403 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, NULL); }
#line 5363 "parser.tab.c"
    break;

  case 385:
#line 2405 "parser.y"
        { ((*yyvalp).node) = create_function_declarator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 5369 "parser.tab.c"
    break;

  case 386:
#line 2410 "parser.y"
        { ((*yyvalp).node) = create_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5375 "parser.tab.c"
    break;

  case 387:
#line 2412 "parser.y"
        { ((*yyvalp).node) = create_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5381 "parser.tab.c"
    break;

  case 388:
#line 2414 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5387 "parser.tab.c"
    break;

  case 389:
#line 2419 "parser.y"
        { ((*yyvalp).node) = create_designation_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5393 "parser.tab.c"
    break;

  case 390:
#line 2421 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5399 "parser.tab.c"
    break;

  case 391:
#line 2423 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), create_designation_initializer_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)), ", "); }
#line 5405 "parser.tab.c"
    break;

  case 392:
#line 2425 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ", "); }
#line 5411 "parser.tab.c"
    break;

  case 393:
#line 2430 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node); }
#line 5417 "parser.tab.c"
    break;

  case 394:
#line 2435 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5423 "parser.tab.c"
    break;

  case 395:
#line 2437 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), " "); }
#line 5429 "parser.tab.c"
    break;

  case 396:
#line 2442 "parser.y"
        { ((*yyvalp).node) = create_designator_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), NULL); }
#line 5435 "parser.tab.c"
    break;

  case 397:
#line 2444 "parser.y"
        { ((*yyvalp).node) = create_designator_node(NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5441 "parser.tab.c"
    break;

  case 398:
#line 2460 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST__STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5447 "parser.tab.c"
    break;

  case 399:
#line 2462 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST__STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 5453 "parser.tab.c"
    break;

  case 400:
#line 2464 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST_STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5459 "parser.tab.c"
    break;

  case 401:
#line 2466 "parser.y"
        { ((*yyvalp).node) = create_static_assert_node(AST_STATIC_ASSERT, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL); }
#line 5465 "parser.tab.c"
    break;

  case 402:
#line 2470 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5471 "parser.tab.c"
    break;

  case 403:
#line 2472 "parser.y"
        { symbol_table_push_scope(); }
#line 5477 "parser.tab.c"
    break;

  case 404:
#line 2474 "parser.y"
        { symbol_table_pop_scope(); ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5483 "parser.tab.c"
    break;

  case 405:
#line 2475 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5489 "parser.tab.c"
    break;

  case 406:
#line 2476 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5495 "parser.tab.c"
    break;

  case 407:
#line 2477 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5501 "parser.tab.c"
    break;

  case 408:
#line 2478 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5507 "parser.tab.c"
    break;

  case 409:
#line 2480 "parser.y"
                               { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5513 "parser.tab.c"
    break;

  case 410:
#line 2485 "parser.y"
        { ((*yyvalp).node) = create_labeled_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5519 "parser.tab.c"
    break;

  case 411:
#line 2487 "parser.y"
        { ((*yyvalp).node) = create_case_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5525 "parser.tab.c"
    break;

  case 412:
#line 2489 "parser.y"
        { ((*yyvalp).node) = create_default_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5531 "parser.tab.c"
    break;

  case 413:
#line 2494 "parser.y"
        { ((*yyvalp).node) = create_block_node(NULL); }
#line 5537 "parser.tab.c"
    break;

  case 414:
#line 2498 "parser.y"
                {
			((*yyvalp).node) = create_block_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node));
		// symbol_table_pop_scope();
		}
#line 5546 "parser.tab.c"
    break;

  case 415:
#line 2507 "parser.y"
        { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5552 "parser.tab.c"
    break;

  case 416:
#line 2509 "parser.y"
        { ((*yyvalp).node) = create_list_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), ""); }
#line 5558 "parser.tab.c"
    break;

  case 417:
#line 2513 "parser.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5564 "parser.tab.c"
    break;

  case 418:
#line 2514 "parser.y"
                      { ((*yyvalp).node) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node); }
#line 5570 "parser.tab.c"
    break;

  case 419:
#line 2519 "parser.y"
        { ((*yyvalp).node) = create_expression_statement_node(NULL); }
#line 5576 "parser.tab.c"
    break;

  case 420:
#line 2521 "parser.y"
        { ((*yyvalp).node) = create_expression_statement_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5582 "parser.tab.c"
    break;

  case 421:
#line 2528 "parser.y"
        { ((*yyvalp).node) = create_if_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5588 "parser.tab.c"
    break;

  case 422:
#line 2530 "parser.y"
        { ((*yyvalp).node) = create_if_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node), NULL); }
#line 5594 "parser.tab.c"
    break;

  case 423:
#line 2532 "parser.y"
        { ((*yyvalp).node) = create_switch_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5600 "parser.tab.c"
    break;

  case 424:
#line 2537 "parser.y"
        { ((*yyvalp).node) = create_while_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5606 "parser.tab.c"
    break;

  case 425:
#line 2539 "parser.y"
        { ((*yyvalp).node) = create_do_while_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node)); }
#line 5612 "parser.tab.c"
    break;

  case 426:
#line 2541 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5618 "parser.tab.c"
    break;

  case 427:
#line 2543 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5624 "parser.tab.c"
    break;

  case 428:
#line 2545 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), NULL, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5630 "parser.tab.c"
    break;

  case 429:
#line 2547 "parser.y"
        { ((*yyvalp).node) = create_for_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yysval.node), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yysval.node)); }
#line 5636 "parser.tab.c"
    break;

  case 430:
#line 2551 "parser.y"
                                { ((*yyvalp).node) = create_goto_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5642 "parser.tab.c"
    break;

  case 431:
#line 2552 "parser.y"
                                { ((*yyvalp).node) = (void *) & continue_node; }
#line 5648 "parser.tab.c"
    break;

  case 432:
#line 2553 "parser.y"
                                { ((*yyvalp).node) = (void *) & break_node; }
#line 5654 "parser.tab.c"
    break;

  case 433:
#line 2554 "parser.y"
                                { ((*yyvalp).node) = (void *) & return_node; }
#line 5660 "parser.tab.c"
    break;

  case 434:
#line 2555 "parser.y"
                                { ((*yyvalp).node) = create_return_node((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yysval.node)); }
#line 5666 "parser.tab.c"
    break;


#line 5670 "parser.tab.c"

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



#line 2558 "parser.y"

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


