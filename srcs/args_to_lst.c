/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:22:34 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 05:14:20 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long long	ft_atoi_local(const char *str, int neg)
{
	int				i;
	long long		res;

	i = 0;
	res = 0;
	while (ft_isblank(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * neg);
}

static int			check_if_nbr_is_valid(char *ptr)
{
	int				minus;
	char			*tmp;
	int				i;

	i = 0;
	if (*ptr == '-')
	{
		minus = -1;
		ptr++;
	}
	else
		minus = 1;
	if (*ptr == '+')
		ptr++;
	if (ft_atoi_local(ptr, minus) >= 2147483648 ||
	ft_atoi_local(ptr, minus) <= -2147483649)
		return (0);
	return (1);
}

static int			args_are_garbage(int ac, char **av)
{
	char			*ptr;
	int				i;

	i = 0;
	while (++i < ac)
	{
		ptr = av[i];
		while (*ptr)
		{
			if (!((*ptr >= 0 + '0' && *ptr <= 9 + '0') ||
			((*ptr == ' ' || *ptr == '"' || *ptr == '+'
			|| *ptr == '-'))))
				return (1);
			ptr++;
		}
	}
	return (0);
}

static int			valid_args(char *ptr, int ac, char **av)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = ptr;
	while (++i < ac)
	{
		ptr = av[i];
		if (((*ptr == '-' || *ptr == '+') && !ft_isdigit(*(ptr + 1)))
		|| !(check_if_nbr_is_valid(ptr)))
			return (0);
		while (*ptr)
		{
			if ((*ptr == '-' || *ptr == '+') && !ft_isdigit(*(ptr + 1)))
				return (0);
			if (!((*ptr >= 0 + '0' && *ptr <= 9 + '0') || *ptr != ' ' ||
			*ptr != '"' || ((*ptr != '+' || *ptr != '-')
			&& ft_isdigit(*(ptr + 1)))))
				return (0);
			++ptr;
		}
	}
	return (1);
}

int					args_to_lst(int ac, char **av, t_lst **head)
{
	int				i;
	char			*ptr;

	i = 0;
	if (args_are_garbage(ac, av))
		return (0);
	if (valid_args(ptr, ac, av))
	{
		while (++i < ac)
		{
			ptr = av[i];
			while (*ptr)
			{
				while (ft_isblank(*ptr))
					++ptr;
				if (((*ptr >= (0 + '0')) && (*ptr <= (9 + '0'))) ||
				((*ptr == '+' || *ptr == '-') && ft_isdigit(*(ptr + 1))))
					(*head = push_lst_to_end(*head, new_lst(ft_atoi(ptr))));
				while (!ft_isblank(*ptr) && *ptr)
					++ptr;
			}
		}
		return (1);
	}
	return (0);
}
