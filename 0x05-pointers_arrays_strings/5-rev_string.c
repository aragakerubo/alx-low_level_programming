#include "main.h"

/**
 * rev_string - Reverses a string
 * @s: String to be reversed
 *
 * Description: Reverses a string
 *
 * Return: void
 */
void rev_string(char *s)
{
	int i, j;
	char temp;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	i--;
	while (i > j)
	{
		temp = s[i];
		s[i--] = s[j];
		s[j++] = temp;
	}
}
