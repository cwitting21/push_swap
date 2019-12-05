/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:43:31 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:43:54 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_nbr_base(t_print *obj, unsigned long long d, int base)
{
	if (d >= (unsigned long long)base)
		print_nbr_base(obj, d / base, base);
	obj->ret += write(1, &obj->start[d % base], 1);
}

void			putnbr_base(t_print *obj, unsigned long long d, int base)
{
	char		*str;

	str = NULL;
	if (obj->fmt.type == 'X')
		str = "0123456789ABCDEF";
	else
		str = "0123456789abcdef";
	obj->start = str;
	print_nbr_base(obj, d, base);
}
