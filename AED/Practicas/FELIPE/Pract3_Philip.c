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
                   
P R A C T I C A     3

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<time.h> 
#define TAM 30
#include <stdbool.h>
#define tamA 30

typedef struct{
    int valor;
}Generico;
typedef struct{
    Generico DatoG;
}Dato;

typedef struct{
    char titulo[30];
    char ancho[10];
    char alto[10];
    char fuente[30];
}Carac;

typedef struct{
    Carac carac;
}Libro;


void ordenamientoSeleccionPares(Dato *arreglo, int tam);
void ordenamientoInsercionImpares(Dato *arreglo, int tam);
void ordenAscendente(Libro *arreglo);
void ordenDescendente(Libro *arreglo);

void main()
{
	int i,random,j=0,TamPar=0,TamImpar=0,k=0,OpcionID,Titulo=1,Alto=2,Ancho=3,Fuente=4;

	Dato arreglo[TAM];

	srand(time(0));
	
	for(i=0; i<TAM;i++){
		random=(rand() % (tamA));
		arreglo[i].DatoG.valor=random;
		if((arreglo[i].DatoG.valor)%2==0)
			TamPar++;
		else
			TamImpar++;
	}

	Dato arregloPar[TamPar];
	Dato arregloImpar[TamImpar];

	puts("Arreglo random");
	//Areglo desordenado
	for(i=0; i<TAM;i++){
		printf("%d=\t%d\n",i+1,arreglo[i].DatoG.valor);
	}
	//Areglo de solo pares

	puts("Ordenamiento Pares");
	for(i=0; i<TAM;i++){
		if((arreglo[i].DatoG.valor)%2==0){
			arregloPar[j].DatoG.valor=arreglo[i].DatoG.valor;
			j++;
    	}
	}


	ordenamientoSeleccionPares(arregloPar,TamPar);

	for(i=0; i<TamPar;i++){
		printf("%d=\t%d\n",i+1,arregloPar[i].DatoG.valor);
	}

	j=0;

	puts("Ordenamiento Impares");
	for(i=0; i<=TAM;i++){
		if((arreglo[i].DatoG.valor)%2==1){
			arregloImpar[j].DatoG.valor=arreglo[i].DatoG.valor;
			j++;
    	}
	}

	ordenamientoInsercionImpares(arregloImpar,TamImpar);

	for(i=0; i<TamImpar;i++){
		printf("%d=\t%d\n",i+1,arregloImpar[i].DatoG.valor);
	}

	// PARTE DE LOS TDA
        Libro libro[33];

    char arregloTDA[35][6][30]=
    {
        {
            {"1"},
            {"Anecdota de un dia"},
            {"8.5"},
            {"3.18"},
            {"Tahoma black"},
            {"2.1"}
        },
        {
            {"2"},
            {"Burros Blancos"},
            {"7.5"},
            {"0.74"},
            {"Agency"},
            {"115"}
        },
        {
            {"3"},
            {"Cien anos y uno mas"},
            {"6.5"},
            {"0.3"},
            {"Abcissa"},
            {"147"}
        },
        {
            {"4"},
            {"Diamantes y dados"},
            {"5.5"},
            {"0.14"},
            {"HP Simplifie"},
            {"137"}
        },
        {
            {"5"},
            {"El avestrus"},
            {"4.5"},
            {"0.58"},
            {"Arial"},
            {"106"}
        },
        {
            {"6"},
            {"El cuento"},
            {"3.5"},
            {"0.46"},
            {"Calibri"},
            {"97"}
        },
        {
            {"7"},
            {"Elefantes"},
            {"2.5"},
            {"1.46"},
            {"Impact"},
            {"186"}
        },
        {
            {"8"},
            {"Fiestas"},
            {"1.5"},
            {"1.9"},
            {"Alanis Hand"},
            {"183"}
        },
        {
            {"9"},
            {"Gatoman"},
            {"0.5"},
            {"2.34"},
            {"Jasmine UPC"},
            {"37"}
        },
        {
            {"10"},
            {"Hipopotamos en su habitat"},
            {"0.5"},
            {"2.78"},
            {"Latha"},
            {"300"}
        },
        {
            {"11"},
            {"Italia, un nuevo mundo"},
            {"1.5"},
            {"3.22"},
            {"Kaiti"},
            {"172"}
        },
        {
            {"12"},
            {"Juanacatlan, pueblo magico"},
            {"2.5"},
            {"3.66"},
            {"Nyala"},
            {"36"}
        },
        {
            {"13"},
            {"Kids, where are them?"},
            {"3.5"},
            {"4.1"},
            {"Verdana"},
            {"175"}
        },
        {
            {"14"},
            {"La nina"},
            {"4.5"},
            {"4.54"},
            {"Tahoma"},
            {"146"}
        },
        {
            {"15"},
            {"Metafisica"},
            {"5.5"},
            {"4.98"},
            {"Modern"},
            {"43"}
        },
        {
            {"16"},
            {"Nuevos horizontes"},
            {"6.5"},
            {"5.42"},
            {"Universe"},
            {"68"}
        },
        {
            {"17"},
            {"Osos polares"},
            {"7.5"},
            {"5.86"},
            {"Yu Gothic"},
            {"142"}
        },
        {
            {"18"},
            {"Pato Hood"},
            {"8.5"},
            {"6.3"},
            {"Ravie"},
            {"140"}
        },
        {
            {"19"},
            {"Poblaciones vulnerables"},
            {"9.5"},
            {"6.74"},
            {"OCRB"},
            {"124"}
        },
        {
            {"30"},
            {"Quo duo"},
            {"10.5"},
            {"7.18"},
            {"Selawik"},
            {"140"}
        },
        {
            {"21"},
            {"Robin Hood"},
            {"11.5"},
            {"7.62"},
            {"Perpetua"},
            {"178"}
        },
        {
            {"22"},
            {"Significado de la vida"},
            {"12.5"},
            {"8.06"},
            {"Times"},
            {"26"}
        },
        {
            {"23"},
            {"Soberanos"},
            {"13.5"},
            {"8.5"},
            {"Webdings"},
            {"67"}
        },
        {
            {"24"},
            {"Trasatlantico"},
            {"14.5"},
            {"8.94"},
            {"Sweet Pea"},
            {"163"}
        },
        {
            {"25"},
            {"Transportes del futuro"},
            {"15.5"},
            {"9.38"},
            {"Bell MT"},
            {"174"}
        },
        {
            {"26"},
            {"Trotamundos"},
            {"16.5"},
            {"9.82"},
            {"Embria"},
            {"35"}
        },
        {
            {"27"},
            {"Uvas para el vino"},
            {"17.5"},
            {"10.26"},
            {"Mangal"},
            {"188"}
        },
        {
            {"28"},
            {"Verduras y frutas"},
            {"18.5"},
            {"10.7"},
            {"Cambria"},
            {"16"}
        },
        {
            {"29"},
            {"Viajando ando"},
            {"19.5"},
            {"11.14"},
            {"Dotum"},
            {"78"}
        },
        {
            {"30"},
            {"Walter Cross, ¿Quien fue?"},
            {"30.5"},
            {"11.58"},
            {"Papyrus"},
            {"68"}
        },
        {
            {"31"},
            {"Xcaret, un lugar magico"},
            {"21.5"},
            {"12.02"},
            {"Arial black"},
            {"180"}
        },
        {
            {"32"},
            {"Yardas"},
            {"22.5"},
            {"12.46"},
            {"Georgia"},
            {"181"}
        },
        {
            {"33"},
            {"Zapato Viejo"},
            {"23.5"},
            {"12.9"},
            {"French Script"},
            {"15"}
        }
    };
    for(int i=0;i<33;i++){
        strcpy(libro[i].carac.titulo,arregloTDA[i][1]);
        strcpy(libro[i].carac.alto,arregloTDA[i][2]);
        strcpy(libro[i].carac.ancho,arregloTDA[i][3]);
        strcpy(libro[i].carac.fuente,arregloTDA[i][4]);
    }

    int opcion;
    printf("Digita la opcion del orden que quieras obtener\n");
    printf("1. Ascendente\n");
    printf("2. Descendente\n");
    scanf("%d", &opcion);

    switch(opcion){
        case 1:
            ordenAscendente(libro);
        break;

        case 2:
            ordenDescendente(libro);
        break;

        default:
            ("Opcion no valida, intente de nuevo\n");
        break;
    }











}



