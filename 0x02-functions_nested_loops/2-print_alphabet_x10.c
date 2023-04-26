#include "main.h"

/**
 * print_alphabet_x10 - Main function
 *
 * Description: Prints the alphabet 10 times,
 * in lowercase, followed by a new line
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	int i;
	char p;

	for (i = 0; i < 10; i++)
	{
		for (p = 'a'; p <= 'z'; p++)
			_putchar(p);
		_putchar('\n');
	}
}
