#include <stdio.h>

/**
 * main - Entry point
 * Description: Prints all possible combinations of single-digit numbers
 * Return: 0 (success)
 */
int main(void)
{
	int n;

	n = 48;
	while (n <= 57)
	{
		putchar((char)n);
		if (n == 57)
		{
			putchar('\n');
			break;
		}
		putchar(',');
		putchar(' ');
		n++;
	}
	return (0);
}
