#include <stdio.h>

int main(){

    //LA DECLARACION si va con *
    char *pc;

    char caracter='m';

    printf("%d\n",pc);  //es el valor de la direccion a la que apunto

    //¿Cómo hacer que un puntero apunte a una dirección?
    pc=&caracter;  //& toma la direccion de la variable que le sigue
    // pc <-  la dirección de carácter, NO EL VALOR, NO M
    //OJO CON ESTE ERROR
    //pc=caracter   estaría diciendo que pc apunte a la direccion idenficada por 
    //valor número de 'm' ERRORRRRRRRRRRRRRRRR

    char *pc2;  //OTRO PUNTERO
    pc2=pc; //porque ahora los dos contienen la misma dirección


    char otroCaracter;
    otroCaracter=*pc2;   //tomar el valor apuntado -> con *
    printf("%c\n",otroCaracter);

    return 0;
}