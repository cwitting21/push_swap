/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 11:36:23 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 07:29:30 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	size_t	end;
	size_t	front;

	if (s)
	{
		front = 0;
		while (ft_isblank(s[front]))
			front++;
		if (s[front] == '\0')
			return (ft_strnew(0));
		end = ft_strlen(s);
		while (ft_isblank(s[end - 1]))
			end--;
		res = ft_strsub(s, front, end - front);
		return (res);
	}
	return (NULL);
}
