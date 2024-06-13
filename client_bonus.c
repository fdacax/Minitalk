/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:53:48 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/06/13 14:53:48 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_bit(pid_t server_pid, int letter)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (letter & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		letter >>= 1;
		bits++;
		usleep(150);
	}
}

void	extract_byte(pid_t server_pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
		send_bit(server_pid, message[i++]);
	send_bit(server_pid, '\0');
}

void	client_signal_handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
		ft_printf("Message completely sent\n");
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	struct sigaction	act;
	char				*message;
	pid_t				server_pid;

	act.sa_sigaction = &client_signal_handler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		ft_printf("Erro to send signal back to client.");
	if (argc != 3)
		return (1);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	extract_byte(server_pid, message);
	return (0);
}
