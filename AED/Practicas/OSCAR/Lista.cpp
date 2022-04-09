#include<iostream>
#include<stdlib.h>
using namespace std;
    typedef struct nodo
    {
    string Tipode;
    string dato;
    int diametro;
    struct nodo*siguiente=NULL;
    float dato2;
    }nodo;
    
void Agregaralfinal(nodo**);
void Agregaralinicio(nodo**);
void AgregaraPosN(nodo**);
void imprimirlista(nodo*);
void eliminarinicio(nodo**);
void eliminarfinal(nodo**);
void eliminarpos(nodo**);
ostream& operator<<(ostream&,nodo);
istream& operator>>(istream&,nodo&);
int main()
{
nodo* inicio=NULL;
int OpUser;
do
{
cout<<"Ingrese la opcion que de desea\n1.Agregar pizza al inicio\n2.Agregar una pizza al final\n3. Agregar pizza al lugar N\n4. Imprrimir inicio a fin\n5. Eliminar inicio\n6. Eliminar Final\n7.Eliminar pos\n8. Salir"<<endl;
cin>>OpUser;
switch(OpUser){
    case 1:
    Agregaralinicio(&inicio);
    break;
    case 2:
    Agregaralfinal(&inicio);
    break;
    case 3:
    AgregaraPosN(&inicio);
    break;
    case 4:
    imprimirlista(inicio);
    break;
    case 8:
    cout<<"Hasta luego :)"<<endl;
    break;
    case 5:
    eliminarinicio(&inicio);
    break;
    case 6:
    eliminarfinal(&inicio);
    break;
    case 7:
    eliminarpos(&inicio);
    break;
    default:
    cout<<"Opcion no valida"<<endl;
    break;
}}
while (OpUser!=8);
return 0;
}
void Agregaralinicio(nodo**inicio){
cout<<"Ingrese los datos en el siguinte orden "<<endl;
if(*inicio==NULL){
    nodo*nuevo=new(nodo);
    nuevo->siguiente=NULL;
    cin>>nuevo->diametro;
    cin>>nuevo->dato;
    cin>>nuevo->Tipode;
    *inicio=nuevo;
}
else
{   nodo*nuevo=new(nodo);
    nuevo->siguiente=*inicio;
    cin>>nuevo->diametro;
    cin>>nuevo->dato;
    cin>>nuevo->Tipode;
    *inicio=nuevo;
}
}
void Agregaralfinal(nodo**inicio){
cout<<"Ingrese los datos en el siguinte orden 1. Diametro, 2. Ingrediente principal de la pizza, 3. Tipo de masa de la pizza"<<endl;
    if(*inicio==NULL){
    nodo*nuevo=new(nodo);
    nuevo->siguiente=NULL;
    cin>>nuevo->diametro;
    cin>>nuevo->dato;
    cin>>nuevo->Tipode;
*inicio=nuevo;
}
else{
    nodo*nuevo=new(nodo);
    nodo*iterador1=*inicio;
    nuevo->siguiente=NULL;
    cin>>nuevo->diametro;
    cin>>nuevo->dato;
    cin>>nuevo->Tipode;
    while (iterador1->siguiente!=NULL)
    {
        iterador1=iterador1->siguiente;
    }
    iterador1->siguiente=nuevo;
}}
void AgregaraPosN(nodo**inicio){
    nodo*nuevo=new(nodo);
    nodo*iterador1=*inicio;
    int pos=0,contador=1;
    nuevo->siguiente=NULL;
    cout<<"Ingrese la poscion"<<endl;
    cin>>pos;
    cout<<"Ingrese los datos en el siguinte orden 1. Diametro, 2. Ingrediente principal de la pizza, 3. Tipo de masa de la pizza"<<endl;
    if(pos==1)Agregaralinicio(inicio);
    else{
    cin>>nuevo->diametro;
    cin>>nuevo->dato;
    cin>>nuevo->Tipode;
    while (contador<pos-1)
    {   
        iterador1=iterador1->siguiente;
        contador++;
    }
    nuevo->siguiente=iterador1->siguiente;
    iterador1->siguiente=nuevo;}
    }
void imprimirlista(nodo* inicio)
{   int cont=0;
    nodo*iterador1;
    iterador1=inicio;
    nodo*vacio;
  if (inicio!=NULL){vacio=inicio;
    while(vacio->siguiente!=NULL){
    	vacio=vacio->siguiente;
    	cont++;}
    while (iterador1->siguiente!=NULL)
    {   cout<<iterador1->dato<<endl;
        cout<<iterador1->Tipode<<endl;
        cout<<iterador1->diametro<<endl;
        iterador1=iterador1->siguiente;
    }
        cout<<iterador1->dato<<endl;
        cout<<iterador1->Tipode<<endl;
        cout<<iterador1->diametro<<endl;
}
}
void eliminarinicio(nodo**inicio){
    nodo *itera=*inicio;
    *inicio=(*inicio)->siguiente;
    delete itera;
}
void eliminarfinal(nodo**inicio){
    nodo *iterador1=*inicio;
    nodo *iterador2=*inicio;
    int contador=0;
    while (iterador1->siguiente!=NULL)
    {   
        iterador1=iterador1->siguiente;
        contador++;
    }
    for (size_t i = 0; i < contador-1; i++)
    {
        iterador2=iterador2->siguiente;
    }
    delete iterador1;
    iterador2->siguiente=NULL;
}
void eliminarpos(nodo**inicio){
    int pos=0,contador=1;
    nodo*iterador1=*inicio;
    nodo*iterador2=*inicio;
    cout<<"Ingrese la poscion"<<endl;
    cin>>pos;
    if(pos==1)eliminarinicio(inicio);
    else{
    while (contador<pos-1)
    {   iterador1=iterador1->siguiente;
        contador++;
    }
    iterador2=iterador1->siguiente;
    iterador1->siguiente=iterador1->siguiente->siguiente;
    if (iterador1==NULL)
    {
        eliminarfinal(inicio);
    }
    else 
    delete iterador2;
    }
    }
ostream& operator<<(ostream& os, nodo est){
 	    os<<"\n campo diametro "<<est.diametro;
 		os<<"\n campo tipo de maza "<<est.Tipode;
 		os<<"\n campo ingrediente principal "<<est.dato;
        os<<"\n campo precio "<<est.dato2;
 		return os;
 }
istream& operator>>(istream& in, nodo& est){
 	      cin>>est.diametro;
        cin>>est.Tipode;
        cin>>est.dato;
        cin>>est.dato2;
 		return in;
 }
