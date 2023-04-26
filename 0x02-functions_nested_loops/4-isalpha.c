#include "main.h"

/**
 * _isalpha - Checks for alphabetic character
 * @c: the ASCII character to be checked
 *
 * Description: Checks for alphabetic character
 *
 * Return: Returns 1 if the character is a letter,
 * returns 0 otherwise
 */
int _isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}
