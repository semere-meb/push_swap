#include "push_swap.h"

static void	set_targets(t_stack *stack1, t_stack *stack2)
{
	if (!stack1 || !stack2 || !stack1->head)
		return;
	t_node *node;
	t_node *target;
	int i;
	int j;

	i = 0;
	node = stack1->head;
	while (i < stack1->length) {
		j = 0;
		target = stack2->head;
		node->target = target;
		while (j < stack2->length) {
			if (target->content < node->content) {
				node->target = target;
				break;
			}
			target = target->next;
			j++;
		}
		node = node->next;
		i++;
	}
}

static void	update_index(t_stack *stack)
{
	int		index;
	t_node	*node;

	if (!stack)
		return;
	if (!stack->head) {
		stack->length = 0;
		return ;
	}
	index = 0;
	node = stack->head;
	while (node && (!index || node != stack->head))
	{
		node->index = index++;
		node = node->next;
	}
	stack->length = index;
}

void	update_stacks(t_stack *stack_a, t_stack *stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	set_targets(stack_a, stack_b);
}
