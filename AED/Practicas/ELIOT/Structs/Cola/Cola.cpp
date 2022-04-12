/**
 * @file Cola.cpp
 * @author Valdés Luis Eliot Fabián
 * @brief archivo que contiene el menu de cola
 * @version 0.1
 * @date 2022-03-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <queue>
using namespace std;

// creamos la estructura
typedef struct
{
    string marca;
    string color;
    int tamanoCalzado;
} tenis;

// Creamos los prototipos
tenis agregarRegistro();
queue<tenis> agregarFin(queue<tenis>, queue<tenis>, tenis, int);
queue<tenis> agregarPosN(queue<tenis>, queue<tenis>, tenis, int, int);
int mostrarAsc(queue<tenis>, tenis, int);
int mostrarDesc(queue<tenis>, tenis, int);
queue<tenis> eliminarFin(queue<tenis>, queue<tenis>, tenis, int);
queue<tenis> eliminarPosN(queue<tenis>, queue<tenis>, tenis, int, int);

// main Function
int main()
{

    // variables de menu
    int opcionMenu, opcionsalir = 9;

    // variables de programa
    // creamos la cola y la cola auxiliar
    queue<tenis> cola;
    queue<tenis> colaAux;
    int tamCola, pos;

    tenis tenisAux;

    do
    {

        cout << "\n======================================================" << endl;
        cout << "\tDigita la opcion que deseas llevar a cabo" << endl;
        cout << "======================================================" << endl;
        cout << "1.- Agregar una elemento al inicio" << endl;
        cout << "2.- Agregar una elemento al final" << endl;
        cout << "3.- Agregar una elemento en una posicion especifica" << endl;
        cout << "4.- Imprimir de Inicio a Fin" << endl;
        cout << "5.- Imprimir de Fin a inicio" << endl;
        cout << "6.- Eliminar inicio" << endl;
        cout << "7.- Eliminar final" << endl;
        cout << "8.- Eliminar una posicion especifica" << endl;
        cout << "9.- Salir" << endl;
        cout << "---------------------------------------------------------" << endl;
        cin >> opcionMenu;
        switch (opcionMenu)
        {
        case 1:
            tenisAux = agregarRegistro();
            cola.push(tenisAux);
            break;

        case 2:
            tamCola = cola.size();
            cola = agregarFin(cola, colaAux, tenisAux, tamCola);
            break;

        case 3:
            cout << "Digita la posicion en la que quieras agregar:";
            cin >> pos;
            tamCola = cola.size();
            cola = agregarPosN(cola, colaAux, tenisAux, tamCola, pos);
            break;

        case 4:
            tamCola = cola.size();
            mostrarAsc(cola, tenisAux, tamCola);
            break;

        case 5:
            tamCola = cola.size();
            mostrarDesc(cola, tenisAux, tamCola);
            break;

        case 6:
            cola.pop();
            break;

        case 7:
            tamCola = cola.size() - 1;
            cola = eliminarFin(cola, colaAux, tenisAux, tamCola);
            break;

        case 8:
            cout << "Digita la posicion de la estructura a eliminar: ";
            cin >> pos;
            tamCola = cola.size();
            cola = eliminarPosN(cola, colaAux, tenisAux, tamCola, pos);
            break;

        case 9:
            cout << "Saliendo del programa..." << endl;
            exit(0);

        default:
            cout << "Por favor selecciona una opcion valida" << endl;
            break;
        }
    } while (opcionMenu != opcionsalir);

    return 0;
}

tenis agregarRegistro()
{
    tenis nuevo;

    cout << "\nDigita la marca del tenis: " << endl;
    cin >> nuevo.marca;
    cout << "Digita el color del tenis" << endl;
    cin >> nuevo.color;
    cout << "Digita el tamano del tenis" << endl;
    cin >> nuevo.tamanoCalzado;

    return nuevo;
}

queue<tenis> agregarFin(queue<tenis> cola, queue<tenis> colaAux, tenis auxTenis, int tamCola)
{
    int fin = tamCola - 1;

    for (int i = 0; i < fin; i++)
    {
        colaAux.push(cola.front());
        cola.pop();
    }

    auxTenis = agregarRegistro();
    colaAux.push(auxTenis);

    for (int i = 0; i < tamCola; i++)
    {
        colaAux.push(cola.front());
        cola.pop();
    }

    return colaAux;
}

queue<tenis> agregarPosN(queue<tenis> cola, queue<tenis> colaAux, tenis auxTenis, int tamCola, int pos)
{
    for (int i = 0; i < pos; i++)
    {
        colaAux.push(cola.front());
        cola.pop();
    }

    auxTenis = agregarRegistro();
    colaAux.push(auxTenis);

    for (int i = 0; i < tamCola; i++)
    {
        colaAux.push(cola.front());
        cola.pop();
    }

    return colaAux;
}

int mostrarAsc(queue<tenis> cola, tenis auxTenis, int tamCola)
{
    for (int i = 0; i < tamCola; i++)
    {
        auxTenis = cola.front();
        cout << "\nMarca => " << auxTenis.marca << endl;
        cout << "Color: " << auxTenis.color << endl;
        cout << "Tamano de calzado: " << auxTenis.tamanoCalzado << endl;
        cola.pop();
    }

    return 0;
}

int mostrarDesc(queue<tenis> cola, tenis auxTenis, int tamCola)
{
    queue<tenis> colaAux;

    auxTenis = cola.back();

    cout << "\nMarca => " << auxTenis.marca << endl;
    cout << "Color: " << auxTenis.color << endl;
    cout << "Tamano de calzado: " << auxTenis.tamanoCalzado << endl;

    if (tamCola - 1 == 0)
    {
        return 0;
    }

    for (int i = 0; i < tamCola - 1; i++)
    {
        colaAux.push(cola.front());
        cola.pop();
    }

    tamCola = colaAux.size();
    mostrarDesc(colaAux, auxTenis, tamCola);

    return 0;
}

queue<tenis> eliminarFin(queue<tenis> cola, queue<tenis> colaAux, tenis auxTenis, int fin)
{
    for (int i = 0; i < fin; i++)
    {
        colaAux.push(cola.front());
        cola.pop();
    }

    auxTenis = cola.back();

    cout << "\n\tSe ha eliminado la estructura: " << endl;
    cout << "Marca: " << auxTenis.marca << endl;
    cout << "Color: " << auxTenis.color << endl;
    cout << "Tamano de calzado: " << auxTenis.tamanoCalzado << endl;

    cola.pop();

    for (int i = fin; i < fin; i++)
    {
        colaAux.push(cola.front());
        cola.pop();
    }

    return colaAux;
}

queue<tenis> eliminarPosN(queue<tenis> cola, queue<tenis> colaAux, tenis auxTenis, int tamCola, int pos)
{
    for (int i = 0; i < pos; i++)
    {
        colaAux.push(cola.front());
        cola.pop();
    }

    auxTenis = cola.back();

    cout << "\n\tSe ha eliminado la estructura: " << endl;
    cout << "Marca: " << auxTenis.marca << endl;
    cout << "Color: " << auxTenis.color << endl;
    cout << "Tamano de calzado: " << auxTenis.tamanoCalzado << endl;

    cola.pop();

    for (int i = pos; i < tamCola - 1; i++)
    {
        colaAux.push(cola.front());
        cola.pop();
    }

    return colaAux;
}