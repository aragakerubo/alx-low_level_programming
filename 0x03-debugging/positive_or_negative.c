#include "main.h"

/**
 * positive_or_negative - Checks for positive, negative
 * @i: the number to be checked
 *
 * Description: Checks whether a number is positive,
 * negative or zero
 *
 * Return: void
 */
void positive_or_negative(int i)
{
	if (i < 0)
		printf("%d is negative\n", i);
	else if (i == 0)
		printf("%d is zero\n", i);
	else
		printf("%d is positive\n", i);
}
