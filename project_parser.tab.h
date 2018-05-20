/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_PROJECT_PARSER_TAB_H_INCLUDED
# define YY_YY_PROJECT_PARSER_TAB_H_INCLUDED
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
    TK_IDENT = 258,
    TK_INT = 259,
    TK_REAL = 260,
    TK_STRING = 261,
    TK_BOOL_TRUE = 262,
    TK_BOOL_FALSE = 263,
    TK_PLUS = 264,
    TK_MINUS = 265,
    TK_MULTIPLY = 266,
    TK_DIVIDE = 267,
    TK_DIV = 268,
    TK_MOD = 269,
    TK_EQUAL = 270,
    TK_NOTEQUAL = 271,
    TK_SMALLER = 272,
    TK_GREATER = 273,
    TK_SMALLEREQUAL = 274,
    TK_GREATER_EQUAL = 275,
    TK_AND = 276,
    TK_OR = 277,
    TK_NOT = 278,
    TK_LPAR = 279,
    TK_RPAR = 280,
    TK_SEMICOLON = 281,
    TK_COMMA = 282,
    TK_LBRACKET = 283,
    TK_RBRACKET = 284,
    TK_COLON = 285,
    TK_POINT = 286,
    TK_DIGIT = 287,
    TK_CHAR = 288,
    TK_ASSIGN = 289,
    KW_ARRAY = 290,
    KW_PROGRAM = 291,
    KW_BEGIN = 292,
    KW_END = 293,
    KW_BOOLEAN = 294,
    KW_CHAR = 295,
    KW_DO = 296,
    KW_ELSE = 297,
    KW_FOR = 298,
    KW_FUNCTION = 299,
    KW_GOTO = 300,
    KW_IF = 301,
    KW_INTEGER = 302,
    KW_VAR = 303,
    KW_OF = 304,
    KW_WHILE = 305,
    KW_PROCEDURE = 306,
    KW_REAL = 307,
    KW_REPEAT = 308,
    KW_TO = 309,
    KW_RESULT = 310,
    KW_RETURN = 311,
    KW_THEN = 312,
    KW_UNTIL = 313,
    KW_DOWNTO = 314,
    KW_TYPE = 315,
    KW_READSTRING = 316,
    KW_READINTEGER = 317,
    KW_READREAL = 318,
    KW_WRITESTRING = 319,
    KW_WRITEINTEGER = 320,
    KW_WRITEREAL = 321
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "project_parser.y" /* yacc.c:1909  */

	char* crepr;

#line 125 "project_parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROJECT_PARSER_TAB_H_INCLUDED  */
