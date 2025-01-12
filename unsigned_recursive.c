#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_unsigned_recursive - Prints an unsigned integer recursively.
 * @n: The unsigned integer to print.
 *
 *
 * Return: Number of characters printed.
 */

int print_unsigned_recursive(unsigned int n)
{
	int count = 0;
	char num;

	if (n < 10)
	{
		num = n + '0';
		count += write(1, &num, 1);
		return (count);
	}

	count += print_unsigned_recursive(n / 10);
	num = (n % 10) + '0';
	count += write(1, &num, 1);

	return (count);
}
