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
            break;
        case 2:
            imprimirArbol(arbol);
            break;
        case 3:
            cout << "Porfavor ingrese el valor del nodo a eliminar" << endl;
            cin >> valor;
            eliminarNodo(arbol, valor);
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