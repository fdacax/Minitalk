/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 18:09:31 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/10/31 16:08:40 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charcompare(char const s2, char const *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == s2)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_start(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_charcompare(s1[i], s2) == 1)
			i++;
		else
			break ;
	}
	return (i);
}

static int	ft_final(char const *s1, char const *s2)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (ft_charcompare(s1[i], s2) == 1)
			i--;
		else
			break ;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		truelen;
	int		truestart;
	int		truefinal;

	i = 0;
	truefinal = ft_final(s1, set);
	truestart = ft_start(s1, set);
	truelen = (truefinal - truestart + 1);
	if (truelen < 0)
		truelen = 0;
	str = ft_calloc(truelen + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (truestart <= truefinal)
	{
		str[i] = s1[truestart];
		i++;
		truestart++;
	}
	str[i] = '\0';
	return (str);
}
