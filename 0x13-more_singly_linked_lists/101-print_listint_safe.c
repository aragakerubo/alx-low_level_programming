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
	listint_t *current, *next;

	if (!head)
		exit(98);

	current = (listint_t *)head;
	while (current)
	{
		next = current->next;
		count++;
		printf("[%p] %d\n", (void *)current, current->n);
		current = next;
	}

	current = (listint_t *)head;
	while (current)
	{
		next = current->next;
		current = next;

		if (current >= next)
		{
			printf("-> [%p] %d\n", (void *)current, current->n);
			break;
		}
	}

	return (count);
}
