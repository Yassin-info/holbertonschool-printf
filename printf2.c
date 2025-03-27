#include <stdio.h>
#include "main.h"
/**
* print_int - imprime un entier sur sortie standard
* @args: liste arguments contenat entier a imprimer
* Return: nombre de chiffe a imprimer
*/
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		n = -n;
	}
	count += print_number(n);

	return (count);
}
/**
 * print_number - imprime nombre en utilisant recursion
 * @num: nombre a imprimer
 * Return: nombre de chiffre a imprimer
 */

int print_number(unsigned int num)
{
    int count = 0;

    if (num / 10)
        count += print_number(num / 10);

    count += _putchar(num % 10 + '0');
    return (count);
}
