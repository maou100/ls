/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 15:44:40 by feedme            #+#    #+#             */
/*   Updated: 2018/09/22 16:29:48 by feedme           ###   ########.fr       */
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

void	ft_ls(t_paths *args, t_flags flags)
{
	t_paths	*files;
	t_paths	*dirs;
	t_paths *errors;

	files = get_files(args, flags);
	dirs = get_dirs(args, flags);
	errors = args;
	if (errors)
	{
		if (errors->next)
		{
			errors = errors_ascii_sorting(errors);
//			if (flags.r)
//				errors = paths_reverse(errors);  pas de reverse sur errors, et apparement pas de reverse sur files non plus (ni time), cheulou
		}
		process_errors(errors);
	}
	while (files)
	{
		process_files(files, flags);
		files = files->next;
	}
	while (dirs)
	{
		process_dirs(dirs, flags);
		dirs = dirs->next;
	}
	ft_free_all(files, dirs, errors);
}

int		main(int argc, char **argv)

	int		i;
	t_paths	*args;
	t_flags	flags;

	if (argc < 1)
		ft_exit_msg(1, "how did that even happen\n");
	i = -1;
	ft_init_flags(&flags);
	args = get_args(argc, argv, &flags);
	
	ft_ls(args, flags);
	return (0);
}
