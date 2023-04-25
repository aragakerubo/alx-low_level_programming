#include <stdio.h>

/**
 * main - Entry point
 * Description: Write a program that prints the alphabet in lowercase,
 *              excluding e and q followed by a new line.
 * Return: 0 (success)
 */
int main(void)
{
	char n;

	for (n = 'a'; n <= 'z'; n++)
		if (n != 'e' && n != 'q')
			putchar(n);
	putchar('\n');
	return (0);
}
