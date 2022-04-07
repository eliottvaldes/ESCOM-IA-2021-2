#include<iostream>
#include<math.h>
using namespace std;
double determinate(int n,double matrixpro[][10]){
  int i,j,k;
  int signos=1;
  double determinante=1;
  for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++){  
       if (abs (matrixpro[i][i]) < abs (matrixpro[j][i]))
          {signos=signos*(-1);
              for (k=0; k<n;k++)
              {   
                  /* intercambia los valores de la matrixpro[i][k] y matrixpro[j][k] */
                     swap(matrixpro[i][k],matrixpro[j][k]);
              }
          }
      double OperacionMatrices=matrixpro [j][i]/matrixpro [i][i];
         for (k=0; k<n;k++)
         {
           matrixpro[j][k]=matrixpro[j][k]-OperacionMatrices*matrixpro[i][k];}
           }}  
  // for (size_t i = 0; i <n; i++)
  // {if (matrixpro[i][i]==0)
  // cout<<"la matriz tiene una infinidad de soluciones";return 0;}
             for (size_t i = 0; i < n; i++)
  { 
    determinante=determinante*matrixpro[i][i];
  }
  return determinante*signos;
}
double cofactor(double matrixpor[][10], int n, int fila, int columna){
   double submatriz[n][10];
   int TAM = n-1;
   int x = 0;
   int y = 0;
   for (int i = 0; i< n; i++) {
      for (int j = 0; j< n; j++) {
         if (i != fila && j != columna) {
             submatriz[x][y] = matrixpor[i][j];
             y++;
             if (y >= TAM) {
                 x++;
               y = 0;}}}}
   return pow(-1.0,fila+1+columna+1)*determinate(TAM,submatriz);}
double matrixporcofactores(double matrixpro[][10],int n,int i,int j){
  double coofacttor;
      coofacttor=cofactor(matrixpro,n,i,j);  
      return coofacttor;
}

int main ()
{  
puts("Introduce el numero de filas o ecuacionmes ");
int n,i,j,k;
scanf("%d", &n);
double matrixpro[n][10];
double matrixmultiplicada[n][10];
double AuxiliaResultado[n];
double matrixcofactor[n][10];
int auxtroll[n][n];
int signos=1;
double determinante;
double mira;
printf("ingrese las filas en orden tal que f1={x11,x12,x13,x14,x15,...,x1m},{x21,x22,x23,x23,x24...x2m} siendo n el resultado de la fila. Limtando cada entrada de la fila por un salto de linea  hasta las n filas ");
for (size_t i = 0; i < n; i++)
{
  for (size_t j = 0; j <n; j++)
  {
    cin>>matrixpro[i][j];
  }
}

for (size_t i = 0; i < n; i++)
{ 
  auxtroll[i][i]=1;
}
for (size_t i = 0; i < n; i++)
{
  for (size_t j = 0; j < n; j++)
  {
    matrixcofactor[i][j]=matrixporcofactores(matrixpro,n,i,j);   
    mira=matrixcofactor[i][j];
  }
  
}
for (i=0; i<n; i++){for (j=0; j<n; j++){matrixmultiplicada [i][j]=0;for (k=0; k<n; k++){
matrixmultiplicada [i][j]=matrixmultiplicada[i][j]+(matrixpro[i][k]*matrixpro[k][j]);
mira=matrixmultiplicada[i][j];}}}
determinante=determinate(n,matrixpro);
//Operacion de eliminacion por gauss-jordan
for (i=0;i<n-1;i++){
    for (j=i+1;j<n;j++){  
       if (abs (matrixpro[i][i]) < abs (matrixpro[j][i]))
          {
              for (k=0; k<n;k++)
              {   signos=signos*-1;
                  /* intercambia los valores de la matrixpro[i][k] y matrixpro[j][k] */
                     swap(matrixpro[i][k],matrixpro[j][k]);
              }
          }
      double OperacionMatrices=matrixpro [j][i]/matrixpro [i][i];
         for (k=0; k<n;k++)
         {
           matrixpro[j][k]=matrixpro[j][k]-OperacionMatrices*matrixpro[i][k];}
          //  if(n!=m-1){{for(int l=j;l<m;l++){OperacionMatrices=matrixpro [i][l]/matrixpro [i][l];}
          //    for (k;k<m;k++)matrixpro[i+1][k]=matrixpro[i+1][k]-OperacionMatrices*matrixpro[i][k];}}
           }}
           
           // el proceso de acontinucion es la representacionn de la eliminacionn gauss jorda pero debido a que no se puede hacer de forma exacta por los decimales para arriba se tendra que hacer con na variable auxiliar
for (i=n-1;i>=0;i--)
{AuxiliaResultado[i]=matrixpro[i][n];
    for (j=i+1;j<n;j++)
    {
      if (i!=j)
      {
  AuxiliaResultado [i]=AuxiliaResultado [i]-matrixpro [i][j]*AuxiliaResultado[j];}}
  AuxiliaResultado [i]=AuxiliaResultado [i]/matrixpro [i][i];}
//   cout<<"Las matriz rankeada (con eliminacion parcial) es la siguiente\n";
// for (i=0;i<n;i++){
//   { for (size_t j = 0; j < n; j++)
//   printf(" %1.3lf ", matrixpro[i][j]);}
//   cout<<"\n";}
//   cout<<"el cuadrado de la matriz es"<<endl;
  for (i=0;i<n;i++){
  { for (size_t j = 0; j < n; j++)
  printf(" %1.3lf ", matrixmultiplicada[i][j]);}
  cout<<"\n";}
  if (determinante==0 ||n==0 ||determinante!=determinante)
  {
  cout<<"la tiene una infinida de soluciones por tanto el determinante simpre es 0 y no exite matris inversa"<<endl;  return 0;
  }
  
  cout<<"la matriz inversa es"<<endl;
  for (i=0;i<n;i++){
  { for (size_t j = 0; j < n; j++)
 cout<<matrixcofactor[j][i]*(1/determinante)<<" ";}
  cout<<"\n";}
  cout<<"de otra forma se puede ver como la matriz transpuesta de cofactores por 1/"<<determinante<<endl;
  for (i=0;i<n;i++){
  { for (size_t j = 0; j < n; j++)
 cout<<matrixcofactor[j][i]<<"/"<<determinante<<" ";}
  cout<<"\n";}

  cout<<"el determinante es "<<determinante<<endl;
    cout<<"el determinante es "<<determinante*determinante<<endl;
  cout<<determinate(n,matrixmultiplicada)<<endl;
  return 0;}
