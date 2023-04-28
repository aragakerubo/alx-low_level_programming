#include "main.h"

/**
 * print_triangle - Prints a triangle, followed by a new line
 * @size: the size of the triangle
 *
 * Description: Prints a triangle, followed by a new line
 *
 * Return: void
 */
void print_triangle(int size)
{
	int i, j, k;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		for (j = size - i; j > 0; j--)
			_putchar(' ');

		for (k = 1; k <= i; k++)
			_putchar('#');

		_putchar('\n');
	}
}
