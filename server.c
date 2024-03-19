#include "minitalk.h"

char	*str = NULL;

static void	ft_sig_handler(int signal)
{
	static int	bit_index = 0;
	static unsigned char byte = 0;

	if (signal == SIGUSR2)
		byte |= (1 << (7 - bit_index)); // Defina o bit apropriado como 1
	else if (signal == SIGUSR1)
		byte &= ~(1 << (7 - bit_index)); // Defina o bit apropriado como 0
	else
		exit(0);
	bit_index++;
	if (bit_index == 8) // Se todos os bits foram lidos
	{
		if (!str)
			str = ft_strdup(""); // Inicialize a string se for a primeira vez
		str = ft_strjoin_free(str, ft_chr_to_str(byte)); // Adicione o byte à string
		byte = 0; // Reinicie o byte
		bit_index = 0; // Reinicie o índice do bit
	}
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
	len = ft_strlen(str); // Obtenha o comprimento da string global
	return (len);
}

int	main(void)
{
	pid_t	pid;
	int		len;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, ft_sig_handler);
	signal(SIGUSR2, ft_sig_handler);
	while (1)
	{
		pause();
		len = ft_len();
		write(1, str, len); // Escreva a string global
	}
}
