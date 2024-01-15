#include "lists.h"

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to head of list
 *
 * Return: void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *next_node = NULL;

	while (head)
	{
		next_node = head->next;
		free(head);
		head = next_node;
	}
}