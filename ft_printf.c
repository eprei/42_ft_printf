/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:38:28 by epresa-c          #+#    #+#             */
/*   Updated: 2021/12/17 17:40:39 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
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

int	ft_switch(char conversion, va_list ap)
{
	if (conversion == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (conversion == 's')
		return (ft_putstr_printf(va_arg(ap, char *)));
	else if (conversion == 'p')
		return (ft_str_putnbr_pointer(va_arg(ap, unsigned long)));
	else if (conversion == 'd' || conversion == 'i')
		return (ft_putstr_itoa(ft_itoa(va_arg(ap, int))));
	else if (conversion == 'u')
		return (ft_u_itoa(va_arg(ap, unsigned int)));
	else if (conversion == 'x')
		return (ft_putnbr_hex_min(va_arg(ap, unsigned int)));
	else if (conversion == 'X')
		return (ft_putnbr_hex_maj(va_arg(ap, unsigned int)));
	else if (conversion == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putstr_printf(char *s)
{
	if (!s)
		s = "(null)";
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
