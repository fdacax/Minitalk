/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:31:39 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/11/06 18:41:00 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_conditions(const char *format, va_list arg, int *i)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				ft_putchar(va_arg(arg, int), i);
			if (*format == 's')
				ft_putstr(va_arg(arg, char *), i);
			if (*format == 'i' || *format == 'd' || *format == 'u')
				ft_choose(*format, va_arg(arg, int), i);
			if (*format == 'x' || *format == 'X' || *format == 'p')
				ft_check_format(*format, arg, i);
			if (*format == '%')
				ft_putchar('%', i);
		}
		else
			ft_putchar(*format, i);
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, format);
	ft_conditions(format, arg, &i);
	va_end(arg);
	return (i);
}
