#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>


typedef struct	s_lst
{
	t_stack		*head;
	t_stack		*prev;
	t_stack		*next;
	size_t		size;
	int			value;
}				t_lst;


typedef struct	s_stack
{
	t_par		*a;
	t_par		*b;
}				t_stack;

#endif
