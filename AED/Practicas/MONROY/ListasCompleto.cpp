/*
    Monroy Fernandez Jose Luis
    2BV1
    Inteliencia Artificial
*/

#include <iostream>

using namespace std;

struct Nodo
{
    int nobolsas;
    string marca;
    string material;
    float precio;
    Nodo *next;
};

ostream &operator<<(ostream &, Nodo);
void pedirNodo(Nodo *);
void agregarInicio(Nodo **);
void agregarFin(Nodo **);
int posicionesDisp(Nodo *);
void agregarCustom(Nodo **, int);
void imprimirInicio(Nodo *);
void eliminarInicio(Nodo **);
void eliminarFin(Nodo **);
void eliminarCustom(Nodo **, int);

int main()
{
    Nodo *inicio = NULL;
    int totalPosi;
    int opcionMenu;
    do
    {

        cout << "Que desesa hacer" << endl;
        cout << "1.- Agregar una Mochila al inicio" << endl;
        cout << "2.- Agregar una Mochila al final" << endl;
        cout << "3.- Agregar una Mochila en una posicion N" << endl;
        cout << "4.- Imprimir lisatdo" << endl;
        cout << "5.- Eliminar al inicio" << endl;
        cout << "6.- Eliminar al final" << endl;
        cout << "7.- Eliminar una posicion N" << endl;
        cout << "8.- Salir" << endl;
        cin >> opcionMenu;
        switch (opcionMenu)
        {
        case 1:
            agregarInicio(&inicio);
            break;
        case 2:
            agregarFin(&inicio);
            break;
        case 3:
            totalPosi = posicionesDisp(inicio);
            agregarCustom(&inicio, totalPosi);
            break;
        case 4:
            imprimirInicio(inicio);
            break;
        case 5:
            eliminarInicio(&inicio);
            break;
        case 6:
            eliminarFin(&inicio);
            break;
        case 7:
            totalPosi = posicionesDisp(inicio);
            eliminarCustom(&inicio, totalPosi);
            break;
        case 8:
            cout << "Saliendo del programa" << endl;
            exit(0);
        default:
            cout << "Porfavor seleccione una opcion valida" << endl;
            break;
        }
    } while (opcionMenu != 9);
    return 0;
}

void pedirNodo(Nodo *temp)
{
    cout << "Ingrese el numero de bolsas" << endl;
    cin >> temp->nobolsas;
    cout << "Ingrese la marca" << endl;
    cin >> temp->marca;
    cout << "Ingrese el material de la mochila" << endl;
    cin >> temp->material;
    cout << "Ingrese el precio de la mochila" << endl;
    cin >> temp->precio;
    temp->next = NULL;
}

void agregarInicio(Nodo **lista)
{
    Nodo *nuevo = new Nodo;
    pedirNodo(nuevo);
    if (*lista == NULL)
    {
        *lista = nuevo;
        cout << "Nodo guardado" << endl;
    }
    else
    {
        nuevo->next = *lista;
        *lista = nuevo;
    }
}

void agregarFin(Nodo **lista)
{
    Nodo *nuevo = new Nodo;
    pedirNodo(nuevo);
    if (*lista == NULL)
    {
        *lista = nuevo;
        cout << "Nodo guardado" << endl;
    }
    else
    {
        Nodo *itera = *lista;
        while (itera->next != NULL)
        {
            itera = itera->next;
        }
        itera->next = nuevo;
        cout << "Nodo guardado" << endl;
    }
}

int posicionesDisp(Nodo *lista)
{
    int posiciones = 1;
    if (lista == NULL)
    {
        posiciones--;
    }
    else
    {
        Nodo *itera = lista;
        while (itera != NULL)
        {
            itera = itera->next;
            posiciones++;
        }
    }
    return posiciones;
}

void agregarCustom(Nodo **lista, int posiciones)
{
    Nodo *nuevo = new Nodo;
    if (posiciones == 0)
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        pedirNodo(nuevo);
        int contador = 1, position;
        cout << "En que posicion deseas agregar el nodo";
        cout << " hay " << posiciones << " disponibles" << endl;
        cin >> position;
        if (position > posiciones)
        {
            cout << "La posicion excede los nodos ya creados" << endl;
        }
        else
        {
            Nodo *itera = *lista;
            while (contador < position - 1)
            {
                itera = itera->next;
                contador++;
            }
            nuevo->next = itera->next;
            itera->next = nuevo;
            cout << "Nodo guardado" << endl;
        }
    }
}

void imprimirInicio(Nodo *lista)
{
    if (lista == NULL)
    {
        cout << "La lista esta vacia" << endl;
    }
    else
    {
        Nodo *itera = lista;
        while (itera != NULL)
        {
            cout << (*itera);
            itera = itera->next;
        }
    }
}

void eliminarInicio(Nodo **lista)
{
    Nodo *aux = *lista;
    *lista = (*lista)->next;
    delete aux;
    cout << "Nodo eliminado" << endl;
}

void eliminarFin(Nodo **lista)
{
    Nodo *itera1 = (*lista)->next;
    Nodo *itera2;
    while (itera1->next != NULL)
    {
        itera2 = itera1;
        itera1 = itera1->next;
    }
    itera2->next = NULL;
    delete itera1;
    cout << "Nodo eliminado" << endl;
}

void eliminarCustom(Nodo **lista, int posiciones)
{
    if (posiciones == 0)
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        int contador = 1, position;
        cout << "En que posicion deseas agregar el nodo";
        cout << " hay " << posiciones - 1 << " disponibles" << endl;
        cin >> position;
        if (position > posiciones)
        {
            cout << "La posicion excede los nodos ya creados" << endl;
        }
        else
        {
            Nodo *itera1 = *lista;
            Nodo *itera2 = *lista;
            while (contador < position - 1)
            {
                itera1 = itera1->next;
                contador++;
            }
            itera2 = itera1->next;
            itera1->next = itera1->next->next;
            delete itera2;
        }
    }
}

ostream &operator<<(ostream &output, Nodo estructura)
{
    output << "\n Marca: " << estructura.marca;
    output << "\n Material: " << estructura.material;
    output << "\n Numero de bolsas: " << estructura.nobolsas;
    output << "\n Precio: " << estructura.precio << endl;
    return output;
}