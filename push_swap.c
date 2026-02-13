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

#include "push_swap.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		res;

	if (argc == 1)
		return (1);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);
	stack_a->head = NULL;
	stack_b->head = NULL;
	if (!parse_input(argc - 1, &argv[1], stack_a))
		return (1);
	update_stacks(stack_a, stack_b);
	if (!is_sorted(stack_a))
		sort(stack_a, stack_b);
	res = is_sorted(stack_a);
	return (stack_iter(stack_a, &free), free(stack_a), free(stack_b), res);
}
