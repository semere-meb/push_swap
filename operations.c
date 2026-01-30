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

void	sa(t_stack **stack_a)
{
	stack_swap(stack_a);
	ft_printf("@sa\n");
}

void	sb(t_stack **stack_b)
{
	stack_swap(stack_b);
	ft_printf("@sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("@ss\n");
}

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*node;

	node = stack_pop(stack_b);
	if (node)
		stack_push(stack_a, node);
	ft_printf("@pa\n");
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	node = stack_pop(stack_a);
	if (node)
		stack_push(stack_b, node);
	ft_printf("@pb\n");
}

void	ra(t_stack **stack_a)
{
	stack_rotate(stack_a);
	ft_printf("@ra\n");
}

void	rb(t_stack **stack_b)
{
	stack_rotate(stack_b);
	ft_printf("@rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("@rr\n");
}

void	rra(t_stack **stack_a)
{
	stack_reverse(stack_a);
	ft_printf("@rra\n");
}

void	rrb(t_stack **stack_b)
{
	stack_reverse(stack_b);
	ft_printf("@rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("@rrr\n");
}
