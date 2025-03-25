#include "main.h"
/**
* 
*/
int_printf(const char *format, ...)
{
    
    int count = 0;
    const char *c;
    va_list args;

    format_specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'\0', NULL}
	};

    for (c = format; *c != '\0'; c++)
	{
        if (format == NULL)
        return (-1);

        va_start(args, format);

        if (c == '%')
        {
            c++;
            if (c == '\0')
            {
                va_end(args);
                return (-1);
            }
			count += handle_specifier(*p, args, specifiers);
		}
		else
		{
			count += _putchar(*p);
		}
	}
	va_end(args);
	return (count);
}
/**
*
*/
int handle_specifier(char specifier, va_list args, format_specifier_t
specifiers[])

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
*
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
*/
