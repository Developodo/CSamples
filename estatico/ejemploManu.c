//ejercicio que introduce un elemento
//en una pos determinada en un array

#include <stdio.h>

int main()
{

    int i, arr[50], pos, len;
    int newitem;

    printf("De cuantos elementos es el array\n");
    scanf("%d", &len);

    printf("Introduce los elementos del mismo: \n");
    for (i = 0; i < len; i++){
        scanf("%d", &arr[i]);
    }
    //i=len
    printf("Introduce un nuevo elemento\n");
    scanf("%d", &newitem);

    printf("En que posición quieres introducirlo\n");
    scanf("%d", &pos);

    len++;
    pos--;
    printf("Cuanto vale i-> %d",i);
    while (i >= pos)
    {
        //array[i+1]=array[i]  <<<----- i=len-1
        arr[i] = arr[i - 1];
        i--;
    }
    arr[pos] = newitem;

    for (i = 0; i < len; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}