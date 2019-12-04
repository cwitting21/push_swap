/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:15:52 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 04:16:05 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				read_commands(t_lst **head_a, t_lst **head_b)
{
	char				*line;
	int					tmp;

	while ((tmp = get_next_line(0, &line)) == 1)
	{
		if (!ft_strcmp("sa", line))
		{
			swap(head_a);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("sb", line))
		{
			swap(head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("ss", line))
		{
			ss(head_a, head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("pa", line))
		{
			pa(head_a, head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("pb", line))
		{
			pb(head_a, head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("ra", line))
		{
			rotate(head_a);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("rb", line))
		{
			rotate(head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("rr", line))
		{
			rr(head_a, head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("rra", line))
		{
			rev_rotate(head_a);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("rrb", line))
		{
			rev_rotate(head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("rrr", line))
		{
			rrr(head_a, head_b);
			ft_strdel(&line);
		}
		else
		{
			ft_strdel(&line);
			return (ft_error());
		}
	}
	ft_strdel(&line);
	if (tmp == -1)
		return (0);
	if (get_next_line(0, &line) == 0)
	{
		ft_strdel(&line);
		return (1);
	}
	return (0);
}