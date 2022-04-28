#include <stdio.h>
#include <stdbool.h>

// TDA nivel 2
typedef struct
{
    int noNolsas;
    float precio;
    char marca[30];
    bool disponibilidad;
} mochila;

// TDA nivel 3
typedef struct
{
    char sucursal[30];
    mochila escolar;
    char empleado[20];
    int caja;
} tienda;

void main()
{
    // asignamos valores a el TDA
    tienda laEsquina = {
        "Zona Centro",
        {2, 851.00, "Willi", true},
        "Juanito",
        2};

    printf("Bienvenido a la tienda La Esquina, sucursal %s \n", laEsquina.sucursal);
    puts("--------------------------------------------------");
    printf(" Lo atendió : %s                    Caja: %d\n", laEsquina.empleado, laEsquina.caja);
    printf("Articulos:\n");
    printf("    Mochila marca %s\n", laEsquina.escolar.marca);
    printf("        Cantidad de bolsas: %d\n", laEsquina.escolar.noNolsas);
    printf("        Disponibilidad: ");
    if (laEsquina.escolar.disponibilidad == true)
    {
        printf("Si hay en la tienda\n");
    }
    else
    {
        printf("Solo en linea\n");
    }
    printf("        Precio: %.2f\n", laEsquina.escolar.precio);
}
