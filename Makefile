CC = clang
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
COMPIL = $(CC) $(CFLAGS) -I$(LIBFT)/includes -I. -L$(LIBFT) -lft

LIBFT = libft

all: libft_ server client

server: server.c
	 $(COMPIL) server.c -o server

client: client.c
	$(COMPIL) client.c -o client

libft_:
	$(MAKE) -C $(LIBFT)

clean:
	$(RM) server
	$(RM) client
	$(RM) -r server.dSYM
	$(RM) -r client.dSYM

re: clean all

.PHONY: all clean re
