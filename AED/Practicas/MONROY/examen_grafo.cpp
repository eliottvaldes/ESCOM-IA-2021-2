#include <iostream>

using namespace std;

struct grafo{
    int V;
    int E;
    int **matriz;
};

string obtenerDatos();
int obtenerDatosNum();
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
    string aux;
    for(int i = 0; i < numeroAristas; i++){
        aux = vinculos[i];
        for (int j = 0; j < nombres.size(); j++){
            if (aux[0] == nombres[j]){
                if (aux[2] == nombres[0]){
                    red->matriz[j][0] = 1;
                }
                else if (aux[2] == nombres[1]){
                    red->matriz[j][1] = 1;
                }
                else if (aux[2] == nombres[2]){
                    red->matriz[j][2] = 1;
                }
                else if (aux[2] == nombres[3]){
                    red->matriz[j][3] = 1;
                }
                else if (aux[2] == nombres[4]){
                    red->matriz[j][4] = 1;
                }
                else if (aux[2] == nombres[5]){
                    red->matriz[j][5] = 1;
                }
                break;
            }
            else {
                continue;
            }
        }
    }
    
    int grado[numeroNodos-1];
    for (int i = 0; i < numeroNodos; i++){
        grado[i] = 0;
    }
    for(int j=0; j < numeroNodos ; j++){
        for (int k = 0; k < numeroNodos; k++)
        {
            if (red->matriz[k][j] == 1)
            {
                grado[j] ++;
                continue;
            }
            else {
                continue;
            }
        }
    }
    cout << "Grado de cada componente en el grafo " << endl;
    for(int i=0; i < numeroNodos; i++){
        cout << "El grado del nodo " << nombres[i] << " es " << grado[i] << endl;
    }
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
}
