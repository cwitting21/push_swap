/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:28:46 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/05 23:01:26 by cwitting         ###   ########.fr       */
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

void			sort_2(t_lst **head)
{
	if ((*head)->value > (*head)->next->value)
	{
		swap(head);
		ft_printf("sa\n");
	}
	clean_one_stack(*head, (*head)->size);
}
