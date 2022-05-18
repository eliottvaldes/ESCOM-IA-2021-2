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

using namespace std;

int main(){
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
            break;
        case '[':
            signo.push('[');
            break;
        case ')':
            if (signo.top()=='(')
            {
                signo.pop();
                flag=true;
            }else{
                flag=false;
            }
            
            break;
        case ']':
            if(signo.top()=='['){
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