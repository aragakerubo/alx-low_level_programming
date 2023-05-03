#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - generates random valid passwords for the program 101-crackme.
 *
 * Description: Generates random valid passwords for the program 101-crackme.
 *
 * Return: 0
 */
int main(void)
{
	int sum, n;
	char c;

	sum = 0;
	srand(time(NULL));
	while (sum < 2772)
	{
		n = rand() % 128;
		if (n > 32)
		{
			c = n;
			sum += c;
			putchar(c);
		}
	}
	putchar(2772 - sum);
	return (0);
}

