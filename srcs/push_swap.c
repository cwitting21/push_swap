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

static int				read_commands(t_lst **head_a, t_lst **head_b)
{
	char				*line;
	int					tmp;

	while ((tmp = get_next_line(0, &line)) == 1)
	{
		if (!ft_strcmp("sa", line))
		{
			swap(head_a);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
		else if (!ft_strcmp("sb", line))
		{
			swap(head_b);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
		else if (!ft_strcmp("ss", line))
		{
			ss(head_a, head_b);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
		else if (!ft_strcmp("pa", line))
		{
			pa(head_a, head_b);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
		else if (!ft_strcmp("pb", line))
		{
			pb(head_a, head_b);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
		else if (!ft_strcmp("ra", line))
		{
			rotate(head_a);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
		else if (!ft_strcmp("rb", line))
		{
			rotate(head_b);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
		else if (!ft_strcmp("rr", line))
		{
			rr(head_a, head_b);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
		else if (!ft_strcmp("rra", line))
		{
			rev_rotate(head_a);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
		else if (!ft_strcmp("rrb", line))
		{
			rev_rotate(head_b);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
		else if (!ft_strcmp("rrr", line))
		{
			rrr(head_a, head_b);
			printf("-----STACK A-------\n");
			test_print(head_a);
			printf("-----STACK B-------\n");
			test_print(head_b);
		}
	}
	if (tmp == -1)
		return (0);
	if (get_next_line(0, &line) == 0)
		return (1);
	return (0);
}

int				main(int ac, char **av)
{
	t_lst		*head;
	t_stack		stack;

	stack.a = NULL;
	stack.b = NULL;
	if (ac > 1)
	{
		if (!(args_to_lst(ac, av, &head)))
			return (ft_error());
		stack.a = head;
		read_commands(&stack.a, &stack.b);
		if (stack_is_sorted(&stack.a))
		{
			printf("OK\n");
			printf("-----STACK A-------\n");
			test_print(&stack.a);
		}
		else
		{
			printf("KO\n");
			printf("-----STACK A-------\n");
			test_print(&stack.a);
		}
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
