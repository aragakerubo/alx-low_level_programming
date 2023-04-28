#include "main.h"

/**
 * _isdigit - Checks for a digit (0 to 9)
 * @c: character to be checked
 *
 * Description: Checks if c is a digit (0 through 9)
 *
 * Return: Returns 1 if c is a digit and 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
