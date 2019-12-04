/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:44:20 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 05:58:25 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		rrr(t_lst **head_a, t_lst **head_b)
{
	if (rev_rotate(head_a) && rev_rotate(head_b))
		return (1);
	return (0);
}
