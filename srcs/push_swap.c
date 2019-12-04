/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:13:06 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 12:18:12 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		sort(t_lst **head_a, t_lst **head_b, t_args *args)
{
	leave_3_nbrs_in_a(head_a, head_b, args);
	sort_3_numbers(head_a);
	sort_lists_hard(head_a, head_b, args);
}

static void		null_args(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
}

int				main(int ac, char **av)
{
	t_stack		s;
	t_args		args;

	null_args(&s);
	if (ac > 1)
	{
		if (!(args_to_lst(ac, av, &s.a))
		|| !(init_args(&args, s.a->size)) || !(args_to_array(&s.a, &args)))
			return (ft_error());
		printf("ARGS\n");
		for (int i = 0; i < s.a->size; i++)
			printf("%d ", args.arr[i]);
		printf("\n\n");
		if (!list_is_sorted(s.a))
		{
			if (s.a->size > 5)
			{
				from_a_to_b(&args, &s.a, &s.b);
				sort(&s.a, &s.b, &args);
			}
			else if (s.a->size == 3)
				sort_3_numbers(&s.a);
			else if (s.a->size > 3 && s.a->size <= 5)
				sort_5_numbers(&s.a, &s.b, &args);
		}
	}
	free(args.arr);
	exit(EXIT_SUCCESS);
}
