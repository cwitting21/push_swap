/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:17:49 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 06:29:47 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		clean_one_stack(t_lst *head, size_t size)
{
	if (size)
	{
		clean_one_stack(head->next, size - 1);
		if (head)
		{
			free(head);
			head = NULL;
		}
	}
}

int				ft_error_and_free(t_lst *head, t_args *args)
{
	write(1, "Error\n", 6);
	if (args)
	{
		printf("-------------------------------------------------------\n");
		// args = NULL;
		free(args->arr);
	}
	if (head)
	{
		printf("-------------------------------------------------------\n");
		clean_one_stack(head, head->size);
	}
	return (0);
}

int				ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
