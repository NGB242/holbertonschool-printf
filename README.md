## printf function - Custom implementation of printf in C

## Description
The '_printf' project consists of recreating the standard 'printf' function of the C library.

This custom version supports certain conversion specifiers and offers a formatted output, while respecting the basic principles of 'printf'.

## Fonctionnality
The '_printf' function allows you to print formatted outputs on the standard output ('stdout'). Here are the currently supported conversion specifiers:
- '%c' : Displays a character.
- '%s' : Displays a string of characters.
- '%%' : Displays a symbol `%`.
- '%i' : Displays an integer 
- '%d' : Displays a decimal

## Characteristics
- Management of current specifiers ('c','s','%','i', 'd').
- Direct write to standard output using the write' function.
- Manipulation of variadic arguments via 
'Stdarg.h'.
*Prototype of the function
int _printf(const char *format, ...);
