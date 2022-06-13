/**
 * @file Ejercicio_EsGrafoConectado.c++
 * @author Juárez Jiménez Oscar Antonio,  Valdés Luis Eliot Fabián
 * @brief Archivo que contiene funciones para crear matrices asociadas dado un txt
 * @version 0.1
 * @date 2022-06-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

// creamos nuestra estructura
typedef struct MatrizAsociada
{
    int Bordes;
    int Vertices;
    int **matriz;
} MatrizAsociada;

MatrizAsociada *AsociarMatriz(int Ver, int Aristas, char **conexiones, map<char, int> map1)
{
    int i, u, v;

    // reservamos memoria
    MatrizAsociada *Grafo = (MatrizAsociada *)malloc(sizeof(MatrizAsociada));

    // si no hay grafo mostramos error
    if (Grafo == NULL)
    {
        printf("Error en la memoria");
        return NULL;
    }

    Grafo->Vertices = Ver;
    Grafo->Bordes = Aristas;
    // reservamos memoria
    Grafo->matriz = (int **)calloc(Grafo->Vertices, sizeof(int *));

    // recorremos todos los vertices y reservamos memoria para la matriz en indice x
    for (size_t i = 0; i < Grafo->Vertices; i++)
    {
        Grafo->matriz[i] = (int *)calloc(Grafo->Vertices, sizeof(int));
    }

    // establecemos nesutra matriz inicial de puros 0
    for (u = 0; u < Grafo->Vertices; u++)
    {
        for (v = 0; v < Grafo->Vertices; v++)
        {
            Grafo->matriz[u][v] = 0;
        }
    }

    // recorremos todas las aristas y cambiamos los valores
    for (i = 0; i < Grafo->Bordes; i++)
    {
        u = map1[conexiones[i][0]];
        v = map1[conexiones[i][1]];
        Grafo->matriz[u][v] = 1;
    }

    return Grafo;
}

void BuscarCaminosPosibles(struct MatrizAsociada *Grafo, int u, int *verticeConectado)
{
    verticeConectado[u] = 1;
    for (int v = 0; v < Grafo->Vertices; v++)
    {
        if (!verticeConectado[v] && Grafo->matriz[u][v] == 1)
        {
            BuscarCaminosPosibles(Grafo, v, verticeConectado);
        }
    }
}

int main()
{
    // creamos nuestro mapa para el grafo
    map<char, int> map1;
    // leemos neustro archivo
    FILE *texto__grafo = fopen("grafo_1def.txt", "rb");
    // si no se pudo abrir mostramos error
    if (texto__grafo == NULL)
    {
        perror("Error en la apertura del archivo");
        return 1;
    }

    char caracter;
    int v = 0, a = 0, cp = 0, fi = 0, col = 0;
    char *vertices;

    fscanf(texto__grafo, "%d", &v);
    vertices = (char *)calloc(v, sizeof(char));

    // leemos siempre y cuando no haya un salto de linea
    while (caracter != '\n')
    {
        caracter = fgetc(texto__grafo);
        if (caracter != ' ')
        {
            vertices[cp] = caracter;
            cp++;
        }

        printf("%c", caracter);
    }

    printf("%s", vertices);
    fscanf(texto__grafo, "%d", &a);

    printf("\n%d\n%d\n", v, a);

    char **aristas;
    aristas = (char **)calloc(a + 1, sizeof(char *));

    for (int i = 0; i < a + 1; i++)
    {
        aristas[i] = (char *)calloc(2, sizeof(char));
    }

    while (feof(texto__grafo) == 0)
    {
        caracter = fgetc(texto__grafo);
        if (caracter != '\n')
        {
            if (caracter != '-' && caracter != '\r')
            {
                aristas[fi][col] = (char)caracter;
                col++;
            }
        }
        else if (col != 0)
        {
            fi++;
            col = 0;
        }
        printf("%c", aristas[fi][col]);
    }

    for (int k = 0; k < v; k++)
    {
        map1[vertices[k]] = k;
    }

    for (int p = 0; p < a; p++)
    {
        for (int q = 0; q < 3; q++)
        {
            printf("%c", aristas[p][q]);
        }
        printf("\n");
    }

    rewind(texto__grafo);
    while (feof(texto__grafo) == 0)
    {
        caracter = fgetc(texto__grafo);
        printf("%c", caracter);
    }

    // terminamos la ledctura del archivo y mostramos el mensaje
    fclose(texto__grafo);
    printf("\nse ha leido el archive correctamente\n");

    MatrizAsociada *Grafo = AsociarMatriz(v, a, aristas, map1);

    for (int y = 0; y < v; y++)
    {
        printf("%c", vertices[y]);
    }

    printf("\n");
    for (int i = 0; i < Grafo->Vertices; i++)
    {
        for (int j = 0; j < Grafo->Vertices; j++)
        {
            printf("%d", Grafo->matriz[i][j]);
        }
        printf("%c", vertices[i]);
        printf("\n");
    }

    int *visita;
    bool esGrafoConectado = true;

    visita = (int *)calloc(Grafo->Vertices, sizeof(int));

    for (int y = 0; y < Grafo->Vertices; y++)
    {

        BuscarCaminosPosibles(Grafo, y, visita);
        for (int i = 0; i < Grafo->Vertices; i++)
        {
            if (visita[i] == 0)
                esGrafoConectado = false;
            printf("%d", visita[i]);
        }

        printf("\n");

        for (int i = 0; i < Grafo->Vertices; i++)
        {
            visita[i] = 0;
        }
    }

    if (esGrafoConectado)
    {
        printf("El grafo es conectado\n");
    }
    else
    {
        printf("El grafo es no conectado\n");
    }

    return 0;
}