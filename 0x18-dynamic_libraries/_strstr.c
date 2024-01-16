#include "main.h"

/**
 * _strstr - locates a substring
 * @haystack: string to search
 * @needle: substring to search for
 *
 * Return: pointer to beginning of needle in haystack or NULL if no match
 */
char *_strstr(char *haystack, char *needle)
{
	int i = 0, j = 0, k = 0;

	while (*(needle + i) != '\0')
		++i;
	if (i == 0)
		return (haystack);
	i = 0;
	while (*(haystack + j) != '\0')
	{
		if (*(haystack + j) == *(needle + i))
		{
			k = j;
			while (*(haystack + k) == *(needle + i))
			{
				if (i == (int)_strlen(needle) - 1)
					return (haystack + j);
				++k;
				++i;
			}
			i = 0;
		}
		++j;
	}
	return (NULL);
}
