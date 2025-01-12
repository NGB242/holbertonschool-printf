#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
* print_integer_recursive - Prints an integer recursively.
*
* @n: The integer to print.
* Return: Number of characters printed.
*/

int print_integer_recursive(int n)
{
	unsigned int count = 0;
	int num;

	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}

	if (n < 10 && n >= 0)
	{
		num = n + '0';
		count += write(1, &num, 1);
		return (count);
	}

	if (n == -2147483648)
	{
		count += write(1, "2147483648", 10);
		return (count);
	}

	count += print_integer_recursive(n / 10);
	num = (n % 10) + '0';
	count += write(1, &num, 1);

	return (count);
}
