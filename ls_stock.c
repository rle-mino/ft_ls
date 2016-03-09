/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_stock.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 11:24:02 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/10 00:24:35 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*stock_file(t_dirent *file, char *path)
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
		files->symb = ft_memalloc(1024);
		readlink(tmp, files->symb, 1024);
	}
	else
		files->symb = NULL;
	free(tmp);
	return (files);
}

t_fold		*stock_fold(char *name, char *path)
{
	t_fold	*fold;
	char	*tmp;

	if (!(fold = ft_memalloc(sizeof(t_fold))))
		ls_error(MALL_ERR, NULL);
	fold->name = ft_strdup(name);
	fold->path = ft_strjoin(path, "/");
	tmp = fold->path;
	fold->path = ft_strjoin(fold->path, name);
	free(tmp);
	tmp = fold->path;
	fold->path = ft_strjoin(path, name);
	free(tmp);
	fold->next = NULL;
	return (fold);
}

t_file		*stk_dir(t_dirent *file, char *path)
{
	t_file	*fold;
	char	*tmp;

	if (!(fold = ft_memalloc(sizeof(t_file))))
		ls_error(MALL_ERR, NULL);
	fold->name = ft_strjoin(path, file->d_name);
	tmp = fold->name;
	fold->name = ft_strjoin(fold->name, "/");
	free(tmp);
	fold->path = ft_strdup(fold->name);
	fold->next = NULL;
	return (fold);
}

t_fold		*stock_arg(char *name)
{
	t_fold		*fold;

	if (!(fold = ft_memalloc(sizeof(t_fold))))
		ls_error(MALL_ERR, NULL);
	fold->name = ft_strdup(name);
	fold->next = NULL;
	return (fold);
}

t_file		*stock_file_arg(char *name, struct stat statb)
{
	t_file		*file;
	struct stat	statl;

	file = ft_memalloc(sizeof(t_file));
	file->name = ft_strdup(name);
	file->stat = statb;
	if (!(lstat(file->name, &statl)) && S_ISLNK(statl.st_mode))
	{
		file->stat = statl;
		file->symb = ft_memalloc(statl.st_size + 1);
		readlink(file->name, file->symb, statl.st_size);
	}
	else
		file->symb = NULL;
	file->path = NULL;
	file->next = NULL;
	return (file);
}
