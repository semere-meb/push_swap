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

typedef struct s_stack
{
	int				index;
	int				content;
	int				cost;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

// sort.c
void				sort(t_stack **stack_a, t_stack **stack_b);

// utils.c
long				ft_atol(const char *nptr);
int					is_str_digit(char *str);
int					parse_input(int argc, char **args, t_stack **stack);
int					is_sorted(t_stack **stack_a);

// stack.c
t_stack				*stack_new(int val);
void				stack_push(t_stack **stack, t_stack *node);
t_stack				*stack_pop(t_stack **stack);
int					stack_size(t_stack **stack);
void				stack_iter(t_stack **stack, void (*f)(void *));
t_stack				*stack_val(t_stack **stack, int index);
int					stack_index(t_stack **stack, int val);
void				stack_swap(t_stack **stack);
void				stack_rotate(t_stack **stack);
void				stack_reverse(t_stack **stack);

// operations.c
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_b, t_stack **stack_a);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

// debug.c
void				printval(void *node);

#endif
