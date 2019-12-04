/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:21:07 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 05:33:45 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void			init_args_local(t_args *args, int size, int i)
{
	args->min_i = args->arr[0];
	args->mid_s = args->arr[i / 3];
	args->mid_e = args->arr[i * 2 / 3];
	args->mid_i = args->mid_s + ((args->mid_e - args->mid_s) / 2);
	args->max_i = args->arr[size - 1];
}

static void			swap_sort(int *a, int *b)
{
	int				tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_bool		arr_has_no_repetetive_vals(t_args *args)
{
	int				i;

	i = 1;
	while (args->arr[i])
	{
		if (args->arr[i - 1] == args->arr[i])
			return (false);
		++i;
	}
	return (true);
}

static int			bubble_sort_arr_args(t_args *args, size_t size)
{
	int				i;
	int				sort;

	sort = 0;
	while (sort == 0)
	{
		sort = 1;
		i = 1;
		while (i < size)
		{
			if (args->arr[i - 1] > args->arr[i])
			{
				swap_sort(&args->arr[i - 1], &args->arr[i]);
				sort = 0;
			}
			++i;
		}
	}
	init_args_local(args, size, i);
	if (!(arr_has_no_repetetive_vals(args)))
		return (0);
	return (1);
}

int					args_to_array(t_lst **head, t_args *args)
{
	t_lst			*end;
	size_t			tmp;
	int				i;

	i = 0;
	tmp = (*head)->size;
	end = *head;
	while (end->next && end->next != (*head))
	{
		args->arr[i++] = end->value;
		end = end->next;
	}
	args->arr[i] = end->value;
	++i;
	return (bubble_sort_arr_args(args, (*head)->size));
}
