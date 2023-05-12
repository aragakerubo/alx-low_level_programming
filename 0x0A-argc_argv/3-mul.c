#include <stdlib.h>
#include <stdio.h>

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Description: multiplies two numbers
 *
 * Return: 0 if successful, 1 if error
 */
int main(int argc, char *argv[])
{
	int i, j, k;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	i = atoi(argv[1]);
	j = atoi(argv[2]);
	k = i * j;

	printf("%d\n", k);

	return (0);
}
