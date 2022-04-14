
#include "TDAPract1_Philip.h"


void CrearTDA(int valor1, int valor2, TDA* TDACreado){
    TDACreado->valor1=valor1;
    TDACreado->valor2=valor2;
    //return TDACreado;
}

bool EliminarTDA(TDA* TDACreado){
    free((void *)TDACreado->valor1);
    free((void *)TDACreado->valor2);
    return true;
}

void ImprimirTDA(TDA TDACreado){
    printf("El valor 1 en el TDA es: %d\n\n", TDACreado.valor1);
    printf("El valor 2 en el TDA es: %d\n\n", TDACreado.valor2);
}

void CopiarTDA(TDA TDACreado, TDA* TDACopia){
    TDACopia->valor1=TDACreado.valor1;
    TDACopia->valor2=TDACreado.valor2;
}
