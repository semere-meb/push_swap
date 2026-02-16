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
		{
			rr(sa, sb);
			n->c_cost -= 1;
		}
		else if (n->c_cost < 0)
		{
			rrr(sa, sb);
			n->c_cost += 1;
		}
	}
	while (n->n_cost)
	{
		if (n->n_cost > 0)
		{
			ra(sa);
			n->n_cost -= 1;
		}
		else if (n->n_cost < 0)
		{
			rra(sa);
			n->n_cost += 1;
		}
	}
	while (n->t_cost)
	{
		if (n->t_cost > 0)
		{
			rb(sb);
			n->t_cost -= 1;
		}
		else if (n->t_cost < 0)
		{
			rrb(sb);
			n->t_cost += 1;
		}
	}
	pb(sa, sb);
	update_index(sa);
	update_index(sb);
	set_targets(sa, sb);
}

void	sort(t_stack *sa, t_stack *sb)
{
	t_node	*node;
	int		i;

	pb(sa, sb);
	pb(sa, sb);
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
			rb(sb);
	else
		while (sb->length - i++)
			rrb(sb);
	while (sb->head)
		pa(sa, sb);
}
