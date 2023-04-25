#include <stdio.h>

/**
 * main - Entry point
 * Description: Write a program that prints the alphabet in lowercase,
 *              followed by a new line.
 * Return: 0 (success)
 */
int main(void)
{
	char n;

	for (n = 'a'; n <= 'z'; n++)
		putchar(n);
	putchar('\n');
	return (0);
}
