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
    Nodo *siguiente;
    Nodo *anterior;
};

ostream &operator<<(ostream &, Nodo);
void pedirNodo(Nodo *);
void agregarInicio(Nodo **, Nodo **);
void agregarFin(Nodo **, Nodo **);
int posicionesDisp(Nodo *);
void agregarCustom(Nodo **, Nodo **, int);
void imprimirInicio(Nodo *);
void imprimirFin(Nodo *);
void eliminarInicio(Nodo **, Nodo **);
void eliminarFin(Nodo **, Nodo **);
void eliminarCustom(Nodo **, Nodo **, int);

int main()
{
    Nodo *inicio = NULL;
    Nodo *final = NULL;
    int totalPosi;
    int opcionMenu;
    do
    {

        cout << "Que desesa hacer" << endl;
        cout << "1.- Agregar una Mochila al inicio" << endl;
        cout << "2.- Agregar una Mochila al final" << endl;
        cout << "3.- Agregar una Mochila en una posicion N" << endl;
        cout << "4.- Imprimir lista de inicio a fin" << endl;
        cout << "5.- Imprimir lista de fin a inicio" << endl;
        cout << "6.- Eliminar al inicio" << endl;
        cout << "7.- Eliminar al final" << endl;
        cout << "8.- Eliminar una posicion N" << endl;
        cout << "9.- Salir" << endl;
        cin >> opcionMenu;
        switch (opcionMenu)
        {
        case 1:
            agregarInicio(&inicio, &final);
            break;
        case 2:
            agregarFin(&inicio, &final);
            break;
        case 3:
            totalPosi = posicionesDisp(inicio);
            agregarCustom(&inicio, &final, totalPosi);
            break;
        case 4:
            imprimirInicio(inicio);
            break;
        case 5:
            imprimirFin(final);
            break;
        case 6:
            eliminarInicio(&inicio, &final);
            break;
        case 7:
            eliminarFin(&inicio, &final);
            break;
        case 8:
            totalPosi = posicionesDisp(inicio);
            eliminarCustom(&inicio, &final, totalPosi);
            break;
        case 9:
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
    temp->siguiente = NULL;
    temp->anterior = NULL;
}

void agregarInicio(Nodo **inicio, Nodo **fin)
{
    Nodo *nuevo = new Nodo;
    pedirNodo(nuevo);
    if (*inicio == NULL)
    {
        *inicio = nuevo;
        *fin = nuevo;
        cout << "Nodo guardado" << endl;
    }
    else
    {
        Nodo *itera = *fin;
        while (itera->anterior != NULL)
        {
            itera = itera->anterior;
        }
        itera->anterior = nuevo;
        nuevo->siguiente = *inicio;
        *inicio = nuevo;
        cout << "Nodo guardado" << endl;
    }
}

void agregarFin(Nodo **inicio, Nodo **fin)
{
    Nodo *nuevo = new Nodo;
    pedirNodo(nuevo);
    if (*fin == NULL)
    {
        *inicio = nuevo;
        *fin = nuevo;
        cout << "Nodo guardado" << endl;
    }
    else
    {
        Nodo *itera = *inicio;
        while (itera->siguiente != NULL)
        {
            itera = itera->siguiente;
        }
        itera->siguiente = nuevo;
        nuevo->anterior = *fin;
        *fin = nuevo;
        cout << "Nodo guardado" << endl;
    }
}

int posicionesDisp(Nodo *inicio)
{
    int posiciones = 1;
    if (inicio == NULL)
    {
        posiciones--;
    }
    else
    {
        Nodo *itera = inicio;
        while (itera != NULL)
        {
            itera = itera->siguiente;
            posiciones++;
        }
    }
    return posiciones;
}

void agregarCustom(Nodo **inicio, Nodo **fin, int posiciones)
{
    Nodo *nuevo = new Nodo;
    if (posiciones == 0)
    {
        cout << "lista vacia" << endl;
    }
    else
    {
        pedirNodo(nuevo);
        int contador = 1, position, itera2pos;
        cout << "En que posicion deseas agregar el nodo";
        cout << " hay " << posiciones << " disponibles" << endl;
        cin >> position;
        if (position > posiciones)
        {
            cout << "La posicion excede los nodos ya creados" << endl;
        }
        else
        {
            Nodo *itera = *inicio;
            Nodo *itera2 = *fin;
            itera2pos = posiciones - position;
            while (contador < position - 1)
            {
                itera = itera->siguiente;
                contador++;
            }
            contador = 1;
            while (contador < itera2pos - 1)
            {
                itera2 = itera2->siguiente;
                contador++;
            }

            nuevo->siguiente = itera2;
            itera2->anterior = nuevo;
            nuevo->anterior = itera;
            itera->siguiente = nuevo;
            cout << "Nodo guardado" << endl;
        }
    }
}

void imprimirInicio(Nodo *inicio)
{
    if (inicio == NULL)
    {
        cout << "La inicio esta vacia" << endl;
    }
    else
    {
        Nodo *itera = inicio;
        while (itera != NULL)
        {
            cout << (*itera);
            itera = itera->siguiente;
        }
    }
}

void imprimirFin(Nodo *fin)
{
    if (fin == NULL)
    {
        cout << "La lista esta vacia" << endl;
    }
    else
    {
        Nodo *itera = fin;
        while (itera != NULL)
        {
            cout << (*itera);
            itera = itera->anterior;
        }
    }
}

void eliminarInicio(Nodo **inicio, Nodo **fin)
{
    Nodo *aux = *inicio;
    *inicio = (*inicio)->siguiente;
    delete aux;
    Nodo *itera1 = (*fin)->anterior;
    Nodo *itera2;
    while (itera1->anterior != NULL)
    {
        itera2 = itera1;
        itera1 = itera1->anterior;
    }
    itera2->anterior = NULL;
    delete itera1;
    cout << "Nodo eliminado" << endl;
}

void eliminarFin(Nodo **inicio, Nodo **fin)
{
    Nodo *aux = *fin;
    *fin = (*fin)->anterior;
    delete aux;
    Nodo *itera1 = (*inicio)->siguiente;
    Nodo *itera2;
    while (itera1->siguiente != NULL)
    {
        itera2 = itera1;
        itera1 = itera1->siguiente;
    }
    itera2->siguiente = NULL;
    delete itera1;
    cout << "Nodo eliminado" << endl;
}

void eliminarCustom(Nodo **inicio, Nodo **fin, int posiciones)
{
    if (posiciones == 0)
    {
        cout << "Lista vacia" << endl;
    }
    else
    {
        int contador = 1, position;
        cout << "Cual elemento de la lista quieres eliminar";
        cout << " hay " << posiciones - 1 << " disponibles" << endl;
        cin >> position;
        if (position > posiciones)
        {
            cout << "El elemento no existe" << endl;
        }
        else
        {
            Nodo *itera1 = *inicio;
            Nodo *itera2 = *inicio;
            Nodo *itera3 = *fin;
            Nodo *itera4 = *fin;
            int itera3pos = posiciones - position;
            while (contador < position - 1)
            {
                itera1 = itera1->siguiente;
                contador++;
            }
            itera2 = itera1->siguiente;
            itera1->siguiente = itera1->siguiente->siguiente;
            delete itera2;

            contador = 1;
            while (contador < itera3pos - 1)
            {
                itera2 = itera3->anterior;
                contador++;
            }
            itera4 = itera3->anterior;
            itera3->anterior = itera3->anterior->anterior;
            delete itera4;
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