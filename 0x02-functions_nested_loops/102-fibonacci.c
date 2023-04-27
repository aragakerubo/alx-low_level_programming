#include <stdio.h>

/**
 * main - Prints the first 50 Fibonacci numbers
 *
 * Description: Prints the first 50 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 *
 * Return: void
 */
void main(void)
{
	unsigned long long int i, j, k, fibonacci;

	fibonacci = 0;
	j = 1;
	k = 2;
	for (i = 1; i <= 48; i++)
	{
		if (i == 1)
		{
			printf("%llu, %llu, ", j, k);
			continue;
		}
		fibonacci = j + k;
		j = k;
		k = fibonacci;
		
		if (i != 48)
			printf("%llu, ", fibonacci);
		else
			printf("%llu\n", fibonacci);
	}
}
