/*
    Monroy Fernandez Jose Luis 
    2BV1
    Inteligencia Artificial
*/

#include <iostream>
#include <stack>

using namespace std;

stack<string> palabraFin(stack<string>, stack<string>, int, string);
stack<string> palabraCustom(stack<string>, stack<string>, int, string);
int imprimirPilaFin(stack<string>, int);
int imprimirPilaInicio(stack<string>, stack<string>, int);
stack<string> elimininarFin(stack<string>, stack<string>, int);
stack<string> eliminarCustom(stack<string>, stack<string>, int);

int main()
{
    stack<string> pila;
    stack<string> aux_str;
    int opcionMenu;
    int tam;
    string palabra;
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
            cout << "Ingrese la palabra" << endl;
            cin >> palabra;
            pila.push(palabra);
            break;
        case 2:
            tam = pila.size();
            pila = palabraFin(pila, aux_str, tam, palabra);
            break;
        case 3:
            tam = pila.size();
            pila = palabraCustom(pila, aux_str, tam, palabra);
            break;
        case 4:
            tam = pila.size();
            imprimirPilaInicio(pila, aux_str, tam);
            break;
        case 5:
            tam = pila.size();
            imprimirPilaFin(pila, tam);
            break;
        case 6:
            pila.pop();
            break;
        case 7:
            tam = pila.size();
            pila = elimininarFin(pila, aux_str, tam);
            break;
        case 8:
            tam = pila.size();
            pila = eliminarCustom(pila, aux_str, tam);
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

stack<string> palabraFin(stack<string> pila, stack<string> aux, int size, string tmp)
{
    for (int i = 0; i < size; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    cout << "Ingrese la palabra" << endl;
    cin >> tmp;
    pila.push(tmp);
    for (int i = 0; i < size; i++)
    {
        pila.push(aux.top());
        aux.pop();
    }
    return pila;
}

stack<string> palabraCustom(stack<string> pila, stack<string> aux, int tam, string tmp)
{
    cout << "En que posicion deseas escribir" << endl;
    int pos;
    cin >> pos;
    if (pos > tam)
    {
        cout << "La posicion que desea agregar no existe en el errglo, su arreglo cuenta con" << tam << "posiciones" << endl;
        return pila;
    }
    cout << "Ingrese la palabra" << endl;
    cin >> tmp;
    for (int i = 0; i < pos; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    pila.push(tmp);
    for (int i = 0; i < pos; i++)
    {
        pila.push(aux.top());
        aux.pop();
    }
    return pila;
}

int imprimirPilaInicio(stack<string> pila, stack<string> aux, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    for (int i = 0; i < tam; i++)
    {
        cout << aux.top() << ", ";
        aux.pop();
    }
    return 0;
}

int imprimirPilaFin(stack<string> pila, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << pila.top() << " ,";
        pila.pop();
    }
    cout << endl;
    return 0;
}

stack<string> elimininarFin(stack<string> pila, stack<string> aux, int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    cout << "Se ha eliminado la palabra" << pila.top() << "de la lista" << endl;
    pila.pop();
    for (int i = 0; i < tam - 1; i++)
    {
        pila.push(aux.top());
        aux.pop();
    }
    return pila;
}

stack<string> eliminarCustom(stack<string> pila, stack<string> aux, int tam)
{
    int pos;
    cout << "Ingrese la posicion a eliminar";
    cin >> pos;
    if (pos > tam)
    {
        cout << "La posicion a eliminanr esta fuera de la pila registrada" << endl;
        return pila;
    }
    for (int i = 0; i < pos - 1; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    cout << "Se ha eliminado la palabra" << pila.top() << "de la lista" << endl;
    pila.pop();
    for (int i = 0; i < pos - 1; i++)
    {
        pila.push(aux.top());
        aux.pop();
    }
    return pila;
}