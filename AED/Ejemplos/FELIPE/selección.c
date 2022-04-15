#include<stdio.h>

typedef struct{
    int valor;
}Generico;
typedef struct{
    Generico DatoG;
}Dato;

void ordenamientoSeleccion(Dato *arreglo, int tam);

int main (void){
    Dato arreglo[4];
    arreglo[0].DatoG.valor = 5;
    arreglo[1].DatoG.valor = 8;
    arreglo[2].DatoG.valor = 2;
    arreglo[3].DatoG.valor = 1;

    puts("Los numeros a ordenar son:");
    for ( int k = 0; k < 4; k++)
    {
        printf("%d ", arreglo[k]);
    }
    puts("\n");
    
    ordenamientoSeleccion(arreglo, 4);

    puts("Los numeros ordenados son:");
    for ( int k = 0; k < 4; k++)
    {
        printf("%d ", arreglo[k]);
    }
    puts("\n");
}

void ordenamientoSeleccion(Dato *arreglo, int tam){
    int i,j;
    Dato pivote;
    for(i=0; i<tam; i++){
        for (j=i+1; j<tam; j++){
            if(arreglo[i].DatoG.valor>arreglo[j].DatoG.valor){
                pivote = arreglo[i];
                arreglo[i].DatoG.valor = arreglo[j].DatoG.valor;
                arreglo[j] = pivote;
            }
        }
    }
}
