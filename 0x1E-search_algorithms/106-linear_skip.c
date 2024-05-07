#include "search_algos.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 * Return: a pointer on the first node where value is located or NULL if value
 * is not present in list
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *node;

	if (list == NULL)
		return (NULL);

	prev = list;
	node = list;
	while (node != NULL)
	{
		prev = node;
		if (node->express == NULL)
		{
			while (node->next != NULL)
				node = node->next;
			break;
		}
		printf("Value checked at index [%lu] = [%d]\n",
		       node->express->index, node->express->n);
		if (node->express->n >= value)
			break;
		node = node->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       prev->index, node->index);
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
