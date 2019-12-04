/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:44:11 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 19:46:50 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			rev_rotate(t_lst **head)
{
	t_lst	*end;

	end = (*head)->prev;
	if ((*head) && head)
	{
		end->size = (*head)->size;
		(*head) = end;
		return (1);
	}
	return (0);
}
