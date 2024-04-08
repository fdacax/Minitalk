/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:32:11 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/11/07 18:40:47 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return (&str[i]);
	while (--i >= 0)
		if (str[i] == (unsigned char)c)
			return (&str[i]);
	return (NULL);
}
