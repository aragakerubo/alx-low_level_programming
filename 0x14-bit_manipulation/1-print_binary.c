#include "main.h"

/**
 * print_binary - prints the binary representation of a number
 * @n: number to print
 *
 * Description: prints the binary representation of a number
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1;
	int i, flag = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = 63; i >= 0; --i)
	{
		if ((n >> i) & mask)
		{
			flag = 1;
			_putchar('1');
		}
		else if (flag)
		{
			_putchar('0');
		}
	}
}
