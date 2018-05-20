/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "project_parser.y" /* yacc.c:339  */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cgen.h"

extern int yylex(void);
extern int line_num;

#line 77 "project_parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "project_parser.tab.h".  */
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
#line 13 "project_parser.y" /* yacc.c:355  */

	char* crepr;

#line 188 "project_parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PROJECT_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 205 "project_parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   522

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  67
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  113
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   158,   166,   167,   168,   170,   171,   173,
     175,   176,   178,   180,   181,   183,   184,   186,   187,   189,
     191,   193,   195,   197,   198,   199,   201,   203,   205,   207,
     209,   210,   211,   212,   214,   215,   216,   218,   219,   222,
     223,   227,   230,   231,   232,   233,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   245,   246,   247,   249,   253,
     255,   257,   258,   260,   261,   263,   264,   266,   268,   270,
     273,   274,   275,   277,   278,   279,   280,   281,   282,   284,
     286,   288,   289,   291,   292,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     311,   312,   313,   314,   316,   317,   318,   319,   322,   323,
     324,   325,   326,   327
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_IDENT", "TK_INT", "TK_REAL",
  "TK_STRING", "TK_BOOL_TRUE", "TK_BOOL_FALSE", "TK_PLUS", "TK_MINUS",
  "TK_MULTIPLY", "TK_DIVIDE", "TK_DIV", "TK_MOD", "TK_EQUAL",
  "TK_NOTEQUAL", "TK_SMALLER", "TK_GREATER", "TK_SMALLEREQUAL",
  "TK_GREATER_EQUAL", "TK_AND", "TK_OR", "TK_NOT", "TK_LPAR", "TK_RPAR",
  "TK_SEMICOLON", "TK_COMMA", "TK_LBRACKET", "TK_RBRACKET", "TK_COLON",
  "TK_POINT", "TK_DIGIT", "TK_CHAR", "TK_ASSIGN", "KW_ARRAY", "KW_PROGRAM",
  "KW_BEGIN", "KW_END", "KW_BOOLEAN", "KW_CHAR", "KW_DO", "KW_ELSE",
  "KW_FOR", "KW_FUNCTION", "KW_GOTO", "KW_IF", "KW_INTEGER", "KW_VAR",
  "KW_OF", "KW_WHILE", "KW_PROCEDURE", "KW_REAL", "KW_REPEAT", "KW_TO",
  "KW_RESULT", "KW_RETURN", "KW_THEN", "KW_UNTIL", "KW_DOWNTO", "KW_TYPE",
  "KW_READSTRING", "KW_READINTEGER", "KW_READREAL", "KW_WRITESTRING",
  "KW_WRITEINTEGER", "KW_WRITEREAL", "$accept", "program",
  "program_header", "program_declarations", "declaring",
  "types_declaration", "program_types", "variables_declaration",
  "variables_declaration_body", "identifiers", "subroutines", "function",
  "function_header", "procedure", "procedure_header",
  "subroutine_arguments", "procedure_declarations", "procedure_body",
  "program_body", "program_end", "basic_data_type", "data_type",
  "brackets", "commands", "complex_command", "command_list", "command",
  "complex_command_list", "statement_commands", "assign_command",
  "special_assign", "if_statement", "for_loop", "while_loop",
  "label_command", "goto_command", "return_command", "call_subroutine",
  "default_subroutine", "call_function", "call_procedure",
  "call_arguments", "call_arguments_list", "expression", "mathematics",
  "compare", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321
};
# endif

