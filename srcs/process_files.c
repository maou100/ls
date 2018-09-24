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
	data->link_c = -1;
	data->owner = NULL;
	data->group = NULL;
	data->byte_c = NULL;
	data->m_data = NULL;
}

char	*get_byte_c(long long size)
{
	char	*bytes;

	if (size < 1000)
		return (ft_itoa((int)size));
	else if (size < 1000000)
		return (kilo_bytes((int)size));
	else if (size < 1000000000)
		return (mega_bytes((int)size));
	else if (size < 1000000000000)
		return (giga_bytes((long long)size));
	else if (size < 1000000000000000)
		return (tera_bytes((long long)size));
	else
		
}

void	get_data(struct stat stats, t_data *data)
{
	data->perm = get_perms(stats);
	data->owner = 
	data->group =
	data->byte_c = get_byte_c((long long)stats.st_size); 
	data->m_data =
}

void	file_l_line(t_paths *file)
{
	struct stat	stats;
	t_data		data;

	stat(file->path, &stats);
	init_data(&data);
	get_data(stats, &data);
	write(1, "-", 1);
	ft_printf("%s  %ld\t%s\t%s\t%s\t%s\t%s\n", data.perm, (long)stats.st_nlink, data.owner, data.group, data.byte_c, data.m_date, file->path);	
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
