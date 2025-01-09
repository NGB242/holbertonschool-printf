#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
typedef struct specificateur
{
char specificateur;
int (*pointeurdefonction)(va_list);
} specificateur_t;
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int _putchar(char c);
#endif
