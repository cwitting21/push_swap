/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_is_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:23:42 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 05:35:39 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool				array_is_sorted(int *arr)
{
	int				i;

	i = 1;
	while (arr[i])
	{
		if (arr[i] < arr[i - 1])
			return (false);
		++i;
	}
	return (true);
}
