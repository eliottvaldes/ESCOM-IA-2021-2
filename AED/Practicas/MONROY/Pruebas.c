#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int CadenaNum[4] = {4, 2, 9, 10};
    int Caract = 4;
    int temp, aux;
    for (int i = 0; i < 4; i++)
    {
        temp = i;
        aux = CadenaNum[i];
        while ((temp > 0) && (CadenaNum[temp - 1] > aux))
        {
            CadenaNum[temp] = CadenaNum[temp - 1];
            temp--;
        }
        CadenaNum[temp] = aux;
    }
    puts("La utima serie registrada es:");
    printf("[");
    for (int i = 0; i < Caract; i++)
    {
        printf("%d, ", CadenaNum[i]);
    }
    printf("]\n");
}
