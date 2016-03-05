/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/05 20:41:04 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/05 21:41:15 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		get_file(t_fold **bck, t_stat statb, t_file **files, t_set set)
{
	t_fold	*tmp;

	if (!stat((*bck)->next->name, &statb) && !(S_ISDIR(statb.st_mode)))
	{
		tmp = (*bck)->next;
		if (!files)
			(*files) = stock_file_arg((*bck)->name, statb);
		else
			ls_cmp(files, stock_file_arg((*bck)->name, statb), set_cmp(set));
		(*bck)->next = (*bck)->next->next;
		free(tmp);
	}
	else
		*bck = (*bck)->next;
}

void		ls_filter(t_fold **fold, t_set set)
{
	struct stat		statb;
	t_fold			*tmp;
	t_fold			*bck;
	t_file			*files;

	files = NULL;
	while (*fold && !stat((*fold)->name, &statb) && S_ISREG(statb.st_mode))
	{
		tmp = *fold;
		if (!files)
			files = stock_file_arg((*fold)->name, statb);
		else
			ls_cmp(&files, stock_file_arg((*fold)->name, statb), set_cmp(set));
		*fold = (*fold)->next;
		free(tmp);
	}
	bck = *fold;
	while (bck && bck->next)
		get_file(&bck, statb, &files, set);
	set = init_set_max(set, files);
	if (files)
		ls_display(files, set);
}
