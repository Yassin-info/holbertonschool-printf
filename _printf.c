#include "main.h"
/**
* 
*/
int_printf(const char *format, ...)
{
    
    int count = 0;
    const char *c;
    va_list args;

    if (format == NULL)
    return (-1);

    va_start(args, format);

    if (c = '%')
    {
        c++;
        if (c = '\0')
        {
            return (-1);
