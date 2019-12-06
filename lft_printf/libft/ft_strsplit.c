/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:34:04 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 07:29:42 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		**index;
	char	**words;

	index = ft_getindex((char *)s, c);
	if (!s || !index || !(words =
				(char **)malloc(sizeof(char *) * (index[0][0] + 1))))
		return (NULL);
	i = 1;
	while (i <= index[0][0])
	{
		if (!(words[i - 1] = ft_strsub(s, index[i][0], \
						index[i][1] - index[i][0] + 1)))
		{
			ft_cleaner((void **)words, i - 2);
			return (NULL);
		}
		i++;
	}
	words[i - 1] = NULL;
	ft_cleaner((void **)index, i);
	return (words);
}
