#include <stdio.h>
#include <stdlib.h>

int** creaMatriz(int f,int c);
void rellenaMatriz(int** m,int f,int c);
int **multiplicaMatriz(int** m1,int f1,int c1,int** m2,int f2,int c2);
void imprimeMatriz(int** m,int f,int c);

int main(){
    int f1,f2,c1,c2;
    int **m1,**m2,**resultado;
    printf("Creando matriz 1\n");
    do{
        printf("Inserte número de filas: ");
        scanf("%d",&f1);
    }while(f1<=0);

    do{
        printf("Inserte número de columnas: ");
        scanf("%d",&c1);
    }while(c1<=0);
    m1=creaMatriz(f1,c1);
    
    printf("Creando matriz 2\n");
    do{
        printf("Inserte número de filas: ");
        scanf("%d",&f2);
    }while(f2<=0);

    do{
        printf("Inserte número de columnas: ");
        scanf("%d",&c2);
    }while(c2<=0);
    m2=creaMatriz(f2,c2);

    printf("Rellenando matriz 1\n");
    rellenaMatriz(m1,f1,c1);
    printf("Rellenando matriz 2\n");
    rellenaMatriz(m2,f2,c2);

    resultado=multiplicaMatriz(m1,f1,c1,m2,f2,c2);
    if(resultado!=NULL){
        imprimeMatriz(resultado,f1,c2);
    }else{
        printf("Error en las dimensiones de las matrices");
    }
    return 0;
}

int** creaMatriz(int f,int c){
    int **m=NULL;
    if(f>0 && c>0){
        m=(int **)calloc(f,sizeof(int*));
        for(int i=0;i<f;i++){
            m[i]=(int *)calloc(c,sizeof(int));
        }
    }
    return m;
}
void rellenaMatriz(int** m,int f,int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            printf("Valor de la celda %d,%d: ",(i+1),(j+1));
            scanf("%d",&m[i][j]);
        }
    }
}
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