#include "main.h"

/**
 * times_table - Prints the 9 times table, starting with 0
 *
 * Description: Prints the 9 times table, starting with 0
 *
 * Return: void
 */
void times_table(void)
{
	int i, j, product;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			product = i * j;
			if (product > 9)
			{
				_putchar('0' + (product / 10));
				_putchar('0' + (product % 10));
			}
			else
			{
				_putchar(' ');
				_putchar('0' + product);
			}
			if (j == 9)
			{
				_putchar('\n');
			}
			else
			{
				_putchar(',');
				_putchar(' ');
			}
		}
	}
}
