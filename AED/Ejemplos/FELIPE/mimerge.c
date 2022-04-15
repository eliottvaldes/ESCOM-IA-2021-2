#include<stdio.h>


typedef struct{
    int valor;
}Generico;
typedef struct{
    Generico DatoG;
}Dato;

void sortmerge(Dato *arreglo, int tam);
void merge(Dato *arregloIzq, Dato *arregloDer, int tamIzq, int tamDer, Dato *arregloFinal, int tamArrFinal);

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
    
    sortmerge(arreglo, 4);

    puts("Los numeros ordenados son:");
    for ( int k = 0; k < 4; k++)
    {
        printf("%d ", arreglo[k]);
    }
    puts("\n");
}



void merge(Dato *arregloIzq, Dato *arregloDer, int tamIzq, int tamDer, Dato *arregloFinal, int tamArrFinal){
    int i=0,j=0,k=0;
    while(i<tamIzq && j<tamDer){
        if(arregloIzq[i].DatoG.valor<arregloDer[j].DatoG.valor){
            arregloFinal[k]=arregloIzq[i];
            i++;
        }
        else{
            arregloFinal[k]=arregloDer[j];
            j++;
        }
        k++;
    }
    while(i<tamIzq){
        arregloFinal[k]=arregloIzq[i];
        i++;
        k++;
    }
    while(j<tamDer){
        arregloFinal[k]=arregloDer[j];
        j++;
        k++;
    }
}

void sortmerge(Dato *arreglo, int tam){
    if(tam>1){
        int posMedia=tam/2;
        int i=0,j=0;
        Dato arregloIzq[posMedia]; 
        Dato arregloDer[tam-posMedia]; 
        for(i=0; i<posMedia; i++)
            arregloIzq[i]=arreglo[i];
        for(i=posMedia; i<tam; i++){
            arregloDer[j]=arreglo[i];
            j++;
        }
        sortmerge(arregloIzq,posMedia);
        sortmerge(arregloDer,tam-posMedia);
        merge(arregloIzq,arregloDer,posMedia,tam-posMedia,arreglo,tam);
    }
}
