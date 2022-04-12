/*
======================================
 ▪* Montero Barraza Alvaro David*
    *2BV1 Ingenieria en IA ▪*  
=======================================
 */
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<ctime>
using namespace std;


//push,pop,empty,size,front,top="elemento de mayor prioridad"


//Prototipos de funciones
bool most_que();

int main(){
    srand(time(0));
    int opt,tam=0,dato;
    priority_queue<int> pq;
    do
    {   
        cout<<"1.-Insertar elemento"<<endl<<"2.-Eliminar elemento"<<endl<<"3.-Ver elementos"<<endl;
        cin>>opt;
        switch (opt)
        {
        case 1:
            cout<<"Cuantos elementos quieres"<<endl;
            cin>>dato;
            for (int i = 0; i < dato; i++)
            {
                pq.push(rand()%1000);
            }
            
            
            
            break;
        case 2:
            
            break;
        case 3:
           
            break;
        default:
            cout<<"Introduce una opcion valida";
            break;
        }
    } while (opt!=5);
    

}





bool elim_elem(){
   
}


bool most_que(){
   
}

/*
================================================
===============Doble apuntador==================
================================================
int **arr=(int**)malloc(n,sizeof(int*));

for(int i;i<3,i++){
    arr[i]=(int*)malloc(n*sizeof(int))
}
*Se puede sustituir malloc con calloc*
*/