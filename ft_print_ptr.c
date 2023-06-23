#include "ft_printf.h"

int	calc_ptr_len(unsigned long num)
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

int	ft_print_ptr(void *ptr)
{
	int	calc_length;
    unsigned long ptr_cast; 

    ptr_cast = (unsigned long)ptr;
	calc_length = 0;
	write(1, "0x", 2);
    calc_length += 2;
	if (ptr == 0)
		calc_length += write(1, "0", 1);
	else
	{
        calc_length += calc_ptr_len(ptr_cast);
		ft_putnbr_base(ptr_cast, "0123456789abcdef");
	}
	return (calc_length);
}