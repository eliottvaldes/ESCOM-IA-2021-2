#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdint.h>
#include <time.h>
#include<stdbool.h>

/*
    |Variable   | Estado    | Significado
        error       0           Sin errores (todo resultado es exitoso)
        error      -1           Error, Lista vacía
        error      -2           Inexistencia de la Lista, o esta apunta a NULL
        error      -3           Inexistencia de la posicion 
        error      -4           Nodo nulo
*/

typedef struct{
    int frecuencia;
    char caracter;
}Dato;

typedef struct nodoA{
    Dato info;
    struct nodoA *izq,*der;
} Elemento_De_Arbol_Binario;

typedef Elemento_De_Arbol_Binario* Arbol;

struct Nodo{
    int pos;
    Arbol arbol;
    struct Nodo* sig;
    struct Nodo* ant;
};

typedef struct{
    struct Nodo* cabecera;
    int cursor;
}ElementoLista;

typedef ElementoLista *Lista;

Arbol crearNodo(Dato valor); //Genera al nodo raiz de un árbol
void nuevoArbol(Arbol* raiz,Arbol Hizq, Arbol Hder, Dato valor);
int profundidadArbol(Arbol raiz);
void contarHojas(Arbol raiz, int* contadorHojas);
void preOrden(Arbol raiz);
void posOrden(Arbol raiz);
void inOrden(Arbol raiz);
void eliminarArbol(Arbol* raiz);
void buscarNodo(Arbol raiz, Dato valor, Arbol* nodoEncontrado);
void eliminarNodo(Arbol* raiz, Dato valor);
void ingresarNodo(Arbol* raiz, Dato valor);
void reemplazar(Arbol* nodo);
Arbol nodoMinimo(Arbol node);
Arbol deleteNodeBST(Arbol raiz, Dato valor);
void iniciaOperacion(int argc, char** argv);
void asignaCodigo(Arbol r, int c[], int n);
void ordenar(Arbol* arreglo, int tam);

Arbol crearNodo(Dato valor){
    Arbol arbol=(Arbol) malloc(sizeof(Elemento_De_Arbol_Binario));
    if(arbol==NULL){
        perror("No hay memoria para tu nodo");
    } else{
        arbol->izq=arbol->der=NULL;
        arbol->info=valor;
    }
    return arbol;
}

//Funcion devuelve la raiz del arbol creado
/**
 * @param raiz Nueva raiz con Hijo izquierdo e hijo derecho, con valorRaiz como clave
 * @param Hizq  Nodo que se coloca a la izquierda del nuevo nodo raiz, previamente creado o NULL
 * @param Hder Nodo ue se coloca a la derecha del nuevo nodo raiz, previamente creado o NULL
 */
void nuevoArbol(Arbol* raiz, Arbol Hizq, Arbol Hder, Dato valorRaiz){ 
    (*raiz)=crearNodo(valorRaiz);
    (*raiz)->der=Hder;
    (*raiz)->izq=Hizq;
}

Lista crearLista(int *e){
    Lista lista = (ElementoLista*)malloc(sizeof(Lista));
    if (lista == NULL){
        *e = -2;
        perror("No hay memeoria para la lista");
    } else{
        lista->cabecera = NULL;
        lista->cursor = 0;
        *e = 0;
    }
    return lista;
}

void agregarDer(Lista *l, int *e, Dato datousuario){
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
    if ((*l)->cabecera ==  NULL){
        nodoUsuario->arbol = crearNodo(datousuario);
        nodoUsuario->sig = NULL;
        nodoUsuario->ant = NULL;
        nodoUsuario->pos = 0;
        (*l)->cabecera = nodoUsuario;
    }else{
        struct Nodo* nodoAux = (*l)->cabecera;
        while (nodoAux->sig != NULL){
            nodoAux = nodoAux->sig;
        }
        nodoUsuario->arbol = crearNodo(datousuario);
        nodoUsuario->ant = nodoAux;
        nodoAux->sig = nodoUsuario;
        nodoUsuario->sig = NULL;
        nodoUsuario->pos = nodoAux->pos + 1; 
    }
    (*l)->cursor++;
    *e = 0;
}

