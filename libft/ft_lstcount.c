/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:32:29 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 07:29:08 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcount(t_list *lst)
{
	long int count;

	if (lst)
	{
		count = 0;
		while (lst)
		{
			count++;
			lst = lst->next;
		}
		return (count);
	}
	return (0);
}
