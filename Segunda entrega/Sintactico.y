%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
#include "lista.h"
#include "tercetos.h"

int yystopparser=0;
FILE  *yyin;

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
        salidaInd=0,
        entradaInd=0,
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
        |programa sentencia {sentInd=prgInd;};

sentencia:  	   
	asignacion 
        |declaracion
        |read       
        |write       
        |ciclo      
        |if ;

asignacion: 
          ID {asignacionInd = crearTerceto(yytext,"_","_",tercetosCreados);} OP_AS expresion {
                                                           
                                                            char auxAsig[LONG_TERCETO];
                                                            char auxInd[LONG_TERCETO];
                                                            sprintf(auxInd,"[%d]",expInd );
                                                            sprintf(auxAsig,"[%d]",asignacionInd);
                                                            asignacionInd = crearTerceto("OP_ASIG",auxAsig,auxInd,tercetosCreados);
                                                        };
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
          lista_id COMA ID {crearTerceto(yytext,"_","_",tercetosCreados);pushStack(&stackVar,$3);}
          |ID {crearTerceto(yytext,"_","_",tercetosCreados);pushStack(&stackVar,$1);};

tipo: 
      INT       {pushStack(&stackDataTypeDecVar,"INTEGER");}
      |FLOAT    {pushStack(&stackDataTypeDecVar,"FLOAT");}	
      |STRING   {pushStack(&stackDataTypeDecVar,"STRING");};

read:
          READ PA ID PC; 

write:
          WRITE PA ID PC 
          |WRITE PA CONST_STRING PC; 

ciclo: 
        CICLO {cicloInd = crearTerceto("InicioCiclo","_","_",tercetosCreados);
                            apilarNroTerceto(cicloInd);} 
        PA condicion PC LA programa LC {
                                                int t = desapilarNroTerceto();
                                                char auxT [LONG_TERCETO]; 
                                                escribirTercetoActualEnAnterior(tercetosCreados+1,t);
                                                t = desapilarNroTerceto(); 
                                                sprintf(auxT,"[%d]",t);
                                                crearTerceto("BI","_",auxT,tercetosCreados);
        };

if:
        IF PA condicion PC LA programa LC {     while(!emptyStack(&pilaComparacion)){
                                                        char  t [30];
                                                        popStack(&pilaComparacion,t);
                                                        printf("A ver que numero trae el desapilar %s\n", t);
                                                        escribirTercetoActualEnAnterior(tercetosCreados,atoi(t));
                                                 }

                                                
                                                }

        |IF PA condicion PC LA programa LC ELSE LA programa LC {
                                                        while(!emptyStack(&pilaComparacion)){
                                                        char  t [30];
                                                        popStack(&pilaComparacion,t);
                                                        printf("A ver que numero trae el desapilar %s\n", t);
                                                        escribirTercetoActualEnAnterior(tercetosCreados,atoi(t));
                                                 }};

condicion:
        comparacion {condicionInd = comparacionInd;}
        |condicion AND comparacion{
                                                        char condicionAux [LONG_TERCETO];
                                                        char comparacionAux [LONG_TERCETO];
                                                        sprintf(condicionAux,"[%d]",condicionInd );
                                                        sprintf(comparacionAux, "[%d]", comparacionInd);
                                                        condicionInd = crearTerceto("AND", condicionAux , comparacionAux,tercetosCreados );
                                                       
                                                        }
        |condicion OR comparacion {
                                                        char condicionAux [LONG_TERCETO];
                                                        char comparacionAux [LONG_TERCETO];
                                                        sprintf(condicionAux,"[%d]",condicionInd);
                                                        sprintf(comparacionAux, "[%d]", comparacionInd);
                                                        condicionInd = crearTerceto("OR", condicionAux , comparacionAux,tercetosCreados );
                                                            
                                                        };
        |NOT comparacion{
                                                        char comparacionAux [LONG_TERCETO];
                                                        sprintf(comparacionAux, "[%d]", comparacionInd);
                                                        condicionInd = crearTerceto("NOT", comparacionAux,"_",tercetosCreados );
                                                           
                                                        };

comparacion:
        expresion comparador expresion{
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
        };

comparador:
        OP_MEN{strcpy(comparador, "BGE");}
        |OP_MAY{strcpy(comparador, "BLE");}
        |OP_COMP{strcpy(comparador,"BNE" );}
        |OP_MEN_IGU{strcpy(comparador,"BGT");}
        |OP_MAY_IGU{strcpy(comparador, "BLT");};


