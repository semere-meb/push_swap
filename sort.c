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

void	move(t_stack *sa, t_stack *sb, t_node *n)
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
	update_index(sa);
	update_index(sb);
	set_targets(sa, sb);
}

void	sort(t_stack *sa, t_stack *sb)
{
	t_node	*node;
	int		i;

	push(sa, sb, 'b');
	push(sa, sb, 'b');
	update_index(sa);
	update_index(sb);
	set_targets(sa, sb);
	while (sa->length)
	{
		node = sa->cheapest;
		move(sa, sb, node);
	}
	i = sb->max->index;
	if (i <= sb->length / 2.0)
		while (i-- > 0)
			rotate(sa, sb, 'b');
	else
		while (sb->length - i++)
			reverse(sa, sb, 'b');
	while (sb->head)
		push(sa, sb, 'a');
}
