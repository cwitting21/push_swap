/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_has_frac_part.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:49:57 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:30:52 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					nbr_has_frac_part(t_float *obj_flt)
{
	int				i;

	i = -1;
	while (++i <= obj_flt->parts.i_frac_e)
	{
		if (obj_flt->p_arr[i] < 0)
			return (1);
	}
	return (0);
}
