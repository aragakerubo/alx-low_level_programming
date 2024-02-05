#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: If an error occurs, return NULL.
 * Otherwise, return a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	sht = malloc(sizeof(shash_table_t));
	if (sht == NULL)
		return (NULL);

	sht->size = size;
	sht->array = malloc(sizeof(shash_node_t *) * size);
	if (sht->array == NULL)
	{
		free(sht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		sht->array[i] = NULL;

	sht->shead = NULL;
	sht->stail = NULL;

	return (sht);
}

/**
 * shash_table_set - Adds an element to a sorted hash table
 * @ht: A pointer to the sorted hash table
 * @key: The key to add
 * @value: The value to add
 *
 * Return: Upon success, return 1. Otherwise, return 0.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *new;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value), node->value = strdup(value);
			if (node->value == NULL)
				return (0);
			return (1);
		}
		node = node->next;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
		return (0);
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = strdup(value);
	if (new->value == NULL)
	{
		free(new->key), free(new);
		return (0);
	}
	new->next = ht->array[index], ht->array[index] = new;
	if (ht->shead == NULL)
	{
		ht->shead = new, new->sprev = NULL, new->snext = NULL, ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL, new->snext = ht->shead, ht->shead->sprev = new, ht->shead = new;
	}
	else
	{
		node = ht->shead;
		while (node->snext && strcmp(node->snext->key, key) < 0)
			node = node->snext;
		new->sprev = node, new->snext = node->snext;
		if (node->snext == NULL)
			ht->stail = new;
		else
			node->snext->sprev = new;
		node->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key
 * @ht: A pointer to the sorted hash table
 * @key: The key to locate
 *
 * Return: If the key is not found, return NULL.
 * Otherwise, return the value associated with the key.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];

	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table
 * @ht: A pointer to the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	char *delim = "";

	if (ht == NULL)
		return;

	putchar('{');
	for (node = ht->shead; node; node = node->snext)
	{
		printf("%s'%s': '%s'", delim, node->key, node->value);
		delim = ", ";
	}
	puts("}");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse
 * @ht: A pointer to the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	char *delim = "";

	if (ht == NULL)
		return;

	putchar('{');
	for (node = ht->stail; node; node = node->sprev)
	{
		printf("%s'%s': '%s'", delim, node->key, node->value);
		delim = ", ";
	}
	puts("}");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: A pointer to the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node)
	{
		temp = node->snext;
		free(node->key), free(node->value), free(node);
		node = temp;
	}
	free(ht->array);
	free(ht);
}
