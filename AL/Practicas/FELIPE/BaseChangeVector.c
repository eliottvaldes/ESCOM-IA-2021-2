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
                   
Lienar Algebra
This program will play with the vectors and the Vector space
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h> 
#include <stdbool.h>
#define TAM 30

typedef struct{
    float matrix[TAM][TAM];
}Matrix;
//R is the number of rows   R=n
//VecorNumber will be the number of columns vectorsNumber=unknown
int i,j,k,w,R,l,vectorsNumber;
//THIS FLAG IS TO KNOW
//THE CONCLUSION OF THE FUNCION
bool flag;
bool flagTGmain;
bool flagBTG;
bool flagBLI;
bool flagLI;

float dataInf[90];

void BothFunction();
void Canonic();
void ChangeBase();
void MatrixStartingCanonic(Matrix* matrix, int Tam);
//FROM Vector's program
void LinearCombination(Matrix matrixB1, Matrix matrixB2, Matrix* matrixChangeBase, int counter, int R, int vectorsNumber);


void swap(Matrix* matrix,int aux, int R, int vectorsNumber);
void swapInit(Matrix* matrix,int R, int vectorsNumber);
bool isBasis(Matrix matrix, int R, int vectorsNumber);
//FroM GaussJordan's Program
void MatrixStarting(Matrix* matrix, int Tam);
void OperacionGauss(Matrix* matrix, int n, Matrix* matrixEqua, int vectorsNumber);
void MatrixPrinting(Matrix* matrix, int rows, int columns);
void MatrixSolutionLC(Matrix* matrix, int n,int unknown);
void MatrixSolutionTG(Matrix* matrix, int n,int unknown, Matrix* matrixEqua);
void OperacionGaussLinealIndependenci(Matrix* matrix, int n, Matrix* matrixEqua, int vectorsNumber);

void main(){
    int option;
    Matrix matrix;
    /* code */
    puts("\n\n\n=============================================");
    puts("============ V E C T O R  B A S E 'I N A T O R =======");
    puts("=============================================\n\n\n");
    do{
        //INIT OF EVERYTHING
        MatrixStarting(&matrix,TAM);
        flag=false;
        flagTGmain=false;
        flagBTG=false;
        flagBLI=false;
        flagLI=false;
        puts("What do U wanna do?");
        puts("1.- Change the base of Vector.");
        puts("2.- Canonic.");
        puts("3.- Both LMAO");
        puts("4.- Close the program.");
        fflush(stdin);
        scanf("%d",&option);
        switch(option){
            case 1:
                ChangeBase();
                break;
            case 2:
                Canonic();
                break;
            case 3:
                BothFunction();
                puts("GG");
                break;
            case 4:
                puts("Have a nice day :)");
                exit(0);
                break;
            default:
                puts("Pls select a correct option");
                printf("\n\n\n");
                break;

        }

    }while (true);
    
}




