%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "y.tab.h"

#define MAX_NUM_16_BITS 65536
#define MAX_CHARACTERS  40
#define LIMIT_FLOAT_INF pow(-1.17549,-38)
#define LIMIT_FLOAT_SUP pow(3.40282,38)

FILE  *yyin;
char *yyltext;

int yyerror(void);

%}

%option noyywrap  
%option yylineno 

DIGITO			[0-9]
LETRA			[a-zA-Z]
CTE		        {DIGITO}+
CARACTER        [a-z|A-Z|0-9|=|OP_MAY|OP_MEN|!|:|+|\-|*|/|@|.|?]
CONST_REAL      {DIGITO}+"."{DIGITO}+|{DIGITO}+"."|"."{DIGITO}+
CONST_STRING    {COMILLA}({CARACTER}+|" ")*{COMILLA}
ID			    {LETRA}({LETRA}|{DIGITO})*
OP_AS   		"="
OP_SUM		    "+"
OP_MUL          "*"
OP_RES		    "-"
OP_DIV          "/"
PA			    "("
PC			    ")"
LA              "{"
LC              "}"
COMILLA         ["]
DOS_PUNTOS      [:]
COMA            [,]
COMENTARIO_A    "*""-"
COMENTARIO_C    "-""*"
COMENTARIO_I    {COMENTARIO_A}({CARACTER}|" ")*{COMENTARIO_C}
CICLO           "ciclo"|"CICLO"
IF              "IF"|"If"|"if"
ELSE            "else"|"ELSE"|"Else"
INT             "Int"|"INT"
FLOAT           "Float"|"FLOAT"
STRING          "String"|"STRING"
INIT            "init"|"INIT"
READ            "read"|"READ"
WRITE           "write"|"WRITE"
AND             "&"
OR              "||"
NOT             "not"|"NOT"
OP_MEN          "<"
OP_MAY          ">"
OP_COMP         "=="
OP_MEN_IGU      {OP_MEN}{OP_AS}
OP_MAY_IGU      {OP_MAY}{OP_AS}
FIB             "FIB"

%%

{INT}			{return INT;}
{FLOAT}         {return FLOAT;}
{STRING}        {return STRING;}
{OP_SUM}		{return OP_SUM;}
{OP_AS}			{return OP_AS;}
{OP_MUL}		{return OP_MUL;}
{OP_RES}		{return OP_RES;}
{OP_DIV}		{return OP_DIV;}
{PA}			{return PA;}
{PC}			{return PC;}
{LA}			{return LA;}
{LC}			{return LC;}
{CICLO}         {return CICLO;}
{IF}            {return IF;}
{ELSE}          {return ELSE;}
{INIT}          {return INIT;}
{READ}          {return READ;}
{WRITE}         {return WRITE;}
{AND}           {return AND;}
{OR}            {return OR;}
{NOT}           {return NOT;}
{DOS_PUNTOS}    {return DOS_PUNTOS;}
{COMA}          {return COMA;}
{COMENTARIO_A}  {;}
{COMENTARIO_I}  {;}
{COMENTARIO_C}  {;}
{OP_MEN}        {return OP_MEN;}
{OP_MAY}        {return OP_MAY;}
{OP_COMP}       {return OP_COMP;}
{OP_MEN_IGU}    {return OP_MEN_IGU;}
{OP_MAY_IGU}    {return OP_MAY_IGU;}
{FIB}           {return FIB;}
{ID}			{yylval.strVal = strdup(yytext);return ID;}
{CTE}           {
                    int value = atoi(strdup(yytext));
                    if( value > MAX_NUM_16_BITS ) {
                        printf("\nLexico --> El entero supera los limites permitidos. \n");
                        exit(1);
                    } else {
                        yylval.strVal = strdup(yytext);
                        return CTE;} }

{CONST_REAL}    { 
                    if (atof(yytext) > LIMIT_FLOAT_SUP || atof(yytext) < LIMIT_FLOAT_INF){
                            printf( "\nLexico --> El real supera los limites permitidos. \n");
                            exit(1);
                    } else{
                        yylval.strVal = strdup(yytext);
                        return CONST_REAL; }}

{CONST_STRING}  {
                    if(strlen(yytext) > MAX_CHARACTERS){
                        printf( "\nLexico --> El string supera los limites permitidos. \n");
                        exit(1);
                    } else {
                        yylval.strVal = strdup(yytext);
                        return CONST_STRING; }}

{COMILLA}       {printf("\nLexico --> Comilla: %s\n", yytext);return COMILLA;}

"\n"      		
"\t"
"\n\t"
" "             		
"\r\n"
.			    { printf( "\nLexico -->ERROR LEXICO : Caracter no reconocido,linea de eror: %s\n", yytext,yylineno ); exit (0);}
%%