#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
int print_queue(queue<int> cola,int num);

int main(){
    int num,aux;
    queue<int> cola;
    cout<<"Cuantos elementos quieres generar?"<<endl;
    cin>>num;
    for (int i = 0; i < num; i++)
    {
        cout<<"Introduce el dato "<<i<<endl;
        cin>>aux;
        cola.push(aux);
    }
    print_queue(cola,num);

    system("pause");
    return 0;
}




int print_queue(queue<int> cola,int num){
    for (int i = 0; i < num; i++)
    {
        cout<<cola.front()<<" ";
        cola.pop();
    }
    
    
}