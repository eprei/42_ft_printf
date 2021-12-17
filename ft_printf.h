/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epresa-c <epresa-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:38:58 by epresa-c          #+#    #+#             */
/*   Updated: 2021/12/17 15:48:48 by epresa-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_putstr_printf(char *s);
int		ft_printf(const char *str, ...);
int		ft_strlen(const char *s);
int		ft_switch(char conversion, va_list ap);
int		ft_putchar(char c);
int		ft_u_itoa(unsigned int n);
int		ft_u_intlen(unsigned int c);
int		ft_itoa(int n);
int		ft_intlen(int c);
int		ft_putnbr_hex_min(unsigned int n);
int		ft_putnbr_hex_maj(unsigned int n);
int		ft_putnbr_pointer(unsigned long n);
int		ft_str_putnbr_pointer(unsigned long n);

#endif
