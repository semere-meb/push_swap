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

int	swap(t_stack *sa, t_stack *sb, char s)
{
	if (s == 'a')
	{
		stack_swap(sa);
		ft_printf("sa\n");
	}
	else if (s == 'b')
	{
		stack_swap(sb);
		ft_printf("sb\n");
	}
	else if (s == 's')
	{
		stack_swap(sa);
		stack_swap(sb);
		ft_printf("ss\n");
	}
	return (1);
}

int	push(t_stack *sa, t_stack *sb, char s)
{
	if (s == 'a')
	{
		stack_push(sa, stack_pop(sb));
		ft_printf("pa\n");
	}
	else if (s == 'b')
	{
		stack_push(sb, stack_pop(sa));
		ft_printf("pb\n");
	}
	return (1);
}

int	rotate(t_stack *sa, t_stack *sb, char s)
{
	if (s == 'a')
	{
		stack_rotate(sa);
		ft_printf("ra\n");
	}
	else if (s == 'b')
	{
		stack_rotate(sb);
		ft_printf("rb\n");
	}
	else if (s == 's')
	{
		stack_rotate(sa);
		stack_rotate(sb);
		ft_printf("rr\n");
	}
	return (1);
}

int	reverse(t_stack *sa, t_stack *sb, char s)
{
	if (s == 'a')
	{
		stack_reverse(sa);
		ft_printf("rra\n");
	}
	else if (s == 'b')
	{
		stack_reverse(sb);
		ft_printf("rrb\n");
	}
	else if (s == 's')
	{
		stack_reverse(sa);
		stack_reverse(sb);
		ft_printf("rrr\n");
	}
	return (1);
}
