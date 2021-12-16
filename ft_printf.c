#include "ft_printf.h"

int ft_printf(const char *str, ...)
{
    va_list		ap;
    int			count;

    count = 0;
    va_start(ap, str);

    while (*str)
    {
        if (*str == '%')
        {
            str++;
            count += (ft_switch(*str, ap));
        }
        else
            count += ft_putchar(*str);   
        str++;
    }
    va_end(ap);
    return (count);
}
