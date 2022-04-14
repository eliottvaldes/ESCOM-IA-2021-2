/*
Importación de librerias estándar, macros, declaración de estructuras, tda, variables globales y prototipo de funciones.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct{
    int valor1;
    int valor2;
} TDA;

void CrearTDA(int valor1, int valor2, TDA* TDACreado);
bool EliminarTDA(TDA* TDACreado);
void ImprimirTDA(TDA TDACreado);
void CopiarTDA(TDA TDACreado, TDA* TDACopia);
