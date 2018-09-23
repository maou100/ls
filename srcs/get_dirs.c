/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dirs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:55:51 by feedme            #+#    #+#             */
/*   Updated: 2018/09/22 15:49:14 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls"

int	is_dirs(char *path)
{
	struct stat	stats;

	if (stat(path, &stats) == -1)
		return (0);
	if (S_ISDIR(stats.st_mode))
		return (1);
	return (0);
}

t_paths	*get_dirs(t_paths *args, t_flags flags)
{
	t_paths		*dirs;
	t_paths		*prev;
	t_paths		*tmp;

	dirs = NULL;
	prev = NULL;
	while (args)
	{
		if (is_dirs(args->path))
		{
			if (prev)
				prev->next = args->next;
			tmp = args->next;
			args->next = dirs;
			dirs = args;
			args = tmp;
		}
		else
		{
			prev = args;
			args = args->next;
		}
	}
	if (dirs && dirs->next)
	{
		dirs = paths_sorting(dirs, flags);
		if (flags.r)
			dirs = paths_reverse(dirs);
	}
	return (dirs);
}
