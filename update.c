#include "push_swap.h"

static void	update_min_max(t_stack *stack)
{
	int		index;
	t_node	*node;

	if (!stack || !stack->length)
		return ;
	index = 0;
	node = stack->head;
	stack->min = node->content;
	stack->max = node->content;
	stack->min_index = 0;
	stack->max_index = 0;
	while (index < stack->length)
	{
		if (node->content < stack->min)
		{
			stack->min = node->content;
			stack->min_index = index;
		}
		else if (node->content > stack->max)
		{
			stack->max = node->content;
			stack->max_index = index;
		}
		node = node->next;
		index++;
	}
}

static void	update_cost(t_stack *stack)
{
	int		index;
	t_node	*node;

	if (!stack || !stack->length)
		return ;
	index = 0;
	node = stack->head;
	stack->cheapest_index = index;
	while (node && index < stack->length)
	{
		node->cost = node->cost_to_top + 1;
		if (node->target)
		{
			node->cost += node->target->cost_to_top;
			if (node->direction == node->target->direction)
				node->cost -= min(node->cost_to_top, node->target->cost_to_top);
		}
		if (node->cost < node_at(stack, stack->cheapest_index)->cost)
			stack->cheapest_index = index;
		node = node->next;
		index++;
	}
}

static void	set_targets(t_stack *stack1, t_stack *stack2)
{
	int		i1;
	int		i2;
	t_node	*node1;
	t_node	*node2;

	if (!stack1 || !stack2 || !stack1->length || !stack2->length)
		return ;
	i1 = 0;
	node1 = stack1->head;
	while (i1 < stack1->length)
	{
		i2 = 0;
		if (node1->content > stack2->max || node1->content < stack2->min)
			node1->target = node_at(stack2, stack2->max_index);
		else
		{
			node2 = stack2->head;
			node1->target = node_at(stack2, stack2->min_index);
			while (i2 < stack2->length)
			{
				if (node2->content < node1->content
					&& node2->content > node1->target->content)
					node1->target = node2;
				node2 = node2->next;
				i2++;
			}
		}
		node1 = node1->next;
		i1++;
	}
}

static void	update_index(t_stack *stack)
{
	int		index;
	t_node	*node;

	if (!stack || !stack->length)
		return ;
	index = 0;
	node = stack->head;
	while (node && index < stack->length)
	{
		node->index = index;
		if (index <= stack->length / 2)
		{
			node->cost_to_top = index;
			node->direction = UP;
		}
		else
		{
			node->cost_to_top = stack->length - index;
			node->direction = DOWN;
		}
		index++;
		node = node->next;
	}
}

void	update_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->length = stack_size(stack_a);
	stack_b->length = stack_size(stack_b);
	update_index(stack_a);
	update_index(stack_b);
	update_min_max(stack_a);
	update_min_max(stack_b);
	set_targets(stack_a, stack_b);
	update_cost(stack_a);
}
