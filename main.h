#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
int _printf(const char *format, ...);
int afficher_caractere(va_list arguments);
int afficher_chaine(va_list arguments);
int afficher_pourcentage(va_list arguments);
int afficher_decimal(va_list arguments);
int afficher_entier(va_list arguments);
/**
 * struct CaractereSpeciale - structure pour associer
 * un caractere special à une fonction
 * @lettreachanger: le caractere special (ex. 'c', 's', '%', etc.)
 * @pointeurdefonction: un pointeur vers la fonction qui gere,
 * ce caractere special
 */
typedef struct CaractereSpeciale
{
char lettreachanger;
int (*pointeurdefonction)(va_list arguments);
}
CaractereSpeciale;
#endif
