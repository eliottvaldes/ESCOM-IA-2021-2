#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
    |Variable   | Estado    | Significado
        error       0           Sin errores (todo resultado es exitoso)
        error      -1           Error, COLA vacía
        error      -4           Inexistencia de la COLA, o esta apunta a NULL
        error      -5           Inexistencia de dato en la estructura 
        error      -6           Nodo inicial nulo
*/
typedef struct{
    int valor;
} Dato;
struct Nodo{
    Dato dato;
    struct Nodo* siguiente;
};
//TDA Cola dinámica
typedef struct{
    int cursor;//iterador  -> cantidad de nodos existentes
    struct Nodo* cabecera;
    struct Nodo* final;
}Elemento_de_Cola;
typedef Elemento_de_Cola* Cola;

Cola crearCola(int*);
// Inserta cola por el final
void encolar(Cola*, int*, Dato );
//Eliminar dato por la cabecera
void desencolar(Cola*, int*, Dato *);
// Devuelve un true o un false si la cola contiene o no Nodos:
bool estaVacia(Cola,int *);
// Libera la memoria RAM usada por la cola:
void borraCola(Cola* , int *);
void imprimeCola(Cola , int*);

int main(){
    int error;
    int cantidadDatos;
    Cola p=crearCola(&error);
    struct Nodo dato;
    Dato datoExtraido;
    puts("¿Cuantos valores quieres agregar a la pila?");
    fflush(stdin);
    scanf("%d",&cantidadDatos);
    for(int i=0; i<cantidadDatos; i++){
        puts("Ingresa un valor:");
        fflush(stdin);
        scanf("%d",&dato.dato.valor);
        encolar(&p,&error,dato.dato);
    }
    desencolar(&p,&error,&datoExtraido);
    printf("Dato extraido es : %d\n", datoExtraido.valor);
    imprimeCola(p,&error);
    puts("aver x2");
    imprimeCola(p,&error);
    puts("n ipi");
    borraCola(&p,&error);
    puts("bye");
}



Cola crearCola(int* e){
    Cola cola=(Cola) malloc(sizeof(Elemento_de_Cola));
    if(cola==NULL){
        *e=-4;
        puts("No se logro obtener memoria para una estructura COLA");
    }
    cola->cabecera=NULL;
    cola->final=NULL;
    cola->cursor=0;
    return cola;
}



// Inserta cola por el final
void encolar(Cola* cola, int* e, Dato datoIngreso){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        *e=-6;
        puts("La estructura del nuevo nodo no se creo correctamente, favor de liberar datos de la cola");
    }
    else if(estaVacia(*cola, e)){
        (*nodoUsuario).dato=datoIngreso;
        (*nodoUsuario).siguiente=NULL;
        (*cola)->cabecera=nodoUsuario;
        (*cola)->final=nodoUsuario;
    } else{
        (*nodoUsuario).dato=datoIngreso;
        (*nodoUsuario).siguiente=NULL;
        (*cola)->final->siguiente=nodoUsuario;
        (*cola)->final=nodoUsuario;
    }
    (*cola)->cursor++;
    *e=0;
}

//Eliminar dato por la cabecera
void desencolar(Cola* cola, int* e, Dato *datoExtraido){
    struct Nodo* nodoAuxiliar=NULL;
    if(estaVacia(*cola,e)){
        *e=-1;
        puts("La cola esta vacia, no es posible leer un elemento");
    } else if((*cola)->cursor>1){
        nodoAuxiliar=(*cola)->cabecera;
        (*cola)->cabecera=(*cola)->cabecera->siguiente;
        nodoAuxiliar->siguiente=NULL;

    } else if((*cola)->cursor==1){
        nodoAuxiliar=(*cola)->cabecera;
        (*cola)->cabecera=NULL;
        (*cola)->final=NULL;
    }
    (*cola)->cursor--;
    *datoExtraido=nodoAuxiliar->dato;
    free(nodoAuxiliar);
    *e=0;
}

// Devuelve un true o un false si la cola contiene o no Nodos:
bool estaVacia(Cola cola,int *e){
    if(cola->cabecera==NULL && cola->final==NULL && cola->cursor==0){
        *e=-1;
        return true;
    } else{
        *e=0;
        return false;
    }
}

// Libera la memoria RAM usada por la cola:
void borraCola(Cola* cola, int *e){
    if(!estaVacia(*cola,e)){
        struct Nodo* nodoAuxiliar, *nodoAuxiliarRespaldo;
        nodoAuxiliar=(*cola)->cabecera;
        while(nodoAuxiliar!=NULL){
            nodoAuxiliarRespaldo=nodoAuxiliar->siguiente;
            free(nodoAuxiliar);
            nodoAuxiliar=nodoAuxiliarRespaldo;
        }
        (*cola)->cabecera=NULL;
        (*cola)->final=NULL;
        (*cola)->cursor=0;
        *e=0;
        free(*cola);
    }
}

void imprimeCola(Cola cola , int* e){
    Dato dato;
    while(!estaVacia(cola, e)){
        desencolar(&cola,e,&dato);
        printf(".-Dato extraido es : %d\n", dato.valor);
    }
    *e=0;

}
