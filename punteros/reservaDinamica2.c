#include <stdio.h>
#include <stdlib.h>

int main(){

    int *v;
    int l;

    printf("Indique la longitud del vector: ");
    scanf("%d",&l);

    //tamaño de bytes que quieres reservar
    v=(int *)calloc(l,sizeof(int));  //v apunta a la direccion incial de la zona reservada

    for(int i=0;i<l;i++){
       printf("%d\n",v[i]);
    }

    free(v);

    return 0;
}