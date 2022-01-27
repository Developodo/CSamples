#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    const int n= 5;
    char cadena0[20]="Hola";
    char *cadena1 =" Mundo";

    char *cadenax="Hola Munda";
    char *cadenax2="Jola";

    char *dummy;
    printf("Longitud: %lu\n",strlen(cadena0));
    strcat(cadena0,cadena1);
    printf("Cadena concatenada (la primera es el destino)-> %s\n",cadena0);
    printf("Comparación de las cadenas -> %d\n",strcmp(cadena0,cadena1));
    printf("Comparación de las cadenas -> %d\n",strcmp(cadena0,cadenax));
    printf("Comparación de las cadenas -> %d\n",strcmp(cadena0,cadenax2));

    char cadenacopiada[20];
    strcpy(cadenacopiada,cadena0);
    printf("%s\n",cadenacopiada);
    //Alternativa
    int i=0;
    for(i=0;i<strlen(cadena0);i++){
        cadenacopiada[i]=cadena0[i];
    }
    cadenacopiada[i]='\0';
    //Fin alternativa


    
}