#include "variadic_functions.h"

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
	unsigned int i = 0, j;
	char *str;

	va_start(ap, format);
	while (format && format[i])
	{
		switch (format[i++])
		{
		case 'c':
			printf("%c", va_arg(ap, int));
			break;
		case 'i':
			printf("%d", va_arg(ap, int));
			break;
		case 'f':
			printf("%f", va_arg(ap, double));
			break;
		case 's':
			str = va_arg(ap, char *);
			if (str == NULL)
				str = "(nil)";
			printf("%s", str);
			break;
		}
		j = i;
		while (format[j] && (format[j] == 'c' || format[j] == 'i' ||
				     format[j] == 'f' || format[j] == 's'))
		{
			printf(", ");
			break;
		}
	}
	printf("\n");
	va_end(ap);
}