expresion:
         termino {
                                                        expInd = termInd;
                                                        char expIndString [10];
                                                        itoa(expInd,expIndString,10);
                                                        pushStack(&pilaExp,expIndString);}

	 |expresion OP_SUM termino {                        char auxTer[LONG_TERCETO];
                                                            char auxExp[LONG_TERCETO];
                                                            sprintf(auxTer,"[%d]",termInd);
                                                            sprintf(auxExp,"[%d]",expInd);
                                                            expInd = crearTerceto("OP_SUMA",auxExp,auxTer,tercetosCreados);
                                                            char expIndString [10];
                                                            itoa(expInd,expIndString,10);
                                                            pushStack(&pilaExp,expIndString); }
	 |expresion OP_RES termino {
                                                            char auxTer[LONG_TERCETO];
                                                            char auxExp[LONG_TERCETO];
                                                            sprintf(auxTer,"[%d]",termInd);
                                                            sprintf(auxExp,"[%d]",expInd);
                                                            expInd = crearTerceto("OP_RESTA",auxExp,auxTer,tercetosCreados);
                                                            char expIndString [10];
                                                            itoa(expInd,expIndString,10);
                                                            pushStack(&pilaExp,expIndString);}
	 ;

termino: 
       factor {
                                                            termInd = factInd;
                                                            char termIndString [10];
                                                            itoa(expInd,termIndString,10);
                                                            pushStack(&pilaTerm,termIndString);
                                                          }
       
       |termino OP_MUL factor {                             char auxTer[LONG_TERCETO];
                                                            char auxFac[LONG_TERCETO];
                                                            sprintf(auxTer,"[%d]",termInd);
                                                            sprintf(auxFac,"[%d]",factInd);
                                                            termInd = crearTerceto("OP_MULT",auxTer,auxFac,tercetosCreados);
                                                            char termIndString [10];
                                                            itoa(termInd,termIndString,10);
                                                            pushStack(&pilaTerm,termIndString);}
                                                            
       |termino OP_DIV factor {                             char auxTer[LONG_TERCETO];
                                                            char auxFac[LONG_TERCETO];
                                                            sprintf(auxTer,"[%d]",termInd);
                                                            sprintf(auxFac,"[%d]",factInd);
                                                            termInd = crearTerceto("OP_DIV",auxTer,auxFac,tercetosCreados);
                                                            char termIndString [10];
                                                            itoa(termInd,termIndString,10);
                                                            pushStack(&pilaTerm,termIndString);}
       ;

factor: 
      ID                {factInd = crearTerceto(yytext,"_","_",tercetosCreados);
                        char factIndString [10];
                        itoa(termInd,factIndString,10);
                        pushStack(&pilaFact,factIndString);}
      | CTE             {
                        insertNumber(&symbolTable,$1);
                        factInd = crearTerceto(yytext,"_","_",tercetosCreados);
                        char factIndString [10];
                        itoa(termInd,factIndString,10);
                        pushStack(&pilaFact,factIndString);}

      | CONST_REAL      {
                        insertNumber(&symbolTable,$1);
                        factInd = crearTerceto(yytext,"_","_",tercetosCreados);
                        char factIndString [10];
                        itoa(termInd,factIndString,10);
                        pushStack(&pilaFact,factIndString);}
      | CONST_STRING    {
                        insertString(&symbolTable, $1);
                        factInd = crearTerceto(yytext,"_","_",tercetosCreados);
                        char factIndString [10];
                        itoa(termInd,factIndString,10);
                        pushStack(&pilaFact,factIndString);}
      | PA expresion PC {factInd = expInd;
                        char factIndString [10];
                        itoa(termInd,factIndString,10);
                        pushStack(&pilaFact,factIndString);}
      | fibonacci       {}
     	;

fibonacci: 
      FIB PA CTE PC {printf("Sintactico --> Fibonacci\n");}
      | FIB PA ID PC {printf("Sintactico --> Fibonacci\n");};

%%


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
   
    //Generacion de intermedia
    
    escribirTercetosEnIntermedia();
    deleteTable(&symbolTable);

    printf("\n Generacion de la intermedia finalizado \n\n");
    printf("\n Compilacion exitosaaa \n");
    fclose(fpIntermedia);
    fclose(yyin);
    return 0;
}
int yyerror(void)
{
        printf("Error Sintactico\n");
        exit (1);
}