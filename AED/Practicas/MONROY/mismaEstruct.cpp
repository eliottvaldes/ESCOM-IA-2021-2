#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo*&, int);
nodo* nuevoNodo(int);
int compararArboles(nodo*, nodo*);

int main(){
    int opcionMenu;
    int valor;
    nodo *arbolA = NULL;
    nodo *arbolB = NULL;
    do
    {
        cout << "Que desesa hacer" << endl;
        cout << "1.- Ingresar nodo al arbol A" << endl;
        cout << "2.- Ingresar nodo al arbol B" << endl;
        cout << "3.- Comparar estrucctura" << endl;
        cout << "4.- Salir del programa" << endl;
        cin >> opcionMenu;
        switch (opcionMenu){
        case 1:
            cout << "Porfavor ingrese el valor del nodo a agregar" << endl;
            cin >> valor;
            agregarNodo(arbolA, valor);
            cout << "Nodo agregado" << endl;
            break;
        case 2:
            cout << "Porfavor ingrese el valor del nodo a agregar" << endl;
            cin >> valor;
            agregarNodo(arbolB, valor);
            cout << "Nodo agregado" << endl;
            break;
        case 3:
            if(compararArboles(arbolA, arbolB)){
                cout << "Los arboles son iguales" << endl;
            } 
            else {
                cout << "Los arboles son diferentes" << endl;
            }
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

int compararArboles(nodo*arbolA, nodo*arbolB){
    if(arbolA == NULL && arbolB == NULL){
        return true;
    }
    else if(arbolA != NULL && arbolB != NULL){
        return (compararArboles(arbolA->izquierda, arbolB->izquierda) && compararArboles(arbolA->derecha, arbolB->derecha));
    }
    return false;
}

//In order to see my work check the commit history of this file in the github repository