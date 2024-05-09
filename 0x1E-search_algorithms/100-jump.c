#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers using the
 * Jump search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: the first index where value is located or -1 if value is not present
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, jump, prev;

	if (array == NULL)
		return (-1);

	jump = sqrt(size);
	for (i = 0; i < size; i += jump)
	{
		if (array[i] >= value)
			break;
		printf("Value checked array[%lu] = [%d]", i, array[i]);
	}
	prev = i - jump;
	printf("Value found between indexes [%lu] and [%lu]", prev, i);
	printf("Value checked array[%lu] = [%d]", prev, array[prev]);
	for (; prev <= i && prev < size; prev++)
	{
		printf("Value checked array[%lu] = [%d]", prev, array[prev]);
		if (array[prev] == value)
			return (prev);
	}
	return (-1);
}
