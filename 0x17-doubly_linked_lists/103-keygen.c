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
	char password[7], *codex;
	int len = strlen(argv[1]), i, tmp;

	if (argc != 2)
		return (1);
	strcpy(password, argv[1]);
	codex = strdup("A-CHRDw87lNS0E9B2T6Y4GzXsQV1g5W3FJZqKpUjLcMnOoIybtvfxePmkuariCdh");
	for (i = 0; i < len; i++)
	{
		tmp = password[i];
		password[i] = codex[(tmp ^ 0x3b) & 0x3f];
	}
	password[i] = codex[(password[0] ^ 0x4f) & 0x3f];
	printf("%s\n", password);
	return (0);
}
