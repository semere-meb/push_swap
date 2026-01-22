/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 04:00:50 by semebrah          #+#    #+#             */
/*   Updated: 2026/01/22 04:01:18 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	stack_swap(stack_a);
}

void	sb(t_stack **stack_b)
{
	stack_swap(stack_b);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*node;

	node = stack_pop(stack_b);
	if (node)
		stack_push(stack_a, node);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	node = stack_pop(stack_a);
	if (node)
		stack_push(stack_b, node);
}

void	ra(t_stack **stack_a)
{
	stack_rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	stack_rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack **stack_a)
{
	stack_reverse(stack_a);
}

void	rrb(t_stack **stack_b)
{
	stack_reverse(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
