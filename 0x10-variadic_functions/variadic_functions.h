#ifndef VARAIDIC_FUNCTIONS_H
#define VARAIDIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct print - struct for printing with corresponding function
 * @c: char to match
 * @f: function to print
 *
 * Description: struct for printing with corresponding function
 */
typedef struct print
{
	char *c;
	void (*f)(va_list);
} print_t;


int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif /* VARAIDIC_FUNCTIONS_H */
