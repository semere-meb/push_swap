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

static int	ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

long	ft_atoi2(const char *nptr)
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

int	parse_input(int argc, char **args, t_stack **stack)
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
			val = ft_atoi2(res[j]);
			if (val < INT_MIN || val > INT_MAX)
				return (ft_printf("Error\n"), 0);
			if (stack_search(stack, val))
				return (ft_printf("Error\n"), 0);
			stack_push(stack, stack_new(val));
			free(res[j++]);
		}
		free(res);
	}
	return (1);
}
