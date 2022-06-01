#include <iostream> 

using namespace std;

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo*&, int);
nodo* nuevoNodo(int);
void conocerMax(nodo*);
void conocerMin(nodo*);

int main(){
    int opcionMenu;
    int valor;
    nodo *arbol = NULL;
    do
    {
        cout << "Que desesa hacer" << endl;
        cout << "1.- Agregar un nodo al arbol" << endl;
        cout << "2.- Conocer el valor maximo del arbol" << endl;
        cout << "3.- Conocer el valor minimo del arbol" << endl;
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
                conocerMax(arbol);
                break;
            case 3:
                conocerMin(arbol);
                break;
            case 4:
                cout << "Saliendo del programa" << endl;
                exit(0);
            default:
                cout << "Porfavor ingrese una opción valida" << endl;
                break;
        }
    }while (opcionMenu != 4);
    return 0;
}