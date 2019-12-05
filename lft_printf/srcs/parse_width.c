/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:37:10 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 15:37:11 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(t_print *obj)
{
	if (ft_isdigit(*obj->end))
	{
		obj->fmt.width = ft_atoi(obj->end);
		obj->end += len_num_base(obj->fmt.width, 10);
	}
	else if (*obj->end == '*')
	{
		obj->fmt.width = va_arg(obj->ap, int);
		++obj->end;
	}
}
