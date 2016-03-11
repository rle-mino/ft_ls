/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 13:20:03 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/11 16:25:41 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_files(t_file *files)
{
	t_file	*tmp;

	while (files)
	{
		tmp = files->next;
		if (files->name)
			free(files->name);
		if (files->path)
			free(files->path);
		free(files);
		files = tmp;
	}
}

void		free_fold(t_fold *fold)
{
	if (fold->name)
		free(fold->name);
	free(fold);
}

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[++i])
		free(tab[i]);
}
