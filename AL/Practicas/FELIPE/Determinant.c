/*      =======================================================================
        ===================INSTITUTO POLITECNICO NACIONAL======================
        =======================================================================
                            =============================
                            =ESCUELA SUPERIOR DE COMPUTO=
                            =============================
>>Name: Sánchez Martánez Felipe
>>Gruop: 2BM1
>>Carrer: Artificial Intelligence engineer
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


void MatrixPrinting(Matrix* matrix, int n, int unknown);
void MatrixFilling(Matrix* matrix, int n, int unknown, int rows);
void OperacionGauss(Matrix* matrix, int n);
void MatrixSolution(Matrix* matrix, int n,int unknown);
void SwapA(Matrix* matrix, int n, int unknown);
void SwapB(Matrix* matrix, int n, int unknown);
void MatrixStarting(Matrix* matrix, int Tam);

void SquareMatrixFilling(Matrix* matrix, int n);
void SquareAA(Matrix* matrix, int n);
int SquareDeterminantA(Matrix* matrix, int n,float det);
void SquareDeterminantAA(Matrix* matrix, int n,float det);
void SquareInverseA(Matrix* matrix,Matrix* matrixInverse, int n);
void SquareMatrixPrinting(Matrix* matrix, int n);
void SquareMatrixCopy(Matrix* matrix,Matrix* squareMatrixCopy, int n);

int i,j,k;

void main(){
    int n,x,rows,option;
    bool flag;
    float det;
    Matrix matrix;
    Matrix squareMatrix;
    Matrix squareMatrixCopy;
    Matrix squareMatrixInverse;
 
    do{
    puts("\n\nWich operation dou you want to do?");
    puts("1.- A*A");
    puts("2.- |A|");
    puts("3.- |A*A|");
    puts("4.- Find A^-1");
    puts("5.- Insert a new square matrix");
    puts("6.- Solve a mayrix Mmxn");
    puts("7.- Get out of the program");
    fflush(stdin);
    scanf("%d", &option);
    switch(option){
        case 1:
            if(flag){
                SquareMatrixCopy(&squareMatrix,&squareMatrixCopy,n);
                SquareAA(&squareMatrixCopy,n);
                SquareMatrixPrinting(&squareMatrixCopy,n);
                break;
            }else{
                puts("First pls insert a matrix Mnxn   ");
            break;
            }

        case 2:
            if(flag ){
                SquareMatrixCopy(&squareMatrix,&squareMatrixCopy,n);
                SquareDeterminantA(&squareMatrixCopy,n,det);
                SquareMatrixPrinting(&squareMatrixCopy,n);
                break;
            }else{
                puts("First pls insert a matrix Mnxn   ");     
                break;
            }
        case 3:


            if(flag ){
                SquareMatrixCopy(&squareMatrix,&squareMatrixCopy,n); 
                SquareDeterminantAA(&squareMatrixCopy,n,det); 
                SquareMatrixPrinting(&squareMatrixCopy,n);
                break;
            }else{
                puts("First pls insert a matrix Mnxn   ");     
                break;
            }

        case 4:
            if(flag){
                if(det==0){
                    puts("That matrix has not inverse because the determinant is 0");
                    break;
                }else{
                    SquareMatrixCopy(&squareMatrix,&squareMatrixCopy,n);  
                    SquareInverseA(&squareMatrix,&squareMatrixInverse,n);
                    SquareMatrixPrinting(&squareMatrixCopy,n);
                break;

                }
            }else{
                puts("First pls insert a matrix Mnxn   ");     
                break;
            }

        case 5:
            printf("\nInsert the number of n for a matrix Mnxn: ");
            fflush(stdin);
            scanf("%d",&n);
            SquareMatrixFilling(&squareMatrix,n);
            SquareMatrixPrinting(&squareMatrix,n);
            flag=true;
            break;
        case 6:
            puts("Nice option for today");
            MatrixStarting(&matrix,TAM);
            puts("\n\n\n=============================================");
            puts("============ M A T R I X 'I N A T O R =======");
            puts("=============================================\n\n\n");
            fflush(stdin);
            puts("This program solves a Matrix mxn, using the GaussJordan method, and writes it's solutions");
            printf("\nInsert the number of equations: ");
            fflush(stdin);
            scanf("%d",&n);

            printf("\nInsert the number of variables: ");
            scanf("%d",&x);
            rows=n;
            if(n<x){
                rows=x;
            }

            MatrixFilling(&matrix,n,x,rows);
            puts("\n\n\n=====================");
            puts("==== M A T R I X ====");
            puts("=====================\n\n");
            MatrixPrinting(&matrix,n,x);

            SwapA(&matrix,rows,x);
            MatrixPrinting(&matrix,n,x);

            OperacionGauss(&matrix,rows);
            puts("\n\n\n================================");
            puts("==== G A U S S  J O R D A N ====");
            puts("================================\n\n\n");
            MatrixPrinting(&matrix,n,x);
            MatrixSolution(&matrix,rows,x);
            break;
        case 7:
            puts("Have a nice day :)");
            exit(0);
            break;
        default:
            puts("Pls insert a correct value");
            break;
    }

    }while(true);

}
    
void MatrixStarting(Matrix* matrix, int Tam){
    for(i=0; i<=Tam-1; i++)
    {
        for(j=0; j<=Tam; j++)
        {
            matrix->matrix[i][j]=0;
        }
    }
}


void SwapA(Matrix* matrix, int n, int unknown){
    //Swap
    int k=0,random,e=0;
    float sum;
    int parameters=0,values=0,r=0,l;
    srand(time(0));
    puts("\n\n\n======================================");
    puts("==== E Q U A T I O N  C H A N G E ====");
    puts("======================================\n\n\n");
    Matrix matrixchange;
    while(matrix->matrix[unknown-1][unknown-1]==0){
        for(j=0; j<=n;j++){
            matrixchange.matrix[unknown-1][j]=matrix->matrix[unknown-1][j];
        }            
        random=(rand() % (n - k +1)) + k;

        for(j=0; j<=n;j++){
            matrix->matrix[unknown-1][j]=matrix->matrix[random][j];
        }
        for(j=0; j<=n;j++){
            matrix->matrix[random][j]=matrixchange.matrix[unknown-1][j];
        }

    }

    for(i=0;i<=unknown-1;i++){
        while(matrix->matrix[i][i]==0){
            for(j=0; j<=n;j++){
                matrixchange.matrix[i][j]=matrix->matrix[i][j];
            }
            random=(rand() % (n - k +1)) + k;
            for(j=0; j<=n;j++){
                matrix->matrix[i][j]=matrix->matrix[random][j];
            }
            for(j=0; j<=n;j++){
                matrix->matrix[random][j]=matrixchange.matrix[i][j];
            }
            e++;
            if(e==70){
                puts("\n\n\n============================");
                puts("==== S  O L U T I O N S ====");
                puts("============================\n\n");




                for(i=0;i<n;i++){
                    sum=0;
                    for(k=0; k<n;k++){
                        // printf("\nvalor %f",matrix->matrix[i][k]);
                        sum=abs(sum)+matrix->matrix[i][k];
                        // printf("\n\n---%f\n",sum);
                    }
                    // printf("\n\nvalor matriz[1][0]=%f , matriz[1][1]=%f ",matrix->matrix[1][0],matrix->matrix[1][1]);
                    // printf("sum=%f, valor de n=%f",sum,matrix->matrix[i][n]);
                    if(abs(matrix->matrix[i][n])!=0 && sum==0){
                        puts("That matrix has not solution");
                        exit(0);
                    }
                }



                    sum=0;
                    for(k=0; k<n;k++){
                                        // printf("\nvalor %f",matrix->matrix[i][k]);
                        sum=abs(sum)+matrix->matrix[1][k];
                                        // printf("\n\n---%f\n",sum);
                    }
                    if(abs(matrix->matrix[1][n])==0 && sum==0){
                        puts("gg");
                    }



                for(i=0;i<n;i++){
                    sum=0;
                    for(k=0; k<=n;k++){
                        sum=abs(sum)+matrix->matrix[i][k];
                    }
                    if(sum==0){
                        parameters++;
                            
                    }
                }


                for(i=0;i<n;i++){
                    sum=0;
                    for(k=0; k<=n;k++){
                        sum=abs(sum)+matrix->matrix[i][k];
                        // printf("sum de sum %d\n",sum);
                    }
                    if(sum==0){
                        printf("That matrix has infinity solutions:\n");                
                        values=unknown-parameters;
                        Matrix constant;

                        for(j=0;j<values;j++){
                            for(i=0; i<values; i++){
                                if(i!=j)
                                {
                                    if(matrix->matrix[j][j]==0)
                                        constant.matrix[0][0]=0;
                                    else
                                        constant.matrix[0][0]=matrix->matrix[i][j]/matrix->matrix[j][j];
                                    for(k=0; k<=n; k++)
                                    {
                                        matrix->matrix[i][k]=matrix->matrix[i][k]-constant.matrix[0][0]*matrix->matrix[j][k];

                                    }

                                }
                            }
                        }

                            
                        for(i=0;i<values;i++){
                            r=parameters;
                            printf("\nX%d= %f", i+1,matrix->matrix[i][n]/matrix->matrix[i][i]);
                            for(j=values; j<unknown; j++){
                                printf("-%fP%d",matrix->matrix[i][j]/matrix->matrix[i][i],r);
                                r--;
                            }
                        }

                        l=parameters;
                        for(j=i; j<unknown ; j++){
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
        //     while(k!=unknown){

        //     }
    //     }
    // }


}

void SwapB(Matrix* matrix, int n, int unknown){
    int k=0,random,e=0;
    float sum;
    int parameters=0,values=0,r=0,l;
    srand(time(0));
}


void MatrixFilling(Matrix* matrix, int n, int unknown,int rows){

    for(i=0; i<=n-1; i++){
        printf("\nFor the equation %d: \n",i+1);
        for(j=0; j<unknown; j++){
            fflush(stdin);
            printf("x%d= ",j+1);
            scanf("%f",&matrix->matrix[i][j]);
            printf("\n");
            if(j==unknown-1){
                printf("C%d= ",i+1);
                scanf("%f",&matrix->matrix[i][rows]);
            }
        }
    }
}

void MatrixPrinting(Matrix* matrix, int n, int unknown){
    for(i=0;i<=n-1;i++){
        printf("\n");
        for(j=0; j<unknown;j++){
//            printf("Matriz[%d][%d]=\t%f\n",i,j,matrix->matrix[i][j]);
            printf("%fx%d\t",matrix->matrix[i][j],j+1);
            if(j==unknown-1){
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
    Matrix constant;
    for(j=0;j<n;j++){
        for(i=0; i<n; i++){
            if(i!=j)
            {
                if(matrix->matrix[j][j]==0)
                    constant.matrix[0][0]=0;
                else
                    constant.matrix[0][0]=matrix->matrix[i][j]/matrix->matrix[j][j];
                for(k=0; k<=n; k++)
                {
                    matrix->matrix[i][k]=matrix->matrix[i][k]-constant.matrix[0][0]*matrix->matrix[j][k];

                }

            }
        }
    }

}

void MatrixSolution(Matrix* matrix, int n, int unknown){
    float sum;
    Matrix matrixchange;
    int parameters=0,values=0,r=0,l;
    //Por rows
    puts("\n\n\n======================================");
    puts("==== S  O  L  U  C  I  O  N  E  S ====");
    puts("======================================\n\n");
    for(i=0;i<n;i++){
        sum=0;
        for(k=0; k<n;k++){
            sum=abs(sum)+matrix->matrix[i][k];
        }
        if(abs(matrix->matrix[i][n])!=0 && sum==0){
            puts("That matrix has not solutions");
            exit(0);
        }
    }

    for(i=0;i<n;i++){
            sum=0;
            for(k=0; k<=n;k++){
                sum=abs(sum)+matrix->matrix[i][k];
            }
            if(sum==0){
                parameters++;
                
            }
    }




    for(i=0;i<n;i++){
        sum=0;
        for(k=0; k<=n;k++){
            sum=abs(sum)+matrix->matrix[i][k];

        }
        if(sum==0){
            printf("That matrix has infinity solutions:\n");                
            values=unknown-parameters;
            Matrix constant;

            for(j=0;j<values;j++){
                for(i=0; i<values; i++){
                    if(i!=j)
                    {
                        if(matrix->matrix[j][j]==0)
                            constant.matrix[0][0]=0;
                        else
                            constant.matrix[0][0]=matrix->matrix[i][j]/matrix->matrix[j][j];
                        for(k=0; k<=n; k++)
                        {
                            matrix->matrix[i][k]=matrix->matrix[i][k]-constant.matrix[0][0]*matrix->matrix[j][k];

                        }

                    }
                }
            }

            for(i=0;i<values;i++){
                r=parameters;
                printf("\nX%d= %f", i+1,matrix->matrix[i][n]/matrix->matrix[i][i]);
                for(j=values; j<unknown; j++){
                    printf("-%fP%d",matrix->matrix[i][j]/matrix->matrix[i][i],r);
                    r--;
                }

            }

            l=parameters;
            for(j=i; j<unknown ; j++){
                printf("\nX%d= P%d",j+1,l); 
                l--;
            }

            exit(0);   
        }
    }
    printf("\nMatrix Solutions:\n");
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


void SquareMatrixFilling(Matrix* matrix, int n){
    for(i=0; i<=n-1; i++){
        printf("\nFor the equation %d: \n",i+1);
        for(j=0; j<=n-1; j++){
            fflush(stdin);
            printf("x%d= ",j+1);
            scanf("%f",&matrix->matrix[i][j]);
            printf("\n");
        }
    }    
}

void SquareMatrixCopy(Matrix* matrix,Matrix* squareMatrixCopy, int n){
    for(i=0; i<=n-1; i++){
        for(j=0; j<=n-1; j++){
            squareMatrixCopy->matrix[i][j]=matrix->matrix[i][j];
        }
    } 
}

void SquareAA(Matrix* matrix, int n){
    for(i=0; i<=n-1; i++){
        for(j=0; j<=n-1; j++){
            matrix->matrix[i][j]=matrix->matrix[i][j]*matrix->matrix[i][j];
        }
    } 
}


int SquareDeterminantA(Matrix* matrix, int n, float det){
    float  ratio;
    float sumRow,sumColum,sumRowA;
    int l=0;
    det=1;
    for(i=0;i<n;i++){
        sumRow=0;
        sumColum=0;
        for(k=0; k<n;k++){
            sumRow=abs(sumRow)+matrix->matrix[i][k];
            sumColum=abs(sumColum)+matrix->matrix[k][i];
        }
        if(sumRow==0 || sumColum==0){
            puts("Determinant of given matrix is: 0");
            det=0;
            return det;   
        }
    }

    for(i=0;i<n;i++){
        sumRow=0;
        sumRowA=0;
        l=0;
        for(k=0; k<n;k++){
            sumRow=abs(sumRow)+matrix->matrix[i][k];
        }
        // printf("========%f suma fila %d\n",sumRow, i);
        while(l<n){
            sumRowA=0;
            if(i==l){
                l++;
            }

            for(k=0; k<n;k++){
                sumRowA=abs(sumRowA)+matrix->matrix[l][k];
            }
            // printf("========%f suma fila %d\n",sumRowA, l);

            if(sumRowA==sumRow){
                puts("Determinant of given matrix is: 0");
                // puts("absqui entra");
                det=0;
                return det;   
            }
            l++;
        }
    }

    for(i=0;i< n;i++)
    {
        for(j=i+1;j< n;j++)
        {
            ratio = matrix->matrix[j][i]/matrix->matrix[i][i];

            for(k=0;k< n;k++)
            {
                matrix->matrix[j][k] = matrix->matrix[j][k] - ratio*matrix->matrix[i][k];
            }
        }
    }
    for(i=0;i< n;i++)
    {
        det = det * matrix->matrix[i][i];
    }
    printf("\n\nDeterminant of given matrix is: %0.3f\n", det);
    return det;
} 


void SquareDeterminantAA(Matrix* matrix, int n,float det){
    for(i=0; i<=n-1; i++){
        for(j=0; j<=n-1; j++){
            matrix->matrix[i][j]=matrix->matrix[i][j]*matrix->matrix[i][j];
        }
    }
    SquareDeterminantA(matrix,n,det);
}


void SquareInverseA(Matrix* matrix,Matrix* matrixInverse, int n){




}
void SquareMatrixPrinting(Matrix* matrix, int n){
   for(i=0;i<=n-1;i++){
        printf("\n");
        for(j=0; j<=n-1;j++){
//            printf("Matriz[%d][%d]=\t%f\n",i,j,matrix->matrix[i][j]);
            printf("%fx%d\t",matrix->matrix[i][j],j+1);
        }

    }
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
