#include<stdio.h>
#include<stdbool.h>

typedef struct{
    int elemento;
} Nodo;

typedef Nodo TipoGenerico;

void printArray(TipoGenerico *arreglo, int tam){
    for(int i=0; i<tam; i++)
        printf("El valor en la pos %d del arreglo es %d\n",i, arreglo[i]);
}

void merge(TipoGenerico *arregloIzq, TipoGenerico *arregloDer, int tamIzq, int tamDer, TipoGenerico *arregloFinal, int tamArrFinal){
    int i=0,j=0,k=0;
    while(i<tamIzq && j<tamDer){
        if(arregloIzq[i].elemento<arregloDer[j].elemento){
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

void sort(TipoGenerico *arreglo, int tam){
    //Dividir hasta quedar con 1 elemento en el arreglo
    puts("**************************Un nuevo elemento en la pila se va almacenar");
    puts("El arreglo que ingresa es:");
    printArray(arreglo,tam);
    if(tam>1){
        int posMedia=tam/2;
        int i=0,j=0;
        TipoGenerico arregloIzq[posMedia]; 
        TipoGenerico arregloDer[tam-posMedia]; 
        for(i=0; i<posMedia; i++)
            arregloIzq[i]=arreglo[i];
        for(i=posMedia; i<tam; i++){
            arregloDer[j]=arreglo[i];
            j++;
        }
        puts("El arreglo resultante izquierdo es:");
        printArray(arregloIzq,posMedia);
        puts("El arreglo resultante derecho es:");
        printArray(arregloDer,tam-posMedia);
        puts("Termina la unidad de la pila");
        sort(arregloIzq,posMedia);
        sort(arregloDer,tam-posMedia);
        merge(arregloIzq,arregloDer,posMedia,tam-posMedia,arreglo,tam);
        puts("--------------Arreglo mezclado en sección pila -------------------------");
        printArray(arreglo,tam);
    }
}


void inicioOperacion(int argc, char** argv){
    TipoGenerico datos[5]={4,3,5,6,9};
    sort(datos,5);
    puts("Arreglo ordenado:");
    printArray(datos,5);
}

void main(int argc, char** argv){
    inicioOperacion(argc,argv);
}