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
#include <stdlib.h>

t_node	*node_new(int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = val;
	node->index = -1;
	node->prev = NULL;
	node->next = NULL;
	node->target = NULL;
	node->c_cost = -1;
	node->n_cost = -1;
	node->t_cost = -1;
	return (node);
}

void	stack_push(t_stack *stack, t_node *node)
{
	t_node	*old_head;

	if (!stack || !node)
		return ;
	old_head = stack->head;
	if (!old_head)
	{
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->next = old_head;
		node->prev = old_head->prev;
		(old_head->prev)->next = node;
		old_head->prev = node;
	}
	stack->head = node;
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*old_head;

	if (!stack || !stack->head)
		return (NULL);
	old_head = stack->head;
	if (old_head->next == old_head)
		stack->head = NULL;
	else
	{
		(old_head->next)->prev = old_head->prev;
		(old_head->prev)->next = old_head->next;
		stack->head = old_head->next;
	}
	return (old_head);
}

void	stack_swap(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;

	if (!stack || stack_size(stack) < 2)
		return ;
	node1 = stack_pop(stack);
	node2 = stack_pop(stack);
	stack_push(stack, node1);
	stack_push(stack, node2);
}

void	stack_rotate(t_stack *stack)
{
	if (!stack || stack_size(stack) < 2)
		return ;
	stack->head = stack->head->next;
}

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

t_node	*node_at(t_stack *stack, int index)
{
	int		size;
	t_node	*node;
	int		first;

	size = 0;
	first = 1;
	if (!stack)
		return (NULL);
	node = stack->head;
	while (node && (first || node != stack->head))
	{
		first = 0;
		if (size == index)
			return (node);
		size++;
		node = node->next;
	}
	return (NULL);
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
			return (node->content);
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
		if (node->content == val)
			return (index);
		node = node->next;
		index++;
	}
	return (-1);
}
