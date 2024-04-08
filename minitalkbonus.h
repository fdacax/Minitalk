/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalkbonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 20:04:57 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/04 20:04:57 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALKBONUS_H
#define MINITALKBONUS_H

#include "libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

static char	*ft_allocate(int len);
static int	ft_len(void);
static char	*ft_allocate(int len);
void	send_message(int signal, siginfo_t *info, void *context);

#endif
