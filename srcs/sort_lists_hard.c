/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lists_hard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:13:17 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/05 22:57:19 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void				first_step(t_solution *solve, size_t i, t_stack *s,
						int num)
{
	solve[UP].num_rb = i;
	solve[UP].num_ra = get_insert_index(&s->a, num);
	solve[UP].num_rr = (solve[UP].num_rb > solve[UP].num_ra ?
	solve[UP].num_ra : solve[UP].num_rb);
	solve[UP].num_ra -= solve[UP].num_rr;
	solve[UP].num_rb -= solve[UP].num_rr;
	solve[UP].num_all = solve[UP].num_ra + solve[UP].num_rb + solve[UP].num_rr;
	solve[DOWN].num_rra = s->size_a - get_insert_index(&s->a, num);
	solve[DOWN].num_rrb = s->size_b - i;
	solve[DOWN].num_rrr = (solve[DOWN].num_rrb > solve[DOWN].num_rra ?
	solve[DOWN].num_rra : solve[DOWN].num_rrb);
	solve[DOWN].num_rra -= solve[DOWN].num_rrr;
	solve[DOWN].num_rrb -= solve[DOWN].num_rrr;
	solve[DOWN].num_all = solve[DOWN].num_rra + solve[DOWN].num_rrb +
	solve[DOWN].num_rrr;
}

static void				second_step(t_solution *solve, size_t i, t_stack *s,
						int num)
{
	solve[UP_DOWN].num_ra = get_insert_index(&s->a, num);
	solve[UP_DOWN].num_rrb = s->size_b - i;
	solve[UP_DOWN].num_all = solve[UP_DOWN].num_ra + solve[UP_DOWN].num_rrb;
	solve[DOWN_UP].num_rra = s->size_a - get_insert_index(&s->a, num);
	solve[DOWN_UP].num_rb = i;
	solve[DOWN_UP].num_all = solve[DOWN_UP].num_rra + solve[DOWN_UP].num_rb;
}

static t_solution		get_solution(t_stack *stacks, int num, size_t i)
{
	t_solution			solve[4];
	t_direction			cur_dir;
	t_direction			best_dir;
	int					min_cmd;

	ft_bzero(solve, sizeof(t_solution) * 4);
	first_step(solve, i, stacks, num);
	second_step(solve, i, stacks, num);
	cur_dir = FIRST;
	min_cmd = solve[FIRST].num_all;
	best_dir = cur_dir;
	while (cur_dir <= LAST)
	{
		if (solve[cur_dir].num_all < min_cmd)
		{
			best_dir = cur_dir;
			min_cmd = solve[cur_dir].num_all;
		}
		cur_dir++;
	}
	return (solve[best_dir]);
}

static t_solution		check_stack_b(t_stack *stacks)
{
	t_solution			best_sol;
	t_solution			cur_sol;
	size_t				size;
	size_t				i;
	t_lst				*end_b;

	ft_bzero(&best_sol, sizeof(t_solution));
	ft_bzero(&cur_sol, sizeof(t_solution));
	i = 0;
	end_b = stacks->b;
	size = stacks->size_b;
	best_sol = get_solution(stacks, end_b->value, i);
	while (i < size)
	{
		cur_sol = get_solution(stacks, end_b->value, i);
		if (cur_sol.num_all < best_sol.num_all)
			best_sol = cur_sol;
		end_b = end_b->next;
		++i;
	}
	return (best_sol);
}

void					sort_lists_hard(t_lst **head_a, t_lst **head_b,
						t_args *args)
{
	t_lst				*end_a;
	size_t				b_size;
	t_solution			sol;
	t_stack				stacks;

	b_size = (*head_b)->size;
	stacks.size_a = (*head_a)->size;
	stacks.size_b = (*head_b)->size;
	stacks.a = (*head_a);
	stacks.b = (*head_b);
	while (stacks.size_b)
	{
		sol = check_stack_b(&stacks);
		spin_stack(&stacks, sol);
		pa(&stacks.a, &stacks.b);
		ft_printf("pa\n");
		--stacks.size_b;
		++stacks.size_a;
	}
	final_sort(&stacks.a, args);
	destroy_stacks(&stacks);
}
