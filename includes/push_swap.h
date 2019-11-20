#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>


typedef struct		s_lst
{
	int				value;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;


// typedef struct		s_stack
// {
// 	t_lst			*a;
// 	t_lst			*b;
// }					t_stack;

int					args_to_lst(int ac, char **av/*, t_stack *stack*/);
t_lst				*new_lst(int value);
t_lst				*put_lst_to_end(t_lst *start, t_lst *new);


#endif
