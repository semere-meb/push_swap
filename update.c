#include "libft/libft.h"
#include "push_swap.h"

int	abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

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

static void	calc_cost(t_stack *sa, t_node *n, t_stack *sb, t_node *t)
{
	int	common;

	if (!sa || !sb || !n || !t)
		return ;
	common = min(n->index, t->index);
	n->c_cost = common;
	n->n_cost = n->index - common;
	n->t_cost = t->index - common;
	common = min(sa->length - n->index, sb->length - t->index);
	if (sa->length - n->index + sb->length - t->index - common < n->c_cost
		+ n->n_cost + n->t_cost)
	{
		n->c_cost = -common;
		n->n_cost = -(sa->length - n->index - common);
		t->t_cost = -(sb->length - t->index - common);
	}
	if (n->index + sb->length - t->index < abs(n->c_cost) + abs(n->n_cost)
		+ abs(n->t_cost))
	{
		n->c_cost = 0;
		n->n_cost = n->index;
		n->t_cost = -(sb->length - t->index);
	}
	if (sa->length - n->index + t->index < abs(n->c_cost) + abs(n->n_cost)
		+ abs(n->t_cost))
	{
		n->c_cost = 0;
		n->n_cost = -(sa->length - n->index);
		n->t_cost = t->index;
	}
}

static void	set_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;
	t_node	*target;
	int		i;
	int		j;

	if (!stack_a || !stack_b || !stack_a->head)
		return ;
	i = 0;
	node = stack_a->head;
	while (i < stack_a->length)
	{
		j = 0;
		target = stack_b->head;
		node->target = target;
		while (j < stack_b->length)
		{
			if (node->val > target->val)
				break ;
			target = target->next;
			j++;
		}
		node->target = target;
		calc_cost(stack_a, node, stack_b, target);
		node = node->next;
		i++;
	}
}

static void	update_index(t_stack *stack)
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
	set_cheapest(stack_a);
}
