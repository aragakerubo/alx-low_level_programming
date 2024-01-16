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
	codex = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	tmp = (len ^ 59) & 63;
	password[0] = codex[tmp];

	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += argv[1][i];
	password[1] = codex[(tmp ^ 79) & 63];

	tmp = 1;
	for (i = 0; i < len; i++)
		tmp *= argv[1][i];
	password[2] = codex[(tmp ^ 85) & 63];

	tmp = 0;
	for (i = 0; i < len; i++)
	{
		if (argv[1][i] > tmp)
			tmp = argv[1][i];
	}
	srand(tmp ^ 14);
	password[3] = codex[rand() & 63];

	tmp = 0;
	for (i = 0; i < len; i++)
		tmp += (argv[1][i] * argv[1][i]);
	password[4] = codex[(tmp ^ 239) & 63];

	for (i = 0; i < argv[1][0]; i++)
		tmp = rand();
	password[5] = codex[(tmp ^ 229) & 63];
	password[6] = '\0';
	printf("%s", password);
	return (0);
}
