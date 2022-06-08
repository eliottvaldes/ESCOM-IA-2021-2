#include "codigoHuffman.h"

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

/**
* @param raiz Raiz del subarbol donde se contara la profundidad
*/
int profundidadArbol(Arbol raiz){ 
    if(!raiz){
        return 0;
    } else{
        int profundidadIzq, profundidadDerecha;
        profundidadIzq=profundidadArbol(raiz->izq);
        profundidadDerecha=profundidadArbol(raiz->der);
        if(profundidadIzq>profundidadDerecha)
            return profundidadIzq+1;
        else 
            return profundidadDerecha+1;
    }
}

void contarHojas(Arbol raiz, int* contadorHojas){
    if(raiz){
        contarHojas(raiz->izq,contadorHojas);
        contarHojas(raiz->der, contadorHojas);
        if(raiz->izq==NULL && raiz->der==NULL)
            (*contadorHojas)++;
    }
}

void preOrden(Arbol raiz){ 
    if(raiz){
		printf("letra:%c-frec:%d,",raiz->info.caracter, raiz->info.frecuencia);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void posOrden(Arbol raiz){ 
	if(raiz){
		posOrden(raiz->izq);
		posOrden(raiz->der);
		printf("letra:%c-frec:%d,",raiz->info.caracter, raiz->info.frecuencia);
	}
}

void inOrden(Arbol raiz){ 
	if(raiz){
		inOrden(raiz->izq);
		printf("letra:%c-frec:%d,",raiz->info.caracter, raiz->info.frecuencia);
		inOrden(raiz->der);
	}
}

void eliminarArbol(Arbol* raiz){ 
    if(*raiz){
        eliminarArbol(&((*raiz)->izq));
        eliminarArbol(&((*raiz)->der));
        free(*raiz);
		*raiz=NULL;
    }
}

void buscarNodo(Arbol raiz, Dato valor, Arbol* nodoEncontrado){ 
    if(raiz){
        if(raiz->info.frecuencia==valor.frecuencia){
            *nodoEncontrado=raiz;       //Aqui se sobre escribe el valor nulo, por el valor encontrado.
        } else if(valor.frecuencia>raiz->info.frecuencia){
            buscarNodo(raiz->der, valor, nodoEncontrado);
        } else{
            buscarNodo(raiz->izq, valor, nodoEncontrado);
        }
    } 
}


void ingresarNodo(Arbol* raiz, Dato valor){ 
    if(!(*raiz)){
        (*raiz)=crearNodo(valor);
    } else if(valor.frecuencia<(*raiz)->info.frecuencia){
        ingresarNodo(&((*raiz)->izq),valor);
    } else if(valor.frecuencia>=(*raiz)->info.frecuencia){
        ingresarNodo(&((*raiz)->der),valor);
    }
}


void eliminarNodo(Arbol* raiz, Dato valor){ 
    if((*raiz)){
		Arbol aux=(*raiz);
		if(valor.frecuencia==(*raiz)->info.frecuencia){
			printf("\nSe encontro el nodo con el valor %d\n", (*raiz)->info);
			if(aux->izq==NULL){
				*raiz=aux->der;
			} else if (aux->der==NULL){
				*raiz=aux->izq;
			} else{
				reemplazar(&aux);
			}
			free(aux);
			aux=NULL;
		}else if(valor.frecuencia<(*raiz)->info.frecuencia)
			eliminarNodo(&((*raiz)->izq),valor);
		else if(valor.frecuencia>(*raiz)->info.frecuencia)
			eliminarNodo(&((*raiz)->der),valor);
	}
}


//Nodo será en un principio el nodo a eliminar (solicitado por el usuario),
//Despues se convertira en el nodo más pequeño, para que este sea quien se elimine.
void reemplazar(Arbol* nodo){ 
    Arbol nodoMinimo, nodoAnterior;
    nodoAnterior=*nodo;
    //Se busca el valor más pequeño en el sub arbol derecho
    nodoMinimo=(*nodo)->der;
    while(nodoMinimo->izq!=NULL){ 
        nodoAnterior=nodoMinimo;
        nodoMinimo=nodoMinimo->izq;
    }
	//Se respalda el valor pequeño para despues asignarse al nodo raiz
    Dato aux=nodoMinimo->info;
	//Se asigna un valor muy pequeño provisional, ya que en cualquier caso de que 
	//el valor más pequeño resulte ser el mismo valor que el que se desea eliminar esto provocará un 
	//bucle infinito
	(*nodo)->info.frecuencia=0;
    //Se borra el nodo minimo
    eliminarNodo(nodo,nodoMinimo->info);
	 //Se reemplaza el nodo a eliminar por el nodo con valor más pequeño
	(*nodo)->info=aux;
    //Se marca el nodominimo para eliminación    
    *nodo=nodoMinimo;
}



Arbol deleteNodeBST(Arbol raiz, Dato valor) {
  // Return el mismo arbol si es que esta vacio
  if (raiz == NULL) 
	  return raiz;

  // Encontrando el nodo para eliminarse 
  if (valor.frecuencia < raiz->info.frecuencia)
    raiz->izq = deleteNodeBST(raiz->izq, valor);
  else if (valor.frecuencia > raiz->info.frecuencia)
    raiz->der = deleteNodeBST(raiz->der, valor);
  else {
	  //Se evalua caso de que el nodo a eliminar tenga un hijo o 0 hijos
    if (raiz->izq == NULL) {
      Arbol temp = raiz->der;
      free(raiz);
      return temp;
    } else if (raiz->der == NULL) {
      Arbol temp = raiz->izq;
      free(raiz);
      return temp;
    }
    // En caso de que se tengan dos hijos
    Arbol temp = nodoMinimo(raiz->der);
    // Reemplaza el nodo solicitado por el usuario por el más pequeño del subarbol derecho
    raiz->info = temp->info;
    // Elimina el nodo más pequeño del sub-arbol derecho, utilizado para remplazar al nodo eliminado por el usuario
    raiz->der = deleteNodeBST(raiz->der, temp->info);
  }
  return raiz;
}


// Funcion para encontrar el valor más pequeño de un arbol
Arbol nodoMinimo(Arbol nodo) {
  Arbol actual = nodo;
  // Buscamos en todos los subarboles izquierdos
  while (actual && actual->izq != NULL)
    actual = actual->izq;
  return actual;
}

//Funciones Huffman

void ordenar(Arbol* arreglo, int tam){
    int i,j;
    struct nodo* temp;
    for(i=1; i<tam;i++){
        for(j=0; j<tam-1; j++){
            if(arreglo[j]->info.frecuencia > arreglo[j+1]->info.frecuencia){
                temp=arreglo[j];
                arreglo[j]=arreglo[j+1];
                arreglo[j+1]=temp;
            }
        }
    }
}

/**
 * @param r raiz del arbol completo donde se buscará el nodo
 * @param codigo Arreglo donde se guardara el código del caracter
 * @param n pos en el arreglo de codigos, una pos por cada nivel que se recorre
 */
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
    Arbol* raiz;
    int i,j,n,sumaFrecuencias,codigo[20];
    char letra;
    //Arreglo de arboles
    Arbol* arreglo=(Arbol*) malloc(sizeof(Arbol)*20);//Hasta 20 subarboles
    if(arreglo==NULL){
        perror("Se acabo la memoria para el arreglo de arboles");
        exit(1);
    }
    int frecuencia;
    printf("Código de Huffman");
    printf("\n Ingrese el numero de caracteres a codificar:");
    fflush(stdin);
    scanf("%d",&n);
    //La tabla de frecuencias la proporcionará el usuario, caracter por caracter
    for(i=0; i<n; i++){
        printf("\nIngresa el caracter y su frecuencia:");
        fflush(stdin);
        letra=getchar();
        scanf("%d", &frecuencia);
        //printf("valores leidos: ca=%c, f=%d",dato,frecuencia);
        Dato nuevoCar={frecuencia,letra};
        arreglo[i]=crearNodo(nuevoCar); //Ingresa el arreglo con los datos al arreglo
    }
    while(n>1){ //Mientras que no se haya construido un árbol de HUFFMAN
        ordenar(arreglo,n);  //Ordena el arreglo
        sumaFrecuencias=arreglo[0]->info.frecuencia+arreglo[1]->info.frecuencia;
        letra=arreglo[1]->info.caracter;
        Dato nuevaRaiz={sumaFrecuencias,letra}; //Construcción del nuevo subárbol
        nuevoArbol(raiz, arreglo[0], arreglo[1],nuevaRaiz);
        printf("se crea raiz: c=%c, frecSuma=%d\n", (*raiz)->info.caracter,(*raiz)->info.frecuencia);
        arreglo[0]=*raiz;
        for(j=1; j<n-1; j++)// se recorren los arboles a la izquierda del arreglo
            arreglo[j]=arreglo[j+1];
        n--;
    }
    //Se le asigna el código a cada caracter que hay en el árbol de Huffman
    asignaCodigo(arreglo[0],codigo,0);
    //Eliminación de árbol y liberación de memoria.
    eliminarArbol(&arreglo[0]);
    free(arreglo);
}
