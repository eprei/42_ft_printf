#include "libftprintf.h"

unsigned int	ft_intlen(int c)
{
	unsigned int	i;
	long int		x;

	x = c;
	i = 0;
	if (x < 0)
	{
		x = x * (-1);
		i++;
	}
	while (x > 9)
	{
		x = x / 10;
		i++;
	}
	i++;
	return (i);
}

unsigned int	ft_itoa(int n)
{
	char			*ptr;
	unsigned int	len_n;
	long int		m;

	m = n;
	len_n = ft_intlen(m);
	ptr = (char *)malloc(sizeof(char) * (len_n + 1));
	if (ptr == NULL)
		return (0);
	if (len_n == 0 || m == 0)
		ptr[0] = '0';
	ptr[len_n] = '\0';
	if (m < 0)
	{
		ptr[0] = '-';
		m = m * (-1);
	}
	while (m > 0)
	{
		ptr[len_n - 1] = (m % 10) + 48;
		m = m / 10;
		len_n--;
	}
	ft_putstr(ptr);
	free(ptr);
	return (ft_intlen(n));
}

unsigned int	ft_u_intlen(unsigned int c)
{
	unsigned int	i;
	unsigned int	x;

	x = c;
	i = 0;
	if (x < 0)
	{
		x = x * (-1);
		i++;
	}
	while (x > 9)
	{
		x = x / 10;
		i++;
	}
	i++;
	return (i);
}

unsigned int	ft_u_itoa(unsigned int n)
{
	char			*ptr;
	unsigned int	len_n;
	unsigned int		m;

	m = n;
	len_n = ft_u_intlen(m);
	ptr = (char *)malloc(sizeof(char) * (len_n + 1));
	if (ptr == NULL)
		return (0);
	if (len_n == 0 || m == 0)
		ptr[0] = '0';
	ptr[len_n] = '\0';
	while (m > 0)
	{
		ptr[len_n - 1] = (m % 10) + 48;
		m = m / 10;
		len_n--;
	}
	ft_putstr(ptr);
	free(ptr);
	return (ft_u_intlen(n));
}


int	ft_putchar(char c)
{
	if (!c)
        return (0);
    else
    {
        write(1, &c, 1);
        return (1);
    }
}

unsigned int	ft_switch(char conversion, va_list ap)
{
	if (conversion == 'c')
        return (ft_putchar(va_arg(ap, int)));
	if (conversion == 's')
		return (ft_putstr(va_arg(ap, char*)));
/*	if (conversion == 'p')
		return (va_arg(ap, unsigned long));*/
	if (conversion == 'd' || conversion == 'i')
		return (ft_itoa(va_arg(ap, int)));
	if (conversion == 'u')
		return (ft_u_itoa(va_arg(ap, unsigned int)));
/*	if (conversion == 'x')
		return (va_arg(ap, unsigned int));
	if (conversion == 'X')
		return (va_arg(ap, unsigned int));*/
    if (conversion == '%')
		return (ft_putchar('%'));
    return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t ft_putstr(char *s)
{
	if (s == NULL)
		return (0);
	write(1, s, ft_strlen(s));
    return (ft_strlen(s));
}

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

int main()
{
//	printf("count = %d\n", ft_printf("car %c str1 %s str2 %s %%\n", 'x', "uno", "trese"));
	printf("Cantidad de caracters %u\n", ft_printf("%u\n", 2147483648));
	printf("%ld\n", 2147483648);
    return (0);
}
