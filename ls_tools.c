/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:43:33 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/08 15:15:53 by rle-mino         ###   ########.fr       */
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
	(void)lstat(tmp, &files->stat);
	if (S_ISLNK(files->stat.st_mode))
	{
		files->symb = ft_memalloc(files->stat.st_size + 1);
		readlink(tmp, files->symb, files->stat.st_size);
	}
	else
		files->symb = NULL;
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