#define YYPACT_NINF -157

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-157)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -31,    39,    38,  -157,    26,  -157,    -7,  -157,  -157,    86,
      87,    95,   113,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,    91,    29,    93,  -157,    87,    35,    99,   104,   121,
      85,    89,    89,  -157,  -157,    53,   135,  -157,  -157,   124,
     129,   331,   331,    97,   108,  -157,   119,   120,   122,   127,
    -157,  -157,  -157,  -157,   106,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,   153,    43,   154,   -12,   153,   -12,
     143,   130,  -157,  -157,   158,    97,   199,  -157,  -157,   109,
     132,  -157,   139,  -157,  -157,  -157,  -157,  -157,   331,   331,
     331,   211,  -157,  -157,   255,  -157,  -157,   269,  -157,   105,
     331,   331,   331,   331,  -157,    97,   138,    61,   -12,  -157,
     -25,  -157,  -157,  -157,  -157,  -157,   145,    88,   150,   -12,
     174,  -157,   157,   152,  -157,     5,  -157,  -157,  -157,   456,
      75,  -157,  -157,   331,   331,   155,   469,   481,  -157,   159,
     388,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,    97,    97,   331,   456,   405,   422,
     439,  -157,   -12,   160,   184,   163,    24,     8,  -157,   204,
    -157,   215,  -157,  -157,   230,   158,  -157,    -3,   356,   331,
     239,  -157,   469,   481,   492,   328,   500,   176,   207,   218,
     191,     0,    47,   223,  -157,  -157,  -157,   456,  -157,  -157,
    -157,  -157,  -157,   217,  -157,  -157,    24,  -157,  -157,  -157,
     224,   331,   331,  -157,   372,  -157,   -12,  -157,  -157,   283,
     311,  -157,  -157,    97,    97,  -157,  -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     0,     1,     0,     3,    39,     0,
       0,     0,     0,     5,     7,     8,     6,    17,     4,    18,
       4,     0,     0,     0,    15,    12,     0,     0,     0,     9,
      26,     0,     0,    29,     2,     0,     0,    55,    28,     0,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
      40,    42,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    70,    71,    72,    23,     0,     0,     0,    23,     0,
       0,     0,    27,    21,    81,     0,     0,    44,    43,     0,
       0,    68,    88,    85,    86,    87,    89,    90,     0,     0,
       0,     0,    92,    91,     0,    97,    98,     0,    58,     0,
       0,     0,     0,     0,    45,     0,     0,     0,     0,    16,
       0,    31,    32,    30,    33,    34,     0,     0,     0,     0,
       0,    83,     0,    82,    67,    88,    76,    77,    78,    59,
       0,    41,    56,     0,     0,    99,    93,    94,   107,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,     0,     0,
       0,    62,     0,     0,     0,     0,     0,     0,    13,     0,
      10,     0,    19,    80,     0,    81,    57,     0,     0,     0,
       0,    95,   102,   103,   104,   100,   101,   110,   113,   111,
     108,   112,   109,   105,   106,    61,    65,    66,    73,    74,
      75,    24,    20,     0,    14,    36,     0,    22,    11,    84,
       0,     0,     0,    37,     0,    96,     0,    35,    79,     0,
       0,    38,    25,     0,     0,    63,    64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,   245,  -157,  -157,  -157,  -157,  -157,   227,
    -157,  -157,  -157,  -157,  -157,   185,   234,   225,   249,  -157,
    -156,   -65,   146,  -157,     3,  -157,   -34,  -157,   -74,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,    84,  -157,   -42,  -157,  -157
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    30,    13,    14,    29,    15,    25,    26,
      16,    17,    18,    19,    20,   107,    31,    71,    72,    34,
     115,   116,   135,    22,    98,    50,    51,    79,    99,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   122,   123,    94,    95,    96
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      97,   124,    78,   134,   118,     1,   141,   142,   143,   144,
     205,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     151,   152,   153,   110,   166,    49,   139,   111,   112,   175,
       8,   161,    35,   134,   129,   113,   179,     9,     5,    77,
     114,    10,     4,   165,    11,   132,   136,   137,   138,   140,
     217,   211,     7,    12,   171,    36,   212,   206,   157,   158,
     159,   160,    66,   111,   112,    67,    37,    38,   152,   153,
      66,   113,    39,   108,    40,    41,   114,    74,    35,    42,
     195,   196,    43,    75,    44,    45,   163,    76,   164,    23,
      24,   177,   178,    46,    47,    48,   176,   201,    27,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,    35,   169,   197,   164,    28,    64,    39,    69,
      40,    41,    33,    68,    70,    42,     8,    80,    43,     9,
      44,    45,    81,    10,    37,   130,    11,   214,    35,    46,
      47,    48,   100,   101,   102,    12,   103,   131,   105,   225,
     226,   222,    39,   104,    40,    41,   106,   109,   119,    42,
     120,   121,    43,   156,    44,    45,   133,   134,   162,   219,
     220,   168,    37,    46,    47,    48,   170,   172,    39,   174,
      40,    41,   173,   179,   180,    42,   202,   203,    43,   204,
      44,    45,   147,   148,   149,   150,   151,   152,   153,    46,
      47,    48,   125,    83,    84,    85,    86,    87,    88,    89,
     150,   151,   152,   153,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   148,   149,   150,   151,   152,   153,
     207,    92,    93,   209,    90,    91,   149,   150,   151,   152,
     153,   208,   215,    92,    93,   153,   110,   216,     6,   218,
     111,   112,    65,   117,    32,    21,   167,    73,   113,   210,
     126,   127,   128,   114,   141,   142,   143,   144,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   141,   142,
     143,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   141,   142,   143,   144,     0,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,     0,     0,     0,
     155,     0,   154,     0,     0,     0,     0,     0,     0,     0,
     141,   142,   143,   144,   223,   145,   146,   147,   148,   149,
     150,   151,   152,   153,    82,    83,    84,    85,    86,    87,
      88,    89,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,   224,     0,    90,    91,     0,     0,     0,     0,
       0,     0,     0,    92,    93,   141,   142,   143,   144,     0,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,   141,   142,   143,   144,   213,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,   141,   142,   143,
     144,   221,   145,   146,   147,   148,   149,   150,   151,   152,
     153,     0,     0,   181,   141,   142,   143,   144,     0,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     0,     0,
     198,   141,   142,   143,   144,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,     0,     0,   199,   141,   142,
     143,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     0,     0,   200,   141,   142,   143,   144,     0,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   142,
     143,   144,     0,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   143,   144,     0,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   144,     0,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   146,   147,   148,   149,   150,
     151,   152,   153
};

