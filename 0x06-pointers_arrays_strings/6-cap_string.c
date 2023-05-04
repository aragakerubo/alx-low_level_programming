#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @s: string to capitalize
 *
 * Description: capitalizes all words of a string
 *
 * Return: pointer to string
 */
char *cap_string(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (i == 0)
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
		}
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == ','
		    || s[i] == ';' || s[i] == '.' || s[i] == '!' || s[i] == '?'
		    || s[i] == '"' || s[i] == '(' || s[i] == ')' || s[i] == '{'
		    || s[i] == '}')
		{
			i++;
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
			continue;
		}
		i++;
	}
	return (s);
}
