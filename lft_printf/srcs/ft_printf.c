/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 23:41:46 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 16:45:54 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_print	obj;
	int		ret;

	ft_bzero(&obj, sizeof(t_print));
	va_start(obj.ap, format);
	obj.end = (char*)format;
	obj.start = (char*)format;
	obj.szof_fmt = sizeof(obj.fmt);
	obj.szof_lens = sizeof(obj.lens);
	obj.sflt = sizeof(obj.flt);
	obj.fmt.prec = -1;
	while (*obj.end)
	{
		while (*obj.end != '%' && *obj.end)
			++obj.end;
		print(&obj);
	}
	va_end(obj.ap);
	ret = obj.ret;
	return (ret);
}
