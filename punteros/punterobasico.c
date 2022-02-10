#include <stdio.h>

int main(){

    int *p;
    int n=5;

    p=&n;  //apuntar al entero

    n++;   //incremento directo
    (*p)++;   //incremento indirecto por medio del puntero

    printf("%d\n",n);   //es lo mismo esta
    printf("%d\n",*p);   //que esta 

    printf("%d\n",p);
    p++;
    printf("%d\n",p);
    printf("%d\n",*p);   //ahora ya no es lo mismo
    p--;
    printf("%d\n",*p);   //ahora ya no es lo mismo
    return 0;
}