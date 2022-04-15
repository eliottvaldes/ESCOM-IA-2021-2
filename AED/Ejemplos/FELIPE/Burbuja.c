#include<stdio.h>

typedef struct{
    int valor;
}Generico;
typedef struct{
    Generico DatoG;
}Dato;

void ordenamientoBurbuja(Dato *arreglo, int tam);

int main (void){
    Dato arreglo[4];
    arreglo[0].DatoG.valor = 7;
    arreglo[1].DatoG.valor = 3;
    arreglo[2].DatoG.valor = 1;
    arreglo[3].DatoG.valor = 4;

    puts("Los numeros a ordenar son:");
    for ( int k = 0; k < 4; k++)
    {
        printf("%d ", arreglo[k]);
    }
    puts("\n");
    
    ordenamientoBurbuja(arreglo, 4);

    puts("Los numeros ordenados son:");
    for ( int k = 0; k < 4; k++)
    {
        printf("%d ", arreglo[k]);
    }
    puts("\n");
}

void ordenamientoBurbuja(Dato *arreglo, int tam){
    int i,j;
    Dato pivote;
    for(i=0; i<tam; i++){
        for(j=0; j<tam-1 ; j++){
            if(arreglo[j].DatoG.valor>arreglo[j+1].DatoG.valor){
                pivote = arreglo[j];
                arreglo[j].DatoG.valor = arreglo[j+1].DatoG.valor;
                arreglo[j+1] = pivote;
            }
        }
    }
}

