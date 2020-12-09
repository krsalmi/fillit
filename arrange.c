/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_to_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:12:37 by laskolin          #+#    #+#             */
/*   Updated: 2019/12/14 16:12:27 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		fit(char **map, char list[][5][5], int tetr, t_dim dim)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	j = 0;
	while (list[tetr][j][0] != '\0')
	{
		i = 0;
		while (list[tetr][j][i])
		{
			if ((map[0][dim.x + i] == '\0') || (map[dim.y + j] == NULL))
				return (0);
			if (map[dim.y + j][dim.x + i] == '.' && list[tetr][j][i] != '.')
				count++;
			if (count == 4)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

static void		put_to_map(char **map, int tetr, char list[][5][5], t_dim dim)
{
	int		i;
	int		j;

	j = 0;
	while (list[tetr][j][0] != '\0')
	{
		i = 0;
		while (list[tetr][j][i])
		{
			if (list[tetr][j][i] != '.')
				map[dim.y + j][dim.x + i] = list[tetr][j][i];
			i++;
		}
		j++;
	}
}

static void		erase(char **map, int tetr, char list[][5][5], t_dim dim)
{
	int		i;
	int		j;

	j = 0;
	while (list[tetr][j][0] != '\0')
	{
		i = 0;
		while (list[tetr][j][i])
		{
			if (list[tetr][j][i] != '.')
				map[dim.y + j][dim.x + i] = '.';
			i++;
		}
		j++;
	}
}

static int		try(char list[][5][5], int tetr, char **map, int num)
{
	t_dim	dim;

	dim.y = 0;
	while (map[dim.y] != NULL)
	{
		dim.x = 0;
		while (map[dim.y][dim.x] != '\0')
		{
			if (map[dim.y][dim.x] == '.' || map[dim.y][dim.x + 1] == '.' ||
				map[dim.y][dim.x + 2] == '.')
			{
				if (fit(map, list, tetr, dim))
				{
					put_to_map(map, tetr, list, dim);
					if ((tetr == num) || (try(list, tetr + 1, map, num) == 1))
						return (1);
					erase(map, tetr, list, dim);
				}
			}
			dim.x++;
		}
		dim.y++;
	}
	return (0);
}

char			**arrange(char **map, char list[][5][5], int num, int side)
{
	int		tetr;
	int		i;

	tetr = 0;
	while (try(list, tetr, map, num) == 0)
	{
		i = 0;
		while (i < side)
		{
			free(map[i]);
			i++;
		}
		free(map);
		map = NULL;
		side++;
		map = newmap(side);
	}
	return (map);
}
