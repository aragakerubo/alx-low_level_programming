#include "main.h"

/**
 * print_diagonal - Drawsa diagonal line on terminal
 * @n: number of times the character \ should be printed
 *
 * Description: Draws a diagonal line on the terminal
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= i; j++)
			{
				if (j != i)
					_putchar(' ');
				else
					_putchar('\\');
			}
			_putchar('\n');
		}
	}
}
