#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

size_t  ft_putstr_printf(char *s);
int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
size_t  ft_switch(char conversion, va_list ap);
int     ft_putchar(char c);
size_t	ft_u_itoa(unsigned int n);
size_t	ft_u_intlen(unsigned int c);
size_t	ft_itoa(int n);
size_t	ft_intlen(int c);
size_t	ft_putnbr_hex(unsigned int n);
size_t	ft_putnbr_HEX(unsigned int n);
size_t	ft_putnbr_pointer(unsigned long n);
size_t	ft_str_putnbr_pointer(unsigned long n);

#endif