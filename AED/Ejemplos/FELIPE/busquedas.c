#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define tam 5

//Nivel 2
typedef struct{
    int valor;
    char letra;
}Dato;

//Nivel 3
typedef Dato TipoDatoGenerico;

void imprimirTDA(TipoDatoGenerico info);
void busquedaSec(TipoDatoGenerico *arreglo, Dato elementoBuscado);
void busquedaBin(TipoDatoGenerico *arreglo, Dato elementoBuscado);

void imprimirTDA(TipoDatoGenerico info){
    puts("Datos del TDA:");
    printf("Valor entero: %d\n", info.valor);
    printf("Valor letra: %c\n", info.letra);
}

void busquedaSec(TipoDatoGenerico *arreglo, Dato elementoBuscado){
    int i;
    bool flag=false;
    for(i=0; i<tam-1;i++){
        if(arreglo[i].valor==elementoBuscado.valor){
            //Imprimir posición
            printf("El elemento se encontro en la pos %d\n",i);
            //Imprimir detalles
            imprimirTDA(arreglo[i]);
            //Imprimir si se encontro
           // puts("se encontro al elemento");
            flag=true;
            break;
        }
    }

    if (!flag)
        puts("Elemento no encontrado");
}



TipoDatoGenerico* busquedaSecPos(TipoDatoGenerico *arreglo, Dato elementoBuscado){
    int i;
    bool flag=false;
    for(i=0; i<tam-1;i++){
        if(arreglo[i].valor==elementoBuscado.valor){
            return &arreglo[i];
            break;
        }
    }
    return NULL;
}

void busquedaBin(TipoDatoGenerico *arreglo, Dato elementoBuscado){
    int posIzq=0;
    int posDer=tam-1;
    int mitad=0;
    bool flag=false;
    while (posIzq<=posDer){
        mitad=(posIzq+posDer)/2;
        if(arreglo[mitad].valor==elementoBuscado.valor){
            flag=true;
            break;
        }
        else if(elementoBuscado.valor>arreglo[mitad].valor){
            posIzq=mitad+1;
        }
        else
            posDer=mitad-1;
    }

    if(flag)
        imprimirTDA(arreglo[mitad]);
    else
        puts("Elemento no encontrado");
}

void main(){
    TipoDatoGenerico *arregloOrg=(TipoDatoGenerico*)malloc(sizeof(TipoDatoGenerico)*tam);
    if(arregloOrg==NULL){
        puts("No hay suficiente memoria, se terminara el programa");
        exit(1);
    }

    arregloOrg[0].valor=1;
    arregloOrg[0].letra='a';

    arregloOrg[1].valor=7;
    arregloOrg[1].letra='h';

    arregloOrg[2].valor=10;
    arregloOrg[2].letra='g';

    arregloOrg[3].valor=15;
    arregloOrg[3].letra='m';

    arregloOrg[4].valor=23;
    arregloOrg[4].letra='k';

    Dato elementoBuscar={'m'};
   // busquedaSec(arregloOrg, elementoBuscar);
    busquedaBin(arregloOrg, elementoBuscar);
    free(arregloOrg);
}