#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int numero_may(stack<int> pila,int num);
int impr_pila(stack<int> pila,int num);



int main(){
    int num,mayor;
    int intaux;
    stack<int> pila;
    cout<<"Cuantos datos quieres guardar"<<endl;
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cout<<"Dato "<<i<<endl;
        cin>>intaux;
        pila.push(intaux);
    }
        cout<<"Imprimiendo pila"<<endl;
        impr_pila(pila,num);
        cout<<"Buscando numero mayor"<<endl;
        mayor=numero_may(pila,num);
        cout<<"El numero mayor es: "<<mayor<<endl;
        system("pause");
return 0;
}

int numero_may(stack<int> pila, int num){
    stack<int> auxiliar;
    auxiliar.push(pila.top());
    for (int i = 0; i < num; i++)
    {
        if (auxiliar.top()>=pila.top())
        {
            pila.pop();
        }else{
            auxiliar.push(pila.top());
            pila.pop();
        }

    }
    return auxiliar.top();
}

int impr_pila(stack<int> pila,int num){
        for (int i = 0; i < num; i++)
        {
            cout<<pila.top()<<" ";
            pila.pop();
        }
        cout<<endl;

}