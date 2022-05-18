/*
    Monroy Fernandez Jose Luis
    2BV1
    Inteliencia Artificial
*/

#include "equilibrioLista.h"

int equilibrio();

int main()
{
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
            equilibrio();
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
int equilibrio()
{
    Nodo *lista = NULL;
    string expresion;
    char caracter;
    cout << "Ingrese la expresion" << endl;
    cin >> expresion;
    for (int i = 0; i < expresion.size(); i++)
    {
        caracter = expresion[i];
        if (caracter == '(' | caracter == '[' | caracter == '{')
        {
            lista_push(&lista, caracter);
            continue;
        }
        if (caracter == ')')
        {
            char pos = lista_top(lista);
            if (lista_empty(lista))
            {
                cout << "Expresion no balanceada" << endl;
                return (0);
            }
            else if (pos == '(')
            {
                lista_pop(&lista);
                continue;
            }
            else
            {
                cout << "Expresion no balanceada" << endl;
                return(0);
            }
        }
        else if (caracter == ']')
        {
            char pos = lista_top(lista);
            if (lista_empty(lista))
            {
                cout << "Expresion no balanceada" << endl;
                return (0);
            }
            else if (pos == '[')
            {
                lista_pop(&lista);
                continue;
            }
            else
            {
                cout << "Expresion no balanceada" << endl;
                return(0);
            }
        }
        else if (caracter == '}')
        {
            char pos = lista_top(lista);
            if (lista_empty(lista))
            {
                cout << "Expresion no balanceada" << endl;
                return (0);
            }
            else if (pos == '{')
            {
                lista_pop(&lista);
                continue;
            }
            else
            {
                cout << "Expresion no balanceada" << endl;
                return(0);
            }
        }
    }
    int tam = lista_size(lista);
    if (tam > 0)
    {
        cout << "Expresion balanceada" << endl;
    }
    else
    {
        cout << "Expresion no balanceada" << endl;
    }
}
