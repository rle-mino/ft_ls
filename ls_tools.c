/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:43:33 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/06 16:57:01 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*stock_file(struct dirent *file, char *path)
{
	t_file	*files;
	char	*tmp;

	if (!(files = ft_memalloc(sizeof(t_file))))
		ls_error(MALL_ERR, NULL);
	files->path = ft_strjoin(path, "/");
	files->name = ft_strdup(file->d_name);
	tmp = ft_strjoin(files->path, files->name);
	files->next = NULL;
	(void)stat(tmp, &files->stat);
	free(tmp);
	return (files);
}

void			ft_pushback(t_file **begin, t_file *link)
{
	link->next = *begin;
	*begin = link;
}

void			ft_push(t_file *begin, t_file *link, int (*cmp)())
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

void			ls_display(t_file *begin, t_set set)
{
	if (set.flag & 1)
	{
		if (!set.file)
			fpf("total %d\n", set.total);
		while (begin)
		{
			if (begin->name[0] == '.' && !(set.flag & 8))
				begin = begin->next;
			else
			{
				print_file(begin, set);
				begin = begin->next;
			}
		}
	}
	else
		while (begin)
		{
			if (*begin->name == '.' && !(set.flag & 8))
				begin = begin->next;
			else if (fpf("%s\n", begin->name))
				begin = begin->next;
		}
}
