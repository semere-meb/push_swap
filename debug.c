/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 04:00:46 by semebrah          #+#    #+#             */
/*   Updated: 2026/01/22 04:01:18 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	printval(void *node)
{
	ft_printf("%d -> ", ((t_node *)node)->content);
}

void	stacks_info(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n### Stack A Info ###\n");
	stack_iter(stack_a, &printval);
	ft_printf("\n");
	ft_printf("min: %d, index: %d\n", stack_a->min, stack_a->min_index);
	ft_printf("max: %d, index: %d\n", stack_a->max, stack_a->max_index);
	ft_printf("\n### Stack B Info ###\n");
	stack_iter(stack_b, &printval);
	ft_printf("\n");
	ft_printf("min: %d, index: %d\n", stack_b->min, stack_b->min_index);
	ft_printf("max: %d,  index: %d\n", stack_b->max, stack_b->max_index);
}
