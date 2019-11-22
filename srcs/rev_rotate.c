#include "../includes/push_swap.h"

int         rev_rotate(t_lst **head)
{
    t_lst   *end;

    end = (*head)->prev;
    if ((*head)->size > 1)
    {
        end->size = (*head)->size;
        (*head) = end;
        return (1);
    }
    return (0);
}