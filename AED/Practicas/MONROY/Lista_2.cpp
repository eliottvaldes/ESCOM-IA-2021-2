/*
    Monroy Fernandez Jose Luis
    2BV1
    Inteligencia Artificial
*/
#include <iostream>

using namespace std;

typedef struct Nodo
{
    int dato;
    Nodo *next;
} Nodo;

void agregarInicio(Nodo *);
void agregarFin(Nodo *);
void imprimirLista(Nodo *);

int main()
{
    Nodo *lista = NULL;
    lista = new Nodo();
    int opcionMenu;
    do
    {
        cout << "\nQue desea hacer?" << endl;
        cout << "1.- Insertar un nuevo nodo al inicio " << endl;
        cout << "2.- Insertar un nuevo nodo al final " << endl;
        cout << "3.- Imprimir lista " << endl;
        cout << "4.- Salir" << endl;
        cin >> opcionMenu;
        switch (opcionMenu)
        {
        case 1:
            agregarInicio(lista);
            break;
        case 2:
            agregarFin(lista);
            break;
        case 3:
            imprimirLista(lista);
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

void agregarInicio(Nodo *lista)
{
    int datoAgregar;
    cout << "Porfavor digite el numero a agregar" << endl;
    cin >> datoAgregar;
    Nodo *nuevo = new Nodo();
    nuevo->next = NULL;
    nuevo->dato = datoAgregar;
    if (lista == NULL)
    {
        lista->next = nuevo;
    }
    else
    {
        nuevo->next = lista->next;
        lista->next = nuevo;
    }
}

void agregarFin(Nodo *lista)
{
    int datoAgregar;
    Nodo *it;
    it = lista;
    Nodo *nuevo = new Nodo();
    while (it->next != NULL)
    {
        it = it->next;
    }
    nuevo->next = NULL;
    it->next = nuevo;
    cout << "Porfavor digite el numero a agregar" << endl;
    cin >> datoAgregar;
    nuevo->dato = datoAgregar;
}

void imprimirLista(Nodo *lista)
{
    Nodo *it;
    it = lista;
    while (it->next != NULL)
    {
        it = it->next;
        cout << it->dato << "->";
    }
}