/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:46:04 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 07:28:26 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_cleaner(void **trash, int index)
{
	if (trash)
	{
		while (index-- != 0)
			ft_memdel(trash + index);
		ft_memdel(trash);
	}
}
