/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laskolin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:00:08 by laskolin          #+#    #+#             */
/*   Updated: 2019/12/13 15:36:06 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			*ft_strdot(int side)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(*new) * side + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < side)
	{
		new[i] = '.';
		i++;
	}
	new[i] = '\0';
	return (new);
}

char			**newmap(int side)
{
	char	**map;
	int		j;

	if (!(map = (char **)malloc(sizeof(char*) * (side + 1))))
		exit(0);
	j = 0;
	while (j < side)
	{
		map[j] = ft_strdot(side);
		j++;
	}
	map[j] = NULL;
	return (map);
}

static int		count_side(int num)
{
	int		a;
	int		i;

	i = 2;
	a = (num + 1) * 4;
	while (i * i < a)
		i++;
	return (i);
}

static void		print_map2(char **map)
{
	int		i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_putendl(map[i]);
		i++;
	}
}

void			solve(char **tetris)
{
	char	list[26][5][5];
	int		num;
	int		side;
	char	**map;
	int		i;

	num = 0;
	num = makelist(tetris, list, num);
	side = count_side(num);
	map = newmap(side);
	map = arrange(map, list, num, side);
	print_map2(map);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
