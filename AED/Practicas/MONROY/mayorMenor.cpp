#include <iostream> 

using namespace std;

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo*&, int);
nodo* nuevoNodo(int);
int conocerMax(nodo*);
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
                valor = conocerMax(arbol);
                cout << "El " << valor << " es el valor más grande del arbol" << endl;
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

int conocerMax(nodo *arbol){
    while(arbol->derecha != NULL){
        arbol = arbol->derecha;
    }
    return arbol->dato;
}