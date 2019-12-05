/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_simple_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 09:42:40 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/05 21:30:02 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		case_1_simpsort(t_lst **head_a, t_lst **head_b, t_args *args)
{
	size_t		i;

	i = get_insert_index_simple_max(head_a, args);
	while (i--)
	{
		rotate(head_a);
		ft_printf("ra\n");
	}
	pa(head_a, head_b);
	ft_printf("pa\n");
}

void		case_2_simpsort(t_lst **head_a, t_lst **head_b)
{
	pa(head_a, head_b);
	ft_printf("pa\n");
}

void		case_3_simpsort(t_lst **head_a, t_lst **head_b, t_args *args)
{
	size_t		i;

	i = get_index_simple_sort(head_a, args);
	while (i--)
	{
		rotate(head_a);
		ft_printf("ra\n");
	}
	pa(head_a, head_b);
	ft_printf("pa\n");
}

void		case_4_simpsort(t_lst **head_a, t_lst **head_b, t_lst *end_a)
{
	while ((*head_b)->value < end_a->value ||
	(*head_b)->value > (*head_a)->value)
	{
		rotate(head_a);
		ft_printf("ra\n");
		end_a = (*head_a)->prev;
	}
	pa(head_a, head_b);
	ft_printf("pa\n");
}
