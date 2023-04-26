#include "main.h"

/**
 * _islower - Checks for lowercase character
 * @c: the ASCII character to be checked
 *
 * Description: Checks for lowercase character
 *
 * Return: Returns 1 if the character is lowercase,
 * returns 0 if the character is uppercase
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
