#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo*&, int);
nodo* nuevoNodo(int);

int main(){
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
