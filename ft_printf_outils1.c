#include "ft_printf.h"

int	ft_putnbr_hex_min(unsigned int n)
{
	char	*str;
	int count = 0;
	str = "0123456789abcdef";

	if (n <= 15){
		write(1, &str[n], 1);
		count += 1;
	} else {
		count += ft_putnbr_hex_min(n / 16);
		count += ft_putnbr_hex_min(n % 16);
	}

	return count;
}

int	ft_putnbr_hex_maj(unsigned int n)
{
	char	*str;
	int count = 0;
	str = "0123456789ABCDEF";

	if (n <= 15){
		write(1, &str[n], 1);
		count += 1;
	} else {
		count += ft_putnbr_hex_maj(n / 16);
		count += ft_putnbr_hex_maj(n % 16);
	}

	return count;
}

int	ft_putnbr_pointer(unsigned long n)
{
	char	*str;
	int count = 0;
	str = "0123456789abcdef";

	if (n <= 15){
		write(1, &str[n], 1);
		count += 1;
	} else {
		count += ft_putnbr_pointer(n / 16);
		count += ft_putnbr_pointer(n % 16);
	}

	return count;
}

int	ft_str_putnbr_pointer(unsigned long n)
{
	int count = 0;

	count += ft_putstr_printf("0x");
	count += ft_putnbr_pointer(n);

	return count;
}
