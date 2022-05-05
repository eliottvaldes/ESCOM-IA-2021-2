#include "Piladinamica.h"


int main(int argc, char** argv){
    int error;
    int cantidadDatos;
    Pila *p=crearPila(&error);
    struct Nodo dato;
    puts("¿Cuantos valores quieres agregar a la pila?");
    fflush(stdin);
    scanf("%d",&cantidadDatos);
    for(int i=0; i<cantidadDatos; i++){
        puts("Ingresa un valor:");
        fflush(stdin);
        scanf("%d",&dato.valor);
        apilar(p,&error,dato);
    }
    consultarCima(*p,&error);
    vaciarPila(p,&error);
    return error;
}