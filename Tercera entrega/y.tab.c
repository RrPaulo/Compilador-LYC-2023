
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "Sintactico.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "lista.h"
#include "tercetos.h"

int yystopparser=0;
FILE  *yyin;
FILE  *fpTabla;
FILE  *fpAss;

//Para la tabla de simbolos
tList symbolTable;
tStack stackDataTypeDecVar;
tStack invertStackDataType;
tStack stackVar;

//Para la intermedia 
///indices
int     sentInd=0,
        prgInd=0,
        declaracionInd=0,
        asignacionInd=0,
        selecInd=0,
        cicloInd=0,
        longInd=0,
        readInd=0,
        writeInd=0,
        expInd=0,
        factInd=0,
        termInd=0,
        listTipoDatoInd=0,
        decInd=0,
        listavarInd=0,
        condicionInd=0,
        comparacionInd=0,
        comparadorInd=0,
        listaInd=0,
        tipoDatoInd=0;

tStack pilaNroTerceto;
tStack pilaExp;
tStack pilaTerm;
tStack pilaFact;
tStack pilaComparacion;

tCola  colaTercetos;

int contList;
char comparador[4];

int yyerror();
int yylex();
extern char* yytext;
extern int yylineno;
void generarAssembler();



/* Line 189 of yacc.c  */
#line 135 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CTE = 258,
     ID = 259,
     OP_AS = 260,
     OP_SUM = 261,
     OP_MUL = 262,
     OP_RES = 263,
     OP_DIV = 264,
     PA = 265,
     PC = 266,
     CONST_REAL = 267,
     CONST_STRING = 268,
     LA = 269,
     LC = 270,
     COMILLA = 271,
     DOS_PUNTOS = 272,
     COMA = 273,
     COMENTARIO_A = 274,
     COMENTARIO_C = 275,
     COMENTARIO_I = 276,
     CICLO = 277,
     IF = 278,
     ELSE = 279,
     INT = 280,
     FLOAT = 281,
     STRING = 282,
     INIT = 283,
     READ = 284,
     WRITE = 285,
     AND = 286,
     OR = 287,
     NOT = 288,
     OP_MEN = 289,
     OP_MAY = 290,
     OP_COMP = 291,
     OP_MEN_IGU = 292,
     OP_MAY_IGU = 293,
     FIB = 294
   };
#endif
/* Tokens.  */
#define CTE 258
#define ID 259
#define OP_AS 260
#define OP_SUM 261
#define OP_MUL 262
#define OP_RES 263
#define OP_DIV 264
#define PA 265
#define PC 266
#define CONST_REAL 267
#define CONST_STRING 268
#define LA 269
#define LC 270
#define COMILLA 271
#define DOS_PUNTOS 272
#define COMA 273
#define COMENTARIO_A 274
#define COMENTARIO_C 275
#define COMENTARIO_I 276
#define CICLO 277
#define IF 278
#define ELSE 279
#define INT 280
#define FLOAT 281
#define STRING 282
#define INIT 283
#define READ 284
#define WRITE 285
#define AND 286
#define OR 287
#define NOT 288
#define OP_MEN 289
#define OP_MAY 290
#define OP_COMP 291
#define OP_MEN_IGU 292
#define OP_MAY_IGU 293
#define FIB 294




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 61 "Sintactico.y"

    char* strVal;



