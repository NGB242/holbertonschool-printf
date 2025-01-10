#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * afficher_caractere - affiche un caractère
 * @arguments: argument à convertir et afficher
 * Return: longueur
 */
int afficher_caractere(va_list arguments)
{
char caractere = va_arg(arguments, int);
write(1, &caractere, 1);
return (1);
}
/**
 * afficher_chaine - affiche une chaine de caractères
 * @arguments: argument à convertir et afficher
 * Return: longueur
 */
int afficher_chaine(va_list arguments)
{
char *chaine = va_arg(arguments, char *);
int longueur = 0;
while (*chaine != '\0')
{
write(1, chaine, 1);
chaine++;
longueur++;
}
return (longueur);
}
/**
 * afficher_pourcentage - affiche un %
 * @arguments: argument à convertir et afficher
 * Return: 1, %
 */
int afficher_pourcentage(va_list arguments)
{
char pourcentage = '%';
(void)arguments;
write(1, &pourcentage, 1);
return (1);
}
/**
 * afficher_entier - affiche un nombre entier
 * @arguments: argument à convertir et afficher
 * Return: longueur
 */
int afficher_entier(va_list arguments)
{
int num = va_arg(arguments, int);
char tampon[20];
int longueur = 0;
int compteur;
if (num == 0)
{
write(1, "0", 1);
return (0);
}
if (num < 0)
{
write(1, "-", 1);
num = -num;
}
while (num > 0)
{
tampon[longueur++] = (num % 10) + '0';
num /= 10;
}
for (compteur = longueur - 1; compteur >= 0; compteur--)
{
write(1, &tampon[compteur], 1);
}
return (longueur);
}

/**
 * afficher_decimal - affiche un nombre décimal
 * @arguments: argument à convertir et afficher
 * Return: longueur
 */
int afficher_decimal(va_list arguments)
{
double nombre = va_arg(arguments, double);
int partie_entier = (int)nombre;
double partie_decimale = nombre - partie_entier;

int longueur = 0;
int stock_entier;
int compteur;
char espace[50];
int chiffre;

stock_entier = partie_entier;
if (partie_entier == 0)
{
write(1, "0", 1);
longueur++;
}
else
{
while (stock_entier > 0)
{
stock_entier /= 10;
longueur++;
}
for (compteur = longueur - 1; compteur >= 0; compteur--)
{
espace[compteur] = (partie_entier % 10) + '0';
partie_entier /= 10;
}
write(1, espace, longueur);
}
if (partie_decimale > 0)
{
write(1, ".", 1);
for (compteur = 0; compteur < 6; compteur++)
{
partie_decimale *= 10;
chiffre = (int)partie_decimale;
espace[0] = chiffre + '0';
write(1, &espace[0], 1);
partie_decimale -= chiffre;
}
}
return (longueur + 7);

}

