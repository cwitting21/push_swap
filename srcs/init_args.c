/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 04:43:15 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/04 05:45:07 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		init_args(t_args *args, size_t size)
{
	if (!(args->arr = malloc(sizeof(int) * size)))
		return (0);
	ft_bzero(args->arr, sizeof(args->arr));
	args->max_i = 0;
	args->mid_s = 0;
	args->mid_e = 0;
	args->min_i = 0;
	return (1);
}
