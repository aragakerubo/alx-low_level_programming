#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to head of list
 * @index: index of node to return
 *
 * Return: address of node at index or NULL if node doesn't exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int node_num = 0;

	while (head)
	{
		if (node_num == index)
			return (head);
		node_num++;
		head = head->next;
	}

	return (NULL);
}
