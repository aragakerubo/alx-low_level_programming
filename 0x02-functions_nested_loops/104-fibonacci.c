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
	int i;
	unsigned long int j = 0, k = 1, fib;
	unsigned long int j1, k1, j2, k2;
	unsigned long int part1, part2;

	for (i = 0; i < 92; i++)
	{
		fib = j + k;
		j = k;
		k = fib;
		printf("%lu, ", fib);
	}
	j1 = j / 10000000000;
	j2 = j % 10000000000;
	k1 = k / 10000000000;
	k2 = k % 10000000000;
	for (i = 93; i < 99; i++)
	{
		part1 = j1 + k1;
		part2 = j2 + k2;
		if (part2 > 9999999999)
		{
			part1 += 1;
			part2 %= 10000000000;
		}
		printf("%lu%lu", part1, part2);
		if (i < 98)
			printf(", ");
		j1 = k1;
		j2 = k2;
		k1 = part1;
		k2 = part2;
	}
	printf("\n");
	return (0);
}
