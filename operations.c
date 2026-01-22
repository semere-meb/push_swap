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

int	find_node(t_stack **stack, int val)
{
	t_stack	*node;
	int		first;

	first = 1;
	if (!stack)
		return (0);
	node = *stack;
	while (node && (first || node != *stack))
	{
		first = 0;
		if (node->content == val)
			return (1);
		node = node->next;
	}
	return (0);
}
