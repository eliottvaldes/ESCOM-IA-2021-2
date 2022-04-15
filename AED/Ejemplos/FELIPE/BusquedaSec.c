#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 5

typedef struct{
    int elemento;
    char car;
} Dato;

typedef Dato TipoGenerico;

void imprimeTDA(TipoGenerico info);

void busquedaSecuencial(TipoGenerico *array, Dato elementoBuscado);

void imprimeTDA(TipoGenerico info){
    puts("Imprimiendo detalles del TDA:");
    printf("Atributo 'elemento'=%d\n",info.elemento);
    printf("Atributo 'car'=%c\n",info.car);
}

void busquedaSecuencial(TipoGenerico *array, Dato elementoBuscado){
    int i, j=-1;
    bool flag=false;
    for(i=0; i<tam; i++){
        if(array[i].elemento==elementoBuscado.elemento){
            flag=true;
            j=i;
            break;
        }
    }

    if(flag){
        printf("El elemento se encontro, y esta en la posicion %d\n",j);
        imprimeTDA(array[j]);
    } else{
        puts("El elemento no se encontro");
    }
}

void main(){
    TipoGenerico *arreglo=(TipoGenerico *)malloc(sizeof(TipoGenerico)*tam);
    if(arreglo==NULL){
        puts("No hay memoria suficiente para el arreglo, terminando programa");
        exit(1);
    }
    
    arreglo[0].elemento=34;
    arreglo[0].car='a';
    arreglo[1].elemento=37;
    arreglo[1].car='c';
    arreglo[2].elemento=39;
    arreglo[2].car='d';
    arreglo[3].elemento=39;
    arreglo[3].car='g';
    arreglo[4].elemento=546;
    arreglo[4].car='h';
    Dato elementoBuscado={39};
    

    busquedaSecuencial(arreglo,elementoBuscado);
    puts("Terminando el programa");
    free(arreglo);
}