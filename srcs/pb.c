#include "../includes/push_swap.h"

int			pb(t_lst **head_a, t_lst **head_b)
{
	t_lst	*end_a = NULL;
	t_lst	*end_b = NULL;

	if (!*head_b && (*head_a)->size)
	{
		end_a = *head_a;
		while (end_a->next && end_a->next != (*head_a))
			end_a = end_a->next;
		(*head_a)->next->size = (*head_a)->size - 1;
		*head_b = *head_a;
		(*head_a)->next->prev = end_a;
		end_a->next = (*head_a)->next;
		(*head_b)->size = 1;
		(*head_a) = (*head_a)->next;
		end_a->next = (*head_a);
		(*head_a)->prev = end_a;
		(*head_b)->next = (*head_b);
		(*head_b)->prev = (*head_b);
		return (1);
	}
	if ((*head_a)->size && *head_b)
	{
		end_a = *head_a;
		end_b = *head_b;
		while (end_a->next && end_a->next != (*head_a))
			end_a = end_a->next;
		while (end_b->next && end_b->next != (*head_b))
			end_b = end_b->next;
		// work with stack a
		end_a->next = (*head_a)->next;
		(*head_a)->next->prev = end_a;
		// move list from top of stack a to top of stack b
		(*head_a)->next = (*head_b);
		(*head_a)->prev = end_b;
		end_b->next = (*head_a);
		(*head_b)->prev = (*head_a);
		(*head_a) = (*head_a)->next;
		return (1);
	}
	return (0);
}