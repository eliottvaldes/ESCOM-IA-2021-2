/**
 * @file ordenamiento.c
 * @author VALDES LUIS ELIOT FABIÁN
 * @brief Archivo con algoritmos de ordenamiento
 * @version 0.1
 * @date 2022-02-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// print animation
int sleep();
int time();
void animacion()
{
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        sleep(1);
    }
    puts("\n");
}

// CREAMOS PROTOTIPOS DE FUNCIONES
int *generarArrayNumerosAleatorios(int, int);
void mostrarDatosEnArreglo(int *, int, int);
void ordenamientoBurbuja(int *, int);
void ordenamientoInsercion(int *, int);
void ordenamientoSeleccion(int *, int);
void ordenamientoMergeSort_division(int *, int, int);
void ordenamientoMerge_union(int *, int, int, int);
void ordenamientoQuickSort(int *, int, int);

// funcion para creacion de numeros aleatorios
int *generarArrayNumerosAleatorios(int extensionDeArreglo, int rangoDeArreglo)
{

    int *arrayNumerico = malloc(extensionDeArreglo * sizeof(int));

    for (int i = 0; i <= extensionDeArreglo; i++)
    {
        // creamos numeros aleatorios y los vamos agregando al array
        arrayNumerico[i] = rand() % rangoDeArreglo;
    }

    return arrayNumerico;
}

// funcion para ver los numeros aleatorios
void mostrarDatosEnArreglo(int *arrayNumerico, int extensionDeArreglo, int i)
{
    if (i == (extensionDeArreglo - 1))
    {
        printf("%d. \n\n", arrayNumerico[i]);
    }
    else
    {
        printf("%d, ", arrayNumerico[i]);
    }
}

// funcion para ordenamiento de burbuja
void ordenamientoBurbuja(int *arrayNumerico, int extensionDeArreglo)
{
    for (int i = 0; i < extensionDeArreglo; i++)
    {
        // recorremos los elementos x veces en el arreglo - i
        for (int j = 0; j < (extensionDeArreglo - i); j++)
        {
            // hacemos la comparacion
            if (arrayNumerico[j] > arrayNumerico[j + 1])
            {
                // hacemos el intercambio de valores
                int temp = arrayNumerico[j];
                arrayNumerico[j] = arrayNumerico[j + 1];
                arrayNumerico[j + 1] = temp;
            }
        }
    }
}

// funcion para ordenamiento insercion
void ordenamientoInsercion(int *arrayNumerico, int extensionDeArreglo)
{
    for (int i = 0; i < extensionDeArreglo; i++)
    {

        int temp = arrayNumerico[i];
        int j = (i - 1);
        while ((arrayNumerico[j] > temp) && (j >= 0))
        {
            arrayNumerico[j + 1] = arrayNumerico[j];
            j--;
        }
        arrayNumerico[j + 1] = temp;
    }
}

// funcion para ordenamiento de Seleccion
void ordenamientoSeleccion(int *arrayNumerico, int extensionDeArreglo)
{
    for (int i = 0; i < extensionDeArreglo; i++)
    {
        int pos_menor = i;
        // buscamos el valor menor
        for (int j = i + 1; j < extensionDeArreglo; j++)
        {
            // comparamos el valor de la pos j  para ver si es menor
            if (arrayNumerico[j] < arrayNumerico[pos_menor])
            {
                // cambiamos la pos_menor por el valor menor que es j
                pos_menor = j;
            }
        }
        // realizamos el cambio de valores
        int temp = arrayNumerico[pos_menor];
        arrayNumerico[pos_menor] = arrayNumerico[i];
        arrayNumerico[i] = temp;
    }
}

// funcion para ordenamiento de Quick Sort
void ordenamientoQuickSort(int *arrayNumerico, int primerElemento, int ultimoElemento)
{
    // asignamos la posicion de inicio y la final con la que se va a iterar el ciclo
    int posicionInicio = primerElemento;
    int posicionFinal = ultimoElemento;
    // variable para intercambios
    int tmp;
    // variable para obtener el valor medio
    int valorIntermedio = arrayNumerico[(primerElemento + ultimoElemento) / 2];
    // usamos do-while para iniciar con una ejecucion antes de parar si es el caso
    do
    {
        // recorremos el numerico solo si el valor de la pos i es menor a x y el f es <= a final
        // f <= final se va a cumplir siempre en la primer iteracion
        while ((arrayNumerico[posicionInicio] < valorIntermedio) && (posicionFinal <= ultimoElemento))
        {
            // incrementamos el contador de inicio
            posicionInicio++;
        }
        while ((valorIntermedio < arrayNumerico[posicionFinal]) && (posicionFinal > primerElemento))
        {
            // decrementamos el contador de final
            posicionFinal--;
        }
        // hacemos la comparacion para intercambiar lso valores en caso de ser necesario
        if (posicionInicio <= posicionFinal)
        {
            // hacemos el intercambio SWAP
            tmp = arrayNumerico[posicionInicio];
            arrayNumerico[posicionInicio] = arrayNumerico[posicionFinal];
            arrayNumerico[posicionFinal] = tmp;
            // incrementamos inicio y decrementamos el final
            posicionInicio++;
            posicionFinal--;
        }
    } while (posicionInicio <= posicionFinal); // evaluamos el do para ver si se repite o no

    // hacemos la comparacion para ver que aprametros le pasamos a nuestra misma funcion
    if (primerElemento < posicionFinal)
    {
        // usamos la recursividad para que se siga ejecutando el ordenamiento cambiando la variable del final
        ordenamientoQuickSort(arrayNumerico, primerElemento, posicionFinal);
    }
    // hacemos la comparacion para ver que aprametros le pasamos a nuestra misma funcion
    if (posicionInicio < ultimoElemento)
    {
        // usamos la recursividad para que se siga ejecutando el ordenamiento cambiando la variable del inicio
        ordenamientoQuickSort(arrayNumerico, posicionInicio, ultimoElemento);
    }
}

// funcion para ordenamiento Merge (union de las partes)
void ordenamientoMerge_union(int *arrayNumerico, int posicionDePartida, int posicionIntermedia, int posicionDeFinalizacion)
{
    // creamos nuestras variables
    int i;
    int j;
    int k;
    // obtenemos la longitud de los arreglos
    int longitudArregloIzquierdo = (posicionIntermedia - posicionDePartida) + 1;
    int longitudArregloDerecho = (posicionDeFinalizacion - posicionIntermedia);
    int *bloqueIzquierdo, *bloqueDerecho;

    // asignamos la memoria dinamica a los arreglos
    bloqueIzquierdo = (int *)malloc(longitudArregloIzquierdo * sizeof(int));
    bloqueDerecho = (int *)malloc(longitudArregloDerecho * sizeof(int));

    // copiamos datos de arrayNumerico en subarreglos / subgrupos bloqueIzquierdo y bloqueDerecho
    // creamos el bloque izquierdo
    for (i = 0; i < longitudArregloIzquierdo; i++)
    {
        bloqueIzquierdo[i] = *(arrayNumerico + posicionDePartida + i);
    }
    // creamos el bloque derecho
    for (j = 0; j < longitudArregloDerecho; j++)
    {
        bloqueDerecho[j] = *(arrayNumerico + posicionIntermedia + j + 1);
    }

    i = 0;
    j = 0;

    // realizamos la union de los dos subgrupos de la division merge
    for (k = posicionDePartida; k < posicionDeFinalizacion + 1; k++)
    {
        if (i == longitudArregloIzquierdo)
        {
            *(arrayNumerico + k) = *(bloqueDerecho + j);
            j = j + 1;
        }
        else if (j == longitudArregloDerecho)
        {
            *(arrayNumerico + k) = *(bloqueIzquierdo + i);
            i = i + 1;
        }
        else
        {
            if (*(bloqueIzquierdo + i) <= *(bloqueDerecho + j))
            {
                *(arrayNumerico + k) = *(bloqueIzquierdo + i);
                i = i + 1;
            }
            else
            {
                *(arrayNumerico + k) = *(bloqueDerecho + j);
                j = j + 1;
            }
        }
    }
}

// funcion para ordenamiento Merge (division del array)
void ordenamientoMergeSort_division(int *arrayNumerico, int posicionDePartida, int posicionDeFinalizacion)
{
    // verificamos que asdasd sea menor a asdasd
    if (posicionDePartida < posicionDeFinalizacion)
    {
        // dividimos el arreglo a la mitad
        int posicionIntermedia = (posicionDePartida + posicionDeFinalizacion) / 2;

        // usamos la recursividad del arreglo para crear los subgrupos
        ordenamientoMergeSort_division(arrayNumerico, posicionDePartida, posicionIntermedia);
        ordenamientoMergeSort_division(arrayNumerico, posicionIntermedia + 1, posicionDeFinalizacion);

        // hacemos la union de los subgrupos
        ordenamientoMerge_union(arrayNumerico, posicionDePartida, posicionIntermedia, posicionDeFinalizacion);
    }
}

// main function
void main()
{

    // excersice variables
    int extensionDeArreglo = 0;
    int rangoDeArreglo = 0;
    int *arrayNumerico;
    bool showMenu = true;
    int j;

    // print greetings
    puts("**************************************");
    puts("Bienvenido");
    puts("**************************************");
    while (showMenu == true)
    {
        // menu variables
        bool repeatExercise = true;
        char askForRepetition;
        int exerciseSelection;

        // show Menu
        puts("--------------------------------------");
        puts("Digita la opcion que deseas realizar:");
        puts("1.- Generar array de numeros aleatorios");
        puts("2.- Imprimir datos");
        puts("3.- Ordenamiento por Burbuja");
        puts("4.- Ordenamiento por Insercion");
        puts("5.- Ordenamiento por Seleccion");
        puts("6.- Ordenamiento por Merge");
        puts("7.- Ordenamiento por Quick Sort");
        puts("8.- Salir");
        puts("--------------------------------------");
        fflush(stdin);
        scanf("%d", &exerciseSelection);

        switch (exerciseSelection)
        {
        case 1:

            puts("\nHas seleccionado la opcion de generar array de numeros aleatorios\n");
            // Start Coding

            // liberamos memoria del arreglo dinamico usando free
            free(arrayNumerico);

            // pedimos la cantidad de numeros en el array
            puts("Digita la cantidad de numeros que quieres en el array");
            fflush(stdin);
            scanf("%d", &extensionDeArreglo);

            // pedimos el rango para la generacion de numeros aleatorios
            puts("Digita el rango superior para los numeros del arreglo");
            fflush(stdin);
            scanf("%d", &rangoDeArreglo);
            fflush(stdin);

            // creamos semilla para generacion de numeros random
            // usamos srand(time()); para no obtener los mismos numeros aleatorios en cada ejecucion ya que la semilla es la hora actual
            srand(time(NULL));

            // mandamos a llamar a la funcion de crear numeros de datos aleatorios
            arrayNumerico = generarArrayNumerosAleatorios(extensionDeArreglo, rangoDeArreglo);

            // mostramos mensaje de exito
            puts("\n*** Arreglo generado exitosamente ***\n");

            // End of Code

            break;

        case 2:

            puts("\nHas seleccionado la opcion de imprimir datos\n");
            // Start Coding

            // verificamos que el usuario ya haya creado un arredo de datos numericos aleatorios
            if (extensionDeArreglo > 0)
            {
                for (int i = 0; i < extensionDeArreglo; i++)
                {
                    mostrarDatosEnArreglo(arrayNumerico, extensionDeArreglo, i);
                }
            }
            else
            {
                puts("\n*** Aun no has generado un arreglo de numeros aleatorios *** \n");
            }

            // End of Code

            break;

        case 3:

            puts("\nHas seleccionado ordenamiento por burbuja\n");
            // Start Coding

            // mostramos mensaje
            printf("Iniciando ordenamiento burbuja ");
            animacion();

            // ejecutamos funcion del ordenamiento burbuja
            ordenamientoBurbuja(arrayNumerico, extensionDeArreglo);

            puts("*** Ordenamiento completado ***\n");

            // End of Code

            break;

        case 4:

            puts("\nHas seleccionado ordenamiento por insercion\n");
            // Start Coding

            printf("Iniciando ordenamiento insercion ");
            animacion();

            // ejecutamos funcion del ordenamiento insercion
            ordenamientoInsercion(arrayNumerico, extensionDeArreglo);

            puts("*** Ordenamiento completado ***\n");

            // End of Code

            break;

        case 5:

            puts("\nHas seleccionado ordenamiento por seleccion\n");
            // Start Coding

            printf("Iniciando ordenamiento seleccion ");
            animacion();

            // ejecutamos funcion del ordenamiento insercion
            ordenamientoSeleccion(arrayNumerico, extensionDeArreglo);

            puts("*** Ordenamiento completado ***\n");

            // End of Code

            break;

        case 6:

            puts("\nHas seleccionado ordenamiento por merge\n");
            // Start Coding

            printf("Iniciando ordenamiento merge ");
            animacion();

            // iniciamos codigo para el algoritmo de Merge

            int posicionDePartida = 0;
            int posicionDeFinalizacion = extensionDeArreglo - 1;
            // ejecutamos la funcion del ordenamiento Merge
            ordenamientoMergeSort_division(arrayNumerico, posicionDePartida, posicionDeFinalizacion);

            puts("*** Ordenamiento completado ***\n");
            // End of Code

            break;

        case 7:

            puts("\nHas seleccionado ordenamiento por Quick Sort\n");
            // Start Coding

            printf("Iniciando ordenamiento Quick Sort ");
            animacion();

            // siempre tomamos el primer elemento el que se encuentra en la pos 0
            int primerElemento = 0;
            // siempre tomamos el primer elemento el que se encuentra en la pos long arreglo -1 para mantenernos en el for
            int ultimoElemento = extensionDeArreglo - 1;

            // ejecutamos funcion del ordenamiento quick sort
            ordenamientoQuickSort(arrayNumerico, primerElemento, ultimoElemento);

            puts("*** Ordenamiento completado ***\n");

            // End of Code

            break;

        case 8:
            printf("\nSaliendo del programa ");
            animacion();
            puts("\n *** ADIOS *** :)");
            showMenu = false;
            break;

        default:
            puts("Opcion no valida");
            showMenu = true;
            exerciseSelection = 0;
            break;
        }
    }
}