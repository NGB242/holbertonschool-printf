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
if (format[i] == '%' && format[i + 1] == 's')
{
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
write(1, str, strlen(str));
count += strlen(str);
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
