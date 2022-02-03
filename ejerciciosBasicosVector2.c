#include <stdio.h>
#define TAM 10

int main(){
    int vector[TAM]={2,3,5,8,7,4,6,1,5,8};
    int vectorInv[TAM];
    int nP=0;
    int nI=0;
    for(int i=TAM-1,j=0;i>=0;i--,j++){
        vectorInv[j]=vector[i];
        if(vector[i]%2==0) nP++;
        else nI++;
    }
    
    int vectorP[nP];
    int vectorI[nI];

    for(int i=0,j=0,k=0;i<TAM;i++){
        if(vector[i]%2==0){
            vectorP[j]=vector[i];
            j++;
        }else{
            vectorI[k++]=vector[i];
        }
    }
    printf("El vector original es...\n");
    for(int i=0;i<TAM;i++){
        printf("%d ",vector[i]);
    }
    printf("El vector inveritdo es...\n");
    for(int i=0;i<TAM;i++){
        printf("%d ",vectorInv[i]);
    }
    printf("\nEl vector PAR es...\n");
    for(int i=0;i<nP;i++){
        printf("%d ",vectorP[i]);
    }
    printf("\nEl vector IMPAR es...\n");
    for(int i=0;i<nI;i++){
        printf("%d ",vectorI[i]);
    }
    printf("\n");
}