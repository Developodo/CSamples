#include <stdio.h>

void incrementa1(int a);
void incrementa2(int *a);
int incrementa3(int a);

int main(){

    int n=5;
    printf("%d\n",n);
    incrementa1(n);
    printf("%d\n",n);
    incrementa2(&n);
    printf("%d\n",n);
    n=incrementa3(n);

    return 0;
}
//Paso por valor <- no se modifica
void incrementa1(int a){
    a++;
}
//Paso por referencia <-si se modifica
void incrementa2(int *a){
    (*a)++;
}
int incrementa3(int a){
    a++;
    return a;
}