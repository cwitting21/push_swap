#include "../includes/push_swap.h"

static int			num_is_valid(char *ptr)
{
	char	*tmp;

	tmp = ptr;
	while (!ft_isblank(*tmp))
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
		return (new);
	}
	end = head;
	while (end->next && end->next != head)
		end = end->next;
	end->next = new;
	new->prev = end;
	new->next = head;
	head->prev = new;
	return (head);
}

static void		test_print(t_lst *head)
{
	t_lst		*end;

	end = head;
	while (end->next && end->next != head)
	{
		printf("%d\n", end->value);
		end = end->next;
	}
	printf("%d\n", end->value);
}

int			args_to_lst(int ac, char **av/*, t_stack *stack*/)
{
	int		i;
	char	*ptr;
	t_lst	*new = NULL;
	t_lst	*head = NULL;

	i = 0;
	while (++i < ac)
	{
		ptr = av[i];
		while (*ptr)
		{
			while (ft_isblank(*ptr))
				++ptr;
			// if (!(num_is_valid(ptr)))
			// 	return (0);
			// new = NULL;
			if (!(new = new_lst(ft_atoi(ptr))))
				return (0);
			if (!(head = push_lst_to_end(head, new)))
				return (0);
			while (!ft_isblank(*ptr) && *ptr)
				++ptr;
		}
	}
	test_print(head);
	return (1);
}
