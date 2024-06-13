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

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;

	if (argc != 3)
		return (1);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	extract_byte(server_pid, message);
}
