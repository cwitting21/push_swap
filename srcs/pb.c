/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:42:34 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 04:42:35 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		stack_b_not_empty(t_lst **head_a, t_lst **head_b, t_lst *end_a)
{
	t_lst	*end_b;
	t_lst	*first;

	(*head_a)->next->size = (*head_a)->size - 1;
	(*head_a)->next->prev = end_a;
	end_a->next = (*head_a)->next;
	end_b = (*head_b)->prev;
	first = (*head_a);
	(*head_a) = (*head_a)->next;
	first->next = (*head_b);
	(*head_b)->prev = first;
	end_b->next = first;
	first->prev = end_b;
	first->size = (*head_b)->size++;
	(*head_b) = first;
	(*head_b)->size++;
}

static void		stack_b_is_empty(t_lst **head_a, t_lst **head_b, t_lst *end_a)
{
	t_lst	*tmp;

	tmp = (*head_a);
	(*head_a) = (*head_a)->next;
	(*head_a)->size = (*head_a)->prev->size - 1;
	end_a->next = (*head_a);
	(*head_a)->prev = end_a;
	(*head_a)->prev = end_a;
	(*head_b) = tmp;
	(*head_b)->size = 1;
	(*head_b)->next = (*head_b);
	(*head_b)->prev = (*head_b);
}

int			pb(t_lst **head_a, t_lst **head_b)
{
	t_lst	*end_a = NULL;

	end_a = (*head_a)->prev;
	if (!*head_b && (*head_a)->size >= 3)
	{
		stack_b_is_empty(head_a, head_b, end_a);
		// print_stacks(head_a, head_b);
		return (1);
	}
	if (*head_b && (*head_a)->size >= 3)
	{
		stack_b_not_empty(head_a, head_b, end_a);
		return (1);
	}
	return (0);
}