void ChangeBase(){
    Matrix matrixChangeBase;
    Matrix matrixB1;
    Matrix matrixB2;
    Matrix matrixNewBase;
    int counter;
    float value=0;

    MatrixStarting(&matrixB1,TAM);
    MatrixStarting(&matrixB2,TAM);
    MatrixStarting(&matrixChangeBase,TAM);
    MatrixStarting(&matrixNewBase,TAM);
    puts("\n\n\n=============================================");
    puts("================ CHANGE BASE =============");
    puts("=============================================\n\n\n");
    puts("REMEMBER THAT B1 & B2 SHOULD BE A BASIS OF THE VECTORIAL SPACE V");
    puts("Insert the dimension of R:");
    fflush(stdin);
    scanf("%d",&R);
    printf("\n\n");
    //WEE START MAKING THE INIT OF THE MATRIX AND FULLING WITH THE DATA
    puts("Insert the number of Vectors:");
    fflush(stdin);
    scanf("%d",&vectorsNumber);
    printf("\n\n");
    //LET'S FILL BOTH MATRIX
    puts("INSERT THE VALUE FOR B1");
    for(i=0; i<vectorsNumber; i++){
        printf("\nFor the vector # %d: \n",i+1);
        for(j=0; j<R; j++){
            printf("Insert the data of the number #%d\n",j+1);
            fflush(stdin);
            scanf("%f",&matrixB1.matrix[j][i]);
        }
    }
    puts("INSERT THE VALUE FOR B2");
    for(i=0; i<vectorsNumber; i++){
        printf("\nFor the vector # %d: \n",i+1);
        for(j=0; j<R; j++){
            printf("Insert the data of the number #%d\n",j+1);
            fflush(stdin);
            scanf("%f",&matrixB2.matrix[j][i]);
        }
    }
    
    // MatrixPrinting(&matrixB1, R, vectorsNumber);
    // MatrixPrinting(&matrixB2, R, vectorsNumber);

//isBasis(matrixB1, R, vectorsNumber)
    if(isBasis(matrixB1, R, vectorsNumber)){
        if(isBasis(matrixB2, R, vectorsNumber)){
            //THE MAIN PROGRAM :3

            //LET'S FIND THE MATRIX CHANGE BASE
            //REMEMBER USE THE LINEAR COMBINATION
            //This is for the coulumns of the matrix

            for(counter=0; counter<R; counter++){
                LinearCombination(matrixB1,matrixB2, &matrixChangeBase, counter, R,vectorsNumber);
            }
            puts("SO THE MATRIX CHANGE BASE IS:");
            // MatrixPrinting(&matrixChangeBase, R, vectorsNumber);
            
            //LET'S SOLVE SOME BUGS WHEN -0.00000000
            value=0;
            for(i=0;i<R;i++){

                for(k=0; k<R;k++){
                    // printf("valor de i=%d, sum=%f, sumA=%f\n",i,sum,sumA);
                    value=matrixChangeBase.matrix[i][k];
                    if(value<=0.0000009 && value>=-0.0000009){
                        matrixChangeBase.matrix[i][k]=abs(matrixChangeBase.matrix[i][k]);
                        // puts("ENTRA");
                    }
                    value=0;
            
                }

            }
            MatrixPrinting(&matrixChangeBase, R, vectorsNumber);

            //NOW LET'S DO THE ARITHMETIC PART
            //A(X)=(Y)

            //FOR EVERY ROW in A
            for(i=0; i<R; i++){

                //FOR EVERY Column in B
                for(int a=0; a<R; a++){
                    value=0;
                    //for evrey data in B

                    for(int b=0; b<R; b++){
                        // value += matrixB1.matrix[i][b] * matrixChangeBase.matrix[i][b];
                        value += matrixChangeBase.matrix[i][b] * matrixB1.matrix[b][a];
                    }
                    matrixNewBase.matrix[i][a]=value;
                }
            
            }
            // MatrixPrinting(&matrixB1, R, vectorsNumber);

            // MatrixPrinting(&matrixNewBase, R, vectorsNumber);

            puts("AND THE NEW B1->B2 is:");
            printf("B1 ==> B2{");
            for(int c=0; c<R; c++){
                printf("(");
                for(i=0; i<R; i++){
                    if(i==R-1){
                        printf("%f)",matrixNewBase.matrix[i][c]);

                    }else{
                        printf("%f,",matrixNewBase.matrix[i][c]);
                    }


                }
                if(c==R-1){
                    printf("}");

                }else{
                    printf(",");
                }

            }

            printf("\n\n");



            puts("THEN THE OTHER PART FOR B2->B1");
            MatrixStarting(&matrixChangeBase,TAM);


            for(counter=0; counter<R; counter++){
                LinearCombination(matrixB2,matrixB1, &matrixChangeBase, counter, R,vectorsNumber);
            }
            puts("SO THE MATRIX CHANGE BASE IS:");
            // MatrixPrinting(&matrixChangeBase, R, vectorsNumber);
            
            //LET'S SOLVE SOME BUGS WHEN -0.00000000
            value=0;
            for(i=0;i<R;i++){

                for(k=0; k<R;k++){
                    // printf("valor de i=%d, sum=%f, sumA=%f\n",i,sum,sumA);
                    value=matrixChangeBase.matrix[i][k];
                    if(value<=0.0000009 && value>=-0.0000009){
                        matrixChangeBase.matrix[i][k]=abs(matrixChangeBase.matrix[i][k]);
                        // puts("ENTRA");
                    }
                    value=0;
            
                }

            }
            MatrixPrinting(&matrixChangeBase, R, vectorsNumber);

            //NOW LET'S DO THE ARITHMETIC PART
            //A(X)=(Y)

            //FOR EVERY ROW in A
            for(i=0; i<R; i++){

                //FOR EVERY Column in B
                for(int a=0; a<R; a++){
                    value=0;
                    //for evrey data in B

                    for(int b=0; b<R; b++){
                        // value += matrixB1.matrix[i][b] * matrixChangeBase.matrix[i][b];
                        value += matrixChangeBase.matrix[i][b] * matrixB1.matrix[b][a];
                    }
                    matrixNewBase.matrix[i][a]=value;
                }
            
            }
            // MatrixPrinting(&matrixB1, R, vectorsNumber);

            // MatrixPrinting(&matrixNewBase, R, vectorsNumber);

            puts("AND THE NEW B2->B1 is:");
            printf("B2 ==> B1{");
            for(int c=0; c<R; c++){
                printf("(");
                for(i=0; i<R; i++){
                    if(i==R-1){
                        printf("%f)",matrixNewBase.matrix[i][c]);

                    }else{
                        printf("%f,",matrixNewBase.matrix[i][c]);
                    }


                }
                if(c==R-1){
                    printf("}");

                }else{
                    printf(",");
                }

            }

            printf("\n\n");





        }else{
            puts("THE MATRIX B1 IS NOT A BASIS");
        }
    }else{
        puts("THE MATRIX B2 IS NOT A BASIS l");
    }
}








void LinearCombination(Matrix matrixB1, Matrix matrixB2, Matrix* matrixChangeBase, int counter, int R, int vectorsNumber){
    //Counter is for rows
    float data[90];
    float dataInf[90];
    Matrix matrixEqua;
    Matrix matrixOperation;
    int aux,h=0,dataAux,unknown=0,auxUnknown=0,cursorUnknon=0,auxRows=0,u=0;
    Matrix matrixConstant;
    //LEts fill the matrix
    MatrixStarting(&matrixOperation,TAM);

    //LET'S FILL THE VECTORS AND SPACE OF U
    matrixOperation=matrixB2;
    // MatrixPrinting(&matrixOperation, R, vectorsNumber);

    for(i=0; i<R; i++){
        matrixOperation.matrix[i][R]=matrixB1.matrix[i][counter];
    }
    // MatrixPrinting(&matrixOperation, R, vectorsNumber);

    if(true){

        OperacionGauss(&matrixOperation, R, &matrixEqua, vectorsNumber);
        MatrixSolutionLC(&matrixOperation,R,vectorsNumber);
        // MatrixPrinting(matrix, R, vectorsNumber);

        if(flag){
            //GG
        }else{
            for(i=0; i<R; i++){
                matrixChangeBase->matrix[i][counter]=matrixOperation.matrix[i][R];
            }

        }
    }



}
    // MatrixPrinting(matrix, R, vectorsNumber);
    // OperacionGauss(matrix, R);
    // MatrixPrinting(matrix, R, vectorsNumber);











