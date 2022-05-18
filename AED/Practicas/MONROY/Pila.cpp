#include <iostream>
#include <stack>
#include <time.h>
using namespace std;

int imprimirPila(stack<int> pila, int numero);
int numeroMayor(stack<int> pila, int numero);

int main()
{
    stack<int> pila;
    int opcionMenu;
    int numero, mayor;
    int range;
    do
    {
        cout << "Que quiere hacer?" << endl;
        cout << "1.- Programa ejercicio" << endl;
        cout << "2.- Salir del programa" << endl;
        cin >> opcionMenu;
        switch (opcionMenu)
        {
        case 1:

            cout << "Cuantos datos estaran en la pila?" << endl;
            cin >> numero;
            cout << "Cual es el rango de los valores al azar?" << endl;
            cin >> range;
            srand(time(NULL));
            for (int i = 0; i < numero; i++)
            {
                pila.push(rand() % range);
            }
            cout << "Imprimiendo pila" << endl;
            imprimirPila(pila, numero);
            cout << "Buscando numero mayor" << endl;
            mayor = numeroMayor(pila, numero);
            cout << "El numero mayor es: " << mayor << "\n\n"<< endl;
            break;

        case 2:
            cout << "Saliendo del programa" << endl;
            exit(0);
            break;

        default:
            cout << "Porfavor digite una opción correcta" << "\n\n" << endl;
            break;
        }
    } while (opcionMenu != 2);

    return(0);
}

int imprimirPila(stack<int> pila, int numero)
{
    for (int i = 0; i < numero; i++)
    {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;
}

int numeroMayor(stack<int> pila, int numero)
{
    stack<int> auxiliar;
    auxiliar.push(pila.top());
    for (int i = 0; i < numero; i++)
    {
        if (auxiliar.top() >= pila.top())
        {
            pila.pop();
        }
        else
        {
            auxiliar.push(pila.top());
            pila.pop();
        }
    }
    return auxiliar.top();
}
