/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 02:34:48 by semebrah          #+#    #+#             */
/*   Updated: 2026/02/16 02:35:06 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move(t_stack *sa, t_stack *sb, t_node *n)
{
	while (n->c_cost)
	{
		if (n->c_cost > 0)
			n->c_cost -= rotate(sa, sb, 's');
		else if (n->c_cost < 0)
			n->c_cost += reverse(sa, sb, 's');
	}
	while (n->n_cost)
	{
		if (n->n_cost > 0)
			n->n_cost -= rotate(sa, sb, 'a');
		else if (n->n_cost < 0)
			n->n_cost += reverse(sa, sb, 'a');
	}
	while (n->t_cost)
	{
		if (n->t_cost > 0)
			n->t_cost -= rotate(sa, sb, 'b');
		else if (n->t_cost < 0)
			n->t_cost += reverse(sa, sb, 'b');
	}
	push(sa, sb, 'b');
}

static void	sort_three(t_stack *s)
{
	if (s->head == s->min && s->head->next == s->max)
		swap(s, NULL, 'a');
	if (s->head == s->max)
		rotate(s, NULL, 'a');
	if (!is_sorted(s) && s->head->prev == s->max)
		swap(s, NULL, 'a');
	else if (!is_sorted(s) && s->head->prev == s->min)
		reverse(s, NULL, 'a');
}

static t_node	*get_asc_target(t_node *n, t_stack *s)
{
	t_node	*target;

	if (!n || !s || !s->head)
		return (NULL);
	if (n->val > s->max->val || n->val < s->min->val)
		return (s->min);
	target = s->head;
	while (target != s->min)
		target = target->next;
	while (n->val > target->val)
		target = target->next;
	return (target);
}

static void	move_top(t_stack *s, t_node *n)
{
	if (n->index <= s->length / 2.0)
		while (n->index)
			rotate(s, NULL, 'a');
	else
		while (n->index)
			reverse(s, NULL, 'a');
}

void	sort(t_stack *sa, t_stack *sb)
{
	int	i;

	update_index(sa);
	update_index(sb);
	i = 2;
	while (i-- && sa->length > 3)
		push(sa, sb, 'b');
	while (sa->length > 3)
	{
		set_targets(sa, sb);
		move(sa, sb, sa->cheapest);
	}
	sort_three(sa);
	while (sb->head)
	{
		move_top(sa, get_asc_target(sb->head, sa));
		push(sa, sb, 'a');
	}
	move_top(sa, sa->min);
}
