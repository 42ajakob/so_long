/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:06:28 by ajakob            #+#    #+#             */
/*   Updated: 2023/01/04 02:15:05 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hexa(char s, unsigned short p)
{
	if (p >= 0 && p <= 9)
		p += 48;
	else if (p >= 10 && p <= 16 && s == 'X')
		p += 55;
	else
		p += 87;
	ft_putchar(p);
}

int	hex_ulong_len(unsigned long p)
{
	int	i;

	i = 1;
	while (p / 16 != 0)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

void	print_order(char s, unsigned long p)
{
	if (p >= 16)
	{
		print_order(s, p / 16);
		print_order(s, p % 16);
	}
	else
	{
		print_hexa(s, p);
	}
}

int	ft_puthexa(char s, unsigned int p)
{
	print_order(s, p);
	return (hex_ulong_len(p));
}
