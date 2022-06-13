/*
    Monroy Fernández José Luis
    2BV1
    Ingenieria en Inteligencia Artificial
    12/06/2022
*/

#include <iostream>
#include <stack>

using namespace std;

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo*&, int);
nodo* nuevoNodo(int);
void impresionZigZag(nodo*, int);

int main(){
    int contador = 1;
    nodo *arbol = NULL;
    agregarNodo(arbol, 49);
    agregarNodo(arbol, 37);
    agregarNodo(arbol, 41);
    agregarNodo(arbol, 13);
    agregarNodo(arbol, 19);
    agregarNodo(arbol, 25);
    agregarNodo(arbol, 7);
    agregarNodo(arbol, 89);
    agregarNodo(arbol, 53);
    agregarNodo(arbol, 71);
    agregarNodo(arbol, 82);
    agregarNodo(arbol, 60);
    impresionZigZag(arbol, contador);
    return 0;
}

nodo* nuevoNodo(int valor){
    nodo *Nuevo = new nodo;
    Nuevo->dato = valor;
    Nuevo->derecha = NULL;
    Nuevo->izquierda = NULL;
    return Nuevo;
}

void agregarNodo(nodo *&arbol, int valor){
    if(arbol == NULL){
        nodo* Nuevo = nuevoNodo(valor);
        arbol = Nuevo;
        return;
    }
    int newValor = arbol->dato;
    if(newValor == valor){
        cout << "El valor ya existe en el arbol" << endl;
        return;
    }
    if(newValor > valor){
        agregarNodo(arbol->izquierda, valor);
    }
    else{
        agregarNodo(arbol->derecha, valor);
    }
}

void impresionZigZag(nodo *arbol, int contador){
    if(arbol == NULL){
        return;
    }
    stack<nodo*> nivelActual;
    stack<nodo*> nivelSiguiente;
    stack<nodo*> auxiliar;
    nivelActual.push(arbol);
    while(!nivelActual.empty()){
        nodo* temp = nivelActual.top();
        nivelActual.pop();
        if(temp != NULL){
            cout << temp->dato << ", ";
            if(contador % 2 == 0){
                nivelSiguiente.push(temp->izquierda);
                nivelSiguiente.push(temp->derecha);
                while(!nivelSiguiente.empty()){
                    auxiliar.push(nivelSiguiente.top());
                    nivelSiguiente.pop();
                }
                while(!auxiliar.empty()){
                    nivelSiguiente.push(auxiliar.top());
                    auxiliar.pop();
                }
            }
            else{
                nivelSiguiente.push(temp->derecha);
                nivelSiguiente.push(temp->izquierda);
            }
        }
        if(nivelActual.empty()){
            contador++;
            auxiliar = nivelActual;
            nivelActual = nivelSiguiente;
            nivelSiguiente = auxiliar;
        }
    }
}

//In order to see my work check the commit history of this file in the github repository
