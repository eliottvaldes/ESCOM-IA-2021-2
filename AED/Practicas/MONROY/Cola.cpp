/*
    Monroy Fernandez Jose Luis
    2BV1
    Inteligencia Artificial
*/

#include <iostream>
#include <queue>

using namespace std;

typedef struct
{
    string nombre;
    string director;
    int noSalones;
} escuela;

escuela registrarEscuela();
queue<escuela> structFin(queue<escuela>, queue<escuela>, escuela, int);
queue<escuela> structCustom(queue<escuela>, queue<escuela>, escuela, int, int);
int imprimirColaInicio(queue<escuela>, escuela, int);
int imprimirColaFin(queue<escuela>, escuela, int);
queue<escuela> eliminarFin(queue<escuela>, queue<escuela>, escuela, int);
queue<escuela> eliminarCustom(queue<escuela>, queue<escuela>, escuela, int, int);
int main()
{
    queue<escuela> cola;
    queue<escuela> auxCola;
    int opcionMenu;
    int tam, pos;
    escuela auxStruct;
    do
    {

        cout << "Que desesa hacer" << endl;
        cout << "1.- Agregar una palabra al inicio" << endl;
        cout << "2.- Agregar una palabra al final" << endl;
        cout << "3.- Agregar una palabra en una posicion N" << endl;
        cout << "4.- Imprimir Inicio a Fin" << endl;
        cout << "5.- Imprimir Fin a inicio" << endl;
        cout << "6.- Eliminar al inicio" << endl;
        cout << "7.- Eliminar al final" << endl;
        cout << "8.- Eliminar una posicion N" << endl;
        cout << "9.- Salir" << endl;
        cin >> opcionMenu;
        switch (opcionMenu)
        {
        case 1:
            auxStruct = registrarEscuela();
            cola.push(auxStruct);
            break;
        case 2:
            tam = cola.size();
            cola = structFin(cola, auxCola, auxStruct, tam);
            break;
        case 3:
            cout << "Digite la posicion en la que quieras agregar, hay " << cola.size() << "posiciones";
            cin >> pos;
            tam = cola.size();
            cola = structCustom(cola, auxCola, auxStruct, tam, pos);
            break;
        case 4:
            tam = cola.size();
            imprimirColaInicio(cola, auxStruct, tam);
            break;
        case 5:
            tam = cola.size();
            imprimirColaFin(cola, auxStruct, tam);
            break;
        case 6:
            cola.pop();
            break;
        case 7:
            tam = cola.size() - 1;
            cola = eliminarFin(cola, auxCola, auxStruct, tam);
            break;
        case 8:
            cout << "Digite la posicion de la estructura a eliminar, hay " << cola.size() << "posiciones";
            cin >> pos;
            tam = cola.size();
            cola = eliminarCustom(cola, auxCola, auxStruct, tam, pos);
            break;
        case 9:
            cout << "Saliendo del programa" << endl;
            exit(0);
        default:
            cout << "Porfavor seleccione una opcion valida" << endl;
            break;
        }
    } while (opcionMenu != 9);
    return 0;
}

escuela registrarEscuela()
{
    escuela nueva;
    cout << "Ingrese el nombre de la escuela" << endl;
    cin >> nueva.nombre;
    cout << "Ingrese el nombre del director" << endl;
    cin >> nueva.director;
    cout << "Digite el numero de salones" << endl;
    return nueva;
}

queue<escuela> structFin(queue<escuela> cola, queue<escuela> auxCola, escuela auxEscuela, int tam)
{
    int fin = tam - 1;
    for (int i = 0; i < fin; i++)
    {
        auxCola.push(cola.front());
        cola.pop();
    }
    auxEscuela = registrarEscuela();
    auxCola.push(auxEscuela);
    for (int i = 0; i < tam; i++)
    {
        auxCola.push(cola.front());
        cola.pop();
    }
    return auxCola;
}

queue<escuela> structCustom(queue<escuela> cola, queue<escuela> auxCola, escuela auxEscuela, int tam, int pos)
{
    for (int i = 0; i < pos; i++)
    {
        auxCola.push(cola.front());
        cola.pop();
    }
    auxEscuela = registrarEscuela();
    auxCola.push(auxEscuela);
    for (int i = 0; i < tam; i++)
    {
        auxCola.push(cola.front());
        cola.pop();
    }
    return auxCola;
}

int imprimirColaInicio(queue<escuela> cola, escuela auxEscuela, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        auxEscuela = cola.front();
        cout << "'" << auxEscuela.nombre << endl;
        cout << "Director: " << auxEscuela.director << endl;
        cout << "Numero de Salones: " << auxEscuela.noSalones << endl;
        cola.pop();
    }
    return 0;
}

int imprimirColaFin(queue<escuela> cola, escuela auxEscuela, int tam)
{
    queue<escuela> auxCola;
    auxEscuela = cola.back();
    cout << "'" << auxEscuela.nombre << endl;
    cout << "Director: " << auxEscuela.director << endl;
    cout << "Numero de Salones: " << auxEscuela.noSalones << endl;
    if (tam - 1 == 0)
    {
        return 0;
    }
    for (int i = 0; i < tam - 1; i++)
    {
        auxCola.push(cola.front());
        cola.pop();
    }
    tam = auxCola.size();
    imprimirColaFin(auxCola, auxEscuela, tam);
    return 0;
}

queue<escuela> eliminarFin(queue<escuela> cola, queue<escuela> auxCola, escuela auxEscuela, int fin)
{
    for (int i = 0; i < fin; i++)
    {
        auxCola.push(cola.front());
        cola.pop();
    }
    auxEscuela = cola.back();
    cout << "La estructura eliminada fue" << endl;
    cout << '"' << auxEscuela.nombre << '"' << endl;
    cout << "Director: " << auxEscuela.director << endl;
    cout << "Numero de Salones: " << auxEscuela.noSalones << endl;
    cola.pop();
    for (int i = fin; i < fin; i++)
    {
        auxCola.push(cola.front());
        cola.pop();
    }
    return auxCola;
}

queue<escuela> eliminarCustom(queue<escuela> cola, queue<escuela> auxCola, escuela auxEscuela, int tam, int pos)
{
    for (int i = 0; i < pos; i++)
    {
        auxCola.push(cola.front());
        cola.pop();
    }
    auxEscuela = cola.back();
    cout << "La estructura eliminada fue" << endl;
    cout << '"' << auxEscuela.nombre << '"' << endl;
    cout << "Director: " << auxEscuela.director << endl;
    cout << "Numero de Salones: " << auxEscuela.noSalones << endl;
    cola.pop();
    for (int i = pos; i < tam - 1; i++)
    {
        auxCola.push(cola.front());
        cola.pop();
    }
    return auxCola;
}