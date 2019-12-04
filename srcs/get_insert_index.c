/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_insert_index.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 08:23:38 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 11:16:15 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				get_insert_index(t_lst **head_a, int num)
{
	t_lst		*cur;
	size_t		i;

	i = 0;
	cur = (*head_a);
	while (cur->value < num || cur->prev->value > num)
	{
		cur = cur->next;
		++i;
	}
	return (i);
}
