/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: switt <switt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:58:58 by switt             #+#    #+#             */
/*   Updated: 2023/06/28 22:59:00 by switt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static int	size(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static int	convert(int len, char *string, unsigned int nbr)
{
	if (nbr < 0)
	{
		nbr = nbr * -1;
		string[0] = '-';
	}
	while (nbr > 0)
	{
		string[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (0);
}

char	*ft_un_itoa(unsigned int nbr)
{
	char	*string;
	int		len;

	len = size(nbr);
	if (nbr == 0)
	{
		string = (char *)malloc(2);
		if (!string)
			return (0);
		string[0] = '0';
		string[1] = '\0';
		return (string);
	}
	string = (char *)malloc(size(nbr) + 1);
	if (!string)
		return (0);
	string[len] = '\0';
	len--;
	convert(len, string, nbr);
	return (string);
}

int	ft_print_unsigned(unsigned int nbr)
{
	int		calc_length;
	char	*num;

	calc_length = 0;
	if (nbr == 0)
		calc_length += write(1, "0", 1);
	else
	{
		num = ft_un_itoa(nbr);
		calc_length += printstr(num);
		free(num);
	}
	return (calc_length);
}
