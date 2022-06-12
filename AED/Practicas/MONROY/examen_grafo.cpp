#include <iostream>

using namespace std;

struct grafo{
    int V;
    int E;
    int **matriz;
};

<<<<<<< HEAD
string obtenerDatos();
int obtenerDatosNum();

int main(){
<<<<<<< HEAD
    string nombresNodos, vinculos;
    int noNodos, noAristas, costo;
    nombresNodos, vinculos = obtenerDatos();
    noNodos, noAristas = obtenerDatosNum();
=======
    
>>>>>>> 2c6b1c8 (Conversión y filtración de datos obtenidos)
=======
grafo *matrizGrafo(int, int);

int main(){
    int renglon = 1, posicion = 0, maxrenglones = 0, contador;
    string nombreNodos;
    int numeroAristas;

    FILE *archivo;
    char linea[15];
    archivo = fopen("grafo1_def.txt", "r");
    while(fgets(linea, 15, archivo) != NULL){
        maxrenglones ++;
    }
    string vinculos[maxrenglones-2];
    rewind(archivo);
    while(fgets(linea, 100, archivo) != NULL){
        if(renglon == 1){
            nombreNodos = linea;
            renglon++;
        }
        else if(renglon == 2){
            numeroAristas = atoi(linea);
            renglon++;
        }
        else{
            vinculos[posicion] = linea;
            posicion++;
        }
    }
    fclose(archivo);

    char numeroNodo[1] = {nombreNodos[0]};
    int numeroNodos = atoi(numeroNodo);
    posicion=0;
    char nombresAux[numeroNodos-1];
    for(int i = 2; i <= nombreNodos.size(); i+=2){
        nombresAux[posicion]= nombreNodos[i];
        posicion++;
    }
    string nombres = nombresAux;

    grafo *red = matrizGrafo(numeroNodos, numeroAristas);
    

    return 0;
}

grafo *matrizGrafo(int numeroNodos, int numeroAristas){
    grafo *red = new grafo;
    if (red == NULL)
    {
        cout << "Error en memoria" << endl;
        return NULL;
    }
    red->V = numeroNodos;
    red->E = numeroAristas;
    red->matriz = (int **)calloc(red->V,sizeof(int *));
    for (int i = 0; i < red->V; i++)
    {
        red->matriz[i] = (int *)calloc(red->V,sizeof(int));
    }
    for (int i = 0; i < red->V; i++)
    {
        for (int j = 0; j < red->V; j++)
        {
            red->matriz[i][j] = 0;
        }
    }
    return red;
>>>>>>> c3d1702 (Creación de matriz adjunta)
}