/**
 * @file t_eliminacion.cpp
 * @author eliottvaldes@hotmail.com
 * @brief archivo que contiene programa de eliminacion de elementos de un arbol
 * @version 0.1
 * @date 2022-05-30
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
void eliminarNodo(nodo *&, int);
void eliminarHoja(nodo *&);
void eliminarNodoConHijo(nodo *&, nodo *&);
void eliminarNodoConDosHijos(nodo *&);
void eliminacionNHijos(nodo *&);
void eliminacionNodoN(nodo *&);

int main()
{
    int opcionMenu, opcionSalir = 4;
    int elemento;
    nodo *arbol = NULL;

    do
    {
        cout << "\n\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Agregar un elemento al arbol" << endl;
        cout << "2.- Mostrar el arbol" << endl;
        cout << "3.- Eliminar un elemento al arbol" << endl;
        cout << "4.- Salir\n"
             << endl;
        cin >> opcionMenu;
        cout << "\n"
             << endl;

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
            cout << endl;

            break;

        case 3:
            cout << "\nDigita el elemento a eliminar: " << endl;
            cin >> elemento;
            if (elemento == arbol->valor)
            {
                cout << "\n\tElija una opcion:" << endl;
                cout << "1.- Eliminar la raiz" << endl;
                cout << "2.- Eliminar el arbol completo" << endl;
                cin >> opcionMenu;                

                if (opcionMenu == 1)
                {
                    eliminarNodo(arbol, elemento);
                }
                else if (opcionMenu == 2)
                {
                    delete arbol;
                    arbol = NULL;
                }

            }
            else
            {
                eliminarNodo(arbol, elemento);
            }

            cout << "Elemento eliminado exitosamente" << endl;
            break;

        case 4:
            cout << "\n\nSaliendo del programa..." << endl;
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

void eliminarNodo(nodo *&arbol, int elemento)
{
    if (!arbol)
    {
    cout << "\nEl elemento no existe en el arbol" << endl;
        return;
    }

    int ultimoElementoGuardado = arbol->valor;
    if (ultimoElementoGuardado == elemento)
    {
        if (arbol->izquierda == NULL && arbol->derecha == NULL)
        {
            eliminarHoja(arbol);
        }
        else if (arbol->izquierda == NULL && arbol->derecha != NULL && arbol->derecha->derecha == NULL && arbol->derecha->izquierda == NULL)
        {
            eliminarNodoConHijo(arbol, arbol->derecha);
        }
        else if (arbol->izquierda != NULL && arbol->derecha == NULL && arbol->izquierda->izquierda == NULL && arbol->izquierda->derecha == NULL)
        {
            eliminarNodoConHijo(arbol, arbol->izquierda);
        }
        else if (arbol->izquierda != NULL && arbol->derecha != NULL && arbol->izquierda->izquierda == NULL && arbol->izquierda->derecha == NULL && arbol->derecha->izquierda == NULL && arbol->derecha->derecha == NULL)
        {
            eliminarNodoConDosHijos(arbol);
        }
        else
        {
            eliminacionNHijos(arbol);
        }
        return;
    }
    else if (ultimoElementoGuardado > elemento)
    {
        eliminarNodo(arbol->izquierda, elemento);
    }
    else
    {
        eliminarNodo(arbol->derecha, elemento);
    }
}

void eliminarHoja(nodo *&arbol)
{
    delete arbol;
    arbol = NULL;
}

void eliminarNodoConHijo(nodo *&arbol, nodo *&hijo)
{
    int temp1 = arbol->valor;
    arbol->valor = hijo->valor;
    hijo->valor = temp1;
    eliminarHoja(hijo);
}

void eliminarNodoConDosHijos(nodo *&arbol)
{
    if (arbol->valor > arbol->izquierda->valor)
    {
        eliminarNodoConHijo(arbol, arbol->izquierda);
    }
    else
    {
        eliminarNodoConHijo(arbol, arbol->derecha);
    }
}

void eliminacionNHijos(nodo *&arbol)
{
    if (arbol->derecha->izquierda == NULL && arbol->derecha->derecha == NULL)
    {
        eliminarNodoConHijo(arbol, arbol->derecha);
    }
    else if (arbol->izquierda->derecha == NULL && arbol->izquierda->izquierda == NULL)
    {
        eliminarNodoConHijo(arbol, arbol->izquierda);
    }
    else
    {
        nodo *arbolaux = NULL;
        arbolaux = arbol->derecha;
        while (arbolaux->izquierda != NULL)
        {
            arbolaux = arbolaux->izquierda;
        }
        arbol->valor = arbolaux->valor;
        eliminacionNodoN(arbol->derecha);
    }
}

void eliminacionNodoN(nodo *&arbol)
{
    if (arbol->derecha == NULL && arbol->izquierda == NULL)
    {
        eliminarHoja(arbol);
    }
    else
    {
        eliminacionNodoN(arbol->izquierda);
    }
}