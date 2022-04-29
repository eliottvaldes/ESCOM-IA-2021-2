#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ordenamiento(int *, int);
int diminirlong(int *, int);
int *eliminarRepeticion(int *, int);
int nuevolong(int);

void main()
{
    int opcionUsuario;
    int Caract;
    int *ptrCadenaNum;
    int *ptrCadenaNumSinRe;
    int nuevalong=0;
    do
    {
        printf("\n");
        printf("-----------------------------------------");
        puts("\nSeleccione una opcion");
        puts("1.- Llevar a cabo el ejercicio");
        puts("2.- Salir del programa");
        fflush(stdin);
        scanf("%d", &opcionUsuario);
        switch (opcionUsuario)
        {
        case 1:
            // Random Numbers
            // Clear memory
            free(ptrCadenaNum);
            // Random Seed
            srand(time(NULL));
            puts("Porfavor digite cuantos digitos habra en la cadena\n");
            fflush(stdin);
            scanf("%d", &Caract);
            // Dinamic memory reservation
            ptrCadenaNum = malloc(Caract * sizeof(int));
            // Save numbers
            for (int i = 0; i < Caract; i++)
            {
                ptrCadenaNum[i] = (rand() % 301) + 200;
            }
            ordenamiento(ptrCadenaNum, Caract);
            printf("Cadena Generada con exito es: \n");
            for (int i = 0; i < Caract; i++)
            {
                printf("%d, ", ptrCadenaNum[i]);
            }
            printf("\n");

            
            nuevalong = diminirlong(ptrCadenaNum, Caract);
            ptrCadenaNumSinRe=malloc(nuevalong*sizeof(int));

            ptrCadenaNumSinRe = eliminarRepeticion(ptrCadenaNum, Caract);
            printf("Cadena Generada con exito es: \n");
            for (int i = 0; i < nuevalong; i++)
            {
                printf("%d, ", ptrCadenaNumSinRe[i]);
            }
            break;
        case 2:
            puts("Saliendo del programa");
            exit(0);
            break;

        default:
            puts("Porfavor digite una opción valida");
            break;
        }
    } while (opcionUsuario != 2);
}

void ordenamiento(int *arrayNumerico, int extensionArreglo)
{
    for (int i = 0; i < extensionArreglo; i++)
    {
        int pos_menor = i;
        for (int j = i + 1; j < extensionArreglo; j++)
        {
            if (arrayNumerico[j] < arrayNumerico[pos_menor])
            {
                pos_menor = j;
            }
        }
        int temp = arrayNumerico[pos_menor];
        arrayNumerico[pos_menor] = arrayNumerico[i];
        arrayNumerico[i] = temp;
    }
}
int diminirlong(int *arrayNumerico, int extensionArreglo)
{
    int posicionnueva = 0;
    int longi = 0;
    int nuevalong = 0;
    for (int i = 0; i < extensionArreglo; i++)
    {
        if (arrayNumerico[i] != arrayNumerico[i + 1])
        {
            longi++;
        }
    }
    return longi;
}

int *eliminarRepeticion(int *arrayNumerico, int extensionArreglo)
{
    int *nuevalista;
    int posicionnueva = 0;
    int longi = extensionArreglo;
    int *nuevalong;

    nuevalista = malloc(extensionArreglo * sizeof(int));

    for (int i = 0; i < extensionArreglo; i++)
    {
        if (arrayNumerico[i] != arrayNumerico[i + 1])
        {
            nuevalista[posicionnueva] = arrayNumerico[i];
            posicionnueva++;
            longi--;
        }
    }
    return nuevalista;
}