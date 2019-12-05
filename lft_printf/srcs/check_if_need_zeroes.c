/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_need_zeroes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:29:02 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:13:40 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					check_if_need_zeroes(t_float *obj_flt, int power)
{
	int				i;

	i = SIZE - 1;
	while (obj_flt->parts.fr_buf[i] != '0' && i >= 0)
		i--;
	if (i == power)
		return (0);
	else
		return (1);
}
