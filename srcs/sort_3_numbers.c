/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:13:17 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/05 21:29:41 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	case_1(t_lst **h)
{
	rev_rotate(h);
	ft_printf("rra\n");
	swap(h);
	ft_printf("sa\n");
}

static void	case_2(t_lst **h)
{
	swap(h);
	ft_printf("sa\n");
	rev_rotate(h);
	ft_printf("rra\n");
}

void		sort_3_numbers(t_lst **h)
{
	if ((*h)->value < (*h)->prev->value
		&& (*h)->prev->value < (*h)->next->value)
		case_1(h);
	else if ((*h)->value > (*h)->prev->value
		&& (*h)->prev->value > (*h)->next->value)
	{
		rotate(h);
		ft_printf("ra\n");
	}
	else if ((*h)->value > (*h)->next->value && (*h)->prev->value > (*h)->value)
	{
		swap(h);
		ft_printf("sa\n");
	}
	else if ((*h)->value > (*h)->prev->value && (*h)->value < (*h)->next->value)
	{
		rev_rotate(h);
		ft_printf("rra\n");
	}
	else if ((*h)->next->value < (*h)->value
		&& (*h)->next->value > (*h)->prev->value)
		case_2(h);
}
