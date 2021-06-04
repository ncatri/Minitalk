#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "minitalk.h"

int main(void)
{
	int pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, &function1);
	while (1)
		;
}

void	function1(int arg)
{
	(void)arg;

	ft_putstr_fd("in sigusr1\n", 1);
}
