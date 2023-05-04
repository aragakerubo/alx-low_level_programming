/*Write a function that concatenates two strings.*/
#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to be appended to
 * @src: string to append
 *
 * Description: appends the src string to the dest string, overwriting the
 * terminating null byte (\0) at the end of dest, and then adds a terminating
 * null byte
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	/* find the length of dest string */
	for (i = 0; dest[i] != '\0'; i++)
		;

	/* concatenate src to dest */
	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];

	/* add terminating null byte */
	dest[i + j] = '\0';

	return (dest);
}
