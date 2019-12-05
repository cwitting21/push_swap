/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spin_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 06:42:28 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/05 22:32:35 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		case_ra_rb(t_lst **head, int code)
{
	rotate(head);
	if (code == 0)
		ft_printf("ra\n");
	else if (code == 1)
		ft_printf("rb\n");
}

static void		case_rra_rrb(t_lst **head, int code)
{
	rev_rotate(head);
	if (code == 0)
		ft_printf("rra\n");
	else if (code == 1)
		ft_printf("rrb\n");
}

void			spin_stack(t_stack *stacks, t_solution sol)
{
	while (sol.num_ra-- > 0)
		case_ra_rb(&stacks->a, 0);
	while (sol.num_rb-- > 0)
		case_ra_rb(&stacks->b, 1);
	while (sol.num_rra-- > 0)
		case_rra_rrb(&stacks->a, 0);
	while (sol.num_rrb-- > 0)
		case_rra_rrb(&stacks->b, 1);
	while (sol.num_rr-- > 0)
	{
		rotate(&stacks->a);
		rotate(&stacks->b);
		ft_printf("rr\n");
	}
	while (sol.num_rrr-- > 0)
	{
		rev_rotate(&stacks->a);
		rev_rotate(&stacks->b);
		ft_printf("rrr\n");
	}
}
