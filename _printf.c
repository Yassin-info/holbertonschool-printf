#include "main.h"
#include <stdio.h>
/**
* _printf - fonction printf personnalisé pour gerer
*			specificateur de formats specifiques
* @format: la chaine de caractere conteant les caracteres et specificateurs
* @...: les valeurs a formater et a imprimer
* Return: nombre de caracteres a imprimer 
*/
int _printf(const char *format, ...)
{
    
    va_list args;
	int count = 0;
    const char *c;

    format_specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};

	if (format == NULL)
    return (-1);

    va_start(args, format);

    for (c = format; *c != '\0'; c++)
    {

        if (*c == '%')
        {
            c++;
            if (*c == '\0')
            {
                va_end(args);
                return (-1);
            }
		count += handle_specifier(*c, args, specifiers);
		}
		else
		{
			count += _putchar(*c);
		}
    }
	va_end(args);
	return (count);
}
/**
*handle_specifier - traite le specificateur de format et
*					apelle la foction approprier
* @specifier: le caractere specificateur de format
* @args: liste d'arguments
* @specifiers: tableau des specificateurs
* Return: nombre de caractere imprimer pour le specificateur
*/
int handle_specifier(char specifier, va_list args, format_specifier_t specifiers[])
{
	int i;

	for (i = 0; specifiers[i].specifier != '\0'; i++)
    {
		if (specifiers[i].specifier == specifier)
		{
			return (specifiers[i].func(args));
		}
    }
	return (_putchar('%') + _putchar(specifier));
}
/**
*print_string - imprime une chaine sur la sortie standard
* @args: chaine a imprimer
* Return: nombre de caractere a imprimer
*/
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		count += _putchar(*s++);
	}
    return (count);
}
/** 
* print_percent - imprime %
* @args: liste arguments
* Return: toujours 1 (succes)
*/
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}
/**
*print_char - imprime un caractère sur la sortie standard.
* @args: Liste d'arguments contenant le caractère à imprimer.
* Return: toujours 1 (succes).
*/
int print_char(va_list args)
{
	char c = va_arg(args, int);
    return (_putchar(c));
}
