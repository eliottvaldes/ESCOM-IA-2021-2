/*
======================================
 ▪* Montero Barraza Alvaro David*
     *2BV1 Ingenieria en IA ▪*  
=======================================
 */
#include<iostream>
#include<string>
#include<stack>
#include<stdlib.h>
#include"equilibrio.h"
using namespace std;

int main(){
    Nodo *inicio=nullptr;
    stack<char> signo;
    string cadena;
    bool flag=true,sflag=true;
    int tam;
    cout<<"Introduce un string para ser analizado"<<endl;
    cin>>cadena;
    tam=cadena.size();
    cout<<tam<<endl;
    for (int i = 0; i < tam; i++)
    {
        switch (cadena[i])
        {
        case '{':
            pila_push(&inicio,'{');
            break;
        case '(':
            pila_push(&inicio,'(');
            break;
        case '[':
            
            pila_push(&inicio,'[');
            break;
        case '}':
            if(pila_empty(inicio)){//checamos si nuestra pila está vacia
                flag=false;
                sflag=false;
            }
            else if(inicio->caract=='{')
            {
                pila_pop(&inicio);
                flag=true;
            }else{
                flag=false;
                sflag=false;
            }
            break;
        case ')':
             if(pila_empty(inicio)){//checamos si nuestra pila está vacia
                flag=false;
                sflag=false;
            }
            else if(inicio->caract=='(')
            {
                pila_pop(&inicio);
                flag=true;
            }else{
                flag=false;
                sflag=false;
            }
            
            break;
        case ']':
            if(pila_empty(inicio)){
                flag=false;
            }
            else if(inicio->caract=='[')
            {
                pila_pop(&inicio);
                flag=true;
            }else{
                flag=false;
                sflag=false;
            }
            break;
        
        default:
            break;
        }
        
    }
    if (pila_size(inicio)>0)
    {
        flag=false;
    }
    
    if(flag&&sflag){
        cout<<"Existe equilibrio"<<endl;
    }else{
        cout<<"No existe equilibrio"<<endl;
    }
    system("pause");
    



}