#include "../includes/push_swap.h"

int			pa(t_lst *head_a, t_lst *head_b)
{
    t_lst	*end_a;
    t_lst	*end_b;

	if (head_b->size)
	{
		end_a = head_a;
		end_b = head_b;
		while (end_a->next && end_a->next != head_a)
			end_a = end_a->next;
		while (end_b->next && end_b->next != head_b)
			end_b = end_b->next;
		// work with stack b
		end_b->next = head_b->next;
		head_b->next->prev = end_b;
		// move list from top of stack b to top of stack a
		head_b->next = head_a;
		head_b->prev = end_a;
		end_a->next = head_b;
		head_a->prev = head_b;
		return (1);
	}
	return (0);
}
