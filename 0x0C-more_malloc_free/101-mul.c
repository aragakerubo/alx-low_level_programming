#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int _strlen(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);
int _isdigit(int c);

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of pointers to arguments
 *
 * Description: multiplies two positive numbers
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, len, i, j, carry, digit1, digit2, *result;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = argv[1], num2 = argv[2];
	len1 = _strlen(num1), len2 = _strlen(num2);
	len = len1 + len2 + 1;
	result = _calloc(sizeof(*result), len);
	if (!result)
		return (1);
	for (i = len1 - 1; i >= 0; i--)
	{
		if (!_isdigit(num1[i]))
		{
			printf("Error\n");
			free(result);
			exit(98);
		}
		digit1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			if (!_isdigit(num2[j]))
			{
				printf("Error\n");
				free(result);
				exit(98);
			}
			digit2 = num2[j] - '0';
			carry += result[i + j + 2] + (digit1 * digit2);
			result[i + j + 2] = carry % 10;
			carry /= 10;
		}
		if (carry)
			result[i + j + 2] += carry;
	}
	i = 0;
	while (result[i] == 0 && i < len - 1)
		i++;
	for (; i < len; i++)
		printf("%d", result[i]);
	printf("\n");
	free(result);
	return (0);
}

/**
 * _strlen - returns the length of a string
 * @s: string to check length of
 *
 * Description: returns the length of a string
 *
 * Return: length of s
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}

/**
 * _calloc - allocates memory for an array, using malloc
 * @nmemb: number of elements in the array
 * @size: size of each element in bytes
 *
 * Description: allocates memory for an array, using malloc
 *
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *mem;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
		mem[i] = 0;
	return (mem);
}

/**
 * _isdigit - checks if a character is a digit
 * @c: character to check
 *
 * Description: checks if a character is a digit
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
