#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

/**
 * _printf - affiche une chaine de caractères, dont si elle en contient:
 * une fonction retournant un caractère, une chaine,
 * un nombre entier ou une décimal
 *
 * @format: la chaine de caractères à traiter
 * Return: nombres de caractères
 */

int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
char *str;

va_start(args, format);
while (format && format[i])
{
if (format[i] == '%' && format[i + 1] == 'r')
{
str = va_arg(args, char *);
if (str)
{
int len = strlen(str);
while (len--)
write(1, &str[len], 1);
count += strlen(str);
}
i += 2;
}
else
{
write(1, &format[i], 1);
count++;
i++;
}
}
va_end(args);
return (count);

}
