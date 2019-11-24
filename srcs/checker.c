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

static int				read_commands(t_lst **head_a, t_lst **head_b)
{
	char				*line;
	int					tmp;

	while ((tmp = get_next_line(0, &line)) == 1)
	{
		if (!ft_strcmp("sa", line))
		{
			swap(head_a);
			print_stacks(head_a, head_b);
		}
		else if (!ft_strcmp("sb", line))
		{
			swap(head_b);
			print_stacks(head_a, head_b);
		}
		else if (!ft_strcmp("ss", line))
		{
			ss(head_a, head_b);
			print_stacks(head_a, head_b);
		}
		else if (!ft_strcmp("pa", line))
		{
			pa(head_a, head_b);
			print_stacks(head_a, head_b);
		}
		else if (!ft_strcmp("pb", line))
		{
			pb(head_a, head_b);
			print_stacks(head_a, head_b);
		}
		else if (!ft_strcmp("ra", line))
		{
			rotate(head_a);
			print_stacks(head_a, head_b);
		}
		else if (!ft_strcmp("rb", line))
		{
			rotate(head_b);
			print_stacks(head_a, head_b);
		}
		else if (!ft_strcmp("rr", line))
		{
			rr(head_a, head_b);
			print_stacks(head_a, head_b);
		}
		else if (!ft_strcmp("rra", line))
		{
			rev_rotate(head_a);
			print_stacks(head_a, head_b);
		}
		else if (!ft_strcmp("rrb", line))
		{
			rev_rotate(head_b);
			print_stacks(head_a, head_b);
		}
		else if (!ft_strcmp("rrr", line))
		{
			rrr(head_a, head_b);
			print_stacks(head_a, head_b);
		}
		else
			return (ft_error());
	}
	ft_strdel(&line);
	if (tmp == -1)
		return (0);
	if (get_next_line(0, &line) == 0)
		return (1);
	return (0);
}

// static void			q_sort_arr_args(t_args *args, size_t size)
// {
// 	size_t			pivot;
// 	size_t			*left_ptr;
// 	size_t			*right_ptr;

// 	pivot = args->arr[size - 1];
// 	left_ptr = args->arr[0];
// 	right_ptr = args->arr[size - 2];
// 	while (*left_ptr < pivot)
// 		left_ptr++;
// 	while (*right_ptr >= pivot)
// 	{
// 		if (left_ptr = right_ptr)
// 			break;
// 		right_ptr++;
// 	}
// 	if (left_ptr = right_ptr)
// 		swap(*left_ptr (or *right_ptr), pivot) // *left_ptr (or right is sorted
// 	else
// 		swap(*left_ptr, *right_ptr);
	

// }

t_bool				array_is_sorted(int *arr)
{
	int				i = 1;

	while (arr[i])
	{
		if (arr[i] < arr[i - 1])
			return (false);
		++i;
	}
	return (true);
}

static void			swap_sort(int *a, int *b)
{
	int				tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
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
	args->max_i = args->arr[size - 1];
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

static int			args_to_array(t_lst **head)
{
	t_lst			*end;
	t_args			args;
	size_t			tmp;
	int				i = 0;

	tmp = (*head)->size;
	if (!(args.arr = malloc(sizeof(int) * tmp)))
		return (0);
	ft_bzero(args.arr, sizeof(args.arr));
	args.max_i = 0;
	args.mid_s = 0;
	args.mid_e = 0;
	args.min_i = 0;
	end = *head;
	while (end->next && end->next != (*head))
	{
		args.arr[i++] = end->value;
		end = end->next;
	}
	args.arr[i] = end->value;
	++i;
	printf("ARR BEFORE\n");
	for (int m = 0; m < (*head)->size; m++)
		printf("%d\n", args.arr[m]);
	// q_sort_arr_args(&args, (*head)->size);
	bubble_sort_arr_args(&args, (*head)->size);
	printf("ARR AFTER SORT\n");
	for (int m = 0; m < (*head)->size; m++)
		printf("%d\n", args.arr[m]);
	if (!(arr_has_no_repetetive_vals(&args)))
		printf("ERROR REP VAL\n");
	if (!(array_is_sorted(args.arr)))
		printf("ERROR ARR NOT SORTED\n");
	return (1);
}

int					main(int ac, char **av)
{
	t_lst		*head;
	t_stack		stack;

	stack.a = NULL;
	stack.b = NULL;
	if (ac > 1)
	{
		if (!(args_to_lst(ac, av, &head)))
			return (ft_error());
		args_to_array(&head);
		// stack.a = head;
		// read_commands(&stack.a, &stack.b);
		// if (stack_is_sorted(&stack.a))
		// {
		// 	printf("OK\n");
		// 	printf("-----STACK A-------\n");
		// 	test_print(&stack.a);
		// }
		// else
		// {
		// 	printf("KO\n");
		// 	printf("-----STACK A-------\n");
		// 	test_print(&stack.a);
		// }
		// printf("-----STACK A before\n");
		// test_print(&stack.a);
		// while (stack.a->size > 3)
			// pb(&stack.a, &stack.b);
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
