%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
int yystopparser=0;
FILE  *yyin;

  int yyerror();
  int yylex();


%}

%token CTE
%token ID
%token OP_AS
%token OP_SUM
%token OP_MUL
%token OP_RES
%token OP_DIV
%token PA
%token PC
%token CONST_REAL
%token CONST_STRING
%token LA
%token LC
%token COMILLA
%token COMENTARIO_A
%token COMENTARIO_C
%token COMENTARIO_I
%token CICLO
%token IF
%token ELSE
%token INT
%token FLOAT
%token STRING
%token INIT
%token READ
%token WRITE
%token AND
%token OR
%token NOT
%token OP_MEN
%token OP_MAY
%token OP_COMP
%token OP_MEN_IGU
%token OP_MAY_IGU
%token FIB

%%
programa:
    sentencia;
    |programa sentencia;

sentencia:  	   
	asignacion  {printf(" FIN\n");} ;
    |read       {printf(" FIN\n");} ;
    |write      {printf(" FIN\n");} ;
    |ciclo      {printf(" FIN\n");} ;
    |if         {printf(" FIN\n");} ;

asignacion: 
          ID OP_AS expresion {printf("    ID = Expresion es ASIGNACION\n");}
	  ;


read:
          READ PA ID PC;

write:
          WRITE PA ID PC;
          |WRITE PA CONST_STRING PC;

ciclo: 
        CICLO PA condicion PC LA programa LC ;

if:
        IF PA condicion PC LA programa LC;
        |IF PA condicion PC LA programa LC ELSE LA programa LC;

condicion:
        comparacion;
        |condicion AND comparacion;
        |condicion OR comparacion;

comparacion:
        expresion comparador expresion;

comparador:
        OP_MEN;
        |OP_MAY;
        |OP_COMP;
        |OP_MEN_IGU;
        |OP_MAY_IGU;


expresion:
         termino {printf("    Termino es Expresion\n");}
	 |expresion OP_SUM termino {printf("    Expresion+Termino es Expresion\n");}
	 |expresion OP_RES termino {printf("    Expresion-Termino es Expresion\n");}
	 ;

termino: 
       factor {printf("    Factor es Termino\n");}
       |termino OP_MUL factor {printf("     Termino*Factor es Termino\n");}
       |termino OP_DIV factor {printf("     Termino/Factor es Termino\n");}
       ;

factor: 
      ID                {printf("   ID es Factor \n");}
      | CTE             {printf("   CTE es Factor\n");}
      | CONST_REAL      {printf("   CTE_R es Factor\n");}
      | CONST_STRING    {printf("   CTE_S es Factor\n");}
	  | PA expresion PC {printf(" Expresion entre parentesis es Factor\n");}
     	;
%%


int main(int argc, char *argv[])
{
    if((yyin = fopen(argv[1], "rt"))==NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
       
    }
    else
    { 
        
        yyparse();
        
    }
	fclose(yyin);
        return 0;
}
int yyerror(void)
     {
       printf("Error Sintactico\n");
	 exit (1);
     }