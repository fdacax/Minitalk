/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:33:27 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/11/09 19:08:31 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freemem(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(str[i++]);
	free(str);
}

static void	ft_putwords(char **str, char const *sub, char c)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	j = 0;
	i = 0;
	while (sub[i])
	{
		while (sub[i] == c)
			i++;
		k = i;
		if (sub[k] == '\0')
			break ;
		while (sub[i] != c && sub[i])
			i++;
		str[j] = ft_substr(sub, k, i - k);
		j++;
	}
	str[j] = NULL;
}

static int	ft_countwords(char const *str, char c)
{
	int	i;
	int	security;

	security = 1;
	i = 0;
	while (*str)
	{
		if (*str == c && security == 0)
		{
			security = 1;
		}
		else if (*str != c && security == 1)
		{
			i++;
			security = 0;
		}
		str++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	str = ft_calloc(ft_countwords(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	ft_putwords(str, s, c);
	while (i < ft_countwords(s, c))
	{
		if (str[i] == NULL)
		{
			ft_freemem(str, ft_countwords(s, c));
			return (NULL);
		}
		i++;
	}
	return (str);
}
