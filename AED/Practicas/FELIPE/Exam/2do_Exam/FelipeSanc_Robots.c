#include "Lista_Robots.h"
#include "ColaDinamica_Robots.h"
#include <time.h>
#include <unistd.h>


void ventanilla(Lista *lista, int *error, int numeroRobot);

void main(int argc, char const *argv[])
{
	/* code */
	//PERSONAS QUE ASISTEN
	int numeroPersonas = atoi(argv[argc - 1]);
	int error=0;
	int i;
	//COLA DE AFUERA
	Cola colaAfuera = crearCola(&numeroPersonas);
	//CREAMOS LISTAS PARA CADA ROBOT
	Lista robot1 = crearLista(&error);
    Lista robot2 = crearLista(&error);
    Lista robot3 = crearLista(&error);
    Lista robot4 = crearLista(&error);
    Lista robot5 = crearLista(&error);

    //PARA AGREGAR EL NOMBRE y ALTURA
    Data infoPersona;
 	//PARA EXTRAER LA INFO DE LA COLA Y PASAR A FILAS
 	Dato infoAgregada;
 	Data infoExtraida;

    //LLENADO Y ENCOLADO DE PERSONAS
    time_t t;
    srand((unsigned)time(&t));
    for (i = 0; i < numeroPersonas; i++){
    	printf("**PARA LA PEROSONA %d:\n",i+1);
        printf("Ingrese el nombre de la persona:\n");
        fflush(stdin);
        scanf("%s", &infoPersona.nombre);
        printf("Ingrese la altura de %s\n", infoPersona.nombre);
        fflush(stdin);
        scanf("%f", &infoPersona.altura);
        infoPersona.edad = (rand() % 60) + 18;
        printf("Edad generada de la persona: %d\n", infoPersona.edad);
        encolar(&colaAfuera, &error, infoPersona);
        printf("\n\n\n");
    }

    //TRASPASO DE PERSONAS  LAS FILAS CORRESPONDIENTES
    puts("Ingreso de personas a sus ventanillas");

    while (!estaVacia(colaAfuera, &error))
    {
        desencolar(&colaAfuera, &error, &infoExtraida);

        infoAgregada.nombre = infoExtraida.nombre;
        infoAgregada.edad = infoExtraida.edad;
       	infoAgregada.altura = infoExtraida.altura;
       	printf("%d Aqui esta la edad",infoAgregada.edad);
        if (infoAgregada.edad > 18 && infoAgregada.edad < 22){
        	agregarPorDerecha(&robot1,&error, infoAgregada);
        	puts("ENTRA 1");
        	
        }

       
        else if (infoAgregada.edad == 18){
        	agregarPorDerecha(&robot2,&error, infoAgregada);
        	puts("ENTRA 2");
        	       	
        }

        else if (infoAgregada.edad > 22 && infoAgregada.edad < 44){
        	agregarPorDerecha(&robot3,&error, infoAgregada);
        	puts("ENTRA 3");
        	       	
        }


        else if (infoAgregada.edad == 22 || infoAgregada.edad == 44){
        	agregarPorDerecha(&robot4,&error, infoAgregada);
        	puts("ENTRA 4");
        	       	
        }


        else if (infoAgregada.edad > 44 && infoAgregada.edad < 60){
        	agregarPorDerecha(&robot5,&error, infoAgregada);
        	puts("ENTRA 5");
        	       	
        }

 
    }

    puts("EMPECEMOS A ATENDER A LAS PERSONAS");
    printf("\n\n");


	ventanilla(&robot1, &error, 1);
	ventanilla(&robot2, &error, 2);
	ventanilla(&robot3, &error, 3);
	ventanilla(&robot4, &error, 4);
	ventanilla(&robot5, &error, 5);
	//FIN DEL PROGRAMA

    borraCola(&colaAfuera, &error);
    borrarLista(&robot1 ,&error);
    borrarLista(&robot2 ,&error);
    borrarLista(&robot3 ,&error);
    borrarLista(&robot4 ,&error);
    borrarLista(&robot5 ,&error);
}


void ventanilla(Lista *lista, int *error, int numeroRobot){
	Dato datoExt;
    int turno = 1;
    int contador = 0; // Cada que llegue a 2 la ventanilla se llena y el programa se detendrá para simular que se está atendiendo
    struct Nodo *auxNodo = (*lista)->cabecera;
    char *siguienteuiente;
    printf("PARA EL ROBOT %d\n\n",numeroRobot);


    while(auxNodo!=NULL){
        contador++;
        if (contador == 2)
        {
            printf("Por el momento la ventanilla se encuentra llena\n");
        }

        if (auxNodo->siguiente == NULL)
        {
            extraerPorIzquierda(lista, error,&datoExt);
            printf("Turno: %d -- Numero de Robot: %d\n", turno, numeroRobot);
            sleep(1);
            printf("Nombre: %s\n", datoExt.nombre);
            sleep(1);
            printf("Edad: %d\n", datoExt.edad);
            sleep(1);
            printf("Altura: %1.2f\n", datoExt.altura);
            sleep(1);
            printf("Es la ultima persona en ser atendida\n");
            sleep(3);
            auxNodo = auxNodo->siguiente;
            
        }else{
        	siguienteuiente = auxNodo->siguiente->dato.nombre;
	        extraerPorIzquierda(lista, error,&datoExt);
	        printf("Turno: %d -- Numero de Robot: %d\n", turno, numeroRobot);
	        sleep(1);
	        printf("Nombre: %s\n", datoExt.nombre);
	        sleep(1);
	        printf("Edad: %d\n", datoExt.edad);
	        sleep(1);
	        printf("Altura: %1.2f\n", datoExt.altura);
	        sleep(1);
	        printf("siguienteuiente en ser atendido: %s\n", siguienteuiente);

	        auxNodo = auxNodo->siguiente;
	        sleep(2);
	        if (contador == 2)
	        {
	            printf("La ventanilla se encuentra de nuevo libre\n");
	            contador = 0;
	        }


	        }
    }
    printf("===YA NO HAY PERSONAS PARA SER ATENDIDAS POR EL ROBOT====\n\n\n");

}