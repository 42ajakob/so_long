/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:33:12 by ajakob            #+#    #+#             */
/*   Updated: 2023/01/27 14:52:54 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int		i;
	char	c;

	i = 0;
	if (s == 0)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		c = s[i];
		ft_putchar(c);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	*s;
	int		i;

	s = ft_itoa(n);
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	free(s);
	return (i);
}

int	ft_print_mem(char s, unsigned long p)
{
	ft_putstr("0x");
	print_order(s, p);
	return (hex_ulong_len(p) + 2);
}
