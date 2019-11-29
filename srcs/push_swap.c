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
		if (end_a->value > args->min_i && end_a->value <= args->mid_s)
		{
			pb(&end_a, head_b);
			printf("pb\n");
			rev_rotate(head_b); // rrb
			printf("rrb\n");
			code = 0;
		}
		else if (end_a->value > args->mid_s && end_a->value <= args->mid_e
		&& end_a->value != args->mid_i)
		{
			pb(&end_a, head_b);
			printf("pb\n");
			code = 0;
		}
		else if (end_a->value > args->mid_e && end_a->value <= args->max_i)
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
			end_a->next->size = end_a->size - 1;
			end_a = end_a->next; // change to ra (rra) ?
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
	ft_bzero(args->arr, sizeof(args->arr));
	args->max_i = 0;
	args->mid_s = 0;
	args->mid_e = 0;
	args->min_i = 0;
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

// static void		sort_5_numbers(t_lst **head_a, t_lst **head_b)
// {
// 	while ((*head_a)->size > 3)
// 		pb(head_a, head_b);
// 	sort_3_numbers(head_a);
// 	printf("!!!!!!!!!!!!!!!!!!!!\n");
// 	print_stacks(head_a, head_b);
// }

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
	// printf("!!!!!!!!!!!!\n");
	// print_stacks(&tmp, head_b);
}

static void		spin_stack(t_lst **head_a, t_lst **head_b)
{
	t_lst		*end_a;

	end_a = (*head_a)->prev;
	while ((*head_b)->value < end_a->value && (*head_b)->value > (*head_a)->value)
	{
		// print_stacks(head_a, head_b);
		rotate(head_a);
		printf("ra\n");
		// print_stacks(head_a, head_b);
	}
	end_a = (*head_a)->prev;
	if ((*head_b)->value < (*head_a)->value && (*head_b)->value < end_a->value)
	{
		while ((*head_b)->value < end_a->value)
		{
			rev_rotate(head_a);
			printf("rra\n");
			// print_stacks(head_a, head_b);
			end_a = (*head_a)->prev;
		}
	}
	if ((*head_b)->value > (*head_a)->value && (*head_b)->value > end_a->value)
	{
		while((*head_b)->value > (*head_a)->value)
		{
			// print_stacks(head_a, head_b);
			rotate(head_a);
			printf("ra\n");
			// print_stacks(head_a, head_b);
		}
	}
}

static void		sort_lists(t_lst **head_a, t_lst **head_b)
{
	t_lst		*end_a;
	// t_lst		*crnt_b;
	size_t		b_size;

	b_size = (*head_b)->size;
	// print_stacks(head_a, head_b);
	// while stack.b has elements
	while (b_size--)
	{
		spin_stack(head_a, head_b);
		end_a = (*head_a)->prev;
		if ((*head_b)->value > end_a->value && (*head_b)->value < (*head_a)->value)
		{
			// print_stacks(head_a, head_b);
			pa(head_a, head_b);
			printf("pa\n");
			// print_stacks(head_a, head_b);
		}
	}
}

static void		final_sort(t_lst **head, t_args args)
{
	while ((*head)->value != args.min_i)
	{
		rev_rotate(head);
		printf("rra\n");
	}
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
			sort_lists(&start_a, &stack.b);
			final_sort(&start_a, args);
		}
		else if (head->size == 3)
		{
			sort_3_numbers(&stack.a);
			// print_stacks(&stack.a, &stack.b);
		}
		// else if (head->size > 3 && head->size <= 5)
		// {
			// sort_5_numbers(&stack.a, &stack.b);
		// }
		// printf("---------------------\n");
		// print_stacks(&start_a, &stack.b);
	}
	return (0);
}