/* Line 214 of yacc.c  */
#line 255 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 267 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNRULES -- Number of states.  */
#define YYNSTATES  101

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    23,    28,    33,    38,    42,    46,    48,    50,
      52,    54,    59,    64,    69,    70,    79,    87,    99,   101,
     103,   107,   111,   114,   118,   120,   122,   124,   126,   128,
     130,   134,   138,   140,   144,   148,   150,   152,   154,   156,
     160,   162,   167
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    44,    -1,    43,    44,    -1,
      45,    -1,    47,    -1,    51,    -1,    52,    -1,    53,    -1,
      55,    -1,    -1,     4,    46,     5,    60,    -1,    28,    14,
      48,    15,    -1,    48,    49,    17,    50,    -1,    49,    17,
      50,    -1,    49,    18,     4,    -1,     4,    -1,    25,    -1,
      26,    -1,    27,    -1,    29,    10,     4,    11,    -1,    30,
      10,     4,    11,    -1,    30,    10,    13,    11,    -1,    -1,
      22,    54,    10,    57,    11,    14,    43,    15,    -1,    23,
      10,    57,    11,    14,    43,    15,    -1,    23,    10,    57,
      11,    14,    43,    56,    24,    14,    43,    15,    -1,    15,
      -1,    58,    -1,    57,    31,    58,    -1,    57,    32,    58,
      -1,    33,    58,    -1,    60,    59,    60,    -1,    34,    -1,
      35,    -1,    36,    -1,    37,    -1,    38,    -1,    61,    -1,
      60,     6,    61,    -1,    60,     8,    61,    -1,    62,    -1,
      61,     7,    62,    -1,    61,     9,    62,    -1,     4,    -1,
       3,    -1,    12,    -1,    13,    -1,    10,    60,    11,    -1,
      63,    -1,    39,    10,     3,    11,    -1,    39,    10,     4,
      11,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   110,   111,   114,   115,   116,   117,   118,
     119,   122,   122,   133,   149,   150,   153,   154,   157,   158,
     159,   162,   165,   166,   169,   169,   181,   191,   199,   215,
     216,   224,   232,   240,   258,   259,   260,   261,   262,   266,
     272,   280,   292,   299,   308,   319,   323,   330,   336,   342,
     346,   350,   351
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CTE", "ID", "OP_AS", "OP_SUM", "OP_MUL",
  "OP_RES", "OP_DIV", "PA", "PC", "CONST_REAL", "CONST_STRING", "LA", "LC",
  "COMILLA", "DOS_PUNTOS", "COMA", "COMENTARIO_A", "COMENTARIO_C",
  "COMENTARIO_I", "CICLO", "IF", "ELSE", "INT", "FLOAT", "STRING", "INIT",
  "READ", "WRITE", "AND", "OR", "NOT", "OP_MEN", "OP_MAY", "OP_COMP",
  "OP_MEN_IGU", "OP_MAY_IGU", "FIB", ".", "$accept", "start", "programa",
  "sentencia", "asignacion", "$@1", "declaracion", "lista_declaracion",
  "lista_id", "tipo", "read", "write", "ciclo", "$@2", "if", "FT",
  "condicion", "comparacion", "comparador", "expresion", "termino",
  "factor", "fibonacci", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    46,    45,    47,    48,    48,    49,    49,    50,    50,
      50,    51,    52,    52,    54,    53,    55,    55,    56,    57,
      57,    57,    57,    58,    59,    59,    59,    59,    59,    60,
      60,    60,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     0,     4,     4,     4,     3,     3,     1,     1,     1,
       1,     4,     4,     4,     0,     8,     7,    11,     1,     1,
       3,     3,     2,     3,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     1,     1,     1,     1,     3,
       1,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    11,    24,     0,     0,     0,     0,     0,     2,     3,
       5,     6,     7,     8,     9,    10,     0,     0,     0,     0,
       0,     0,     1,     4,     0,     0,    46,    45,     0,    47,
      48,     0,     0,     0,    29,     0,    39,    42,    50,    17,
       0,     0,     0,     0,     0,    12,     0,     0,    32,     0,
       0,     0,     0,     0,     0,    34,    35,    36,    37,    38,
       0,     0,     0,    13,     0,     0,     0,    21,    22,    23,
       0,    49,     0,     0,     0,    30,    31,    40,    41,    33,
      43,    44,     0,    18,    19,    20,    15,    16,     0,    51,
      52,     0,    14,     0,    26,     0,    25,     0,     0,     0,
      27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    16,    11,    40,    41,    86,
      12,    13,    14,    17,    15,    95,    33,    34,    60,    35,
      36,    37,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -35
