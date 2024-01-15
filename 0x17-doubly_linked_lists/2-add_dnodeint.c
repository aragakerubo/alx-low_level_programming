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
	dlistint_t *new_head = NULL;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(dlistint_t));
	if (!new_head)
		return (NULL);
	new_head->n = n;
	new_head->prev = NULL;
	new_head->next = *head;
	if (*head)
		(*head)->prev = new_head;
	*head = new_head;

	return (new_head);
}