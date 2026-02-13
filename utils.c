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

int	parse_input(int count, char **args, t_stack *stack)
{
	int		i;
	long	val;
	bool	dynamic;

	dynamic = 0;
	if (count == 1)
	{
		dynamic = 1;
		args = ft_split(args[0], ' ');
		count = 0;
		while (args[count])
			count++;
	}
	i = count - 1;
	while (i >= 0)
	{
		if (!is_str_digit(args[i]))
			return (ft_printf("Error\n"), 0);
		val = ft_atol(args[i]);
		if (val < INT_MIN || val > INT_MAX)
			return (ft_printf("Error\n"), 0);
		if (node_index(stack, val) != -1)
			return (ft_printf("Error\n"), 0);
		stack_push(stack, node_new(val));
		if (dynamic)
			free(args[i--]);
	}
	if (dynamic)
		free(args);
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
		if (head->val < max)
			return (0);
		max = head->val;
		head = head->next;
	}
	return (1);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
