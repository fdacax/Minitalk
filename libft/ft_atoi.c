/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:54:17 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/10/17 17:17:15 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	toy;
	int	less;

	less = 1;
	toy = 0;
	i = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			less = less * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		toy = toy * 10 + (nptr[i] - '0');
		i++;
	}
	return (toy * less);
}
