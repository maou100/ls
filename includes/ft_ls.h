/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:29:20 by feedme            #+#    #+#             */
/*   Updated: 2018/09/18 12:31:46 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"

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

#endif
