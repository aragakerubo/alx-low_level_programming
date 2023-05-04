#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Description: compares two strings
 *
 * Return: 0 if equal, -15 if s1 < s2, 15 if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0, k = 0;

	while (*(s1 + i) != '\0')
		i++;
	while (*(s2 + j) != '\0')
		j++;
	if (i < j)
		k = -15;
	else if (i > j)
		k = 15;
	else
		k = 0;
	return (k);
}
