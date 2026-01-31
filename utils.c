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

void	update_stacks(t_stack *stack_a, t_stack *stack_b)
{
	stack_a->length = stack_size(stack_a);
	stack_a->min_index = get_min(stack_a);
	stack_a->min = node_val(stack_a, stack_a->min_index);
	stack_a->max_index = get_max(stack_a);
	stack_a->max = node_val(stack_a, stack_a->max_index);
	stack_b->length = stack_size(stack_b);
	stack_b->min_index = get_min(stack_b);
	stack_b->min = node_val(stack_b, stack_b->min_index);
	stack_b->max_index = get_max(stack_b);
	stack_b->max = node_val(stack_b, stack_b->max_index);
}
