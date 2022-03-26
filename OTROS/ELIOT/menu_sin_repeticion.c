/**
 * @file menu sin repeticion interna de ejercicios
 * @author VALDES LUIS ELIOT FABIAN
 * @brief plantilla de codigo de menu sin repeticion interna por ejercicio
 * @version 0.1
 * @date 2022-03-03
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// print animation
int sleep();
void loading()
{
    printf("[");
    for (int i = 0; i < 3; i++)
    {
        printf("#");
        // usar si no se quiere mostrar la animacion
        // sleep(1 / 2);
        sleep(1);
    }
    printf("]");
}

// main function
void main()
{
    int opcionSalir = 4; // varia de acuerdo a la cantidad de opciones
    int opcionSeleccionadaMenu;

    // print greetings
    puts("**************************************");
    puts("Bienvenido");
    puts("**************************************");

    do
    {
        opcionSeleccionadaMenu = 0;
        // print Menu
        puts("--------------------------------------");
        puts("Digita la opcion que deseas realizar:");
        puts("1.- OPx");
        puts("2.- OPx");
        puts("3.- OPx");
        puts("X.- Salir");
        puts("--------------------------------------");
        scanf("%d", &opcionSeleccionadaMenu);
        fflush(stdin);

        switch (opcionSeleccionadaMenu)
        {

        case 1:

            puts("\n\t *** Has seleccionado la opcion de x ***\n ");
            // Start Coding

            // End of Code

            break;

        case 2:

            puts("\n\t *** Has seleccionado la opcion de xx ***\n ");
            // Start Coding

            // End of Code

            break;

        case 3:

            puts("\n\t *** Has seleccionado la opcion de xxx ***\n ");
            // Start Coding

            // End of Code

            break;

        case 4:
            printf("\nSALIENDO DEL PROGRAMA ");
            loading();
            puts("\n *** ADIOS *** :)");
            exit(0);
            break;

        default:
            puts("Opcion no valida");
            break;
        }
    } while (opcionSeleccionadaMenu != opcionSalir);
}