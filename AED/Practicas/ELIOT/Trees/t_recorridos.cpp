/**
 * @file t_recorridos.cpp
 * @author eliottvaldes@hotmail.com
 * @brief archivo que conrtiene programa de recorridos de arboles (pre orden, in orden, post orden)
 * @version 0.1
 * @date 2022-05-28
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

// ostream &operator<<(ostream &, nodo);
void agregarNodo(nodo *&, int);
nodo *crearNodoBase(int);
void mostrarArbol(nodo *);
void preOrden(nodo *);
void inOrden(nodo *);
void postOrden(nodo *);
void preOrdenConverso(nodo *);
void inOrdenConverso(nodo *);
void postOrdenConverso(nodo *);

int main()
{
    int opcionMenu, opcionSalir = 3;
    int elemento;
    nodo *arbol = NULL;
    do
    {
        cout << "\n\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Agregar un elemento al arbol" << endl;
        cout << "2.- Mostrar el arbol" << endl;
        cout << "3.- Salir\n\n"
             << endl;

        cin >> opcionMenu;

        switch (opcionMenu)
        {
        case 1:

            cout << "\nDigita el elemento del nuevo elemento del arbol:" << endl;
            cin >> elemento;

            agregarNodo(arbol, elemento);

            break;

        case 2:

            mostrarArbol(arbol);

            break;

        case 3:

            cout << "\n\nSaliendo del programa..." << endl;
            exit(0);

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
    int opcionUsuario;
    cout << "\n\n---------------------------------------------------" << endl;
    cout << "\tDigita el numero del recorrido que deseas llevar a cabo" << endl;
    cout << "---------------------------------------------------" << endl;
    cout << "1.- Pre-Orden" << endl;
    cout << "2.- In-Orden" << endl;
    cout << "3.- Post-Orden" << endl;
    cout << "4.- Pre-Orden Converso" << endl;
    cout << "5.- In-Orden Converso" << endl;
    cout << "6.- Post-Orden Converso" << endl;
    cout << "7.- Regresar a menu principal\n"
         << endl;
    cin >> opcionUsuario;

    switch (opcionUsuario)
    {
    case 1:

        cout << "\n\tMostrando Arbol con recorrido Pre-Orden" << endl;
        preOrden(arbol);

        break;

    case 2:

        cout << "\n\tMostrando Arbol con recorrido In-Orden" << endl;
        inOrden(arbol);
        cout << endl;

        break;

    case 3:

        cout << "\n\tMostrando Arbol con recorrido Post-Orden" << endl;
        postOrden(arbol);
        cout << endl;

        break;

    case 4:

        cout << "\n\tMostrando Arbol con recorrido Pre-Orden Converso" << endl;
        preOrdenConverso(arbol);
        cout << endl;

        break;

    case 5:

        cout << "\n\tMostrando Arbol con recorrido In-Orden Converso" << endl;
        inOrdenConverso(arbol);
        cout << endl;

        break;

    case 6:

        cout << "\n\tMostrando Arbol con recorrido Post-Orden Converso" << endl;
        postOrdenConverso(arbol);
        cout << endl;

        break;

    case 7:
        cout << "\nRegresando a menu principal...\n"
             << endl;
        break;

    default:
        break;
    }
}

void preOrden(nodo *arbol)
{
    if (!arbol)
    {
        return;
    }
    cout << arbol->valor << " ";
    preOrden(arbol->izquierda);
    preOrden(arbol->derecha);
    cout << endl;
}

void inOrden(nodo *arbol)
{
    if (!arbol)
    {
        return;
    }
    inOrden(arbol->izquierda);
    cout << arbol->valor << " ";
    inOrden(arbol->derecha);
}

void postOrden(nodo *arbol)
{
    if (!arbol)
    {
        return;
    }
    postOrden(arbol->izquierda);
    postOrden(arbol->derecha);
    cout << arbol->valor << " ";
}

void preOrdenConverso(nodo *arbol)
{
    if (!arbol)
    {
        return;
    }
    cout << arbol->valor << " ";
    preOrdenConverso(arbol->derecha);
    preOrdenConverso(arbol->izquierda);
}

void inOrdenConverso(nodo *arbol)
{
    if (!arbol)
    {
        return;
    }
    inOrdenConverso(arbol->derecha);
    cout << arbol->valor << "  ";
    inOrdenConverso(arbol->izquierda);
}

void postOrdenConverso(nodo *arbol)
{
    if (!arbol)
    {
        return;
    }
    postOrdenConverso(arbol->derecha);
    postOrdenConverso(arbol->izquierda);
    cout << arbol->valor << " ";
}