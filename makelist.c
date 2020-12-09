/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makelist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:27:27 by laskolin          #+#    #+#             */
/*   Updated: 2019/12/13 13:31:38 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		cut_to_square(char **tetris, char raw[5][5], int tetri, int num)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetris[tetri + y][x] == '#')
				raw[y][x] = num + 65;
			else
				raw[y][x] = '.';
			x++;
		}
		raw[y][x] = '\0';
		y++;
	}
	raw[y][0] = '\0';
}

static int		width(char raw[5][5])
{
	int		width;
	int		x;

	width = 4;
	x = 0;
	while (x < 4)
	{
		if (raw[0][x] == '.' && raw[1][x] == '.' &&
				raw[2][x] == '.' && raw[3][x] == '.')
			width--;
		x++;
	}
	return (width);
}

static int		height(char raw[5][5])
{
	int		y;
	int		height;

	height = 4;
	y = 0;
	while (y < 4)
	{
		if (raw[y][0] == '.' && raw[y][1] == '.' &&
				raw[y][2] == '.' && raw[y][3] == '.')
			height--;
		y++;
	}
	return (height);
}

static void		cut(char list[][5][5], char raw[5][5], int num, t_dim size)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = 0;
	while (raw[0][x] == '.' && raw[1][x] == '.' &&
			raw[2][x] == '.' && raw[3][x] == '.')
		x++;
	y = 0;
	while (ft_strcmp(raw[y], "....") == 0)
		y++;
	j = 0;
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			list[num][j][i] = raw[j + y][i + x];
			i++;
		}
		list[num][j][i] = '\0';
		j++;
	}
	list[num][j][0] = '\0';
}

int				makelist(char **tetris, char list[][5][5], int num)
{
	t_dim	size;
	int		tetri;
	char	raw[5][5];

	tetri = 0;
	while (tetris[tetri])
	{
		cut_to_square(tetris, raw, tetri, num);
		size.x = width(raw);
		size.y = height(raw);
		cut(list, raw, num, size);
		if (tetris[tetri + 4] == NULL)
			break ;
		tetri += 5;
		num++;
	}
	return (num);
}
