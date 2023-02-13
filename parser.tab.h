/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Skeleton interface for Bison GLR parsers in C

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    STRING_LITERAL = 259,
    I_CONSTANT = 260,
    F_CONSTANT = 261,
    ENUMERATION_CONSTANT = 262,
    TYPEDEF_NAME = 263,
    FUNC_NAME = 264,
    SIZEOF = 265,
    ARROW = 266,
    INC = 267,
    DEC = 268,
    SHL = 269,
    SHR = 270,
    LE = 271,
    GE = 272,
    EQ = 273,
    NE = 274,
    AND = 275,
    OR = 276,
    MUL_ASSIGN = 277,
    DIV_ASSIGN = 278,
    MOD_ASSIGN = 279,
    ADD_ASSIGN = 280,
    SUB_ASSIGN = 281,
    SHL_ASSIGN = 282,
    SHR_ASSIGN = 283,
    AND_ASSIGN = 284,
    XOR_ASSIGN = 285,
    OR_ASSIGN = 286,
    TYPEDEF = 287,
    EXTERN = 288,
    STATIC = 289,
    AUTO = 290,
    REGISTER = 291,
    INLINE = 292,
    CONST = 293,
    RESTRICT = 294,
    VOLATILE = 295,
    ELLIPSIS = 296,
    PRAGMA = 297,
    __ALIGNOF = 298,
    __ALIGNOF__ = 299,
    __ASM = 300,
    __ASM__ = 301,
    __ATTRIBUTE = 302,
    __ATTRIBUTE__ = 303,
    __COMPLEX = 304,
    __COMPLEX__ = 305,
    __CONST = 306,
    __CONST__ = 307,
    __EXTENSION__ = 308,
    __IMAG = 309,
    __IMAG__ = 310,
    __INLINE = 311,
    __INLINE__ = 312,
    __INTERATOR = 313,
    __INTERATOR__ = 314,
    __LABEL__ = 315,
    __REAL = 316,
    __REAL__ = 317,
    __SIGNED = 318,
    __SIGNED__ = 319,
    __TYPEOF = 320,
    __TYPEOF__ = 321,
    __VOLATILE = 322,
    __VOLATILE__ = 323,
    ASM = 324,
    TYPEOF = 325,
    __RESTRICT = 326,
    __AUTO_TYPE = 327,
    VOID = 328,
    CHAR = 329,
    SHORT = 330,
    INT = 331,
    LONG = 332,
    FLOAT = 333,
    DOUBLE = 334,
    SIGNED = 335,
    UNSIGNED = 336,
    BOOL = 337,
    COMPLEX = 338,
    IMAGINARY = 339,
    ATOMIC = 340,
    STRUCT = 341,
    UNION = 342,
    ENUM = 343,
    __BUILTIN_VA_LIST = 344,
    _DECIMAL32 = 345,
    _DECIMAL64 = 346,
    _DECIMAL128 = 347,
    _FLOAT128 = 348,
    __INT128 = 349,
    __INT128_T = 350,
    __UINT128_T = 351,
    _BITINT128 = 352,
    _BITINT = 353,
    CASE = 354,
    DEFAULT = 355,
    IF = 356,
    ELSE = 357,
    SWITCH = 358,
    WHILE = 359,
    DO = 360,
    FOR = 361,
    GOTO = 362,
    CONTINUE = 363,
    BREAK = 364,
    RETURN = 365,
    ALIGNAS = 366,
    ALIGNOF = 367,
    GENERIC = 368,
    NORETURN = 369,
    _STATIC_ASSERT = 370,
    STATIC_ASSERT = 371,
    THREAD_LOCAL = 372,
    THIS = 373,
    SELF = 374,
    NEW = 375,
    DELETE = 376,
    NS = 377,
    FAT_ARROW = 378,
    GET = 379,
    SET = 380,
    IMPL = 381,
    END_OF_FILE = 382,
    UNARY = 383
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 88 "parser.y"

	char *id;
	char *string;
	char *i_constant;
	char *f_constant;
	union ast_node* node;
	int type;					//	Used for AST_STRUCT and AST_UNION: `struct_or_union`

#line 191 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
