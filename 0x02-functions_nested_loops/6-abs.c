#include "main.h"

/**
 * _abs - Computes the absolute value of an integer
 * @i: the number to be computed
 *
 * Description: Computes the absolute value of an integer
 *
 * Return: Returns the absolute value of an integer
 */
int _abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
