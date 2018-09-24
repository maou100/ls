/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:29:20 by feedme            #+#    #+#             */
/*   Updated: 2018/09/23 11:20:07 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
#include <pwd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <time.h>


# define IS_FLAG(x) (x == 'R' || x == 'r' || x == 'a' || x == 't' || x == 'l')

typedef struct	s_flags
{
	char		R;
	char		r;
	char		a;
	char		t;
	char		l;
}				t_flags;

typedef	struct	s_paths
{
	char		*path;
	t_paths		*next;
}				t_paths;

typedef struct	s_data
{
	char		*perm;
	char		*owner;
	char		*group;
	char		*byte_c;
	char		*m_date;
}				t_data;

void	str_swap(t_paths *paths, t_paths *next);
int		ascii_cmp(char paths, char next);
int		time_cmp(char *paths, char *next);
t_paths *paths_sorting(t_paths *paths, t_flags flags);
t_paths	*paths_reverse(t_paths *paths);
t_paths		*errors_ascii_sorting(t_paths *errors);

#endif
