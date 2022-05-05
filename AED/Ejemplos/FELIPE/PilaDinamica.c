#include "Piladinamica.h"

Pila* crearPila(int* error){
    Pila* pilaAsignacion=(Pila*) malloc(sizeof(Pila));
    if(pilaAsignacion==NULL){
        perror("No hay memoria para la pila");
        *error=-2;
        return NULL;
    }
    pilaAsignacion->cima=NULL;
    pilaAsignacion->cursor=0;
    *error=0;
    return pilaAsignacion;
}

void consultarCima(Pila p, int* error){
    if(!isEmpty(p,error) && *error==0){
        printf("Valor en la cima: %d\n", p.cima->valor);
    }
    *error=0;
}

//@param p Pila donde se alamcenaran los datos
//@param error variable que gestiona errores
//@param dato Nodo con la información del usuario
void apilar(Pila *p, int* error, struct Nodo dato){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        perror("No hay memoria para almacenar tu información");
        *error=-1;
    }
    nodoUsuario->valor=dato.valor;
    nodoUsuario->nodoAnterior=p->cima;
    p->cima=nodoUsuario;
    p->cursor++;
    *error=0;
}

void desapilar(Pila *p, int* error,struct Nodo *datoExtraido){
    if(!isEmpty(*p,error)){
        struct Nodo* aux=p->cima;
        datoExtraido->valor=aux->valor;
        p->cima=aux->nodoAnterior;//p->cima=p->cima->nodoAnterior
        aux->nodoAnterior=NULL;
        p->cursor--;
        free(aux);
        *error=0;
    } else{
        *error=-3;
    }
}

bool isEmpty(Pila p, int* error){
    if(p.cima==NULL){
        *error=-3;
        return true;
    } else{
        *error=0;
        return false;   
    }
}

void vaciarPila(Pila *p, int* error){
    while(!isEmpty(*p, error)){
        struct Nodo datoExtraido;
        desapilar(p,error,&datoExtraido);
        printf("Valor extraido: %d\n",datoExtraido.valor);
        *error=0;
    }
}

void destruirPila(Pila* p, int* error){
    if(isEmpty(*p,error)){
        puts("Destruyendo pila");
        free(p);
    }
    else{
        puts("No se puede destruir debido a que contiene información");
    }
}