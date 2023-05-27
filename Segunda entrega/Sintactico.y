%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "lista.h"
#include "pila.h"

int yystopparser=0;
FILE  *yyin;

tList symbolTable;
tStack stackDataTypeDecVar;
tStack invertStackDataType;
tStack stackVar;

int yyerror();
int yylex();
extern char* yytext;
extern int yylineno;


%}
%union{
    char* strVal;
}
%token <strVal>CTE
%token <strVal>ID
%token OP_AS
%token OP_SUM
%token OP_MUL
%token OP_RES
%token OP_DIV
%token PA
%token PC
%token <strVal>CONST_REAL
%token <strVal>CONST_STRING
%token LA
%token LC
%token COMILLA
%token DOS_PUNTOS
%token COMA
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
%token .
%%
programa:
        sentencia
        |programa sentencia;

sentencia:  	   
	asignacion 
        |declaracion
        |read       
        |write       
        |ciclo      
        |if ;

asignacion: 
          ID OP_AS expresion {printf("ID = Expresion es ASIGNACION\n");}
	  ;

declaracion: 
                INIT LA lista_declaracion LC    {
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
                                                };

lista_declaracion:  
                    lista_declaracion lista_id DOS_PUNTOS tipo {pushStack(&stackVar,"*");}
                    |lista_id DOS_PUNTOS tipo {pushStack(&stackVar,"*");};

lista_id: 
          lista_id COMA ID {pushStack(&stackVar,$3);}
          |ID {pushStack(&stackVar,$1);};

tipo: 
      INT       {pushStack(&stackDataTypeDecVar,"INTEGER");}
      |FLOAT    {pushStack(&stackDataTypeDecVar,"FLOAT");}	
      |STRING   {pushStack(&stackDataTypeDecVar,"STRING");};

read:
          READ PA ID PC {printf("Sintactico --> READ\n");};

write:
          WRITE PA ID PC {printf("Sintactico --> WRITE\n");}
          |WRITE PA CONST_STRING PC {printf("Sintactico --> WRITE\n");};

ciclo: 
        CICLO PA condicion PC LA programa LC {printf("Sintactico --> CICLO\n");};

if:
        IF PA condicion PC LA programa LC {printf("Sintactico --> IF\n");}
        |IF PA condicion PC LA programa LC ELSE LA programa LC {printf("Sintactico --> IF\n");};

condicion:
        comparacion
        |condicion AND comparacion
        |condicion OR comparacion;
        |NOT comparacion;

comparacion:
        expresion comparador expresion;

comparador:
        OP_MEN
        |OP_MAY
        |OP_COMP
        |OP_MEN_IGU
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
      | CTE             {printf("   CTE es Factor\n");insertNumber(&symbolTable,$1);}
      | CONST_REAL      {printf("   CTE_R es Factor\n");insertNumber(&symbolTable,$1);}
      | CONST_STRING    {printf("   CTE_S es Factor\n"); insertString(&symbolTable, $1);}
      | fibonacci       {printf("   Fibonacci es Factor\n");}
      | PA expresion PC {printf(" Expresion entre parentesis es Factor\n");}
     	;

fibonacci: 
      FIB PA CTE PC {printf("Sintactico --> Fibonacci\n");}
      | FIB PA ID PC {printf("Sintactico --> Fibonacci\n");};

%%


int main(int argc, char *argv[])
{
    if((yyin = fopen(argv[1], "rt"))==NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);    
    }
    printf("\n Comienzo de la compilacion \n\n");

    createList(&symbolTable);
    createStack(&stackVar);
    createStack(&stackDataTypeDecVar);
    createStack(&invertStackDataType);
    
    yyparse();
   
    deleteTable(&symbolTable);
    
    printf("\n Compilacion exitosa \n");
    fclose(yyin);
    return 0;
}
int yyerror(void)
{
        printf("Error Sintactico\n");
        exit (1);
}