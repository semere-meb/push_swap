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
	ft_printf("sa\n");
}

void	sb(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap(stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	stack_swap(stack_a);
	stack_swap(stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("ss\n");
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	stack_push(stack_a, stack_pop(stack_b));
	update_stacks(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	stack_push(stack_b, stack_pop(stack_a));
	update_stacks(stack_a, stack_b);
	ft_printf("pb\n");
}

void	ra(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate(stack_a);
	update_stacks(stack_a, stack_b);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate(stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	stack_rotate(stack_a);
	stack_rotate(stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("rr\n");
}

void	rra(t_stack *stack_a, t_stack *stack_b)
{
	stack_reverse(stack_a);
	update_stacks(stack_a, stack_b);
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_a, t_stack *stack_b)
{
	stack_reverse(stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	stack_reverse(stack_a);
	stack_reverse(stack_b);
	update_stacks(stack_a, stack_b);
	ft_printf("rrr\n");
}
