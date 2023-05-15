#include <stdio.h>
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * @str: string to be duplicated
 *
 * Description: returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * Return: pointer to duplicated string
 */
char *_strdup(char *str)
{
	char *dup;
	int i = 0, j;

	if (str == NULL)
		return (NULL);

	while (str[i])
		i++;

	dup = malloc(sizeof(char) * i + 1);

	if (dup == NULL)
		return (NULL);

	for (j = 0; j < i; j++)
		dup[j] = str[j];

	dup[j] = '\0';

	return (dup);
}
