#include "main.h"

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Description: prints an integer
 *
 * Return: void
 */
void print_number(int n)
{
	unsigned int number = n;

	if (n < 0)
	{
		_putchar('-');
		number = -number;
	}
	if (number / 10)
	{
		print_number(number / 10);
	}
	_putchar(number % 10 + '0');
}
