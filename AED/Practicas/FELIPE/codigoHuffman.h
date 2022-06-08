#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int frecuencia;
    char caracter;
} Dato;

typedef struct nodo{
    Dato info;
    struct nodo *izq,*der;
} Elemento_De_Arbol_Binario;

typedef Elemento_De_Arbol_Binario* Arbol;

//Prototipo de funciones de arboles
Arbol crearNodo(Dato valor); //Genera al nodo raiz de un árbol
void nuevoArbol(Arbol* raiz,Arbol Hizq, Arbol Hder, Dato valor);
int profundidadArbol(Arbol raiz);
void contarHojas(Arbol raiz, int* contadorHojas);
void preOrden(Arbol raiz);
void posOrden(Arbol raiz);
void inOrden(Arbol raiz);
void eliminarArbol(Arbol* raiz);
void buscarNodo(Arbol raiz, Dato valor, Arbol* nodoEncontrado);
void eliminarNodo(Arbol* raiz, Dato valor);
void ingresarNodo(Arbol* raiz, Dato valor);
void reemplazar(Arbol* nodo);
Arbol nodoMinimo(Arbol node);
Arbol deleteNodeBST(Arbol raiz, Dato valor);
void iniciaOperacion(int argc, char** argv);
void asignaCodigo(Arbol r, int c[], int n);
void ordenar(Arbol* arreglo, int tam);