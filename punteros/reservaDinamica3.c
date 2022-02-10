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

    //1 parametro el puntero de la zona de memoria que quieres copiar
    //2 parametro, el nuevo tamaño
    //devuelve el puntero a la nueva zona de memoria
    v=realloc(v,(l+1)*sizeof(int));   //ahora tiene 4
    v[l]=900;  //pongo el último 900
    for(int i=0;i<=l;i++){
       printf("%d\n",v[i]);
    }

    free(v);

    return 0;
}