#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;
	t_node	*target;
	int		i;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->length > 0)
	{
		cheapest = node_at(stack_a, stack_a->cheapest_index);
		target = cheapest->target;
		i = 0;
		if (cheapest->direction == cheapest->target->direction)
		{
			while (i < min(cheapest->cost_to_top,
					cheapest->target->cost_to_top))
			{
				if (cheapest->direction == UP)
					rr(stack_a, stack_b);
				else
					rrr(stack_a, stack_b);
				i++;
			}
		}
		while (target->index > 0)
		{
			if (target->direction == UP)
				rb(stack_a, stack_b);
			else
				rrb(stack_a, stack_b);
		}
		while (cheapest->index > 0)
		{
			if (cheapest->direction == UP)
				ra(stack_a, stack_b);
			else
				rra(stack_a, stack_b);
		}
		pb(stack_a, stack_b);
	}
	target = node_at(stack_b, stack_b->max_index);
	while (target->cost_to_top > 0)
	{
		if (target->direction == UP)
			rb(stack_a, stack_b);
		else
			rrb(stack_a, stack_b);
	}
	while (stack_b->length > 0)
		pa(stack_a, stack_b);
	// stacks_info(stack_a, stack_b);
}
