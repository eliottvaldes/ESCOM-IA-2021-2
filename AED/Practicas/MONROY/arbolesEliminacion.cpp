#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo*&, int);
nodo* nuevoNodo(int);
void imprimirArbol(nodo*);
void eliminarNodo(nodo*&,int);
void eliminarHoja(nodo*&);
void eliminarNodoConHijo(nodo*&, nodo*&);
void eliminarNodoConDosHijos(nodo*&, nodo*&);

int main (){
    int opcionMenu;
    int valor;
    nodo *arbol = NULL;
    do
    {
        cout << "Que desesa hacer" << endl;
        cout << "1.- Agregar un nodo al arbol" << endl;
        cout << "2.- Imprimir el arbol" << endl;
        cout << "3.- Eliminar un nodo del arbol" << endl;
        cout << "4.- Salir del programa" << endl;
        cin >> opcionMenu;
        switch (opcionMenu){
        case 1:
            cout << "Porfavor ingrese el valor del nodo a agregar" << endl;
            cin >> valor;
            agregarNodo(arbol, valor);
            cout << "Nodo agregado" << endl;
            break;
        case 2:
            imprimirArbol(arbol);
            cout << endl;
            break;
        case 3:
            cout << "Porfavor ingrese el valor del nodo a eliminar" << endl;
            cin >> valor;
            eliminarNodo(arbol, valor);
            cout << "Nodo eliminado" << endl;
            break;
        case 4:
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

void imprimirArbol(nodo *arbol){
    if(arbol==NULL){
        return;
    }
    imprimirArbol(arbol->izquierda);
    cout << arbol->dato << ", ";
    imprimirArbol(arbol->derecha);
}

void eliminarNodo(nodo *&arbol, int valor){
    if(arbol == NULL){
        cout << "El valor no existe en el arbol" << endl;
        return;
    }
    int newValor = arbol->dato;
    if(newValor == valor){
        if(arbol->izquierda == NULL && arbol->derecha == NULL){
            eliminarHoja(arbol);
        }
        return;
    }
    else if(newValor > valor){
        eliminarNodo(arbol->izquierda, valor);
    }
    else{
        eliminarNodo(arbol->derecha, valor);
    }
}

void eliminarHoja(nodo *&arbol){
    delete arbol;
    arbol = NULL;
}