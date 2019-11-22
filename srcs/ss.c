#include "../includes/push_swap.h"

int         ss(t_lst **head_a, t_lst **head_b)
{
    if (swap(head_a) && swap(head_b))
        return (1);
    return (0);
}