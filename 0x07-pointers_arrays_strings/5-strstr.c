#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: substring to search for
 *
 * Description: finds the first occurrence of the
 * substring needle in the string haystack
 *
 * Return: pointer to beginning of substring or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j, match;

	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		match = 1;
		while (needle[j] != '\0')
		{
			if (haystack[i + j] != needle[j])
			{
				match = 0;
				break;
			}
			j++;
		}
		if (match)
			return (haystack + i);
		i++;
	}
	return (0);
}
