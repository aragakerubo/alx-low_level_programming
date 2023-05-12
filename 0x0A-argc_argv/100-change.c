#include <stdio.h>
#include <stdlib.h>

int find_coins(int cents);

/**
 * main - prints the minimum number of coins to make change
 * for an amount of money
 * @argc: number of arguments passed to the program
 * @argv: array of pointers to the arguments
 *
 * Description: prints the minimum number of coins to make
 * change for an amount of money
 *
 * Return: 0 if successful, 1 if error
 */
int main(int argc, char *argv[])
{
	int cents, coins;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	coins = find_coins(cents);

	printf("%d\n", coins);

	return (0);
}

/**
 * find_coins - finds the minimum number of coins to make change
 * @cents: the amount of cents to make change for
 *
 * Description: finds the minimum number of coins to make change
 *
 * Return: the minimum number of coins to make change
 */
int find_coins(int cents)
{
	int coins = 0;

	while (cents > 0)
	{
		if (cents >= 25)
			cents -= 25;
		else if (cents >= 10)
			cents -= 10;
		else if (cents >= 5)
			cents -= 5;
		else if (cents >= 2)
			cents -= 2;
		else
			cents -= 1;
		coins++;
	}

	return (coins);
}
