/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_len_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:41:57 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 16:42:49 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_len_float(t_float *obj_flt, t_print *obj)
{
	int		ret;
	int		i;

	ret = 0;
	i = SIZE;
	while (obj_flt->parts.whole[i] < 1 && i >= 0)
		--i;
	obj->flt.whole_len = i + 1;
	ret = obj->flt.whole_len + obj->fmt.prec;
	return (ret);
}
