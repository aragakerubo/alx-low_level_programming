#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of
 * a listint_t linked list
 * @head: pointer to the first node
 * @index: index of the node that should be deleted
 *
 * Description: if the node does not exist, do not do anything
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *tmp;
	unsigned int i = 0;

	if (*head)
	{
		if (index == 0)
		{
			tmp = *head;
			*head = (*head)->next;
			free(tmp);
			return (1);
		}
		else
		{
			current = *head;
			while (i < index - 1 && current != NULL)
			{
				current = current->next;
				i++;
			}
			if (i < index - 1)
				return (-1);
			tmp = current->next;
			current->next = tmp->next;
			free(tmp);
			return (1);
		}
	}
	return (-1);
}
