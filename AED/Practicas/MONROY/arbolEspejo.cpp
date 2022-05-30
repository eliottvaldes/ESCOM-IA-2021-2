#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo*&, int);
nodo* nuevoNodo(int);
void arbolEspejo(nodo*&, nodo*&);
void imprimirArbol(nodo*);

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
            arbolEspejo(arbol, arbolEspejo);
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
