#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - Produit une sortie formatée selon une chaîne donnée
 * @format: Une chaîne de caractères contenant le format et les spécificateurs
 * return:Le nombre total de caractères imprimés (hors le caractère nul final)
 */

int _printf(const char *format, ...);
/**
 * print_number - Affiche un entier en écrivant chaque chiffre
 * @n: L'entier à afficher
 * Return: Le nombre de caractères écrits
 */
int print_number(int n);
/**
 * handle_specifier_d_or_i - Gère les spécificateurs %d et %i
 * @args: Liste des arguments variadiques
 * Return: Le nombre de caractères imprimés
 */
int handle_specifier_d_or_i(va_list args);

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;       // Compteur pour le nombre de caractères imprimés
    unsigned long i = 0; // Index pour parcourir la chaîne format
    if (!format)
        return (-1);
    va_start(args, format); // Initialise la liste d'arguments variadiques
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        { // Vérifie si un spécificateur est détecté
            i++;
            if (format[i] == 'd' || format[i] == 'i')
            { // Spécificateurs %d et %i
                count += handle_specifier_d_or_i(args);
            }
            else
            {
                count += write(1, "%", 1); // Écrit littéralement un '%'
                if (format[i] != '\0')
                    count += write(1, &format[i], 1);
            }
        }
        else
        {
            count += write(1, &format[i], 1); // Affiche le caractère normal
        }
        {
            i++;
        }

        va_end(args);   // Termine la liste des arguments variadiques
        return (count); // Retourne le nombre total de caractères imprimés
    }

    int handle_specifier_d_or_i(va_list args)
    {
        int i = va_arg(args, int); // Récupère le prochain argument de type int
        return print_number(num);    // Appelle print_number pour afficher l'entier
    }
    int print_number(int n)
    {
        int count = 0;
        char digit;
        if (n < 0)
        {
            count += write(1, "-", 1);
            n = -n;
        }
        if (n / 10 != 0)
            count += print_number(n / 10);
        digit = (n % 10) + '0'; // Convertit le chiffre en caractère
        count += write(1, &digit, 1);

        return count;
 
      }      }   
