#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node *cheapest;
	t_node *target;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (stack_a->length > 0) {
		cheapest = node_at(stack_a, stack_a->cheapest_index);
		target = cheapest->target;
		while (target->index > 0) {
			if (target->direction == UP)
				ra(stack_b, stack_a);
			else
				rra(stack_b, stack_a);
		}
		while (cheapest->index > 0) {
			if (cheapest->direction == UP)
				ra(stack_a, stack_b);
			else
				rra(stack_a, stack_b);
		}
		pb(stack_a, stack_b);
	}

	target = node_at(stack_b, stack_b->max_index);
	while (target->cost_to_top > 0){
		if (target->direction == UP)
			ra(stack_b, stack_a);
		else
			rra(stack_b, stack_a);
	}
	while (stack_b->length > 0)
		pa(stack_a, stack_b);
}
