#include <stdio.h>
#include "main.h"

/**
 * _isupper - check if character is uppercase
 * @c: character to be checked
 *
 * Description: Checks for uppercase character
 *
 * Return: Returns 1 if c is uppercase and 0 otherwise
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
