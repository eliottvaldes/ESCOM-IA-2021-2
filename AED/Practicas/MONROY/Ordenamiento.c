/*
Monroy Fernández José Luis
2BV1
Inteligencia artificial
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge( int *, int, int, int);
void sort(int *, int, int);
void Quick(int*, int, int);


void merge(int *arrayNum, int numcad, int splitcad, int half)
{
    int string1 = (splitcad - numcad) + 1;
    int string2 = (half - splitcad);
    int *left, *right;
    // Memory asignation
    left = (int *)malloc(string1 * sizeof(int));
    right = (int *)malloc(string2 * sizeof(int));
    // Save dates of first part
    for (int i = 0; i < string1; i++)
    {
        left[i] = *(arrayNum + numcad + i);
    }
    for (int j = 0; j < string2; j++)
    {
        right[j] = *(arrayNum + splitcad + j + 1);
    }
    // merge
    int i = 0, j = 0;
    for (int k = numcad; k < half + 1; k++)
    {
        if (i == string1)
        {
            *(arrayNum + k) = *(right + j);
            j = j + 1;
        }
        else if (j == string2)
        {
            *(arrayNum + k) = *(left + i);
            i = i + 1;
        }
        else
        {
            if (*(left + i) <= *(right + j))
            {
                *(arrayNum + k) = *(left + i);
                i = i + 1;
            }
            else
            {
                *(arrayNum + k) = *(right + j);
                j = j + 1;
            }
        }
    }
}
void sort(int *ArrNum, int start, int end)
{
    if (start < end)
    {
        // split string
        int splitcad = (start + end) / 2;
        // slipt
        sort(ArrNum, start, splitcad);
        sort(ArrNum, splitcad + 1, end);
        // Merge
        merge(ArrNum, start, splitcad, end);
    }
}

void Quick(int *ptrCadenaNum, int inicio, int final)
{
    int tempini = inicio, tempfin = final, temp;
    int temparr = ptrCadenaNum[(inicio + final) / 2];
    do
    {
        while (ptrCadenaNum[tempini] < temparr && tempfin <= final)
        {
            tempini++;
        }
        while (temparr < ptrCadenaNum[tempfin] && tempfin > inicio)
        {
            tempfin--;
        }
        if (tempini <= tempfin)
        {
            temp = ptrCadenaNum[tempini];
            ptrCadenaNum[tempini] = ptrCadenaNum[tempfin];
            ptrCadenaNum[tempfin] = temp;
            tempini++;
            tempfin--;
        }
    } while (tempini <= tempfin);
    if (inicio < tempfin)
    {
        Quick(ptrCadenaNum, inicio, tempfin);
    }
    if (tempini < final)
    {
        Quick(ptrCadenaNum, tempini, final);
    }
}
void main()
{
    int opcionUsuario;
    int Range;
    int Caract;
    int *ptrCadenaNum;
    int posicion, minposition, temp, half;
    do
    {
        printf("\n\n");
        printf("-----------------------------------------");
        puts("\nSeleccione una opcion");
        puts("1.- Generar datos");
        puts("2.- Imprimir la ultima cadena registrada");
        puts("3.- Ordenar datos con Bubble");
        puts("4.- Ordenar datos con Insercion");
        puts("5.- Ordenar datos con Selection");
        puts("6.- Ordenar datos con Merge");
        puts("7.- Ordenar datos con Quick");
        puts("8.- Salir del programa");
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
            puts("Porfavor digite cuantos digitos habra en la cadena");
            fflush(stdin);
            scanf("%d", &Caract);
            puts("Porfavor digite el limite del rango para obtener los numeros aleatorios");
            fflush(stdin);
            scanf("%d", &Range);
            // Dinamic memory reservation
            ptrCadenaNum = malloc(Caract * sizeof(int));
            // Save numbers
            for (int i = 0; i < Caract; i++)
            {
                ptrCadenaNum[i] = rand() % Range;
            }
            printf("Cadena Generada con exito es: \n(");
            for (int i = 0; i < Caract; i++)
            {
                printf("%d, ", ptrCadenaNum[i]);
            }
            puts(")");
            break;
        case 2:
            // Print String
            printf("La utima serie registrada es: \n(");
            for (int i = 0; i < Caract; i++)
            {
                printf("%d, ", ptrCadenaNum[i]);
            }
            puts(")\n");
            break;
        case 3:
            // BUbble
            printf("Iniciando arreglo");
            for (int i = 0; i < Caract; i++)
            {
                for (int j = 0; j < Caract - i; j++)
                {
                    if (ptrCadenaNum[j] > ptrCadenaNum[j + 1])
                    {
                        int temp = ptrCadenaNum[j];
                        ptrCadenaNum[j] = ptrCadenaNum[j + 1];
                        ptrCadenaNum[j + 1] = temp;
                    }
                }
            }
            puts("\nOrden hecho correctamente");
            break;
        case 4:
            // Insercion
            printf("Iniciando arreglo");
            for (int i = 0; i < Caract; i++)
            {
                temp = i;
                posicion = ptrCadenaNum[i];
                while ((temp > 0) && (ptrCadenaNum[temp - 1] > posicion))
                {
                    ptrCadenaNum[temp] = ptrCadenaNum[temp - 1];
                    temp--;
                }
                ptrCadenaNum[temp] = posicion;
            }
            printf("\nOrdenamiento correcto");
            break;
        case 5:
            // Selection
            printf("Iniciando arreglo");
            for (int i = 0; i < Caract; i++)
            {
                minposition = i;
                for (int j = i + 1; j < Caract; j++)
                {
                    if (ptrCadenaNum[minposition] > ptrCadenaNum[j])
                    {
                        minposition = j;
                    }
                }
                // Swap
                temp = ptrCadenaNum[minposition];
                ptrCadenaNum[minposition] = ptrCadenaNum[i];
                ptrCadenaNum[i] = temp;
            }
            puts("\nOrden hecho correctamente");
            break;
        case 6:
            // Merge
            printf("Iniciando arreglo");
            int posini = 0;
            int posfin = Caract - 1;
            sort(ptrCadenaNum, posini, posfin);
            printf("\nOrdenamiento hecho");
            break;
        case 7:
            Quick(ptrCadenaNum, 0, Caract - 1);
            break;
        default:
            // End Of The Program
            puts("Fin del programa");
            break;
        }
    } while (opcionUsuario != 8);
}
