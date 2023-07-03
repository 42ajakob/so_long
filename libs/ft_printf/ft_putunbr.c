/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:09:04 by ajakob            #+#    #+#             */
/*   Updated: 2022/12/30 04:09:43 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_nbr_len(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	char	c;
	int		i;

	i = find_nbr_len(n);
	if (n >= 10)
	{
		ft_putunbr(n / 10);
		c = n % 10 + 48;
		ft_putchar(c);
	}
	else
	{
		c = n + 48;
		ft_putchar(c);
	}
	return (i);
}
