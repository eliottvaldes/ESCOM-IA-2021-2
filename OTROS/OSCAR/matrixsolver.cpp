#include<iostream>
#include<math.h>
using namespace std;
int main ()
{  
puts("Introduce el numero de filas y luego el de columnas");
int n,m,i,j,k;
scanf("%d", &n);
scanf("%d", &m);
float matrixpro[n][m] = {};
float AuxiliaResultado[n];
int auxtroll[n][m];
printf("ingrese las filas en orden tal que f1={x11,x12,x13,x14,x15,...,x1m},{x21,x22,x23,x23,x24...x2m} siendo m el resultado de la fila. Limtando cada entrada de la fila por un salto de linea  hasta las n filas ");
for (i = 0; i < n; i++)
{for ( j = 0; j < m; j++)
{cin>>matrixpro[i][j];}}  
      for (i=0;i<n;i++)
{
for (size_t i = 0; i < n; i++)
{for (size_t j = 0; j < m; j++)
{
  auxtroll[i][j]=0;
}  
}
for (size_t i = 0; i < n; i++)
{
  auxtroll[i][i]=1;
}
//Operacion de eliminacion por gauss-jordan
for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++)
    {  if (abs (matrixpro[i][i]) < abs (matrixpro[j][i]))
         {
             for (k=0; k<n+1;k++)
             {
                 /* intercambia los valores de la matrixpro[i][k] y matrixpro[j][k] */
                    swap(matrixpro[i][k],matrixpro[j][k]);
             }
         }
      float OperacionMatrices=matrixpro [j][i]/matrixpro [i][i];
         for (k=0; k<n+1;k++)
         {
           matrixpro[j][k]=matrixpro[j][k]-OperacionMatrices*matrixpro[i][k];}
           if(n!=m-1){{for(int l=j;l<m;l++){OperacionMatrices=matrixpro [i][l]/matrixpro [i][l];}
             for (k;k<m;k++)matrixpro[i+1][k]=matrixpro[i+1][k]-OperacionMatrices*matrixpro[i][k];}
           }}}
           
           // el proceso de acontinucion es la representacionn de la eliminacionn gauss jorda pero debido a que no se puede hacer de forma exacta por los decimales para arriba se tendra que hacer con na variable auxiliar
for (i=n-1;i>=0;i--)
{AuxiliaResultado[i]=matrixpro[i][n];
    for (j=i+1;j<n;j++)
    {
      if (i!=j)
      {
  AuxiliaResultado [i]=AuxiliaResultado [i]-matrixpro [i][j]*AuxiliaResultado[j];}}
  AuxiliaResultado [i]=AuxiliaResultado [i]/matrixpro [i][i];}
  cout<<"\nLos valores rresultantes de la matriz dada son los siguientes\n";
  if (matrixpro[n][m]==0 && matrixpro[n][m-1]==0)
  cout<<"la matriz tiene una infinidad de soluciones";
  if (matrixpro[n][m]==0 && matrixpro[n][m-1]!=0)
  cout<<"la matriz no tiene soluciones";
  if (matrixpro[n][m]!=0 && matrixpro[n][m-1]!=0){
  for (i=0;i<n;i++){
  { for (size_t j = 0; j < m-1; j++)
  printf(" %d ", auxtroll[i][j]);}
cout<<AuxiliaResultado[i]<<"\n";
  }}}
  cout<<"Las matriz para obtener los rangos (con eliminacion parcial) es la siguiente\n";
for (i=0;i<n;i++){
  { for (size_t j = 0; j < m-1; j++)
  printf(" %1.3f ", matrixpro[i][j]);}
  cout<<"\n";}
  return 0;}
           
