#include "libft/libft.h"
#include <ctype.h>

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

ssize_t	find(int *numbers, size_t size, int val)
{
	size_t	ix;

	ix = 0;
	if (!numbers)
		return (-1);
	while (ix < size)
	{
		if (numbers[ix] == val)
			return (ix);
		ix++;
	}
	return (-1);
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
