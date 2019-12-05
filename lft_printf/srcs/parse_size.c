/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:37:42 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 15:38:09 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		size_cap_l(t_print *obj)
{
	obj->fmt.size = *((char *)obj->end);
	++obj->end;
	return (0);
}

static int		size_two(t_print *obj)
{
	obj->fmt.size = *((short *)obj->end);
	obj->end += 2;
	return (0);
}

static int		size_one(t_print *obj)
{
	obj->fmt.size = *((char *)obj->end);
	++obj->end;
	return (0);
}

int				parse_size(t_print *obj)
{
	if ((*obj->end == 'l' && *(obj->end + 1) == 'l')
			|| (*obj->end == 'h' && *(obj->end + 1) == 'h'))
		return (size_two(obj));
	else if (*obj->end == 'l' || *obj->end == 'h')
		return (size_one(obj));
	else if (*obj->end == 'L')
		return (size_cap_l(obj));
	return (0);
}
