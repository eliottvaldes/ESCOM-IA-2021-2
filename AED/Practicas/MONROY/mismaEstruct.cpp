#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo*&, int);
nodo* nuevoNodo(int);
void compararArboles(nodo*, nodo*);

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
            break;
        case 2:
            cout << "Porfavor ingrese el valor del nodo a agregar" << endl;
            cin >> valor;
            agregarNodo(arbolB, valor);
            break;
        case 3:
            compararArboles(arbolA, arbolB);
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