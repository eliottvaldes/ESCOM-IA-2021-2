/*      =======================================================================
        ===================INSTITUTO POLITECNICO NACIONAL======================
        =======================================================================
                            =============================
                            =ESCUELA SUPERIOR DE COMPUTO=
                            =============================
>>Name: Sánchez Martánez Felipe
>>Gruop: 2BM1
>>Carrer: Artificial Inteligence Engineer.
>>date of last modification: 04/14/22
                   
P R A C T I C A     7

*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<string.h>
#define TAM 10

/*
    |Variable   | State    | Meaning
        error       0           Everything is OK.
        error      -1           Error, The BiTail is empty
        error      -4           There is no a BiTail, or it points to NULL
        error      -5           There is not a data in the structure
        error      -6           First Node is NUll
*/
typedef struct{
    char subject[25];
    char body[90];
} EmailInfo;
struct Node{
    EmailInfo data;
    struct Node* next;
};
//TDA BiTail dinámica
typedef struct{
    int cursorFront;//iterador  -> cantidad de Nodes existentes
    int cursorBack;
    struct Node* head;
    struct Node* final;
}Tail_element;

typedef Tail_element* BiTail;

BiTail createBiTail(int*);
// Inserta BiTail por el final
void enqueue(BiTail* bitail, int* error, EmailInfo emailInfo);
//Eliminar EmailInfo por la head
// void dequeue(BiTail* bitail, int* error, EmailInfo *emailInfo);
// Devuelve un true o un false si la BiTail contiene o no Nodes:
bool isEmpty(BiTail bitail,int* error);
// Libera la memoria RAM usada por la BiTail:
void eraseBiTail(BiTail* bitail, int* error);
void deleteEmails(BiTail* bitail, int* error);
void printBiTail(BiTail* bitail, int* error);
void showBiTail(BiTail bitail, int* error,EmailInfo *emailInfo);
void printFirstEmail(BiTail bitail, int* error, EmailInfo *emailInfo);
void push(BiTail *bitail, int* error, EmailInfo emailInfo);//push
void pop(BiTail *bitail, int* error, EmailInfo *emailInfo);

int main(){
    int option,error;
    EmailInfo emailInfo;
    struct Node email;
    BiTail bitail=createBiTail(&error);
    puts("Welcome to a mail program using the stack and tail structure");
    do{
        puts("What do you want to do?");
        puts("1.-Insert a email in the front");
        puts("2.-Insert a email in the End");
        puts("3.-Show the first email to send");
        puts("4.-Show all the emails");
        puts("5.-Count the emails, that you have");
        puts("6.-Delete the first email");
        puts("7.-Delete all the emails");
        puts("8.-Send all the mails");
        puts("9.-Get out the program");
        scanf("%d",&option);
        switch(option){
            case 1 :
                puts("Please insert the subject of the email:");
                fflush(stdin);
                scanf("%s",&email.data.subject);
                printf("\n");
                puts("Please insert the body of the email:");
                fflush(stdin);
                scanf("%s",&email.data.body);
                push(&bitail,&error,email.data);
                printf("\n");
                printf("\n");
                break;
            case 2 :
                puts("Please insert the subject of the email:");
                fflush(stdin);
                scanf("%s",&email.data.subject);
                printf("\n");
                puts("Please insert the body of the email:");
                fflush(stdin);
                scanf("%s",&email.data.body);
                enqueue(&bitail,&error,email.data);
                printf("\n");
                printf("\n");
                break;
            case 3 :
                printFirstEmail(bitail, &error, &emailInfo);
                printf("\n");
                printf("\n");
                break;
            case 4 :
                showBiTail(bitail, &error, &emailInfo);
                printf("\n");
                printf("\n");
                break;
            case 5 :
                printf("The total amount of emails is: %d",bitail->cursorFront+abs(bitail->cursorBack));
                printf("\n");
                printf("\n");
                break;
            case 6 :
                pop(&bitail, &error,&emailInfo);
                printf("\n");
                printf("\n");
                break;
            case 7 :
                deleteEmails(&bitail, &error);
                printf("\n");
                printf("\n");
                break;
            case 8 :
                printBiTail(&bitail, &error);
                printf("\n");
                printf("\n");
                break;
            case 9 :
                puts("Have a nice day :)");
                eraseBiTail(&bitail, &error);
                exit(0);
                break;
            default :
                puts("Please select a correct option");
                break;
        }
    }while(true);
}



