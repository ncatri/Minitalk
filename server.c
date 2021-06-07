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
	static char				**message = 0;
	static int				bit_count = 0;
	static unsigned char	c = 0;

	if (!message) 
		message = init_strptr();
	if (!message)
		return ;
	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	printf("signal: %d, bit_count: %d, bits: ", signal, bit_count);
	print_bits(c);
	bit_count++;
	if (bit_count == 8)
	{
		if (c)
		{
			printf("in signal_handler, c: %c\n", c);
			*message = append_char(*message, c);
			bit_count = 0;
			c = 0;
		}
		else
		{
			ft_putstr_fd(*message, 1);
			free(*message);
			free(message);
			message = NULL;
		}
	}
}

char	*append_char(char *str, char c)
{
	char	to_append[2];
	char	*tmp;

	printf("in append_char, c: %c\n", c);
	to_append[0] = c;
	to_append[1] = '\0';
	printf("to_append: %s\n", to_append);
	tmp = ft_strjoin(str, to_append);
	free(str);
	printf("tmp: %s\n", tmp);
	return (tmp);	
}

char	**init_strptr(void)
{
	char	**str;

	str = NULL;
	str = malloc(sizeof(char*));
	if (str)
	{
		*str = ft_strdup("");
		if (!*str)
			return (NULL);
	}
	return (str);
}

void	print_bits(char c)
{
	int i;

	i = -1;
	while (++i < 8)
		printf("%d ", !!((c << i) & 0x80));
	printf("\n");
}
