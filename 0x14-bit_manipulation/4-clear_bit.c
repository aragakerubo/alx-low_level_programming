#include "main.h"

/**
 * clear_bit - sets the value of a bit to 0 at a given index
 * @n: number to set bit in
 * @index: index of the bit to set
 *
 * Description: sets the value of a bit to 0 at a given index
 * where index is the index, starting from 0 of the bit you want to set
 *
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index > 63)
		return (-1);

	mask <<= index;

	if (mask & *n)
		*n ^= mask;

	return (1);
}
