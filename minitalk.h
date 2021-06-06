#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"

enum e_returns{SUCCESS, FAILURE};

/* client */

int		send_letter(char c, int pid);
int		send_string(char *str, int pid);

/* server */

void	signal_handler(int signal);
int		init_string(char **str_ptr);
char	*append_char(char **str_ptr, char c);

#endif
