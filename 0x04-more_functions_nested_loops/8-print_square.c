#include "main.h"

/**
 * print_square - Prints a square, followed by a new line
 * @size: the size of the square
 *
 * Description: Prints a square, followed by a new line
 *
 * Return: void
 */
void print_square(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= size; j++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
