/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 22:04:54 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:14:56 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double			extract_float(t_print *obj)
{
	if (!obj->fmt.size)
		return ((long double)(va_arg(obj->ap, double)));
	if (obj->fmt.size == 108)
		return ((long double)(va_arg(obj->ap, double)));
	else if (obj->fmt.size == 76)
		return ((long double)va_arg(obj->ap, long double));
	return (0);
}
