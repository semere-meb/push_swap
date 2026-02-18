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

# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
	int				val;
	int				index;
	int				c_cost;
	int				n_cost;
	int				t_cost;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				length;
	t_node			*max;
	t_node			*min;
	t_node			*cheapest;
}					t_stack;

// sort.c
void				sort(t_stack *stack_a, t_stack *stack_b);

// utils.c
long				ft_atol(const char *nptr);
int					parse_input(int argc, char **args, t_stack *stack);
int					is_sorted(t_stack *stack_a);
int					min(int a, int b);
int					abs(int a);

// update.c
void				set_targets(t_stack *stack_a, t_stack *stack_b);
void				update_index(t_stack *stack);

// stack.c
t_node				*node_new(int val);
void				stack_push(t_stack *stack, t_node *node);
t_node				*stack_pop(t_stack *stack);
void				stack_swap(t_stack *stack);
void				stack_rotate(t_stack *stack);

// stack2.c
void				stack_reverse(t_stack *stack);
int					stack_size(t_stack *stack);
void				stack_iter(t_stack *stack, void (*f)(void *));
int					node_val(t_stack *stack, int index);
int					node_index(t_stack *stack, int val);

// operations.c
int					swap(t_stack *sa, t_stack *sb, char s);
int					push(t_stack *sa, t_stack *sb, char s);
int					rotate(t_stack *sa, t_stack *sb, char s);
int					reverse(t_stack *sa, t_stack *sb, char s);

#endif
