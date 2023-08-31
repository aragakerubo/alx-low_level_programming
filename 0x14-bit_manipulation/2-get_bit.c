#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number to get bit from
 * @index: index of the bit to get
 *
 * Description: returns the value of a bit at a given index
 * where index is the index, starting from 0 of the bit you want to get
 *
 * Return: value of the bit at index or -1 if an error occured
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1;

	if (index > 63)
		return (-1);

	mask <<= index;

	if (mask & n)
		return (1);

	return (0);
}
