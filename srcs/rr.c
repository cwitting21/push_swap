#include "../includes/push_swap.h"

int         rr(t_lst **head_a, t_lst **head_b)
{
    if (rotate(head_a) && rotate(head_b))
        return (1);
    return (0);
}