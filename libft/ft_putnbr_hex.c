/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:56:42 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/11/06 18:47:50 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_check_format(char format, va_list arg, int *i)
{
	unsigned long	nb;

	if (format == 'p')
	{
		nb = va_arg(arg, unsigned long);
		if (nb == 0)
		{
			ft_putstr("(nil)", i);
			return ;
		}
		ft_putstr("0x", i);
		ft_put_pointer(nb, i);
	}
	else
		ft_put_hex(format, va_arg(arg, unsigned int), i);
}

void	ft_put_hex(char format, unsigned int nb, int *i)
{
	char			*hex;
	unsigned int	j;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nb >= 16)
		ft_put_hex(format, nb / 16, i);
	j = nb % 16;
	ft_putchar(hex[j], i);
}

void	ft_put_pointer(unsigned long nb, int *i)
{
	char			*hex;
	unsigned int	j;

	hex = "0123456789abcdef";
	if (nb >= 16)
		ft_put_pointer(nb / 16, i);
	j = nb % 16;
	ft_putchar(hex[j], i);
}
