#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: string to encode
 *
 * Description: Letters a and A should be replaced by 4
 * Letters e and E should be replaced by 3
 * Letters o and O should be replaced by 0
 * Letters t and T should be replaced by 7
 * Letters l and L should be replaced by 1
 *
 * Return: address of s
 */
char *leet(char *s)
{
	int i, j;
	char leet[11] = "aAeEoOtTlL";
	char leet2[11] = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; leet[j] != '\0'; j++)
		{
			if (s[i] == leet[j])
				s[i] = leet2[j];
		}
	}
	return (s);
}
