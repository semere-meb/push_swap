/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:33:02 by semebrah          #+#    #+#             */
/*   Updated: 2026/02/16 18:33:03 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_reverse(t_stack *stack)
{
	if (!stack || stack_size(stack) < 2)
		return ;
	stack->head = stack->head->prev;
}

int	stack_size(t_stack *stack)
{
	int		size;
	t_node	*node;

	if (!stack || !stack->head)
		return (0);
	size = 0;
	node = stack->head;
	while (node && (!size || node != stack->head))
	{
		size++;
		node = node->next;
	}
	return (size);
}

void	stack_iter(t_stack *stack, void (*f)(void *))
{
	t_node	*node;
	t_node	*temp;
	int		first;

	first = 1;
	if (!stack || !f)
		return ;
	node = stack->head;
	while (node && (first || node != stack->head))
	{
		first = 0;
		temp = node->next;
		f(node);
		node = temp;
	}
}

int	node_val(t_stack *stack, int index)
{
	int		size;
	t_node	*node;
	int		first;

	size = 0;
	first = 1;
	if (!stack)
		return (-1);
	node = stack->head;
	while (node && (first || node != stack->head))
	{
		first = 0;
		if (size == index)
			return (node->val);
		size++;
		node = node->next;
	}
	return (-1);
}

int	node_index(t_stack *stack, int val)
{
	t_node	*node;
	int		first;
	int		index;

	index = 0;
	first = 1;
	if (!stack)
		return (-1);
	node = stack->head;
	while (node && (first || node != stack->head))
	{
		first = 0;
		if (node->val == val)
			return (index);
		node = node->next;
		index++;
	}
	return (-1);
}
