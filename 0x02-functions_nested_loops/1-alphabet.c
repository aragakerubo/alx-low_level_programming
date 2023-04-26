#include "main.h"

/**
 * print_alphabet - Main function
 * Description: Prints the alphabet, in lowercase, followed by a new line
 * Return: void
 */
void print_alphabet(void)
{
	char n;

	for (n = 'a'; n <= 'z'; n++)
		_putchar(n);
	_putchar('\n');
}
