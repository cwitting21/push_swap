/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 20:34:36 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 07:29:34 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	if (s)
	{
		i = 0;
		subs = ft_strnew(len);
		while (len-- != 0 && subs)
			subs[i++] = s[start++];
		return (subs);
	}
	return (NULL);
}
