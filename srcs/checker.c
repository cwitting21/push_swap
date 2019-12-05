/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:42:58 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/05 21:28:56 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int					main(int ac, char **av)
{
	t_lst		*head;
	t_stack		stack;
	t_args		args;

	stack.a = NULL;
	stack.b = NULL;
	if (ac > 1)
	{
		if (!(args_to_lst(ac, av, &head)) || !(init_args(&args, head->size)) ||
		!(args_to_array(&head, &args)))
			return (ft_error());
		stack.a = head;
		read_commands(&stack.a, &stack.b);
		if (stack_is_sorted(&stack.a, &stack.b) || stack.a->size == 1)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
