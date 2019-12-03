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

static void				print_stacks(t_lst **head_a, t_lst **head_b)
{
	printf("-----STACK A-------\n");
	test_print(head_a);
	printf("-----STACK B-------\n");
	test_print(head_b);
}

static int				ft_error()
{
	write(1, "Error\n", 6);
	return (0);
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
			ft_strdel(&line);
		}
		else if (!ft_strcmp("sb", line))
		{
			swap(head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("ss", line))
		{
			ss(head_a, head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("pa", line))
		{
			pa(head_a, head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("pb", line))
		{
			pb(head_a, head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("ra", line))
		{
			rotate(head_a);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("rb", line))
		{
			rotate(head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("rr", line))
		{
			rr(head_a, head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("rra", line))
		{
			rev_rotate(head_a);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("rrb", line))
		{
			rev_rotate(head_b);
			ft_strdel(&line);
		}
		else if (!ft_strcmp("rrr", line))
		{
			rrr(head_a, head_b);
			ft_strdel(&line);
		}
		else
		{
			ft_strdel(&line);
			return (ft_error());
		}
	}
	ft_strdel(&line);
	if (tmp == -1)
		return (0);
	if (get_next_line(0, &line) == 0)
	{
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

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

int					main(int ac, char **av)
{
	t_lst		*head;
	t_stack		stack;
	t_args		args;

	stack.a = NULL;
	stack.b = NULL;
	if (ac > 1)
	{
		if (!(args_to_lst(ac, av, &head)) || !(initialise_args(&args, head->size)) ||
		!(args_to_array(&head, &args)))
			return (ft_error());
		stack.a = head;
		read_commands(&stack.a, &stack.b);
		if (stack_is_sorted(&stack.a, &stack.b))
			printf("OK\n");
		else
			printf("KO\n");
	}
	return (0);
}
