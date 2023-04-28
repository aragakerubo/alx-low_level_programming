#include <stdio.h>

/**
 * main - Finds and prints the largest prime factor
 *
 * Description: Finds and prints the largest prime factor
 * of the number 612852475143, followed by a new line.
 *
 * Return: 0 (success)
 */
int main(void)
{
	long int n = 612852475143;
	long int i = 2;

	while (i < n)
	{
		if (n % i == 0)
		{
			n = n / i;
		}
		else
		{
			i++;
		}
	}
	printf("%ld\n", n);
	return (0);
}
