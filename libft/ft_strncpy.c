/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:16:25 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 07:30:00 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	size;

	size = ft_strlen(src);
	if (size < len)
	{
		ft_memcpy(dst, src, size);
		ft_bzero(dst + size, len - size);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
