#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - Handles the display of a character.
 * @args: List of arguments.
 *
 * Return: Number of characters printed.
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Handles the display of a string.
 * @args: List of arguments.
 *
 * Return: Number of characters printed.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	if (str == NULL)
	{
		count += write(1, "(null)", 6);
		return (count);
	}

	if (*str == '\0')
	{
		return (count);
	}

	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}

	return (count);
}

/**
 * print_integer - Handles the display of an integer.
 * @args: List of arguments.
 * Return: Number of characters printed.
 */
int print_integer(va_list args)
{
	int n = va_arg(args, int);

	return (print_integer_recursive(n));
}

/**
 * handle_format - Handles format specifiers.
 * @format: The format string.
 * @args: List of arguments.
 *
 * Return: Number of characters printed.
 */
int handle_format(const char *format, va_list args)
{
	int count = 0;

	if (*format == 'c')
		count += print_char(args);
	else if (*format == 's')
		count += print_string(args);
	else if (*format == '%')
		count += write(1, "%", 1);
	else if (*format == 'd' || *format == 'i')
		count += print_integer(args);
	else if (*format == 'u')
		count += print_unsigned_recursive(va_arg(args, unsigned int));
	else
		count += write(1, format, 1);

	return (count);
}

/**
 * _printf - Produces output according to a given format.
 * @format: The format string containing specifiers.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
			count += handle_format(&format[++i], args);
		else
			count += write(1, &format[i], 1);
		i++;
	}

	va_end(args);

	return (count);
}
