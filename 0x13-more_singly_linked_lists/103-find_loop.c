#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the first node
 *
 * Description: The function finds the loop in a linked list
 *
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *current = head, *next = head;

	while (current && next && next->next)
	{
		current = current->next;
		next = next->next->next;
		if (current == next)
			break;
	}

	if (current != next)
		return (NULL);

	current = head;
	while (current != next)
	{
		current = current->next;
		next = next->next;
	}

	return (current);
}
