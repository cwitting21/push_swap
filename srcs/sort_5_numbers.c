/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:28:06 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 04:44:48 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static size_t	get_index_simple_sort(t_lst **head, t_args *args)
{
	size_t		i;
	t_lst		*cur;
	int			min;

	i = 0;
	cur = (*head);
	min = cur->value;
	while (cur->next != (*head))
	{
		if (cur->value < min)
			min = cur->value;
		cur = cur->next;
	}
	if (cur->value < min)
		min = cur->value;
	cur = (*head);
	while (cur->value != min)
	{
		++i;
		cur = cur->next;
	}
	return (i);
}

static size_t		get_insert_index_simple_max(t_lst **h, t_args *args)
{
	size_t		i;
	int			max_in_a;
	t_lst		*cur;

	i = 0;
	cur = (*h);
	max_in_a = cur->value;
	while (cur->next != (*h))
	{
		if (cur->value > max_in_a)
			max_in_a = cur->value;
		cur = cur->next;
	}
	if (cur->value > max_in_a)
			max_in_a = cur->value;
	cur = (*h);
	while (cur->value != max_in_a)
	{
		++i;
		cur = cur->next;
	}
	if ((*h)->size == 3 && i == 2)
		return (0);
	return (i + 1);
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

static void		sort_lists_simple(t_lst **head_a, t_lst **head_b, t_args *args)
{
	t_lst		*end_a;
	size_t		i;

	end_a = (*head_a)->prev;
	if ((*head_b)->value == args->max_i)
	{
		i = get_insert_index_simple_max(head_a, args);
		while (i--)
		{
			rotate(head_a);
			printf("ra\n");
		}
		pa(head_a, head_b);
		printf("pa\n");
	}
	else if ((*head_b)->value > end_a->value && (*head_b)->value < (*head_a)->value)
	{
		pa(head_a, head_b);
		printf("pa\n");
	}
	else if ((*head_b)->value == args->min_i)
	{
		i = get_index_simple_sort(head_a, args);
		while (i--)
		{
			rotate(head_a);
			printf("ra\n");
		}
		pa(head_a, head_b);
		printf("pa\n");
	}
	else if ((*head_b)->value > end_a->value && (*head_b)->value > (*head_a)->value && (*head_b)->value > (*head_a)->next->value && (*head_a)->size == 3)
	{
		pa(head_a, head_b);
		printf("pa\n");
	}
	else if ((*head_b)->value > end_a->value && (*head_b)->value > (*head_a)->value && (*head_b)->value != args->max_i)
	{
		while ((*head_b)->value < end_a->value || (*head_b)->value > (*head_a)->value)
		{
			rotate(head_a);
			printf("ra\n");
			end_a = (*head_a)->prev;
		}
		pa(head_a, head_b);
		printf("pa\n");
	}
	else if ((*head_b)->value < end_a->value && (*head_b)->value != args->min_i && is_smallest(head_a, (*head_b)->value))
	{
		pa(head_a, head_b);
		printf("pa\n");
	}
	else if ((*head_b)->value < end_a->value && (*head_b)->value != args->min_i)
	{
		while ((*head_b)->value < end_a->value || (*head_b)->value > (*head_a)->value)
		{
			rotate(head_a);
			printf("ra\n");
			end_a = (*head_a)->prev;
		}
		pa(head_a, head_b);
		printf("pa\n");
	}
}

void		sort_5_numbers(t_lst **head_a, t_lst **head_b, t_args *args)
{
	size_t		tmp;

	while ((*head_a)->size > 3)
	{
		pb(head_a, head_b);
		printf("pb\n");
	}
	sort_3_numbers(head_a);
	tmp = (*head_a)->size;
	while (tmp++ < 5 && (*head_b))
		sort_lists_simple(head_a, head_b, args);
	final_sort(head_a, args);
}