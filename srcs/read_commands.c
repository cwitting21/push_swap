/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:15:52 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 19:48:27 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		case_1_local(t_lst **head_a, t_lst **head_b, char *line)
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
}

static void		case_2_local(t_lst **head_a, t_lst **head_b, char *line)
{
	if (!ft_strcmp("pb", line))
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
		printf("!!!!!!!!!!!!!\n");
		printf("!!!!!!!!!!!!!\n");
		if (head_b && (*head_b))
			rotate(head_b);
		ft_strdel(&line);
	}
	else if (!ft_strcmp("rr", line))
	{
		rr(head_a, head_b);
		ft_strdel(&line);
	}
}

static int		case_3_local(t_lst **head_a, t_lst **head_b, char *line)
{
	if (!ft_strcmp("rra", line))
	{
		if (head_a && (*head_a))
			rev_rotate(head_a);
		ft_strdel(&line);
	}
	else if (!ft_strcmp("rrb", line))
	{
		if (head_b && (*head_b))
			rev_rotate(head_b);
		ft_strdel(&line);
	}
	else if (!ft_strcmp("rrr", line))
	{
		if (head_b && (*head_b) && (head_a) && (*head_a))
			rrr(head_a, head_b);
		ft_strdel(&line);
	}
	else if (ft_strcmp("sa", line) && ft_strcmp("sb", line) &&
	ft_strcmp("ss", line) && ft_strcmp("pa", line) && ft_strcmp("pb", line)
	&& ft_strcmp("ra", line) && ft_strcmp("rb", line) && ft_strcmp("rr", line))
	{
		ft_strdel(&line);
		return (ft_error());
	}
	return (1);
}

int				read_commands(t_lst **head_a, t_lst **head_b)
{
	char				*line;
	int					tmp;
	int					error;

	while ((tmp = get_next_line(0, &line)) == 1)
	{
		printf("LALA\n");
		case_1_local(head_a, head_b, line);
		printf("LALA\n");
		case_2_local(head_a, head_b, line);
		printf("LALA\n");
		error = case_3_local(head_a, head_b, line);
		printf("LALA\n");
	}
	ft_strdel(&line);
	if (tmp == -1 || error == 0)
		return (0);
	if (get_next_line(0, &line) == 0)
	{
		ft_strdel(&line);
		return (1);
	}
	return (0);
}
