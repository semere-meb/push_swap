NAME = push_swap

LIBFTDIR = libft
LIBFT = libft.a

SRCS = operations.c push_swap.c stack.c utils.c sort.c update.c debug.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFTDIR)/$(LIBFT) .
	$(CC) $(CFLAGS) $(OBJS) -L. -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(LIBFT)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
