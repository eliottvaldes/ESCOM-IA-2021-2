/*
======================================
 ▪* Montero Barraza Alvaro David*
     *2BV1 Ingenieria en IA ▪*  
======================================
 */
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct Nodo{
    char caract;
    Nodo *sig;
}Nodo;

void pila_push(Nodo **inicio,char dato){
    Nodo *n_caract;
    n_caract=new Nodo();
    n_caract->caract=dato;
    n_caract->sig=NULL;
    if (*inicio==NULL)
    {
        *inicio=n_caract;
    }else{
        n_caract->sig=*inicio;
        *inicio=n_caract;
    }

    

}
void pila_pop(Nodo **inicio){
    Nodo *aux;
    Nodo *aux2;
    aux=(*inicio);
    aux2=aux->sig;
    (*inicio)=aux2;
    delete aux;
    
}

bool pila_empty(Nodo *inicio){
    bool retVal;
    if (inicio==nullptr)
    {
        retVal=true;
    }else{
        retVal=false;
    }
    return retVal;
}

int pila_size(Nodo *inicio){
    int cont;
    Nodo *iterador;
    iterador=inicio;
    if(iterador==NULL){
        return 0;
    }else{
        while (iterador->sig!=NULL)
        {
        iterador=iterador->sig;
        cont++;
        }
    }
    
    return cont;
}
