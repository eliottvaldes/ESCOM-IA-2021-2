/* ▪* Montero Barraza Alvaro David*
 *2BV1 Ingenieria en IA ▪*  ▪*/
#include<iostream>
#include<stdlib.h>
#include<queue>


using namespace std;

typedef struct{
    string nombre;
    string apellido;
    int edad;
}Datos;



Datos int_datos();
queue<Datos> agregar_pos(queue<Datos> cola,int pos);
void print_ini(queue<Datos> cola);
int print_fin(queue<Datos> cola);
queue<Datos> Delet_pos(queue<Datos> cola, int pos);

int main(){
    queue<Datos> cola;
	int opt=0,pos;

    Datos aux;
    do
    {
        cout<<endl<<"introduce la opción deseada"<<endl<<"1.-Agregar datos a inicio"<<endl<<"2.-Agregar datos fin"<<endl<<"3.-Agregar datos pos N"<<endl<<"4.-Imprimir inicio a fin"<<endl<<"5.-Imprimir fin a inicio"<<endl<<"6.-Elimina al inicio"<<endl<<"7.-Elimina al final"<<endl<<"8.-Elimina en posicion"<<endl<<"9.-Salir"<<endl;
		cin>>opt;
		switch (opt)
        {
        case 1:
            aux=int_datos();
            cola.push(aux);
            break;
        case 2:
            cola=agregar_pos(cola,cola.size()-1);
            
            break;
        case 3:

            cout<<"Introduce la posicion que quieras cambiar, hay "<<cola.size()<<"posiciones";
            cin>>pos;
            cola=agregar_pos(cola,pos);

            break;
        case 4:
            print_ini(cola);
            
            opt=0;
            break;
        case 5:
            print_fin(cola);
            system("pause");
            opt=0;
            break;
        case 6:
            cola=Delet_pos(cola,cola.size()-1);
            break;
        case 7:
             cout<<"Introduce la posicion que quieras cambiar, hay "<<cola.size()<<"posiciones";
            cin>>pos;
            cola=Delet_pos(cola,pos);
            break;
        case 8:
            cola.pop();
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



Datos int_datos(){
    Datos intr;
    cout<<"Introduce el nombre"<<endl;
    cin>>intr.nombre;
    cout<<"Introduce el apellido"<<endl;
    cin>>intr.apellido;
    cout<<"Introduce la edad"<<endl;
    cin>>intr.edad;
    
    return intr;
}


queue<Datos> agregar_pos(queue<Datos> cola,int pos){
    queue<Datos> aux;
    int tam=cola.size();
    Datos entrada;
    for (int i = 0; i < pos; i++)
    {
        aux.push(cola.front());
        cola.pop();
    }
    entrada=int_datos();
    aux.push(entrada);
    for (int i = pos; i < tam; i++)
    {
        aux.push(cola.front());
        cola.pop();
    }
    
    return aux;
}


void print_ini(queue<Datos> cola){
    int tam=cola.size();
    Datos aux;
    for (int i = 0; i < tam; i++)
    {
        aux=cola.front();
        cout<<aux.nombre<<" "<<aux.apellido<<" "<<aux.edad<<" anios"<<endl;
        cola.pop();
    }
    
    system("pause");
}


int print_fin(queue<Datos> cola){
    int tam=cola.size();
    queue <Datos> ColaAux; 
    Datos aux;
        aux=cola.back();
        cout<<aux.nombre<<" "<<aux.apellido<<" "<<aux.edad<<" anios"<<endl;
        if(tam-1==0){
            return 0;
        }
    for (int i = 0; i < tam-1; i++)
    {
        ColaAux.push(cola.front());
        cola.pop();
    }
    print_fin(ColaAux);
    return 0;
}


queue<Datos> Delet_pos(queue<Datos> cola, int pos){
    queue<Datos> Aux;
    int tam=cola.size();
    for (int i = 0; i < pos; i++)
    {
        Aux.push(cola.front());
        cola.pop();
    }
    cola.pop();
    for (int i = pos; i < tam-1; i++)
    {
        Aux.push(cola.front());
        cola.pop();
    }
    
    return Aux;

}