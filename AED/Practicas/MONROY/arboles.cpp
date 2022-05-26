#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *derecha;
    nodo *izquierda;
};

//ostream &operator<<(ostream &, nodo);
void agregarNodo(nodo*&, int);
nodo* nuevoNodo(int);
void imprimirArbol(nodo*);
void preorden(nodo*);
void inorden(nodo*);
void postorden(nodo*);
void preordenCon(nodo*);

int main(){
    int opcionMenu;
    int valor;
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

void imprimirArbol(nodo*arbol){
    int opcionUsuario;
    cout << "Con que orden desea imprimir el arbol" << endl;
    cout << "1.- Preorden" << endl;
    cout << "2.- Inorden" << endl;
    cout << "3.- Postorden" << endl;
    cout << "4.- Preorden converso" << endl;
    cout << "5.- Inorden converso" << endl;
    cout << "6.- Postorden converso" << endl;
    cout << "Cualquier otro numero para regresar al menu" << endl;
    cin >> opcionUsuario;
    switch (opcionUsuario){
        case 1:
            cout << "Preorden" << endl;
            preorden(arbol);
            break;
        case 2:
            cout << "Inorden" << endl;
            inorden(arbol);
            cout << endl;
            break;
        case 3:
            cout << "Postorden" << endl;
            postorden(arbol);
            cout << endl;
            break;
        case 4:
            cout << "Preorden converso" << endl;
            preordenCon(arbol);
            cout << endl;
            break;
        case 5:
            cout << "Inorden converso" << endl;
            break;
        case 6:
            cout << "Postorden converso" << endl;
            break;
        default:
            break;
    }
}

void preorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }
    cout << arbol->dato << ", ";
    preorden(arbol->izquierda);
    preorden(arbol->derecha);
    cout << endl;
}

void inorden(nodo* arbol){
    if(arbol==NULL){
        return;
    }
    inorden(arbol->izquierda);
    cout << arbol->dato << ", ";
    inorden(arbol->derecha);
}

void postorden(nodo* arbol){
    if(arbol==NULL){
        return;
    }
    postorden(arbol->izquierda);
    postorden(arbol->derecha);
    cout << arbol->dato << ", ";
}

void preordenCon(nodo* arbol){
    if(arbol==NULL){
        return;
    }
    cout << arbol->dato << ", ";
    preordenCon(arbol->derecha);
    preordenCon(arbol->izquierda);
}


/*ostream &operator<<(ostream &output, nodo dato){
    output << "\n Dato registrado: "<< dato.dato;
    return output;
}*/

//In order to see my work check the commit line of this file in the repository 
