#include <stdio.h>

int cuentaPalabras(char m[256]);

int main(){
    char mensaje[256]=" Hola Mundo     Como estás to doo pasa    ";
    printf("Número de palabras %d\n",cuentaPalabras(mensaje));
}

int cuentaPalabras(char m[256]){
    char c='x';
    int nPalabras=0;
    int i=0;
    while(c!='\0'&&i<256){
        //B
        if(m[i]!=' '){
            nPalabras++;
             while(m[i]!=' '&&c!='\0'&&i<256){
                i++;
            }
        }
        //A
        while(m[i]==' '&&c!='\0'&&i<256){
            i++;
        }
        c=m[i];
    }
    return nPalabras;
}