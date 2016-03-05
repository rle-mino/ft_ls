/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:11:42 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/05 12:02:36 by rle-mino         ###   ########.fr       */
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

t_set		init_set_max(t_set set, t_file *begin)
{
	int		lid;
	int		lg;
	int		lsi;
	int		lda;

	set.lid = 0;
	set.lg = 0;
	set.lsi = 0;
	set.lda = 0;
	while (begin)
	{
		lid = ft_strlen(getpwuid(begin->stat.st_uid)->pw_name);
		lg = ft_strlen(getgrgid(begin->stat.st_gid)->gr_name);
		lda = ft_strlen(ctime(&begin->stat.st_mtime));
		lsi = ft_nbrlen(begin->stat.st_size);
		set.lid = lid > set.lid ? lid : set.lid;
		set.lg = lg > set.lg ? lg : set.lg;
		set.lsi = lsi > set.lsi ? lsi : set.lsi;
		set.lda = lda > set.lda ? lda : set.lda;
		begin = begin->next;
	}
	return (set);
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
		return (ls_error(ERRNO, dir));
	cmp = set_cmp(set);
	if ((file = readdir(folder)))
		files = stock_file(file, dir);
	while ((file = readdir(folder)))
		ls_cmp(&files, stock_file(file, dir), cmp);
	set = init_set_max(set, files);
	ls_display(files, set);
	closedir(folder);
	return (1);
}
