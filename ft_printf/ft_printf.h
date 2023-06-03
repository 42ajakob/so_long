/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajakob <ajakob@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:41:52 by ajakob            #+#    #+#             */
/*   Updated: 2023/01/04 02:15:20 by ajakob           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
int		ft_putchar(char s);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
char	*ft_uitoa(unsigned int n);
int		ft_putunbr(unsigned int n);
int		ft_puthexa(char c, unsigned int p);
int		ft_print_mem(char s, unsigned long p);
void	print_order(char s, unsigned long p);
int		hex_ulong_len(unsigned long p);

#endif