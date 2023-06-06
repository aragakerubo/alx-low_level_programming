#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the first node
 * @idx: index of the list where the new node should be added
 * @n: value of the new node
 *
 * Description: if it is not possible to add the new node at index idx,
 * do not add the new node and return NULL
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current, *new;
	unsigned int i = 0;

	new = malloc(sizeof(listint_t));
	if (new)
	{
		new->n = n;
		if (i == 0)
		{
			new->next = *head;
			*head = new;
		}
		else
		{
			current = *head;
			while (i < idx && current != NULL)
			{
				current = current->next;
				i++;
			}
			if (i < idx)
			{
				new->next = current->next;
				current->next = new;
			}
		}
	}
	return (new);
}
