#include <stdio.h>

void incrementa(int v[3]);   //int *v

int main(){
    int vector[3]={1,2,3};
    incrementa(vector);     //
    for(int i=0;i<3;i++){
        printf("%d\n",vector[i]);   
    }

    return 0;
}

void incrementa(int v[3]){   //las modificaciones de los vectores y matrices son persistentes
    for(int i=0;i<3;i++){
        v[i]++;    //(*(v+i))++
    }
}