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
    CLASS_NAME = 264,
    FUNC_NAME = 265,
    SIZEOF = 266,
    ARROW = 267,
    INC = 268,
    DEC = 269,
    SHL = 270,
    SHR = 271,
    LE = 272,
    GE = 273,
    EQ = 274,
    NE = 275,
    AND = 276,
    OR = 277,
    MUL_ASSIGN = 278,
    DIV_ASSIGN = 279,
    MOD_ASSIGN = 280,
    ADD_ASSIGN = 281,
    SUB_ASSIGN = 282,
    SHL_ASSIGN = 283,
    SHR_ASSIGN = 284,
    AND_ASSIGN = 285,
    XOR_ASSIGN = 286,
    OR_ASSIGN = 287,
    TYPEDEF = 288,
    EXTERN = 289,
    STATIC = 290,
    AUTO = 291,
    REGISTER = 292,
    INLINE = 293,
    CONST = 294,
    RESTRICT = 295,
    VOLATILE = 296,
    ELLIPSIS = 297,
    PRAGMA = 298,
    __ALIGNOF = 299,
    __ALIGNOF__ = 300,
    __ASM = 301,
    __ASM__ = 302,
    __ATTRIBUTE = 303,
    __ATTRIBUTE__ = 304,
    __COMPLEX = 305,
    __COMPLEX__ = 306,
    __CONST = 307,
    __CONST__ = 308,
    __EXTENSION__ = 309,
    __IMAG = 310,
    __IMAG__ = 311,
    __INLINE = 312,
    __INLINE__ = 313,
    __INTERATOR = 314,
    __INTERATOR__ = 315,
    __LABEL__ = 316,
    __REAL = 317,
    __REAL__ = 318,
    __SIGNED = 319,
    __SIGNED__ = 320,
    __TYPEOF = 321,
    __TYPEOF__ = 322,
    __VOLATILE = 323,
    __VOLATILE__ = 324,
    ASM = 325,
    TYPEOF = 326,
    __RESTRICT = 327,
    __AUTO_TYPE = 328,
    __FORCEINLINE = 329,
    FOREACH = 330,
    IN = 331,
    VOID = 332,
    CHAR = 333,
    SHORT = 334,
    INT = 335,
    LONG = 336,
    FLOAT = 337,
    DOUBLE = 338,
    SIGNED = 339,
    UNSIGNED = 340,
    BOOL = 341,
    COMPLEX = 342,
    IMAGINARY = 343,
    ATOMIC = 344,
    STRUCT = 345,
    UNION = 346,
    ENUM = 347,
    __BUILTIN_VA_LIST = 348,
    _DECIMAL32 = 349,
    _DECIMAL64 = 350,
    _DECIMAL128 = 351,
    _FLOAT128 = 352,
    __INT128 = 353,
    __INT128_T = 354,
    __UINT128_T = 355,
    _BITINT128 = 356,
    _BITINT = 357,
    CASE = 358,
    DEFAULT = 359,
    IF = 360,
    ELSE = 361,
    SWITCH = 362,
    WHILE = 363,
    DO = 364,
    FOR = 365,
    GOTO = 366,
    CONTINUE = 367,
    BREAK = 368,
    RETURN = 369,
    ALIGNAS = 370,
    ALIGNOF = 371,
    GENERIC = 372,
    NORETURN = 373,
    _STATIC_ASSERT = 374,
    STATIC_ASSERT = 375,
    THREAD_LOCAL = 376,
    THIS = 377,
    SELF = 378,
    NEW = 379,
    DELETE = 380,
    NS = 381,
    FAT_ARROW = 382,
    BYTE = 383,
    DEFER = 384,
    VAR = 385,
    LET = 386,
    CONSTRUCTOR = 387,
    DESTRUCTOR = 388,
    GET = 389,
    SET = 390,
    READONLY = 391,
    IMPL = 392,
    CLASS = 393,
    EXTENDS = 394,
    ABSTRACT = 395,
    OPAQUE = 396,
    VIRTUAL = 397,
    INTERFACE = 398,
    FINAL = 399,
    PUBLIC = 400,
    PRIVATE = 401,
    PROTECTED = 402,
    INTERNAL = 403,
    OVERRIDE = 404,
    EXPLICIT = 405,
    FRIEND = 406,
    OPERATOR = 407,
    TYPENAME = 408,
    USING = 409,
    IMPLEMENTS = 410,
    TRAIT = 411,
    MIXIN = 412,
    TYPE = 413,
    TEMPLATE = 414,
    NAMESPACE = 415,
    IMPORT = 416,
    PACKAGE = 417,
    INSTANCEOF = 418,
    NATIVE = 419,
    SUPER = 420,
    SYNCRONIZED = 421,
    TRANSIENT = 422,
    END_OF_FILE = 423,
    UNARY = 424
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

#line 232 "parser.tab.h"

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
