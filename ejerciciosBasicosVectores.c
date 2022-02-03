#include <stdio.h>
#define TAM 10

int main(){
    
    float notas[TAM];
    for(int i=0;i<TAM;i++){
        printf("Nota del alumnos %d: ",i);
        scanf("%f",&notas[i]);
        fflush(stdin);
    }

    float media=0;
    float naprobados=0;
    float nsuspensos=0;
    for(int i=0;i<TAM;i++){
        media+=notas[i];
        if(notas[i]>=5) naprobados++;
        else nsuspensos++;
    }
    printf("Nota media %.2f, con %.2f% aprobados y %.2f% suspensos",media/TAM,(naprobados/TAM)*100,(nsuspensos/TAM)*100);
}