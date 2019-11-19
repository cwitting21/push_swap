#include "../includes/push_swap.h"

t_lst			*new_lst(int value)
{
	t_lst	*new;
	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
		return (NULL);
	new->value = value;
	new->head = NULL;
	new->next = NULL;
	new->prev = NULL;
	new->size = 0;
	//initialise(stack);
	return (new);
}
