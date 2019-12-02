#include "../includes/push_swap.h"

static int		num_is_valid(char *ptr)
{
	char		*tmp;

	tmp = ptr;
	while (*tmp && !ft_isblank(*tmp))
	{
		if (!(*tmp >= 0 + '0' && *tmp <= 9 + '0'))
			return (0);
		++tmp;
	}
	return (1);
}

static t_lst	*push_lst_to_end(t_lst *head, t_lst *new)
{
	t_lst		*end;

	if (!head)
	{
		new->next = new;
		new->prev = new;
		new->size++;
		return (new);
	}
	end = head;
	end->size++;
	while (end->next && end->next != head)
		end = end->next;
	end->next = new;
	new->prev = end;
	new->next = head;
	head->prev = new;
	return (head);
}

// static int			check_if_neg_is_valid(char *ptr)
// {

// }

static int			valid_args(char *ptr, int ac, char  **av)
{
	int				i;
	char			*tmp;

	i = 0;
	tmp = ptr;
	while (++i < ac)
	{
		ptr = av[i];
		while (*ptr)
		{
			// if (*ptr == '-')
			// 	check_if_neg_is_valid(ptr);
			if (!((*ptr >= 0 + '0' && *ptr <= 9 + '0') || *ptr == ' ' || *ptr == '"'))
				return (0);
			++ptr;
		}
	}
	return (1);
}

int			args_to_lst(int ac, char **av, t_lst **head)
{
	int		i;
	char	*ptr;

	i = 0;
	if (valid_args(ptr, ac, av))
	{
		while (++i < ac)
		{
			ptr = av[i];
			while (*ptr)
			{
				while (ft_isblank(*ptr))
					++ptr;
				if ((*ptr >= (0 + '0')) && (*ptr <= (9 + '0')))
					(*head = push_lst_to_end(*head, new_lst(ft_atoi(ptr))));
				while (!ft_isblank(*ptr) && *ptr)
					++ptr;
			}
		}
		return (1);
	}
	return (0);
}
