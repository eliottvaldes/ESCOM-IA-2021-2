

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node{
    int valor;  //--> Puede ser otro TDA
    //ALTURA DE LA PERSONA EN CM
    int altura;
    int edad;
    char nombre[20];
    struct Node* NodeAnterior;
};

//Nivel 3
typedef struct{
    struct Node* cima;
    int cursor;
}Pila;





Pila* crearPila(int* error);
void consultarCima(Pila p, int* error);
void apilar(Pila *p, int* error, struct Node dato);//push
void desapilar(Pila *p, int* error,struct Node *datoExtraido,int *alturaExtr,int* edadExtr);
bool isEmpty(Pila p, int* error);
// void vaciarPila(Pila *p, int* error);
// void destruirPila(Pila* p, int* error);

// int main(int argc, char** argv){
//     int error;
//     int cantidadDatos;
//     Pila *p=crearPila(&error);
//     struct Node dato;
//     puts("¿Cuantos valores quieres agregar a la pila?");
//     fflush(stdin);
//     scanf("%d",&cantidadDatos);
//     for(int i=0; i<cantidadDatos; i++){
//         puts("Ingresa un valor:");
//         fflush(stdin);
//         scanf("%d",&dato.valor);
//         apilar(p,&error,dato);
//     }
//     consultarCima(*p,&error);
//     vaciarPila(p,&error);
//     return error;
// }


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
//@param dato Node con la información del usuario
void apilar(Pila *p, int* error, struct Node dato){
    struct Node* NodeUsuario=(struct Node*) malloc(sizeof(struct Node));
    if(NodeUsuario==NULL){
        perror("No hay memoria para almacenar tu información");
        *error=-1;
    }
    // NodeUsuario=&dato;
    // printf("ALTURA AL APILAS: %d\n",dato.altura);
    NodeUsuario->altura=dato.altura;
    NodeUsuario->edad=dato.edad;

    NodeUsuario->NodeAnterior=p->cima;
    p->cima=NodeUsuario;
    p->cursor++;
    *error=0;

}

void desapilar(Pila *p, int* error,struct Node *datoExtraido, int *alturaExtr,int* edadExtr){
    if(!isEmpty(*p,error)){
        struct Node* aux=p->cima;
        datoExtraido=aux;
        // printf("ALTURA AL desapilasr: %d\n",datoExtraido->altura);
        *alturaExtr=datoExtraido->altura;
        // nombreExtr=datoExtraido->nombre;
        *edadExtr=datoExtraido->edad;



        p->cima=aux->NodeAnterior;//p->cima=p->cima->NodeAnterior
        aux->NodeAnterior=NULL;
        p->cursor--;
        free(aux);
        *error=0;
        // printf("ALTURA AL desapilasr: %d\n",alturaExtr);
     
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

// void vaciarPila(Pila *p, int* error){
//     while(!isEmpty(*p, error)){
//         struct Node datoExtraido;
//         desapilar(p,error,&datoExtraido);
//         printf("Valor extraido: %d\n",datoExtraido.valor);
//         *error=0;
//     }
// }

// void destruirPila(Pila* p, int* error){
//     if(isEmpty(*p,error)){
//         puts("Destruyendo pila");
//         free(p);
//     }
//     else{
//         puts("No se puede destruir debido a que contiene información");
//     }
// }