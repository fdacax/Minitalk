/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 22:01:38 by fdacax-m          #+#    #+#             */
/*   Updated: 2023/10/31 16:12:48 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_firstlist(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	void	*c;

	c = f(lst->content);
	ptr = ft_lstnew(c);
	if (!ptr)
	{
		del(c);
		return (NULL);
	}
	return (ptr);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*start;
	void	*c;

	if (!lst)
		return (NULL);
	ptr = ft_firstlist(lst, f, del);
	if (ptr == NULL)
		return (NULL);
	start = ptr;
	while (lst->next)
	{
		lst = lst->next;
		c = f(lst->content);
		ptr->next = ft_lstnew(c);
		if (!ptr->next)
		{
			del(c);
			ft_lstclear(&start, del);
			return (NULL);
		}
		ptr = ptr->next;
	}
	return (start);
}
