#include "Lista_ParqueFelipe.h"
#include "Pila_ParqueFelipe.h"
#include <time.h>
#include <unistd.h>


void ventanilla(Lista *lista, int *error, int numerojuego);

void main(int argc, char const *argv[])
{
	/* code */
	//PERSONAS QUE ASISTEN
	int numeroPersonas = atoi(argv[argc - 1]);
	int error=0;
	int i;
    int alturaExtr, edadExtr;
    char* nombreExtr;
	//COLA DE AFUERA
    Pila *pilaAfuera=crearPila(&error);
	//CREAMOS LISTAS PARA CADA juego
	Lista juego1 = crearLista(&error);
    Lista juego2 = crearLista(&error);
    Lista juego3 = crearLista(&error);
    Lista juego4 = crearLista(&error);
    Lista juego5 = crearLista(&error);

    //PARA AGREGAR EL NOMBRE y ALTURA
    struct Node infoPersona;
 	//PARA EXTRAER LA INFO DE LA COLA Y PASAR A FILAS
 	Dato infoAgregada;
 	struct Node infoExtraida;

    //LLENADO Y ENCOLADO DE PERSONAS
    time_t t;
    srand((unsigned)time(&t));
    for (i = 0; i < numeroPersonas; i++){
    	printf("**PARA LA PEROSONA %d:\n",i+1);
        printf("Ingrese el nombre de la persona:\n");
        fflush(stdin);
        scanf("%s", &infoPersona.nombre);

        printf("Ingrese la edad de la persona:\n");
        fflush(stdin);
        scanf("%d", &infoPersona.edad);


        infoPersona.edad = (rand() % 200) + 100;

        printf("Altura generada de la persona en cm: %d\n", infoPersona.altura);

        apilar(pilaAfuera,&error,infoPersona);
        printf("\n\n\n");
    }

    //TRASPASO DE PERSONAS  LAS FILAS CORRESPONDIENTES
    puts("@@ Ingreso de personas a sus Juegos @@");
    printf("\n\n\n");

    while (!isEmpty(*pilaAfuera, &error))
    {
        desapilar(pilaAfuera, &error,&infoExtraida,&alturaExtr,&edadExtr);


        // printf("Altura Extraida Luego luego: %d\n",alturaExtr);
        infoAgregada.nombre = nombreExtr;
        // printf("Nombre: que llega%s\n",*nombreExtr);

        infoAgregada.edad = edadExtr;
       	infoAgregada.altura =alturaExtr;
       	// printf("Altura Extraida para agregar: %d\n",infoAgregada.altura);

        if (infoAgregada.altura > 100 && infoAgregada.altura < 120){
        	agregarPorDerecha(&juego1,&error, infoAgregada);
        	// puts("ENTRA 1");
        	
        }

       
        else if (infoAgregada.altura == 100){
        	agregarPorDerecha(&juego2,&error, infoAgregada);
        	// puts("ENTRA 2");
        	       	
        }

        else if (infoAgregada.altura > 120 && infoAgregada.altura < 170){
        	agregarPorDerecha(&juego3,&error, infoAgregada);
        	// puts("ENTRA 3");
        	       	
        }


        else if (infoAgregada.altura == 120 || infoAgregada.altura == 170){
        	agregarPorDerecha(&juego4,&error, infoAgregada);
        	// puts("ENTRA 4");
        	       	
        }


        else if (infoAgregada.altura > 170 && infoAgregada.altura <= 200){
        	agregarPorDerecha(&juego5,&error, infoAgregada);
        	// puts("ENTRA 5");
        	       	
        }

 
    }

    puts("EMPECEMOS A ATENDER A LAS PERSONAS");
    printf("\n\n");


	ventanilla(&juego1, &error, 1);
	ventanilla(&juego2, &error, 2);
	ventanilla(&juego3, &error, 3);
	ventanilla(&juego4, &error, 4);
	ventanilla(&juego5, &error, 5);
	//FIN DEL PROGRAMA

    // destruirPila(pilaAfuera, &error);

    borrarLista(&juego1 ,&error);
    borrarLista(&juego2 ,&error);
    borrarLista(&juego3 ,&error);
    borrarLista(&juego4 ,&error);
    borrarLista(&juego5 ,&error);
}


void ventanilla(Lista *lista, int *error, int numerojuego){
	Dato datoExt;
    int turno = 1;
    int contador = 0; // Cada que llegue a 2 la ventanilla se llena y el programa se detendrá para simular que se está atendiendo
    struct Nodo *auxNodo = (*lista)->cabecera;
    char *siguienteuiente;
    printf("PARA EL juego %d\n\n",numerojuego);


    while(auxNodo!=NULL){
        contador++;
        if (contador == 2)
        {
            printf("Por el momento el juego esta lleno\n");
        }

        if (auxNodo->siguiente == NULL)
        {
            extraerPorIzquierda(lista, error,&datoExt);
            printf("Turno: %d -- Numero de juego: %d\n", turno, numerojuego);
            sleep(1);
            // printf("Nombre: %s\n", datoExt.nombre);
            // sleep(1);
            printf("Edad: %d\n", datoExt.edad);
            sleep(1);
            printf("Altura: %d\n", datoExt.altura);
            sleep(1);
            printf("Es la ultima persona en pasar\n");
            sleep(3);
            auxNodo = auxNodo->siguiente;
            
        }else{
        	siguienteuiente = auxNodo->siguiente->dato.nombre;
	        extraerPorIzquierda(lista, error,&datoExt);
	        printf("Turno: %d -- Numero de juego: %d\n", turno, numerojuego);
	        sleep(1);
	        printf("Nombre: %s\n", datoExt.nombre);
	        sleep(1);
	        printf("Edad: %d\n", datoExt.edad);
	        sleep(1);
	        printf("Altura: %1.2f\n", datoExt.altura);
	        sleep(1);
	        printf("siguienteuiente en pasar es: %s\n", siguienteuiente);

	        auxNodo = auxNodo->siguiente;
	        sleep(2);
	        if (contador == 2)
	        {
	            printf("El juego se encuentra libre\n");
	            contador = 0;
	        }


	        }
    }
    printf("===YA NO HAY PERSONAS PARA SER ATENDIDAS POR EL juego====\n\n\n");

}