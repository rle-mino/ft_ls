/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:43:33 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/26 11:28:13 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*stock_file(struct dirent *file, int info)
{
	t_file	*files;

	if (!(files = ft_memalloc(sizeof(t_file))))
		return (NULL);
	if (info == O_NAME)
	{
		files->name = ft_strdup(file->d_name);
		files->next = NULL;
	}
	return (files);
}

void		ft_pushback(t_file **begin, t_file *link)
{
	link->next = *begin;
	*begin = link;
}

void		ft_push_name(t_file *begin, t_file *link, int (*cmp)())
{
	t_file	*tmp;

	tmp = begin;
	while (tmp->next)
	{
		if (tmp->next && cmp(tmp->next, link) >= 0)
		{
			link->next = tmp->next;
			tmp->next = link;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = link;
}

void		ls_display(t_file *begin, int info)
{
	if (info == O_NAME)
	{
		while (begin)
		{
			if (begin->name[0] != '.')
				fpf("%s\n", begin->name);
			begin = begin->next;
		}
	}
}
