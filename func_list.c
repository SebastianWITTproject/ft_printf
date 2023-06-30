/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: switt <switt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 22:58:51 by switt             #+#    #+#             */
/*   Updated: 2023/06/30 17:01:00 by switt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int	printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = printstr(num);
	free(num);
	return (len);
}

int	percent(void)
{
	write(1, "%", 1);
	return (1);
}
