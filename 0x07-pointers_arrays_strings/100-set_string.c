#include <stdio.h>
#include <stdlib.h>

/**
 * set_string - sets the value of a pointer to a char.
 * @s: pointer to pointer to char
 * @to: pointer to char
 *
 * Description: sets the value of a pointer to a char.
 *
 * Return: void
 */
void set_string(char **s, char *to)
{
	*s = to;
}
