/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:36:51 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 15:36:51 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(t_print *obj)
{
	if (obj->end != obj->start)
		obj->ret += write(1, obj->start, obj->end - obj->start);
	if (*obj->end == '%')
	{
		++obj->end;
		parse(obj);
		format_output(obj);
	}
}
