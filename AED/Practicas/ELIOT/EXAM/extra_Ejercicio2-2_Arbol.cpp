/**
 * @file Ejercicio_2_2_ArbolNMayor.c++
 * @author Juárez Jiménez Oscar Antonio,  Valdés Luis Eliot Fabián
 * @brief archivo con  la implementacion de encontrar iun mayor
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct nodo
{
    int valor;
    struct nodo *izquierdo = NULL;
    struct nodo *derecho = NULL;
} nodo;

nodo *CrearNodo(int);
int encontrarMayor(struct nodo *raiz);
void AgregarNodo(nodo **, int);
void eliminarArbol(nodo *&);
void eliminarNodo(nodo **, int valor);
void ArbolCopia(nodo *, nodo **raiz);

int main()
{
    int nodosDeArbol[] = {49, 37, 89, 13, 41, 53, 7, 19, 71, 25, 60, 82};
    int cantidadNodos = sizeof(nodosDeArbol) / sizeof(nodosDeArbol[0]);

    nodo *arbolPredefinido = NULL;

    int cont = 1;

    nodo *raiz = NULL;
    nodo *raizCopia = NULL;
    nodo *final = NULL;
    nodo *it = NULL;

    int OpUser = 0, valor = 0;

    do
    {
        cout << "\n\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Inicializar Arbol Predefinido (para el examen)" << endl;
        cout << "2.- Agregar nuevo elemento al arbol (propio)" << endl;
        cout << "3.- Encontrar N-Mayor" << endl;
        cout << "4.- Salir\n\n"
             << endl;

        cin >> OpUser;
        switch (OpUser)
        {

        case 1:

            // hacemos hardcoding para agregar los valores predefinidos para el ejemplo
            for (int i = 0; i < cantidadNodos; i++)
            {
                AgregarNodo(&raiz, nodosDeArbol[i]);
                cout << "\tElemento (" << nodosDeArbol[i] << ") agregado exitosamente\n"
                     << endl;
            }

            break;

        case 2:
            cout << "\nIngrese el valor que se asignara al nodo:" << endl;
            cin >> valor;
            AgregarNodo(&raiz, valor);
            break;

        case 3:
            if (raiz != NULL)
                cout << "\nIngres el numero mayor que desea:" << endl;
            int ncimo;
            cin >> ncimo;
            ArbolCopia(raiz, &raizCopia);
            for (int i = 0; i < ncimo - 1; i++)
            {
                eliminarNodo(&raizCopia, encontrarMayor(raizCopia));
            }
            cout << "\t" << encontrarMayor(raizCopia) << endl;
            break;

        case 4:
            cout << "\nSaliendo..." << endl;
            eliminarArbol(raiz);
            break;

        default:
            cout << "\nOpcion no valida" << endl;
            break;
        }
    } while (OpUser != 4);
    return 0;
}

void ArbolCopia(nodo *raiz, nodo **raizespejo)
{
    struct nodo *temp;
    if (raiz != NULL)
    {
        *raizespejo = CrearNodo(raiz->valor);
        ArbolCopia(raiz->derecho, &(*raizespejo)->derecho);
        ArbolCopia(raiz->izquierdo, &(*raizespejo)->izquierdo);
    }
}
nodo *CrearNodo(int valor)
{
    nodo *nuevo = new (nodo);
    nuevo->izquierdo = NULL;
    nuevo->derecho = NULL;
    nuevo->valor = valor;
    return nuevo;
}
void AgregarNodo(nodo **raiz, int valor)
{
    if (*raiz == NULL)
    {
        nodo *nuevo = CrearNodo(valor);
        *raiz = nuevo;
    }
    else
    {
        int r = (*raiz)->valor;
        if (r == valor)
        {
            cout << "\nValor existente\n";
        }
        else if (valor < r)
            AgregarNodo(&(*raiz)->izquierdo, valor);
        else
            AgregarNodo(&(*raiz)->derecho, valor);
    }
}

void eliminarNodo(nodo **raiz, int valor)
{
    if (valor > (*raiz)->valor)
        eliminarNodo(&(*raiz)->derecho, valor);
    if (valor < (*raiz)->valor)
        eliminarNodo(&(*raiz)->izquierdo, valor);
    if (valor == (*raiz)->valor)
    { // caso 1 nodo hoja
        if ((*raiz)->derecho == NULL && (*raiz)->izquierdo == NULL)
        {
            delete (*raiz);
            (*raiz) = NULL;
        }
        else if (((*raiz)->derecho == NULL || (*raiz)->izquierdo == NULL)) // caso 2 nodo padre de 1 hijo
        {
            nodo *aux;
            if ((*raiz)->derecho == NULL)
            {
                aux = (*raiz);
                (*raiz) = (*raiz)->izquierdo;
                delete aux;
            }
            else if ((*raiz)->izquierdo == NULL)
            {
                aux = (*raiz);
                (*raiz) = (*raiz)->derecho;
                delete aux;
            }
        }
        else if ((*raiz)->derecho != NULL && (*raiz)->izquierdo != NULL) // caso 3 padre de 2 hijos
        {
            int temp = encontrarMayor((*raiz)->izquierdo);
            eliminarNodo(raiz, temp);
            (*raiz)->valor = temp;
        }
    }
}

void eliminarArbol(struct nodo *&root)
{
    if (root == NULL)
        return;
    eliminarArbol(root->izquierdo);
    eliminarArbol(root->derecho);
    delete (root);
}

int encontrarMayor(struct nodo *raiz)
{
    int val, izq, derecho, maximo = 0;
    if (raiz != NULL)
    {
        val = raiz->valor;
        izq = encontrarMayor(raiz->izquierdo);
        derecho = encontrarMayor(raiz->derecho);
        if (izq > derecho)
            maximo = izq;
        else
            maximo = derecho;
        if (val > maximo)
            maximo = val;
    }
    return maximo;
}