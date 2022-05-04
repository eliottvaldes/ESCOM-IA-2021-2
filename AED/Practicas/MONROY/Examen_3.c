#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char apellido1[20];
    char apellido2[20];
    char nombre[20];
} autor;

typedef struct
{
    int dia;
    char mes[12];
    int ano;
} fecha;

// TDA nivel 3
typedef struct
{
    autor libro;
    fecha publicacion;
    char editorial[20];
    char nombre[20];
    char nombreAutor;
} libro;

libro registrarlibro();
int bsuqeda(libro estanteria[], int, char);

void main()
{
    int opcionMenu;
    int librono = 0;
    libro estanteria[10];
    char apellido[20];
    int resultadobusqueda;
    int cantidad = 10;

    do
    {
        printf("\n\n");
        puts("Que desea hacer?");
        puts("1.- Registrar una nueva tienda");
        puts("2.- Imprimir los datos de la ultima tienda registrada");
        puts("3.- Buscar tienda por ID");
        puts("4.- Salir del programa");
        scanf("%d", &opcionMenu);
        switch (opcionMenu)
        {
        case 1:
            estanteria[librono] = registrarlibro(librono);
            librono++;
            break;
        case 2:
            puts("El ultimo libro registrado es:");
            printf("    Titulo: %d\n", estanteria[librono - 1].nombre);
            printf("    Editorial: %s\n", estanteria[librono - 1].editorial);
            printf("    Publicado el: %d / %s / %d\n", estanteria[librono - 1].publicacion.dia, estanteria[librono - 1].publicacion.mes, estanteria[librono - 1].publicacion.ano);
            printf("    Autor: %s %s %s", estanteria[librono - 1].libro.nombre, estanteria[librono - 1].libro.apellido1, estanteria[librono - 1].libro.apellido2);
            break;
        case 3:
            puts("Porfavor ingrese el apellido paterno del autor");
            scanf("%s", &apellido);
            fflush(stdin);
            resultadobusqueda = bsuqeda(estanteria, cantidad, apellido);
            imprimirBusqueda(estanteria, resultadobusqueda);
            break;
            break;
        case 4:
            puts("Saliendo del programa");
            exit(0);
            break;
        default:
            puts("Porafvor digite una opcion valida");
            break;
        }
    } while (opcionMenu != 4);
}

libro registrarlibro()
{
    libro nuevo;
    puts("Porfavor ingrese la editorial");
    scanf("%s", &nuevo.editorial);
    fflush(stdin);
    puts("porfavor ingrese el titulo del libro");
    scanf("%s", &nuevo.nombre);
    fflush(stdin);
    puts("ingrese el nombre del autor (Solo nombre)");
    scanf("%s", &nuevo.libro.nombre);
    fflush(stdin);
    puts("Ingrese el apellido paterno del autor");
    scanf("%s", &nuevo.libro.apellido1);
    puts("Ingrese el apellido paterno del autor");
    scanf("%s", &nuevo.libro.apellido2);
    fflush(stdin);
    puts("Ingrese el dia de la publicacion (Solo dia)");
    scanf("%d", &nuevo.publicacion.dia);
    fflush(stdin);
    puts("Ingrese el mes de la publicacion (solo mes)");
    scanf("%s", &nuevo.publicacion.mes);
    fflush(stdin);
    puts("Ingrese el año de la publicación");
    scanf("%d", &nuevo.publicacion.ano);
    return nuevo;
}

int bsuqeda(libro estanterias[], int cantidad, char apellido)
{
    bool noEncontrado = true;
    int i = 0;
    int indice = -1;
    while (i < cantidad && noEncontrado)
    {
        if (estanterias[i].libro.apellido1 == apellido)
            ;
        {
            noEncontrado = false;
            indice = i;
        }
        i++;
    }
    return (indice);
}
int imprimirBusqueda(libro estanterias[], int idbusqueda)
{
    if (idbusqueda >= 0)
    {
        puts("El ultimo libro registrado es:");
        printf("    Titulo: %d\n", estanterias[idbusqueda].nombre);
        printf("    Editorial: %s\n", estanterias[idbusqueda].editorial);
        printf("    Publicado el: %d / %s / %d\n", estanterias[idbusqueda].publicacion.dia, estanterias[idbusqueda].publicacion.mes, estanterias[idbusqueda].publicacion.ano);
        printf("    Autor: %s %s %s", estanterias[idbusqueda].libro.nombre, estanterias[idbusqueda].libro.apellido1, estanterias[idbusqueda].libro.apellido2);
        return 1;
    }
    printf("No hay nada por mostrar\n");
    return 0;
}