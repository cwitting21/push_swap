/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwitting <cwitting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 22:38:26 by cwitting          #+#    #+#             */
/*   Updated: 2019/12/05 22:57:45 by cwitting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	32
# define MAX_FD		10240
# define UL unsigned long int
# include "../libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif
