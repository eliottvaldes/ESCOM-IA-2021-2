/**
 * @file Ejercicio_2_2_ArbolNMayor.c++
 * @author Juárez Jiménez Oscar Antonio,  Valdés Luis Eliot Fabián
 * @brief archivo con  la implementacion
 * @version 0.1
 * @date 2022-06-12
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
void inOrdenConverso(nodo *, int, int);

int main()
{
    // opciones para el menu
    int opcionMenu, opcionSalir = 3;

    // variables para el programa
    int nodosDeArbol[] = {49, 37, 89, 13, 41, 53, 7, 19, 71, 25, 60, 82};
    int cantidadNodos = sizeof(nodosDeArbol) / sizeof(nodosDeArbol[0]);
    int elemento, contador = 0;

    nodo *arbol = NULL;
    nodo *arbolPredefinido = NULL;

    do
    {
        cout << "\n\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Inicializar Arbol Predefinido (para el examen)" << endl;
        cout << "2.- Encontrar N-Mayor" << endl;
        cout << "3.- Salir\n\n"
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
                agregarNodo(arbol, nodosDeArbol[i]);
                cout << "\tElemento (" << nodosDeArbol[i] << ") agregado exitosamente\n"
                     << endl;
            }

            break;

        case 2:

            elemento = 0;

            cout << "\nDigita el elemento 'n' mayor a buscar:" << endl;
            cin >> elemento;

            // si pide un elemento mayor a la cantidad de nodos mostramos un mensaje de error
            if (elemento > cantidadNodos)
            {
                cout << "\nERROR. No hay los suficientes nodos disponibles\n"
                     << endl;
                break;
            }

            // hacemos la impresion inOrdenCoverso y detenemos cuando el contador interno sea igual a nuestro elemento n
            cout << "\t\nEl elemento 'n'" << elemento << " mayor  en el arbol es:\n"
                 << endl;
            inOrdenConverso(arbol, elemento, 0);

            break;

        case 3:

            cout << "\n\nSaliendo del programa..." << endl;
            exit(0);

        case 4:

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
    if (arbol == NULL)
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

void inOrdenConverso(nodo *arbol, int elemento, int contador)
{
    if (!arbol)
    {
        return;
    }

    if (contador == elemento)
    {   
        inOrdenConverso(arbol->derecha, elemento, contador);        
        cout << arbol->valor << "  ";
        inOrdenConverso(arbol->izquierda, elemento, contador);     
        return;
    }

    if (contador != elemento)
    {
        contador++;
        inOrdenConverso(arbol->derecha, elemento, contador);
        inOrdenConverso(arbol->izquierda, elemento, contador);
    }
}