// agregarDerconArbol(Lista *l, int *e, Arbol datousuario){
//         struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
//     if ((*l)->cabecera ==  NULL){
//         nodoUsuario->arbol = datousuario;
//         nodoUsuario->sig = NULL;
//         nodoUsuario->ant = NULL;
//         nodoUsuario->pos = 0;
//         (*l)->cabecera = nodoUsuario;
//     }else{
//         struct Nodo* nodoAux = (*l)->cabecera;
//         while (nodoAux->sig != NULL){
//             nodoAux = nodoAux->sig;
//         }
//         nodoUsuario->arbol = datousuario;
//         nodoUsuario->ant = nodoAux;
//         nodoAux->sig = nodoUsuario;
//         nodoUsuario->sig = NULL;
//         nodoUsuario->pos = nodoAux->pos + 1; 
//     }
//     (*l)->cursor++;
//     *e = 0;

// }

void agregarIzq(Lista *l, int *e, Dato datousuario){
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
    if ((*l)->cabecera ==  NULL){
        nodoUsuario->arbol->info = datousuario;
        nodoUsuario->sig = NULL;
        nodoUsuario->ant = NULL;
        nodoUsuario->pos = 0;
        (*l)->cabecera = nodoUsuario;
    } else {  
        nodoUsuario->arbol->info = datousuario;  
        struct Nodo* aux = (*l)->cabecera;
        nodoUsuario->sig = (*l)->cabecera;
        nodoUsuario->ant = NULL;
        aux->ant = nodoUsuario;
        (*l)->cabecera = nodoUsuario;
        nodoUsuario->pos = 0;
        while (aux != NULL){
            aux->pos++;
            aux = aux->sig;
        }
        
    }
     *e = 0;
    (*l)->cursor++;
}

void extraerDer(Lista *l, int *e, Arbol *datoextraido){
    if ((*l)->cabecera != NULL){
        struct Nodo* nodoAux = (*l)->cabecera;
        while (nodoAux->sig != NULL){
            nodoAux = nodoAux->sig;
        }
        (*datoextraido) = nodoAux->arbol;
        if (nodoAux->ant != NULL){
            nodoAux->ant->sig = NULL;
            nodoAux->ant = NULL;
        } else {
            (*l)->cabecera = NULL;
        }
        free(nodoAux);
        *e = 0;
        (*l)->cursor--;
    } else{
        *e = -1;
        perror("La lista esta vacia");
    }
}

void extraerIzq(Lista *l, int *e){
    if ((*l)->cabecera == NULL){
        *e = -1;
        perror("La lista esta vacia");
    } else{
        struct Nodo* nodoAux = (*l)->cabecera;
        (*l)->cabecera = nodoAux->sig;
        (*l)->cabecera->ant = NULL;
        nodoAux->sig = NULL;
        // (*datoextraido) = nodoAux->arbol;
        free(nodoAux);
        struct Nodo* nodoCursor = (*l)->cabecera;
        while ( nodoCursor != NULL){
            nodoCursor->pos--;
            nodoCursor = nodoCursor->sig;
        }
        *e = 0;
        (*l)->cursor--;
    }
}

void recorrerLista(Lista l, int *e){
    if (l->cabecera == NULL){
        *e = -1;
        perror("Lista vacia");
    } else {
        struct Nodo *nodoAux = (*l).cabecera;
        puts("Elementos de la lista:\n");
        while (nodoAux != NULL){
            printf("Pos: ||%d|| Dato: ||%c|| frecuencia %d\t\n", nodoAux->pos, nodoAux->arbol->info.caracter, nodoAux->arbol->info.frecuencia);
            nodoAux = nodoAux->sig;
        }
        puts("\n");
        *e = 0;
    }
}

