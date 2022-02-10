#include <stdio.h>
#include <stdlib.h>
int main()
{

	int fila, col;
	printf("****PIRÁMIDE CON ASTERISCO****\n");

	/***
	** Primero pedimos al usuario/a el valor de filas y columnas
	** condicionando que sea siempre el mismo para obtener
	** matrices cuadradas
	*/

	do
	{
		printf("Debes introducir el valor de filas y columnas y ambos deben ser iguales\n");
		printf("Introduce el tamaño de la fila: ");
		scanf("%d", &fila);
		printf("Introduce el tamaño de la columna: ");
		scanf("%d", &col);
	} while (fila != col && fila % 2 != 0 && fila > 1);

	char piramide[fila][col];
	int base = col;
	int altura = 3;
	if (fila > 3)
	{
		altura = fila / 2 + 1;
	}

	// recorro todas las filas de arriba a abajo
	int nivel=0;
	for (int i = 0; i < fila; i++)
	{
		if (i < fila - altura)
		{
			// rellenar el hueco superior antes del comienzo de la pirámide
			for (int j = 0; j < col ; j++)
			{
				piramide[i][j] = 'N';
				printf("%c ", 'N');
			}
			printf("\n");
		}else{
			//rellenar pirámide
			//calculo número de espacios
			int nEspacios=col/2-nivel;   //1
			//calculo número de asteriscos
			int nAsteriscos=2*nivel+1;   //3

			for (int j = 0; j < nEspacios ; j++)
			{
				//piramide[i][j] = 'N';
				printf("%c ", 'N');
			}
			for (int j = 0; j < nAsteriscos ; j++)
			{
				//piramide[i][j] = 'N';
				printf("%c ", '*');
			}
			for (int j = 0; j < nEspacios ; j++)
			{
				//piramide[i][j] = 'N';
				printf("%c ", 'N');
			}
			printf("\n");
			nivel++;
		}
	}
}
