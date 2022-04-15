#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<string.h>

int busquedaBinaria(int arreglo[26][2], int item, int tamArr){
    int posIzq=0;
    int posDer=tamArr-1;
    int puntoMedio=0;
    while(posIzq<=posDer){
        puntoMedio=(posIzq+posDer)/2;
        if(arreglo[puntoMedio][1]==item)
            return puntoMedio;
        else if(arreglo[puntoMedio][1]>item){
            posDer=puntoMedio-1;
        } else
            posIzq=puntoMedio+1;
    }
    return -1;  
}

void imprimeArregloLibros(char lista[33][64]){
    int i;
    puts("Entrando a impresion");
    for(i=0; i<33; i++)
        printf("Libro en la pos %d -> %s", i, lista[i]);
}

void main(){
    //Apertura del archivo
    char *path="C:\\Users\\gusta\\Desktop\\BD_Libros.txt";
    char *pathIndex="G:\\Programas_ESCOM\\workspace_Gustavo_G3\\Algoritmos y Estructuras de datos\\2bm1\\archivoIndicex.txt";
    char arreglo[33][64];
    int arregloRangoIndex[26][2];
    char linea[64];
    int indice=0;
    char tituloBusqueda[64];
    int valor=0;
    char caracter;
    int limiteSup=0;
    int limiteInf=0;
    FILE *archivo=fopen(path,"r+");
    if(archivo==NULL){
        perror("No se pudo abrir el archivo de titulos");
        exit(1);
    }

    FILE *archivoIndex=fopen(pathIndex,"r+");
    if(archivoIndex==NULL){
        perror("No se pudo abrir el archivo de indices");
        exit(1);
    }

    //transferir todos los datos al arreglo
    while(!feof(archivo)){
        fgets(linea,64,archivo);
        strcpy(arreglo[indice],linea);
        indice++;
    }
    //imprimeArregloLibros(arreglo);

    //transferencia de indices a un arreglo
    indice=0;
    while(!feof(archivoIndex)){
        fscanf(archivoIndex,"%d,%c",&valor,&caracter);
        arregloRangoIndex[indice][0]=valor;
        arregloRangoIndex[indice][1]=(int)caracter;
        indice++;
    }

    for(int j=0; j<26; j++){
        printf("Arreglo indices: pos=%d, valorNum=%d, car=%c \n", j, arregloRangoIndex[j][0],arregloRangoIndex[j][1]);
    }

    puts("Ingrese un elemento que se desea buscar");
    fflush(stdin);
    scanf("%s",tituloBusqueda);
    int posInicial=busquedaBinaria(arregloRangoIndex,(int)tituloBusqueda[0],26);
    limiteInf=arregloRangoIndex[posInicial][0];
    if(posInicial==26)
        limiteSup=33;
    else
        limiteSup=arregloRangoIndex[posInicial+1][0];
    printf("El titulo se encuentra a partir del indice inf: %d, indiceSup=%d\n", limiteInf, limiteSup);
    for(int k=limiteInf-1; k<limiteSup-1;k++){
        //Aplicar una busqueda en el espacio de libros reducido
    }
}