void OperacionGauss(Matrix* matrix, int n, Matrix* matrixEqua, int vectorsNumber){
    Matrix constante;
    int aux=0,a,b=0;
    int rowEqu=0, columnEqu=0;
    int auxCount=0;
    w=0;
    //watching the matrix
    swapInit(matrix,R,vectorsNumber);
    for(j=0;j<n;j++){
        auxCount++;
        for(i=0; i<n; i++){
            if(i!=j)
            {
                if(matrix->matrix[j][j]==0){

 
                    swap(matrix,n,vectorsNumber,j);


                }


                constante.matrix[0][0]=matrix->matrix[i][j]/matrix->matrix[j][j];
                for(b=0; b<=vectorsNumber; b++)
                {
                    matrix->matrix[i][b]=matrix->matrix[i][b]-constante.matrix[0][0]*matrix->matrix[j][b];
                }
                // puts("A-DESPUES DE PRIMEROS 0'S");
                // MatrixPrinting(matrix, n, vectorsNumber);
                k=vectorsNumber-1;
                //For TermGenerator


                if(w==n){
                    w=0;
                }
                if(w==i-1){
                    w++;
                }

                for(a=0;a<=auxCount;a++){
                    matrixEqua->matrix[w][a]=matrixEqua->matrix[w][a]-constante.matrix[0][0]*matrixEqua->matrix[j][a];

                }

                w++;
                // // printf("Valor en gauss  %f de la i %d y la k %d\n",matrix->matrix[i][k],i,k);
                // matrixEqua->matrix[w][]=matrix->matrix[i][k]*matrixEqua->matrix[][w];
                // // printf("Posicion0 %dtiene a  %f\n",w,matrixEqua->matrix[0][w]);
                // w++;
                // puts("B-DESPUES DE PRIMEROS 0'S");
                // MatrixPrinting(matrix, n, vectorsNumber);

            }else{
                w++;
                // puts("C-DESPUES DE PRIMEROS 0'S");
                // MatrixPrinting(matrix, n, vectorsNumber);
            }
        }
    }

}


void MatrixPrinting(Matrix* matrix, int rows, int columns){
    //PRINTING LIKE A FUNCTION
//     int n,m;
//     for(n=0;n<=rows-1;n++){
//         printf("\n");
//         for(m=0; m<columns;m++){
// //            printf("Matriz[%d][%d]=\t%f\n",i,j,matrix->matrix[i][j]);
//             printf("%fx%d\t",matrix->matrix[n][m],j+1);
//             if(m==columns-1){
//                 printf("= %f",matrix->matrix[n][columns]);
//             }
//         }

//     }
//     printf("\n\n\n");
    //ANOTHER WAY TO PRINT LIKE A FUNCTION
//     for(i=0;i<=n-1;i++){
//         printf("\n");
//         for(j=0; j<n;j++){
// //            printf("Matriz[%d][%d]=\t%f\n",i,j,matrix->matrix[i][j]);
//             printf("%fx%d\t",matrix->matrix[i][j],j+1);
//         }
//         printf("= %f\t",matrix->matrix[i][n]);
//     }

    //PRINTING LIKE A MATRIX

    int n,m;
    for(n=0;n<=rows-1;n++){
        printf("\n");
        for(m=0; m<columns;m++){
//            printf("Matriz[%d][%d]=\t%f\n",i,j,matrix->matrix[i][j]);
            printf("%f\t\t",matrix->matrix[n][m]);
        }

    }
    printf("\n\n\n");


}

    
void MatrixStarting(Matrix* matrix, int Tam){

    int f,g;

    for(f=0; f<=Tam-1; f++)
    {
        for(g=0; g<=Tam; g++)
        {
            matrix->matrix[f][g]=0;
        }
    }
}

void MatrixStartingCanonic(Matrix* matrix, int Tam){
    int f,g;
    for(f=0; f<=Tam-1; f++)
    {
        for(g=0; g<=Tam; g++)
        {
            if(g==f){
                matrix->matrix[f][g]=1;
            }else{
                matrix->matrix[f][g]=0;
            }
            
        }
    }
}

void MatrixSolutionLC(Matrix* matrix, int n, int unknown){
    float sum,sumA;
    Matrix matrixConstant;
    int parameters=0,values=0,r=0,l;
    //Por rows
    for(i=0;i<n;i++){
        sum=0.0000000000000000000;
        sumA=0.00000000000000;
        for(k=0; k<n;k++){
            sum=abs(sum)+matrix->matrix[i][k];
            sumA=sumA+matrix->matrix[i][k];

        }
        // printf("\nSUMA #%d  sum = %f y sumA=%f\n",i,sumA,sum);
        if(sum<=0.0000009 && sumA<=0.0000009 && sum>=-0.0000009 && sumA>=-0.0000009){
            //There is no solution to the matrix
            flag=true;
        }
    }

    if(flag){
        puts("THAT'S NOT A LINEAR COMBINATION OF U");
        puts("So, it doesn't belong to U");
        puts("ERROR");
    }else{
        printf("\n\n");
        // puts("THAT'S A LINEAR COMBINATION OF U");

        // puts("So, it belong to U");
        printf("\n");
        for(i=0;i<n;i++){ 
   
            matrixConstant.matrix[0][0]=matrix->matrix[i][i];
            matrix->matrix[i][i]=matrix->matrix[i][i]/matrixConstant.matrix[0][0];
            matrix->matrix[i][n]=matrix->matrix[i][n]/matrixConstant.matrix[0][0];
        }
    }

}



void MatrixSolutionTG(Matrix* matrix, int n, int unknown, Matrix* matrixEqua){
    float sum,sumA;
    int parameters=0,values=0,r=0,l;
    float dataAux[90];
    //Por rows
    // MatrixPrinting(matrix, n, unknown);
    
    for(i=0;i<n;i++){
        sum=0;
        sumA=0;
        for(k=0; k<=unknown;k++){
            sum=abs(sum)+matrix->matrix[i][k];
            sumA=sumA+matrix->matrix[i][k];
            
        }
        // printf("valor de i=%d, sum=%f, sumA=%f\n",i,sum,sumA);
        if(sum<=0.0000009 && sumA<=0.0000009 && sum>=-0.0000009 && sumA>=-0.0000009){
            //There is no solution to the matrix
            flagTGmain=true;
            flagBTG=true;
            // puts("ACA PASO");
        }

    }
    // if(flagTGmain){
    //     puts("VOtata");
    // }else{
    //     puts("Pasara");
    // }


}


