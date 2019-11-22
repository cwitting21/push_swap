#include "../includes/push_swap.h"

int         rrr(t_lst **head_a, t_lst **head_b)
{
    if (rev_rotate(head_a) && rev_rotate(head_b))
        return (1);
    return (0);
}