#include "ft_printf.h"
#include <stdio.h>

static int	calc_ptr_len(unsigned long long int num)
{ 
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

static void	ft_putptr_base(unsigned long long int nb)
{
	char *base;

	base = "0123456789abcdef";

		if (nb >= 16)
		{
			ft_putptr_base(nb / 16);
			ft_putptr_base(nb % 16);
		}
		else
			write(1, &base[nb], 1);
}


int	ft_print_ptr(unsigned long long int ptr)
{
	int	calc_length;
	calc_length = 0;
	if (ptr == 0)
	{
		calc_length += write(1, "(nil)", 5);
		return (calc_length);
	}
	write(1, "0x", 2);
    calc_length += 2;
	if (ptr == 0)
		calc_length += write(1, "(nil)", 5);
	else
	{
        calc_length += calc_ptr_len(ptr);
		ft_putptr_base(ptr);
	}
	return (calc_length);
}
