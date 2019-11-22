#include "../includes/push_swap.h"

static void		stack_a_not_empty(t_lst **head_a, t_lst **head_b, t_lst *end_a)
{
	t_lst	*end_b;
	t_lst	*first;

	first = (*head_b);
	end_b = (*head_b);
	if ((*head_b)->size == 1)
	{
		first->next = (*head_a);
		(*head_a)->prev = first;
		first->prev = end_a;
		end_a->next = first;
		(*head_a) = (*head_a)->prev;
		(*head_a)->size = (*head_a)->next->size + 1;
		(*head_b) = NULL;
	}
	else if ((*head_b)->size > 1)
	{
		while (end_b->next && end_b->next != (*head_b))
			end_b = end_b->next;
		(*head_b)->next->prev = end_b;
		end_b->next = (*head_b)->next;
		(*head_b) = (*head_b)->next;
		(*head_b)->size = first->size - 1;
		first->next = (*head_a);
		(*head_a)->prev = first;
		first->prev = end_a;
		end_a->next = first;
		(*head_a) = (*head_a)->prev;
		(*head_a)->size = (*head_a)->next->size + 1;
	}
}

int			pa(t_lst **head_a, t_lst **head_b)
{
	t_lst	*end_a = NULL;

	end_a = *head_a;
	while (end_a->next && end_a->next != (*head_a))
		end_a = end_a->next;
	if ((*head_b)->size)
	{
		stack_a_not_empty(head_a, head_b, end_a);
		return (1);
	}
	return (0);
}
