#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - Produit une sortie formatée selon une chaîne donnée
 * @format: Une chaîne de caractères contenant le format et les spécificateurs
 * return:Le nombre total de caractères imprimés (hors le caractère nul final)
 */

int _printf(const char *format, ...)
{
    int count = 0; // Compteur pour le nombre de caractères imprimés
    va_list args; // Liste pour stocker les arguments variadiques
    char *str; // Pointeur pour gérer les chaînes de caractères
    char c;  // Variable pour stocker un caractère à imprimer
    unsigned long i = 0; // Variable pour parcourir l'index de la chaine, déclarée à l'exterieure

if (!format)
        return (-1);
va_start(args, format);
while (format[i] != '\0') {
    if (format[i] == '%') {
            i++;
    if (format[i] == 'c') {
        c = (char)va_arg(args, int);
        count += write(1, &c, 1);
} else if  (format[i] == 's') {
    str = va_arg(args, char *);
     if (!str)
     str = "(null)"; 
     while (*str)
     count += write(1, str++, 1);
     } else if (format[i] == '%') {
        count += write(1, "%", 1);
        } else {
            count += write(1, "%", 1);
            count += write(1, &format[i], 1);
        }
    } else { 
        count += write(1, &format[i], 1);
     }
    va_end(args);
    return (count);
}
