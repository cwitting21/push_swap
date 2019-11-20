#include "../includes/push_swap.h"
#include <stdio.h>

int				main(int ac, char **av)
{
	t_stack		stack;

	stack.a = NULL;
	stack.b = NULL;
	//initialise_stack(&stack);
	validation(ac, av, &stack);
	// printf("%d\n", stack.a->next->value);
	// printf("%d\n", stack.a->next->next->value);
	return (0);
}
