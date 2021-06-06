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
server: server.c
	 $(COMPIL) server.c -o server -L$(LIBFT) -lft

client: client.c
	$(COMPIL) client.c -o client -L$(LIBFT) -lft
else
server: server.c
	 $(COMPIL) server.c -o server

client: client.c
	$(COMPIL) client.c -o client
endif

libft_:
	$(MAKE) -C $(LIBFT)

clean:
	$(RM) server
	$(RM) client
	$(RM) -r server.dSYM
	$(RM) -r client.dSYM

re: clean all

.PHONY: all clean re
