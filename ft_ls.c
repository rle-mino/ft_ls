/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:11:42 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/03 13:39:13 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		set_cmp(int (*cmp)(), t_set set)
{
	if (set.flag & 4 && set.flag & 16)
		cmp = cmp_rev_time;
	else if (set.flag & 16)
		cmp = cmp_time;
	else if (set.flag & 4)
		cmp = cmp_rev_name;
	else
		cmp = cmp_name;
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
	int				cmp();

	if (!(folder = opendir(dir)))
		ls_error(ERRNO, dir);
	set_cmp(cmp, set);
	if ((file = readdir(folder)))
		files = stock_file(file, O_ALL);
	while ((file = readdir(folder)))
		ls_cmp(&files, stock_file(file, O_ALL), cmp);
	ls_display(files, set);
	closedir(folder);
	return (1);
}
