/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 04:00:54 by semebrah          #+#    #+#             */
/*   Updated: 2026/01/22 04:01:18 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define UP 1
# define DOWN 0

typedef struct s_node
{
	int				index;
	int				content;
	int direction;
	struct s_node	*target;
	int				cost;
	int				cost_to_top;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				length;
	int				min;
	int				min_index;
	int				max;
	int				max_index;
	int cheapest_index;
}					t_stack;

// sort.c
void				sort(t_stack *stack_a, t_stack *stack_b);

// utils.c
long				ft_atol(const char *nptr);
int					is_str_digit(char *str);
int					parse_input(int argc, char **args, t_stack *stack);
int					is_sorted(t_stack *stack_a);
int					get_min(t_stack *stack);
int					get_max(t_stack *stack);
void				update_stacks(t_stack *stack_a, t_stack *stack_b);

// stack.c
t_node				*node_new(int val);
t_node				*node_at(t_stack *stack, int index);
void				stack_push(t_stack *stack, t_node *node);
t_node				*stack_pop(t_stack *stack);
int					stack_size(t_stack *stack);
void				stack_iter(t_stack *stack, void (*f)(void *));
int					node_val(t_stack *stack, int index);
int					node_index(t_stack *stack, int val);
void				stack_swap(t_stack *stack);
void				stack_rotate(t_stack *stack);
void				stack_reverse(t_stack *stack);

// operations.c
void				sa(t_stack *stack_a, t_stack *stack_b);
void				sb(t_stack *stack_a, t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a, t_stack *stack_b);
void				rb(t_stack *stack_a, t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a, t_stack *stack_b);
void				rrb(t_stack *stack_a, t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);

// debug.c
void				printval(void *node);
void				stacks_info(t_stack *stack_a, t_stack *stack_b);

#endif
