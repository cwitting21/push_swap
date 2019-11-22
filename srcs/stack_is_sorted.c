#include "../includes/push_swap.h"

int         stack_is_sorted(t_lst **head)
{
	t_lst   *end;

	end = (*head)->next;
	if (!((*head)->value < (*head)->next->value
		&& (*head)->value < (*head)->prev->value))
		return (0);
	while (end->next && end->next != (*head))
	{
		if (!(end->value > end->prev->value && end->value < end->next->value))
			return (0);
		end = end->next;
	}
	if (!(end->value > end->prev->value && end->value > (*head)->value))
		return (0);
	return (1);
}