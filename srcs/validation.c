#include "../includes/push_swap.h"

static int			num_is_valid(char *ptr)
{
	char	*tmp;

	tmp = ptr;
	while (!ft_isblank(*tmp))
	{
		if (!(*tmp >= 0 + '0' && *tmp <= 9 + '0'))
			return (0);
		++tmp;
	}
	return (1);
}

int			validation(int ac, char **av, t_stack *stack)
{
	int		i;
	char	*ptr;

	i = 0;
	while (++i < ac)
	{
		ptr = av[i];
		while (*ptr)
		{
			while (ft_isblank(*ptr))
				++ptr;
			if (!(num_is_valid(ptr)))
				return (0);
			if (!(stack->a = put_lst_end(stack->a, new_lst(ft_atoi(ptr)))))
				return (0);
			while (!ft_isblank(*ptr) && *ptr)
				++ptr;
		}
	}
	return (1);
}
