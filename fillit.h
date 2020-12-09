/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:30:25 by ksalmi            #+#    #+#             */
/*   Updated: 2019/12/14 17:32:32 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef	struct	s_dim
{
	int	x;
	int	y;
}				t_dim;

int				tetrimino_check(char **tetri);
int				param_check(char *line, int i);
char			**list_to_array(t_list *list, int i);
void			solve(char **tetris);
int				makelist(char **tetris, char list[][5][5], int num);
char			**arrange(char **map, char list[][5][5], int num, int side);
char			*ft_strdot(int side);
char			**newmap(int side);

#endif
