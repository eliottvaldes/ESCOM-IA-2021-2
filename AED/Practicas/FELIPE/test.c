#include "TDAPract1_Philip.h"
int main(){
    int valor1=0,valor2=0;
    puts("Cree su TDA con los valores 1 y 2 de tipo entero");
    puts("Ingrese el valor 1");
    scanf("%d", &valor1);
    puts("Ingrese el valor 2");
    scanf("%d", &valor2);
    TDA TDACreado;
    CrearTDA(valor1,valor2, &TDACreado);
    ImprimirTDA(TDACreado);
    TDA TDACopia;
    CopiarTDA(TDACreado, &TDACopia);
    ImprimirTDA(TDACopia);
    EliminarTDA(&TDACreado);
    //ImprimirTDA(TDACreado);
    return 0;
}

//Compilación:  gcc miLibreria.h miLibreria.c test.c -O3 -o programa