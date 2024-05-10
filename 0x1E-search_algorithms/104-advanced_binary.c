#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers using
 * the Binary search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: number of elements in array
 * @value: value to search for
 * Return: the first index where value is located or -1 if value is not present
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t start = 0;
	size_t end = size - 1;
	size_t mid;
	size_t i;

	if (array == NULL || size == 0)
		return -1;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		printf("Searching in array: ");
		for (i = start; i <= end; i++)
			printf("%d%s", array[i], (i == end) ? "\n" : ", ");

		if (array[mid] == value)
		{
			if (mid == start || array[mid - 1] != value)
				return mid;
			else
				end = mid - 1;
		}
		else if (array[mid] < value)
			start = mid + 1;
		else
			end = mid - 1;
	}

	return -1;
}
