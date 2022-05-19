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
    float altura;
    int edad;
    char *nombre;
} Dato;

struct Nodo{
    Dato dato;
    int pos;
    struct Nodo* siguiente;
};

//TDA Cola dinámica
typedef struct{
    // int cursor;//iterador  -> cantidad de nodos existentes
    struct Nodo* cabecera;
    
}Elemento_de_Lista;


typedef Elemento_de_Lista* Lista;

Lista crearLista(int* e);

void agregarPorIzquierda(Lista* lista, int* e, Dato datousuario);
void agregarPorDerecha(Lista* lista, int* e, Dato datousuario);
void extraerPorIzquierda(Lista* lista, int* e,Dato* datoExt);
void extraerPorDerecha(Lista* lista, int* e);
void agregarPosN(Lista* lista, int* e, Dato* datoExtraido, int posUsuario);
void recorrerLista(Lista lista, int* e);
void borrarLista(Lista* lista ,int* e);

// void main(int argc, char const *argv[])
// {
//     int error;
//     int cantidadDatos;
    
//     Lista lista=crearLista(&error);
//     struct Nodo dato;
//     Dato datoIngresado;
//     puts("COLOCANDO NODOS EN LISTA");
//         datoIngresado.valor=12;
//     agregarPorDerecha(&lista,&error,datoIngresado);
//     datoIngresado.valor=75;
//     agregarPorDerecha(&lista,&error,datoIngresado);
//         datoIngresado.valor=18;
//     agregarPorDerecha(&lista,&error,datoIngresado);

//     extraerPorDerecha(&lista,&error);
//      extraerPorDerecha(&lista,&error);
//       extraerPorDerecha(&lista,&error);
//       borrarLista(&lista,&error);
    
// }


Lista crearLista(int* e){
    Lista lista=(Lista) malloc(sizeof(Elemento_de_Lista));
    if(lista==NULL){
        *e=-1;
        perror("No hay memoria para la lista");
        puts("No se logro obtener memoria para una estructura COLA");
    }else{
        lista->cabecera=NULL;
        // lista->cursor=0;

    }
    return lista;

    
}


void agregarPorDerecha(Lista* lista, int* e, Dato datousuario){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* nodoCursor;
    int posicionfinal=0;
    if(nodoUsuario==NULL){
        perror("NO HAY MEMORIA SUFICIENTE");
    }else{
        if((*lista)->cabecera==NULL){
            (*lista)->cabecera=nodoUsuario;
            nodoUsuario->dato= datousuario;
            nodoUsuario->siguiente=NULL;
            nodoUsuario->pos=0;
        }else{
            // (*lista)->cabecera=nodoUsuario;
            nodoUsuario->dato= datousuario;
            nodoUsuario->siguiente=NULL;
            
            nodoCursor=(*lista)->cabecera;
            while(nodoCursor->siguiente!=NULL){
                nodoCursor=nodoCursor->siguiente;
            }
            posicionfinal=nodoCursor->pos;
            nodoCursor->siguiente=nodoUsuario;
            nodoUsuario->pos=posicionfinal;
        }

    }

}
void agregarPorIzquierda(Lista* lista, int* e, Dato datousuario){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    struct Nodo* nodoCursor;
    int posicionfinal=0;
    if(nodoUsuario==NULL){
        perror("NO HAY MEMORIA SUFICIENTE");
    }else{
        if((*lista)->cabecera==NULL){
            (*lista)->cabecera=nodoUsuario;
            nodoUsuario->dato= datousuario;
            nodoUsuario->siguiente=NULL;
            nodoUsuario->pos=0;
        }else{
            // (*lista)->cabecera=nodoUsuario;
            nodoUsuario->dato= datousuario;
            nodoUsuario->siguiente=(*lista)->cabecera;
            nodoUsuario->pos=0;
            
            nodoCursor=(*lista)->cabecera;
            while(nodoCursor!=NULL){
                nodoCursor=nodoCursor->siguiente;
                nodoCursor->pos++;
            }
            (*lista)->cabecera=nodoUsuario;
        }

    }

}


//C C++ JAVA PROLOG, SQL




// void extraerPorIzquierda(Lista* lista, int* e){
//     struct Nodo* nodoExtraido;
//     struct Nodo* nodoCursor;
//     struct Nodo* nodoAux;
//     if((*lista)->cabecera==NULL){
//         perror("NO HAY NADA EN LA LISTA PARA EXTRAER");
//         *e=-2;
//     }else{
//         nodoExtraido=(*lista)->cabecera;
//         (*lista)->cabecera=nodoExtraido->siguiente;
//         nodoExtraido->siguiente=NULL;
//         nodoAux=(*lista)->cabecera;
//         // free((*l)->cabecera);
//         //AHORA RECORREMOS LAS POSICIONES, DISMINUYENDOLAS
//         while(nodoAux->siguiente!=NULL){
//             nodoAux->pos--;
//             nodoAux=nodoAux->siguiente;
//         }
//         //Disminuimos del utlimo nodo
//         nodoAux->pos--;
//         puts("\nINFORMACION DEL NODO ESTRAIDO:\n ");
//         printf("Info= %d\n, posicion=%d\n\n",nodoExtraido->dato,nodoExtraido->pos);
//         free(nodoExtraido);
//         *e=0;
//     }

