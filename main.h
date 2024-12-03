#ifndef our_printf
#define our_printf
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * struct specifier - struct specifier
 * @valid: the valid character.
 * @f: the functions associated.
 *
 */
typedef struct specifier
{
	char *valid;
	int (*f)(va_list);
} spec;
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int handle_specifier_d_or_i(va_list args);
int (*get_func(char x))(va_list args);
#endif
