/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percentage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:50:33 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:50:34 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_percentage(t_print *obj)
{
	if (!obj->fmt.flags[4])
	{
		if (obj->fmt.flags[0] != '-' && obj->fmt.width > 1)
			obj->ret += print_space(obj->fmt.width - 1);
	}
	else if (obj->fmt.flags[0] != '-' && obj->fmt.width > 1)
		obj->ret += print_zero(obj->fmt.width - 1);
	obj->ret += write(1, "%", 1);
	if (obj->fmt.flags[0] && obj->fmt.width > 1)
		obj->ret += print_space(obj->fmt.width - 1);
	obj->start = obj->end;
	ft_memset(&obj->fmt, 0, obj->szof_fmt);
	obj->fmt.prec = -1;
	return (0);
}
