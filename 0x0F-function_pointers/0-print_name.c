#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - prints a name
 * @name: name to print
 * @f: function pointer
 *
 * Description: prints a name
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
