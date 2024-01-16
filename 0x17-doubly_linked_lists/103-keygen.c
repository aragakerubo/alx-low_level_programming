#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * main - generates passwords for crackme5 executable
 * @argc: number of arguments
 * @argv: array of pointers to arguments
 *
 * Return: always 0
 */
int main(int argc, char *argv[])
{
	char *password;
	int len, i, sum, prod, last;

	if (argc != 2)
	{
		printf("Usage: %s username\n", argv[0]);
		exit(1);
	}
	len = strlen(argv[1]);
	password = malloc(len + 1);
	if (password == NULL)
	{
		printf("Malloc failed\n");
		exit(1);
	}
	for (i = 0, sum = 0, prod = 1; i < len; i++)
	{
		sum += argv[1][i];
		prod *= argv[1][i];
	}
	last = argv[1][len - 1];
	password[0] = last;
	password[1] = sum & 0x3f;
	password[2] = (sum ^ 0x4f) & 0x3f;
	password[3] = prod & 0x3f;
	password[4] = (prod ^ 0xef) & 0x3f;
	password[5] = '\0';
	for (i = 0; i < len; i++)
		password[i] = (password[i] & 0x3f) + 0x3f;
	printf("%s\n", password);
	free(password);
	return (0);
}
