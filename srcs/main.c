/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:44:40 by feedme            #+#    #+#             */
/*   Updated: 2018/09/18 21:54:44 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_init_flags(t_flags *flags)
{
	flags->R = 0;
	flags->r = 0;
	flags->a = 0;
	flags->t = 0;
	flags->l = 0;
}

void	ft_ls(t_paths *paths, t_flags flags)
{
	apply_sort(paths, flags);
	while (paths)
	{
		if (ft_file_type(paths->path) = 'd'(dir))
			ft_ls(paths-path(erh...), flags);
		else
			ft_print_file(paths->path, flags);
		paths = paths->next;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	t_paths	*paths;
	t_flags	flags;

	if (argc < 1)
		ft_exit_msg(-1, "how did that even happen\n");
	i = -1;
	ft_init_flags(&flags);
	paths = get_paths(argc, argv, &flags);
	ft_ls(paths, flags);
	ft_free_list(paths);
	return (0);
}
