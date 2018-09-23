/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 15:22:46 by feedme            #+#    #+#             */
/*   Updated: 2018/09/22 16:20:07 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	str_swap(t_paths *paths, t_paths *next)
{
	char	*tmp;

	tmp = paths->path;
	paths->path = next->path;
	next->path = tmp;
}

int		ascii_cmp(char paths, char next)
{
	if (paths > next)
		return (0);
	else
		return (1);
}

int		time_cmp(char *paths, char *next)
{
	struct stat	stat1;
	struct stat	stat2;

	stat(paths, &stat1);
	stat(next, &stat2);
	if (stat1->st_mtime > stat2->st_mtime)
		return (1);
	else
		return (0);
}

t_paths *paths_sorting(t_paths *paths, t_flags flags)
{
	t_paths	*tmp;
	t_paths	*head;

	head = paths;
	while (paths)
	{
		tmp = paths;
		while (tmp-next)
		{
			if (!(flags.t ? time_cmp(paths->path, (tmp->next)->path) : ascii_cmp(paths->path[0], (tmp->next)->path[0])))
				strswap(paths, tmp->next);
			tmp = tmp->next;
		}
		paths = paths->next;
	}
	return (head);
}

t_paths	*paths_reverse(t_paths *paths)
{
	t_paths	*new;
	t_paths	*tmp;

	new = NULL;
	while (paths)
	{
		tmp = paths->next;
		paths->next = new;
		new = paths;
		paths = tmp;
	}
	return (new);
}
