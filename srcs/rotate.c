#include "../includes/push_swap.h"

int         rotate(t_lst **head)
{
    if ((*head)->size > 1)
    {
        (*head)->next->size = (*head)->size;
        (*head) = (*head)->next;
        return (1);
    }
    return (0);
}