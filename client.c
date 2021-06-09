#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		server_pid;

	if (argc != 3)
	{
		printf("usage: ./client [pid] [message]\n");
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid < PID_SAFEGUARD || \
			send_string(argv[2], server_pid) == FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	send_string(char *str, int pid)
{
	if (!str)
		return (FAILURE);
	while (*str)
	{
		if (send_letter(*str, pid) == FAILURE)
			return (FAILURE);
		str++;
	}
	if (send_letter('\0', pid) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	send_letter(char c, int pid)
{
	int	i;
	int	signal;

	i = 8;
	while (--i >= 0)
	{
		if ((c >> i) & 1)
			signal = SIGUSR2;
		else
			signal = SIGUSR1;
		if (kill(pid, signal) == -1)
			return (FAILURE);
		usleep(150);
	}
	return (SUCCESS);
}

void	print_bits(char c)
{
	int	i;

	i = -1;
	while (++i < 8)
		printf("%d ", !!((c << i) & 0x80));
	printf("\n");
}
