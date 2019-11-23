#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE	32
# define MAX_FD		10240
# define UL unsigned long int
# include "../libft/libft.h"

int		get_next_line(const int fd, char **line);

#endif