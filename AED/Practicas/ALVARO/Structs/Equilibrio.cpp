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
#include<C:\Users\Montero\Desktop\Algoritmos\Equilibrio\equilibrio.h>
using namespace std;

int main(){
    Nodo *inicio;
    inicio=new Nodo();
    stack<char> signo;
    string cadena;
    bool flag=true;
    int tam;
    cout<<"Introduce un string para ser analizado"<<endl;
    cin>>cadena;
    tam=cadena.size();
    cout<<tam<<endl;
    for (int i = 0; i < tam; i++)
    {
        switch (cadena[i])
        {
        case '(':
            signo.push('(');
            //pila_push(&inicio,'(');
            break;
        case '[':
            signo.push('[');
            //pila_push(&inicio,'[');
            break;
        case ')':
            if (signo.top()=='(') //if(inicio->caract=='(')
            {
                //pila_pop(&inicio);
                signo.pop();
                flag=true;
            }else{
                flag=false;
            }
            
            break;
        case ']':
            if(signo.top()=='[')//if(inicio->caract=='[')
            {
                //pila_pop(&inicio);
                signo.pop();
                flag=true;
            }else{
                flag=false;
            }
            break;
        
        default:
            break;
        }
        
    }
    if(signo.size()>0){
        flag=false;
    }
    if(flag){
        cout<<"Existe equilibrio"<<endl;
    }else{
        cout<<"No existe equilibrio"<<endl;
    }
    system("pause");
    



}