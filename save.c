#include "minitalk.h"

int	bb;

static void	ft_sig_handler(int signal)
{
	if (signal == SIGUSR2)
	{
		bb = bb << 1;
		bb = bb + 1;
	}
	else if (signal == SIGUSR1)
		bb = bb << 1;
	else
		exit(0);
}

static int	ft_len(void)
{
	int	i;
	int	len;

	i = 30;
	while (i >= 0)
	{
		usleep(205);
		i--;
	}
	len = bb;
	bb = 0;
	return (len);
}

static char	*ft_allocate(int len)
{
	unsigned char	byte;
	char			*str;
	int				i;
	int				j;

	str = calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		byte = 0;
		j = 0;
		while (j < 8)
		{
			pause();
			byte |= bb << (7 - j);
			j++;
		}
		str[i] = byte;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	main(void)
{
	pid_t	pid;
	int		len;
	char	*str;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	while (1)
	{
		pause();
		bb = 0;
		len = ft_len();
		str = ft_allocate(len);
		write (1, str, len);
		free (str);
	}
}
