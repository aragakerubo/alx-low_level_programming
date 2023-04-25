#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints the lowercase alphabet in reverse,
 * followed by a new line
 * Return: 0 (success)
 */
int main(void)
{
	char n;

	for (n = 'z'; n >= 'a'; n--)
		putchar(n);
	putchar('\n');
	return (0);
}
