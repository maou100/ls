/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 10:17:11 by feedme            #+#    #+#             */
/*   Updated: 2018/09/23 11:26:25 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_data(struct stat stats, t_data *data)
{
	
}

void	file_l_line(t_paths *file)
{
	struct stat	stats;
	t_data		data;

	stat(file->path, &stats);
	get_data(stats, &data);
	write(1, "-", 1);
	ft_printf("%s  %d\t%s\t%s\t%s\t%s\t%s\n", data.perm, data.link_c, data.owner, data.group, data.byte_c, data.m_date, file->path);	
}

void	file_l_display(t_paths *files, t_flags flags)
{
	while (files)
	{
		if (files->path[0] == '.')
			if (flags.a)
				file_l_line(files);
		else
			file_l_line(files);
		files = files->next;
	}
}

void	process_files(t_paths files, t_flag flags)
{
	int	pr_tern;

	pr_tern = 1;
	if (flags.l)
	{
		file_l_display(files, flags);
		return ;
	}
	while (files)
	{
		if (files->path[0] == '.')
			flags.a ? ft_putstr(files->path) : pr_tern = 0;
		else
		{
			ft_putstr(files->path);
			pr_tern = 1;
		}
		if (files->next && pr_tern)
			write(1, " ", 1);
		files = files->next;
	}
		write(1, "\n", 1);
}
