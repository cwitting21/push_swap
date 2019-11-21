#include "../includes/push_swap.h"

int			pb(t_lst **head_a, t_lst **head_b)
{
	t_lst	*end_a = NULL;
	t_lst	*end_b = NULL;
	t_lst	*head_a_dup = NULL;
	t_lst	*tmp = NULL;

	end_a = *head_a;
	while (end_a->next && end_a->next != (*head_a))
		end_a = end_a->next;
	if (!*head_b && (*head_a)->size)
	{
		(*head_a)->next->size = (*head_a)->size - 1;
		(*head_b) = *head_a;
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
	if (*head_b && (*head_a)->size)
	{
		end_b = *head_b;
		while (end_b->next && end_b->next != (*head_b))
			end_b = end_b->next;
		printf("end->pr->val = %d\n", end_b->prev->value);
		printf("end->val = %d\n", end_b->value);
		printf("end->n->val = %d\n", end_b->next->value);
		(*head_a)->next->size = (*head_a)->size - 1;
		(*head_a)->next->prev = end_a;
		end_a->next = (*head_a)->next;
		(*head_b)->size++;
		(*head_a) = (*head_a)->next;
		end_a->next = (*head_a);
		(*head_a)->prev = end_a;
		(*head_b)->next = (*head_b);
		(*head_b)->prev = (*head_b);
		// // work with stack a
		// end_a->next = (*head_a)->next;
		// (*head_a)->next->prev = end_a;
		// // move list from top of stack a to top of stack b
		// head_a_dup = (*head_a);
		// head_a_dup->next = (*head_b);
		// (*head_b)->prev = head_a_dup;
		// head_a_dup->prev = end_b;
		// end_b->next = head_a_dup;
		// (*head_a) = (*head_a)->next;
		// return (1);
		// printf("head_a = %d\n", (*head_a)->value);
		// tmp = (*head_a);
		// (*head_a)->next->size = (*head_a)->size - 1;
		// // (*head_b) = *head_a;
		// (*head_a)->next->prev = end_a;
		// end_a->next = (*head_a)->next;
		// (*head_a) = (*head_a)->next;
		// end_a->next = (*head_a);
		// (*head_a)->prev = end_a;

		// (*head_b)->size++;
		// (*head_b)->next = end_b;
		// (*head_b)->prev = tmp;

		// printf("head_b->pr->pr->pr->val = %d\n", (*head_b)->prev->prev->prev->value);
		// printf("head_b->prev->prev->val = %d\n", (*head_b)->prev->prev->value);
		// printf("head_b->prev->val = %d\n", (*head_b)->prev->value);
		// printf("head_b->val = %d\n", (*head_b)->value);
		// printf("head_b->next->val = %d\n", (*head_b)->next->value);
		// printf("head_b->n->nval = %d\n", (*head_b)->next->next->value);
		return (1);
	}
	return (0);
}