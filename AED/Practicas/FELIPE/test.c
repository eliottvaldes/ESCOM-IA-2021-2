#include "arbolBST.h"

void iniciaOperacion(int argc, char** argv){
	//Se creara un arbol con el siguiente orden de datos: 1,7,8,10,15,1,13,5,7,25,689
	
	//Se crea un arbol vacío
	Arbol raiz=NULL;
	Dato valorUser=1;
	puts("Iniciando ingreso de datos");
	ingresarNodo(&raiz, valorUser);
	valorUser=7;
	ingresarNodo(&raiz, valorUser);
	valorUser=8;
	ingresarNodo(&raiz, valorUser);
	valorUser=10;
	ingresarNodo(&raiz, valorUser);
	valorUser=15;
	ingresarNodo(&raiz, valorUser);
	valorUser=4;
	ingresarNodo(&raiz, valorUser);	
	valorUser=13;
	ingresarNodo(&raiz, valorUser);
	valorUser=5;
	ingresarNodo(&raiz, valorUser);
	valorUser=7;
	ingresarNodo(&raiz, valorUser);
	valorUser=25;
	ingresarNodo(&raiz, valorUser);
	valorUser=689;
	ingresarNodo(&raiz, valorUser);
	puts("Imprimiendo in orden");
	//Se confirma el ordenamiento natural del arbol
	inOrden(raiz);
	puts("\nImpresión pos-Orden:");
	posOrden(raiz);
	puts("\nImpresión pre-orden");
	preOrden(raiz);
	
	//Buscando un nodo 7:
	Arbol nodoEncontrado=NULL;
	buscarNodo(raiz,7, &nodoEncontrado);
	if(!nodoEncontrado)
		puts("Nodo no encontrado");
	else
		printf("\nSe encontro el nodo con el valor %d\n", nodoEncontrado->info);
	
	//Eliminando nodo 13
	raiz=deleteNodeBST(raiz,7);
	puts("\nImprimiendo in orden sin el nodo eliminado");
	//Se valida la eliminación
	inOrden(raiz);
	
	//Eliminando arbol
	eliminarArbol(&raiz);
	puts("\nSe elimina arbol");
	puts("\nImpresión pos-Orden:");
	posOrden(raiz);
}

void main(int argc, char** argv){
	iniciaOperacion(argc, argv);
}