#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "minitalk.h"

int main(int argc, char **argv)
{
	int		server_pid;

	if (argc != 3)
	{
		printf("usage: ./client [pid] [message]\n");
		return (EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (send_string(argv[2], server_pid) == FAILURE)
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
		if ((c >> i) & 1) // we got a 1
			signal = SIGUSR2;
		else
			signal = SIGUSR1;
		if (kill(pid, signal) == -1)
			return (FAILURE);
		usleep(100);
	}
	return (SUCCESS);
}
