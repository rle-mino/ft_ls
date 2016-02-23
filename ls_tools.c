/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 17:43:33 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/23 23:11:15 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls_file		*stock_file(struct dirent *file, int info)
{
	t_ls_file	*files;

	if (!(files = ft_memalloc(sizeof(t_ls_file))))
		return (NULL);
	if (info == O_NAME)
	{
		files->name = ft_strdup(file->d_name);
		files->next = NULL;
	}
	return (files);
}

int		is_sorted(t_ls_file *files)
{
	while (files->next && ft_strcmp(files->name, files->next->name) <= 0)
		files = files->next;
	if (!(files->next))
		return (1);
	return (0);
}

void	sort_ls_list(t_ls_file **files, int sequ)
{
	t_ls_file	*head;
	t_ls_file	*insert;
	t_ls_file	*tmp;

	while (is_sorted(*files) == 0)
	{
		//TRI CETTE SALOPERIE DE LISTE BORDEL
	}
}

int		main(void)
{
	t_ls_file	*files;
	t_ls_file	*save;
	int		i = 7;
	files = ft_memalloc(sizeof(t_ls_file));
	save = files;
	while (i--)
	{
		files->next = ft_memalloc(sizeof(t_ls_file));
		files = files->next;
	}
	files = save;
	files->name = "b";
	files->next->name = "c";
	files->next->next->name = "e";
	files->next->next->next->name = "d";
	files->next->next->next->next->name = "j";
	files->next->next->next->next->next->name = "a";
	files->next->next->next->next->next->next->name = "A";
	
	while (files)
	{
		fpf("data = %s\n", files->name);
		files = files->next;
	}
	files = save;
	sort_ls_list(&files, ASCII);
	fpf("####################\n");
	while (files)
	{
		fpf("data = %s\n", files->name);
		files = files->next;
	}
}
