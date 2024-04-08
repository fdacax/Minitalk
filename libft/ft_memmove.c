/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:59:04 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/11/07 18:32:03 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cdest;
	unsigned char	*csrc;

	cdest = (unsigned char *) dest;
	csrc = (unsigned char *) src;
	if (csrc > cdest)
		ft_memcpy(dest, src, n);
	if (csrc < cdest)
	{
		while (n > 0)
		{
			cdest[n - 1] = csrc[n - 1];
			n--;
		}
	}
	return (cdest);
}
