/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:21:27 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/11/09 18:41:54 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	t;
	size_t	i;

	i = 0;
	t = ft_strlen(s);
	c = ft_calloc(t + 1, 1);
	if (!c)
		return (NULL);
	while (i <= t)
	{
		c[i] = s[i];
		i++;
	}
	return (c);
}
