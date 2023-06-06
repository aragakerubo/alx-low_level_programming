#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to the first node
 *
 * Description: The function frees a listint_t list
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current = *h, *next;

	if (h)
	{
		while (current)
		{
			next = current->next;
			count++;
			free(current);
			if (current <= next)
				break;
			current = next;
		}
		*h = NULL;
	}

	return (count);
}
