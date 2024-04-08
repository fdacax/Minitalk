/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:42:29 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/08 20:06:23 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"

void	send_bit(pid_t server_pid, int bit)
{
	if (bit == 0)
		kill(server_pid, SIGUSR1);
	else
		kill(server_pid, SIGUSR2);
}

void	sig_handler_server(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;

	if(signum == SIGUSR1)
		ft_printf("SIGNAL RECEIVED\n");
	exit(EXIT_SUCCESS);
}

void	send_len(pid_t server_pid, unsigned int len)
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

int main(int argc, char **argv)
{
	pid_t 				server_pid;
	struct sigaction	sa;
	const char 			*message;

	if(argc != 3)
		return (0);
	sa.sa_sigaction = &sig_handler_server;
	sigemptyset(&sa.sa_mask);
	if(sigaction(SIGUSR1, &sa, NULL))
		ft_printf("Erro to send signal back");
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	send_len(server_pid, ft_strlen(message));
	send_string(server_pid, message);
	return (0);
}