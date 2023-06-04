
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

/* Line 1676 of yacc.c  */
#line 61 "Sintactico.y"

    char* strVal;



/* Line 1676 of yacc.c  */
#line 136 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


