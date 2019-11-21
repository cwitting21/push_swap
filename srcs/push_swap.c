#include "../includes/push_swap.h"

static void		test_print(t_lst **head)
{
	t_lst		*end;

	end = *head;
	while (end->next && end->next != *head)
	{
		printf("%d\n", end->value);
		end = end->next;
	}
	printf("%d\n", end->value);
	printf("size = %zu\n", (*head)->size);
}

static void		test_print_2(t_lst **head)
{
	t_lst		*end;

	end = *head;
	printf("%d\n", end->value);
	printf("%d\n", end->next->value);
	printf("%d\n", end->next->next->value);
	
}

int				ft_error()
{
	write(1, "Error\n", 6);
	return (0);
}

int				main(int ac, char **av)
{
	t_lst		*head;
	t_stack		stack;

	stack.a = NULL;
	stack.b = NULL;
	// stack.b = NULL;
	if (ac > 1)
	{
		// stack.a = NULL;
		// stack.b = NULL;
		//initialise_stack(&stack);
		if (!(args_to_lst(ac, av, &head)))
			return (ft_error());
		stack.a = head;
		test_print(&stack.a);
		pb(&stack.a, &stack.b);
		pb(&stack.a, &stack.b);
		printf("-----STACK A-------\n");
		test_print(&stack.a);
		printf("-----STACK B-------\n");
		test_print(&stack.b);
		// printf("-----TEST A-------\n");
		// test_print_2(&stack.a);
		// printf("-----TEST B-------\n");
		// test_print_2(&stack.b);
	}
	// printf("%d\n", stack.a->value);
	// printf("%d\n", stack.a->next->value);
	return (0);
}
