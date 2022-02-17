#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{ //snodo es el nombre de la estructura
    char nombre[256];
    char telefono[9];
    struct nodo *sig; //El puntero siguiente para recorrer la lista enlazada
}tnodo; //tnodo es el tipo de dato para declarar la estructura

typedef tnodo *tp; //Puntero al tipo de dato tnodo para no utilizar punteros de punteros

void insertarEnLista (tp *root, char n[256],char t[9]);
void imprimeLista (tp root);
void borraContacto(tp *root, char n[256]);
//void borrarLista (tp *root);

int main(){
    tp root=NULL;
    int opcion=-1;
    do{
        printf("1. Imprime agenda\n");
        printf("2. Inserta contacto\n");
        printf("3. Elimina contacto\n");
        printf("4. Salir\n");

        scanf("%d",&opcion);

        switch(opcion){
            case 1:
                imprimeLista(root);
                break;
            case 2:
                printf("Inserte el nombre: ");
                char n[256];
                scanf("%s",n);
                printf("Inserte teléfono: ");
                char t[9];
                scanf("%s",t);
                borraContacto(&root,n);  //eliminar si existiese
                insertarEnLista(&root,n,t);
                break;
            case 3:
                printf("Inserte el nombre: ");
                char n2[256];
                scanf("%s",n2);
                borraContacto(&root,n2);
                break;
            case 4: break;
            default:
                printf("Opción incorrecta\n");
        }


    }while(opcion!=4);
    printf("Hasta pronto\n");
}
void insertarEnLista (tp *root, char n[256],char t[9]){
    tp nuevoNodo=(tp)malloc(sizeof(tnodo));
    strcpy(nuevoNodo->nombre,n);
    strcpy(nuevoNodo->telefono,t);
    nuevoNodo->sig=NULL;

    if(*root==NULL){
        *root=nuevoNodo;
    }else{
        tp aux=*root;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevoNodo;
    }   
}
void imprimeLista (tp root){
    if(root!=NULL){
        tp aux=root;
        while(aux!=NULL){
            printf("Nombre: %s y teléfono %s\n",aux->nombre,aux->telefono);
            aux=aux->sig;
        }
    }else{
        printf("Agenda vacía\n");
    }
}
void borraContacto(tp *root, char n[256]){
    if(*root!=NULL){
        tp aux;
        tp ant=NULL;
        aux=*root;
        int deleted=0;
        while(aux!=NULL&&deleted==0){
            if(strcmp(aux->nombre,n)==0){
                deleted=1;
                if(ant==NULL){
                    *root=aux->sig;
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