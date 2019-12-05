/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:25:30 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/05 22:13:10 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		clean_one_stack(t_lst *head, size_t size)
{
	if (size)
	{
		clean_one_stack(head->next, size - 1);
		if (head)
		{
			head = NULL;
			free(head);
		}
	}
}

void			destroy_stacks(t_stack *stacks)
{
	clean_one_stack(stacks->a, stacks->size_a);
	clean_one_stack(stacks->b, stacks->size_b);
}
