#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints all possible different combinations of two digits
 * Return: 0 (success)
 */
int main(void)
{
	int m, n;

	for (m = 48; m <= 57; m++)
	{
		for (n = m + 1; n <= 57; n++)
		{
			putchar((char)m);
			putchar((char)n);
			if (m == 56)
				break;
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
