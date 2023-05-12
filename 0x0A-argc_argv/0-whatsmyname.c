#include <stdio.h>

/**
 * main - prints its name, followed by a new line
 * @argc: number of arguments
 * @argv: array of pointers to the strings (arguments)
 *
 * Description: prints its name, followed by a new line
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	(void)argc;
	printf("%s\n", argv[0]);
	return (0);
}
