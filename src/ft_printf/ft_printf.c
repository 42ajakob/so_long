/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:18:56 by ajakob            #+#    #+#             */
/*   Updated: 2023/01/04 02:51:17 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_arg_return_len(const char *s, va_list arg)
{
	int	i;

	i = 0;
	if (*s == 'c')
		i += ft_putchar(va_arg(arg, int));
	else if (*s == 's')
		i += ft_putstr(va_arg(arg, char *));
	else if (*s == 'p')
		i += ft_print_mem(*s, va_arg(arg, unsigned long));
	else if (*s == 'd' || *s == 'i')
		i += ft_putnbr(va_arg(arg, int));
	else if (*s == 'u')
		i += ft_putunbr(va_arg(arg, unsigned int));
	else if (*s == 'x' || *s == 'X')
		i += ft_puthexa(*s, va_arg(arg, unsigned int));
	else if (*s == '%')
		i += ft_putchar('%');
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	arg;

	count = 0;
	i = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			count++;
		}
		else
		{
			i++;
			count += print_arg_return_len(&s[i], arg);
		}
		i++;
	}
	va_end(arg);
	return (count);
}
