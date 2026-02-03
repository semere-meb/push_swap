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

#include "libft/libft.h"
#include "push_swap.h"

void	sa(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap(stack_a);
	update_stacks(stack_a, stack_b);
	ft_printf("@sa\n");
	stacks_info(stack_a, stack_b);
}

void	sb(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap(stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("@sb\n");
	stacks_info(stack_a, stack_b);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, stack_b);
	sb(stack_a, stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("@ss\n");
	stacks_info(stack_a, stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = stack_pop(stack_b);
	if (node)
		stack_push(stack_a, node);
	update_stacks(stack_a, stack_b);
	ft_printf("@pa\n");
	stacks_info(stack_a, stack_b);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = stack_pop(stack_a);
	if (node)
		stack_push(stack_b, node);
	update_stacks(stack_a, stack_b);
	ft_printf("@pb\n");
	stacks_info(stack_a, stack_b);
}

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate(stack_a);
	update_stacks(stack_a, stack_b);
	ft_printf("@ra\n");
	stacks_info(stack_a, stack_b);
}

void	rb(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate(stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("@rb\n");
	stacks_info(stack_a, stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, stack_b);
	rb(stack_a, stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("@rr\n");
	stacks_info(stack_a, stack_b);
}

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	stack_reverse(stack_a);
	update_stacks(stack_a, stack_b);
	ft_printf("@rra\n");
	stacks_info(stack_a, stack_b);
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	stack_reverse(stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("@rrb\n");
	stacks_info(stack_a, stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, stack_b);
	rrb(stack_a, stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("@rrr\n");
	stacks_info(stack_a, stack_b);
}
