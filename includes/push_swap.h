#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>


typedef struct		s_lst
{
	int				value;
	struct s_lst	*prev;
	struct s_lst	*next;
	size_t			size;
}					t_lst;


typedef struct		s_stack
{
	t_lst			*a;
	t_lst			*b;
}					t_stack;

int					args_to_lst(int ac, char **av, t_lst **head);
int					pb(t_lst **head_a, t_lst **head_b);
int					pa(t_lst **head_a, t_lst **head_b);
int					swap(t_lst **head);
int         		ss(t_lst **head_a, t_lst **head_b);
int					rotate(t_lst **head);
int					rr(t_lst **head_a, t_lst **head_b);
t_lst				*new_lst(int value);

#endif
