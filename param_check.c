/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:37:06 by ksalmi            #+#    #+#             */
/*   Updated: 2019/12/10 13:10:02 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		basic_error_check(char *line, int i)
{
	int	error;
	int j;

	error = 0;
	if ((i + 1) % 5 != 0 && ft_strlen(line) != 4)
		error = 1;
	if (i != 0 && (i + 1) % 5 == 0 && line[0] != '\0')
		error = 1;
	j = 0;
	while (error == 0 && line[j])
	{
		if (line[j] != '.' && line[j] != '#')
			error = 1;
		j++;
	}
	return (error);
}

static	char	**create_tetri(char **tetri)
{
	int i;

	i = 0;
	if (!tetri)
	{
		if (!(tetri = (char **)malloc(sizeof(char*) * 4)))
			exit(0);
		while (i < 4)
		{
			tetri[i] = ft_strnew(4);
			i++;
		}
	}
	return (tetri);
}

int				param_check(char *line, int i)
{
	static int	k;
	static char	**tetri;
	int			error;
	int			h;

	tetri = create_tetri(tetri);
	if ((error = basic_error_check(line, i)) == 0 \
			&& k < 5 && ((i + 1) % 5 != 0 || i == 0))
		ft_strcpy(tetri[k], line);
	k++;
	if (error == 0 && k == 4)
	{
		if (tetrimino_check(tetri))
			error = 1;
		h = -1;
		while (++h < 4)
			free(tetri[h]);
		free(tetri);
		tetri = NULL;
	}
	if (k == 5)
		k = 0;
	return (error);
}
