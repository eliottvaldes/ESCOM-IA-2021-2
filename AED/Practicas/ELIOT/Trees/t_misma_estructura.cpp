/**
 * @file t_misma_estructura.cpp
 * @author eliottvaldes@hotmail.com
 * @brief archivo que contiene programa para verificar si la estructura de dos arboles son iguales
 * @version 0.1
 * @date 2022-06-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
using namespace std;

struct nodo
{
    int valor;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo *&, int);
nodo *nuevoNodo(int);
int compararArboles(nodo *, nodo *);

int main()
{
    int opcionMenu;
    int elemento;
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

        switch (opcionMenu)
        {
        case 1:

            cout << "\nDigita el valor del nuevo elemento del arbol:" << endl;
            cin >> elemento;
            agregarNodo(arbolA, elemento);
            cout << "Nodo agregado" << endl;

            break;

        case 2:

            cout << "\nDigita el valor del nuevo elemento del arbol:" << endl;
            cin >> elemento;
            agregarNodo(arbolB, elemento);
            cout << "Nodo agregado" << endl;

            break;

        case 3:

            if (compararArboles(arbolA, arbolB))
            {
                cout << "Los arboles son iguales" << endl;
            }
            else
            {
                cout << "Los arboles son diferentes" << endl;
            }

            break;

        case 4:

            cout << "Saliendo del programa" << endl;
            exit(0);
            break;

        default:
              cout << "Porfavor seleccione una opcion valida" << endl;
            break;
        }
    } while (opcionMenu != 4);
    return 0;
}

nodo *nuevoNodo(int elemento)
{
    nodo *Nuevo = new nodo;
    Nuevo->valor = elemento;
    Nuevo->derecha = NULL;
    Nuevo->izquierda = NULL;
    return Nuevo;
}

void agregarNodo(nodo *&arbol, int elemento)
{
    if (!arbol)
    {
        nodo *Nuevo = nuevoNodo(elemento);
        arbol = Nuevo;
        return;
    }
    int newValor = arbol->valor;
    if (newValor == elemento)
    {
        cout << "El elemento ya existe en el arbol" << endl;
        return;
    }
    if (newValor > elemento)
    {
        agregarNodo(arbol->izquierda, elemento);
    }
    else
    {
        agregarNodo(arbol->derecha, elemento);
    }
}

int compararArboles(nodo *arbolA, nodo *arbolB)
{
    if (arbolA == NULL && arbolB == NULL)
    {
        return true;
    }
    else if (arbolA != NULL && arbolB != NULL)
    {
        return (compararArboles(arbolA->izquierda, arbolB->izquierda) && compararArboles(arbolA->derecha, arbolB->derecha));
    }
    return false;
}