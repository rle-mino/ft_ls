/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 15:11:42 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/23 21:05:31 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_ls(char *dir)
{
	DIR				*folder;
	struct dirent	*file;
	t_ls_file		*files;
	t_ls_file		*save;

	if (!(folder = opendir(dir)))
		ls_error(ERRNO, dir);
	if ((file = readdir(folder)))
		files = stock_file(file, O_NAME);
	save = files;
	while ((file = readdir(folder)))
	{
		files->next = stock_file(file, O_NAME);
		files = files->next;
	}
	sort_ls_list(&files, ASCII);
	ls_display(save);
	return (1);
}
