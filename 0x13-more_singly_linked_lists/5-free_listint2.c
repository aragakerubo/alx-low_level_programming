#include "lists.h"

/**
 * free_listint2 - frees a listint_t list
 * @head: pointer to the head of the list
 *
 * Description: frees a listint_t list
 *
 * Return: void
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp = NULL;

	if (!head)
		return;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}

	head = NULL;
}
