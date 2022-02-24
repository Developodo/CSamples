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
int numeroContactos(tp root);
void extraerContacto (tp root, int n);
void insertarEnPosicion (tp *root, int pos, char n[256],char t[9]);

//void borrarLista (tp *root);

int main(){
    tp root=NULL;
    int opcion=-1;
    do{
        printf("\n");
        printf("\t MENÚ EJERCICIO LISTAS\n");
        printf("     *****************************\n");
        printf("\n");
        printf("Seleccione una opción:\n");
        printf("1. Imprime agenda\n");
        printf("2. Inserta contacto\n");
        printf("3. Elimina contacto\n");
        printf("4. Número de contactos\n");
        printf("5. Extraer contacto\n");
        printf("6. Insertar contacto en una posición\n");
        printf("7. Salir\n");

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
            case 4:
                printf("La lista tiene %d contactos\n",  numeroContactos(root) );
                break;
            case 5:
                printf("¿Qué número de contacto de la lista quiere extraer?\n");
                int numero;
                scanf("%d", &numero);
                if (numero>numeroContactos(root)+1){
                    printf("En la lista hay menos contactos que el número introducido\n");
                }else{
                    extraerContacto(root, numero);
                }
                break;
            case 6:
                printf("¿En qué posición quieres incluir el nuevo contacto?\n");
                int posicion;
                scanf("%d", &posicion);
                if (posicion>numeroContactos(root)){
                    printf("En la lista hay menos contactos que el número introducido\n");
                }else{
                    printf("Inserte el nombre: ");
                    char n[256];
                    scanf("%s",n);
                    fflush(stdin);
                    printf("Inserte teléfono: ");
                    char t[9];
                    scanf("%s",t);
                    fflush(stdin);
                    insertarEnPosicion(&root, posicion, n, t);
                }
                break;
            case 7:
                break;
            default:
                printf("Opción incorrecta\n");
        }


    }while(opcion!=7);
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
int numeroContactos(tp root)
{
    int numero=0;
    if(root!=NULL){
        tp aux=root;
        while(aux!=NULL){
            aux=aux->sig;
            numero++;
        }
    }else{
        printf("Agenda vacía\n");
    }
    return numero;
}

void extraerContacto (tp root, int n)
{
    int posicion=1;
    if (root != NULL){
        tp aux= root;
        while(aux!=NULL){
            if (posicion == n){
                printf("%d. Nombre: %s y teléfono %s\n",posicion, aux->nombre,aux->telefono);    
            } 
            posicion++;
            aux=aux->sig;
        }
    }else{
        printf("Agenda vacía\n");
    }
}

void insertarEnPosicion (tp *root, int pos, char n[256],char t[9])
{
    tp nuevoNodo=(tp)malloc(sizeof(tnodo));
    strcpy(nuevoNodo->nombre,n);
    strcpy(nuevoNodo->telefono,t);
    nuevoNodo->sig=NULL;

    tp aux=*root;
    tp ant=NULL;
    
    int posicion=1;
    
    while(posicion != pos){
            ant=aux;
            aux=aux->sig;
            posicion++;
    }
    if(ant!=NULL){
        //No somos el primero
        if(aux!=NULL){
            //no soy el último
            ant->sig = nuevoNodo;
            nuevoNodo->sig=aux;
        }else{
            //si soy el último, por lo tanto el último (aux), su sig -> nuevoNodo
            ant->sig=nuevoNodo;
        }
    }else{
        //primer nodo
        nuevoNodo->sig=aux;  //siguiente es el primer nodo
        *root=nuevoNodo; //el primer nodo es ahora nuevoNodo
    }
}  
