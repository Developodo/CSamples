#include <stdio.h>
#include <stdlib.h>

int main(){

    int *v;
    int l;

    printf("Indique la longitud del vector: ");
    scanf("%d",&l);

    //tamaño de bytes que quieres reservar
    v=(int *)malloc(l*sizeof(int));  //v apunta a la direccion incial de la zona reservada

    //Inicializar el vector <-0
    for(int i=0;i<l;i++){
        v[i]=0;
    }

    for(int i=0;i<l;i++){
       printf("%d\n",v[i]);
    }
    for(int i=0;i<l;i++){  //otra forma de recorrer el vector
        printf("%d\n",*(v+i));
    }

    free(v);

    return 0;
}

