/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:34:18 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 05:27:29 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	case_4(t_lst **head_a)
{
	rotate(head_a);
	printf("ra");
}

static void	case_3(t_lst **end_a, int *code)
{
	rotate(end_a);
	printf("ra\n");
	*code = 0;
}

static void	case_2(t_lst **end_a, t_lst **head_b, int *code)
{
	pb(end_a, head_b);
	printf("pb\n");
	*code = 0;
}

static void	case_1(t_lst **end_a, t_lst **head_b, int *code)
{
	pb(end_a, head_b);
	printf("pb\n");
	rotate(head_b);
	printf("rb\n");
	*code = 0;
}

void		*from_a_to_b(t_args *args, t_lst **head_a, t_lst **head_b)
{
	t_lst			*end_a;
	int				code;
	int				tmp;

	tmp = (*head_a)->size;
	end_a = (*head_a);
	while (tmp-- || tmp > 3)
	{
		code = 1;
		if (end_a->value > args->min_i && end_a->value < args->mid_s)
			case_1(&end_a, head_b, &code);
		else if (end_a->value >= args->mid_s && end_a->value <= args->mid_e
		&& end_a->value != args->mid_i)
			case_2(&end_a, head_b, &code);
		else if ((end_a->value > args->mid_e && end_a->value <= args->max_i)
			|| (end_a->value == args->min_i || end_a->value == args->mid_i))
			case_3(&end_a, &code);
		if (code)
			case_4(head_a);
	}
	(*head_a) = end_a;
}
