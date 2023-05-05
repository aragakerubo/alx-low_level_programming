#include <stddef.h>
#include "main.h"

int get_sum(char *num1, char *num2, char *buffer, int buffer_size);

/**
 * get_sum - calculates the sum of two numbers and stores it in the buffer
 * @num1: first number
 * @num2: second number
 * @buffer: buffer to store result
 * @buffer_size: buffer size
 *
 * Description: calculates the sum of two numbers
 * where num1 and num2 are two numbers
 * and stores the result in the buffer.
 * buffer_size is the size of the buffer.
 *
 * Return: 1 if the calculation was successful, 0 if not.
 */
int get_sum(char *num1, char *num2, char *buffer, int buffer_size)
{
	int i, j, k, l, m, n, sum, num1_int, num2_int, carry;

	for (i = 0; num1[i] != '\0'; i++)
		;
	for (j = 0; num2[j] != '\0'; j++)
		;
	if (i + 2 > buffer_size || j + 2 > buffer_size)
		return (0);
	carry = 0;
	k = i - 1;
	l = j - 1;
	m = 0;
	while (k >= 0 || l >= 0)
	{
		num1_int = num2_int = 0;
		if (k >= 0)
			num1_int = num1[k--] - '0';
		if (l >= 0)
			num2_int = num2[l--] - '0';
		sum = num1_int + num2_int + carry;
		if (sum > 9)
		{
			carry = 1;
			sum -= 10;
		}
		else
			carry = 0;
		buffer[m++] = sum + '0';
	}
	if (carry == 1)
		buffer[m++] = carry + '0';
	buffer[m] = '\0';
	for (k = m - 1, l = 0; l < k; k--, l++)
	{
		n = buffer[k];
		buffer[k] = buffer[l];
		buffer[l] = n;
	}
	return (1);
}

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @result_buffer: buffer to store result
 * @result_size: buffer size
 *
 * Description: adds two numbers where n1 and n2 are two numbers
 * r is the buffer that the function will use to store the result
 * result_size is the buffer size.
 * The function returns a pointer to the result
 *
 * Return: pointer to result, or NULL if calculation failed
 */
char *infinite_add(char *n1, char *n2, char *result_buffer, int result_size)
{
	char *result = NULL;

	if (get_sum(n1, n2, result_buffer, result_size))
		result = result_buffer;
	return (result);
}