BiTail createBiTail(int* e){
    BiTail biTail=(BiTail) malloc(sizeof(Tail_element));
    if(biTail==NULL){
        *e=-4;
        puts("No se logro obtener memoria para una estructura BiTail");
    }
    biTail->head=NULL;
    biTail->final=NULL;
    biTail->cursorFront=0;
    biTail->cursorBack=0;
    return biTail;
}



//Eliminar data por la head
// void dequeue(BiTail* BiTail, int* e, EmailInfo *EmailInfoExtraido){
//     struct Node* NodeAuxiliar=NULL;
//     if(isEmpty(*BiTail,e)){
//         *e=-1;
//         puts("La BiTail esta vacia, no es posible leer un elemento");
//     } else if((*BiTail)->cursor>1){
//         NodeAuxiliar=(*BiTail)->head;
//         (*BiTail)->head=(*BiTail)->head->next;
//         NodeAuxiliar->next=NULL;

//     } else if((*BiTail)->cursor==1){
//         NodeAuxiliar=(*BiTail)->head;
//         (*BiTail)->head=NULL;
//         (*BiTail)->final=NULL;
//     }
//     (*BiTail)->cursor--;
//     *EmailInfoExtraido=NodeAuxiliar->EmailInfo;
//     free(NodeAuxiliar);
//     *e=0;
// }

// Devuelve un true o un false si la BiTail contiene o no Nodes:
bool isEmpty(BiTail bitail,int *e){
    if(bitail->head==NULL && bitail->final==NULL && bitail->cursorFront==bitail->cursorBack){
        *e=-1;
        return true;
    } else{
        *e=0;
        return false;
    }
}



//Aqui andamos
void push(BiTail* bitail, int* error, EmailInfo emailInfo){
    struct Node* userNode=(struct Node*) malloc(sizeof(struct Node));
    if(userNode==NULL){
        perror("There is no memory");
        *error=-1;
    }else if(isEmpty(*bitail,error)){
        userNode->data=emailInfo;
        userNode->next=NULL;
        (*bitail)->head=userNode;
        (*bitail)->final=userNode;

    }else{
        userNode->data=emailInfo;
        userNode->next=(*bitail)->head;
        (*bitail)->head=userNode;
    }
    (*bitail)->cursorFront++;
    *error=0;
}

// Inserta BiTail por el final
void enqueue(BiTail* bitail, int* error, EmailInfo emailInfo){
    struct Node* userNode=(struct Node*) malloc(sizeof(struct Node));
    if(userNode==NULL){
        *error=-6;
        puts("There is no memory");
    }
    else if(isEmpty(*bitail,error)){
        userNode->data=emailInfo;
        userNode->next=NULL;
        (*bitail)->head=userNode;
        (*bitail)->final=userNode;
    } else{
        userNode->data=emailInfo;
        userNode->next=NULL;
        (*bitail)->final->next=userNode;
       (*bitail)->final=userNode;

    }
    *error=0;
    (*bitail)->cursorBack--;
}

void printFirstEmail(BiTail bitail, int* error, EmailInfo *emailInfo){
    if(isEmpty(bitail,error)){
        puts("There is no email to show");
    }else{
        *emailInfo= bitail->head->data;
        printf("Subject of the first email: %s",emailInfo->subject);
        *error=0;
    }
}

void showBiTail(BiTail bitail, int* error,EmailInfo *emailInfo){
    if(isEmpty(bitail,error)){
        puts("There is no email to show");
    }else{
        struct Node* userNode=(struct Node*) malloc(sizeof(struct Node));
        int cursorAux,i=1;
        cursorAux=bitail->cursorFront;
        userNode=bitail->head;
        puts("\n\n");
        while(cursorAux!=bitail->cursorBack){
            puts("\n");
            printf("The email #%d with Subject: %s\n",i,userNode->data.subject);
            cursorAux--;
            i++;
            userNode=userNode->next;

        }
        *error=0;
    }
}