void extraerN(Lista *l, int *e, int n){
        struct Nodo* nodoAux = (*l)->cabecera;
        while (nodoAux->pos < n){
            nodoAux = nodoAux->sig;
        }
        //printf("Dato extarido: %d\n", datoextraido->valor);
        struct Nodo* NodoEnlace = nodoAux->ant;
        NodoEnlace->sig = nodoAux->sig;
        nodoAux->sig->ant = NodoEnlace;
        nodoAux->sig = NULL;
        nodoAux->ant = NULL;
        free(nodoAux);
        struct Nodo* nodoCursor = NodoEnlace->sig;
        while ( nodoCursor != NULL){
            nodoCursor->pos--;
            nodoCursor = nodoCursor->sig;
        }
        *e = 0;
        (*l)->cursor--;
}

void borrarLista(Lista *l, int *e){
    struct Nodo *eliminar, *siguiente;
    eliminar = (*l)->cabecera;
    while (eliminar != NULL){
        siguiente = eliminar->sig;
        eliminar->sig = NULL;
        eliminar->ant=NULL;
        free(eliminar);
        eliminar = siguiente;
    }
    (*l)->cabecera= NULL;
}


void ordenamientoSeleccion(Lista *l, int tam){
    int i,j,k, aux;
    Dato pivote;
    struct Nodo* nodoAux = (*l)->cabecera;
    struct Nodo* nodoRecorre = (*l)->cabecera;

    puts("Entrandi");
    printf("Para un tam %d",tam);

    for(i=0; i<tam; i++){
        
        nodoRecorre = (*l)->cabecera;
        aux=i+1;
        for (j=i+1; j<tam; j++){
            //  INICIO DE OPERACION
            nodoRecorre = (*l)->cabecera;
            for(k=0;k<j;k++){
                nodoRecorre=nodoRecorre->sig;
            }

            
            if(nodoAux->arbol->info.frecuencia>nodoRecorre->arbol->info.frecuencia){
                //COPIAMOS LA IBNFO
                pivote.caracter = nodoAux->arbol->info.caracter;
                pivote.frecuencia = nodoAux->arbol->info.frecuencia;
                //PASAMOS LA INFO
                nodoAux->arbol->info=nodoRecorre->arbol->info;
                //El mayor passa al menor
                nodoRecorre->arbol->info.frecuencia=pivote.frecuencia;
                nodoRecorre->arbol->info.caracter=pivote.caracter;
            }
            

        }
        nodoAux=nodoAux->sig;
    }
}

void asignaCodigo(Arbol r, int codigo[], int n){
    int i;
    if((r->izq==NULL) && (r->der==NULL)){
        printf("\n\t%c Codigo: ",r->info.caracter);
        for(i=0; i< n; i++)
            printf("%d", codigo[i]);
    } else{
        codigo[n]=0; //Suponemos que siempre ira por la izquierda
        n++;
        asignaCodigo(r->izq,codigo,n);
        codigo[n-1]=1; //Por si el recorrido tuvo que ser por la derecha
        asignaCodigo(r->der,codigo,n);
    }
}



