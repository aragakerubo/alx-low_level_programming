#include "main.h"

/**
 * _strcpy - copies the string
 * @dest: destination
 * @src: source
 *
 * Destination: Copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest.
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = src[i];
	return (dest);
}
