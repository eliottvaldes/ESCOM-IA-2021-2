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

void lista_push( Nodo **, char );

void lista_pop(Nodo **);
void lista_top(Nodo *);
void lista_empty(Nodo *);
void lista_size(Nodo *);