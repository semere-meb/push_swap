/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 22:07:42 by semebrah          #+#    #+#             */
/*   Updated: 2026/02/20 22:07:44 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

static int	do_op(char *nl, t_stack *sa, t_stack *sb)
{
	if (!ft_strncmp(nl, "sa\n", -1))
		swap(sa, sb, 'a', 0);
	else if (!ft_strncmp(nl, "sb\n", -1))
		swap(sa, sb, 'b', 0);
	else if (!ft_strncmp(nl, "ss\n", -1))
		swap(sa, sb, 's', 0);
	else if (!ft_strncmp(nl, "pa\n", -1))
		push(sa, sb, 'a', 0);
	else if (!ft_strncmp(nl, "pb\n", -1))
		push(sa, sb, 'b', 0);
	else if (!ft_strncmp(nl, "ra\n", -1))
		rotate(sa, sb, 'a', 0);
	else if (!ft_strncmp(nl, "rb\n", -1))
		rotate(sa, sb, 'b', 0);
	else if (!ft_strncmp(nl, "rr\n", -1))
		rotate(sa, sb, 's', 0);
	else if (!ft_strncmp(nl, "rra\n", -1))
		reverse(sa, sb, 'a', 0);
	else if (!ft_strncmp(nl, "rrb\n", -1))
		reverse(sa, sb, 'b', 0);
	else if (!ft_strncmp(nl, "rrr\n", -1))
		reverse(sa, sb, 's', 0);
	else
		return (free(nl), ft_printf("Error\n"), 0);
	return (free(nl), 1);
}

static int	read_n_op(t_stack *sa, t_stack *sb)
{
	char	*nl;

	while (true)
	{
		nl = get_next_line(0);
		if (!nl)
			return (1);
		if (!do_op(nl, sa, sb))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*sa;
	t_stack	*sb;

	sa = malloc(sizeof(t_stack));
	sb = malloc(sizeof(t_stack));
	sa->head = NULL;
	sb->head = NULL;
	argv++;
	if (argc == 1 || !sa || !sb)
		return (0);
	if (argc == 2)
		argv = ft_split(argv[0], ' ');
	if (parse_input(argc - 1, argv, sa) && read_n_op(sa, sb))
	{
		if (is_sorted(sa))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	free_mem(argv, argc, sa, sb);
	return (0);
}
