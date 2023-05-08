#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: pointer to array of 8 characters
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int i, j;
	char *p;

	i = 0;
	j = 0;
	p = (char *)a;

	while (i < 64)
	{
		if (j == 8)
		{
			j = 0;
			printf("\n");
		}
		printf("%c", *(p + i));
		i++;
		j++;
	}
	printf("\n");
}
