/*
======================================
 ▪* Montero Barraza Alvaro David*
     *2BV1 Ingenieria en IA ▪*  
=======================================
 */
#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct{
        string nombre;
        string apellido;
        int edad;
        int id;
}Dato;

typedef struct Nodo{
        Dato dato;
        Nodo *sig;
        Nodo *ant;
}Nodo;

void ins_listini(Nodo **lista,Nodo **fin,Dato dato);
void most_list(Nodo *lista);
bool ins_listfin(Nodo **lista,Dato dato);
void ins_listpos(Nodo **lista,Dato dato, int pos);
int sizeof_nodo(Nodo* Lista);
void elim_ini(Nodo **lista);
int elim_fin(Nodo **Lista);
void elim_pos(Nodo **Lista,int pos);
bool desp_lat(Nodo **Lista);
ostream& operator<<(ostream& print,Nodo list);
//istream& operator>>(istream& save,Nodo list);
Dato istr();

int main(){
    Nodo *inicio=NULL;
    Nodo *fin=NULL;
    fin=new Nodo;
    inicio=new Nodo();
    inicio->ant=NULL;
    int cond=0,tam,pos;
    Dato num;
    
    do
    {
        cout<<endl<<"introduce la opción deseada"<<endl<<"1.-Agregar datos a inicio"<<endl<<"2.-Agregar datos fin"<<endl<<"3.-Agregar datos pos N"<<endl<<"4.-Imprimir inicio a fin"<<endl<<"5.-Elimina al inicio"<<endl<<"6.-Elimina al final"<<endl<<"7.-Elimina en posicion"<<endl<<"8.-Desplazamiento lateral"<<endl<<"9.-Salir"<<endl;
        cin>>cond;
        switch (cond)
        {
        case 1:
            
            num=istr();
            ins_listini(&inicio,&fin,num);
            break;
        case 2:
            
           // cin>>num;
            num=istr();
            ins_listfin(&inicio,num);
            break;
        case 3:
            tam=sizeof_nodo(inicio);
            cout<<"Hay "<<tam<<" posiciones"<<endl<<"Introduce la posicion que quieres cambiar"<<endl;
            cin>>pos;
                if (pos>tam||tam<0)
            {
                cout<<"Introduce una opcion valida";
                break;
            }
            
            //cin>>num;
            num=istr(); 
            ins_listpos(&inicio,num,pos);
            break;
        case 4:
            system("cls");
            most_list(inicio);
            break;
        case 5:
            elim_ini(&inicio);
            break;
        case 6:
            tam=sizeof_nodo(inicio);
            if(tam==1){
                elim_ini(&inicio);
            }else{
                elim_fin(&inicio);
            }
            
            break;
        case 7:
            tam=sizeof_nodo(inicio);
            cout<<"hay "<<tam<<" posiciones"<<endl<<"Introduce la posicion que quieres cambiar"<<endl;
            cin>>pos;
            if (pos>tam||tam<0)
            {
                cout<<"Introduce una opcion valida";
                break;
            }
            elim_pos(&inicio,pos);

            break;
        case 8:
            desp_lat(&inicio);
            break;
        case 9:
            break;
        default:
            cout<<"Introduce una opcion valida"<<endl;
            break;
        }
        
        
    } while (cond!=9);
    
    system("pause");

    return 0;
}



void ins_listini(Nodo **inicio,Nodo **fin,Dato dato){
      Nodo *nuevo_nodo=new Nodo();//1
      nuevo_nodo->sig=NULL;//2
      nuevo_nodo->ant=NULL;
      nuevo_nodo->dato=dato;//3
      
      
      if ((*inicio)==NULL)
      {    
          (*inicio)=nuevo_nodo;
          (*fin)=nuevo_nodo;
      }else{
          nuevo_nodo->sig=(*inicio);
          (*inicio)->ant=nuevo_nodo;
          (*inicio)=nuevo_nodo;
          
      }
      
}


bool ins_listfin(Nodo **inicio,Nodo **fin,Dato dato){
    Nodo *nuevo_nodo=new Nodo();
    Nodo *antes;
    nuevo_nodo->sig=NULL;//2
    nuevo_nodo->ant=NULL;
    if (*inicio==NULL)
    {
        (*inicio)=nuevo_nodo;
        (*fin)=nuevo_nodo;
        return true;
    }
    nuevo_nodo->ant=*fin;
    (*fin)->sig=nuevo_nodo;
    (*fin)=nuevo_nodo;
    
    
    return true;
    
}


void most_list(Nodo *lista){
    Nodo *iterador;
    iterador=lista;
    while (iterador->sig!=NULL)
    {
        iterador=iterador->sig;
        cout<<(*iterador);//sobrecarga de la funcion
    }
    cout<<endl;
}

