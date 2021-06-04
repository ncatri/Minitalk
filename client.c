#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "minitalk.h"

int main(int argc, char **argv)
{
	int		server_pid;
	char	*message;
	char	octet[8];

	if (argc != 3)
	{
		printf("usage: ./client [pid] [message]\n");
		return (0);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
	{
		encode(*message, server_pid);
		message++;
	}
	printf("%c\n", octet[0]);
	kill(server_pid, SIGUSR1);
}

void	encode(char c, int pid)
{
	(void)pid;
	int	i;	

	i = 8;
	while (--i >= 0)
		printf("%d ", (c >> i) & 0x01);
	write(1, "\n", 1);
}
