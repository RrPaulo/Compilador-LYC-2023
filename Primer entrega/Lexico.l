%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "y.tab.h"

#define MAX_NUM_16_BITS 65536
#define MAX_CHARACTERS  40
#define MAX_NUM_16_BITS INT_MAX

FILE  *yyin;
int yylval;
char *yyltext;

int yyerror(void);

%}

%option noyywrap  
%option yylineno 

DIGITO			[0-9]
LETRA			[a-zA-Z]
CTE		        {DIGITO}+
CONST_REAL      {DIGITO}+"."{DIGITO}+|{DIGITO}+"."|"."{DIGITO}+
CONST_STRING    {COMILLA}{1}(.)*{COMILLA}{1}
ID			    {LETRA}({LETRA}|{DIGITO})*
OP_AS   		":""="
OP_SUM		    "+"
OP_MUL          "*"
OP_RES		    "-"
OP_DIV          "/"
PA			    "("
PC			    ")"
LA              "{"
LC              "}"
COMILLA         ["]
COMENTARIO_A    "*""-"
COMENTARIO_C    "-""*"
COMENTARIO_I    {COMENTARIO_A}(.)*{COMENTARIO_C}
CICLO           "ciclo"|"CICLO"
IF              "IF"|"If"|"if"
ELSE            "else"|"ELSE"|"Else"
ASIGNACION      "="
INT             "Int"|"INT"
FLOAT           "Float"|"FLOAT"
STRING          "String"|"STRING"
INIT            "init"|"INIT"
READ            "read"|"READ"
WRITE           "write"|"WRITE"
AND             "&"
OR              "||"
NOT             "not"|"NOT"

%%

{CTE}			{printf("\nConstante: %s\n", yytext);return CTE;}
{CONST_REAL}    {printf("\nCte real: %s\n", yytext);return CONST_REAL;}
{CONST_STRING}  {printf("\nCte string: %s\n", yytext);return CONST_STRING;}
{ID}			{printf("\nIdentificador: %s\n", yytext);return ID;}
{OP_SUM}		{printf("\nSuma: %s\n", yytext);return OP_SUM;}
{OP_AS}			{printf("\nAsignacion: %s\n", yytext);return OP_AS;}
{OP_MUL}		{printf("\nMultiplicacion: %s\n", yytext);return OP_MUL;}
{OP_RES}		{printf("\nResta: %s\n", yytext);return OP_RES;}
{OP_DIV}		{printf("\nDivision: %s\n", yytext);return OP_DIV;}
{PA}			{printf("\nParAbre: %s\n", yytext);return PA;}
{PC}			{printf("\nParCierra: %s\n", yytext);return PC;}
{LA}			{printf("\nLlave apertura: %s\n", yytext);return LA;}
{LC}			{printf("\nLlave cierre: %s\n", yytext);return LC;}
{CICLO}         {printf("\nCiclo: %s\n", yytext);return CICLO;}
{IF}            {printf("\nIF: %s\n", yytext);return IF;}
{ELSE}          {printf("\nElse: %s\n", yytext);return ELSE;}
{ASIGNACION}    {printf("\nAsignacion: %s\n", yytext);return ASIGNACION;}
{INT}           {printf("\nINT: %s\n", yytext);
                                int value = atoi(strdup(yytext));
                                if( value > MAX_NUM_16_BITS ) {
                                    printf("\nNUMERO SUPERA EL MAXIMO PERMITIDO");
                                } else {
                                     yylval.strVal = strdup(yytext);
                                    return INT;
                                }}

{FLOAT}         {printf("\nFloat: %s\n", yytext);
                                int value = atoi(strdup(yytext));
                                if( value > MAX_NUM_32_BITS ) {
                                    printf("\nNUMERO SUPERA EL MAXIMO PERMITIDO")
                                } else {
                                     yylval.strVal = strdup(yytext);
                                    return FLOAT;
                                }}

{STRING}        {printf("\nString: %s\n", yytext);
                                if(strlen(yytext) > MAX_CHARACTERS){
                                   printf("\nSTRING SUPERA EL MAXIMO PERMITIDO")
                                } else {
                                   yylval.strVal = strdup(yytext);
                                    return STRING;
                                }}

{INIT}          {printf("\nInit: %s\n", yytext);return INIT;}
{READ}          {printf("\nRead: %s\n", yytext);return READ;}
{WRITE}         {printf("\nWrite: %s\n", yytext);return WRITE;}
{AND}           {printf("\nAND: %s\n", yytext);return AND;}
{OR}            {printf("\nAND: %s\n", yytext);return OR;}
{NOT}           {printf("\nAND: %s\n", yytext);return NOT;}
"\n"      		
"\t"
"\n\t"
" "             		
"\r\n"
{COMILLA}       {printf("\nComilla: %s\n", yytext);return COMILLA;}
{COMENTARIO_A}  {;}
{COMENTARIO_C}  {;}
{COMENTARIO_I}  {;}
.			    { printf( "ERROR LEXICO : Caracter no reconocido: %s\n", yytext ); exit (0);}

%%