void OperacionGaussLinealIndependenci(Matrix* matrix, int n, Matrix* matrixEqua, int vectorsNumber){
    //THIS JUST MAKE A DIAGONAL WITH 0'S UNDER
    Matrix constante;
    int aux=0;
    int rowEqu=0, columnEqu=0;
    int auxCount=0;
    w=0;
// MatrixPrinting(matrix, R, vectorsNumber);
    for(j=0;j<vectorsNumber;j++){

        for(i=0; i<n; i++){
            if(i<j){
                i++;
            }
            if(i!=j){

                if(matrix->matrix[j][j]==0){


                    swap(matrix,n,vectorsNumber,j);


                }
                constante.matrix[0][0]=matrix->matrix[i][j]/matrix->matrix[j][j];
                for(k=0; k<=vectorsNumber; k++)
                {
                    matrix->matrix[i][k]=matrix->matrix[i][k]-constante.matrix[0][0]*matrix->matrix[j][k];
                }
            }

        }
        aux++;
        

    }
    // puts("IMPRIMIENDO DESPUES DEL GAUSS");
    // MatrixPrinting(matrix, R, vectorsNumber);





}

void swap(Matrix* matrix,int R, int vectorsNumber,int aux){
    Matrix matrixRespaldo;
    MatrixStarting(&matrixRespaldo,TAM);
    int cursor=aux,e=0,m=0;
    cursor++;
    while(e<50){
        
        if(matrix->matrix[cursor][aux]!=0 && matrix->matrix[aux][aux]==0){
            // puts("ACAAAA SE ATORA");

            for(m=0; m<=vectorsNumber; m++){
                matrixRespaldo.matrix[0][m]=matrix->matrix[aux][m];
                matrix->matrix[aux][m]=matrix->matrix[cursor][m];
                matrix->matrix[cursor][m]=matrixRespaldo.matrix[0][m];
            }

        }else{
            cursor++;
        }
        e++;
    }

}

//I FINALLY DONT USE THIS

