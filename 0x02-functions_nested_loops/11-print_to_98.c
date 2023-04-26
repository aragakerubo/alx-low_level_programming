#include <stdio.h>

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: the starting integer
 *
 * Description: Prints all natural numbers from n to 98,
 * followed by a new line
 *
 * Return: void
 */
void print_to_98(int n)
{
	while (n != 98)
	{
		printf("%d", n);
		if (n > 98)
		{
			printf(" ,");
			n--;
		}
		else if (n < 98)
		{
			printf(" ,");
			n++;
		}
	}
	printf("%d\n", 98);
}
