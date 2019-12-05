/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:39:00 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 15:39:23 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(t_print *obj)
{
	while (*obj->end == '-' || *obj->end == '+' || *obj->end == ' '
			|| *obj->end == '#' || *obj->end == '0')
	{
		if (*obj->end == '-')
			obj->fmt.flags[0] = '-';
		else if (*obj->end == '+')
			obj->fmt.flags[1] = *obj->end;
		else if (*obj->end == ' ')
			obj->fmt.flags[2] = *obj->end;
		else if (*obj->end == '#')
			obj->fmt.flags[3] = *obj->end;
		else if (*obj->end == '0')
			obj->fmt.flags[4] = 1;
		++obj->end;
	}
}
