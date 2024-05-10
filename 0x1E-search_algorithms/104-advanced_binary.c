#include "search_algos.h"

int advanced_binary_recursive(int *array, size_t start, size_t end, int value);

/**
 * advanced_binary_recursive - recursive helper function for advanced_binary
 * @array: pointer to the first element of the array to search in
 * @start: starting index of the subarray to search in
 * @end: ending index of the subarray to search in
 * @value: value to search for
 * Return: the index where value is located or -1 if value is not present
 */
int advanced_binary_recursive(int *array, size_t start, size_t end, int value)
{
	size_t mid = start + (end - start) / 2;
	size_t i;

	if (start > end)
		return -1;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
		printf("%d%s", array[i], (i == end) ? "\n" : ", ");

	if (array[mid] == value)
	{
		if (mid == start || array[mid - 1] != value)
			return mid;
		else
			return advanced_binary_recursive(array, start, mid - 1, value);
	}
	else if (array[mid] < value)
		return advanced_binary_recursive(array, mid + 1, end, value);
	else
		return advanced_binary_recursive(array, start, mid - 1, value);
}

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
	if (array == NULL || size == 0)
		return (-1);

	return advanced_binary_recursive(array, 0, size - 1, value);
}
