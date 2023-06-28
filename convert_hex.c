#include "ft_printf.h"

int	calc_hex_len(unsigned	int num)
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

int	ft_print_hex(unsigned int num, const char caps)
{
	if (caps == 'X')
    {
        ft_putnbr_base(num, "0123456789ABCDEF");
    }
    else if (caps == 'x')
    {
        ft_putnbr_base(num, "0123456789abcdef");
    }
	return (calc_hex_len(num));
}