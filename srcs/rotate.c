/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:44:14 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 19:44:21 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rotate(t_lst **head)
{
	if ((*head) && (head))
	{
		if ((*head)->next)
		{
			(*head)->next->size = (*head)->size;
			(*head) = (*head)->next;
		}
		return (1);
	}
	return (0);
}
