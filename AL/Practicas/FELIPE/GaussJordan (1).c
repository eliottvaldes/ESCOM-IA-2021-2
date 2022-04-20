/*      =======================================================================
        ===================INSTITUTO POLITECNICO NACIONAL======================
        =======================================================================
                            =============================
                            =ESCUELA SUPERIOR DE COMPUTO=
                            =============================
>>Name: Sánchez Martánez Felipe
>>Gruop: 2BM1
>>Carrer: Ing en Inteligencia Artificial
>>date of last modification: 03/01/22
                   
Gauss-Jordan
This program is the Gauss-Jordan algorithm, when inserting the number of variables and corresponding values, 
it will generate its solution indicating whether or not it exists

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h> 
#define TAM 30
#include <stdbool.h>

typedef struct{
    float matrix[TAM][TAM];
}Matrix;

void Impresionmatriz(Matrix* matrix, int n, int incognitas);
void Llenadomatriz(Matrix* matrix, int n, int incognitas, int filas);
void OperacionGauss(Matrix* matrix, int n);
void Solucion(Matrix* matrix, int n,int incognitas);
void CambioEcuaciones(Matrix* matrix, int n, int incognitas);
void IniciacionMatriz(Matrix* matrix, int Tam);

int i,j,k;

void main(){
    int n,x,filas;
    Matrix matrix;
    IniciacionMatriz(&matrix,TAM);
    puts("\n\n\n=============================================");
    puts("============ M A T R I X 'I N A T O R =======");
    puts("=============================================\n\n\n");
    fflush(stdin);
    printf("\nIngresa la cantidad de ecuaciones del sistema: ");
    scanf("%d",&n);
    fflush(stdin);

    printf("\nIngrese la cantidad de incognitas: ");
    scanf("%d",&x);
    filas=n;
    if(n<x){
        filas=x+1;
    }


    //Llenado de matrices
    Llenadomatriz(&matrix,n,x,filas);
    puts("\n\n\n=====================");
    puts("==== M A T R I Z ====");
    puts("=====================\n\n");
    Impresionmatriz(&matrix,n,x);

    CambioEcuaciones(&matrix,filas,x);
    Impresionmatriz(&matrix,n,x);

    OperacionGauss(&matrix,filas);
    puts("\n\n\n================================");
    puts("==== G A U S S  J O R D A N ====");
    puts("================================\n\n\n");
    Impresionmatriz(&matrix,n,x);
    // puts("Impresion");
    // Impresionmatriz(&matrix,n);
    // puts("Solucion");
    Solucion(&matrix,filas,x);
}
    
void IniciacionMatriz(Matrix* matrix, int Tam){
    for(i=0; i<=Tam-1; i++)
    {
        for(j=0; j<=Tam; j++)
        {
            matrix->matrix[i][j]=0;
        }
    }
}


void CambioEcuaciones(Matrix* matrix, int n, int incognitas){
    //Swap
    int k=0,random,e=0;
    float suma;
    int parametros=0,valores=0,r=0,l;
    srand(time(0));
    puts("\n\n\n=================================================");
    puts("==== A C O M O D O  D E  E C U A C I O N E S ====");
    puts("=================================================\n\n\n");
    Matrix matrixcambio;
    while(matrix->matrix[incognitas-1][incognitas-1]==0){
        for(j=0; j<=n;j++){
            matrixcambio.matrix[incognitas-1][j]=matrix->matrix[incognitas-1][j];
        }            
        random=(rand() % (n - k +1)) + k;

        for(j=0; j<=n;j++){
            matrix->matrix[incognitas-1][j]=matrix->matrix[random][j];
        }
        for(j=0; j<=n;j++){
            matrix->matrix[random][j]=matrixcambio.matrix[incognitas-1][j];
        }

    }

    for(i=0;i<=incognitas-1;i++){
        while(matrix->matrix[i][i]==0){
            for(j=0; j<=n;j++){
                matrixcambio.matrix[i][j]=matrix->matrix[i][j];
            }
            random=(rand() % (n - k +1)) + k;
            for(j=0; j<=n;j++){
                matrix->matrix[i][j]=matrix->matrix[random][j];
            }
            for(j=0; j<=n;j++){
                matrix->matrix[random][j]=matrixcambio.matrix[i][j];
            }
            e++;
            if(e==70){




                for(i=0;i<n;i++){
                        suma=0;
                        for(k=0; k<=n;k++){
                            suma=abs(suma)+matrix->matrix[i][k];
                            // printf("suma de suma %d\n",suma);
                        }
                        if(suma==0){
                            parametros++;
                            
                        }
                }

                for(i=0;i<n;i++){
                    suma=0;
                    for(k=0; k<=n;k++){
                        suma=abs(suma)+matrix->matrix[i][k];
                        // printf("suma de suma %d\n",suma);
                    }
                    if(suma==0){
                        printf("El sistema Tiene una infinidad de soluciones:\n");                valores=incognitas-parametros;
                        Matrix constante;

                        for(j=0;j<valores;j++){
                            for(i=0; i<valores; i++){
                                if(i!=j)
                                {
                                    if(matrix->matrix[j][j]==0)
                                        constante.matrix[0][0]=0;
                                    else
                                        constante.matrix[0][0]=matrix->matrix[i][j]/matrix->matrix[j][j];
                                    for(k=0; k<=n; k++)
                                    {
                                        matrix->matrix[i][k]=matrix->matrix[i][k]-constante.matrix[0][0]*matrix->matrix[j][k];

                                    }

                                }
                            }
                        }

                            
                        for(i=0;i<valores;i++){
                            r=parametros;
                            printf("\nX%d= %f", i+1,matrix->matrix[i][n]/matrix->matrix[i][i]);
                            for(j=valores; j<incognitas; j++){
                                printf("-%fP%d",matrix->matrix[i][j]/matrix->matrix[i][i],r);
                                r--;
                            }
                        }

                        l=parametros;
                        for(j=i; j<incognitas ; j++){
                            printf("\nX%d= P%d",j+1,l); 
                            l--;
                        }

                        exit(0);   
                    }
                }

            }
        }
        k++;

    }
    // for(i=0;i<=n-1;i++){
        // for(j=0; j<=n;j++){
        //     printf("Matriz[%d][%d]=\t%f\n",i,j,matrix->matrix[i][j]);
        //     while(k!=incognitas){

        //     }
    //     }
    // }


}

void Llenadomatriz(Matrix* matrix, int n, int incognitas,int filas){

    for(i=0; i<=n-1; i++){
        printf("\nPara la ecuacion %d: \n",i+1);
        for(j=0; j<incognitas; j++){
            fflush(stdin);
            printf("x%d= ",j+1);
            scanf("%f",&matrix->matrix[i][j]);
            printf("\n");
            if(j==incognitas-1){
                printf("C%d= ",i+1);
                scanf("%f",&matrix->matrix[i][filas]);
            }
        }
    }
}

void Impresionmatriz(Matrix* matrix, int n, int incognitas){
    for(i=0;i<=n-1;i++){
        printf("\n");
        for(j=0; j<incognitas;j++){
//            printf("Matriz[%d][%d]=\t%f\n",i,j,matrix->matrix[i][j]);
            printf("%fx%d\t",matrix->matrix[i][j],j+1);
            if(j==incognitas-1){
                printf("= %f",matrix->matrix[i][n]);
            }
        }

    }
//     printf("\n\n\n\n");
//     for(i=0;i<=n-1;i++){
//         printf("\n");
//         for(j=0; j<n;j++){
// //            printf("Matriz[%d][%d]=\t%f\n",i,j,matrix->matrix[i][j]);
//             printf("%fx%d\t",matrix->matrix[i][j],j+1);
//         }
//         printf("= %f\t",matrix->matrix[i][n]);
//     }
}


void OperacionGauss(Matrix* matrix, int n){
    Matrix constante;
    for(j=0;j<n;j++){
        for(i=0; i<n; i++){
            if(i!=j)
            {
                if(matrix->matrix[j][j]==0)
                    constante.matrix[0][0]=0;
                else
                    constante.matrix[0][0]=matrix->matrix[i][j]/matrix->matrix[j][j];
                for(k=0; k<=n; k++)
                {
                    matrix->matrix[i][k]=matrix->matrix[i][k]-constante.matrix[0][0]*matrix->matrix[j][k];

                }

            }
        }
    }

}

void Solucion(Matrix* matrix, int n, int incognitas){
    float suma;
    int parametros=0,valores=0,r=0,l;
    //Por filas
    puts("\n\n\n======================================");
    puts("==== S  O  L  U  C  I  O  N  E  S ====");
    puts("======================================\n\n");
    for(i=0;i<n;i++){
        suma=0;
        for(k=0; k<n;k++){
            // printf("\nvalor %f",matrix->matrix[i][k]);
            suma=abs(suma)+matrix->matrix[i][k];
            // printf("\n\n---%f\n",suma);
        }
        // printf("\n\nvalor matriz[1][0]=%f , matriz[1][1]=%f ",matrix->matrix[1][0],matrix->matrix[1][1]);
        // printf("suma=%f, valor de n=%f",suma,matrix->matrix[i][n]);
        if(abs(matrix->matrix[i][n])!=0 && suma==0){
            puts("El sistema No Tiene solucion");
            exit(0);
        }
    }




    for(i=0;i<n;i++){
            suma=0;
            for(k=0; k<=n;k++){
                suma=abs(suma)+matrix->matrix[i][k];
                // printf("suma de suma %d\n",suma);
            }
            if(suma==0){
                parametros++;
                
            }
    }

    for(i=0;i<n;i++){
        suma=0;
        for(k=0; k<=n;k++){
            suma=abs(suma)+matrix->matrix[i][k];
            // printf("suma de suma %d\n",suma);
        }
        if(suma==0){
            printf("El sistema Tiene una infinidad de soluciones:\n");                valores=incognitas-parametros;
            Matrix constante;

            for(j=0;j<valores;j++){
                for(i=0; i<valores; i++){
                    if(i!=j)
                    {
                        if(matrix->matrix[j][j]==0)
                            constante.matrix[0][0]=0;
                        else
                            constante.matrix[0][0]=matrix->matrix[i][j]/matrix->matrix[j][j];
                        for(k=0; k<=n; k++)
                        {
                            matrix->matrix[i][k]=matrix->matrix[i][k]-constante.matrix[0][0]*matrix->matrix[j][k];

                        }

                    }
                }
            }

                
            for(i=0;i<valores;i++){
                r=parametros;
                printf("\nX%d= %f", i+1,matrix->matrix[i][n]/matrix->matrix[i][i]);
                for(j=valores; j<incognitas; j++){
                    printf("-%fP%d",matrix->matrix[i][j]/matrix->matrix[i][i],r);
                    r--;
                }
            }

            l=parametros;
            for(j=i; j<incognitas ; j++){
                printf("\nX%d= P%d",j+1,l); 
                l--;
            }

            exit(0);   
        }
    }



    printf("\nSoluciones del sistema:\n");
    for(i=0;i<n;i++){
        for(j=0; j<n;j++){
            if(matrix->matrix[i][j]!=0){
                printf("\nX%d= %f\n", i+1,matrix->matrix[i][n]/matrix->matrix[i][j]);
                i++;
            }
        }
    }

    // for(i=0;i<n;i++){
    //     printf("\nX%d= %f\n", i+1,matrix->matrix[i][n]/matrix->matrix[i][i]);
    // }

}

//             mm    mm                      
//    *@@@@* *@@@    @@                      
//      @@     @@                            
//      @@     @@  *@@@  *@@@@@@@@m   mm@*@@ 
//      @@     !@    @@    @@   *@@  m@*   @@
//      @@     !@    !@    !@    @@  !@******
// @@!  @@     !@    !@    !@    !@  !@m    m
//      !!     !!    !!    !@!   !!  !!******
// !!!  !!     :!    !!    !@   !!!  :!!     
//  :!: :    : : : : : :   :!: : :    : : :: 
//                         ::                
//                       : : ::              
