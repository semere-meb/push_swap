/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 04:00:59 by semebrah          #+#    #+#             */
/*   Updated: 2026/01/22 04:01:18 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	size_t	i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

int	is_str_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (!isdigit(str[i++]))
			return (0);
	return (1);
}

int	parse_input(int argc, char **args, t_stack *stack)
{
	char	**res;
	int		i;
	int		j;
	long	val;

	i = 0;
	while (i < argc - 1)
	{
		res = ft_split(args[i++], ' ');
		j = 0;
		while (res[j])
		{
			if (!is_str_digit(res[j]))
				return (ft_printf("Error\n"), 0);
			val = ft_atol(res[j]);
			if (val < INT_MIN || val > INT_MAX)
				return (ft_printf("Error\n"), 0);
			if (node_index(stack, val) != -1)
				return (ft_printf("Error\n"), 0);
			stack_push(stack, node_new(val));
			free(res[j++]);
		}
		free(res);
	}
	return (1);
}

int	is_sorted(t_stack *stack_a)
{
	t_node	*head;
	long	max;
	int		first;

	max = INT_MIN;
	first = 1;
	if (!stack_a)
		return (1);
	head = stack_a->head;
	while (head && (first || head != stack_a->head))
	{
		first = 0;
		if (head->content < max)
			return (0);
		max = head->content;
		head = head->next;
	}
	return (1);
}

int	get_min(t_stack *stack)
{
	int	index_min;
	int	index;

	if (!stack || !stack->length)
		return (-1);
	index_min = 0;
	index = 0;
	while (index < stack->length)
	{
		if (node_val(stack, index) < node_val(stack, index_min))
			index_min = index;
		index++;
	}
	return (index_min);
}

int	get_max(t_stack *stack)
{
	int	index_max;
	int	index;

	if (!stack || !stack->length)
		return (-1);
	index_max = 0;
	index = 0;
	while (index < stack->length)
	{
		if (node_val(stack, index) > node_val(stack, index_max))
			index_max = index;
		index++;
	}
	return (index_max);
}

int min(int a, int b) {
	if (a < b)
		return a;
	return b;
}

void	update_cost(t_stack *stack)
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
		if (node->target) {
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

void	set_targets(t_stack *stack1, t_stack *stack2)
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

// update index & cost_to_top
void	update_index(t_stack *stack)
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
		if (index <= stack->length / 2) {
			node->cost_to_top = index;
			node->direction = UP;
		}
		else {
			node->cost_to_top = stack->length - index;
			node->direction = DOWN;
		}
		index++;
		node = node->next;
	}
}

void	update_meta(t_stack *stack)
{
	stack->length = stack_size(stack);
	stack->min_index = get_min(stack);
	stack->min = node_val(stack, stack->min_index);
	stack->max_index = get_max(stack);
	stack->max = node_val(stack, stack->max_index);
}

void	update_stacks(t_stack *stack_a, t_stack *stack_b)
{
	update_meta(stack_a);
	update_meta(stack_b);
	update_index(stack_a);
	update_index(stack_b);
	set_targets(stack_a, stack_b);
	set_targets(stack_b, stack_a);
	update_cost(stack_a);
	update_cost(stack_b);
}