void swapInit(Matrix* matrix,int R, int vectorsNumber){
    Matrix matrixRespaldo;
    MatrixStarting(&matrixRespaldo,TAM);
    int cursor=0,e=0,m=0,w=0;
    cursor++;
    int aux;
    aux=R-1;
    for(w=0;w<R;w++){
        if(matrix->matrix[aux][aux]==0){

            for(e=0;e<R;e++){
                if(matrix->matrix[e][aux]!=0){
                    for(m=0; m<=vectorsNumber; m++){
                    matrixRespaldo.matrix[0][m]=matrix->matrix[aux][m];
                    matrix->matrix[aux][m]=matrix->matrix[e][m];
                    matrix->matrix[e][m]=matrixRespaldo.matrix[0][m];
                    }

                }
            }
   
        }

        aux--;
    }
    
}
bool isBasis(Matrix matrixB, int R, int vectorsNumber){
    //From Vectors program   lol
    float data[90];
    Matrix matrix;
    Matrix matrixEqua;
    Matrix matrixConstant;
    Matrix matrixLinearInd;
    float sum,sumA;
    int parameters=0,auxRows=0, unknown=0, cursorUnknon=0, auxUnknown=0;
    int aux=0,h=0,dataAux,u=0;
    int conLiInd=0,n,thereIs0=0;


//     flag=true;
// flagTGmain=true;
// flagBTG=true;
// flagBLI=true;
// flagLI=true;


    //INIT OF the matrixLinearly
    MatrixStarting(&matrixLinearInd,TAM);
    //INIT OF THE MATRIX MATRIX
    matrix=matrixB;
    // puts("Insert the dimension of R:");
    // fflush(stdin);
    // scanf("%d",&R);
    // printf("\n\n");
    dataAux=R;
    // puts("Insert the number of Vectors:");
    // fflush(stdin);
    // scanf("%d",&vectorsNumber);
    // printf("\n\n");
    k=R;
    //Init of the new Matrix
    for(i=0; i<=TAM-1; i++){
        for(j=0; j<=TAM; j++)
        {
            if(j==i){
                matrixEqua.matrix[i][j]=1;
            }else{
                matrixEqua.matrix[i][j]=0;
            }
        }
    }

    // puts("**LET'S  START **");
    // puts("LETS CHECK IF THE SET IS A TERM GENERATOR");
    //The last Column  
    //Init of that
    for(i=0; i<R; i++){
        matrix.matrix[i][vectorsNumber]=1;
    }
    for(i=0;i<TAM;i++){

    }
    // puts("-Insert the Vectors");    
    //FILLING THE MATRIX
    for(i=0; i<vectorsNumber; i++){
        // printf("\nFor the vector # %d: \n",i+1);
        for(j=0; j<R; j++){
            // printf("Insert the data of the number #%d\n",j+1);
            // fflush(stdin);
            // scanf("%f",&matrix->matrix[j][i]);
            data[k]=matrix.matrix[j][i];
            matrixLinearInd.matrix[j][i]=matrix.matrix[j][i];
            k++;
        }
    }


    if(R>vectorsNumber){
        // puts("THAT'S NOT A SET GENERATOR");
        // puts("(Because the matrix has not solutions)");
        flagBTG=false;
  
    }else if(R==vectorsNumber){
 
        OperacionGauss(&matrix, R, &matrixEqua, vectorsNumber);
        MatrixSolutionTG(&matrix,R,vectorsNumber, &matrixEqua);


        for(i=0;i<R;i++){
            sumA=0;
            sum=0;
            for(k=0; k<vectorsNumber;k++){
                sum=abs(sum)+matrix.matrix[i][k];
                sumA=sumA+matrix.matrix[i][k];
            }
            if(sum<=0.0000009 && sumA<=0.0000009 && sum>=-0.0000009 && sumA>=-0.0000009){
                parameters++;
                // puts("SUma de parameters");
            }   
        }

        if(flagTGmain){
            // puts("THAT'S NOT A SET GENERATOR");
            // puts("Because the matrix hasnot solutions");
            flagBTG=false;
    
        
        }else{
            // printf("\n\n");
            // puts("Aqui pasa calabaza");
            // puts("THAT'S A SET GENERATOR");
            //Flag of the basis
            flagBTG=true;


        }

    }else if(vectorsNumber>R){
        flagBTG=true;
    }
    // MatrixPrinting(matrix, R, vectorsNumber);
    // OperacionGauss(matrix, R);
    // MatrixPrinting(matrix, R, vectorsNumber);


    // puts("LETS CHECK IF THE SET IS  LINEARLY INDEPENDENT");

    // MatrixPrinting(&matrixLinearInd, R, vectorsNumber);
    OperacionGaussLinealIndependenci(&matrixLinearInd, R, &matrixEqua, vectorsNumber);
    OperacionGaussLinealIndependenci(&matrixLinearInd, R, &matrixEqua, vectorsNumber);
    OperacionGaussLinealIndependenci(&matrixLinearInd, R, &matrixEqua, vectorsNumber);
    // MatrixPrinting(&matrixLinearInd, R, vectorsNumber);

    conLiInd=0;
    // printf("**valor del con=%d",conLiInd);
    for(i=0;i<R;i++){
        sum=0;
        sumA=0;
        for(k=0; k<vectorsNumber;k++){
            
            sum=abs(sum)+matrixLinearInd.matrix[i][k];
            sumA=sumA+matrixLinearInd.matrix[i][k];
        }
        if(!(sum<=0.000009 && sumA<=0.000009 && sum>=-0.000009 && sumA>=-0.000009)){
            //sumA!=0
            conLiInd++;
        }
        
    }   
    // puts("IMPRIMIEDNO EN LA MMISMA FUNCION");
    // MatrixPrinting(&matrixLinearInd, R, vectorsNumber);

    if(conLiInd==vectorsNumber){
        // puts("THAT SET IS LINEAR INDEPENDECE");
        // printf("Because #Unknowns=%d=A*=%d\n\n\n",conLiInd,vectorsNumber);
        //THE FLAG
        flagBLI=true;

    }else{
        // puts("THAT SET IS NOT LINEAR INDEPENDECE");
        // //THIS IS RIGHT
        // printf("Because #Unknowns=%d is different from A*=%d\n\n",vectorsNumber,conLiInd);
        flagBLI=false;
    }


    // puts("So the conclusion is: ");
    if(flagBTG){
        if(flagBLI){
            // printf("THE SET IS A BASIS OF R^%d\n\n",R);
            return true;
        }else{
            // printf("THE SET IS NOT A BASIS OF R^%d\n",R);
            // printf("Because is no Lineary independent\n\n");
            return false;
        }
    }else{
        if(flagBLI){
            // printf("THE SET IS NOT A BASIS OF R^%d\n",R);
            // printf("Because is not a set Generator\n\n");
            return false;
        }else{
            // printf("THE SET IS NOT A BASIS OF R^%d\n",R);
            // printf("Because is no Lineary independent and is not a set Generator\n\n");
            return false;
        }

    }


}
void Canonic(Matrix* matrix){

    Matrix matrixChangeBaseB1;
    Matrix matrixChangeBaseB2;
    Matrix matrixB1;
    Matrix matrixB2;
    Matrix matrixNewBaseB1;
    Matrix matrixNewBaseB2;
    Matrix matrixCanonic;
    Matrix matrixin2Canonic;
    int counter;
    float value=0;

    MatrixStarting(&matrixB1,TAM);
    MatrixStarting(&matrixin2Canonic,TAM);
    MatrixStarting(&matrixB2,TAM);
    MatrixStarting(&matrixChangeBaseB1,TAM);
    MatrixStarting(&matrixChangeBaseB2,TAM);

    MatrixStarting(&matrixNewBaseB2,TAM);
    MatrixStarting(&matrixNewBaseB1,TAM);
    MatrixStartingCanonic(&matrixCanonic,TAM);
    puts("\n\n\n=============================================");
    puts("================ CHANGE BASE =============");
    puts("=============================================\n\n\n");
    puts("REMEMBER THAT B1 & B2 SHOULD BE A BASIS OF THE VECTORIAL SPACE V");
    puts("Insert the dimension of R:");
    fflush(stdin);
    scanf("%d",&R);
    printf("\n\n");
    //WEE START MAKING THE INIT OF THE MATRIX AND FULLING WITH THE DATA
    puts("Insert the number of Vectors:");
    fflush(stdin);
    scanf("%d",&vectorsNumber);
    printf("\n\n");
    //LET'S FILL BOTH MATRIX
    puts("INSERT THE CANONIC MATRIX U WANT");

    for(j=0; j<R; j++){
        printf("Insert the data of the number #%d\n",j+1);
        fflush(stdin);
        scanf("%f",&matrixin2Canonic.matrix[j][0]);
    }

    puts("INSERT THE VALUE FOR B1");
    for(i=0; i<vectorsNumber; i++){
        printf("\nFor the vector # %d: \n",i+1);
        for(j=0; j<R; j++){
            printf("Insert the data of the number #%d\n",j+1);
            fflush(stdin);
            scanf("%f",&matrixB1.matrix[j][i]);
        }
    }
    puts("INSERT THE VALUE FOR B2");
    for(i=0; i<vectorsNumber; i++){
        printf("\nFor the vector # %d: \n",i+1);
        for(j=0; j<R; j++){
            printf("Insert the data of the number #%d\n",j+1);
            fflush(stdin);
            scanf("%f",&matrixB2.matrix[j][i]);
        }
    }
    
    // MatrixPrinting(&matrixB1, R, vectorsNumber);
    // MatrixPrinting(&matrixB2, R, vectorsNumber);


    if(isBasis(matrixB1, R, vectorsNumber)){
        if(isBasis(matrixB2, R,vectorsNumber)){
            //THE MAIN PROGRAM :3

            //LET'S FIND THE MATRIX CHANGE BASE
            //REMEMBER USE THE LINEAR COMBINATION
            //This is for the coulumns of the matrix
            for(counter=0; counter<R; counter++){
                LinearCombination(matrixCanonic,matrixB1, &matrixChangeBaseB1, counter, R,vectorsNumber);
            }
            puts("SO THE MATRIX CHANGE BASE FOR B1 IS:");
            // MatrixPrinting(&matrixChangeBase, R, vectorsNumber);
            
            //LET'S SOLVE SOME BUGS WHEN -0.00000000
            value=0;
            for(i=0;i<R;i++){

                for(k=0; k<R;k++){
                    // printf("valor de i=%d, sum=%f, sumA=%f\n",i,sum,sumA);
                    value=matrixChangeBaseB1.matrix[i][k];
                    if(value<=0.0000009 && value>=-0.0000009){
                        matrixChangeBaseB1.matrix[i][k]=abs(matrixChangeBaseB1.matrix[i][k]);
                        // puts("ENTRA");
                    }
                    value=0;
            
                }

            }
            MatrixPrinting(&matrixChangeBaseB1, R, vectorsNumber);


            MatrixStartingCanonic(&matrixCanonic,TAM);
            for(counter=0; counter<R; counter++){
                LinearCombination(matrixCanonic,matrixB2, &matrixChangeBaseB2, counter, R,vectorsNumber);
            }
            puts("SO THE MATRIX CHANGE BASE FOR B2 IS:");
            // MatrixPrinting(&matrixChangeBase, R, vectorsNumber);
            
            //LET'S SOLVE SOME BUGS WHEN -0.00000000
            value=0;
            for(i=0;i<R;i++){

                for(k=0; k<R;k++){
                    // printf("valor de i=%d, sum=%f, sumA=%f\n",i,sum,sumA);
                    value=matrixChangeBaseB2.matrix[i][k];
                    if(value<=0.0000009 && value>=-0.0000009){
                        matrixChangeBaseB2.matrix[i][k]=abs(matrixChangeBaseB2.matrix[i][k]);
                        // puts("ENTRA");
                    }
                    value=0;
            
                }

            }
            MatrixPrinting(&matrixChangeBaseB2, R, vectorsNumber);

            //NOW LET'S DO THE ARITHMETIC PART
            //A(X)=(Y)

            //FOR EVERY ROW in A
            // MatrixPrinting(&matrixin2Canonic, R, vectorsNumber);

            for(i=0; i<R; i++){
                value=0;

                //FOR EVERY Column in B
                for(int a=0; a<R; a++){
                    
                    value += matrixChangeBaseB1.matrix[i][a] * matrixin2Canonic.matrix[a][0];
        
                }
                matrixNewBaseB1.matrix[i][0]=value;
            }
            // MatrixPrinting(&matrixNewBaseB1, R, vectorsNumber);



            // MatrixPrinting(&matrixin2Canonic, R, vectorsNumber);
            for(i=0; i<R; i++){
                value=0;

                //FOR EVERY Column in B
                for(int a=0; a<R; a++){
                    
                    value += matrixChangeBaseB2.matrix[i][a] * matrixin2Canonic.matrix[a][0];
        
                }
                matrixNewBaseB2.matrix[i][0]=value;
            }
            // MatrixPrinting(&matrixNewBaseB2, R, vectorsNumber);


            // MatrixPrinting(&matrixB1, R, vectorsNumber);

            // MatrixPrinting(&matrixNewBase, R, vectorsNumber);

            //SO FOR 
            puts("SO THE CANONIC FORM OF: ");
            printf("(");
            for(i=0;i<R;i++){
                if(i==R-1){
                    printf("%f)=(",matrixin2Canonic.matrix[i][0]);

                }else{
                    printf("%f,",matrixin2Canonic.matrix[i][0]);
                }
                
            }

            for(i=0;i<R;i++){
                if(i==R-1){
                    printf("%f)B1=(",matrixNewBaseB1.matrix[i][0]);

                }else{
                    printf("%f,",matrixNewBaseB1.matrix[i][0]);
                }
                
            }

            for(i=0;i<R;i++){
                if(i==R-1){
                    printf("%f)B2",matrixNewBaseB2.matrix[i][0]);

                }else{
                    printf("%f,",matrixNewBaseB2.matrix[i][0]);
                }
                
            }
            printf("\n\n\n");




        }else{
            puts("THE MATRIX B2 IS NOT A BASIS");
        }
    }else{
        puts("THE MATRIX B1 IS NOT A BASIS");
    }



}