static const yytype_int16 yycheck[] =
{
      42,    75,    36,    28,    69,    36,     9,    10,    11,    12,
     166,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      20,    21,    22,    35,    49,    22,    91,    39,    40,    24,
      37,   105,     3,    28,    76,    47,    28,    44,     0,    36,
      52,    48,     3,   108,    51,    79,    88,    89,    90,    91,
     206,    54,    26,    60,   119,    26,    59,    49,   100,   101,
     102,   103,    27,    39,    40,    30,    37,    38,    21,    22,
      27,    47,    43,    30,    45,    46,    52,    24,     3,    50,
     154,   155,    53,    30,    55,    56,    25,    34,    27,     3,
       3,   133,   134,    64,    65,    66,   130,   162,     3,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,     3,    25,   156,    27,     3,    24,    43,    15,
      45,    46,    31,    24,     3,    50,    37,     3,    53,    44,
      55,    56,     3,    48,    37,    26,    51,   179,     3,    64,
      65,    66,    34,    24,    24,    60,    24,    38,    42,   223,
     224,   216,    43,    26,    45,    46,     3,     3,    15,    50,
      30,     3,    53,    58,    55,    56,    34,    28,    30,   211,
     212,    26,    37,    64,    65,    66,    26,     3,    43,    27,
      45,    46,    25,    28,    25,    50,    26,     3,    53,    26,
      55,    56,    16,    17,    18,    19,    20,    21,    22,    64,
      65,    66,     3,     4,     5,     6,     7,     8,     9,    10,
      19,    20,    21,    22,     3,     4,     5,     6,     7,     8,
       9,    10,    23,    24,    17,    18,    19,    20,    21,    22,
      26,    32,    33,     3,    23,    24,    18,    19,    20,    21,
      22,    26,     3,    32,    33,    22,    35,    30,     3,    25,
      39,    40,    25,    68,    20,     6,   110,    32,    47,   175,
      61,    62,    63,    52,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,     9,    10,    11,    12,    -1,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      41,    -1,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       9,    10,    11,    12,    41,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     3,     4,     5,     6,     7,     8,
       9,    10,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    41,    -1,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,     9,    10,    11,    12,    29,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,     9,    10,    11,
      12,    29,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    25,     9,    10,    11,    12,    -1,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      25,     9,    10,    11,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    -1,    25,     9,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    25,     9,    10,    11,    12,    -1,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    10,
      11,    12,    -1,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    11,    12,    -1,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    12,    -1,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    15,    16,    17,    18,    19,
      20,    21,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    68,    69,     3,     0,    70,    26,    37,    44,
      48,    51,    60,    71,    72,    74,    77,    78,    79,    80,
      81,    85,    90,     3,     3,    75,    76,     3,     3,    73,
      70,    83,    83,    31,    86,     3,    26,    37,    38,    43,
      45,    46,    50,    53,    55,    56,    64,    65,    66,    91,
      92,    93,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    24,    76,    27,    30,    24,    15,
       3,    84,    85,    84,    24,    30,    34,    91,    93,    94,
       3,     3,     3,     4,     5,     6,     7,     8,     9,    10,
      23,    24,    32,    33,   110,   111,   112,   110,    91,    95,
      34,    24,    24,    24,    26,    42,     3,    82,    30,     3,
      35,    39,    40,    47,    52,    87,    88,    82,    88,    15,
      30,     3,   108,   109,    95,     3,    61,    62,    63,   110,
      26,    38,    93,    34,    28,    89,   110,   110,   110,    88,
     110,     9,    10,    11,    12,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    57,    41,    58,   110,   110,   110,
     110,    95,    30,    25,    27,    88,    49,    89,    26,    25,
      26,    88,     3,    25,    27,    24,    93,   110,   110,    28,
      25,    25,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,    95,    95,   110,    25,    25,
      25,    88,    26,     3,    26,    87,    49,    26,    26,     3,
     108,    54,    59,    29,   110,     3,    30,    87,    25,   110,
     110,    29,    88,    41,    41,    95,    95
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    67,    68,    69,    70,    70,    70,    71,    71,    72,
      73,    73,    74,    75,    75,    76,    76,    77,    77,    78,
      79,    80,    81,    82,    82,    82,    83,    84,    85,    86,
      87,    87,    87,    87,    88,    88,    88,    89,    89,    90,
      90,    91,    92,    92,    92,    92,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    94,    95,    96,
      97,    98,    98,    99,    99,   100,   100,   101,   102,   103,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   106,
     107,   108,   108,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     111,   111,   111,   111,   111,   111,   111,   111,   112,   112,
     112,   112,   112,   112
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     0,     2,     2,     1,     1,     2,
       4,     5,     2,     4,     5,     1,     3,     1,     1,     5,
       6,     3,     6,     0,     3,     5,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     4,     0,
       2,     3,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     3,     1,     3,
       3,     4,     3,     8,     8,     4,     4,     3,     2,     1,
       1,     1,     1,     4,     4,     4,     3,     3,     3,     6,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     4,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
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
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 145 "project_parser.y" /* yacc.c:1646  */
    {
	/* We have a successful parse!
		Check for any errors and generate output.
	*/
	if(yyerror_count==0) {
		puts(c_prologue); // include etc
		printf("/* program  %s */ \n\n", (yyvsp[-3].crepr)); // program name as comment
		printf((yyvsp[-2].crepr)); // declaration part
		printf("int main() %s \n", (yyvsp[-1].crepr)); // program main
	}
}
#line 1528 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 158 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[-1].crepr)); }
#line 1534 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 166 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template(""); }
#line 1540 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 167 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s\n%s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 1546 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 168 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s\n%s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 1552 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 170 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1558 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 171 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1564 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 173 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1570 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 175 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("typedef %s %s;", (yyvsp[-1].crepr), (yyvsp[-3].crepr)); }
#line 1576 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 176 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s\ntypedef %s %s;", (yyvsp[-4].crepr), (yyvsp[-1].crepr), (yyvsp[-3].crepr)); }
#line 1582 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 178 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1588 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 180 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s %s;", (yyvsp[-1].crepr), (yyvsp[-3].crepr)); }
#line 1594 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 181 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s\n%s %s;", (yyvsp[-4].crepr), (yyvsp[-1].crepr), (yyvsp[-3].crepr)); }
#line 1600 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 183 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1606 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 184 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s, %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1612 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 186 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1618 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 187 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1624 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 189 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s{\n\t%s\n%s} %s %s", (yyvsp[-4].crepr), (yyvsp[-3].crepr), (yyvsp[-2].crepr), (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 1630 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 191 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("void %s(%s)", (yyvsp[-4].crepr), (yyvsp[-2].crepr)); }
#line 1636 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 193 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s{\n\t%s\n%s}", (yyvsp[-2].crepr), (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 1642 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 195 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("void %s(%s)", (yyvsp[-4].crepr), (yyvsp[-2].crepr)); }
#line 1648 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 197 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template(""); }
#line 1654 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 198 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s %s", (yyvsp[0].crepr), (yyvsp[-2].crepr)); }
#line 1660 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 199 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s, %s %s", (yyvsp[-4].crepr), (yyvsp[0].crepr), (yyvsp[-2].crepr)); }
#line 1666 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 201 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1672 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 203 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1678 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 205 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("{/n %s /n }\n", (yyvsp[-1].crepr)); }
#line 1684 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 207 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template(""); }
#line 1690 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 209 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("int"); }
#line 1696 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 210 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("int"); }
#line 1702 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 211 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("char"); }
#line 1708 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 212 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("double"); }
#line 1714 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 214 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template((yyvsp[0].crepr)); }
#line 1720 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 215 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s [%s]", (yyvsp[0].crepr), (yyvsp[-2].crepr)); }
#line 1726 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 216 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s*", (yyvsp[0].crepr)); }
#line 1732 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 218 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("[%s]", (yyvsp[-1].crepr)); }
#line 1738 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 219 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s [%s]", (yyvsp[-3].crepr), (yyvsp[-1].crepr)); }
#line 1744 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 222 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template(""); }
#line 1750 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 223 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s%s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 1756 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 227 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[-1].crepr)); }
#line 1762 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 230 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1768 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 231 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s\n", (yyvsp[0].crepr)); }
#line 1774 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 232 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1780 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 233 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[-1].crepr)); }
#line 1786 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 235 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1792 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 236 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1798 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 237 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1804 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 238 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1810 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 239 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1816 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 240 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1822 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 241 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1828 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 242 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1834 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 243 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1840 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 245 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template(""); }
#line 1846 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 246 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s\n%s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 1852 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 247 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s\n%s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1858 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 249 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1864 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 253 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s = %s;", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1870 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 255 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("result = %s;", (yyvsp[0].crepr)); }
#line 1876 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 257 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("if (%s){\n\t%s}\n", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1882 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 258 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("else{\n\t%s}\n", (yyvsp[0].crepr)); }
#line 1888 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 260 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("for(%s=%s;%s<=%s;%s++){\n\t%s}\n", (yyvsp[-6].crepr), (yyvsp[-4].crepr), (yyvsp[-6].crepr), (yyvsp[-2].crepr), (yyvsp[-6].crepr), (yyvsp[0].crepr));}
#line 1894 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 261 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("for(%s=%s;%s>=%s;%s--){\n\t%s}\n", (yyvsp[-6].crepr), (yyvsp[-4].crepr), (yyvsp[-6].crepr), (yyvsp[-2].crepr), (yyvsp[-6].crepr), (yyvsp[0].crepr));}
#line 1900 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 263 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("while (%s){\n\t%s}\n", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1906 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 264 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("do{\n\t%s\n} while( %s );", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1912 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 266 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s: %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 1918 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 268 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("goto %s;", (yyvsp[0].crepr)); }
#line 1924 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 270 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("return result;"); }
#line 1930 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 273 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1936 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 274 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1942 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 275 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 1948 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 277 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("writeString(%s);", (yyvsp[-1].crepr)); }
#line 1954 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 278 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("writeInteger(%s);", (yyvsp[-1].crepr)); }
#line 1960 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 279 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("writeReal(%s);", (yyvsp[-1].crepr)); }
#line 1966 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 280 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s = readString();", (yyvsp[-2].crepr)); }
#line 1972 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 281 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s = readInteger();", (yyvsp[-2].crepr)); }
#line 1978 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 282 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s = readReal();", (yyvsp[-2].crepr)); }
#line 1984 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 284 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s = %s(%s);", (yyvsp[-5].crepr), (yyvsp[-3].crepr), (yyvsp[-1].crepr)); }
#line 1990 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 286 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s(%s);", (yyvsp[-3].crepr), (yyvsp[-1].crepr)); }
#line 1996 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 288 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template(""); }
#line 2002 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 289 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 2008 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 291 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s", (yyvsp[0].crepr)); }
#line 2014 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 292 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s, %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2020 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 294 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "%s", (yyvsp[0].crepr)); }
#line 2026 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 295 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "%s", (yyvsp[0].crepr)); }
#line 2032 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 296 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "%s", (yyvsp[0].crepr)); }
#line 2038 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 297 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "%s", (yyvsp[0].crepr)); }
#line 2044 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 298 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "1"); }
#line 2050 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 299 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "0"); }
#line 2056 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 300 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "%s", (yyvsp[0].crepr)); }
#line 2062 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 301 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "%s", (yyvsp[0].crepr)); }
#line 2068 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 302 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "+%s", (yyvsp[0].crepr)); }
#line 2074 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 303 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "-%s", (yyvsp[0].crepr)); }
#line 2080 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 304 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "(%s)",(yyvsp[-1].crepr)); }
#line 2086 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 305 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("(%s)%s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2092 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 306 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "%s", (yyvsp[0].crepr)); }
#line 2098 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 307 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = (yyvsp[0].crepr); }
#line 2104 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 308 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template( "%s%s", (yyvsp[-1].crepr), (yyvsp[0].crepr)); }
#line 2110 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 311 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s/%s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2116 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 312 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s % %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2122 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 313 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s+%s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2128 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 314 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s-%s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2134 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 316 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s * %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2140 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 317 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s && %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2146 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 318 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s || %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2152 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 319 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("! %s", (yyvsp[0].crepr)); }
#line 2158 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 322 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s > %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2164 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 323 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s >= %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2170 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 324 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s==%s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2176 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 325 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s < %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2182 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 326 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s <= %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2188 "project_parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 327 "project_parser.y" /* yacc.c:1646  */
    { (yyval.crepr) = template("%s != %s", (yyvsp[-2].crepr), (yyvsp[0].crepr)); }
#line 2194 "project_parser.tab.c" /* yacc.c:1646  */
    break;


#line 2198 "project_parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 330 "project_parser.y" /* yacc.c:1906  */



int main()
{
	yyparse();
}
