#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo*&, int);
nodo* nuevoNodo(int);
void espejo(nodo*&, nodo*);
void imprimirArbol(nodo*);
void agregarEspejo(nodo*&, int);

int main(){
    int opcionMenu;
    int valor;
    nodo *arbol = NULL;
    nodo *arbolEspejo = NULL;
    do
    {
        cout << "Que desesa hacer" << endl;
        cout << "1.- Agregar un nodo al arbol" << endl;
        cout << "2.- Imprimir el arbol en espejo" << endl;
        cout << "3.- Salir del programa" << endl;
        cin >> opcionMenu;
        switch (opcionMenu){
        case 1:
            cout << "Porfavor ingrese el valor del nodo a agregar" << endl;
            cin >> valor;
            agregarNodo(arbol, valor);
            break;
        case 2:
            espejo(arbolEspejo, arbol);
            imprimirArbol(arbolEspejo);
            cout << endl;
            break;
        case 3:
            cout << "Saliendo del programa" << endl;
            exit(0);
        default:
            cout << "Porfavor seleccione una opcion valida" << endl;
            break;
        }
    } while (opcionMenu != 4);
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

void espejo(nodo*&arEspejo, nodo* arbol){
    if(arbol==NULL){
        return;
    }
    agregarEspejo(arEspejo, arbol->dato);
    espejo(arEspejo, arbol->izquierda);
    espejo(arEspejo, arbol->derecha);
}

void agregarEspejo(nodo *&arbol, int valor){
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
    if(newValor < valor){
        agregarEspejo(arbol->izquierda, valor);
    }
    else{
        agregarEspejo(arbol->derecha, valor);
    }
}

void imprimirArbol(nodo *arbol){
    if(arbol==NULL){
        return;
    }
    cout << arbol->dato << ", ";
    imprimirArbol(arbol->izquierda);
    imprimirArbol(arbol->derecha);
}