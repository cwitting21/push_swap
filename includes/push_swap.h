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
int					stack_is_sorted(t_lst **head_a, t_lst **head_b);
int					get_next_line(const int fd, char **line);
int					init_args(t_args *args, size_t size);
int					read_commands(t_lst **head_a, t_lst **head_b);
int					args_to_array(t_lst **head, t_args *args);
int					list_is_sorted(t_lst *head);
int					get_insert_index(t_lst **head_a, int num);
int					ft_error(void);
int					num_is_valid(char *ptr);


void				sort_3_numbers(t_lst **h);
void				destroy_stacks(t_stack *stacks);
void				sort_5_numbers(t_lst **head_a, t_lst **head_b, t_args *args);
void				final_sort(t_lst **head, t_args *args);
void				sort_lists_hard(t_lst **head_a, t_lst **head_b, t_args *args);
void				leave_3_nbrs_in_a(t_lst **head_a, t_lst **head_b, t_args *args);
void				from_a_to_b(t_args *args, t_lst **head_a, t_lst **head_b);
void				spin_stack(t_stack *stacks, t_solution sol);
void				case_1_simpsort(t_lst **head_a, t_lst **head_b, t_args *args);
void				case_2_simpsort(t_lst **head_a, t_lst **head_b);
void				case_3_simpsort(t_lst **head_a, t_lst **head_b, t_args *args);
void				case_4_simpsort(t_lst **head_a, t_lst **head_b, t_lst *end_a);

void				print_stacks(t_lst **head_a, t_lst **head_b);

t_lst				*new_lst(int value);
t_lst				*push_lst_to_end(t_lst *head, t_lst *new);
t_bool				array_is_sorted(int *arr);

size_t				get_insert_index_simple_max(t_lst **h, t_args *args);
size_t				get_index_simple_sort(t_lst **head, t_args *args);


#endif
