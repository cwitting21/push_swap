/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 15:37:27 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 15:37:28 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_type(t_print *obj)
{
	char	*types;

	types = TYPES;
	while (*types)
	{
		if (*types == *obj->end)
		{
			obj->fmt.type = *obj->end;
			++obj->end;
			return ;
		}
		++types;
	}
}
