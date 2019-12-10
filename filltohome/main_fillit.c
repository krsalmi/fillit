/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fillit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:55:32 by ksalmi            #+#    #+#             */
/*   Updated: 2019/12/10 14:02:56 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int i;
	int fd;
	char *line;
	t_list *head;
	t_list *new;
	int	error;
	char **arr;

	error = 0;
	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		while(get_next_line(fd, &line) && i < 131)
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
		{
 			ft_putendl_fd("error", 2);
			exit(0);
		}
		else
		{
	//		ft_putendl("<SUCCESS> >>send to tetrissolver");
			arr = list_to_array(head, i); /* send this arr to solver! */
		}
	}
	else
		ft_putendl("usage: fillit [target_file]");
	return (0);
}
