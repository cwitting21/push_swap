#include "../includes/push_swap.h"

int			swap(t_lst **head)
{
	int		tmp;

	if ((*head)->size > 1)
	{
		tmp = (*head)->value;
		(*head)->value = (*head)->next->value;
		(*head)->next->value = tmp;
		return (1);
	}
	return (0);
}