/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 23:42:04 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 15:39:42 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			parse(t_print *obj)
{
	parse_flags(obj);
	parse_width(obj);
	parse_prec(obj);
	parse_size(obj);
	parse_type(obj);
	obj->start = obj->end;
}
