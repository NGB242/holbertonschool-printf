#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
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
va_list arguments;
int compteur;
int compteur2;
int longueur = 0;

CaractereSpeciale Speciale[] = {
{'c', afficher_caractere},
{'s', afficher_chaine},
{'%', afficher_pourcentage},
{'d', afficher_decimal},
{'i', afficher_entier},
};

va_start(arguments, format);
if (format == NULL)
return (-1);
for (compteur = 0; format[compteur] != '\0'; compteur++)
{
if (format[compteur] == '%')
{
compteur++;
for (compteur2 = 0; Speciale[compteur2].lettreachanger != '\0'; compteur2++)
{
if (format[compteur] == Speciale[compteur2].lettreachanger)
{
longueur += Speciale[compteur2].pointeurdefonction(arguments);
}
}
}
else
{
write(1, &format[compteur], 1);
longueur++;
}
}
va_end(arguments);
return (longueur);
}
