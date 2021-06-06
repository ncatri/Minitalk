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
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		;
}

void	signal_handler(int signal)
{
	static char	*message = 0;
	static int	bit_count = 0;
	static char	c = 0;

	if (!message) 
		if (init_string(&message) == FAILURE)
			return ;
	if (signal == SIGUSR2)
		c |= 1;
	c <<= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (c)
		{
			message = append_char(&message, c);
			bit_count = 0;
			c = 0;
		}
		else
		{
			ft_putstr_fd(message, 1);
			free(message);
			message = NULL;
		}
	}
}

char	*append_char(char **str_ptr, char c)
{
	char	to_append[2];
	char	*tmp;

	to_append[0] = c;
	to_append[1] = 0;
	printf("to_append: %s\n", to_append);
	tmp = ft_strjoin(*str_ptr, to_append);
	free(*str_ptr);
	printf("str_ptr: %s\n", *str_ptr);
	*str_ptr = tmp;
	return (tmp);	
}

int	init_string(char **str_ptr)
{
	if (!str_ptr)
		return (FAILURE);
	*str_ptr = ft_calloc(sizeof(char), 1);
	if (!*str_ptr)
		return (FAILURE);
	return (SUCCESS);
}
