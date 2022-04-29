/*
    Monroy Fernandez Jose Luis
    2BV1
    Inteliencia Artificial
*/

#include <iostream>

using namespace std;

struct Nodo
{
    char caracter;
    Nodo *sig;
};
void push_Nodo(Nodo *nuevo, char caracter)
{
    nuevo->caracter = caracter;
    nuevo->sig = NULL;
}
void lista_push(Nodo **lista, char caracter)
{
    Nodo *nuevo = new Nodo;
    push_Nodo(nuevo, caracter);
    if (*lista == NULL)
    {
        *lista = nuevo;
    }
    else
    {
        nuevo->sig = *lista;
        *lista = nuevo;
    }
}

void lista_pop(Nodo **lista)
{
    Nodo *aux = *lista;
    *lista = (*lista)->sig;
    delete aux;
}
char lista_top(Nodo *lista)
{
    return lista->caracter;
}
int lista_empty(Nodo *lista)
{
    int tam = 0;
    Nodo *itera = lista;
    while (itera != NULL)
    {
        itera = itera->sig;
        tam++;
    }
    return tam;
}

int lista_size(Nodo *lista)
{
    int tam = 0;
    Nodo *itera = lista;
    while (itera != NULL)
    {
        itera = itera->sig;
        tam++;
    }
    return tam;
}