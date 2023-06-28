/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: switt <switt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:38:54 by seb               #+#    #+#             */
/*   Updated: 2023/06/28 21:49:12 by switt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(va_list *args, const char format)
{
	int	calc_length;

	calc_length = 0;
	if (format == 's')
		calc_length += printstr(va_arg(*args, char *));
	else if (format == 'c')
		calc_length += printchar(va_arg(*args, int));
	else if (format == 'd' || format == 'i')
		calc_length += ft_printnbr(va_arg(*args, int));
	else if (format == 'x' || format == 'X')
		calc_length += ft_print_hex(va_arg(*args, unsigned int), format);
    else if (format == 'u')
		calc_length += ft_print_unsigned(va_arg(*args, unsigned int));
    else if (format == '%')
		calc_length += percent();
    else if (format == 'p')
		calc_length += ft_print_ptr((unsigned long long int)va_arg(*args, void *));
	return (calc_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		calc_length;

	i = 0;
	calc_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			calc_length += ft_formats(&args, str[i + 1]);
			i++;
		}
		else
			calc_length += printchar(str[i]);
		i++;
	}
	va_end(args);
	return (calc_length);
}
