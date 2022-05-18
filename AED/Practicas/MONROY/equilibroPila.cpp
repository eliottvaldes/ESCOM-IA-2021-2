/*
    Monroy Fernandez Jose Luis
    2BV1
    Inteliencia Artificial
*/

#include <iostream>
#include <stack>
using namespace std;

int equilibrio(stack<char>);

int main()
{
    stack<char> contenedor;
    int opcionUsuario;
    do
    {
        cout << "Elija una opcion" << endl;
        cout << "1 .- Ingresar expresion" << endl;
        cout << "2 .- Salir del programa" << endl;
        cin >> opcionUsuario;
        switch (opcionUsuario)
        {
        case 1:
            equilibrio(contenedor);
            break;
        case 2:
            cout << "Saliendo del programa" << endl;
            return (0);
            break;
        default:
            cout << "Elija una opcion valida" << endl;
            break;
        }
    } while (opcionUsuario != 2);
    return (0);
}

int equilibrio(stack<char> pila)
{
    string expresion;
    char caracter;
    cout << "Ingrese la expresion" << endl;
    cin >> expresion;
    for (int i = 0; i < expresion.size(); i++)
    {
        caracter = expresion[i];
        if (caracter == '(' | caracter == '[' | caracter == '{')
        {
            pila.push(caracter);
            continue;
        }
        if (caracter == ')')
        {
            if (pila.empty())
            {
                cout << "Expresion no balanceada" << endl;
                return (0);
            }
            else if (pila.top() == '(')
            {
                pila.pop();
                continue;
            }
            else
            {
                cout << "Expresion no balanceada" << endl;
                continue;
            }
        }
        else if (caracter == ']')
        {
            if (pila.empty())
            {
                cout << "Expresion no balanceada" << endl;
                return (0);
            }
            else if (pila.top() == '[')
            {
                pila.pop();
                continue;
            }
            else
            {
                cout << "Expresion no balanceada" << endl;
                continue;
            }
        }
        else if (caracter == '}')
        {
            if (pila.empty())
            {
                cout << "Expresion no balanceada" << endl;
                return (0);
            }
            else if (pila.top() == '{')
            {
                pila.pop();
                continue;
            }
            else
            {
                cout << "Expresion no balanceada" << endl;
                continue;
            }
        }
    }

    if (pila.size() == 0)
    {
        cout << "Expresion balanceada" << endl;
    }
    else
    {
        cout << "Expresion no balanceada" << endl;
    }
}