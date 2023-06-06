#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 * @head: pointer to the first node
 *
 * Description: The function prints a listint_t linked list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head, *next;

	while (current)
	{
		next = current->next;
		count++;
		printf("[%p] %d\n", (void *)current, current->n);
		if (current <= next)
		{
			printf("-> [%p] %d\n", (void *)next, next->n);
			break;
		}
		current = next;
	}

	return (count);
}
