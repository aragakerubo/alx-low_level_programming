#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: The head of the dlistint_t list.
 * @n: The data to insert into the dlistint_t list.
 *
 * Return: The address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_tail = NULL, *tail = NULL;

	if (!head)
		return (NULL);
	new_tail = malloc(sizeof(dlistint_t));
	if (!new_tail)
		return (NULL);
	new_tail->n = n;
	new_tail->next = NULL;
	if (!*head)
	{
		new_tail->prev = NULL;
		*head = new_tail;
		return (new_tail);
	}
	tail = *head;
	while (tail->next)
		tail = tail->next;
	tail->next = new_tail;
	new_tail->prev = tail;

	return (new_tail);
}
