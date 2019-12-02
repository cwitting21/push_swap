#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>

static int			gl = 0;
static int			gl1 = 0;

typedef struct		s_lst
{
	int				value;
	struct s_lst	*prev;
	struct s_lst	*next;
	size_t			size;
	int				oper;
}					t_lst;

typedef struct		s_args
{
	int				*arr;
	size_t			max_i;
	size_t			mid_s;
	size_t			mid_e;
	size_t			mid_i;
	size_t			min_i;
}					t_args;

typedef struct		s_stack
{
	t_lst			*a;
	t_lst			*b;
	size_t			size_a;
	size_t			size_b;
}					t_stack;

typedef struct		s_solution
{
	int				num_ra;
	int				num_rb;
	int				num_rra;
	int				num_rrb;
	int				num_rr;
	int				num_rrr;
	int				num_all;
}					t_solution;

typedef enum		e_bool
{
					true = 1,
					false = !true
}					t_bool;

typedef enum		e_direction
{
					UP = 0,
					DOWN = 1,
					UP_DOWN = 2,
					DOWN_UP = 3,
					FIRST = UP,
					LAST = DOWN_UP
}					t_direction;

int					args_to_lst(int ac, char **av, t_lst **head);
int					pb(t_lst **head_a, t_lst **head_b);
int					pa(t_lst **head_a, t_lst **head_b);
int					swap(t_lst **head);
int         		ss(t_lst **head_a, t_lst **head_b);
int					rotate(t_lst **head);
int					rr(t_lst **head_a, t_lst **head_b);
int					rev_rotate(t_lst **head);
int					rrr(t_lst **head_a, t_lst **head_b);
int					stack_is_sorted(t_lst **head);
int					get_next_line(const int fd, char **line);
t_lst				*new_lst(int value);

#endif
