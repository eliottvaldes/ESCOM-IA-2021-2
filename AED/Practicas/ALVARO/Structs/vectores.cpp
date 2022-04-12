#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<stack>
//vector y stack
using namespace std;

int main(){
vector<int> objeto;
vector<int>aux;
for (int i = 0; i < 50; i++)
{
    objeto.push_back(rand()%10);;
   
}
for (int i = 0; i < 50; i++)
{
    cout<<objeto.at(i)<<" ";
    
}


system("pause");
return 0;  
}