// }
void extraerPorIzquierda(Lista *listini, int *e, Dato *datoExtraido)
{
    if ((*listini)->cabecera == NULL)
    {
        perror("Nada que extraer");
        *e = 3;
    }
    else
    {
        *datoExtraido = (*listini)->cabecera->dato;
        (*listini)->cabecera = NULL;
        *e = 0;
    }
}
void extraerPorDerecha(Lista* lista, int* e){
    struct Nodo* nodoAux;
        struct Nodo* nodoExtraido;
        struct Nodo* nodoCursor=(*lista)->cabecera;
    if((*lista)->cabecera==NULL){
        perror("NO HAY NADA EN LA LISTA PARA EXTRAER");
        *e=-2;
    }else if(nodoCursor->siguiente!=NULL){

        nodoCursor=(*lista)->cabecera;
        //recorremos la cabecera poniendonos antes del final
        while(nodoCursor->siguiente->siguiente!=NULL){
            nodoCursor=nodoCursor->siguiente;
        }
        nodoExtraido=nodoCursor->siguiente;
        nodoCursor->siguiente=NULL;
        
        //AHORA RECORREMOS LAS POSICIONES, DISMINUYENDOLAS

        puts("\nINFORMACION DEL NODO EXTRAIDO:\n ");
        printf("Info= %d\n, \n",nodoExtraido->dato);
        free(nodoExtraido);
        *e=0;
    }else{
        nodoExtraido=(*lista)->cabecera;
        (*lista)->cabecera=NULL;
        puts("\nINFORMACION DEL NODO EXTRAIDO:\n ");
        printf("Info= %d\n\n",nodoExtraido->dato);
        free(nodoExtraido);
        *e=0;

    }
}

//USA NODO AUX EN LUGAR DE LA CABECERA




void recorrerLista(Lista lista, int* e){
    struct Nodo* nodoAux;
    struct Nodo* nodoExtraido;
    struct Nodo* nodoCursor=(lista)->cabecera;
    if((lista)->cabecera=NULL){
        puts("Lista vacia");
        *e=3;
    }else{
        puts("La lista contiene elementos");
        while(nodoCursor!=NULL){
            printf("\n Dato %d\n",nodoCursor->dato.valor);
            nodoCursor=nodoCursor->siguiente;

        }
        *e=0;
    }

}




void borrarLista(Lista* lista ,int* e){
    struct Nodo* nodoElimina=(*lista)->cabecera;
    struct Nodo* nodoSiguiente=(*lista)->cabecera;
    while(nodoSiguiente!=NULL){
        nodoElimina=nodoSiguiente;
        nodoSiguiente=nodoSiguiente->siguiente;
        free(nodoElimina);

    }

    (*lista)=NULL;

}
void agregarPosN(Lista* lista, int* e, Dato* datoExtraido, int posUsuario){

    struct Nodo* nodoCursor;

    struct Nodo* nodoAux;

    struct Nodo* nodoExtraido;
    int posicionFinal;

    if((*lista)->cabecera==NULL){
        puts("NO hay nada en lista");
    }else{

        nodoCursor=(*lista)->cabecera;
        while(nodoCursor->siguiente!=NULL){
            nodoCursor=nodoCursor->siguiente;
        }

        posicionFinal=nodoCursor->pos;
        //Posiciones desde 1 en la lista
        if (posUsuario>posicionFinal)
        {
            perror("La posicion no esta en la lista aun");

            //posicionFinal>=posUsuario
        }else{
            //REGREGRESAMOS LA INICIO y nos ubicamos en el nodo donde se mete
            nodoCursor=(*lista)->cabecera;
            nodoAux=(*lista)->cabecera;
            nodoExtraido=(*lista)->cabecera;

            while(nodoCursor->pos!=posUsuario-1){
                nodoCursor=nodoCursor->siguiente;
            }
          while(nodoAux->pos!=posUsuario+1){
                nodoAux=nodoAux->siguiente;
            }
            while(nodoExtraido->pos!=posUsuario){
                nodoExtraido=nodoExtraido->siguiente;
            }
            datoExtraido->valor=nodoExtraido->dato.valor;

            free(nodoExtraido);
            //recoreer
            while(nodoAux!=NULL){
                nodoAux->pos--;
                nodoAux=nodoAux->siguiente;
            }
            //Aumentando del ultimo nod
        
            //AQUI EL FINAL ES POSICION USUARIO
            //AHORA VOLVER A LA CAB

            }
        *e=0;

    }



}
