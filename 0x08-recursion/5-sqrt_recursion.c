#include "main.h"

int find_sqrt(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find the square root of
 *
 * Description: returns the natural square root of a number
 *
 * Return: the square root of n,
 * or -1 if n does not have a natural square root
 */
int _sqrt_recursion(int n)
{
	int i = 1;

	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);

	return (find_sqrt(n, i));
}

/**
 * find_sqrt - finds the square root of n
 * @n: number to find the square root of
 * @i: iterator
 *
 * Description: finds the square root of n
 *
 * Return: the square root of n,
 * or -1 if n does not have a natural square root
 */
int find_sqrt(int n, int i)
{
	if (n == (i * i))
		return (i);
	if (n < (i * i))
		return (-1);

	return (find_sqrt(n, i + 1));
}
