/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:58:26 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 07:30:18 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	size_t	i;
	char	*res;

	if (s && f)
	{
		len = ft_strlen(s);
		i = 0;
		res = ft_strnew(len);
		if (res)
		{
			while (len-- != 0)
				res[i++] = f(*s++);
			return (res);
		}
	}
	return (NULL);
}
