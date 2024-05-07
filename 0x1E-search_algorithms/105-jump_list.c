#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list of integers using the
 * Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 * Return: a pointer to the first node where value is located or NULL if value
 * is not present in list
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t i, jump;
	listint_t *prev, *node;

	if (list == NULL)
		return (NULL);

	jump = sqrt(size);
	prev = list;
	node = list;
	for (i = 0; i < size; i += jump)
	{
		if (i != 0)
			prev = prev->next;
		while (node->index < i)
			node = node->next;
		printf("Value checked at index [%lu] = [%d]\n",
		       node->index, node->n);
		if (node->n >= value)
			break;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, node->index);
	printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
	while (prev->index <= node->index && prev != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
