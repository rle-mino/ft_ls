/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:11:42 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/04 14:27:13 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		*set_cmp(t_set set)
{
	if (set.flag & 4 && set.flag & 16)
		return (void*)cmp_rev_time;
	else if (set.flag & 16)
		return (void*)cmp_time;
	else if (set.flag & 4)
		return (void*)cmp_rev_name;
	else
		return (void*)cmp_name;
}

void		ls_cmp(t_file **files, t_file *new, int (*cmp)())
{
	if (cmp(*files, new) >= 0)
		ft_pushback(files, new);
	else
		ft_push(*files, new, cmp);
}

int			ft_ls(char *dir, t_set set)
{
	DIR				*folder;
	struct dirent	*file;
	t_file			*files;
	int				(*cmp)();

	if (!(folder = opendir(dir)))
		ls_error(ERRNO, dir);
	cmp = set_cmp(set);
	if ((file = readdir(folder)))
		files = stock_file(file);
	while ((file = readdir(folder)))
		ls_cmp(&files, stock_file(file), cmp);
	ls_display(files, set);
	closedir(folder);
	return (1);
}
