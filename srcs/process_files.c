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

void	init_data(t_data *data)
{
	data->perm = NULL;
	data->owner = NULL;
	data->group = NULL;
	data->m_date = NULL;
}

void	get_data(struct stat stats, t_data *data)
{
	struct passwd	*user;
	struct group	*grp;
	char		*tmp;

	user = getpwuid(stats.st_uid);//errors?
	grp = getgrgid(stats.st_gid);//errors?
	data->perm = get_perms(stats);
	data->owner = user->pw_name;
	data->group = grp->gr_name;
	data->m_date = ft_strplit(ctime(&stats.st_mtime), ' ');//ctime errors?
	tmp = ft_strsub(data->m_date[3], 0, 5);
	free(data->m_date[3]);
	data->m_date[3] = tmp;
}

void	file_l_line(t_paths *file)
{
	struct stat	stats;
	t_data		data;
	int		i;

	i = -1;
	stat(file->path, &stats);
	init_data(&data);
	get_data(stats, &data);
	printf("-");
	ft_printf("%s ", data.perm);
	ft_printf("%3ld ", (long)stats.st_link);
	ft_printf("%16s ", data.owner);
	ft_printf("%16s ", data.group);
	ft_printf("%10s ", data.byte_c);
	ft_printf("%s", data.m_date[1]);
	ft_printf("%3s ", data.m_date[2]);
	ft_printf("%s ", data.m_date[3]);
	ft_printf("%s\n", file->path);
	while (data.m_date[++i])
		free(data.m_date[i]);
	free(data.m_date);
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
