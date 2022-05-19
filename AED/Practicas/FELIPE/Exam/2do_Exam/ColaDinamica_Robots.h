#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
    |Variable   | Estado    | Significado
        error       0           Sin errores (todo resultado es exitoso)
        error      -1           Error, COLA vacía
        error      -4           Inexistencia de la COLA, o esta apunta a NULL
        error      -5           Inexistencia de Data en la estructura
        error      -6           Node inicial nulo
*/
typedef struct
{
    int valor;
    float altura;
    int edad;
    char nombre[20];
} Data;
struct Node
{
    Data Data;
    struct Node *siguiente;
};
// TDA Cola dinámica
typedef struct
{
    int cursor; // iterador  -> cantidad de Nodes existentes
    struct Node *cabecera;
    struct Node *final;
} Elemento_de_Cola;
typedef Elemento_de_Cola *Cola;

Cola crearCola(int *);
// Inserta cola por el final
void encolar(Cola *, int *, Data);
// Eliminar Data por la cabecera
void desencolar(Cola *, int *, Data *);
// Devuelve un true o un false si la cola contiene o no Nodes:
bool estaVacia(Cola, int *);
// Libera la memoria RAM usada por la cola:
void borraCola(Cola *, int *);
void imprimeCola(Cola, int *);

/**int main(){
    int error;
    int cantidadDatas;
    Cola p=crearCola(&error);
    struct Node Data;
    Data DataExtraido;
    puts("¿Cuantos valores quieres agregar a la pila?");
    fflush(stdin);
    scanf("%d",&cantidadDatas);
    for(int i=0; i<cantidadDatas; i++){
        puts("Ingresa un valor:");
        fflush(stdin);
        scanf("%d",&Data.Data.valor);
        encolar(&p,&error,Data.Data);
    }
    desencolar(&p,&error,&DataExtraido);
    printf("Data extraido es : %d\n", DataExtraido.valor);
    imprimeCola(p,&error);
    borraCola(&p,&error);
}
**/

Cola crearCola(int *e)
{
    Cola cola = (Cola)malloc(sizeof(Elemento_de_Cola));
    if (cola == NULL)
    {
        *e = -4;
        puts("No se logro obtener memoria para una estructura COLA");
    }
    cola->cabecera = NULL;
    cola->final = NULL;
    cola->cursor = 0;
    return cola;
}

// Inserta cola por el final
void encolar(Cola *cola, int *e, Data DataIngreso)
{
    struct Node *NodeUsuario = (struct Node *)malloc(sizeof(struct Node));
    if (NodeUsuario == NULL)
    {
        *e = -6;
        puts("La estructura del nuevo Node no se creo correctamente, favor de liberar Datas de la cola");
    }
    else if (estaVacia(*cola, e))
    {
        (*NodeUsuario).Data = DataIngreso;
        (*NodeUsuario).siguiente = NULL;
        (*cola)->cabecera = NodeUsuario;
        (*cola)->final = NodeUsuario;
    }
    else
    {
        (*NodeUsuario).Data = DataIngreso;
        (*NodeUsuario).siguiente = NULL;
        (*cola)->final->siguiente = NodeUsuario;
        (*cola)->final = NodeUsuario;
    }
    (*cola)->cursor++;
    *e = 0;
}

// Eliminar Data por la cabecera
void desencolar(Cola *cola, int *e, Data *DataExtraido)
{
    struct Node *NodeAuxiliar = NULL;
    if (estaVacia(*cola, e))
    {
        *e = -1;
        puts("La cola esta vacia, no es posible leer un elemento");
    }
    else if ((*cola)->cursor > 1)
    {
        NodeAuxiliar = (*cola)->cabecera;
        (*cola)->cabecera = (*cola)->cabecera->siguiente;
        NodeAuxiliar->siguiente = NULL;
    }
    else if ((*cola)->cursor == 1)
    {
        NodeAuxiliar = (*cola)->cabecera;
        (*cola)->cabecera = NULL;
        (*cola)->final = NULL;
    }
    (*cola)->cursor--;
    *DataExtraido = NodeAuxiliar->Data;
    free(NodeAuxiliar);
    *e = 0;
}

// Devuelve un true o un false si la cola contiene o no Nodes:
bool estaVacia(Cola cola, int *e)
{
    if (cola->cabecera == NULL && cola->final == NULL && cola->cursor == 0)
    {
        *e = -1;
        return true;
    }
    else
    {
        *e = 0;
        return false;
    }
}

// Libera la memoria RAM usada por la cola:
void borraCola(Cola *cola, int *e)
{
    if (!estaVacia(*cola, e))
    {
        struct Node *NodeAuxiliar, *NodeAuxiliarRespaldo;
        NodeAuxiliar = (*cola)->cabecera;
        while (NodeAuxiliar != NULL)
        {
            NodeAuxiliarRespaldo = NodeAuxiliar->siguiente;
            free(NodeAuxiliar);
            NodeAuxiliar = NodeAuxiliarRespaldo;
        }
        (*cola)->cabecera = NULL;
        (*cola)->final = NULL;
        (*cola)->cursor = 0;
        *e = 0;
        free(*cola);
    }
}

void imprimeCola(Cola cola, int *e)
{
    Data Data;
    while (!estaVacia(cola, e))
    {
        desencolar(&cola, e, &Data);
        printf(".-Data extraido es : %d\n", Data.valor);
    }
    *e = 0;
}
