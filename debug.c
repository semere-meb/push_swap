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
	t_node	*nd;

	nd = (t_node *)node;
	ft_printf("[");
	ft_printf("%d, ", nd->content);
	ft_printf("%d, ", nd->index);
	ft_printf("%d, ", nd->cost_to_top);
	ft_printf("%d, ", nd->cost);
	ft_printf("%s, ", nd->direction == UP ? "UP" : "DOWN");
	if (!nd->target)
		ft_printf("NULL");
	else
		ft_printf("%d, ", nd->target->content);
	ft_printf("]\n");
}

void	stacks_info(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n### Stack A Info ###\n");
	ft_printf("[content, index, cost-TT, cost, target]\n");
	stack_iter(stack_a, &printval);
	ft_printf("\n");
	ft_printf("len: %d\n", stack_a->length);
	ft_printf("min: %d, index: %d\n", stack_a->min, stack_a->min_index);
	ft_printf("max: %d, index: %d\n", stack_a->max, stack_a->max_index);
	if (node_at(stack_a, stack_a->cheapest_index))
		ft_printf("cheapest: %d, index: %d\n", node_at(stack_a, stack_a->cheapest_index)->content, stack_a->cheapest_index);

	ft_printf("\n### Stack B Info ###\n");
	stack_iter(stack_b, &printval);
	ft_printf("\n");
	ft_printf("len: %d\n", stack_b->length);
	ft_printf("min: %d, index: %d\n", stack_b->min, stack_b->min_index);
	ft_printf("max: %d,  index: %d\n", stack_b->max, stack_b->max_index);
	if (stack_b->cheapest_index)
		ft_printf("cheapest: %d, index: %d\n", node_at(stack_b, stack_b->cheapest_index)->content, stack_b->cheapest_index);
}
