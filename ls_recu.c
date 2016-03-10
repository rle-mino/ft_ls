/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 20:15:00 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/10 19:25:13 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*ls_conv(t_fold *fold)
{
	t_file		*file;
	char		*tmp;

	if (!(file = ft_memalloc(sizeof(t_file))))
		return (NULL);
	file->name = ft_strdup(fold->name);
	if (file->name[ft_strlen(file->name) - 1] != '/')
	{
		tmp = file->name;
		file->name = ft_strjoin(file->name, "/");
		free(tmp);
	}
	file->path = ft_strdup(fold->path);
	file->next = NULL;
	return (file);
}

t_file			*get_next_fold(t_file *fold, t_set set)
{
	DIR				*folder;
	struct dirent	*file;
	t_file			*folds;

	if (!(folder = opendir(fold->name)))
		return (NULL);
	while ((file = readdir(folder)) && !is_directory(file, fold, set));
	if (file != NULL)
		folds = stk_dir(file, fold->name);
	else
	{
		closedir(folder);
		return (NULL);
	}
	while ((file = readdir(folder)) != NULL && ft_strcmp(".", file->d_name) &&
				ft_strcmp("..", file->d_name))
	{
		if (is_directory(file, fold, set))
			ls_cmp(&folds, stk_dir(file, fold->name), set_cmp(set));
	}
	closedir(folder);
	return (folds);
}

int				*ls_recu(t_file *fold, t_set set)
{
	t_file	*next;

	if (!fold)
		return (0);
	fpf("\n%s:\n", fold->name);
	ft_ls(fold->path, set);
	if ((next = get_next_fold(fold, set)))
		ls_recu(next, set);
	ls_recu(fold->next, set);
	return (0);
}
