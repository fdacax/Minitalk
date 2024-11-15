/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:31:26 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/03/19 17:31:26 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*g_msg = NULL;

unsigned char	*str_join_c(unsigned char *msg, unsigned char c)
{
	unsigned char	*str;
	size_t			i;

	if (!msg)
	{
		str = ft_calloc(2, sizeof(unsigned char));
		if (!str)
			return (NULL);
		str[0] = c;
		return (str);
	}
	i = ft_strlen((char *)msg);
	str = ft_calloc(i + 2, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, msg, i);
	str[i] = c;
	free(msg);
	return (str);
}

void	making_str( int *byte)
{
	unsigned char			c;
	int						i;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c |= (byte[i] << i);
		i++;
	}
	if (c == '\0')
	{
		ft_printf("%s", g_msg);
		free(g_msg);
		g_msg = NULL;
	}
	else
		g_msg = str_join_c(g_msg, c);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	byte[8];
	static int	bit = 0;

	(void)info;
	(void)context;
	if (signal == SIGUSR2)
		byte[bit] = 1;
	else if (signal == SIGUSR1)
		byte[bit] = 0;
	else
	{
		if (g_msg)
		{
			free(g_msg);
			g_msg = NULL;
		}
		ft_printf("\nReceived SIGINT. Exiting...\n");
		exit(0);
	}
	bit++;
	if (bit == 8)
	{
		making_str(byte);
		bit = 0;
	}
}

void	error_handler(int flag)
{
	if (flag == 1)
	{
		perror("Failed to set up signal handler");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	act.sa_sigaction = &signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("The process ID is: %i\n", pid);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		error_handler(1);
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		error_handler(1);
	if (sigaction(SIGINT, &act, NULL) == -1)
		error_handler(1);
	while (1)
	{
		usleep(10);
		pause();
	}
}
