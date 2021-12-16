#include "ft_printf.h"

size_t	ft_putnbr_hex(unsigned int n)
{
	char *str;
	size_t count;
	
	count = 0;
	str = "0123456789abcdef";
	if (n >= 0 && n <= 15)
	{
		write(1, &str[n], 1);
		count += 1;
	}
	else
	{
		count += ft_putnbr_hex(n / 16);
		count += ft_putnbr_hex(n % 16);
	}
	return (count);
}

size_t	ft_putnbr_HEX(unsigned int n)
{
	char *str;
	size_t count;
	
	count = 0;
	str = "0123456789ABCDEF";
	if (n >= 0 && n <= 15)
	{
		write(1, &str[n], 1);
		count += 1;
	}
	else
	{
		count += ft_putnbr_HEX(n / 16);
		count += ft_putnbr_HEX(n % 16);
	}
	return (count);
}

size_t	ft_putnbr_pointer(unsigned long n)
{
	char *str;
	size_t count;
	
	count = 0;
	str = "0123456789abcdef";
	if (n >= 0 && n <= 15)
	{
		write(1, &str[n], 1);
		count += 1;
	}
	else
	{
		count += ft_putnbr_pointer(n / 16);
		count += ft_putnbr_pointer(n % 16);
	}
	return (count);
}

size_t	ft_str_putnbr_pointer(unsigned long n)
{
	size_t	count;

	count = 0;
	count += ft_putstr_printf("0x");
	count += ft_putnbr_pointer(n);
	return (count);
}

size_t	ft_intlen(int c)
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

size_t	ft_itoa(int n)
{
	char			*ptr;
	unsigned int	len_n;
	long int		m;

	m = n;
	len_n = ft_intlen(m);
	if (!(ptr = (char *)malloc(sizeof(char) * (len_n + 1))))
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
	ft_putstr_printf(ptr);
	free(ptr);
	return (ft_intlen(n));
}

size_t	ft_u_intlen(unsigned int c)
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

size_t	ft_u_itoa(unsigned int n)
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
	ft_putstr_printf(ptr);
	free(ptr);
	return (ft_u_intlen(n));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_switch(char conversion, va_list ap)
{
	if (conversion == 'c')
        return (ft_putchar(va_arg(ap, int)));
	else if (conversion == 's')
		return (ft_putstr_printf(va_arg(ap, char*)));
	else if (conversion == 'p')
		return (ft_str_putnbr_pointer(va_arg(ap, unsigned long)));
	else if (conversion == 'd' || conversion == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (conversion == 'u')
		return (ft_u_itoa(va_arg(ap, unsigned int)));
	else if (conversion == 'x')
		return (ft_putnbr_hex(va_arg(ap, unsigned int)));
	else if (conversion == 'X')
		return (ft_putnbr_HEX(va_arg(ap, unsigned int)));
    else if (conversion == '%')
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

size_t ft_putstr_printf(char *s)
{
	if (!s)
		s = "(null)";
	write(1, s, ft_strlen(s));
    return (ft_strlen(s));
}
