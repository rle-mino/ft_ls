/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:11:42 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/08 17:13:53 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
		return (ls_error(ERRNO, dir));
	cmp = set_cmp(set);
	if ((file = readdir(folder)))
		files = stock_file(file, dir);
	while ((file = readdir(folder)))
		ls_cmp(&files, stock_file(file, dir), cmp);
	set = init_set_max(set, files, 0, 0);
	ls_display(files, set);
	free_files(files);
	closedir(folder);
	return (1);
}
