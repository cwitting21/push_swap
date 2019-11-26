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

static void			bubble_sort_arr_args(t_args *args, size_t size)
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
		printf("Error\n");
}

static void			sort_lists(t_args *args, t_lst **head_a, t_lst **head_b)
{
	t_lst			*end_a;
	t_lst			*end_b;
	t_lst			*start_a = NULL;
	int				code;

	end_a = (*head_a);
	if (*head_b)
		end_b = (*head_b)->prev;
	code = 1;
	while (end_a->next != (*head_a))
	{
		if (end_a->value > args->min_i && end_a->value <= args->mid_s)
		{
			pb(&end_a, head_b);
			(*head_a) = end_a;
			print_stacks(&end_a, head_b);
			printf("!!!!!!!!!!!!!!!!!!!!!\n");
			print_stacks(head_a, head_b);
			// printf("STACK A!!!\n");
			// test_print(head_a);
			// test_print_2(head_a);
			rev_rotate(head_b); // rrb
			code = 0;
		}
		else if (end_a->value > args->mid_s && end_a->value <= args->mid_e
		&& end_a->value != args->mid_i)
			pb(&end_a, head_b);
		else if (end_a->value > args->mid_e && end_a->value < args->max_i)
		{
			rotate(&end_a);
			code = 1;
		}
		if (code)
		{
			end_a->next->size = end_a->size - 1;
			end_a = end_a->next;
		}
	}
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
	// printf("ARR BEFORE\n");
	// for (int m = 0; m < (*head)->size; m++)
	// 	printf("%d\n", args.arr[m]);
	bubble_sort_arr_args(args, (*head)->size);
	// printf("ARR AFTER SORT\n");
	// for (int m = 0; m < (*head)->size; m++)
	// 	printf("%d\n", args->arr[m]);
	return (1);
}

int					main(int ac, char **av)
{
	t_lst		*head;
	t_stack		stack;
	t_args		args;

	stack.a = NULL;
	stack.b = NULL;
	if (ac > 1)
	{
		if (!(args_to_lst(ac, av, &head)))
			return (ft_error());
		stack.a = head;
		if (!(args.arr = malloc(sizeof(int) * head->size)))
			return (0);
		ft_bzero(args.arr, sizeof(args.arr));
		args.max_i = 0;
		args.mid_s = 0;
		args.mid_e = 0;
		args.min_i = 0;
		args_to_array(&head, &args);
		sort_lists(&args, &stack.a, &stack.b);
		printf("STACKS\n");
		print_stacks(&stack.a, &stack.b);
		// printf("-----STACK A before\n");
		// test_print(&stack.a);
		// pb(&stack.a, &stack.b);
		// pb(&stack.a, &stack.b);
		// pb(&stack.a, &stack.b);
		// pb(&stack.a, &stack.b);
		// printf("-----STACK B-------\n");
		// test_print(&stack.b);
		// printf("!!!!!!!!!!!\n");
		// printf("sorted = %d\n", stack_is_sorted(&stack.a));
		// swap(&stack.a);
		// ss(&stack.a, &stack.b);
		// rr(&stack.a, &stack.b);
		// pa(&stack.a, &stack.b);
		// rotate(&stack.a);
		// rrr(&stack.a, &stack.b);
		// printf("-----STACK A-------\n");
		// test_print(&stack.a);
		// printf("-----STACK B-------\n");
		// test_print(&stack.b);
		// printf("-----TEST A-------\n");
		// test_print_2(&stack.a);
		// printf("-----TEST B-------\n");
		// test_print_2(&stack.b);
	}
	return (0);
}