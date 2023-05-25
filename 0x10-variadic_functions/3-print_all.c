#include "variadic_functions.h"

void print_char(va_list ap);
void print_int(va_list ap);
void print_float(va_list ap);
void print_string(va_list ap);

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Description: prints anything
 *
 * Return: void
 */
void print_all(const char *const format, ...)
{
	va_list ap;
	unsigned int i, j;
	char *separator = "";
	print_t print[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(ap, format);
	i = 0;
	while (format && format[i])
	{
		j = 0;
		while (print[j].c != NULL)
		{
			if (*(print[j].c) == format[i])
			{
				printf("%s", separator);
				print[j].f(ap);
				separator = ", ";
			}
			j++;
		}
		i++;
	}
	va_end(ap);
	printf("\n");
}

/**
 * print_char - prints a char
 * @ap: argument pointer
 *
 * Description: prints a char
 *
 * Return: void
 */
void print_char(va_list ap)
{
	printf("%c", va_arg(ap, int));
}

/**
 * print_int - prints an int
 * @ap: argument pointer
 *
 * Description: prints an int
 *
 * Return: void
 */
void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_float - prints a float
 * @ap: argument pointer
 *
 * Description: prints a float
 *
 * Return: void
 */
void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_string - prints a string
 * @ap: argument pointer
 *
 * Description: prints a string
 *
 * Return: void
 */
void print_string(va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}
