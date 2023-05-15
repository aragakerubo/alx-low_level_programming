#include <stdio.h>
#include <stdlib.h>

/**
 * argstostr - concatenates all the arguments of your program.
 * @ac: number of arguments
 * @av: array of arguments
 *
 * Description: concatenates all the arguments of your program.
 *
 * Return: pointer to a new string, or NULL if it fails
 */
char *argstostr(int ac, char **av)
{
	int i, j, k, len;
	char *str;

	if (ac == 0 || av == NULL)
		return (NULL);

	len = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++, len++)
			;
		len++;
	}

	str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (NULL);

	k = 0;
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j]; j++, k++)
			str[k] = av[i][j];
		str[k] = '\n';
		k++;
	}
	str[k] = '\0';

	return (str);
}
