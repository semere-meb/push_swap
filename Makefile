NAME = push_swap
B_NAME = checker

LIBFTDIR = libft
LIBFT = libft.a

SHARED = operations.c stack.c stack2.c utils.c utils2.c sort.c update.c

SRCS = $(SHARED) push_swap.c
B_SRCS = $(SHARED) bonus_checker.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFTDIR)/$(LIBFT) .
	$(CC) $(CFLAGS) $(OBJS) -L. -lft -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(B_OBJS) $(LIBFT)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME) $(B_NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

bonus: $(B_NAME)

$(B_NAME): $(B_OBJS) $(LIBFT)
	cp $(LIBFTDIR)/$(LIBFT) .
	$(CC) $(CFLAGS) $(B_OBJS) -L. -lft -o $@

.PHONY: all clean fclean re
