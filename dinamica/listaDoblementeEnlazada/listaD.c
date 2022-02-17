#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Método que devuelva el número de contactos que tienes
 * Imprimir el elemento indicado por una pos
 * Inserta un nuevo nodo, pero en la posición indicada (ojo)
 * 
 * Imprimir hacia atrás -> doblemente enlazada (ojo2)
 */

typedef struct n{
    char nombre[256];
    char telefono[9];
    struct n *sig;
    //struct n *ant;
}nodo;

typedef nodo* pnodo;  //creamos un alias a los punteros a nodos

void imprimeLista(pnodo r);
void insertaContacto(pnodo *r,char n[256],char t[9]);
void borraContacto(pnodo *r, char n[256]);
int main(){
    pnodo raiz=NULL;   //nodo *raiz=NULL;

    int opcion=-1;
    do{
        printf("1. Imprime agenda\n");
        printf("2. Inserta contacto\n");
        printf("3. Elimina contacto\n");
        printf("4. Salir\n");

        scanf("%d",&opcion);
        switch (opcion){
        case 1:  imprimeLista(raiz);
                 break;
        case 2:
                printf("Inserte el nombre: ");
                char n[256];
                scanf("%s",n);
                printf("Inserte teléfono: ");
                char t[9];
                scanf("%s",t);
                borraContacto(&raiz,n);
                insertaContacto(&raiz,n,t);
                break;
        case 3: 
                printf("Inserte el nombre: ");
                char n2[256];
                scanf("%s",n2);
                borraContacto(&raiz,n2);
                break;
        case 4: break;
        default: printf("Opción incorrecta");
                 break;
        }
    }while(opcion!=4);
    printf("Hasta pronto...");
    return 0;
}

void insertaContacto(pnodo *r,char n[256],char t[9]){
    //Creo el nuevo nodo
    nodo *nuevoNodo=(nodo *)malloc(sizeof(nodo));  //devuelve la dirección de memoria donde se ha reservado la zona del struct
    /**  nuevoNodo en memoria
     *   -> char nombre[256]
     *   -> char telefono[9]
     *   -> nodo *sig;
     */
    strcpy(nuevoNodo->nombre,n);  // strcpy((*nuevoNodo).nombre,n); /nuevoNodo->nombre=n;
    strcpy(nuevoNodo->telefono,t);
    nuevoNodo->sig=NULL;
    /**  nuevoNodo en memoria
     *   -> char nombre[256]="Carlos"
     *   -> char telefono[9]="123"
     *   -> nodo *sig=NULL
     */

    //Nodo listo para ser insertado
    if(*r==NULL){
        //lista vacía
        //el *r es el valor del puntero, es decir la dirección a la que el puntero apunta
        *r=nuevoNodo;
    }else{
        //El puntero no apunta a NULL, sino a algún nodo
        //nodo 1 -> nodo 2 -> nodo 3 -> NULL
        //paso 1 -> irme hasta el último nodo
        //nodo 3 -> nuevoNodo
        pnodo aux=*r;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        //aux apunta al último elemento
        aux->sig=nuevoNodo;
    }
}
void imprimeLista(pnodo r){
    if(r==NULL){
        printf("La lista está vacía\n");
    }else{
        pnodo aux=r;
        while(aux!=NULL){
            printf("Nombre: %s y teléfono %s\n",aux->nombre,aux->telefono);
            aux=aux->sig;
        }
    }
}
void borraContacto(pnodo *r, char n[256]){
    if(*r!=NULL){
        pnodo aux;
        pnodo ant=NULL;
        aux=*r;
        int deleted=0;
        while(aux!=NULL && deleted==0){
            if(strcmp(aux->nombre,n)==0){
                //EUREKA, encontrado
                deleted=1;
                if(ant==NULL){
                    //estoy en el primer nodo;
                    *r=aux->sig;
                    free(aux);
                }else{
                    ant->sig=aux->sig;
                    free(aux);
                }
            }else{
                ant=aux;
                aux=aux->sig;
            }
        }
    }
}
