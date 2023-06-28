/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: switt <switt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:58:09 by switt             #+#    #+#             */
/*   Updated: 2023/06/28 23:00:11 by switt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	calc_hex_len(unsigned int num)
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
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
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
