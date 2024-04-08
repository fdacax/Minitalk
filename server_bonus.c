/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdacax-m <fdacax-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:42:57 by fdacax-m          #+#    #+#             */
/*   Updated: 2024/04/08 20:06:10 by fdacax-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalkbonus.h"
int	bb;

static void	ft_sig_handler(int signal)
{
	if (signal == SIGUSR2)
	{
		bb = bb << 1;
		bb = bb + 1;
	}
	else
		bb = bb << 1;
}

static int	ft_len(void)
{
	int	i;

	bb = 0;
	i = -1;
	while (++i < 32)
		usleep(30000);
	return (bb);
}

static char	*ft_allocate(int len)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < 8)
		{
			if (!usleep(100000))
			{
				free(str);
				return (NULL);
			}
		}
		str[i] = bb;
	}
	str[i] = '\0';
	return (str);
}

void	send_message(char *str, siginfo_t *info, void *context)
{
	(void)context;
	while ()
		kill(info->si_pid, SIGUSR1);
}

int main()
{
	struct sigaction	sa;
	struct sigaction	send;
	pid_t 				pid;
	char				*str;
	int 				len;


	sa.sa_sigaction = &ft_sig_handler;
	send.sa_sigaction = &send_message;
	sigemptyset(&sa.sa_mask);
	sigemptyset(&send.sa_mask);
	send.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("PID:%d\n", pid);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("failed handler\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("failed handler\n");
	while (1)
	{
		pause();
		bb = 0;
		len = ft_len();
		str = ft_allocate(len);
		write(1, str, len);
		free(str);

	}
}