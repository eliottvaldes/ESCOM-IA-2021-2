#include "arbolBST.h"

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
		printf("%d,",raiz->info);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void posOrden(Arbol raiz){ 
	if(raiz){
		posOrden(raiz->izq);
		posOrden(raiz->der);
		printf("%d,",raiz->info);
	}
}

void inOrden(Arbol raiz){ 
	if(raiz){
		inOrden(raiz->izq);
		printf("%d,",raiz->info);
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
        if(raiz->info==valor){
            *nodoEncontrado=raiz;       //Aqui se sobre escribe el valor nulo, por el valor encontrado.
        } else if(valor>raiz->info){
            buscarNodo(raiz->der, valor, nodoEncontrado);
        } else{
            buscarNodo(raiz->izq, valor, nodoEncontrado);
        }
    } 
}


void ingresarNodo(Arbol* raiz, Dato valor){ 
    if(!(*raiz)){
        (*raiz)=crearNodo(valor);
    } else if(valor<(*raiz)->info){
        ingresarNodo(&((*raiz)->izq),valor);
    } else if(valor>=(*raiz)->info){
        ingresarNodo(&((*raiz)->der),valor);
    }
}


void eliminarNodo(Arbol* raiz, Dato valor){ 
    if((*raiz)){
		Arbol aux=(*raiz);
		if(valor==(*raiz)->info){
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
		}else if(valor<(*raiz)->info)
			eliminarNodo(&((*raiz)->izq),valor);
		else if(valor>(*raiz)->info)
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
	(*nodo)->info=0;
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
  if (valor < raiz->info)
    raiz->izq = deleteNodeBST(raiz->izq, valor);
  else if (valor > raiz->info)
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