void pop(BiTail *bitail, int* error, EmailInfo *emailInfo){
    struct Node* nodoAuxiliar=NULL;
    if(isEmpty(*bitail,error)){
        *error=-1;
        puts("There is no email to send");
    } else if((*bitail)->cursorFront==1 && (*bitail)->cursorBack==0){
        nodoAuxiliar=(*bitail)->head;
        (*bitail)->head=(*bitail)->head->next;
        nodoAuxiliar->next=NULL;
        (*bitail)->cursorFront--;
        (*bitail)->head=NULL;
        (*bitail)->final=NULL;
        *emailInfo=nodoAuxiliar->data;
    } else if((*bitail)->cursorFront==0 && (*bitail)->cursorBack==-1){

        nodoAuxiliar=(*bitail)->head;
        (*bitail)->head=(*bitail)->head->next;
        nodoAuxiliar->next=NULL;
        (*bitail)->cursorBack++;
        (*bitail)->head=NULL;
        (*bitail)->final=NULL;
        *emailInfo=nodoAuxiliar->data;
    }else if((*bitail)->cursorFront>0){
        nodoAuxiliar=(*bitail)->head;
        (*bitail)->head=(*bitail)->head->next;
        nodoAuxiliar->next=NULL;
        (*bitail)->cursorFront--;
        *emailInfo=nodoAuxiliar->data;
    }else if((*bitail)->cursorBack<0){

        nodoAuxiliar=(*bitail)->head;
        (*bitail)->head=(*bitail)->head->next;
        nodoAuxiliar->next=NULL;
        (*bitail)->cursorBack++;
        *emailInfo=nodoAuxiliar->data;
    }
    free(nodoAuxiliar);
    *error=0;

}

void deleteEmails(BiTail* bitail, int* error){
    if(!isEmpty(*bitail,error)){
        struct Node* nodoAuxiliar, *nodoAuxiliarRespaldo;
        nodoAuxiliar=(*bitail)->head;
        while(nodoAuxiliar!=NULL){
            nodoAuxiliarRespaldo=nodoAuxiliar->next;
            nodoAuxiliar->next=NULL;
            free(nodoAuxiliar);
            nodoAuxiliar=nodoAuxiliarRespaldo;
        }
        (*bitail)->head=NULL;
        (*bitail)->final=NULL;
        (*bitail)->cursorFront=0;
        (*bitail)->cursorBack=0;
        *error=0;
    }
}

void eraseBiTail(BiTail* bitail, int* error){
    // Libera la memoria RAM usada por la BiTail:
    if(!isEmpty(*bitail,error)){
        struct Node* nodoAuxiliar, *nodoAuxiliarRespaldo;
        nodoAuxiliar=(*bitail)->head;
        while(nodoAuxiliar!=NULL){
            nodoAuxiliarRespaldo=nodoAuxiliar->next;
            nodoAuxiliar->next=NULL;
            free(nodoAuxiliar);
            nodoAuxiliar=nodoAuxiliarRespaldo;
        }
        (*bitail)->head=NULL;
        (*bitail)->final=NULL;
        (*bitail)->cursorFront=0;
        (*bitail)->cursorBack=0;
        *error=0;
        free(*bitail);
    }

}

void printBiTail(BiTail* bitail, int* error){
    EmailInfo emailInfo;
    int cursorAuxFr,i=1;
    if(isEmpty(*bitail,error)){
        puts("nothing to send");
        *error=-1;
    }else{
        while((*bitail)->cursorFront!=(*bitail)->cursorBack){
            pop(bitail, error, &emailInfo);
            printf("The email #%d with subject: %s\n",i,emailInfo.subject);
            puts("It was sent successfully\n\n");
            i++;
        }
        (*bitail)->head=NULL;
        (*bitail)->final=NULL;
        (*bitail)->cursorFront=0;
        (*bitail)->cursorBack=0;
        puts("\n***We send successfully all the emails***\n\n");
        *error=0;
    }
}