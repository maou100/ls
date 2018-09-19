/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feedme <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:47:38 by feedme            #+#    #+#             */
/*   Updated: 2018/09/18 21:54:45 by feedme           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls"

t_paths		*ft_create_list(int count)
{
	t_paths	*head;
	t_paths	*cur;

	IF_NULL_X_MSG((head = (t_paths *)malloc(sizeof(t_paths))), -1, "Malloc error\n");
	cur = head;
	while (--count)
	{	
		IF_NULL_X_MSG((cur->next = (t_paths *)malloc(sizeof(t_paths))), -1, "Malloc error\n");
		cur = cur->next;
	}
	cur->next = NULL;
	return (head);
}
