#include "main.h"

/**
 * _atoi - Convert a string to an integer
 * @s: The string to be converted
 *
 * Description: The number in the string can be preceded by an infinite number
 * of characters. You need to take into account all the - and + signs
 * before the number. If there are no numbers in the string,
 * the function must return 0
 *
 * Return: The first number in the string converted to integer
 */
int _atoi(char *s)
{
	int i, sign, num;

	i = 0;
	sign = 1;
	num = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + (s[i] - '0');
		if (s[i] == ';')
			break;
		i++;
	}
	return (num * sign);
}
