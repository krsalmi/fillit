/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:55:07 by ksalmi            #+#    #+#             */
/*   Updated: 2019/12/09 13:55:20 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int	neighbor_check(char **tetri, int x, int y)
{
	int neighbor;

	neighbor = 0;
	if (x != 3)
	{
		if (tetri[y][x + 1] == '#')
			neighbor++;
	}
	if (y != 3)
	{
		if (tetri[y + 1][x] == '#')
			neighbor++;
	}
	return (neighbor);
}

int			tetrimino_check(char **tetri)
{
	int x;
	int y;
	int count;
	int neighbor;

	y = -1;
	count = 0;
	neighbor = 0;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (tetri[y][x] == '#')
			{
				count++;
				if (count > 4)
					return (1);
				neighbor = neighbor + neighbor_check(tetri, x, y);
			}
		}
	}
	if (neighbor < 3)
		return (1);
	return (0);
}
