/* 
Monroy Fernandez Jose Luis
2BV1
Inteliencia Artificial
*/
#include <stdio.h>

typedef struct
{
    char nombre[30];
    float duracion;
    char genero[15];
    char director[30];
    char clasificacion[5];
    int year;
} Pelicula;

int main()
{
    int opcionusuario;
    // Instancia TDA
    Pelicula nueva;
    do
    {
        puts("Que desea hacer?");
        puts("1-. Registrar pelicula");
        puts("2-. Mostrar ultima pelicula");
        puts("3.- Salir del programa");
        fflush(stdin);
        scanf("%d", &opcionusuario);
        switch (opcionusuario)
        {
            case 1:
                // Obtener datos de la pelicula
                puts("Inserte el nombre de la pelicula");
                fflush(stdin);
                scanf("%s", &nueva.nombre);
                puts("Inserte la duracion de la pelicula");
                fflush(stdin);
                scanf("%f", &nueva.duracion);
                puts("Inserte el genero de la película");
                fflush(stdin);
                scanf("%s",&nueva.genero);
                puts("Inserte el nombre del director");
                fflush(stdin);
                scanf("%s",&nueva.director);
                puts("Inserte la clasificacion");
                fflush(stdin);
                scanf("%s",&nueva.clasificacion);
                puts("Ingrese el año");
                fflush(stdin);
                scanf("%d",&nueva.year);
            break;

            case 2:
                // Imprimir datos de la ultima pelicula
                printf("Nombre de la pelicula: %s\n", nueva.nombre);
                printf("Duracion de la pelicula: %f\n", nueva.duracion);
                printf("Genero de la película: %s\n",nueva.genero);
                printf("Nombre del director: %s\n",nueva.director);
                printf("Casificacion: %s\n",nueva.clasificacion);
                printf("Año: %d\n",nueva.year);
            break;
            default:
                //Finalizar todo
                puts("Fin del programa");
            break;
        }
    } while (opcionusuario != 3);
}