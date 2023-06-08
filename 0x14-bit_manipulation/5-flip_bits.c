#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip to get from
 * one number to another
 * @n: first number
 * @m: second number
 *
 * Description: returns the number of bits you would need to flip to get from
 * one number to another
 *
 * Return: number of bits you would need to flip to get from one number to
 * another
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int mask = 1;
	unsigned int count = 0;
	int i;

	for (i = 63; i >= 0; --i)
	{
		if (((n >> i) & mask) != ((m >> i) & mask))
			++count;
	}

	return (count);
}
