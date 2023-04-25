#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints the alphabet in lowercase,
 *              excluding e and q followed by a new line.
 * Return: 0 (success)
 */
int main(void)
{
	int n;

	for (n = 48; n <= 57; n++)
		putchar((char)n);
	putchar('\n');
	return (0);
}
