#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

int		tetrimino_check(char **tetri);
int		param_check(char *line, int i);
char	**list_to_array(t_list *list, int i);

#endif
