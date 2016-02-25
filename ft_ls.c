/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:11:42 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/25 19:15:24 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_ls(char *dir)
{
	DIR				*folder;
	struct dirent	*file;
	t_file		*files;

	if (!(folder = opendir(dir)))
		ls_error(ERRNO, dir);
	if ((file = readdir(folder)))
		files = stock_file(file, O_NAME);
	while ((file = readdir(folder)))
	{
		if (ft_strcmp(files->name, file->d_name) >= 0)
			ft_pushback(&files, stock_file(file, O_NAME));
		else
			ft_push_name(files, stock_file(file, O_NAME), cmp_name);
	}
	ls_display(files, O_NAME);
	return (1);
}
