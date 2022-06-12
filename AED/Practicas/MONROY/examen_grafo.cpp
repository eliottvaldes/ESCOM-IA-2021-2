#include <iostream>

using namespace std;

struct grafo{
    int V;
    int E;
    int **matriz;
};

string obtenerDatos();
int obtenerDatosNum();

int main(){
    string nombresNodos, vinculos;
    int noNodos, noAristas, costo;
    nombresNodos, vinculos = obtenerDatos();
    noNodos, noAristas = obtenerDatosNum();
}