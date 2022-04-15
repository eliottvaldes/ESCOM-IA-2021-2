#include<stdio.h>

typedef struct{
    int valor;
}Generico;
typedef struct{
    Generico DatoG;
}Dato;

void ordenamientoInsercion(Dato *arreglo, int tam);

int main (void){
    Dato arreglo[4];
    puts("Ingresa el primer digito: ");
    scanf("%d", &arreglo[0]);
    puts("Ingresa el segundo digito: ");
    scanf("%d", &arreglo[1]);
    puts("Ingresa el tercer digito: ");
    scanf("%d", &arreglo[2]);
    puts("Ingresa el cuarto digito: ");
    scanf("%d", &arreglo[3]);

    
    puts("Los numeros a ordenar son:");
    for ( int k = 0; k < 4; k++)
    {
        printf("%d ", arreglo[k]);
    }
    puts("\n");
    
    ordenamientoInsercion(arreglo, 4);

       puts("Los numeros ordenados son:");
    for ( int k = 0; k < 4; k++)
    {
        printf("%d ", arreglo[k]);
    }
    puts("\n");
}

void ordenamientoInsercion(Dato *arreglo, int tam){
    int i,j;
    Dato pivote; 
    for(i=1; i<tam; i++){
        pivote=arreglo[i];
        j=i-1;
        while (j>=0 && arreglo[j].DatoG.valor>pivote.DatoG.valor){
            arreglo[j+1]=arreglo[j];
            /*EEHH para el segundo ciclo tambn se le baja
            a J-1 por lo que no seria i eso no mamon*/
            j=j-1;
        }
        /*EEHH wacha que se le bajo a J=-1 en el primer ciclo,
        entonces j+1 seria el lugar 0*/
        arreglo[j+1]=pivote;
    }
}