int sizeof_nodo(Nodo* Lista){
    Nodo *iterador;
    int counter=0;
    iterador=Lista;
    while (iterador->sig!=NULL)
    {
        counter++;
        iterador=iterador->sig;
    }
    return counter;
}


void ins_listpos(Nodo **lista,Dato dato, int pos){
    Nodo *iterador;
    Nodo *antes;
    iterador=*lista;
    for (int i = 0; i < pos-1; i++)
    {
        antes=iterador;
        iterador=iterador->sig;
    }
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=dato;
    antes->sig=nuevo_nodo;
    nuevo_nodo->ant=antes;
    nuevo_nodo->sig=iterador;
    iterador->ant=nuevo_nodo;
}


void elim_ini(Nodo **lista){
    Nodo *aux;
    Nodo *aux2;
    aux=(*lista)->sig;
    aux2=aux->sig;
    aux2->ant=NULL;
    (*lista)->sig=aux2;
    delete aux;
}


int elim_fin(Nodo **Lista){
    Nodo *iterador;
    Nodo *antes;
    iterador=(*Lista)->sig;
    if (iterador==NULL)
    {
        cout<<"No hay lista que borrar";
        return 0;
    }
    
    while (iterador->sig!=NULL)
    {   
        antes=iterador;
        iterador=iterador->sig;

    }
    antes->sig=NULL;
    delete iterador;
    return 0;
}


void elim_pos(Nodo **Lista,int pos){
    Nodo *iterador;
    Nodo *Antes=new Nodo();
    iterador=*Lista;
    for (int i = 0; i < pos; i++)
    {   
        Antes=iterador;
        iterador=iterador->sig;
    }
    Nodo *aux=new Nodo();
    if(iterador->sig==NULL){
        Antes->sig=NULL;
        delete iterador;
    }else{
        Antes->sig=iterador->sig;
        delete iterador;
    }
    

    

}


bool desp_lat(Nodo **inicio,Nodo **fin){
    int cond=1,contador=1;
    Nodo *iterador=*inicio;
    string opt;
    bool dir;
    int tam=sizeof_nodo(*inicio);
    cout<<"Desplazamiento lateral"<<endl<<endl;
    cout<<"Quieres empezar por el inicio o el final?";
    cin>>opt;
    if (opt[0]=='d'||opt[0]=='D')
    {
        /* code */
    }else if(opt[0]=='I'||opt[0]=='i'){

    
    
    cout<<"Actualmente se encuentra en pos "<<contador<<endl;
    iterador=iterador->sig;
    cout<<(*iterador);
    do
    {
        if(contador>1){
            cout<<"Actualmente se encuentra en pos "<<contador<<endl;
            cout<<(*iterador)<<endl;
        }

        if (contador>1&&tam>2)
        {
            cout<<"Deseas ir a la izquierda o a la derecha?"<<endl;
            cin>>opt;
            opt=="izquierda"?dir=false:dir=true;
            if (dir=true)
            {
                iterador=iterador->sig;
                contador++;
            }else if(dir=false&&iterador->ant!=NULL){
                iterador=iterador->ant;
                contador--;
            }
            

        }else{
            cout<<"Deseas Moverte una posicion a la derecha?"<<endl;
            cin>>opt;
            opt=="si"?dir=true:cond=0;
            if(iterador->sig==NULL){
            
            }else{
                if (cond==0)
                {
                    cond=0;
                }else if(dir==true){
                    iterador=iterador->sig;
                    contador++;

                }
                
            }
            
        }
        if(iterador==NULL){
            
        }
        cout<<endl;
        cout<<(*iterador);
    

    
    } while (opt!="salir");
    


}}


ostream& operator<<(ostream& print,Nodo list){
    print<<list.dato.id<<" "<<list.dato.nombre<<" "<<list.dato.apellido<<endl<<"Edad: "<<list.dato.edad<<endl<<"direccion: ";printf("%p",&list);cout<<endl<<"Direccion apuntada: ";printf("%p",list.sig);cout<<endl;
    return print;
}

Dato istr(){
    Dato list;
    cout<<"Introduce el nombre ";
    cin>>list.nombre;
    cout<<"introduce el apellido ";
    cin>>list.apellido;
    cout<<"introduce la edad ";
    cin>>list.edad;
    list.id=rand()%100;
    return list;
}
/*istream& operator>>(istream& save,Dato &list){
    cout<<"Introduce el nombre";
    save>>list.nombre;
    cout<<"introduce el apellido";
    save>>list.apellido;
    cout<<"introduce la edad";
    save>>list.edad;
    return save;
}*/