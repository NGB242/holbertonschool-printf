#include "main.h"
#include <string.h>  
/**
 * print_char - Imprime un caractère
 * @args: Liste des arguments de type va_list
 * 
 * Return: Nombre de caractères imprimés
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return write(1, &c, 1);
}
int print_string(va_list args)
/**
 * print_string - Imprime une chaîne de caractères
 * @args: Liste des arguments de type va_list
 * 
 * Return: Nombre de caractères imprimés
 */
{
	char *str = va_arg(args, char *);
    int compteur = 0;
    if (!str)
    str = "(null)";
    while (*str)
{
    write(1, str++, 1);
    compteur++;
}
    return compteur;
}
int print_percent(va_list args)
/**
 * print_percent - Imprime un caractère de pourcentage
 * @args: Liste des arguments de type va_list (non utilisé)
 * 
 * Return: Nombre de caractères imprimés
 */
{
    (void)args; 
    return write(1, "%", 1);
}
int print_decimal(va_list args)
/**
 * print_decimal - Imprime un entier
 * @args: Liste des arguments de type va_list
 * 
 * Return: Nombre de caractères imprimés
 */
{
    int n = va_arg(args, int);  
    int count = 0;
    char buffer[12];  
    int i = 0;
	
	if (n < 0) {
        _putchar('-');
        count++;
        n = -n; 
    }
	if (n == 0) {
        buffer[i++] = '0';
    } else 
	{
		while (n > 0) {
            buffer[i++] = (n % 10) + '0'; 
            n /= 10;  
        }
    }
    while (i > 0) {
        _putchar(buffer[--i]);
        count++;
    }
    return count;
}
/**
 * print_integer - Imprime un entier (identique à print_decimal)
 * @args: Liste des arguments de type va_list
 * 
 * Return: Nombre de caractères imprimés
 */
int print_integer(va_list args)
{
    return print_decimal(args); 
}
