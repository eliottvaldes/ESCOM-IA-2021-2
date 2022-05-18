/*
    Definición de PILA ESTÁTICA 
*/
#include<stdio.h>
#include<stdbool.h>

#define TAM 4
/**
 *              Tabla de errores
 *      Variable    Estado      Significado
 *         error    -1          Elemento Null /Cima Null
 *         error    -2          Pila esta Llena
 *         error    -3          Pila esta vacia
 *         error    0           No hay errores / Todo Ok
 */

typedef struct{
    char val;
}Nodo;

typedef struct{
    Nodo elementos[TAM];
    int cima;
}Pila;

void crearPILA(int* error, Pila *p);
int apilar(Pila *p, int* error, Nodo dato);
void desapilar(Pila *p, int* error, Nodo *datoExtraido);
int consultarCima(Pila p, int* error);
void vaciarPila(Pila *p, int* error);
bool isEmpty(Pila p, int* error);
bool isPilaEmpty(Pila p, int* error);
bool isFull(Pila p, int* error);
bool isParentesis(Nodo dato);


void main(int argc,char** argv ){
    int error,i=0;
    Nodo datoUsuario;
    Pila p;
    crearPILA(&error,&p);
    puts("Recuerda modificar el valor de TAM de la pila");

    while(i<TAM){
        puts("Ingresa los valores:");
        fflush(stdin);
        scanf("%c",&datoUsuario.val);
        apilar(&p,&error,datoUsuario);
        i++;
        printf("valor cima%d\n",p.cima );
    }
    if(isPilaEmpty(p, &error)){
        puts("Verdadero");
    }else{
        puts("Falso");
    }

}




void crearPILA(int* error, Pila *p){  
    p->cima=-1;
    *error=0;
}

int apilar(Pila *p, int* error, Nodo dato){
   Nodo aux;


        if(isParentesis(dato)){

            switch(dato.val){
                case '{':
                    p->cima++;  
                    p->elementos[p->cima]=dato;
                    *error=0;
                    break;
                case '}':
                    desapilar(p,error,&aux);

                    break;

                case '(':
                    p->cima++;  
                    p->elementos[p->cima]=dato;
                    *error=0;

                    break;

                case ')':
                    desapilar(p,error,&aux);

                    break;
                case '[':
                    p->cima++;  
                    p->elementos[p->cima]=dato;
                    *error=0;
                case ']':
                    desapilar(p,error,&aux);

            }

        }else{
            *error=0;
        }
    return 0;
}

void desapilar(Pila *p, int* error, Nodo *datoExtraido){   
    if(!isEmpty(*p,error)){ 
        *datoExtraido=p->elementos[p->cima];
        p->cima--;
        *error=0;
    } else{
        *error=-3;
    }

}


int consultarCima(Pila p, int* error){ 
    if(isEmpty(p,error) && *error==0){
        printf("El valor en la cima es: %d\n",p.elementos[p.cima]); 
    }else{
        puts("No hay elementos en la cima");
        *error=-3;
    }


}

void vaciarPila(Pila *p, int* error){   
    Nodo aux;
    puts("Vaciando Pila");
    while(!isEmpty(*p,error) && *error==0){
        desapilar(p,error,&aux);
        printf("Elemento extraido: %d\n", aux.val);
    }
    *error=0;

}

bool isEmpty(Pila p, int* error){  
    if(p.cima==-1){
        *error=-3;
        return true;
    }else{
        *error=0;
        return false;
    } 
}

bool isPilaEmpty(Pila p, int* error){
    if(p.cima==-1){
        *error=-3;
        return true;
    }else{
        *error=0;
        return false;
    } 
}


bool isFull(Pila p, int* error){   
    if(p.cima==(TAM-1)){
        *error=-2;
        return true;

    }else{
        *error=0;
        return false;
    }
}

bool isParentesis(Nodo dato){
    if(dato.val==')' || dato.val=='(' || dato.val== '[' || dato.val==']'|| dato.val=='{'|| dato.val=='}'){

        return true;
    }else{

        return false;
    } 
}
