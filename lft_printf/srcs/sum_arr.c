/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:28:24 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:38:13 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				sum_arr(t_float *obj_flt, int code)
{
	int				i;

	i = -1;
	if (code == 0)
	{
		while (++i < SIZE)
			obj_flt->parts.whole[i] += obj_flt->p_buf.buf[i];
		normalise_whole(obj_flt->parts.whole);
	}
	if (code == 1)
	{
		while (++i < SIZE)
			obj_flt->parts.frac[i] += obj_flt->parts.fr_buf[i];
		normalise_whole(obj_flt->parts.frac);
	}
}
