/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 04:00:57 by semebrah          #+#    #+#             */
/*   Updated: 2026/01/22 04:01:18 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int val)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->content = val;
	node->next = NULL;
	return (node);
}

void	stack_push(t_stack **stack, t_stack *node)
{
	t_stack	*temp;

	if (!stack || !node)
		return ;
	temp = *stack;
	if (!*stack)
	{
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->next = temp;
		node->prev = temp->prev;
		(temp->prev)->next = node;
		temp->prev = node;
	}
	*stack = node;
}

t_stack	*stack_pop(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	if (temp->prev == temp->next)
		*stack = NULL;
	else
	{
		(temp->next)->prev = temp->prev;
		(temp->prev)->next = temp->next;
		*stack = temp->next;
	}
	return (temp);
}

size_t	stack_size(t_stack **stack)
{
	size_t	size;
	t_stack	*node;

	size = 0;
	if (!stack)
		return (size);
	node = *stack;
	while (node && (!size || node != *stack))
	{
		size++;
		node = node->next;
	}
	return (size);
}

void	stack_iter(t_stack **stack, void (*f)(void *))
{
	t_stack	*node;
	t_stack	*temp;
	int		first;

	first = 1;
	if (!stack || !f)
		return ;
	node = *stack;
	while (node && (first || node != *stack))
	{
		first = 0;
		temp = node->next;
		f(node);
		node = temp;
	}
}
