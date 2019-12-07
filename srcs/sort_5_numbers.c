/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:28:06 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/07 22:46:45 by cwitting         ###   ########.fr       */
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

static int		is_smallest(t_lst **head_a, int val)
{
	t_lst		*cur;

	cur = (*head_a);
	while (cur->next != (*head_a))
	{
		if (val > cur->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

static void		sort_lists_simple(t_lst **ha, t_lst **hb, t_args *args)
{
	t_lst		*end_a;
	size_t		i;

	end_a = (*ha)->prev;
	if ((*hb)->value == args->max_i)
		case_1_simpsort(ha, hb, args);
	else if ((*hb)->value > end_a->value && (*hb)->value < (*ha)->value)
		case_2_simpsort(ha, hb);
	else if ((*hb)->value == args->min_i)
		case_3_simpsort(ha, hb, args);
	else if ((*hb)->value > end_a->value && (*hb)->value > (*ha)->value &&
			(*hb)->value > (*ha)->next->value && (*ha)->size == 3)
		case_2_simpsort(ha, hb);
	else if ((*hb)->value > end_a->value && (*hb)->value > (*ha)->value &&
			(*hb)->value != args->max_i)
		case_4_simpsort(ha, hb, end_a);
	else if ((*hb)->value < end_a->value && (*hb)->value != args->min_i &&
			is_smallest(ha, (*hb)->value))
		case_2_simpsort(ha, hb);
	else if ((*hb)->value < end_a->value && (*hb)->value != args->min_i)
		case_4_simpsort(ha, hb, end_a);
}

void			sort_5_numbers(t_lst **head_a, t_lst **head_b, t_args *args)
{
	size_t		tmp;

	while ((*head_a)->size > 3)
	{
		pb(head_a, head_b);
		ft_printf("pb\n");
	}
	sort_3_numbers(head_a);
	tmp = (*head_a)->size;
	while (tmp++ < 5 && (*head_b))
		sort_lists_simple(head_a, head_b, args);
	final_sort(head_a, args);
	clean_one_stack(*head_a, (*head_a)->size);
	if (*head_b && head_b)
		clean_one_stack(*head_b, (*head_b)->size);
}
