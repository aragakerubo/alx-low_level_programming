#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * main - generates keygen for crackme5
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	char *username;
	char *key;
	int i, len, sum;

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		return (1);
	}
	username = argv[1];
	len = strlen(username);
	key = malloc(len + 1);
	if (key == NULL)
		return (1);
	for (i = 0, sum = 0; i < len; i++)
		sum += username[i];
	key[i] = '\0';
	printf("%s\n", key);
	return (0);
}
