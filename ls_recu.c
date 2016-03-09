/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_recu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 20:15:00 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/09 23:40:18 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file			*ls_conv(t_fold *fold)
{
	t_file		*file;

	if (!(file = ft_memalloc(sizeof(t_file))))
		return (NULL);
	file->name = ft_strdup(fold->name);
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
		return (NULL);
	while ((file = readdir(folder)) != NULL && ft_strcmp(".", file->d_name) &&
				ft_strcmp("..", file->d_name))
	{
		if (is_directory(file, fold, set))
		{
			if (ft_strcmp(fold->name, "./") != 0)
			{
				ls_cmp(&folds, stk_dir(file, fold->name), set_cmp(set));
				fpf("fold = %s\n", fold->name);
			}
		}
	}
	closedir(folder);
	return (folds);
}

int				*ls_recu(t_file *fold, t_set set)
{
	if (!fold)
	{
		fpf("retour 0\n");
		return (0);
	}	//fpf("\n%s:\n", fold->name);
	//ft_ls(fold->path, set);i
	if (!get_next_fold(fold, set))
		return (ls_recu(fold->next, set));
	else
		return (ls_recu(get_next_fold(fold, set), set));
	return (0);
}
