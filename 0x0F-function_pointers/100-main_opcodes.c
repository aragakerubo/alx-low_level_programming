#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the opcodes of its own main function
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Description: prints the opcodes of its own main function
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int i, bytes;
	char *main_addr;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	main_addr = (char *)main;

	for (i = 0; i < bytes; i++)
	{
		printf("%02hhx", main_addr[i]);
		if (i < bytes - 1)
			printf(" ");
		else
			printf("\n");
	}

	return (0);
}
