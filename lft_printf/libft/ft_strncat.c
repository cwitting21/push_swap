/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 23:59:58 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 07:30:10 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	char	*x;

	x = s1;
	len = ft_strlen(s1);
	s1 += len;
	len = ft_strlen(s2);
	if (len <= n)
		n = len;
	s1[n] = '\0';
	ft_memcpy(s1, s2, n);
	return (x);
}
