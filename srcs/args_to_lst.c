/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:42:46 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 04:42:46 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		num_is_valid(char *ptr)
{
	char		*tmp;

	tmp = ptr;
	while (*tmp && !ft_isblank(*tmp))
	{
		if (!(*tmp >= 0 + '0' && *tmp <= 9 + '0'))
			return (0);
		++tmp;
	}
	return (1);
}

static t_lst	*push_lst_to_end(t_lst *head, t_lst *new)
{
	t_lst		*end;

	if (!head)
	{
		new->next = new;
		new->prev = new;
		new->size++;
		return (new);
	}
	end = head;
	end->size++;
	while (end->next && end->next != head)
		end = end->next;
	end->next = new;
	new->prev = end;
	new->next = head;
	head->prev = new;
	return (head);
}

static int			check_if_nbr_is_valid(char *ptr)
{
	int				minus;
	char			*tmp;
	int				i;

	i = 0;
	if (*ptr == '-')
	{
		minus = 1;
		ptr++;
	}
	else
		minus = 0;
	if (*ptr == '+')
		ptr++;
	tmp = ptr;
	while (*tmp++)
		++i;
	if (i > 10)
		return (0);
	tmp = ptr;
	for (int m = 0; m < 10; m++)
		tmp[m] -= '0';
	for (int m = 0; m < 10; m++)
		printf("%d ", ptr[m]);
	if (ptr[0] >= 2 && ptr[1] >= 1 && ptr[2] >= 4 && ptr[3] >= 7
	&& ptr[4] >= 4 && ptr[5] >= 8 && ptr[6] >= 3 && ptr[7] >= 6
	&& ptr[8] >= 4 && (minus ? ptr[9] == 9 : ptr[9] >= 8))
		return (0);
	return (1);
}

// 2,147,483,647
// -2,147,483,648

static int			valid_args(char *ptr, int ac, char  **av)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = ptr;
	while (++i < ac)
	{
		ptr = av[i];
		while (*ptr)
		{
			if (((*ptr == '-' || *ptr == '+') && !ft_isdigit(*(ptr + 1)))
			|| !check_if_nbr_is_valid(ptr))
				return (0);
			else if ((*ptr == '-' || *ptr == '+') && !ft_isdigit(*(ptr + 1)))
				return (0);
			if (!((*ptr >= 0 + '0' && *ptr <= 9 + '0') || *ptr == ' ' || *ptr == '"'
				|| *ptr == '+' || *ptr == '-'))
				return (0);
			++ptr;
		}
	}
	return (1);
}

int			args_to_lst(int ac, char **av, t_lst **head)
{
	int		i;
	char	*ptr;

	i = 0;
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
