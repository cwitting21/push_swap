#include "../includes/push_swap.h"

int			put_arg_to_lst(char **av, int ac)
{
	int		i;
	char	*ptr;

	i = 0;
	while (++i < ac)
	{
		if (num_is_valid(ptr))
		{
			while (ft_isblank(av[i]))
				++i;
			stack->a = (put_lst_end(stack->a, new_lst(ft_atoi(ptr))));
		//
			++i;
		}
	}

}

int			validation(int ac, char **av, t_stack *stack)
{
	int		i;
	char	*ptr;
	int		n;

	i = 0;
	n = 0;
	while (++n < ac)
	{
		put_arg_to_lst(av, &n);
	}

}
