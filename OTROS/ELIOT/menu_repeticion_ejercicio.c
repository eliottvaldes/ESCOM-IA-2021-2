/**
 * @file menu sin repeticion con repeticion interna en cada ejercicio
 * @author VALDES LUIS ELIOT FABIAN
 * @brief plantilla de codigo de menu para ejercicios con repeticion interna
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

// ask for confirmation
bool asking()
{

    char askForRepetition = 'y';
    bool esRepetido = true;

    puts("\nPara repetir el ejercicio digita ' y '. Para regresar al menu digita ' n '.");
    scanf("%c", &askForRepetition);
    fflush(stdin);

    if (askForRepetition == 'y')
    {
        esRepetido = true;
    }
    else if (askForRepetition == 'n')
    {
        esRepetido = false;
    }
    else
    {
        printf("\nOpcion no valida, regresando a menu principal ");
        loading();
        puts("\n\n");
        esRepetido = false;
    }
    return esRepetido;
}

// main function
void main()
{
    int opcionSalir = 4; // varia de acuerdo a la cantidad de opciones
    int opcionSeleccionadaMenu;
    bool esEjercicioRepetido;

    // print greetings
    puts("**************************************");
    puts("Bienvenido");
    puts("**************************************");

    do
    {
        opcionSeleccionadaMenu = 0;
        esEjercicioRepetido = true;
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
            while (esEjercicioRepetido == true)
            {
                puts("\n\t *** Has seleccionado la opcion de x ***\n ");
                // Start Coding

                // End of Code

                // Ask for confirmation
                esEjercicioRepetido = asking();
            }
            break;

        case 2:
            while (esEjercicioRepetido == true)
            {
                puts("\n\t *** Has seleccionado la opcion de xx ***\n ");
                // Start Coding

                // End of Code

                // Ask for confirmation
                esEjercicioRepetido = asking();
            }

            break;

        case 3:
            while (esEjercicioRepetido == true)
            {
                puts("\n\t *** Has seleccionado la opcion de xxx ***\n ");
                // Start Coding

                // End of Code

                // Ask for confirmation
                esEjercicioRepetido = asking();
            }

            break;

        case 4:
            printf("\nSaliendo del programa :)");
            loading();
            exit(0);
            break;

        default:
            puts("Opcion no valida");
            break;
        }
    } while (opcionSeleccionadaMenu != opcionSalir);
}