/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 22:53:31 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 15:38:38 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdlib.h"

void	parse_prec(t_print *obj)
{
	if (*obj->end == '.')
	{
		++obj->end;
		if (ft_isdigit(*obj->end))
		{
			obj->fmt.prec = ft_atoi(obj->end);
			while (ft_isdigit(*obj->end) && *obj->end)
				++obj->end;
		}
		else if (*obj->end == '*')
		{
			++obj->end;
			obj->fmt.prec = va_arg(obj->ap, int);
		}
		else
			obj->fmt.prec = 0;
	}
}
