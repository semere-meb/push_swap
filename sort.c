#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (stack_b->head->content < stack_b->head->next->content)
		sb(stack_a, stack_b);
}
