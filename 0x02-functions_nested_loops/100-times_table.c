#include <stdio.h>

/**
 * print_times_table - Prints the n times table, starting with 0
 * @n: the integer
 *
 * Description: Prints the n times table, starting with 0
 *
 * Return: void
 */
void print_times_table(int n)
{
	int i, j, product;

	if (n < 0 || n > 15)
		return;
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			product = i * j;

			if (j == n && j != 0)
			{
				printf("%3d\n", product);
			}
			else if (j == 0 && j < n)
			{
				printf("%d, ", product);
			}
			else if (j == n && j == 0)
			{
				printf("%d\n", product);
			}
			else
			{
				printf("%3d, ", product);
			}
		}
	}
}
