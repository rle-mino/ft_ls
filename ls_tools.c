/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:43:33 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/03 20:40:30 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*stock_file(struct dirent *file, int info)
{
	t_file	*files;

	if (!(files = ft_memalloc(sizeof(t_file))))
		ls_error(MALL_ERR, NULL);
	files->name = ft_strdup(file->d_name);
	files->next = NULL;
	files->stat = get_stat(files->name);
	return (files);
}

void		ft_pushback(t_file **begin, t_file *link)
{
	link->next = *begin;
	*begin = link;
}

void		ft_push(t_file *begin, t_file *link, int (*cmp)())
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

void		ls_display(t_file *begin, t_set set)
{
	while (begin)
	{
		fpf("%s", get_right(begin));
		begin = begin->next;
	}
}
