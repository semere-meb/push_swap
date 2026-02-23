NAME = push_swap
B_NAME = checker

LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a

SHARED = operations.c stack.c stack2.c utils.c utils2.c sort.c update.c

SRCS = $(SHARED) push_swap.c
B_SRCS = $(SHARED) bonus_checker.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(B_NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L $(LIBFTDIR) -lft -o $@

$(B_NAME): $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_OBJS) -L $(LIBFTDIR) -lft -o $@

clean:
	rm -f $(OBJS) $(B_OBJS) $(LIBFT)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME) $(B_NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
