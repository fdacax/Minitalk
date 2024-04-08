/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:33:42 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/11/09 19:04:40 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			i;
	size_t			all;

	all = nmemb * size;
	i = 0;
	ptr = malloc(all);
	if (!ptr)
		return (NULL);
	while (i < all)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
