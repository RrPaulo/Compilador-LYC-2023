
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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
     DOS_PUNTOS = 271,
     COMA = 272,
     CICLO = 273,
     IF = 274,
     ELSE = 275,
     INT = 276,
     FLOAT = 277,
     STRING = 278,
     INIT = 279,
     READ = 280,
     WRITE = 281,
     AND = 282,
     OR = 283,
     NOT = 284,
     OP_MEN = 285,
     OP_MAY = 286,
     OP_COMP = 287,
     OP_MEN_IGU = 288,
     OP_MAY_IGU = 289,
     FIB = 290,
     COMILLA = 291
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
#define DOS_PUNTOS 271
#define COMA 272
#define CICLO 273
#define IF 274
#define ELSE 275
#define INT 276
#define FLOAT 277
#define STRING 278
#define INIT 279
#define READ 280
#define WRITE 281
#define AND 282
#define OR 283
#define NOT 284
#define OP_MEN 285
#define OP_MAY 286
#define OP_COMP 287
#define OP_MEN_IGU 288
#define OP_MAY_IGU 289
#define FIB 290
#define COMILLA 291




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 61 "Sintactico.y"

    char* strVal;



/* Line 1676 of yacc.c  */
#line 130 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


