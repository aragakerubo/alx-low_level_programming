#include <stdio.h>

long fibonacci(int n);

/**
 * main - Entry point
 *
 * Description: Entry point
 *
 * Return: 0 (success)
 */
int main(void)
{
	int i;
	long j, fib, sum = 0;

	for (i = 0; i <= 33; i++)
	{
		fib = fibonacci(i);
		j = fib % 2;
		if (j == 0)
			sum = sum + fib;
	}
	printf("%.0ld\n", sum);
	return (0);
}

/**
 * fibonacci - Computes the n-th Fibonacci number
 * @n: the integer position
 *
 * Description: Computes the n-th Fibonacci number
 *
 * Return: Returns the n-th Fibonacci number
 */
long fibonacci(int n)
{
	if (n <= 1)
		return (n);
	return (fibonacci(n - 1) + fibonacci(n - 2));
}
