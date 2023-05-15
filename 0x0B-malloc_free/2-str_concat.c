#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Description: concatenates two strings
 *
 * Return: pointer to new string, NULL if fails
 */
char *str_concat(char *s1, char *s2)
{
	char *s3;
	int i, j, k, l;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	i = 0;
	while (*(s1 + i))
		i++;
	j = 0;
	while (*(s2 + j))
		j++;
	s3 = malloc(sizeof(char) * (i + j + 1));
	if (s3 == NULL)
		return (NULL);
	k = 0;
	while (k < i)
	{
		*(s3 + k) = *(s1 + k);
		k++;
	}
	l = 0;
	while (l < j)
	{
		*(s3 + k) = *(s2 + l);
		k++;
		l++;
	}
	*(s3 + k) = '\0';
	return (s3);
}
