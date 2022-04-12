/**
 * @file Lista-Agregar.cpp
 * @author Valdes Luis Eliot Fabián
 * @brief programa que contiene ejercicio de Lista - Agregar(2)
 * @version 0.1
 * @date 2022-04-01
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

// creamos la estructura
typedef struct Nodo
{
    int dato;
    Nodo *sig;
} Nodo;

// Creamos prototipos
void agregarInicio(Nodo *list, int dato);
void agregarFin(Nodo *list, int dato);

int main()
{

    Nodo *inicio = NULL;
    inicio = new Nodo();

    int opcionMenu = 0, opcionsalir = 3;
    int cantidadAgregar;
    do
    {
        cout << "\n\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Agregar una elemento al inicio" << endl;
        cout << "2.- Agregar una elemento al final" << endl;
        cout << "3.- Salir" << endl;
        cin >> opcionMenu;
        cout << "\n" << endl;

        switch (opcionMenu)
        {

        case 1:
            cout << "Digita una cantidad: " << endl;
            cin >> cantidadAgregar;
            agregarInicio(inicio, cantidadAgregar);
            break;

        case 2:
            cout << "Digita una cantidad: " << endl;
            cin >> cantidadAgregar;
            agregarFin(inicio, cantidadAgregar);
            break;

        case 3:
            cout << "\nSaliendo del programa..." << endl;
            exit(0);
            break;
        default:
            cout << "Por favor selecciona una opcion valida \n" << endl;
            break;
        }
    } while (opcionMenu != opcionsalir);

    return 0;
}

void agregarInicio(Nodo *list, int dato)
{

    Nodo *nodoAuxiliar = new Nodo();

    nodoAuxiliar->sig = NULL;
    nodoAuxiliar->dato = dato;

    if (list == NULL)
    {
        list->sig = nodoAuxiliar;
    }
    else
    {
        nodoAuxiliar->sig = list->sig;
        list->sig = nodoAuxiliar;
    }
}

void agregarFin(Nodo *list, int dato)
{

    Nodo *iterador;
    iterador = list;

    while (iterador->sig != NULL)
    {
        iterador = iterador->sig;
    }

    Nodo *nodoAuxiliar = new Nodo();

    nodoAuxiliar->sig = NULL;
    iterador->sig = nodoAuxiliar;
    nodoAuxiliar->dato = dato;
}
