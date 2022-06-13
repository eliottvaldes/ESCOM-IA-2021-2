/**
 * @file t_espejo.cpp
 * @author eliottvaldes@hotmail.com
 * @brief archivo que contiene programa de generador de arboles espejos a partir de uno base (dado por input)
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
void mostrarArbol(nodo *);
void crearArbolEspejo(nodo *&, nodo *);
void mostarArbolEspejo(nodo *);
void agregarEspejo(nodo *&, int);

int main()
{
    int opcionMenu, opcionSalir = 4;
    int elemento;
    nodo *arbol = NULL;
    nodo *arbolEspejo = NULL;
    do
    {
        cout << "\n\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Agregar un elemento al arbol" << endl;
        cout << "2.- Mostrar el arbol normal" << endl;
        cout << "3.- Mostrar el arbol crearArbolEspejo" << endl;
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

            // Mostramos neustro arbol normal
            if (!arbol)
            {
                cout << "El arbol esta vacio!!" << endl;
            }
            else
            {
                cout << "El arbol tiene los siguiente elementos:\n"
                     << endl;
                mostrarArbol(arbol);
            }

            break;

        case 3:

            // Primero vamos a crear nuestro arbol espejo y depues mostrarlo
            crearArbolEspejo(arbolEspejo, arbol);
            mostarArbolEspejo(arbolEspejo);
            cout << endl;

            break;

        case 4:
            cout << "Saliendo del programa" << endl;
            exit(0);
            break;

        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcionMenu != opcionSalir);
    return 0;
}

nodo *crearNodoBase(int elemento)
{
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

void crearArbolEspejo(nodo *&arEspejo, nodo *arbol)
{
    if (!arbol)
    {
        return;
    }
    agregarEspejo(arEspejo, arbol->valor);
    crearArbolEspejo(arEspejo, arbol->izquierda);
    crearArbolEspejo(arEspejo, arbol->derecha);
}

void agregarEspejo(nodo *&arbol, int elemento)
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
    if (ultimoElementoGuardado < elemento)
    {
        agregarEspejo(arbol->izquierda, elemento);
    }
    else // si el elemento es mayor que el ultimo elemento guardado, entonces lo agregamos a la derecha
    {
        agregarEspejo(arbol->derecha, elemento);
    }

    return;
}

void mostarArbolEspejo(nodo *arbol)
{
    // si el arbol está vacio, entonces no hay nada que imprimir y salimos de la recursividad
    // si aun tiene elementos los mostramos
    if (!arbol)
    {
        return;
    }
    else
    {
        cout << arbol->valor << "  ";
        mostarArbolEspejo(arbol->izquierda);
        mostarArbolEspejo(arbol->derecha);
    }
}

void mostrarArbol(nodo *arbol)
{

    // si el arbol está vacio, entonces no hay nada que imprimir y salimos de la recursividad
    // si aun tiene elementos los mostramos
    if (!arbol)
    {
        return;
    }
    else
    {
        mostrarArbol(arbol->izquierda);
        cout << arbol->valor << "  ";
        mostrarArbol(arbol->derecha);
    }
}