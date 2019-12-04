/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:29:40 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 05:42:03 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	case_1(t_lst **head)
{
	rev_rotate(head);
	printf("rra\n");
}

static void	case_2(t_lst **head)
{
	rotate(head);
	printf("ra\n");
}

void		final_sort(t_lst **head, t_args *args)
{
	t_lst		*tmp;
	t_lst		*tmp2;
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	tmp = (*head);
	tmp2 = (*head);
	while (tmp->value != args->min_i)
	{
		rev_rotate(&tmp);
		++i;
	}
	while (tmp2->value != args->min_i)
	{
		rotate(&tmp2);
		++n;
	}
	if (i < n)
		while ((*head)->value != args->min_i)
			case_1(head);
	else
		while ((*head)->value != args->min_i)
			case_2(head);
}
