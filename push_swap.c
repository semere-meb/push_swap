/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semebrah <semebrah@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 04:00:54 by semebrah          #+#    #+#             */
/*   Updated: 2026/01/22 04:01:18 by semebrah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

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
	if (parse_input(argc - 1, argv, sa) && !is_sorted(sa))
		sort(sa, sb);
	free_mem(argv, argc, sa, sb);
	return (0);
}
