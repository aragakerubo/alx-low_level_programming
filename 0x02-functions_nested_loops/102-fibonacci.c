#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers
 *
 * Description: Prints the first 50 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 *
 * Return: 0 (success)
 */
int main(void)
{
	double i, j, k, fibonacci;

	fibonacci = 0;
	j = 1;
	k = 2;
	for (i = 0; i <= 48; i++)
	{
		if (i == 0)
		{
			printf("%.0f, %.0f, ", j, k);
			continue;
		}
		fibonacci = j + k;
		j = k;
		k = fibonacci;

		if (i != 48)
			printf("%.0f, ", fibonacci);
		else
			printf("%.0f\n", fibonacci);
	}
	return (0);
}
