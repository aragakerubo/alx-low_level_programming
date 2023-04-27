#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Description: Prints the first 98 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line
 *
 * Return: 0 (success)
 */
int main(void)
{
	int limit = 96;

	long double i, j, k, fib;

	j = 1;
	k = 2;
	printf("%.0Lf, %.0Lf, ", j, k);
	for (i = 1; i <= limit; i++)
	{
		fib = j + k;
		j = k;
		k = fib;
		if (i == limit)
			printf("%.0Lf\n", fib);
		else
			printf("%.0Lf, ", fib);
	}

	return (0);
}
