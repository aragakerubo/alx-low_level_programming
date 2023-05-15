#include <stdlib.h>
#include <stdio.h>

int count_words(char *str);

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Description: splits a string into words
 *
 * Return: pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	int i, j, k, l, m, count = 0, count2 = 0;
	char **p;

	if (str == NULL)
		return (NULL);
	count = count_words(str);
	p = malloc(sizeof(char *) * (count + 1));
	if (p == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ')
		{
			for (j = i; str[j] != ' '; j++)
				;
			p[count2] = malloc(sizeof(char) * (j - i + 1));
			if (p[count2] == NULL)
			{
				for (k = 0; k < count2; k++)
					free(p[k]);
				free(p);
				return (NULL);
			}
			for (l = i, m = 0; l < j; l++, m++)
				p[count2][m] = str[l];
			p[count2][m] = '\0';
			count2++;
			i = j;
		}
	}
	p[count2] = NULL;
	return (p);
}

/**
 * count_words - counts the number of words in a string
 * @str: string to count
 *
 * Description: counts the number of words in a string
 *
 * Return: number of words in a string
 */
int count_words(char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i + 1] == ' ')
			count++;
	}
	return (count);
}
