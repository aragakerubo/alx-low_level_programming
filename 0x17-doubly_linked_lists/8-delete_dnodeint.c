#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index index of a linked list
 * @head: pointer to a pointer to a dlistint_t struct
 * @index: index of the node that should be deleted
 *
 * Return: 1 if it succeeded, -1 if it failed
 *         if the node does not exist, do not do anything
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		temp = *head;
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}
	current = *head;
	for (i = 0; i < index - 1; i++)
	{
		if (current->next == NULL)
			return (-1);
		current = current->next;
	}
	temp = current->next;
	current->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = current;
	free(temp);
	return (1);
}
