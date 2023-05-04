#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: string to be appended to
 * @src: string to append
 * @n: number of bytes to append
 *
 * Description: appends src to dest using at most n bytes
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int p, q;

	/* find the end of dest */
	for (p = 0; dest[p] != '\0'; p++)
		;

	/* copy src to the end of dest */
	for (q = 0; src[q] != '\0' && q < n; q++)
		dest[p + q] = src[q];

	return (dest);
}
