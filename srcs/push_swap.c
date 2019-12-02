#include "../includes/push_swap.h"

static void		test_print(t_lst **head)
{
	t_lst		*end;

	if (*head)
	{
		end = *head;
		while (end->next && end->next != *head)
		{
			printf("%d\n", end->value);
			end = end->next;
		}
		printf("%d\n", end->value);
		printf("size = %zu\n", (*head)->size);
	}
	else
		printf("stack is empty\n");
}

static void		test_print_2(t_lst **head)
{
	t_lst		*end;

	end = *head;
	printf("pr.pr = %d\n", end->prev->prev->value);
	printf("pr = %d\n", end->prev->value);
	printf("val = %d\n", end->value);
	printf("n = %d\n", end->next->value);
	printf("n.n = %d\n", end->next->next->value);
	
}

static int				ft_error()
{
	write(1, "Error\n", 6);
	return (0);
}

static void				print_stacks(t_lst **head_a, t_lst **head_b)
{
	printf("-----STACK A-------\n");
	test_print(head_a);
	printf("-----STACK B-------\n");
	test_print(head_b);
}
	
// }

// t_bool				array_is_sorted(int *arr)
// {
// 	int				i = 1;

// 	while (arr[i])
// 	{
// 		if (arr[i] < arr[i - 1])
// 			return (false);
// 		++i;
// 	}
// 	return (true);
// }

