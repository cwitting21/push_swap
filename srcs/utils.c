/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:37:20 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 08:30:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		str_del_and_ret_1(char **line)
{
	ft_strdel(line);
	return (1);
}

void	init_args_read_cmd(char **line, int *tmp, int *error)
{
	*line = NULL;
	*tmp = 0;
	*error = 0;
}

t_lst	*push_lst_to_end(t_lst *head, t_lst *new)
{
	t_lst		*end;

	end = NULL;
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
