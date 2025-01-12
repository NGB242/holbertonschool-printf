#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Prototypes of functions used in _printf */
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int handle_format(const char *format, va_list args);
int print_integer(va_list args);
int print_integer_recursive(int n);
int print_unsigned_recursive(unsigned int n);

#endif /* MAIN_H */
