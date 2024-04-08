/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:29:44 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/03/19 17:29:44 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit(pid_t server_pid, int bit)
{
	if (bit == 0)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

static void	send_len(pid_t server_pid, unsigned int len)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		send_bit(server_pid, (len >> i) & 1);
		usleep(150);
		i--;
	}
}

static void	send_string(pid_t server_pid, const char *str)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			send_bit(server_pid, (*str >> i) & 1);
			usleep(150);
			i--;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	pid_t		server_pid;
	const char	*message;

	if (argc != 3)
		return (1);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_len(server_pid, ft_strlen(message));
	send_string(server_pid, message);
	return (0);
}
