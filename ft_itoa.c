/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:19:11 by switt             #+#    #+#             */
/*   Updated: 2023/06/20 17:44:11 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	size(long int nbr)
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

static int	convert(int len, char *string, long int nbr)
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

char	*ft_itoa(int n)
{
	char		*string;
	long int	nbr;
	int			len;

	nbr = n;
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
