#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t	i;
	t_stack	**stack_a;
	long	val;

	i = 0;
	if (argc == 1)
		return (1);
	stack_a = malloc(sizeof(t_stack *));
	if (!stack_a)
		return (1);
	while (argv[i + 1])
	{
		if (!is_str_digit(argv[i + 1]))
			return (ft_printf("Error\n"), 1);
		val = ft_atoi2(argv[i + 1]);
		if (val < INT_MIN || val > INT_MAX)
			return (ft_printf("Error\n"), 1);
		// TODO: check if it is in the stack
		// TODO: add it at the top
	}
	for (int i = 0; i < argc - 1; i++)
	{
		ft_printf("%d\n", stack_a[i]);
	}
}