void ordenamientoSeleccionPares(Dato *arreglo, int tam){
    int i,j;
    Dato pivote;
    for(i=0; i<tam; i++){
        for (j=i+1; j<tam; j++){
            if(arreglo[i].DatoG.valor>arreglo[j].DatoG.valor){
                pivote = arreglo[i];
                arreglo[i].DatoG.valor = arreglo[j].DatoG.valor;
                arreglo[j] = pivote;
            }
        }
    }
}


void ordenamientoInsercionImpares(Dato *arreglo, int tam){
    int i,j;
    Dato pivote; 
    for(i=1; i<tam; i++){
        pivote=arreglo[i];
        j=i-1;
        while (j>=0 && arreglo[j].DatoG.valor>pivote.DatoG.valor){
            arreglo[j+1]=arreglo[j];
            /*EEHH para el segundo ciclo tambn se le baja
            a J-1 por lo que no seria i eso no mamon*/
            j=j-1;
        }
        /*EEHH wacha que se le bajo a J=-1 en el primer ciclo,
        entonces j+1 seria el lugar 0*/
        arreglo[j+1]=pivote;
    }
}


void ordenAscendente(Libro *arreglo){
    int opcion;
    printf("Ingresa la opcion que quieras ver\n");
    printf("1. Alto\n 2. Ancho\n 3. Titulo\n 4. Fuente\n");
    scanf("%d",&opcion);
    int j;
    char copia[30];
    switch(opcion){
        case 1: 
            for(int i=0;i<33;i++){  
                for(j=i+1;j<33;j++){
                    if((int)arreglo[j].carac.alto<(int)arreglo[i].carac.alto){ 
                        strcpy(copia,arreglo[j].carac.alto);
                        strcpy(arreglo[j].carac.alto,arreglo[i].carac.alto);
                        strcpy(arreglo[i].carac.alto,copia);
                    }
                }
            }
            for(int i=0;i<33;i++){
                    printf("\n%s",arreglo[i].carac.alto);
            }
        break;

        case 2:
            for(int i=0;i<33;i++){  
                for(j=i+1;j<33;j++){
                    if((int)arreglo[j].carac.ancho<(int)arreglo[i].carac.ancho){ 
                        strcpy(copia,arreglo[j].carac.ancho);
                        strcpy(arreglo[j].carac.ancho,arreglo[i].carac.ancho);
                        strcpy(arreglo[i].carac.ancho,copia);
                    }
                }
            }
            for(int i=0;i<33;i++){
                    printf("\n%s",arreglo[i].carac.ancho);
            }

        break;

        case 3:
            for(int i=0;i<33;i++){  
                for(j=i+1;j<33;j++){
                    if((int)arreglo[j].carac.titulo<(int)arreglo[i].carac.titulo){ 
                        strcpy(copia,arreglo[j].carac.titulo);
                        strcpy(arreglo[j].carac.titulo,arreglo[i].carac.titulo);
                        strcpy(arreglo[i].carac.titulo,copia);
                    }
                }
            }
            for(int i=0;i<33;i++){
                printf("\n%s",arreglo[i].carac.titulo);
            }

        break;

        case 4: 
            for(int i=0;i<33;i++){  
                for(j=i+1;j<33;j++){
                    if((int)arreglo[j].carac.fuente<(int)arreglo[i].carac.fuente){ 
                        strcpy(copia,arreglo[j].carac.fuente);
                        strcpy(arreglo[j].carac.fuente,arreglo[i].carac.fuente);
                        strcpy(arreglo[i].carac.fuente,copia);
                    }
                }
            }
            for(int i=0;i<33;i++){
                printf("\n%s",arreglo[i].carac.fuente);
            }
        break;

        default: 
            printf("Opcion incorrecta, intentalo de nuevo\n");
        break;
    }
}

