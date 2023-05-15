#include <stdlib.h>
#include <stdio.h>

int count_words(char *str);
int word_len(char *str);

/**
 * word_len - counts the length of a word
 * @str: string to count
 *
 * Description: counts the length of a word
 *
 * Return: length of a word
 */
int word_len(char *str)
{
	int i, len = 0;

	for (i = 0; str[i] != '\0' && str[i] != ' '; i++)
		len++;
	return (len);
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
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}

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
	int i, j, k, l, words, len;
	char **p;

	if (str == NULL || str[0] == '\0')
		return (NULL);
	words = count_words(str);
	if (words == 0)
		return (NULL);
	p = malloc((words + 1) * sizeof(char *));
	if (p == NULL)
		return (NULL);
	for (i = 0, j = 0; i < words; i++)
	{
		while (str[j] == ' ')
			j++;
		len = word_len(str + j);
		p[i] = malloc((len + 1) * sizeof(char));
		if (p[i] == NULL)
		{
			for (k = 0; k < i; k++)
				free(p[k]);
			free(p);
			return (NULL);
		}
		for (l = 0; l < len; l++)
			p[i][l] = str[j++];
		p[i][l] = '\0';
	}
	p[i] = NULL;
	return (p);
}
