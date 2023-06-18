/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seb <seb@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 12:34:58 by switt             #+#    #+#             */
/*   Updated: 2023/06/18 23:52:36 by seb              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i ++;
	}
	return (i);
}

static int	check(char *base, char c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (base [i] == c)
		{
			return (0);
		}
	i ++;
	}
	return (1);
}

static int	isvalid(char *base)
{
	int	i;

	i = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
	{
		return (0);
	}
	while (base [i] != '\0')
	{
		if (base[i] <= 32 || base[i] == 127 || base[i] == '+' || base[i] == '-')
		{
			return (0);
		}
	i ++;
	}
	i = 0;
	while (base [i] != '\0')
	{
		if (!check(base, base [i], i))
		{
			return (0);
		}	
	i ++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			size;
	long int	nb;

	size = ft_strlen(base);
	nb = nbr;
	if (isvalid(base))
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb < size)
			write(1, &base[nb], 1);
		if (nb >= size)
		{
			ft_putnbr_base(nb / size, base);
			ft_putnbr_base(nb % size, base);
		}
	}
}
