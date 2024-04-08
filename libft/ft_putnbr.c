/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:24:15 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/11/06 18:46:55 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_choose(char format, int nb, int *i)
{
	if (format == 'u')
		ft_formu(nb, i);
	else
		ft_putnbr(nb, i);
}

void	ft_putnbr(int nb, int *i)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		*i = *i + 11;
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', i);
		nb = -nb;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + 48, i);
	else
	{
		ft_putnbr(nb / 10, i);
		ft_putchar((nb % 10) + 48, i);
	}
}

void	ft_formu(unsigned int nb, int *i)
{
	if (nb < 10)
		ft_putchar(nb + 48, i);
	else
	{
		ft_formu(nb / 10, i);
		ft_putchar((nb % 10) + 48, i);
	}
}
