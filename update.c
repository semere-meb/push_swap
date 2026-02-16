/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 02:34:59 by semebrah          #+#    #+#             */
/*   Updated: 2026/02/16 02:35:06 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_cheapest(t_stack *stack)
{
	int		i;
	t_node	*n;

	i = 0;
	if (!stack)
		return ;
	i = 0;
	n = stack->head;
	stack->cheapest = n;
	while (i < stack->length)
	{
		if (abs(n->c_cost) + abs(n->n_cost)
			+ abs(n->t_cost) < abs(stack->cheapest->c_cost)
			+ abs(stack->cheapest->n_cost) + abs(stack->cheapest->t_cost))
			stack->cheapest = n;
		n = n->next;
		i++;
	}
}

static void	set_cost(t_node *n, int c_cost, int n_cost, int t_cost)
{
	n->c_cost = c_cost;
	n->n_cost = n_cost;
	n->t_cost = t_cost;
}

static void	calc_cost(t_stack *sa, t_node *n, t_stack *sb, t_node *t)
{
	int	common;

	if (!sa || !sb || !n || !t)
		return ;
	common = min(n->index, t->index);
	set_cost(n, common, n->index - common, t->index - common);
	common = min(sa->length - n->index, sb->length - t->index);
	if (sa->length - n->index + sb->length - t->index - common < n->c_cost
		+ n->n_cost + n->t_cost)
		set_cost(n, -common, -(sa->length - n->index - common), -(sb->length
				- t->index - common));
	if (n->index + sb->length - t->index < abs(n->c_cost) + abs(n->n_cost)
		+ abs(n->t_cost))
		set_cost(n, 0, n->index, -(sb->length - t->index));
	if (sa->length - n->index + t->index < abs(n->c_cost) + abs(n->n_cost)
		+ abs(n->t_cost))
		set_cost(n, 0, -(sa->length - n->index), t->index);
	set_cheapest(sa);
}

void	set_targets(t_stack *sa, t_stack *sb)
{
	t_node	*n;
	t_node	*t;
	int		i;
	int		j;

	if (!sa || !sb || !sa->head)
		return ;
	i = 0;
	n = sa->head;
	while (i < sa->length)
	{
		t = sb->head;
		while (t->val != sb->max->val)
			t = t->next;
		j = 0;
		if (n->val > sb->min->val && n->val < sb->max->val)
			while (j++ < sb->length && n->val < t->val)
				t = t->next;
		n->target = t;
		calc_cost(sa, n, sb, t);
		n = n->next;
		i++;
	}
}

void	update_index(t_stack *stack)
{
	int		index;
	t_node	*node;

	if (!stack)
		return ;
	if (!stack->head)
	{
		stack->length = 0;
		return ;
	}
	index = 0;
	node = stack->head;
	stack->min = node;
	stack->max = node;
	while (node && (!index || node != stack->head))
	{
		node->index = index++;
		if (node->val > stack->max->val)
			stack->max = node;
		if (node->val < stack->min->val)
			stack->min = node;
		node = node->next;
	}
	stack->length = index;
}
