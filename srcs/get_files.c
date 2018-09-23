/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 12:57:08 by feedme            #+#    #+#             */
/*   Updated: 2018/09/22 15:44:05 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	is_file(const char *path)
{
	struct stat	stats;

	if (stat(path, &stats) == -1)
		return (0);
	if (!(S_ISDIR(stats.st_mode)))
		return (1);
	return (0);
}

t_paths	*get_files(t_paths *args, t_flags flags)
{
	t_paths		*files;
	t_paths		*prev;
	t_paths		*tmp;

	files = NULL;
	prev = NULL;
	while (args)
	{
		if (is_file(args->path))
		{
			if (prev)
				prev->next = args->next;
			tmp = args->next;
			args->next = files;
			files = args;
			args = tmp;
			
		}
		else
		{
			prev = args;
			args = args->next;
		}
	}
	if (files && files->next)
	{
		files = paths_sorting(files, flags);
		if (flags.r)
			files = paths_reverse(files);
	}
	return (files);
}
