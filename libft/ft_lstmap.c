/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:13:26 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/06 07:31:12 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*frash;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	frash = new;
	lst = lst->next;
	while (lst)
	{
		frash->next = f(lst);
		lst = lst->next;
		frash = frash->next;
	}
	return (new);
}
