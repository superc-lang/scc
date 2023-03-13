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
    GENERIC_TYPE = 264,
    GENERIC_NAME = 265,
    FUNC_NAME = 266,
    SIZEOF = 267,
    ARROW = 268,
    INC = 269,
    DEC = 270,
    SHL = 271,
    SHR = 272,
    LE = 273,
    GE = 274,
    EQ = 275,
    NE = 276,
    AND = 277,
    OR = 278,
    MUL_ASSIGN = 279,
    DIV_ASSIGN = 280,
    MOD_ASSIGN = 281,
    ADD_ASSIGN = 282,
    SUB_ASSIGN = 283,
    SHL_ASSIGN = 284,
    SHR_ASSIGN = 285,
    AND_ASSIGN = 286,
    XOR_ASSIGN = 287,
    OR_ASSIGN = 288,
    TYPEDEF = 289,
    EXTERN = 290,
    STATIC = 291,
    AUTO = 292,
    REGISTER = 293,
    INLINE = 294,
    CONST = 295,
    RESTRICT = 296,
    VOLATILE = 297,
    ELLIPSIS = 298,
    PRAGMA = 299,
    __ALIGNOF = 300,
    __ALIGNOF__ = 301,
    __ASM = 302,
    __ASM__ = 303,
    __ATTRIBUTE = 304,
    __ATTRIBUTE__ = 305,
    __COMPLEX = 306,
    __COMPLEX__ = 307,
    __CONST = 308,
    __CONST__ = 309,
    __EXTENSION__ = 310,
    __IMAG = 311,
    __IMAG__ = 312,
    __INLINE = 313,
    __INLINE__ = 314,
    __INTERATOR = 315,
    __INTERATOR__ = 316,
    __LABEL__ = 317,
    __REAL = 318,
    __REAL__ = 319,
    __SIGNED = 320,
    __SIGNED__ = 321,
    __TYPEOF = 322,
    __TYPEOF__ = 323,
    __VOLATILE = 324,
    __VOLATILE__ = 325,
    ASM = 326,
    TYPEOF = 327,
    __RESTRICT = 328,
    __AUTO_TYPE = 329,
    VOID = 330,
    CHAR = 331,
    SHORT = 332,
    INT = 333,
    LONG = 334,
    FLOAT = 335,
    DOUBLE = 336,
    SIGNED = 337,
    UNSIGNED = 338,
    BOOL = 339,
    COMPLEX = 340,
    IMAGINARY = 341,
    ATOMIC = 342,
    STRUCT = 343,
    UNION = 344,
    ENUM = 345,
    __BUILTIN_VA_LIST = 346,
    _DECIMAL32 = 347,
    _DECIMAL64 = 348,
    _DECIMAL128 = 349,
    _FLOAT128 = 350,
    __INT128 = 351,
    __INT128_T = 352,
    __UINT128_T = 353,
    _BITINT128 = 354,
    _BITINT = 355,
    CASE = 356,
    DEFAULT = 357,
    IF = 358,
    ELSE = 359,
    SWITCH = 360,
    WHILE = 361,
    DO = 362,
    FOR = 363,
    GOTO = 364,
    CONTINUE = 365,
    BREAK = 366,
    RETURN = 367,
    ALIGNAS = 368,
    ALIGNOF = 369,
    GENERIC = 370,
    NORETURN = 371,
    _STATIC_ASSERT = 372,
    STATIC_ASSERT = 373,
    THREAD_LOCAL = 374,
    THIS = 375,
    SELF = 376,
    NEW = 377,
    DELETE = 378,
    NS = 379,
    FAT_ARROW = 380,
    GET = 381,
    SET = 382,
    IMPL = 383,
    END_OF_FILE = 384,
    UNARY = 385
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "parser.y"

	char *id;
	char *string;
	char *i_constant;
	char *f_constant;
	union ast_node *node;
	int type;					//	Used for AST_STRUCT and AST_UNION: `struct_or_union`

#line 193 "parser.tab.h"

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
