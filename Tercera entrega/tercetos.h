#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "cola.h"

#define INTERMEDIA_TXT "intermedia.txt"
#define ELEMENTOS_TERCETO 20

#define LONG_TERCETO 30 
#define LONG_ID 30

FILE * fpIntermedia;
tCola  colaTercetos;
tStack pilaNroTerceto;
int tercetosCreados=1;
int fueOr=0;

typedef struct
{
    int numTerceto;
    char posUno[ELEMENTOS_TERCETO];
    char posDos[ELEMENTOS_TERCETO];
    char posTres[ELEMENTOS_TERCETO];
}t_Terceto;


int abrirIntermedia();
void escribirTercetosEnIntermedia();
int crearTerceto(char *c1, char*c2 ,char *c3,int nroT);
int apilarNroTerceto(int  nroTerceto);
int desapilarNroTerceto();
void escribirTercetoActualEnAnterior(int tercetoAEscribir,int tercetoBuscado,char * etiqueta);



int abrirIntermedia(){
    fpIntermedia = fopen(INTERMEDIA_TXT,"wt");
    if(!fpIntermedia)
    {
        printf("Error de apertura del archivo de la tabla de simbolos");
        return 0;
    }
    return 1;
}

void escribirTercetosEnIntermedia()
{
    while(!colaVacia(&colaTercetos)){
      
        t_Terceto t;
        sacarDeCola(&colaTercetos,&t,sizeof(t_Terceto));
        fprintf(fpIntermedia,"[%d] ( %s ; %s ; %s ) \n",t.numTerceto,t.posUno,t.posDos,t.posTres);
    }
     fclose(fpIntermedia);
}


int crearTerceto(char *c1, char*c2 ,char *c3,int nroT){
    
    t_Terceto tercetos;
    tercetosCreados++;
    tercetos.numTerceto = nroT;
    strcpy(tercetos.posUno,c1);
    strcpy(tercetos.posDos,c2);
    strcpy(tercetos.posTres,c3);
  
    //printf("%d Se pone en cola %s,%s,%s \n",nroT,tercetos.posUno,tercetos.posDos,tercetos.posTres);
    ponerEnCola(&colaTercetos,&tercetos,sizeof(tercetos));
    return nroT;
}


int apilarNroTerceto(int  nroTerceto)
{
    char nroTercetoString [50];
    sprintf(nroTercetoString,"[%d]",nroTerceto);
    //printf("A ver que apila %d %s \n",nroTerceto,nroTercetoString);
    return pushStack(&pilaNroTerceto,nroTercetoString);
    
}

int desapilarNroTerceto()
{   
    char * nroTerceto;
    popStack(&pilaNroTerceto, nroTerceto);
    printf("A ver que desapilar %s\n",nroTerceto);
    char  subtext [strlen(nroTerceto-2)];
    strncpy(subtext,&nroTerceto[1],strlen(nroTerceto)-1);
    printf("A ver que tiene subtext: %s\n",subtext);
    return atoi(subtext);
}


void escribirTercetoActualEnAnterior(int tercetoAEscribir,int tercetoBuscado,char * etiqueta) //68 59
{
    tCola  aux;
    crearCola(&aux);
    t_Terceto terceto;
    
    while(!colaVacia(&colaTercetos))
    {
        sacarDeCola(&colaTercetos,&terceto,sizeof(terceto));
        if(terceto.numTerceto == tercetoBuscado){
            int flag = 0;
            if(fueOr == 1){
              
               
                    if(strcmp ("BNE",terceto.posUno)==0 && flag != 1) {
                        flag = 1;
                       strcpy(terceto.posUno, "BEQ\0");                          
                    }                        
                    if(strcmp ("BLT",terceto.posUno)==0 && flag != 1) {
                         flag = 1;
                        strcpy(terceto.posUno, "BGE\0");        
                    }
                    if(strcmp ("BLE",terceto.posUno)==0  && flag != 1) {
                      strcpy(terceto.posUno, "BGT\0");        
                     flag = 1;
                    }
                    if(strcmp ("BGT",terceto.posUno)==0  && flag != 1) {
                        strcpy(terceto.posUno, "BLE\0");        
                    flag = 1;
                    }       
                    if(strcmp ("BGE",terceto.posUno)==0  && flag != 1) {
                       strcpy(terceto.posUno, "BLT\0"); 
                    flag = 1;                                  
                    }
                        
                    if(strcmp ("BEQ",terceto.posUno)==0  && flag != 1) {
                        strcpy(terceto.posUno, "BNE\0");
                    flag = 1;                                
                    }

            }

                char nueComponente [LONG_TERCETO];
                sprintf( nueComponente, "%s%d",etiqueta,tercetoAEscribir);

                strcpy(terceto.posTres, nueComponente);
        }
        ponerEnCola(&aux,&terceto,sizeof(terceto));
    }
    
    colaTercetos=aux;
    printf("Entro a escribirTAE3  %d\n",tercetoBuscado);
}

