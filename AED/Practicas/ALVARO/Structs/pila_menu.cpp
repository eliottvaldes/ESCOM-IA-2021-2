#include<stdlib.h>
#include<iostream>
#include<stack>
using namespace std;



stack<string> palabra_ini(stack<string> pila);
stack<string> palabra_fin(stack<string> pila);
stack<string> palabra_pos(stack<string> pila);
void imp_ini(stack<string> pila);
void imp_fin(stack<string> pila);
stack<string> elim_inicio(stack<string> pila);
stack<string> elim_fin(stack<string> pila);
stack<string> elim_pos(stack<string> pila);





int main(){
    stack<string> pila;

	int opt=0;
    do
    {
        cout<<endl<<"introduce la opción deseada"<<endl<<"1.-Agregar palabra a inicio"<<endl<<"2.-Agregar palabra fin"<<endl<<"3.-Agregar palabra pos N"<<endl<<"4.-Imprimir inicio a fin"<<endl<<"5.-Imprimir fin a inicio"<<endl<<"6.-Elimina al inicio"<<endl<<"7.-Elimina al final"<<endl<<"8.-Elimina en posicion"<<endl<<"9.-Salir"<<endl;
		cin>>opt;
		switch (opt)
        {
        case 1:
            pila=palabra_ini(pila);
            break;
        case 2:
            pila=palabra_fin(pila);
            break;
        case 3:
            pila=palabra_pos(pila);
            break;
        case 4:
            imp_ini(pila);
            opt=0;
            break;
        case 5:
            imp_fin(pila);
            opt=0;
            break;
        case 6:
            pila=elim_inicio(pila);
            break;
        case 7:
            pila=elim_fin(pila);
            break;
        case 8:
            pila=elim_pos(pila);
            break;
        case 9:
            break;
        default:
            cout<<"Introduce una opcion valida"<<endl;
            system("pause");
            break;
        }
		
	
	
	
	
	system("cls");
    } while (opt!=9);
    
	return 0;
}

stack<string> palabra_ini(stack<string> pila){
        string aux;
        cout<<"Introduce la palabra que quieras poner"<<endl;
        cin>>aux;
        pila.push(aux);
        return pila;
}


stack<string> palabra_fin(stack<string> pila){
        //se copia toda la estructura y se procede a escribir al final
        stack<string> aux_str;
        int tam=pila.size();
        for (int i = 0; i < tam; i++)
        {
            aux_str.push(pila.top());
            pila.pop();
        }
        cout<<"Introduce tu palabra"<<endl;
        string aux;
        cin>>aux;
        pila.push(aux);
        for (int i = 0; i < tam; i++)
        {
            pila.push(aux_str.top());
            aux_str.pop();
        }
        
        return pila;
}


stack<string> palabra_pos(stack<string> pila){
            
            int tam=pila.size();
            stack<string> P_aux;
            string aux;
            cout<<"El arreglo tiene tamano "<<tam<<" En que posicion deseas escribir"<<endl;
            int pos;
            cin>>pos;
            if (pos>tam)
            {
                cout<<"Posicion no encontrada";
                system("pause");
                pila=palabra_pos(pila);
                return pila;
            }
            cout<<"Introduce la nueva palabra"<<endl;
            cin>>aux;
            for (int i = 0; i < pos; i++)
            {
                P_aux.push(pila.top());
                pila.pop();
            }
            pila.push(aux);
            for (int i = 0; i < pos; i++) 
            {
                pila.push(P_aux.top());
                P_aux.pop();
            }
            


            
    return pila;
}


void imp_ini(stack<string> pila){
    int tam=pila.size();
            for (int i = 0; i < tam; i++)
            {
                cout<<pila.top()<<" ";
                pila.pop();
            }
            cout<<endl;
            system("pause");
}


void imp_fin(stack<string> pila){
    int tam=pila.size();
    stack<string> str_aux;
    for (int i = 0; i < tam; i++)
    {
        str_aux.push(pila.top());
        pila.pop();
    }
    for (int i = 0; i < tam; i++)
    {
        cout<<str_aux.top()<<" ";
        str_aux.pop();
    }
    system("pause");
}


stack<string> elim_inicio(stack<string> pila){
    pila.pop();
    return pila;
}


stack<string> elim_fin(stack<string> pila){
    int tam=pila.size();
    stack<string> aux;
    for (int i = 0; i < tam-1; i++)
    {
        aux.push(pila.top());
        pila.pop();
    }
    pila.pop();
    for (int i = 0; i < tam-1; i++)
    {
        pila.push(aux.top());
        aux.pop();
    }
    
    return pila;
}


stack<string> elim_pos(stack<string> pila){
        int tam=pila.size(),pos;
        stack<string> aux;
        cout<<"El arreglo tiene "<<tam<<" posiciones, cual deseas eliminar";
        cin>>pos;
        if (pos>tam)
        {
            cout<<"Introduce un tamaño valido";
            system("pause");
            pila=elim_pos(pila);
            return pila;
        }
        
        for (int i = 0; i <pos-1 ; i++)
        {
            aux.push(pila.top());
            pila.pop();
        }
            pila.pop();
        for (int i = 0; i < pos-1; i++)
        {
            pila.push(aux.top());
            aux.pop();
        }
    return pila;
}