#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				content;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// utils.c
long				ft_atoi2(const char *nptr);
int					is_str_digit(char *str);
int	parse_input(int argc, char **args, t_stack **stack);

// stack.c
t_stack				*stack_new(int val);
void				stack_push(t_stack **stack, t_stack *node);
t_stack				*stack_pop(t_stack **stack);
size_t				stack_size(t_stack **stack);
void				stack_iter(t_stack **stack, void (*f)(void *));

// operations.c
int					find_node(t_stack **stack, int val);

// debug.c
void				printval(void *node);

#endif
