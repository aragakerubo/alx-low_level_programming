#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints all possible different combinations of three digits
 * Return: 0 (success)
 */
int main(void)
{
	int m, n, p;

	for (m = 48; m <= 57; m++)
	{
		for (n = m + 1; n <= 57; n++)
		{
			for (p = n + 1; p <= 57; p++)
			{
				putchar((char)m);
				putchar((char)n);
				putchar((char)p);
				if (m == 55)
					break;
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}
