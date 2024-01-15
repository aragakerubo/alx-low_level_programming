#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list.
 * @head: The head of the dlistint_t list.
 * @n: The data to insert into the dlistint_t list.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	size_t nodes = 0;
	dlistint_t *new_node = NULL;

	if (!head)
		return (NULL);

	nodes = dlistint_len(*head);

	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->prev = NULL;
	if (nodes)
	{
		new_node->next = *head;
		(*head)->prev = new_node;
	}
	else
		new_node->next = NULL;
	*head = new_node;

	return (new_node);
}