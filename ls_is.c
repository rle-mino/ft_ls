/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 11:05:42 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/09 18:58:50 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			is_directory(struct dirent *file, t_file *fold, t_set set)
{
	struct stat	statbuff;
	char		*tmp;

	tmp = ft_strjoin(fold->name, file->d_name);
	if (!lstat(tmp, &statbuff) && S_ISDIR(statbuff.st_mode))
	{
		if (!(set.flag & 8) && file->d_name[0] == '.')
			return (0);
		if ((file->d_name[0] == '.') && ((file->d_name[1] == '\0') ||
				(file->d_name[1] == '.' && file->d_name[2] == '\0')))
			return (0);
		return (1);
	}
	return (0);
}

int			is_symb_lnk(char *link, t_stat *statl)
{
	if (!lstat(link, statl) && S_ISLNK(statl->st_mode))
		return (1);
	return (0);
}

int			is_folder(char *link, t_stat *statb)
{
	if (!stat(link, statb) && S_ISDIR(statb->st_mode))
		return (1);
	return (0);
}
