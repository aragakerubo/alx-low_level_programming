#include "main.h"

/**
 * print_last_digit - Prints the last digit of a number
 * @i: the number to be checked
 *
 * Description: Prints the last digit of a number
 *
 * Return: Returns the last digit of the number i
 */
int print_last_digit(int i)
{
	int abs = i % 10;

	if (abs < 0)
		abs = -abs;
	_putchar(abs + '0');
	return (abs);
}
