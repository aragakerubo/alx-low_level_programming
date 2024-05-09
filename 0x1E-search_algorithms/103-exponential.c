#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: the first index where value is located or -1 if value is not present
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound, i;

	if (array == NULL)
		return (-1);

	if (size == 0)
		return (-1);

	bound = 1;
	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       bound,
		       array[bound]);
		bound *= 2;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       bound / 2, bound);
	if (bound >= size)
		bound = size - 1;
	for (i = bound / 2; i <= bound; i++)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return (i);
	}
	return (-1);
}