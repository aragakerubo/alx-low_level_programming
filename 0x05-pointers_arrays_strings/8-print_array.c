#include <stdio.h>

/**
 * print_array - Prints n elements of an array of integers
 * @a: The array of integers
 * @s: The number of elements to be printed
 *
 * Description: Prints n elements of an array of integers
 * followed by a new line. Numbers must be separated by comma,
 * followed by a space
 *
 * Return: void
 */
void print_array(int *a, int s)
{
	int i;

	i = 0;
	while (i < s)
	{
		printf("%d", a[i]);
		if (i < (s - 1))
			printf(", ");
		i++;
	}
	printf("\n");
}
