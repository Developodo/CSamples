#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int **multiplicaMatriz(int** m1,int f1,int c1,int** m2,int f2,int c2){
    int **resultado=NULL;
    if(c1==f2){
        printf("Matrices compatibles\n");
        //https://www.varsitytutors.com/hotmath/hotmath_help/spanish/topics/matrix-multiplication#:~:text=Usted%20solo%20puede%20multiplicar%20dos,una%20matriz%20a%20%C3%97%20c%20.
        resultado=creaMatriz(f1,c2);
        printf("Procedemos a multiplicar\n");
        for(int i=0;i<f1;i++){
            for(int j=0;j<c2;j++){
                //elemento i,j resultado
                int tmp=0;
                for(int k=0;k<c1;k++){
                    tmp+=m1[i][k]*m2[k][j];
                }
                resultado[i][j]=tmp;
            }
        }
    }
    return resultado;
}
void imprimeMatriz(int** m,int f,int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            if(m[i][j]>=0)
                printf(" %d ",m[i][j]);
            else   
                printf("%d ",m[i][j]);  //para no tabular el signo -
        }
        printf("\n");
    }
}