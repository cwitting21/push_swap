/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:42:58 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/07 23:41:37 by cwitting         ###   ########.fr       */
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
			free(head);
			head = NULL;
		}
	}
}

static void		clean_local(t_lst *h_a, t_lst *h_b, t_args *args)
{
	if (args->arr)
		free(args->arr);
	if (h_a)
		clean_one_stack(h_a, h_a->size);
	if (h_b)
		clean_one_stack(h_b, h_b->size);
}

int				main(int ac, char **av)
{
	t_lst		*head;
	t_stack		stack;
	t_args		args;
	int			ret;

	stack.a = NULL;
	stack.b = NULL;
	head = NULL;
	ret = 1;
	if (ac > 1)
	{
		printf("0000000000\n");
		if (!(args_to_lst(ac, av, &head)) || !(init_args(&args, head->size)) ||
		!(args_to_array(&head, &args)))
			return (ft_error_and_free(head, &args));
		printf("111\n");
		stack.a = head;
		// printf("111\n");
		ret = read_commands(&stack.a, &stack.b);
		// printf("111\n");
		// printf("ret = %d\n", ret);
		if ((stack_is_sorted(&stack.a, &stack.b) || stack.a->size == 1) && ret != 0)
			ft_printf("OK\n");
		else if (!stack_is_sorted(&stack.a , &stack.b) && ret != 0)
			ft_printf("KO\n");
		clean_local(stack.a, stack.b, &args);
	}
	exit(EXIT_SUCCESS);
}
