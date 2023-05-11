#include "main.h"

int find_prime(int n, int i);

/**
 * is_prime_number - checks if a number is prime
 * @n: number to check
 *
 * Description: checks if a number is prime
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (find_prime(n, 2));
}

/**
 * find_prime - finds if a number is prime
 * @n: number to check
 * @i: iterator
 *
 * Description: finds if a number is prime
 *
 * Return: 1 if prime, 0 otherwise
 */
int find_prime(int n, int i)
{
	if (n == i)
		return (1);

	if (n % i == 0)
		return (0);

	return (find_prime(n, i + 1));
}
