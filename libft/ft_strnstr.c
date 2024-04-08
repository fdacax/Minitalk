/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:06:15 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/10/16 18:52:31 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	size_t			j;

	str1 = (unsigned char *)big;
	str2 = (unsigned char *)little;
	i = 0;
	j = 0;
	if (str2[0] == '\0')
		return ((char *)str1);
	while (str1[i] && i < len)
	{
		while ((str1[i + j] == str2[j]) && str2[j] && i + j < len)
			j++;
		if (str2[j] == '\0')
			return ((char *)str1 + i);
		j = 0;
		i++;
	}
	return (NULL);
}
