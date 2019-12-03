#include "../includes/push_swap.h"

int         stack_is_sorted(t_lst **head_a, t_lst **head_b)
{
	t_lst   *end_a;

	end_a = (*head_a)->next;
	if (!((*head_a)->value < (*head_a)->next->value
		&& (*head_a)->value < (*head_a)->prev->value))
		return (0);
	while (end_a->next && end_a->next != (*head_a))
	{
		if (!(end_a->value > end_a->prev->value && end_a->value < end_a->next->value))
			return (0);
		end_a = end_a->next;
	}
	if (!(end_a->value > end_a->prev->value && end_a->value > (*head_a)->value) || (*head_b))
		return (0);
	return (1);
}