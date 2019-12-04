/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave_3_nbrs_in_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:35:25 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 05:45:46 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		leave_3_nbrs_in_a(t_lst **head_a, t_lst **head_b, t_args *args)
{
	t_lst		*tmp;
	int			code;
	int			i;

	i = (*head_a)->size;
	tmp = (*head_a);
	while (i--)
	{
		code = 1;
		if (tmp->value != args->max_i && tmp->value != args->mid_i
			&& tmp->value != args->min_i)
		{
			pb(&tmp, head_b);
			printf("pb\n");
			code = 0;
		}
		if (code)
		{
			rotate(&tmp);
			printf("ra\n");
		}
	}
	(*head_a) = tmp;
}