void ordenDescendente(Libro *arreglo){
    int opcion;
    printf("Ingresa la opcion que quieras ver\n");
    printf("1. Alto\n 2. Ancho\n 3. Titulo\n 4. Fuente\n");
    scanf("%d",&opcion);
    int j;
    char copia[30];
    switch(opcion){
        case 1: 
            for(int i=0;i<33;i++){  
                for(j=i+1;j<33;j++){
                    if((int)arreglo[j].carac.alto>(int)arreglo[i].carac.alto){ 
                        strcpy(copia,arreglo[j].carac.alto);
                        strcpy(arreglo[j].carac.alto,arreglo[i].carac.alto);
                        strcpy(arreglo[i].carac.alto,copia);
                    }
                }
            }
            for(int i=0;i<33;i++){
                printf("\n%s",arreglo[i].carac.alto);
            }
        break;

        case 2:
            for(int i=0;i<33;i++){  
                for(j=i+1;j<33;j++){
                    if((int)arreglo[j].carac.ancho>(int)arreglo[i].carac.ancho){ 
                        strcpy(copia,arreglo[j].carac.ancho);
                        strcpy(arreglo[j].carac.ancho,arreglo[i].carac.ancho);
                        strcpy(arreglo[i].carac.ancho,copia);
                    }
                }
            }
            for(int i=0;i<33;i++){
                printf("\n%s",arreglo[i].carac.ancho);
            }
        break;

        case 3:
            for(int i=0;i<33;i++){  
                for(j=i+1;j<33;j++){
                    if((int)arreglo[j].carac.titulo>(int)arreglo[i].carac.titulo){ 
                        strcpy(copia,arreglo[j].carac.titulo);
                        strcpy(arreglo[j].carac.titulo,arreglo[i].carac.titulo);
                        strcpy(arreglo[i].carac.titulo,copia);
                    }
                }
            }
            for(int i=0;i<33;i++){
                printf("\n%s",arreglo[i].carac.titulo);
            }

        break;

        case 4: 
            for(int i=0;i<33;i++){  
                for(j=i+1;j<33;j++){
                    if((int)arreglo[j].carac.fuente>(int)arreglo[i].carac.fuente){ 
                        strcpy(copia,arreglo[j].carac.fuente);
                        strcpy(arreglo[j].carac.fuente,arreglo[i].carac.fuente);
                        strcpy(arreglo[i].carac.fuente,copia);
                    }
                }
            }
            for(int i=0;i<33;i++){
                printf("\n%s",arreglo[i].carac.fuente);
            }
        break;

        default: 
            printf("Opcion incorrecta, intentalo de nuevo\n");
        break;        
    }
}
