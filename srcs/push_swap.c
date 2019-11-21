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
}

int				ft_error()
{
	write(1, "Error\n", 6);
	return (0);
}

int				main(int ac, char **av)
{
	t_lst		*head;
	// t_stack		stack;

	if (ac > 1)
	{
		// stack.a = NULL;
		// stack.b = NULL;
		//initialise_stack(&stack);
		if (!(args_to_lst(ac, av, &head)))
			return (ft_error());
		test_print(&head);
	}
	// printf("%d\n", stack.a->value);
	// printf("%d\n", stack.a->next->value);
	return (0);
}
