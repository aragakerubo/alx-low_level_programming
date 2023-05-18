#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes of s2 to concatenate
 *
 * Description: concatenates two strings
 *
 * Return: pointer to new string, NULL if it fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *p;
	unsigned int i, j, k, l;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] != '\0'; i++)
		;
	for (j = 0; s2[j] != '\0'; j++)
		;

	if (n >= j)
		n = j;

	p = malloc(sizeof(char) * (i + n + 1));

	if (p == NULL)
		return (NULL);

	for (k = 0; k < i; k++)
		p[k] = s1[k];
	for (l = 0; l < n; l++)
		p[k + l] = s2[l];
	p[k + l] = '\0';

	return (p);
}
