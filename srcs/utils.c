/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:37:20 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 20:39:26 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		num_is_valid(char *ptr)
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

t_lst	*push_lst_to_end(t_lst *head, t_lst *new)
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
