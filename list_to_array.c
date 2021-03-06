/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:12:12 by ksalmi            #+#    #+#             */
/*   Updated: 2019/12/13 16:59:31 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

char	**list_to_array(t_list *list, int i)
{
	t_list	*current;
	char	**arr;
	int		j;

	if (!(arr = (char **)malloc(sizeof(char*) * (i + 1))) || !list)
		exit(0);
	current = list;
	j = 0;
	while (current)
	{
		arr[j] = current->content;
		j++;
		current = current->next;
	}
	arr[j] = NULL;
	ft_lstfree(list);
	return (arr);
}
