%{
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
%token DOS_PUNTOS
%token COMA
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
%token COMILLA
%token .
%%
start:
        programa{
                
                };

programa:
        sentencia
        |programa sentencia {sentInd=prgInd;};

sentencia:  	   
	asignacion      {sentInd=asignacionInd;}
        |declaracion    {sentInd=decInd ;}
        |read           {sentInd=readInd;}
        |write          {sentInd=writeInd;}
        |ciclo          {sentInd= cicloInd;}
        |if             {sentInd= selecInd;};

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
          READ PA ID PC {
            char nv[200] ;
            nv[0] = '_';
            nv[1] = '\0';
            strcat(nv,yytext);
            readInd= crearTerceto("READ",nv,"_",tercetosCreados);}; 

write:
          WRITE PA ID  {  int i=0 ;
                             char aux [strlen(yytext)+1];
                            strcpy(aux,yytext);
                            aux[0] = '_';
                            for (i=0; i<= strlen(yytext) ; i++ )
                            {
                                if(aux[i] == ' ')
                                    aux[i]= '_';
                            }
                            aux[i-2]='\0';
                        writeInd=crearTerceto("WRITE",aux,"_",tercetosCreados);}PC
          |WRITE PA CONST_STRING {
                            int i=0 ;
                            char aux [strlen(yytext)+1];
                            strcpy(aux,yytext);
                              printf("A VER QUE TIENE AUX %s\n",aux);
                            aux[0] = '_';
                            for (i=0; i<= strlen(yytext) ; i++ )
                            {
                                if(aux[i] == ' ')
                                    aux[i]= '_';
                            }
                            aux[i-2]='\0';
                            printf("A VER QUE TIENE AUX %s\n",aux);
                            writeInd=crearTerceto("WRITE",aux,"_",tercetosCreados);}PC; 

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
                                                        printf("FIN de un IF NORMAL %s\n", t);
                                                        escribirTercetoActualEnAnterior(tercetosCreados,atoi(t));
                                                 }

                                                
                                                }

        | IF PA condicion PC LA programa FT ELSE LA programa LC {
                                                        while(!emptyStack(&pilaComparacion)){
                                                        char  t [30];
                                                        popStack(&pilaComparacion,t);
                                                        printf("A ver que salida tenemos al FINAL %s\n", t);
                                                        escribirTercetoActualEnAnterior(tercetosCreados,atoi(t));}
                                                        };
FT:
        LC {                    
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
                                                        };


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
      FIB PA CTE  {
            
            char nv[200] ;
            nv[0] = '_';
            nv[1] = '\0';
            strcat(nv,yytext);
            factInd =  crearTerceto("FIB",nv,"_",tercetosCreados);}PC; 
      | FIB PA ID PC {printf("Sintactico --> Fibonacci\n");};

%%


int main(int argc, char *argv[])
{

    if((yyin = fopen(argv[1], "rt"))==NULL)
    {
        printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);    
    }
    printf("\n Comienzo de la compilacion \n\n");
    //Generacion de tabla de simbolos
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
    escribirTercetosEnIntermedia();
    generarAssembler();
    
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

if(!fpAss )
    {
        printf("Error en el archivo de assembler");
        return;
    }
    
if( !fpTabla )
    {
        printf("Error en la apertura de la tabla de simbolos");
        return;
    }
if( !fpInterm)
    {
        printf("Error en la apertura del archivo intermedia");
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
    //printf("Vamos a ver que trajo la LINEA %s \n",linea);
    sscanf(linea, "|%49[^|]|%26[^|]|%49[^|]|%19[^|]|", nombre, tipo, valor, longitud);
    //printf("A ver como esta cada columna %s %s %s %s\n",nombre,tipo,valor,longitud);
  
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

    printf("Linea de intermedia %s \n",linea);

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