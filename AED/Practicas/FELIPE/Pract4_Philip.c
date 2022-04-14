/*      =======================================================================
        ===================INSTITUTO POLITECNICO NACIONAL======================
        =======================================================================
                            =============================
                            =ESCUELA SUPERIOR DE COMPUTO=
                            =============================
>>Name: Sánchez Martánez Felipe
>>Gruop: 2BM1
>>Carrer: Ing en Inteligencia Artificial
>>date of last modification: 03/16/22
                   
P R A C T I C A     4

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h> 
#include <stdbool.h>
#define TamBD 122


typedef struct{
    char paisorigen[25];
    char nombre[15];
    float altura;
    int telefono;
}Carac;

typedef struct{
    Carac carac;
}Persona;

void impresion(Persona *persona, int tam);
void Desorden(Persona *persona, int tam);
void OrdenamientoSeleccion(Persona *persona, int tam);
void OrdenamientoInsercion(Persona *persona, int tam);

void OrdenamientoBurbuja(Persona *persona, int tam);
void OrdenamientoMezcla(Persona *persona, int tam);
void merge(Persona *arregloIzq, Persona *arregloDer, int tamIzq, int tamDer, Persona *arregloFinal, int tamArrFinal);



void main(){
    int opcion,i,j,k=0;
    bool flag=true;
    Persona persona[122];
    //Llenado de tabla
    char matriz[122][4][30]={
        {"España","ESTEFANIA","1.62","558205580"},
        {"Venezuela","QUERALT","1.55","556545115"},
        {"Perú","JOAN","1.6","558202768"},
        {"Ecuador","JOAN","1.8","558727844"},
        {"Guatemala","MARC","1.81","558350521"},
        {"Cuba","JOSEP","1.57","558755645"},
        {"República Dominicana","ESTHER","1.57","556520547"},
        {"Honduras","LAURA","1.72","556565656"},
        {"Bolivia","RAQUEL","1.81","556752156"},
        {"El Salvador","JOAN","1.62","558300025"},
        {"Nicaragua","MARIA ISABEL","1.56","558385567"},
        {"Paraguay","ADRIÀ","1.6","557809812"},
        {"Costa Rica","GERARD","1.87","556520741"},
        {"Panamá","ELIOT","1.82","558202456"},
        {"Guinea Ecuatorial","JORDI","1.6","558754554"},
        {"Barbados","LUÍS","1.67","556875544"},
        {"Belice","LAURA","1.87","555880712"},
        {"Botsuana","JORDI","1.75","556875255"},
        {"Camerún","DOUNYA","1.73","556542775"},
        {"Canadá","JULIO","1.86","558773545"},
        {"Dominica","ANDREU","1.79","558200022"},
        {"Eritrea","RAMON","1.81","556512545"},
        {"Filipinas","DAVID-JESE","1.57","557785655"},
        {"Gambia","ARAN","1.64","558300385"},
        {"Ghana","GEMMA","1.69","556520471"},
        {"Granada","IVAN","1.56","556012445"},
        {"Guyana","DAVID","1.57","554500611"},
        {"India","XAVIER","1.73","557885544"},
        {"Irlanda","MARIO","1.75","556512105"},
        {"Jamaica","JESUS","1.82","558202200"},
        {"Francia","GEMMA","1.81","559965585"},
        {"Canadá","SILVIA","1.62","556541235"},
        {"Madagascar","ALBERT","1.71","558204054"},
        {"Camerún","MARIA","1.73","556584541"},
        {"Ruanda","BERTA","1.71","554111475"},
        {"Bélgica","BERTA","1.9","555687444"},
        {"Guinea","MIREIA","1.87","556658711"},
        {"Haití","GEMMA","1.89","558773941"},
        {"Botsuana","MARIA ISABEL","1.83","558305295"},
        {"Camerún","TONI","1.59","556524446"},
        {"Canadá","ALEJANDRO","1.78","558305551"},
        {"Dominica","JOAN MARTÍ","1.72","558206097"},
        {"Eritrea","INGRID","1.89","554500644"},
        {"Filipinas","OLIVER","1.66","558305594"},
        {"Gambia","SANDRA","1.6","558300422"},
        {"Guyana","JORDI","1.74","558350511"},
        {"India","MARC","1.7","558727589"},
        {"Irlanda","JORDINA","1.59","558208488"},
        {"Jamaica","MARIA JOSÉ","1.87","558320587"},
        {"Francia","RAQUEL","1.78","558203095"},
        {"Canadá","ENRIC","1.86","554555455"},
        {"Madagascar","MARTA","1.65","558208502"},
        {"Camerún","CARLA","1.73","558205245"},
        {"Ruanda","MARIA NOELIA","1.56","558300374"},
        {"Bélgica","CRISTINA","1.67","558305576"},
        {"Canadá","CARLOS","1.82","558208614"},
        {"Dominica","DAVID","1.7","558770077"},
        {"Eritrea","CRISTIAN","1.7","558200713"},
        {"Filipinas","JULIO ALBERTO","1.65","558270685"},
        {"Gambia","SERGI","1.79","556021048"},
        {"Guyana","ALEIX","1.7","558773553"},
        {"India","VERÒNICA","1.84","558206766"},
        {"Irlanda","MARIONA","1.81","558305223"},
        {"Jamaica","MARC","1.81","558325565"},
        {"Guatemala","GEMMA","1.56","556565448"},
        {"Cuba","RICARD","1.74","558208360"},
        {"República Dominicana","JUAN","1.6","556549889"},
        {"Honduras","MARTA","1.73","558208677"},
        {"Bolivia","NATÀLIA","1.86","558325558"},
        {"El Salvador","MARTA","1.88","558360281"},
        {"Nicaragua","LAURA","1.89","558208380"},
        {"Paraguay","JOAN","1.83","558770878"},
        {"Costa Rica","ALEXIA","1.67","556874511"},
        {"Panamá","FERRAN","1.81","556548745"},
        {"Guinea Ecuatorial","CRISTINA","1.74","558755512"},
        {"Guyana","JOSÉ ANTONIO","1.59","558722096"},
        {"India","JORDI","1.85","554512544"},
        {"Irlanda","BEGONYA","1.8","558205011"},
        {"Jamaica","INGRID","1.82","558300864"},
        {"Guatemala","MIQUEL","1.64","553256844"},
        {"Cuba","AGUSTÍ","1.59","556528779"},
        {"República Dominicana","ANTONI","1.84","551021886"},
        {"Honduras","JOAN","1.71","556201457"},
        {"Bolivia","MÒNICA","1.86","558207515"},
        {"Jamaica","GERARD","1.84","558208558"},
        {"Francia","GEMMA","1.76","558300496"},
        {"Canadá","MARIA","1.77","550120545"},
        {"Madagascar","ORIOL","1.7","558207095"},
        {"Camerún","VIRGINIA","1.82","558300214"},
        {"Ruanda","DAMIÀ","1.64","558727244"},
        {"Bélgica","VALENTÍ","1.65","556565874"},
        {"Guinea","AINA","1.75","558205782"},
        {"Haití","DAVID","1.73","558305551"},
        {"Botsuana","GERARD","1.72","556577225"},
        {"Camerún","MARTA","1.72","558773647"},
        {"Canadá","MIREIA","1.57","558208054"},
        {"Dominica","ELOI","1.61","558208054"},
        {"Jamaica","ANNA","1.84","550712563"},
        {"Guatemala","ALBA","1.57","558204078"},
        {"Cuba","SANDRA","1.61","556871045"},
        {"República Dominicana","ERIC","1.68","558745211"},
        {"Honduras","LLUÍS","1.75","558300065"},
        {"Bolivia","CRISTIAN","1.63","558208674"},
        {"Jamaica","GUILLEM","1.87","550214054"},
        {"Francia","DIMAS","1.61","556521404"},
        {"Canadá","ANA INÉS","1.82","558350555"},
        {"Madagascar","IVET","1.55","559962045"},
        {"Camerún","JÚLIA","1.59","558755603"},
        {"Madagascar","DANIEL","1.6","558305524"},
        {"Camerún","ABEL","1.89","556571974"},
        {"Ruanda","IRENE","1.66","558300036"},
        {"Bélgica","ADRIÀ","1.84","556505455"},
        {"Guinea","JAIRO","1.78","556587454"},
        {"Haití","CRISTINA","1.86","558725845"},
        {"Botsuana","DAVID","1.83","558205730"},
        {"Camerún","ADRIÀ","1.71","556828258"},
        {"Canadá","LUCIA","1.58","558300045"},
        {"Dominica","CARLA","1.55","556521452"},
        {"Guinea","ADRIÀ","1.58","558725885"},
        {"Haití","MARTA","1.77","558208303"},
        {"Botsuana","MARC","1.58","558360213"},
        {"Camerún","ALEX","1.65","558320537"},
    };

    for(int i=0;i<122;i++){
        strcpy(persona[i].carac.paisorigen,matriz[i][0]);
        strcpy(persona[i].carac.nombre,matriz[i][1]);
        persona[i].carac.altura=atof(matriz[i][2]);
        persona[i].carac.telefono=strtol(matriz[i][3],NULL,10);

    }

    
    puts("Bienvenido");
    do{
        puts("¿Que deseas realizar?");
        puts("1.- Mostrar lista de personas en desorden");
        puts("2.- Ordenar lista de personas por Altura");
        puts("3.- Ordenar lista de personas por la segunda letra del nombre");
        puts("4.- Ordenar lista de personas por número de teléfono");
        puts("5.- Ordenar lista de personas por país de origen");
        puts("6.- Salir del programa");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                Desorden(persona,TamBD);
                impresion(persona,TamBD);
                break;

            case 2:
                OrdenamientoSeleccion(persona,TamBD);
                impresion(persona,TamBD);
                break;

            case 3:
                OrdenamientoMezcla(persona,TamBD);
                impresion(persona,TamBD);
                break;

            case 4:
                OrdenamientoBurbuja(persona,TamBD);
                impresion(persona,TamBD);
                break;

            case 5:
                OrdenamientoInsercion(persona,TamBD);

                impresion(persona,TamBD);
                break;

            case 6:
                puts("Fin del programa");
                exit(0);
                break;

            default:
                puts("Ingresa una opcion valida");
                break;
        }

    }while(flag);
}


void impresion(Persona *persona, int tam){
    printf("\t\t****LISTA DE PERSONAS*****\n\n");
    printf("Pais\t\tNombre\t\t\t\tAltura\t\tTelefono\n");
    for(int i=0;i<tam;i++){
        printf("%s\t\t",persona[i].carac.paisorigen);
        printf("%s\t\t",persona[i].carac.nombre);
        printf("%f\t\t",persona[i].carac.altura);
        printf("%d\n",persona[i].carac.telefono);
    }
}


void Desorden(Persona *persona, int tam){
    int random,i ;
    srand(time(0));
    random=(rand() % (tam-1));
    Persona temporal[tam];
    Persona pivote;
    for (i = 0; i < tam; i++) {
        random=(rand() % (tam-1));
        pivote = persona[i];
        persona[i]= persona[random];
        persona[random]=pivote;
    }
}

void OrdenamientoSeleccion(Persona *persona, int tam){
    int i,j;
    Persona pivote;
    for(i=0; i<tam; i++){
        for (j=i+1; j<tam; j++){
            if(persona[i].carac.altura>persona[j].carac.altura){
                pivote = persona[i];
                persona[i] = persona[j];
                persona[j] = pivote;
            }
        }
    }
}

//pais
void OrdenamientoInsercion(Persona *persona, int tam){
    int i,j;
    Persona pivote; 
    for(i=1; i<tam; i++){
        pivote=persona[i];
        j=i-1;
        while (j>=0 && persona[j].carac.paisorigen[0]>pivote.carac.paisorigen[0]){
            persona[j+1]=persona[j];
            j=j-1;
        }
        persona[j+1]=pivote;
    }
}



void OrdenamientoBurbuja(Persona *persona, int tam){
    int i,j;
    Persona pivote;
    for(i=0; i<tam; i++){
        for(j=0; j<tam-1 ; j++){
            if(persona[j].carac.telefono>persona[j+1].carac.telefono){
                pivote = persona[j];
                persona[j] = persona[j+1];
                persona[j+1] = pivote;
            }
        }
    }

}



void OrdenamientoMezcla(Persona *persona, int tam){
    if(tam>1){
        int posMedia=tam/2;
        int i=0,j=0;
        Persona arregloIzq[posMedia]; 
        Persona arregloDer[tam-posMedia]; 
        for(i=0; i<posMedia; i++)
            arregloIzq[i]=persona[i];
        for(i=posMedia; i<tam; i++){
            arregloDer[j]=persona[i];
            j++;
        }
        OrdenamientoMezcla(arregloIzq,posMedia);
        OrdenamientoMezcla(arregloDer,tam-posMedia);
        merge(arregloIzq,arregloDer,posMedia,tam-posMedia,persona,tam);
    }

}

void merge(Persona *arregloIzq, Persona *arregloDer, int tamIzq, int tamDer, Persona *arregloFinal, int tamArrFinal){
    int i=0,j=0,k=0;
    while(i<tamIzq && j<tamDer){
        if(arregloIzq[i].carac.nombre[1]<arregloDer[j].carac.nombre[1]){
            arregloFinal[k]=arregloIzq[i];
            i++;
        }
        else{
            arregloFinal[k]=arregloDer[j];
            j++;
        }
        k++;
    }
    while(i<tamIzq){
        arregloFinal[k]=arregloIzq[i];
        i++;
        k++;
    }
    while(j<tamDer){
        arregloFinal[k]=arregloDer[j];
        j++;
        k++;
    }
}