void iniciaOperacion(int argc, char** argv){
    //TIEMPO
    unsigned int t0, t1;
    t0=clock();

    char linea[64];
    char arreglo[33][64];
    int indice=0;
    int i,n;
    int error, op, pos, pose,tam=0;
    int frecuLetra=0;
    bool flag;
    //CREAMOS
    Lista lista = crearLista(&error);
    Dato datoextraido, datousuario;
    Dato datoagregado;
    struct Nodo* nodoLista = (struct Nodo*)malloc(sizeof(struct Nodo));
    //Lectura de TXT
    char *path="C:\\Users\\MrJel\\Desktop\\TextoPlano.txt";
    FILE *archivo=fopen(path,"r+");    
    if(archivo==NULL){
        perror("No se pudo abrir el archivo");
        exit(1);
    }
    //transferir todos los datos al arreglo
    while(!feof(archivo)){
        fgets(linea,64,archivo);
        printf("%c",archivo);
        strcpy(arreglo[indice],linea);
        indice++;
    }  

    for (int i = 0; i < strlen(linea); i++)
    {
        frecuLetra=0;
        for (int j = 0; j < strlen(linea); j++){
            /* code */
            if(linea[i]==linea[j]){
                frecuLetra++;
            } 
        }
        printf("\nLetra: %c  Frecuencia: %d",linea[i],frecuLetra);
        datoagregado.frecuencia=frecuLetra;
        datoagregado.caracter=linea[i];



        if (lista->cabecera == NULL){
            agregarDer(&lista, &error, datoagregado);
        } else {


            struct Nodo *nodoAux = (*lista).cabecera;

            while(nodoAux != NULL){
                if (nodoAux->arbol->info.caracter == datoagregado.caracter){
                    flag=true;
                    break;
                } else{
                    flag=false;
                } 
                nodoAux = nodoAux->sig; 
            }

            if (!flag){
                agregarDer(&lista, &error, datoagregado);
                tam++;

            }
            
        }
    }
    puts("\nDatos agregados correctamente");
    // \*struct Nodo *nodoAux = (*lista).cabecera;
    // struct Nodo *nodoAux2 = nodoAux->sig;
    // while((nodoAux->sig)!= NULL){
    //     while(nodoAux2 != NULL ){
    //         if (nodoAux->arbol->info.caracter == nodoAux2->arbol->info.caracter )
    //         {
    //             extraerN(&lista, &error, nodoAux2->pos);
    //         }
    //         nodoAux2 = nodoAux2->sig;
    //     }
    //     nodoAux = nodoAux->sig;
    //     //nodoAux2 = nodoAux2->sig;  
    //     //*error = 0;
    // }*/
    recorrerLista(lista,&error); 

    puts("ORDENAMIENTO");
    //EN CADA NODO DE LISTA HAY UN ARBOL
    ordenamientoSeleccion(&lista, tam+1);
    recorrerLista(lista,&error); 

    //=====================================================
    // SOLO QUEDA CODIGO HUFFMAN


    // n=tam+1;
    // int sumaFrecuencias,codigo[20];
    // char letra;
    // Arbol* raiz;
    //  while(n>1){ //Mientras que no se haya construido un árbol de HUFFMAN
    //     ordenarSeleccion(arreglo,n);  //Ordena el arreglo
    //     struct Nodo *nodoActual = (*lista).cabecera;
    //     struct Nodo *nodoSiguiente = (*lista).cabecera->sig;

    //     sumaFrecuencias=nodoActual.arbol.info.frecuencia+nodoSiguiente.arbol.info.frecuencia;
    //     letra='X';
    //     Dato nuevaRaiz={sumaFrecuencias,letra}; //Construcción del nuevo subárbol
        
    //     nuevoArbol(raiz, nodoActual, nodoSiguiente,nuevaRaiz);
    //     // printf("se crea raiz: c=%c, frecSuma=%d\n", (*raiz)->info.caracter,(*raiz)->info.frecuencia);
    //     agregarDerconArbol(&lista, &error, raiz);
    //     extraerIzq(&lista, &error);
    //     extraerIzq(&lista, &error);

    //     n--;
    // }
    // asignaCodigo(arreglo[0],codigo,0);

    

   //=====================================================





    //TIEMPO
    t1=clock();
    double time=(t1-t0)/CLOCKS_PER_SEC;
    printf("\nTiempo de ejecución: %f",time);

} 

void main(int argc, char** argv){
    unsigned int t0, t1;
    t0=clock();
    iniciaOperacion(argc, argv);
    t1=clock();
    double time=(t1-t0)/CLOCKS_PER_SEC;
    printf("\nTiempo de ejecución: %f",time);
}