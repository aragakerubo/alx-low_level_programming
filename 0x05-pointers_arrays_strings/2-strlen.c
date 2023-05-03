#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string to get the length of
 *
 * Description: Returns the length of a string
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*(s + i))
		i++;

	return (i);
}
