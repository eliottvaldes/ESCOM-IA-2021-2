#include <iostream>

using namespace std;

ostream &operator<<(ostream &, nodo);
void pedirNodo(nodo *);
void agregarNodo(nodo**);
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
            agregarNodo(&arbol);
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

void pedirNodo(nodo *tmp){
    cout << "Ingrese el dato a agregar:" << endl;
    cin >> tmp->dato;
    tmp->derecha = NULL;
    tmp->izquierda = NULL;
}

void agregarNodo(nodo **arbol){

}

void imprimirArbol(nodo*arbol){

}

ostream &operator<<(ostream &output, nodo dato){
    output << "\n Dato registrado: "<< dato.dato;
    return output;
}
