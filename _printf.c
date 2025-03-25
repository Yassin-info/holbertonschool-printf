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
            if (c = '\0')
            {
                return (-1);
