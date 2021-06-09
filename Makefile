CC = clang
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

# detecting os to compile on Linux
UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
COMPIL = $(CC) $(CFLAGS) -I$(LIBFT)/includes -I.
else
COMPIL = $(CC) $(CFLAGS) -I$(LIBFT)/includes -I. -L$(LIBFT) -lft
endif

LIBFT = libft

all: libft_ server client

ifeq ($(UNAME), Linux)
server: server.c minitalk.h $(LIBFT)/$(LIBFT).a
	 $(COMPIL) server.c -o server -L$(LIBFT) -lft

client: client.c minitalk.h $(LIBFT)/$(LIBFT).a
	$(COMPIL) client.c -o client -L$(LIBFT) -lft
else
server: server.c minitalk.h $(LIBFT)/$(LIBFT).a
	 $(COMPIL) server.c -o server

client: client.c minitalk.h $(LIBFT)/$(LIBFT).a
	$(COMPIL) client.c -o client
endif

libft_:
	$(MAKE) -C $(LIBFT)

clean:
	$(RM) -r server.dSYM
	$(RM) -r client.dSYM

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) server
	$(RM) client


re: fclean all

.PHONY: all clean fclean re
