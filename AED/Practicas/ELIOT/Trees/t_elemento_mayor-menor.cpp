/**
 * @file t_elemento_mayor-menor.cpp
 * @author eliottvaldes@hotmail.com
 * @brief archivo que contiene el programa de arboles que meustra el elemento (elemento numerico) mayor y menor
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
nodo *crearNodoBase(int);
int obtenerValorMayor(nodo *);
int obtenerValorMenor(nodo *);

int main()
{
    int opcionMenu, opcionSalir = 4;
    int elemento, valorMayor, valorMenor;
    nodo *arbol = NULL;
    do
    {
        cout << "\n\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Agregar un elemento al arbol" << endl;
        cout << "2.- Mostrar el elemento mayor del arbol" << endl;
        cout << "3.- Mostrar el elemento menor del arbol" << endl;
        cout << "4.- Salir\n\n"
             << endl;

        cin >> opcionMenu;

        switch (opcionMenu)
        {
        case 1:

            cout << "\nDigita el valor del nuevo elemento del arbol:" << endl;
            cin >> elemento;

            agregarNodo(arbol, elemento);
            cout << "\tElemento (" << elemento << ") agregado exitosamente\n"
                 << endl;

            break;

        case 2:

            valorMayor = obtenerValorMayor(arbol);
            cout << "El " << valorMayor << " es el elemento mayor del arbol" << endl;

            break;

        case 3:

            valorMenor = obtenerValorMenor(arbol);
            cout << "El " << valorMenor << " es el elemento menor del arbol" << endl;

            break;

        case 4:

            cout << "\n\nSaliendo del programa..." << endl;
            exit(0);

            break;

        default:
            cout << "Opcion no valida." << endl;
            break;
        }
    } while (opcionMenu != opcionSalir);

    return 0;
}

nodo *crearNodoBase(int elemento)
{
    // creamos nuestro nodo base
    nodo *Nuevo = new nodo;
    Nuevo->valor = elemento;
    Nuevo->derecha = NULL;
    Nuevo->izquierda = NULL;
    return Nuevo;
}

void agregarNodo(nodo *&arbol, int elemento)
{
    // si nuestro arbol está vacio, entonces creamos un nodo inicial
    if (!arbol)
    {
        nodo *Nuevo = crearNodoBase(elemento);
        arbol = Nuevo;
        return;
    }

    // obtenemos el ultimo elemento guardo y lo comparamos con el nuevo elemento
    int ultimoElementoGuardado = arbol->valor;

    if (ultimoElementoGuardado == elemento)
    {
        cout << "\nElemento registrado previamente, cuidado!!\n"
             << endl;
        return;
    }

    // si el elemento es menor que el ultimo elemento guardado, entonces lo agregamos a la izquierda
    if (ultimoElementoGuardado > elemento)
    {
        agregarNodo(arbol->izquierda, elemento);
    }
    else // si el elemento es mayor que el ultimo elemento guardado, entonces lo agregamos a la derecha
    {
        agregarNodo(arbol->derecha, elemento);
    }

    return;
}

int obtenerValorMayor(nodo *arbol)
{
    // recorremos todo nuestro arbol de la parte derecha para obtener el valor más grande
    while (arbol->derecha != NULL)
    {
        arbol = arbol->derecha;
    }

    return arbol->valor;
}

int obtenerValorMenor(nodo *arbol)
{
    // recorremos todo nuestro arbol de la parte izquiera para obtener el valor más pequeño
    while (arbol->izquierda != NULL)
    {
        arbol = arbol->izquierda;
    }

    return arbol->valor;
}