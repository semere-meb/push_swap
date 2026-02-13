#include "libft/libft.h"
#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	ft_printf("\n");
	stack_iter(stack_a, &printval);
	ft_printf("\n");
	stack_iter(stack_b, &printval);
	ft_printf("\n%d", stack_a->cheapest->val);
}
