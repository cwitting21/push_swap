#include "../includes/push_swap.h"

t_lst			*new_lst(int value)
{
	t_lst		*new;
	static int	i = 0;

	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	new->value = value;
	new->next = new;
	new->prev = new;
	new->size = 0;
	new->oper = 0;
	// i++;
	// printf("I = %d\n", i);
	return (new);
}
