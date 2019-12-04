/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_insert_index_simpsort.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 09:45:02 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 09:45:16 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t		get_insert_index_simple_max(t_lst **h, t_args *args)
{
	size_t		i;
	int			max_in_a;
	t_lst		*cur;

	i = 0;
	cur = (*h);
	max_in_a = cur->value;
	while (cur->next != (*h))
	{
		if (cur->value > max_in_a)
			max_in_a = cur->value;
		cur = cur->next;
	}
	if (cur->value > max_in_a)
		max_in_a = cur->value;
	cur = (*h);
	while (cur->value != max_in_a)
	{
		++i;
		cur = cur->next;
	}
	if ((*h)->size == 3 && i == 2)
		return (0);
	return (i + 1);
}

size_t	get_index_simple_sort(t_lst **head, t_args *args)
{
	size_t		i;
	t_lst		*cur;
	int			min;

	i = 0;
	cur = (*head);
	min = cur->value;
	while (cur->next != (*head))
	{
		if (cur->value < min)
			min = cur->value;
		cur = cur->next;
	}
	if (cur->value < min)
		min = cur->value;
	cur = (*head);
	while (cur->value != min)
	{
		++i;
		cur = cur->next;
	}
	return (i);
}