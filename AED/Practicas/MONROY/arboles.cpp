#include <iostream>

using namespace std;

ostream &operator<<(ostream &, nodo);
void agregarNodo(nodo**, int);
nodo *crearNodo(int);
void imprimirArbol(nodo*);

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

int main(){
    int opcionMenu;
    nodo *arbol = NULL;
    do
    {
        cout << "Que desesa hacer" << endl;
        cout << "1.- Agregar un nodo al arbol" << endl;
        cout << "2.- Imprimir el arbol" << endl;
        cout << "3.- Salir del programa" << endl;
        cin >> opcionMenu;
        switch (opcionMenu){
        case 1:
            int valor;
            cout << "Porfavor ingrese el valor del nodo a agregar" << endl;
            cin >> valor;
            agregarNodo(arbol, valor);
            break;
        case 2:
            imprimirArbol(arbol);
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

nodo *crearNodo(int valor){
    nodo *Nuevo = NULL;
    Nuevo->dato = valor;
    Nuevo->derecha = NULL;
    Nuevo->izquierda = NULL;
    return Nuevo;
}


void agregarNodo(nodo *&arbol, int valor){
    if(arbol==NULL){
        nodo* Nuevo = crearNodo(valor);
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

void imprimirArbol(nodo*arbol){

}

ostream &operator<<(ostream &output, nodo dato){
    output << "\n Dato registrado: "<< dato.dato;
    return output;
}