static const yytype_int8 yypact[] =
{
      48,   -35,   -35,     7,    12,    19,    39,    55,    48,   -35,
     -35,   -35,   -35,   -35,   -35,   -35,    54,    65,    -2,    76,
      78,     9,   -35,   -35,     2,    -2,   -35,   -35,     2,   -35,
     -35,     2,    90,    -7,   -35,    10,    14,   -35,   -35,   -35,
      15,    45,    91,    92,    93,    30,    58,    73,   -35,    70,
      51,     2,     2,     2,     2,   -35,   -35,   -35,   -35,   -35,
       2,     2,     2,   -35,    77,    61,    97,   -35,   -35,   -35,
      94,   -35,    95,    96,    48,   -35,   -35,    14,    14,    30,
     -35,   -35,    61,   -35,   -35,   -35,   -35,   -35,    48,   -35,
     -35,     5,   -35,    28,    81,    85,   -35,    98,    48,    38,
     -35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -35,   -35,   -34,    -8,   -35,   -35,   -35,   -35,    71,    31,
     -35,   -35,   -35,   -35,   -35,   -35,    89,    41,   -35,   -21,
      43,    37,   -35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -29
static const yytype_int8 yytable[] =
{
      23,    26,    27,    45,    50,    26,    27,    47,    28,     1,
      29,    30,    28,    43,    29,    30,    53,    18,    54,    39,
      94,    61,    44,    62,    51,    52,    19,     2,     3,    20,
      63,    31,     1,     4,     5,     6,    53,    32,    54,    79,
      91,    32,     1,    96,    55,    56,    57,    58,    59,    21,
       2,     3,     1,   100,    93,    22,     4,     5,     6,    24,
       2,     3,    65,    66,    99,    74,     4,     5,     6,    70,
       2,     3,    48,    72,    73,    25,     4,     5,     6,    53,
      39,    54,    42,    23,    71,    23,    83,    84,    85,    51,
      52,    23,    75,    76,    82,    66,    77,    78,    80,    81,
      49,    87,    67,    68,    69,   -28,    89,    90,    88,    97,
       0,    64,    98,    92,    46
};

static const yytype_int8 yycheck[] =
{
       8,     3,     4,    24,    11,     3,     4,    28,    10,     4,
      12,    13,    10,     4,    12,    13,     6,    10,     8,     4,
      15,     7,    13,     9,    31,    32,    14,    22,    23,    10,
      15,    33,     4,    28,    29,    30,     6,    39,     8,    60,
      74,    39,     4,    15,    34,    35,    36,    37,    38,    10,
      22,    23,     4,    15,    88,     0,    28,    29,    30,     5,
      22,    23,    17,    18,    98,    14,    28,    29,    30,    11,
      22,    23,    31,     3,     4,    10,    28,    29,    30,     6,
       4,     8,     4,    91,    11,    93,    25,    26,    27,    31,
      32,    99,    51,    52,    17,    18,    53,    54,    61,    62,
      10,     4,    11,    11,    11,    24,    11,    11,    14,    24,
      -1,    40,    14,    82,    25
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    22,    23,    28,    29,    30,    42,    43,    44,
      45,    47,    51,    52,    53,    55,    46,    54,    10,    14,
      10,    10,     0,    44,     5,    10,     3,     4,    10,    12,
      13,    33,    39,    57,    58,    60,    61,    62,    63,     4,
      48,    49,     4,     4,    13,    60,    57,    60,    58,    10,
      11,    31,    32,     6,     8,    34,    35,    36,    37,    38,
      59,     7,     9,    15,    49,    17,    18,    11,    11,    11,
      11,    11,     3,     4,    14,    58,    58,    61,    61,    60,
      62,    62,    17,    25,    26,    27,    50,     4,    14,    11,
      11,    43,    50,    43,    15,    56,    15,    24,    14,    43,
      15
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 104 "Sintactico.y"
    {
                escribirTercetosEnIntermedia();
                generarAssembler();
                }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 111 "Sintactico.y"
    {sentInd=prgInd;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 114 "Sintactico.y"
    {sentInd=asignacionInd;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 115 "Sintactico.y"
    {sentInd=decInd ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 116 "Sintactico.y"
    {sentInd=readInd;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 117 "Sintactico.y"
    {sentInd=writeInd;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 118 "Sintactico.y"
    {sentInd= cicloInd;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 119 "Sintactico.y"
    {sentInd= selecInd;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 122 "Sintactico.y"
    {asignacionInd = crearTerceto(yytext,"_","_",tercetosCreados);}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 122 "Sintactico.y"
    {
                                                           
                                                            char auxAsig[LONG_TERCETO];
                                                            char auxInd[LONG_TERCETO];
                                                            sprintf(auxInd,"[%d]",expInd );
                                                            sprintf(auxAsig,"[%d]",asignacionInd);
                                                            asignacionInd = crearTerceto("OP_ASIG",auxAsig,auxInd,tercetosCreados);
                                                        }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 133 "Sintactico.y"
    {
                                                char dataType[100];
                                                char variable[100];
                                                while(!emptyStack(&stackVar))
                                                {
                                                        popStack(&stackVar,variable); 
                                                        if(strcmp(variable,"*") == 0)
                                                        {
                                                                popStack(&stackDataTypeDecVar,dataType);
                                                                popStack(&stackVar,variable); 
                                                        }
                                                        insertVariable(&symbolTable,variable,dataType);
                                                }
                                                }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 149 "Sintactico.y"
    {pushStack(&stackVar,"*");}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 150 "Sintactico.y"
    {pushStack(&stackVar,"*");}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 153 "Sintactico.y"
    {crearTerceto(yytext,"_","_",tercetosCreados);pushStack(&stackVar,(yyvsp[(3) - (3)].strVal));}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 154 "Sintactico.y"
    {crearTerceto(yytext,"_","_",tercetosCreados);pushStack(&stackVar,(yyvsp[(1) - (1)].strVal));}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 157 "Sintactico.y"
    {pushStack(&stackDataTypeDecVar,"INTEGER");}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 158 "Sintactico.y"
    {pushStack(&stackDataTypeDecVar,"FLOAT");}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 159 "Sintactico.y"
    {pushStack(&stackDataTypeDecVar,"STRING");}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 162 "Sintactico.y"
    {readInd= crearTerceto("READ","_","_",tercetosCreados);}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 165 "Sintactico.y"
    {writeInd=crearTerceto("WRITE","_","_",tercetosCreados);}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 166 "Sintactico.y"
    {writeInd=crearTerceto("WRITE","_","_",tercetosCreados);}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 169 "Sintactico.y"
    {cicloInd = crearTerceto("InicioCiclo","_","_",tercetosCreados);
                            apilarNroTerceto(cicloInd);}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 171 "Sintactico.y"
    {
                                                int t = desapilarNroTerceto();
                                                char auxT [LONG_TERCETO]; 
                                                escribirTercetoActualEnAnterior(tercetosCreados+1,t);
                                                 t = desapilarNroTerceto();
                                                sprintf(auxT,"[%d]",t);
                                                crearTerceto("BI","_",auxT,tercetosCreados);
        }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 181 "Sintactico.y"
    {     while(!emptyStack(&pilaComparacion)){
                                                        char  t [30];
                                                        popStack(&pilaComparacion,t);
                                                        printf("FIN de un IF NORMAL %s\n", t);
                                                        escribirTercetoActualEnAnterior(tercetosCreados,atoi(t));
                                                 }

                                                
                                                }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 191 "Sintactico.y"
    {
                                                        while(!emptyStack(&pilaComparacion)){
                                                        char  t [30];
                                                        popStack(&pilaComparacion,t);
                                                        printf("A ver que salida tenemos al FINAL %s\n", t);
                                                        escribirTercetoActualEnAnterior(tercetosCreados,atoi(t));}
                                                        }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 199 "Sintactico.y"
    {                    
                        while(!emptyStack(&pilaComparacion)){
                                char  t [30];
                                popStack(&pilaComparacion,t);
                                printf("Vamos a ver como se comporta en el TRUE %s\n", t);
                                escribirTercetoActualEnAnterior(tercetosCreados+1,atoi(t));}

                        int t = crearTerceto("BI","_","_" ,tercetosCreados);
                        char tString [10];
                        itoa(t,tString,10);
                        printf("A ver el BI %s\n",tString);
                        pushStack(&pilaComparacion,tString);
                                                        }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 215 "Sintactico.y"
    {condicionInd = comparacionInd;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 216 "Sintactico.y"
    {
                                                        char condicionAux [LONG_TERCETO];
                                                        char comparacionAux [LONG_TERCETO];
                                                        sprintf(condicionAux,"[%d]",condicionInd );
                                                        sprintf(comparacionAux, "[%d]", comparacionInd);
                                                        condicionInd = crearTerceto("AND", condicionAux , comparacionAux,tercetosCreados );
                                                       
                                                        }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 224 "Sintactico.y"
    {
                                                        char condicionAux [LONG_TERCETO];
                                                        char comparacionAux [LONG_TERCETO];
                                                        sprintf(condicionAux,"[%d]",condicionInd);
                                                        sprintf(comparacionAux, "[%d]", comparacionInd);
                                                        condicionInd = crearTerceto("OR", condicionAux , comparacionAux,tercetosCreados );
                                                            
                                                        }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 232 "Sintactico.y"
    {
                                                        char comparacionAux [LONG_TERCETO];
                                                        sprintf(comparacionAux, "[%d]", comparacionInd);
                                                        condicionInd = crearTerceto("NOT", comparacionAux,"_",tercetosCreados );
                                                           
                                                        }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 240 "Sintactico.y"
    {
                char exp1[30];
                char exp2[30];
                popStack(&pilaExp,exp1);
                popStack(&pilaExp,exp2);
                printf ("A ver la comparacion %s %s \n",exp1, exp2);
                comparacionInd=crearTerceto("CMP",exp1,exp2,tercetosCreados);
              
                int t = crearTerceto(comparador,"_","_" ,tercetosCreados);
                apilarNroTerceto(t);
                printf("A ver t %d\n",t);
                char tString [10];
                itoa(t,tString,10);
                printf("A ver tSTRING %s\n",tString);
                pushStack(&pilaComparacion,tString);
        }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 258 "Sintactico.y"
    {strcpy(comparador, "BGE");}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 259 "Sintactico.y"
    {strcpy(comparador, "BLE");}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 260 "Sintactico.y"
    {strcpy(comparador,"BNE" );}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 261 "Sintactico.y"
    {strcpy(comparador,"BGT");}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 262 "Sintactico.y"
    {strcpy(comparador, "BLT");}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 266 "Sintactico.y"
    {
                                                        expInd = termInd;
                                                        char expIndString [10];
                                                        itoa(expInd,expIndString,10);
                                                        pushStack(&pilaExp,expIndString);}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 272 "Sintactico.y"
    {                        char auxTer[LONG_TERCETO];
                                                            char auxExp[LONG_TERCETO];
                                                            sprintf(auxTer,"[%d]",termInd);
                                                            sprintf(auxExp,"[%d]",expInd);
                                                            expInd = crearTerceto("OP_SUMA",auxExp,auxTer,tercetosCreados);
                                                            char expIndString [10];
                                                            itoa(expInd,expIndString,10);
                                                            pushStack(&pilaExp,expIndString); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 280 "Sintactico.y"
    {
                                                            char auxTer[LONG_TERCETO];
                                                            char auxExp[LONG_TERCETO];
                                                            sprintf(auxTer,"[%d]",termInd);
                                                            sprintf(auxExp,"[%d]",expInd);
                                                            expInd = crearTerceto("OP_RESTA",auxExp,auxTer,tercetosCreados);
                                                            char expIndString [10];
                                                            itoa(expInd,expIndString,10);
                                                            pushStack(&pilaExp,expIndString);}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 292 "Sintactico.y"
    {
                                                            termInd = factInd;
                                                            char termIndString [10];
                                                            itoa(expInd,termIndString,10);
                                                            pushStack(&pilaTerm,termIndString);
                                                          }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 299 "Sintactico.y"
    {                             char auxTer[LONG_TERCETO];
                                                            char auxFac[LONG_TERCETO];
                                                            sprintf(auxTer,"[%d]",termInd);
                                                            sprintf(auxFac,"[%d]",factInd);
                                                            termInd = crearTerceto("OP_MULT",auxTer,auxFac,tercetosCreados);
                                                            char termIndString [10];
                                                            itoa(termInd,termIndString,10);
                                                            pushStack(&pilaTerm,termIndString);}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 308 "Sintactico.y"
    {                             char auxTer[LONG_TERCETO];
                                                            char auxFac[LONG_TERCETO];
                                                            sprintf(auxTer,"[%d]",termInd);
                                                            sprintf(auxFac,"[%d]",factInd);
                                                            termInd = crearTerceto("OP_DIV",auxTer,auxFac,tercetosCreados);
                                                            char termIndString [10];
                                                            itoa(termInd,termIndString,10);
                                                            pushStack(&pilaTerm,termIndString);}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 319 "Sintactico.y"
    {factInd = crearTerceto(yytext,"_","_",tercetosCreados);
                        char factIndString [10];
                        itoa(termInd,factIndString,10);
                        pushStack(&pilaFact,factIndString);}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 323 "Sintactico.y"
    {
                        insertNumber(&symbolTable,(yyvsp[(1) - (1)].strVal));
                        factInd = crearTerceto(yytext,"_","_",tercetosCreados);
                        char factIndString [10];
                        itoa(termInd,factIndString,10);
                        pushStack(&pilaFact,factIndString);}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 330 "Sintactico.y"
    {
                        insertNumber(&symbolTable,(yyvsp[(1) - (1)].strVal));
                        factInd = crearTerceto(yytext,"_","_",tercetosCreados);
                        char factIndString [10];
                        itoa(termInd,factIndString,10);
                        pushStack(&pilaFact,factIndString);}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 336 "Sintactico.y"
    {
                        insertString(&symbolTable, (yyvsp[(1) - (1)].strVal));
                        factInd = crearTerceto(yytext,"_","_",tercetosCreados);
                        char factIndString [10];
                        itoa(termInd,factIndString,10);
                        pushStack(&pilaFact,factIndString);}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 342 "Sintactico.y"
    {factInd = expInd;
                        char factIndString [10];
                        itoa(termInd,factIndString,10);
                        pushStack(&pilaFact,factIndString);}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 346 "Sintactico.y"
    {}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 350 "Sintactico.y"
    {printf("Sintactico --> Fibonacci\n");}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 351 "Sintactico.y"
    {printf("Sintactico --> Fibonacci\n");}
    break;



/* Line 1455 of yacc.c  */
#line 2053 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 353 "Sintactico.y"



int main(int argc, char *argv[])
{

   //Generacion de tabla de simbolos
    if((yyin = fopen(argv[1], "rt"))==NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);    
    }
    printf("\n Comienzo de la compilacion \n\n");

    createList(&symbolTable);
    createStack(&stackVar);
    createStack(&stackDataTypeDecVar);

    //Para intermedia
    createStack(&pilaNroTerceto);
    createStack(&pilaExp);
    createStack(&pilaTerm);
    createStack(&pilaFact);
    createStack(&pilaComparacion);
    crearCola(&colaTercetos);

    abrirIntermedia();
    yyparse();

    deleteTable(&symbolTable);
    printf("\n Compilacion exitosaaa \n");
   
    fclose(yyin);
    return 0;
}
int yyerror(void)
{
        printf("Error Sintactico\n");
        exit (1);
}

//////////////////////////////////////GENERAR ASSEMBLER///////////////////////////////////////////
void generarAssembler(){
FILE * fpInterm;
char idWhile[200];
int contWhile=0;
fpInterm = fopen("intermedia.txt","rt");
fpTabla = fopen("tabla_de_simbolos.txt","rt");
fpAss = fopen("Assembler_generado.asm","wt");

if(!fpAss || !fpTabla || !fpAss)
    {
        printf("Error en alguna apertura de los archivos, por favor corrabore");
        return;
    }

tStack pAss;
tStack pWhile;
createStack(&pAss);
createStack(&pWhile);

fprintf(fpAss,  "include macros2.asm\n");
fprintf(fpAss,  "include number.asm\n");
fprintf(fpAss, ".MODEL LARGE\n.STACK 200h\n.386\n.DATA\n\n");

//Pegar la tabla de simbolos en el archivo assembler 
char linea[1000];
int lineasignorar = 0;
while(lineasignorar<5)
{
        fgets(linea, sizeof(linea),fpTabla); // Para que se saltee las primeras 5 lineas de la tabla de simbolos
        lineasignorar++;
}

while(fgets(linea, sizeof(linea),fpTabla) && !strstr(linea,"____")){

    char nombre[50];
    char tipo[27];
    char valor[50];
    char longitud[20];   
    printf("Vamos a ver que trajo la LINEA %s \n",linea);
    sscanf(linea, "|%49[^|]|%26[^|]|%49[^|]|%19[^|]|", nombre, tipo, valor, longitud);
    printf("A ver como esta cada columna %s %s %s %s\n",nombre,tipo,valor,longitud);
    printf("valor %c\n",valor[0]);
   
    if(strstr(tipo,"STRING") != NULL){

        if(valor[0] ==' ')
        {
             valor[0] = '?';
            valor[1] = '\0';   
        }
        fprintf(fpAss,"%-20s db\t\t %-30s, \'$\', %s dup (?)\n",nombre,valor,"14");

    }else 
    {
        if( strlen(valor)>1 && valor[0] ==' '){
            valor[0] = '?';
            valor[1] = '\0';
          }
        fprintf(fpAss,"%-20s dd\t\t %-30s\n",nombre,valor);

    }
    
}

fprintf(fpAss,  "\n.CODE");
fprintf(fpAss,  "\nMOV EAX,@DATA");
fprintf(fpAss,  "\nMOV DS,EAX");
fprintf(fpAss,  "\nMOV ES,EAX;\n\n");

while(fgets(linea, sizeof(linea),fpInterm)){
     char p0[200];
     char p1[200];
     char p2[200];
     char p3[200];

    printf("Vamos a ver que trajo la LINEAAAAAAAAAAAAAAAAAAAAAAAAA %s \n",linea);

    sscanf(linea,"%s ( %s ; %s ; %s )",p0,p1,p2,p3);
    strcat(p0,"\0");
      if( strncmp(p1,"etiq",4) != 0  && (p2[0]  == '_')  &&  (p3[0] == '_') ){
         pushStack(&pAss, p1);

     }

    if(strcmp("OP_ASIG",p1) == 0 )
    {
        char st[200];
        popStack(&pAss,st); 
        fprintf(fpAss,"FSTP %s\n",st);     
    }

    if(strcmp("OP_SUMA",p1) == 0 ){
        char st[200];
        popStack(&pAss,st);       
        fprintf(fpAss,"FLD %s\n",st);
        popStack(&pAss,st);       
        fprintf(fpAss,"FLD %s\n",st);
        fprintf(fpAss,"FXCH\n");
        fprintf(fpAss,"FADD\n");
    }

    if(strcmp("OP_RESTA",p1) == 0 ){
        char st[200];
        popStack(&pAss,st);       
        fprintf(fpAss,"FLD %s\n",st);
        popStack(&pAss,st);       
        fprintf(fpAss,"FLD %s\n",st);
        fprintf(fpAss,"FXCH\n");
        fprintf(fpAss,"FSUB\n");
    }

    if(strcmp("OP_DIV",p1) == 0 ){
        char st[200];
        popStack(&pAss,st);       
        fprintf(fpAss,"FLD %s\n",st);
        popStack(&pAss,st);       
        fprintf(fpAss,"FLD %s\n",st);
        fprintf(fpAss,"FXCH\n");
        fprintf(fpAss,"FDIV\n");
    }

       if(strcmp("OP_MULT",p1) == 0 ){
        char st[200];
        popStack(&pAss,st);       
        fprintf(fpAss,"FLD %s\n",st);
        popStack(&pAss,st);       
        fprintf(fpAss,"FLD %s\n",st);
        fprintf(fpAss,"FXCH\n"); 
        fprintf(fpAss,"FMUL\n");
    }

     if(strcmp("CMP",p1) == 0 ){
         char st[200];
        popStack(&pAss,st);
        fprintf(fpAss,"FLD %s\n",st);
        popStack(&pAss,st);       
        fprintf(fpAss,"FLD %s\n",st); 
        fprintf(fpAss,"FXCH\n"); 
        fprintf(fpAss,"FCOM\n");
        fprintf(fpAss,"FSTSW AX\n");
        fprintf(fpAss,"SAHF\n");
        fprintf(fpAss,"FFREE\n");
    }

    if(strcmp("CMPWH",p1) == 0 ){
        int i=0;
        char st[200];
        tStack auxP;
        createStack(&auxP);
        for (i=0 ; i < contWhile ; i++){
            popStack(&pAss,st); 
            fprintf(fpAss,"FLD %s\n",st) ;   
        }
        char etWhile[200];
        pushStack(&pWhile,etWhile);
        fprintf(fpAss,"%s\n",etWhile);
        fprintf(fpAss,"FLD %s\n",idWhile);
        fprintf(fpAss,"FCOMPP\n");  
        fprintf(fpAss,"FSTSW AX\n");
        fprintf(fpAss,"SAHF\n");
        
        }
//Pasaje de los saltos a assembler
   if(strcmp ("BNE",p1)==0) {
        char et[10];
        sscanf(p3,"%[^ ]",et);
        fprintf(fpAss,"JNE %s\n",et);

    }

    if(strcmp ("BLT",p1)==0) {
         char et[10];
        sscanf(p3,"%[^ ]",et);
        fprintf(fpAss,"JB %s\n",et);
    }

    if(strcmp ("BLE",p1)==0) {
        char et[10];
        sscanf(p3,"%[^ ]",et);
        fprintf(fpAss,"JNA %s\n",et);
      
    }

    if(strcmp ("BGT",p1)==0) {
           char et[10];
        sscanf(p3,"%[^ ]",et);
          fprintf(fpAss,"JA %s\n",et);
       
    }

    if(strcmp ("BGE",p1)==0) {
        char et[10];
        sscanf(p3,"%[^ ]",et);
        fprintf(fpAss,"JAE %s\n",et);
      
    }
        
    if(strcmp ("BEQ",p1)==0) {
        char et[10];
        sscanf(p3,"%[^ ]",et);
        fprintf(fpAss,"JE %s\n",et);
   
    }

    if(strcmp("BI", p1) == 0){
        char et[10];
     
        sscanf(p3,"%[^ ]",et);
      
        fprintf(fpAss,"JMP %s\n",et);

    }

}

fprintf(fpAss,  "\nmov ax,4c00h");
fprintf(fpAss,  "\nint 21h");
fprintf(fpAss,  "\nEnd");

///REVISAR
fclose(fpTabla);
fclose(fpAss);

}
