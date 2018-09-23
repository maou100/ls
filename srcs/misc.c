/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 16:01:09 by feedme            #+#    #+#             */
/*   Updated: 2018/09/22 16:15:33 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_paths		*errors_ascii_sorting(t_paths *errors)
{
	t_paths	*tmp;
	t_paths	*head;

	head = paths;
	while (paths)
	{
		tmp = paths;
		while (tmp-next)
		{
			if (!(ascii_cmp(paths->path[0], (tmp->next)->path[0])))
				strswap(paths, tmp->next);
			tmp = tmp->next;
		}
		paths = paths->next;
	}
	return (head);	
}
