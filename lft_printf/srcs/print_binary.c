/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:57:52 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 15:36:29 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_binary(t_print *obj)
{
	int		bin;
	char	res[32];
	int		i;

	i = 31;
	bin = (int)va_arg(obj->ap, int);
	ft_bzero(&res, 32);
	while (bin > 0)
	{
		res[i--] = bin % 2 + '0';
		bin /= 2;
	}
	obj->ret += 0;
	write(1, &res, 32);
	write(1, "\n", 1);
	return (0);
}
