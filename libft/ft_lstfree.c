/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksalmi <ksalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:25:03 by ksalmi            #+#    #+#             */
/*   Updated: 2019/12/13 16:58:03 by ksalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list *head)
{
	t_list *tmp;

	if (head)
	{
		while (head)
		{
			tmp = head;
			head = head->next;
			free(tmp);
		}
	}
}
