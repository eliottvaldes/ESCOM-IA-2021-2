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
    
}

void imprimirInicio(Nodo *inicio)
{
    
}

void imprimirFin(Nodo *fin)
{
    
}

void eliminarInicio(Nodo **inicio, Nodo **fin)
{
    
}

void eliminarFin(Nodo **inicio, Nodo **fin)
{
    
}

void eliminarCustom(Nodo **inicio, Nodo **fin, int posiciones)
{
    
}

ostream &operator<<(ostream &output, Nodo estructura)
{
    output << "\n Marca: " << estructura.marca;
    output << "\n Material: " << estructura.material;
    output << "\n Numero de bolsas: " << estructura.nobolsas;
    output << "\n Precio: " << estructura.precio << endl;
    return output;
}