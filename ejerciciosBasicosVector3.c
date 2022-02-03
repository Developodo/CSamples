#include <stdio.h>

#define TAM 5
typedef enum{
    A = 'a',
    E = 'e',
    I = 'i',
    O = 'o',
    U = 'u'
} VOCALES;

int esVocal(char c);

int main(){
  
    char vector[TAM]={'a','b','c','d','e'};
    int nVocales=0;
    for(int i=0;i<TAM;i++){
        if(esVocal(vector[i])==1){
                nVocales++;
        }
    }
    printf("Número de volcales %d\n",nVocales);
    char newVector[TAM+nVocales];

    for(int i=0,j=0;i<TAM;i++,j++){
        newVector[j]=vector[i];
        if(esVocal(vector[i])==1){
            //j++;
            newVector[++j]=vector[i];
        }
        
    }

    for(int i=0;i<TAM+nVocales;i++){
        printf("%c ",newVector[i]);
    }
    printf("\n");
}


int esVocal(char c){
    int result=0;
    if(c==A || c==E || 
            c==I || c==O || c==U){
                result=1;
    }
    return result;
}