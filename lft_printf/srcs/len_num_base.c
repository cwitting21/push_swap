/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_num_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:29:50 by cwitting          #+#    #+#             */
/*   Updated: 2019/11/10 14:29:54 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				len_num_base(unsigned long long num, int base)
{
	int			count;

	count = 0;
	if (!num)
		return (1);
	while (num)
	{
		num /= base;
		++count;
	}
	return (count);
}
