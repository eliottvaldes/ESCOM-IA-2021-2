#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int noBolsas;
    float precio;
    char marca[30];
    int disponibilidad;
} mochila;

// TDA nivel 3
typedef struct
{
    char sucursal[30];
    mochila escolar;
    char empleado[20];
    int idTienda;
} tienda;

tienda RegistrarTienda();
void ordenarDatos(int *, int);
int busquedaBinaria(int *, int, int);
int imprimirBusqueda(int , tienda usuario[]);

void main()
{
    int opcionMenu;
    int noTienda = 0;
    int *ptrTienda;
    int numeroBusqueda;
    int tiendaBusqueda;
    tienda usuario[10];
    free(ptrTienda);
    ptrTienda = malloc(50 * sizeof(int));

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
            usuario[noTienda] = RegistrarTienda(noTienda);
            ptrTienda[noTienda] = usuario[noTienda].idTienda;
            noTienda++;
            break;
        case 2:
            puts("La ultima tienda registrada es:");
            printf("    ID: %d\n", usuario[noTienda-1].idTienda);
            printf("    Sucursal: %s\n", usuario[noTienda-1].sucursal);
            printf("    Empleado: %s\n", usuario[noTienda-1].empleado);
            /*
            printf("    Marca: %s", usuario[noTienda].escolar.marca);
            printf("    Precio: %.2f", usuario[noTienda].escolar.noBolsas);
            printf("    No de bolsas: %d", usuario[noTienda].escolar.noBolsas);
            printf("    Disponibilidad: %d", usuario[noTienda].escolar.disponibilidad);
            */
            break;
        case 3:
            ordenarDatos(ptrTienda, noTienda - 1);
            puts("Porfavor digite el ID de la tienda que desea buscar");
            scanf("%d", &numeroBusqueda);
            tiendaBusqueda = busquedaBinaria(ptrTienda, noTienda, numeroBusqueda);
            imprimirBusqueda(tiendaBusqueda, usuario);
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

tienda RegistrarTienda()
{
    tienda usuario;
    puts("Porfavor digite el ID de la tienda:");
    scanf("%d", &usuario.idTienda);
    fflush(stdin);
    puts("Porfavor ingrese el nombre del empleado de la tienda:");
    scanf("%s", &usuario.empleado);
    fflush(stdin);
    puts("Porfavor ingrese el nombre de la tienda:");
    scanf("%s", &usuario.sucursal);
    fflush(stdin);
    puts("Porfavor ingrese la amrca de la mochila:");
    scanf("%s", &usuario.escolar.marca);
    fflush(stdin);
    puts("Porfavor ingrese cuantas mochilas hay:");
    scanf("%d", &usuario.escolar.disponibilidad);
    fflush(stdin);
    puts("Porfavor digite el numero de bolsas de la mochila:");
    scanf("%d", &usuario.escolar.noBolsas);
    fflush(stdin);
    puts("Porfavor digite el precio de la mochila:");
    scanf("%f", &usuario.escolar.precio);
    fflush(stdin);
    return usuario;
}

void ordenarDatos(int *cadenaNum, int limite)
{
    for (int i = 0; i < limite; i++)
    {
        int position = i;
        for (int j = i + 1; j < limite; j++)
        {
            if (cadenaNum[position] > cadenaNum[j])
            {
                position = j;
            }
        }
        // Swap
        int temp = cadenaNum[position];
        cadenaNum[position] = cadenaNum[i];
        cadenaNum[i] = temp;
    }
}

int busquedaBinaria(int *arreglo, int longitud, int numeroBusqueda)
{
    int min = 0;
    int max = (longitud - 1);
    while (min <= max)
    {
        int middle = ((max - min) / 2) + min;
        if (arreglo[middle] == numeroBusqueda)
        {
            printf("La tienda %d esta en los datos registrados\n", numeroBusqueda);
            return middle;
        }
        else
        {
            if (numeroBusqueda < arreglo[middle])
            {
                max = middle - 1;
            }
            else
            {
                min = middle + 1;
            }
        }
    }
    printf("La tienda %d no se encuentra en los datos registrados\n", numeroBusqueda);
    return -1;
}
int imprimirBusqueda(int idbusqueda, tienda usuario[])
{
    if (idbusqueda >= 0)
    {
        printf("    ID: %d\n", usuario[idbusqueda].idTienda);
        printf("    Sucursal: %s\n", usuario[idbusqueda].sucursal);
        printf("    Empleado: %s\n", usuario[idbusqueda].empleado);
        return 1;
    }
    printf("No hay nada por mostrar\n");
    return 0;
}
