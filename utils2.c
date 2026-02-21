/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:50:44 by semebrah          #+#    #+#             */
/*   Updated: 2026/02/19 19:51:03 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	is_str_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (!isdigit(str[i++]))
			return (0);
	return (1);
}

void	free_mem(char **argv, int argc, t_stack *sa, t_stack *sb)
{
	int	i;

	i = 0;
	stack_iter(sa, &free);
	free(sa);
	stack_iter(sb, &free);
	free(sb);
	if (argc == 2)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
}
