#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimeMatriz(int m[3][3]);
void rellenaDiagonal(int m[3][3],int numero);


int main(int argc, char *argv[]){
    

    if(argc!=3){
        printf("Error al ejecutar el programa, su uso es: ./a.out -n numero_a_rellenar\n");
        return -1;
    }
    if(strcmp(argv[1],"-n")!=0){
        printf("Error al ejecutar el programa, su uso es: ./a.out -n numero_a_rellenar\n");
        return -1;
    }

    int numero = atoi(argv[2]);
   
    int matriz[3][3]={{0,0,0},   //matriz[1]
                      {0,0,0},
                      {0,0,0}};

   imprimeMatriz(matriz);
   rellenaDiagonal(matriz,numero);
   imprimeMatriz(matriz);

   printf("\n-------------------\n");
   printf("%d\n",argc);
   for(int i=0;i<argc;i++){
       printf("%s\n",argv[i]);
   }
    
}

void imprimeMatriz(int m[3][3]){
     for(int i=0;i<3;i++){  //3 veces
        for(int j=0;j<3;j++){  //i=0 -> 3 veces... i=2 entra 3 veces
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}
void rellenaDiagonal(int m[3][3],int numero){
    for(int i=0;i<3;i++){  //3 veces
        for(int j=0;j<3;j++){  //i=0 -> 3 veces... i=2 entra 3 veces
            if(i==j){
                m[i][j]=numero;
            }
        }
    }
}


/*
int comprueba3enraya(int m[3][3]){  

}*/