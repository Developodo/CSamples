#include <stdio.h>

int main()
{
    int m[3][3];
    int f, c, sumafila = 0, nfila = 0, mayorfila = 0;

    for (f = 0; f < 3; f++)
    {
        for (c = 0; c < 3; c++)
        {
            printf("Introduce el valor de [%i][%i]", f, c);
            scanf("%i", &m[f][c]);
        }
        printf("\n## Fila [%i] completada\n", f + 1);
    }

    for (f = 0; f < 3; f++)
    {
        sumafila = 0;
        
        for (c = 0; c < 3; c++)
        {
            sumafila += m[f][c];
        }
        if (sumafila > mayorfila)
        {
            mayorfila = sumafila;
            nfila = f + 1;
        }
    }

    printf("\n-----------\n");
    printf("La fila con suma mayor es: %i con resultado %i\n", nfila, mayorfila);

    return 0;
}