void BothFunction(){
    
    Matrix matrixChangeBaseB1;
    Matrix matrixChangeBaseB2;
    Matrix matrixB1;
    Matrix matrixB2;
    Matrix matrixNewBaseB1;
    Matrix matrixNewBaseB2;
    Matrix matrixCanonic;
    Matrix matrixin2Canonic;
    //FROM THE FIRST PART
    Matrix matrixChangeBase;
    Matrix matrixNewBase;


    int counter;
    float value=0;

    MatrixStarting(&matrixB1,TAM);
    MatrixStarting(&matrixin2Canonic,TAM);
    MatrixStarting(&matrixB2,TAM);
    MatrixStarting(&matrixChangeBaseB1,TAM);
    MatrixStarting(&matrixChangeBaseB2,TAM);

    MatrixStarting(&matrixNewBaseB2,TAM);
    MatrixStarting(&matrixNewBaseB1,TAM);
    MatrixStartingCanonic(&matrixCanonic,TAM);
    //FROM THE FIRST PART
    MatrixStarting(&matrixChangeBase,TAM);
    MatrixStarting(&matrixNewBase,TAM);
    puts("\n\n\n=============================================");
    puts("================ BOTH FUNCTION =============");
    puts("=============================================\n\n\n");
    puts("REMEMBER THAT B1 & B2 SHOULD BE A BASIS OF THE VECTORIAL SPACE V");
    puts("Insert the dimension of R:");
    fflush(stdin);
    scanf("%d",&R);
    printf("\n\n");
    //WEE START MAKING THE INIT OF THE MATRIX AND FULLING WITH THE DATA
    puts("Insert the number of Vectors:");
    fflush(stdin);
    scanf("%d",&vectorsNumber);
    printf("\n\n");
    //LET'S FILL BOTH MATRIX
    puts("INSERT THE CANONIC MATRIX U WANT");

    for(j=0; j<R; j++){
        printf("Insert the data of the number #%d\n",j+1);
        fflush(stdin);
        scanf("%f",&matrixin2Canonic.matrix[j][0]);
    }

    puts("INSERT THE VALUE FOR B1");
    for(i=0; i<vectorsNumber; i++){
        printf("\nFor the vector # %d: \n",i+1);
        for(j=0; j<R; j++){
            printf("Insert the data of the number #%d\n",j+1);
            fflush(stdin);
            scanf("%f",&matrixB1.matrix[j][i]);
        }
    }
    puts("INSERT THE VALUE FOR B2");
    for(i=0; i<vectorsNumber; i++){
        printf("\nFor the vector # %d: \n",i+1);
        for(j=0; j<R; j++){
            printf("Insert the data of the number #%d\n",j+1);
            fflush(stdin);
            scanf("%f",&matrixB2.matrix[j][i]);
        }
    }
    
    // MatrixPrinting(&matrixB1, R, vectorsNumber);
    // MatrixPrinting(&matrixB2, R, vectorsNumber);


    if(isBasis(matrixB1, R, vectorsNumber)){
        if(isBasis(matrixB2, R,vectorsNumber)){
            //THE MAIN PROGRAM :3

            //LET'S FIND THE MATRIX CHANGE BASE
            //REMEMBER USE THE LINEAR COMBINATION
            //This is for the coulumns of the matrix
            for(counter=0; counter<R; counter++){
                LinearCombination(matrixCanonic,matrixB1, &matrixChangeBaseB1, counter, R,vectorsNumber);
            }

            puts("SO THE MATRIX CHANGE BASE FOR B1 IS:");
            // MatrixPrinting(&matrixChangeBase, R, vectorsNumber);
            
            //LET'S SOLVE SOME BUGS WHEN -0.00000000
            value=0;
            for(i=0;i<R;i++){

                for(k=0; k<R;k++){
                    // printf("valor de i=%d, sum=%f, sumA=%f\n",i,sum,sumA);
                    value=matrixChangeBaseB1.matrix[i][k];
                    if(value<=0.0000009 && value>=-0.0000009){
                        matrixChangeBaseB1.matrix[i][k]=abs(matrixChangeBaseB1.matrix[i][k]);
                        // puts("ENTRA");
                    }
                    value=0;
            
                }

            }
            MatrixPrinting(&matrixChangeBaseB1, R, vectorsNumber);


            MatrixStartingCanonic(&matrixCanonic,TAM);
            for(counter=0; counter<R; counter++){
                LinearCombination(matrixCanonic,matrixB2, &matrixChangeBaseB2, counter, R,vectorsNumber);
            }
            puts("SO THE MATRIX CHANGE BASE FOR B2 IS:");
            // MatrixPrinting(&matrixChangeBase, R, vectorsNumber);
            
            //LET'S SOLVE SOME BUGS WHEN -0.00000000
            value=0;
            for(i=0;i<R;i++){

                for(k=0; k<R;k++){
                    // printf("valor de i=%d, sum=%f, sumA=%f\n",i,sum,sumA);
                    value=matrixChangeBaseB2.matrix[i][k];
                    if(value<=0.0000009 && value>=-0.0000009){
                        matrixChangeBaseB2.matrix[i][k]=abs(matrixChangeBaseB2.matrix[i][k]);
                        // puts("ENTRA");
                    }
                    value=0;
            
                }

            }
            MatrixPrinting(&matrixChangeBaseB2, R, vectorsNumber);

            //NOW LET'S DO THE ARITHMETIC PART
            //A(X)=(Y)

            //FOR EVERY ROW in A
            // MatrixPrinting(&matrixin2Canonic, R, vectorsNumber);

            for(i=0; i<R; i++){
                value=0;

                //FOR EVERY Column in B
                for(int a=0; a<R; a++){
                    
                    value += matrixChangeBaseB1.matrix[i][a] * matrixin2Canonic.matrix[a][0];
        
                }
                matrixNewBaseB1.matrix[i][0]=value;
            }
            // MatrixPrinting(&matrixNewBaseB1, R, vectorsNumber);



            // MatrixPrinting(&matrixin2Canonic, R, vectorsNumber);
            for(i=0; i<R; i++){
                value=0;

                //FOR EVERY Column in B
                for(int a=0; a<R; a++){
                    
                    value += matrixChangeBaseB2.matrix[i][a] * matrixin2Canonic.matrix[a][0];
        
                }
                matrixNewBaseB2.matrix[i][0]=value;
            }
            // MatrixPrinting(&matrixNewBaseB2, R, vectorsNumber);


            // MatrixPrinting(&matrixB1, R, vectorsNumber);

            // MatrixPrinting(&matrixNewBase, R, vectorsNumber);

            //SO FOR 
            puts("SO THE CANONIC FORM OF: ");
            printf("(");
            for(i=0;i<R;i++){
                if(i==R-1){
                    printf("%f)=(",matrixin2Canonic.matrix[i][0]);

                }else{
                    printf("%f,",matrixin2Canonic.matrix[i][0]);
                }
                
            }

            for(i=0;i<R;i++){
                if(i==R-1){
                    printf("%f)B1=(",matrixNewBaseB1.matrix[i][0]);

                }else{
                    printf("%f,",matrixNewBaseB1.matrix[i][0]);
                }
                
            }

            for(i=0;i<R;i++){
                if(i==R-1){
                    printf("%f)B2",matrixNewBaseB2.matrix[i][0]);

                }else{
                    printf("%f,",matrixNewBaseB2.matrix[i][0]);
                }
                
            }
            printf("\n\n\n");

            //THEN
            puts("***Let's start with the change of B1<->B2***");




            for(counter=0; counter<R; counter++){
                LinearCombination(matrixB1,matrixB2, &matrixChangeBase, counter, R,vectorsNumber);
            }
            puts("SO THE MATRIX CHANGE BASE IS:");
            // MatrixPrinting(&matrixChangeBase, R, vectorsNumber);
            
            //LET'S SOLVE SOME BUGS WHEN -0.00000000
            value=0;
            for(i=0;i<R;i++){

                for(k=0; k<R;k++){
                    // printf("valor de i=%d, sum=%f, sumA=%f\n",i,sum,sumA);
                    value=matrixChangeBase.matrix[i][k];
                    if(value<=0.0000009 && value>=-0.0000009){
                        matrixChangeBase.matrix[i][k]=abs(matrixChangeBase.matrix[i][k]);
                        // puts("ENTRA");
                    }
                    value=0;
            
                }

            }
            MatrixPrinting(&matrixChangeBase, R, vectorsNumber);

            //NOW LET'S DO THE ARITHMETIC PART
            //A(X)=(Y)

            //FOR EVERY ROW in A
            for(i=0; i<R; i++){

                //FOR EVERY Column in B
                for(int a=0; a<R; a++){
                    value=0;
                    //for evrey data in B

                    for(int b=0; b<R; b++){
                        // value += matrixB1.matrix[i][b] * matrixChangeBase.matrix[i][b];
                        value += matrixChangeBase.matrix[i][b] * matrixB1.matrix[b][a];
                    }
                    matrixNewBase.matrix[i][a]=value;
                }
            
            }
            // MatrixPrinting(&matrixB1, R, vectorsNumber);

            // MatrixPrinting(&matrixNewBase, R, vectorsNumber);

            puts("AND THE NEW B1->B2 is:");
            printf("B1 ==> B2{");
            for(int c=0; c<R; c++){
                printf("(");
                for(i=0; i<R; i++){
                    if(i==R-1){
                        printf("%f)",matrixNewBase.matrix[i][c]);

                    }else{
                        printf("%f,",matrixNewBase.matrix[i][c]);
                    }


                }
                if(c==R-1){
                    printf("}");

                }else{
                    printf(",");
                }

            }

            printf("\n\n");



            puts("THEN THE OTHER PART FOR B2->B1");
            MatrixStarting(&matrixChangeBase,TAM);


            for(counter=0; counter<R; counter++){
                LinearCombination(matrixB2,matrixB1, &matrixChangeBase, counter, R,vectorsNumber);
            }
            puts("SO THE MATRIX CHANGE BASE IS:");
            // MatrixPrinting(&matrixChangeBase, R, vectorsNumber);
            
            //LET'S SOLVE SOME BUGS WHEN -0.00000000
            value=0;
            for(i=0;i<R;i++){

                for(k=0; k<R;k++){
                    // printf("valor de i=%d, sum=%f, sumA=%f\n",i,sum,sumA);
                    value=matrixChangeBase.matrix[i][k];
                    if(value<=0.0000009 && value>=-0.0000009){
                        matrixChangeBase.matrix[i][k]=abs(matrixChangeBase.matrix[i][k]);
                        // puts("ENTRA");
                    }
                    value=0;
            
                }

            }
            MatrixPrinting(&matrixChangeBase, R, vectorsNumber);

            //NOW LET'S DO THE ARITHMETIC PART
            //A(X)=(Y)

            //FOR EVERY ROW in A
            for(i=0; i<R; i++){

                //FOR EVERY Column in B
                for(int a=0; a<R; a++){
                    value=0;
                    //for evrey data in B

                    for(int b=0; b<R; b++){
                        // value += matrixB1.matrix[i][b] * matrixChangeBase.matrix[i][b];
                        value += matrixChangeBase.matrix[i][b] * matrixB1.matrix[b][a];
                    }
                    matrixNewBase.matrix[i][a]=value;
                }
            
            }
            // MatrixPrinting(&matrixB1, R, vectorsNumber);

            // MatrixPrinting(&matrixNewBase, R, vectorsNumber);

            puts("AND THE NEW B2->B1 is:");
            printf("B2 ==> B1{");
            for(int c=0; c<R; c++){
                printf("(");
                for(i=0; i<R; i++){
                    if(i==R-1){
                        printf("%f)",matrixNewBase.matrix[i][c]);

                    }else{
                        printf("%f,",matrixNewBase.matrix[i][c]);
                    }


                }
                if(c==R-1){
                    printf("}");

                }else{
                    printf(",");
                }

            }

            printf("\n\n");








        }else{
            puts("THE MATRIX B2 IS NOT A BASIS");
        }
    }else{
        puts("THE MATRIX B1 IS NOT A BASIS");
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
