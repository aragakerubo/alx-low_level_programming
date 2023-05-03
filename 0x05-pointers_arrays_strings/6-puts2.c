#include "main.h"

/**
 * puts2 - Prints every other character of a string
 * @str: The string to print
 *
 * Description: Prints every other character of a string
 * starting with the first character, followed by a new line.
 *
 * Return: void
 */
void puts2(char *str)
{
	int i = 0;

	while (*(str + i))
	{
		if (str[i] == '\0')
			break;
		_putchar(*(str + i));
		i += 2;
	}
	_putchar('\n');
}
