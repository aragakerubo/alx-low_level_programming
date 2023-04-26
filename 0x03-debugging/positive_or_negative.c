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
	printf("%d", i);
	if (i < 0)
		printf(" is negative");
	else if (i == 0)
		printf(" is zero");
	else
		printf(" is positive");
	printf("\n");
}