static void			swap_sort(int *a, int *b)
{
	int				tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static t_bool		arr_has_no_repetetive_vals(t_args *args)
{
	int 			i;

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
	args->min_i = args->arr[0];
	args->mid_s = args->arr[i / 3];
	args->mid_e = args->arr[i * 2 / 3];
	args->mid_i = args->mid_s + ((args->mid_e - args->mid_s) / 2);
	args->max_i = args->arr[size - 1];
	if (!(arr_has_no_repetetive_vals(args)))
		return (0);
	return (1);
}

static t_lst		*from_a_to_b(t_args *args, t_lst **head_a, t_lst **head_b)
{
	t_lst			*end_a;
	t_lst			*end_b;
	t_lst			*start_a = NULL;
	int				code;
	int				tmp = (*head_a)->size;

	end_a = (*head_a);
	if (*head_b)
		end_b = (*head_b)->prev;
	while (tmp-- || tmp > 3)
	{
		code = 1;
		if (end_a->value > args->min_i && end_a->value < args->mid_s)
		{
			pb(&end_a, head_b);
			printf("pb\n");
			rotate(head_b);
			printf("rb\n");
			code = 0;
		}
		else if (end_a->value >= args->mid_s && end_a->value < args->mid_e
		&& end_a->value != args->mid_i)
		{
			pb(&end_a, head_b);
			printf("pb\n");
			code = 0;
		}
		else if (end_a->value >= args->mid_e && end_a->value <= args->max_i)
		{
			rotate(&end_a);
			printf("ra\n");
			code = 0;
		}
		else if (end_a->value == args->min_i || end_a->value == args->mid_i)
		{
			rotate(&end_a);
			printf("ra\n");
			code = 0;
		}
		if (code)
		{
			rotate(head_a);
			printf("ra");
		}
	}
	return (end_a);
}

static int			args_to_array(t_lst **head, t_args *args)
{
	t_lst			*end;
	size_t			tmp;
	int				i = 0;

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

static int		initialise_args(t_args *args, size_t size)
{
	if (!(args->arr = malloc(sizeof(int) * size)))
			return (0);
	// gl++;
	ft_bzero(args->arr, sizeof(args->arr));
	args->max_i = 0;
	args->mid_s = 0;
	args->mid_e = 0;
	args->min_i = 0;
	// printf("GL = %d\n", gl);
	return (1);
}

static void		sort_3_numbers(t_lst **h)
{
	if ((*h)->value < (*h)->prev->value && (*h)->prev->value < (*h)->next->value)
	{
		rev_rotate(h);
		printf("rra\n");
		swap(h);
		printf("sa\n");
	}
	else if ((*h)->value > (*h)->prev->value && (*h)->prev->value > (*h)->next->value)
	{
		rev_rotate(h);
		printf("rra\n");
		rev_rotate(h);
		printf("rra\n");
	}
	else if ((*h)->value > (*h)->next->value && (*h)->prev->value > (*h)->value)
	{
		swap(h);
		printf("sa\n");
	}
	else if ((*h)->value > (*h)->prev->value && (*h)->value < (*h)->next->value)
	{
		rev_rotate(h);
		printf("rra\n");
	}
	else if ((*h)->next->value < (*h)->value && (*h)->next->value > (*h)->prev->value)
	{
		swap(h);
		printf("sa\n");
		rev_rotate(h);
		printf("rra\n");
	}
}

static void		leave_3_nbrs_in_a(t_lst **head_a, t_lst **head_b, t_args *args)
{
	t_lst		*tmp;
	int			code;
	int			i;

	i = (*head_a)->size;
	tmp = (*head_a);
	while (i--)
	{
		code = 1;
		if (tmp->value != args->max_i && tmp->value != args->mid_i
			&& tmp->value != args->min_i)
		{
			pb(&tmp, head_b);
			printf("pb\n");
			code = 0;
		}
		if (code)
		{
			rotate(&tmp);
			printf("ra\n");
		}
	}
	(*head_a) = tmp;
	// printf("\n\n");
	// printf("!!!!! 3 NUMBERS IN STACK A!!!!!!!\n");
	// printf("\n\n");
	// print_stacks(&tmp, head_b);
}

static void		spin_stack(t_stack *stacks, t_solution sol)
{
	t_lst		*end_a;

	// end_a = stacks->a->prev;
	while (sol.num_ra-- > 0)
	{
		rotate(&stacks->a);
		printf("ra\n");
	}
	while (sol.num_rb-- > 0)
	{
		rotate(&stacks->b);
		printf("rb\n");
	}
	while (sol.num_rra-- > 0)
	{
		rev_rotate(&stacks->a);
		printf("rra\n");
	}
	while (sol.num_rrb-- > 0)
	{
		rev_rotate(&stacks->b);
		printf("rrb\n");
	}
	while (sol.num_rr-- > 0)
	{
		rotate(&stacks->a);
		rotate(&stacks->b);
		printf("rr\n");
	}
	while (sol.num_rrr-- > 0)
	{
		rev_rotate(&stacks->a);
		rev_rotate(&stacks->b);
		printf("rrr\n");
	}
	// while ((*head_b)->value < end_a->value && (*head_b)->value > (*head_a)->value)
	// {
	// 	// print_stacks(head_a, head_b);
	// 	rotate(head_a);
	// 	printf("ra\n");
	// 	// print_stacks(head_a, head_b);
	// }
	// end_a = (*head_a)->prev;
	// if ((*head_b)->value < (*head_a)->value && (*head_b)->value < end_a->value)
	// {
	// 	while ((*head_b)->value < end_a->value)
	// 	{
	// 		rev_rotate(head_a);
	// 		printf("rra\n");
	// 		// print_stacks(head_a, head_b);
	// 		end_a = (*head_a)->prev;
	// 		// print_stacks(head_a, head_b);
	// 	}
	// }
	// if ((*head_b)->value > (*head_a)->value && (*head_b)->value > end_a->value)
	// {
	// 	while((*head_b)->value > (*head_a)->value)
	// 	{
	// 		// print_stacks(head_a, head_b);
	// 		rotate(head_a);
	// 		printf("ra\n");
	// 		// print_stacks(head_a, head_b);
	// 	}
	// }
}

static int				get_insert_index(t_lst **head_a, int num)
{
	t_lst				*cur;
	size_t				i;

	i = 0;
	cur = (*head_a);
	while (cur->value < num || cur->prev->value > num)
	{
		cur = cur->next;
		++i;
	}
	return (i);
}

static t_solution		get_solution(t_stack *stacks, int num, size_t i) // i - index of element at stack b
{
	t_solution			solve[4]; // 0 - up, 1 - down, 2 - up_down, 3 - down_up
	t_direction			cur_dir;
	t_direction			best_dir;
	int					min_cmd;

	ft_bzero(solve, sizeof(t_solution) * 4);
	solve[UP].num_rb = i;
	solve[UP].num_ra = get_insert_index(&stacks->a, num);
	solve[UP].num_rr = (solve[UP].num_rb > solve[UP].num_ra ? solve[UP].num_ra : solve[UP].num_rb);
	solve[UP].num_ra -= solve[UP].num_rr;
	solve[UP].num_rb -= solve[UP].num_rr;
	solve[UP].num_all = solve[UP].num_ra + solve[UP].num_rb + solve[UP].num_rr;

	solve[DOWN].num_rra = stacks->size_a - get_insert_index(&stacks->a, num);
	solve[DOWN].num_rrb = stacks->size_b - i;
	solve[DOWN].num_rrr = (solve[DOWN].num_rrb > solve[DOWN].num_rra ? solve[DOWN].num_rra : solve[DOWN].num_rrb);
	solve[DOWN].num_rra -= solve[DOWN].num_rrr;
	solve[DOWN].num_rrb -= solve[DOWN].num_rrr;
	solve[DOWN].num_all = solve[DOWN].num_rra + solve[DOWN].num_rrb + solve[DOWN].num_rrr;

	solve[UP_DOWN].num_ra = get_insert_index(&stacks->a, num);
	solve[UP_DOWN].num_rrb = stacks->size_b - i;
	solve[UP_DOWN].num_all = solve[UP_DOWN].num_ra + solve[UP_DOWN].num_rrb;

	solve[DOWN_UP].num_rra = stacks->size_a - get_insert_index(&stacks->a, num);
	solve[DOWN_UP].num_rb = i;
	solve[DOWN_UP].num_all = solve[DOWN_UP].num_rra + solve[DOWN_UP].num_rb;

	cur_dir = FIRST;
	min_cmd = solve[FIRST].num_all;
	best_dir = cur_dir;
	while(cur_dir != LAST)
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

	// init sols ;
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

static void		clean_one_stack(t_lst *head, size_t size)
{
	if (size)
	{
		clean_one_stack(head->next, size - 1);
		if (head)
		{
			gl1++;
			free(head);
			head = NULL;
		}
	}
	// printf("LALALA = %d\n", gl1);
}

static void		destroy_stack(t_stack *stacks)
{
	clean_one_stack(stacks->a, stacks->size_a);
	clean_one_stack(stacks->b, stacks->size_b);
}

static void		final_sort(t_lst **head, t_args args)
{
	t_lst		*tmp;
	t_lst		*tmp2;
	size_t		i;
	size_t		n;

	i = 0;
	n = 0;
	tmp = (*head);
	tmp2 = (*head);
	while (tmp->value != args.min_i)
	{
		rev_rotate(&tmp);
		++i;
	}
	while (tmp2->value != args.min_i)
	{
		rotate(&tmp2);
		++n;
	}
	if (i < n)
	{
		while ((*head)->value != args.min_i)
		{
			rev_rotate(head);
			printf("rra\n");
		}
	}
	else
	{
		while ((*head)->value != args.min_i)
		{
			rotate(head);
			printf("ra\n");
		}
	}
}

static void		sort_lists_hard(t_lst **head_a, t_lst **head_b, t_args args)
{
	t_lst		*end_a;
	// t_lst		*crnt_b;
	size_t		b_size;
	t_solution	sol;
	t_stack				stacks;

	b_size = (*head_b)->size;
	stacks.size_a = (*head_a)->size;
	stacks.size_b = (*head_b)->size;
	stacks.a = (*head_a);
	stacks.b = (*head_b);
	// print_stacks(head_a, head_b);
	// while stack.b has elements
	while (stacks.size_b)
	{
		sol = check_stack_b(&stacks);
		spin_stack(&stacks, sol);
		// end_a = (*head_a)->prev;
		// if ((*head_b)->value > end_a->value && (*head_b)->value < (*head_a)->value)
		// {
			// print_stacks(head_a, head_b);

			// print_stacks(&stacks.a, &stacks.b);
			pa(&stacks.a, &stacks.b);
			// print_stacks(&stacks.a, &stacks.b);
			printf("pa\n");
			--stacks.size_b;
			++stacks.size_a;
			// print_stacks(&stacks.a, &stacks.b);
		// }
	}
	final_sort(&stacks.a, args);
	// printf("--------- END -----------\n");
	// print_stacks(&stacks.a, &stacks.b);
	destroy_stack(&stacks);
}

// static void		sort_lists_simple(t_lst **head_a, t_lst **head_b)
// {

// }

static void		sort_5_numbers(t_lst **head_a, t_lst **head_b)
{
	while ((*head_a)->size > 3)
		pb(head_a, head_b);
	sort_3_numbers(head_a);
	printf("!!!!!!!!!!!!!!!!!!!!\n");
	print_stacks(head_a, head_b);
	// sort_lists_simple(head_a, head_b);
	print_stacks(head_a, head_b);
}

int				main(int ac, char **av)
{
	t_lst		*head;
	t_stack		stack;
	t_args		args;
	t_lst		*start_a;

	stack.a = NULL;
	stack.b = NULL;
	start_a = NULL;
	if (ac > 1)
	{
		if (!(args_to_lst(ac, av, &head)) || !(initialise_args(&args, head->size)) ||
		!(args_to_array(&head, &args)))
			return (ft_error());
		stack.a = head;
		if (head->size > 5)
		{
			start_a = from_a_to_b(&args, &stack.a, &stack.b);
			leave_3_nbrs_in_a(&start_a, &stack.b, &args);
			sort_3_numbers(&start_a);
			sort_lists_hard(&start_a, &stack.b, args);
		}
		else if (head->size == 3)
		{
			sort_3_numbers(&stack.a);
		}
		else if (head->size > 3 && head->size <= 5)
		{
			sort_5_numbers(&stack.a, &stack.b);
		}
	}
	// exit(EXIT_SUCCESS);
	free(args.arr);
	return (0);
}