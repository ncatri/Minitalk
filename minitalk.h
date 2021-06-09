#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"

enum e_returns{SUCCESS, FAILURE};

# define PID_SAFEGUARD (100)

/* client */

int		send_letter(char c, int pid);
int		send_string(char *str, int pid);

/* server */

void	signal_handler(int signal);
char	**init_strptr(void);
char	*append_char(char *str, char c);

/* debug */
void	print_bits(char c);

#endif
