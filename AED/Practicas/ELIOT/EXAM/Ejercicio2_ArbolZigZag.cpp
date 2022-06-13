/**
 * @file Tree_BST.cpp
 * @author Juárez Jiménez Oscar Antonio,  Valdés Luis Eliot Fabián
 * @brief Archivo que contiene al arbol BST con impresión de nodos por nivel y en zigzag
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct nodo
{
    int valor;
    nodo *derecha;
    nodo *izquierda;
};

void agregarNodo(nodo *&, int);
nodo *crearNodoBase(int);
void recorridoPorNivel(nodo *);
void recorridoPorZigZag(nodo *);

int main()
{
    // variables para el menu
    int opcionMenu, opcionSalir = 7;

    // variables para el programa de arbolPredefinido
    int nodosDeArbol[] = {49, 37, 89, 13, 41, 53, 7, 19, 71, 25, 60, 82};
    int cantidadNodos = sizeof(nodosDeArbol) / sizeof(nodosDeArbol[0]);
    int elemento;

    // creacion inicial del arbolPredefinido
    nodo *arbolPredefinido = NULL;
    nodo *arbolPropio = NULL;

    do
    {
        cout << "\n\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Iniciar arbol con valores predefinidos (para examen)" << endl;
        cout << "2.- Agregar nuevo elemento al arbol propio (valores propios)" << endl;
        cout << "3.- Mostrar arbol (PREDEFINIDO) por nivel" << endl;
        cout << "4.- Mostrar arbol (PROPIO) por nivel" << endl;
        cout << "5.- Mostrar arbol (PREDEFINIDO) por ZigZag" << endl;
        cout << "6.- Mostrar arbol (PROPIO) por ZigZag" << endl;
        cout << "7.- Salir\n\n"
             << endl;

        cin >> opcionMenu;

        switch (opcionMenu)
        {
        case 1:

            // hacemos hardcoding para agregar los valores predefinidos para el ejemplo
            // recorremos todos los nodos predefinidos para agregarlos al arbolPredefinido
            for (int i = 0; i < cantidadNodos; i++)
            {
                // agredamos los nodos al arbolPredefinido
                agregarNodo(arbolPredefinido, nodosDeArbol[i]);
                cout << "\tElemento (" << nodosDeArbol[i] << ") agregado exitosamente\n"
                     << endl;
            }

            break;

        case 2:
            // como vamos a crear el arbol por los valores de entrada se lso pedimos al usuario
            cout << "\nDigita el elemento nuevo para tu arbol:" << endl;
            cin >> elemento;

            agregarNodo(arbolPropio, elemento);
            break;

        case 3:
            cout << "\nMostrar arbol PREDEFINIDO por nivel\n"
                 << endl;
            recorridoPorNivel(arbolPredefinido);
            break;

        case 4:
            cout << "\nMostrar arbol PROPIO por nivel\n"
                 << endl;
            recorridoPorNivel(arbolPropio);
            break;

        case 5:
            cout << "\nMostrar arbol PREDEFINIDO por Zig Zag\n"
                 << endl;
            recorridoPorZigZag(arbolPredefinido);
            break;

        case 6:
            cout << "\nMostrar arbol PROPIO por Zig Zag\n"
                 << endl;
            recorridoPorZigZag(arbolPropio);
            break;

        case 7:
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

void agregarNodo(nodo *&arbolPredefinido, int elemento)
{
    // si nuestro arbolPredefinido está vacio, entonces creamos un nodo inicial
    if (arbolPredefinido == NULL)
    {
        nodo *Nuevo = crearNodoBase(elemento);
        arbolPredefinido = Nuevo;
        return;
    }

    // obtenemos el ultimo elemento guardo y lo comparamos con el nuevo elemento
    int ultimoElementoGuardado = arbolPredefinido->valor;

    // si ya existe el elemento, no se agrega y no hacemos nada
    if (ultimoElementoGuardado == elemento)
        return;

    // si el elemento es menor que el ultimo elemento guardado, entonces lo agregamos a la izquierda
    if (ultimoElementoGuardado > elemento)
    {
        agregarNodo(arbolPredefinido->izquierda, elemento);
    }
    else // si el elemento es mayor que el ultimo elemento guardado, entonces lo agregamos a la derecha
    {
        agregarNodo(arbolPredefinido->derecha, elemento);
    }

    return;
}

// creamos nuestra funcion para mostar el arbol por nivel
void recorridoPorNivel(nodo *arbol)
{

    // creamos un nodo temporal auxiliar
    nodo *temp;
    // creamos nuestra cola auxiliar
    queue<nodo *> cola;

    // verificamos que no este vacio
    if (!arbol)
    {
        cout << "El arbol esta vacio" << endl;
        return;
    }

    // agregamos el nodo raiz a la cola
    cola.push(arbol);

    cout << "\t";

    // recorremos mientras no encontremos un null
    while (!cola.empty())
    {
        // obtenemos el ultimo valor de la cola y lo asignamos a temp
        temp = cola.front();
        cola.pop();

        // mostramos el primer elemento de la cola
        cout << temp->valor << " ";

        // verificamos si hay nodo izquierdo o derecho
        if (temp->izquierda)
        {
            // agredamos a nuestra cola el valor izquierdo de nuestro nodo temp
            cola.push(temp->izquierda);
        }
        if (temp->derecha)
        {
            // agredamos a nuestra cola el valor derecho de nuestro nodo temp
            cola.push(temp->derecha);
        }
    }

    // eliminamos todos los elementos de la cola
    cola.pop();

    return;
}

// creamos nuetra funcion para mostrar el arbol por ZigZag
void recorridoPorZigZag(nodo *arbol)
{
    // creamos un nodo temporal
    nodo *temp;
    // creamos nuestro iterador de nivel izquierda a derecha
    int der_a_izq = 1;

    // verificamos que no esté vacio
    if (!arbol)
    {
        cout << "El arbol esta vacio" << endl;
        return;
    }

    // creamos nuestras pila temporal del nivel actual y el siguiente
    stack<nodo *> nivelActual, nivelSiguiente;

    // agregamos a nuestra pila del nivel actual el nodo raiz
    nivelActual.push(arbol);

    cout << "\t";
    // recorremos mientras no encontremos un null en la pila de nivel actual
    while (!nivelActual.empty())
    {
        // obtenemos el ultimo valor de la pila y lo asignamos a temp
        temp = nivelActual.top();
        // eliminamos el ultimo valor de la pila
        nivelActual.pop();

        // hacemos la validacion de nuestro nodo Temp

        if (temp)
        {
            // mostramos el primer elemento de la pila
            cout << temp->valor << " ";

            // de acuerdo a nuestro iterador vamos a agregar a neustra pila del nivel siguiente
            if (der_a_izq)
            {
                if (temp->derecha)
                    nivelSiguiente.push(temp->derecha);
                if (temp->izquierda)
                    nivelSiguiente.push(temp->izquierda);
            }
            else
            {
                if (temp->izquierda)
                    nivelSiguiente.push(temp->izquierda);
                if (temp->derecha)
                    nivelSiguiente.push(temp->derecha);

            } // fin del else

        } // fin del if temp

        // verificamos si nuestro nivel actual esta vacio
        if (nivelActual.empty())
        {

            // si esta vacio, entonces cambiamos el iterador de nivel
            der_a_izq = 1 - der_a_izq;
            // hacemos swap entre el nivel actual y el nivel siguiente
            // Como no se peude usar el swap pal examen hacemos una copia de la pila y la usamos como auxiliar
            stack<nodo *> aux = nivelActual;
            nivelActual = nivelSiguiente;
            nivelSiguiente = aux;

        } // fin del if nivelActual -> empty()

    } // fin del while
}