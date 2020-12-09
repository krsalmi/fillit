/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:55:32 by ksalmi            #+#    #+#             */
/*   Updated: 2019/12/14 17:03:38 by laskolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char	**error_finder(int fd)
{
	int		error;
	int		i;
	t_list	*head;
	t_list	*new;
	char	*line;

	error = 0;
	i = 0;
	while ((get_next_line(fd, &line) == 1) && i < 131)
	{
		if ((error = param_check(line, i)) == 1)
			break ;
		new = ft_lstnew(line, 5);
		ft_lstadd_back(&head, new);
		if (line)
			free(line);
		i++;
	}
	if ((i + 1) % 5 != 0)
		error = 1;
	if (error == 1)
		return (NULL);
	else
		return (list_to_array(head, i));
}

static	void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int				main(int argc, char **argv)
{
	int		fd;
	char	**arr;
	int		error;

	error = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if ((arr = error_finder(fd)) == NULL)
			error = 1;
		if (error == 1)
			ft_putendl("error");
		else
		{
			solve(arr);
			free_array(arr);
		}
	}
	else
		ft_putendl("usage: ./fillit [target_file]");
	return (0);
}
