#include "../includes/push_swap.h"

void			initialise(t_stack *stack)
{
	stack->a = NULL;
	stack->a->head = NULL;
	stack->a->prev = NULL;
	stack->a->next = NULL;
	stack->a->size = 0;
	stack->b = NULL;
	stack->b->head = NULL;
	stack->b->prev = NULL;
	stack->b->next = NULL;
	stack->b->size = 0;
}

int				main(int ac, char **av)
{
	t_stack		stack;

	initialise(&stack);
	validation(ac, av, &stack);
	return (0);
}
