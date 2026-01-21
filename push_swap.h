#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_stack
{
	struct s_stack	*prev;
	void			*content;
	struct s_stack	*next;
}					t_stack;

long				ft_atoi2(const char *nptr);
int					is_str_digit(char *str);
ssize_t				find(int *numbers, size_t size, int val);

void				stack_push(t_stack **lst, t_stack *new_node);
t_stack				*stack_pop(t_stack **lst);
t_stack				*stack_new(void *content);
size_t				stack_size(t_stack **stack);
void				stack_iter(t_stack **stack, void (*f)(void *));

#endif
