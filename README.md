
![images](https://github.com/user-attachments/assets/958a28ec-f9b0-487c-80f4-3085c1eb39d4)


Printf


Overview
This project implements a custom version of the printf function in C, named _printf. It is designed to handle specific format specifiers and is developed for use in environments where the standard library is not available or for specific needs.

Features
Supported Format Specifiers:

%c for characters

%s for strings

%d and %i for integers

%% to print the percentage sign

Error Handling:

Check if the format is NULL

Handling cases where the format is incorrect

Code Structure
The code is organized into several functions for better readability and maintainability:

_printf: Main function that processes the format string and calls appropriate functions for each specifier.

handle_specifier: Function that handles a given format specifier and calls the corresponding function.

print_char, print_string, print_int, print_percent: Functions that handle printing of different data types.

print_number: Recursive function to print integer numbers.

Code :

function prototype :
int_printf(const char *format, ...)

printf function:

int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;
            count += handle_specifier(*format, args, specifiers);
        }
        else
        {
            count += _putchar(*format);
        }
        format++;
    }

    va_end(args);
    return (count);
}

handle_specifier function:

int handle_specifier(char specifier, va_list args, format_specifier_t specifiers[])
{
    int i = 0;

    while (specifiers[i].specifier != '\0')
    {
        if (specifiers[i].specifier == specifier)
        {
            return (specifiers[i].func(args));
        }
        i++;
    }
    return (_putchar('%') + _putchar(specifier));
}

print_string function:

int print_string(va_list args)
{
    char *s = va_arg(args, char *);
    int count = 0;

    if (s == NULL)
        s = "(null)";

    while (*s != '\0')
    {
        count += _putchar(*s++);
    }
    return (count);
}

print_percent function

int print_percent(va_list args)
{
    (void)args;
    return (_putchar('%'));
}

print_char unction

int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (_putchar(c));
}

print_int function

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

print_number function

int print_number(unsigned int num)
{
    int count = 0;

    if (num / 10)
        count += print_number(num / 10);

    count += _putchar(num % 10 + '0');
    return (count);
}


Usage :
To use this function, include the main.h file in your program and call _printf as you would with printf, passing a format string and the necessary arguments.


#include "main.h"

int main()
{
    _printf("Hello, %s!\n", "world");
    _printf("The integer is: %d\n", 123);
    return 0;
}


Compilation
To compile this project, use a standard C compiler like GCC. Make sure all source files are in the same directory.

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format _printf.c printf2.c main.c -o test

Output :


![image](https://github.com/user-attachments/assets/49e3426a-2b4c-49b9-90d6-e89aa7378a55)


Flowchart :

![image](https://github.com/user-attachments/assets/98750bbb-6083-4ad5-a5b3-c47f6989395f)

Author :
https://github.com/zoulouhh
https://github.com/Yassin-info
