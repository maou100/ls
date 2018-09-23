/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:47:21 by feedme            #+#    #+#             */
/*   Updated: 2018/09/22 10:59:10 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	fill_flags(char c, t_flags *flags)
{
	if (c == 'R')
		flags->R = 1;
	else if (c == 'r')
		flags->r = 1;
	else if (c == 'a')
		flags->a = 1;
	else if (c == 't')
		flags->t = 1;
	else if (c == 'l')
		flags->l = 1;
	else
		IF_NULL_X_MSG(0, 1, "ls: option used illegal\nusage: ls [-Ralrt] [file/directory ...]\n");
}

int		get_flags(int argc, char **argv, t_flags *flags)
{
	int		i;
	int		j;
	int		flags_c;

	flags_c = 0;
	j = 0;
	i = 0;
	while (argv[++i])
	{
		if (argv[i][j] == '-')
		{
			if (IS_FLAG(argv[i][j + 1]))
			{
				while (argv[i][++j])
					fill_flags(argv[i][j], flags);
				flags_c++;
			}
			else
				IF_NULL_X_MSG(0, 1, "ls: option used illegal\nusage: ls [-Ralrt] [file/directory ...]\n");
		}
		else
			break ;
	}
	return (argc - (flags_c + 1));
}

t_paths	*current_dir(void)
{
	t_paths	*tmp;

	IF_NULL_X_MSG((tmp = (t_paths *)malloc(sizeof(t_paths))), 1, "Malloc error\n");
	IF_NULL_X_MSG((tmp->path = (char *)malloc(2)), 1, "Malloc error\n");
	tmp->next = NULL;
	tmp->path[0] = '.';
	tmp->path[1] = '\0';
	return (tmp);
}

t_paths	*get_args(int argc, char **argv, t_flags *flags)
{
	int		path_c;
	int		i;
	t_paths	*args;
	t_paths *head;

	i = -1;
	if (!(path_c = get_flags(argc, argv, flags)))
		return (current_dir());
	args = ft_create_list(path_c);
	head = args;
	while (args)
	{
		arg->path = argv[--argc];
		args = args->next;
	}
	return (head)
}
