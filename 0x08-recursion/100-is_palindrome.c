#include "main.h"

int find_palindrome(char *s, int start, int end);
int _strlen_recursion(char *s);

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to check
 *
 * Description: checks if a string is a palindrome
 *
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(char *s)
{
	return (find_palindrome(s, 0, _strlen_recursion(s) - 1));
}

/**
 * find_palindrome - finds if a string is a palindrome
 * @s: string to check
 * @start: start of string
 * @end: end of string
 *
 * Description: finds if a string is a palindrome
 *
 * Return: 1 if palindrome, 0 if not
 */
int find_palindrome(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);
	return (find_palindrome(s, start + 1, end - 1));
}

/**
 * _strlen_recursion - returns the length of a string
 * @s: string to check
 *
 * Description: returns the length of a string
 *
 * Return: length of string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (_strlen_recursion(++s) + 1);
}
