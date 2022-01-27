#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void imprimeLista(int *l,int n);
int main(){
    int vector[4];
    int *vectorPuntero;
    
    int n;
    printf("Cuantos número desea almacenar: ");
    scanf("%d",&n);
    vectorPuntero= (int *)malloc(n*sizeof(int));  //recibe el número de bytes

    
    for(int i=0;i<n;i++){
        fflush(stdin);
        printf("Introduzca el número %d: ",(i+1));
        scanf("%d",&vectorPuntero[i]);
    }
    imprimeLista(vectorPuntero,n);
    free(vectorPuntero);


    /**
     * Alternativa Calloc
     *  vectorPuntero= (int *)calloc(n,sizeof(int));  //número elementos, cantidad de elementos
     */
}

void imprimeLista(int *l,int n){

    for(int i=0;i<n;i++){
        printf("%d\n",l[i]);
    }
}